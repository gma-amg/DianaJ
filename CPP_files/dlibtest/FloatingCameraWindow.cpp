//====================================================================================================
//The Free Edition of Java to C++ Converter limits conversion output to 100 lines per file.

//To purchase the Premium Edition, visit our website:
//https://www.tangiblesoftwaresolutions.com/order/order-java-to-cplus.html
//====================================================================================================

#include "FloatingCameraWindow.h"

namespace com::tzutalin::dlibtest
{
	using Context = android::content::Context;
	using Bitmap = android::graphics::Bitmap;
	using Point = android::graphics::Point;
	using Build = android::os::Build;
	using Handler = android::os::Handler;
	using Looper = android::os::Looper;
	using Log = android::util::Log;
	using Display = android::view::Display;
	using Gravity = android::view::Gravity;
	using LayoutInflater = android::view::LayoutInflater;
	using MotionEvent = android::view::MotionEvent;
	using View = android::view::View;
	using WindowManager = android::view::WindowManager;
	using FrameLayout = android::widget::FrameLayout;
	using ImageView = android::widget::ImageView;
	using TextView = android::widget::TextView;
	using UiThread = androidx::annotation::UiThread;
	using WeakReference = java::lang::ref::WeakReference;
const std::wstring FloatingCameraWindow::TAG = L"FloatingCameraWindow";

	FloatingCameraWindow::FloatingCameraWindow(Context *context)
	{
		mContext = context;
		mUIHandler = new Handler(Looper::getMainLooper());

		// Get screen max size
		Point *size = new Point();
		Display *display = (static_cast<WindowManager*>(context->getSystemService(Context::WINDOW_SERVICE)))->getDefaultDisplay();
		if (Build::VERSION::SDK_INT >= Build::VERSION_CODES::HONEYCOMB)
		{
			display->getSize(size);
			mScreenMaxWidth = size->x;
			mScreenMaxHeight = size->y;
		}
		else
		{
			mScreenMaxWidth = display->getWidth();
			mScreenMaxHeight = display->getHeight();
		}
		// Default window size
		mWindowWidth = mScreenMaxWidth;
		mWindowHeight = mScreenMaxHeight;

		mWindowWidth = mWindowWidth > 0 && mWindowWidth < mScreenMaxWidth ? mWindowWidth : mScreenMaxWidth;
		mWindowHeight = mWindowHeight > 0 && mWindowHeight < mScreenMaxHeight ? mWindowHeight : mScreenMaxHeight;

//JAVA TO C++ CONVERTER TODO TASK: A 'delete size' statement was not added since size was passed to a method or constructor. Handle memory management manually.
	}

	FloatingCameraWindow::FloatingCameraWindow(Context *context, int windowWidth, int windowHeight) : FloatingCameraWindow(context)
	{

		if (windowWidth < 0 || windowWidth > mScreenMaxWidth || windowHeight < 0 || windowHeight > mScreenMaxHeight)
		{
			throw std::invalid_argument("Window size is illegal");
		}

		mScaleWidthRatio = static_cast<float>(windowWidth) / mWindowHeight;
		mScaleHeightRatio = static_cast<float>(windowHeight) / mWindowHeight;

		if (DEBUG)
		{
			Log::d(TAG, L"mScaleWidthRatio: " + std::to_wstring(mScaleWidthRatio));
			Log::d(TAG, L"mScaleHeightRatio: " + std::to_wstring(mScaleHeightRatio));
		}

		mWindowWidth = windowWidth;
		mWindowHeight = windowHeight;
	}

	void FloatingCameraWindow::init()
	{
		mUIHandler->postAtFrontOfQueue([&] ()
		{
			if (mWindowManager == nullptr || mRootView == nullptr)
			{
				mWindowManager = static_cast<WindowManager*>(mContext->getSystemService(Context::WINDOW_SERVICE));
				mRootView = new FloatCamView(this, FloatingCameraWindow::this);
				mWindowManager->addView(mRootView, initWindowParameter());
			}
		}
		);
	}

	void FloatingCameraWindow::release()
	{
		mUIHandler->postAtFrontOfQueue([&] ()
		{
			if (mWindowManager != nullptr)
			{
				mWindowManager->removeViewImmediate(mRootView);
				mRootView = nullptr;
			}
			mUIHandler->removeCallbacksAndMessages(nullptr);
		}
		);
	}

	WindowManager::LayoutParams *FloatingCameraWindow::initWindowParameter()
	{
		mWindowParam = new WindowManager::LayoutParams();

		mWindowParam->type = WindowManager::LayoutParams::TYPE_SYSTEM_ALERT;
		mWindowParam->format = 1;
		mWindowParam->flags = WindowManager::LayoutParams::FLAG_NOT_FOCUSABLE;
		mWindowParam->flags = mWindowParam->flags | WindowManager::LayoutParams::FLAG_WATCH_OUTSIDE_TOUCH;
		mWindowParam->flags = mWindowParam->flags | WindowManager::LayoutParams::FLAG_LAYOUT_NO_LIMITS;

		mWindowParam->alpha = 1.0f;

		mWindowParam->gravity = Gravity::BOTTOM | Gravity::RIGHT;
		mWindowParam->x = 0;
		mWindowParam->y = 0;
		mWindowParam->width = mWindowWidth;
		mWindowParam->height = mWindowHeight;
		return mWindowParam;
	}

	void FloatingCameraWindow::setRGBBitmap(Bitmap *const rgb)
	{
		checkInit();
		mUIHandler->post([&] ()
		{
			mRootView->setRGBImageView(rgb);
		}
		);
	}

	void FloatingCameraWindow::setFPS(float const fps)
	{
		checkInit();
		mUIHandler->post([&] ()
		{
			checkInit();
			mRootView->setFPS(fps);
		}
		);
	}

	void FloatingCameraWindow::setMoreInformation(const std::wstring &info)
	{
		checkInit();
		mUIHandler->post([&] ()
		{
			checkInit();
			mRootView->setMoreInformation(info);
		}
		);
	}

	void FloatingCameraWindow::checkInit()
	{
		if (mRootView == nullptr)
		{
			init();
		}
	}

	FloatingCameraWindow::FloatCamView::FloatCamView(FloatingCameraWindow *outerInstance, FloatingCameraWindow *window) : android::widget::FrameLayout(window->mContext), outerInstance(outerInstance)
	{
		mWeakRef = new WeakReference<FloatingCameraWindow*>(window);
		// mLayoutInflater = LayoutInflater.from(context);
		mLayoutInflater = static_cast<LayoutInflater*>(window->mContext->getSystemService(Context::LAYOUT_INFLATER_SERVICE));
		FrameLayout *body = static_cast<FrameLayout*>(this);
		OnTouchListenerAnonymousInnerClass tempVar(this);
		body->setOnTouchListener(&tempVar);


//====================================================================================================
//End of the allowed output for the Free Edition of Java to C++ Converter.

//To purchase the Premium Edition, visit our website:
//https://www.tangiblesoftwaresolutions.com/order/order-java-to-cplus.html
//====================================================================================================
