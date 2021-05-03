the//====================================================================================================
//The Free Edition of Java to C++ Converter limits conversion output to 100 lines per file.

//To purchase the Premium Edition, visit our website:
//https://www.tangiblesoftwaresolutions.com/order/order-java-to-cplus.html
//====================================================================================================

#include "OnGetImageListener.h"
#include "ImageUtils.h"
#include "AppData.h"
#include "FileUtils.h"

namespace com::tzutalin::dlibtest
{
	using Context = android::content::Context;
	using AssetManager = android::content::res::AssetManager;
	using Configuration = android::content::res::Configuration;
	using Resources = android::content::res::Resources;
	using Bitmap = android::graphics::Bitmap;
	using Config = android::graphics::Bitmap::Config;
	using BitmapFactory = android::graphics::BitmapFactory;
	using Canvas = android::graphics::Canvas;
	using Color = android::graphics::Color;
	using ColorMatrix = android::graphics::ColorMatrix;
	using ColorMatrixColorFilter = android::graphics::ColorMatrixColorFilter;
	using Matrix = android::graphics::Matrix;
	using Paint = android::graphics::Paint;
	using Point = android::graphics::Point;
	using Rect = android::graphics::Rect;
	using BitmapDrawable = android::graphics::drawable::BitmapDrawable;
	using Image = android::media::Image;
	using Plane = android::media::Image::Plane;
	using ImageReader = android::media::ImageReader;
	using OnImageAvailableListener = android::media::ImageReader::OnImageAvailableListener;
	using Build = android::os::Build;
	using Handler = android::os::Handler;
	using Trace = android::os::Trace;
	using Log = android::util::Log;
	using Display = android::view::Display;
	using WindowManager = android::view::WindowManager;
	using RequiresApi = androidx::annotation::RequiresApi;
	using Constants = com::tzutalin::dlib::Constants;
	using FaceDet = com::tzutalin::dlib::FaceDet;
	using VisionDetRet = com::tzutalin::dlib::VisionDetRet;
	using Utils = org::opencv::android::Utils;
	using Core = org::opencv::core::Core;
	using CvType = org::opencv::core::CvType;
	using Mat = org::opencv::core::Mat;
	using MatOfByte = org::opencv::core::MatOfByte;
	using MatOfFloat = org::opencv::core::MatOfFloat;
	using MatOfPoint2f = org::opencv::core::MatOfPoint2f;
	using Size = org::opencv::core::Size;
	using TermCriteria = org::opencv::core::TermCriteria;
	using Imgproc = org::opencv::imgproc::Imgproc;
	using Video = org::opencv::video::Video;
	using File = java::io::File;
	using ArrayList = java::util::ArrayList;
	using List = java::util::List;
//	import static org.opencv.core.CvType.CV_32F;
const std::wstring OnGetImageListener::EARRING = L"Earrings";
const std::wstring OnGetImageListener::NECKWEAR = L"Neck Jewellery";
const std::wstring OnGetImageListener::CHAIN = L"chain";
const std::wstring OnGetImageListener::NECKLACE = L"necklace";
const std::wstring OnGetImageListener::TAG = L"OnGetImageListener";

	void OnGetImageListener::initialize(Context *const context, AssetManager *const assetManager, TrasparentTitleView *const scoreView, Handler *const handler)
	{
		this->mContext = context;
		this->mTransparentTitleView = scoreView;
		this->mInferenceHandler = handler;
		mFaceDet = new FaceDet(Constants::getFaceShapeModelPath());
		mNeckDet = new FaceDet(Constants::getNeckModelPath());
		mWindow = new FloatingCameraWindow(mContext);

		mFaceLandmarkPaint = new Paint();
		mFaceLandmarkPaint->setColor(Color::RED);
		mFaceLandmarkPaint->setStrokeWidth(2);
		mFaceLandmarkPaint->setStyle(Paint::Style::FILL_AND_STROKE);
	}

	void OnGetImageListener::deInitialize()
	{
		{
				std::scoped_lock<std::mutex> lock(OnGetImageListener::this);
			if (mFaceDet != nullptr)
			{
				mFaceDet->release();
			}

			if (mNeckDet != nullptr)
			{
				mNeckDet->release();
			}

			if (mWindow != nullptr)
			{
				mWindow->release();
			}
		}
	}

	void OnGetImageListener::drawResizedBitmap(Bitmap *const src, Bitmap *const dst)
	{

		Display *getOrient = (static_cast<WindowManager*>(mContext->getSystemService(Context::WINDOW_SERVICE)))->getDefaultDisplay();
		int orientation = Configuration::ORIENTATION_UNDEFINED;
		Point *point = new Point();
		getOrient->getSize(point);
		int screen_width = point->x;
		int screen_height = point->y;
		Log::d(TAG, std::wstring::format(L"screen size (%d,%d)", screen_width, screen_height));
		if (screen_width < screen_height)
		{
			orientation = Configuration::ORIENTATION_PORTRAIT;
			mScreenRotation = -90;
		}
		else
		{
			orientation = Configuration::ORIENTATION_LANDSCAPE;
			mScreenRotation = 0;
		}

		constexpr float minDim = std::min(src->getWidth(), src->getHeight());

		Matrix * const matrix = new Matrix();

		// We only want the center square out of the original rectangle.
		constexpr float translateX = -std::max(0, (src->getWidth() - minDim) / 2);
		constexpr float translateY = -std::max(0, (src->getHeight() - minDim) / 2);
		matrix->preTranslate(translateX, translateY);

		constexpr float scaleFactor = dst->getHeight() / minDim;
		//        matrix.preScale(-scaleFactor,scaleFactor);
		matrix->postScale(scaleFactor, scaleFactor);

		// Rotate around the center if necessary.
		if (mScreenRotation != 0)
		{
			matrix->postTranslate(-dst->getWidth() / 2.0f, -dst->getHeight() / 2.0f);
			matrix->postRotate(mScreenRotation);
			matrix->postTranslate(dst->getWidth() / 2.0f, dst->getHeight() / 2.0f);
		}

		Canvas * const canvas = new Canvas(dst);
		//        matrix.preScale(-1,1);
		canvas->drawBitmap(src, matrix, nullptr);

	}

	bool OnGetImageListener::inRange(int x, int min, int max)
	{
		Log::i(TAG, L"min - " + std::to_wstring(min));
		Log::i(TAG, L"max - " + std::to_wstring(max));
		Log::i(TAG, L"x - " + std::to_wstring(x));

