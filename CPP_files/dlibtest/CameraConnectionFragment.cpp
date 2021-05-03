//====================================================================================================
//The Free Edition of Java to C++ Converter limits conversion output to 100 lines per file.

//To purchase the Premium Edition, visit our website:
//https://www.tangiblesoftwaresolutions.com/order/order-java-to-cplus.html
//====================================================================================================

#include "CameraConnectionFragment.h"

namespace com::tzutalin::dlibtest
{
	using Manifest = android::Manifest;
	using SuppressLint = android::annotation::SuppressLint;
	using Activity = android::app::Activity;
	using AlertDialog = android::app::AlertDialog;
	using Dialog = android::app::Dialog;
	using DialogFragment = android::app::DialogFragment;
	using Fragment = android::app::Fragment;
	using Context = android::content::Context;
	using DialogInterface = android::content::DialogInterface;
	using PackageManager = android::content::pm::PackageManager;
	using Configuration = android::content::res::Configuration;
	using ImageFormat = android::graphics::ImageFormat;
	using Matrix = android::graphics::Matrix;
	using RectF = android::graphics::RectF;
	using SurfaceTexture = android::graphics::SurfaceTexture;
	using CameraAccessException = android::hardware::camera2::CameraAccessException;
	using CameraCaptureSession = android::hardware::camera2::CameraCaptureSession;
	using CameraCharacteristics = android::hardware::camera2::CameraCharacteristics;
	using CameraDevice = android::hardware::camera2::CameraDevice;
	using CameraManager = android::hardware::camera2::CameraManager;
	using CaptureRequest = android::hardware::camera2::CaptureRequest;
	using CaptureResult = android::hardware::camera2::CaptureResult;
	using TotalCaptureResult = android::hardware::camera2::TotalCaptureResult;
	using StreamConfigurationMap = android::hardware::camera2::params::StreamConfigurationMap;
	using ImageReader = android::media::ImageReader;
	using Build = android::os::Build;
	using Bundle = android::os::Bundle;
	using Handler = android::os::Handler;
	using HandlerThread = android::os::HandlerThread;
	using Size = android::util::Size;
	using SparseArray = android::util::SparseArray;
	using SparseIntArray = android::util::SparseIntArray;
	using LayoutInflater = android::view::LayoutInflater;
	using Surface = android::view::Surface;
	using TextureView = android::view::TextureView;
	using View = android::view::View;
	using ViewGroup = android::view::ViewGroup;
	using Toast = android::widget::Toast;
	using RequiresApi = androidx::annotation::RequiresApi;
	using ActivityCompat = androidx::core::app::ActivityCompat;
	using ArrayList = java::util::ArrayList;
	using Collections = java::util::Collections;
	using Comparator = java::util::Comparator;
	using List = java::util::List;
	using Semaphore = java::util::concurrent::Semaphore;
	using TimeUnit = java::util::concurrent::TimeUnit;
	using DebugLog = hugo::weaving::DebugLog;
	using Timber = timber::log::Timber;
const std::wstring CameraConnectionFragment::TAG = L"CameraConnectionFragment";
const android::util::SparseIntArray *CameraConnectionFragment::ORIENTATIONS = new android::util::SparseIntArray();
const std::wstring CameraConnectionFragment::FRAGMENT_DIALOG = L"dialog";

	CameraConnectionFragment::StaticConstructor::StaticConstructor()
	{
	ORIENTATIONS->append(Surface::ROTATION_0, 90);
	ORIENTATIONS->append(Surface::ROTATION_90, 0);
	ORIENTATIONS->append(Surface::ROTATION_180, 270);
	ORIENTATIONS->append(Surface::ROTATION_270, 180);
	}

CameraConnectionFragment::StaticConstructor CameraConnectionFragment::staticConstructor;

	void CameraConnectionFragment::SurfaceTextureListenerAnonymousInnerClass::onSurfaceTextureAvailable(SurfaceTexture *const texture, int const width, int const height)
	{
		outerInstance->openCamera(width, height);
	}

	void CameraConnectionFragment::SurfaceTextureListenerAnonymousInnerClass::onSurfaceTextureSizeChanged(SurfaceTexture *const texture, int const width, int const height)
	{
		outerInstance->configureTransform(width, height);
	}

	bool CameraConnectionFragment::SurfaceTextureListenerAnonymousInnerClass::onSurfaceTextureDestroyed(SurfaceTexture *const texture)
	{
		return true;
	}

	void CameraConnectionFragment::SurfaceTextureListenerAnonymousInnerClass::onSurfaceTextureUpdated(SurfaceTexture *const texture)
	{
	}

	void CameraConnectionFragment::StateCallbackAnonymousInnerClass::onOpened(CameraDevice *const cd)
	{
		// This method is called when the camera is opened.  We start camera preview here.
		outerInstance->cameraOpenCloseLock.release();
		outerInstance->cameraDevice = cd;
		outerInstance->createCameraPreviewSession();
	}

	void CameraConnectionFragment::StateCallbackAnonymousInnerClass::onDisconnected(CameraDevice *const cd)
	{
		outerInstance->cameraOpenCloseLock.release();
		cd->close();
		outerInstance->cameraDevice = nullptr;

		if (outerInstance->mOnGetPreviewListener != nullptr)
		{
			outerInstance->mOnGetPreviewListener.deInitialize();
		}
	}

	void CameraConnectionFragment::StateCallbackAnonymousInnerClass::onError(CameraDevice *const cd, int const error)
	{
		outerInstance->cameraOpenCloseLock.release();
		cd->close();
		outerInstance->cameraDevice = nullptr;
		Activity * const activity = getActivity();
		if (nullptr != activity)
		{
			activity->finish();
		}

		if (outerInstance->mOnGetPreviewListener != nullptr)
		{
			outerInstance->mOnGetPreviewListener.deInitialize();
		}
	}

	void CameraConnectionFragment::showToast(const std::wstring &text)
	{
		Activity * const activity = getActivity();
		if (activity != nullptr)
		{
			activity->runOnUiThread([&] ()
			{
						Toast::makeText(activity, text, Toast::LENGTH_SHORT).show();
			}
					);
		}
	}

//JAVA TO C++ CONVERTER TODO TASK: Most Java annotations will not have direct C++ equivalents:
//ORIGINAL LINE: @SuppressLint("LongLogTag") @DebugLog private static android.util.Size chooseOptimalSize(final android.util.Size[] choices, final int width, final int height, final android.util.Size aspectRatio)
	Size *CameraConnectionFragment::chooseOptimalSize(std::vector<Size*> &choices, int const width, int const height, Size *const aspectRatio)
	{
		// Collect the supported resolutions that are at least as big as the preview Surface
//JAVA TO C++ CONVERTER WARNING: C++ has no equivalent to a 'final' collection which allows modification of internal state:
//ORIGINAL LINE: final java.util.List<android.util.Size> bigEnough = new java.util.ArrayList<android.util.Size>();
		std::vector<Size*> bigEnough;
		for (auto option : choices)
		{
			if (option->getHeight() >= MINIMUM_PREVIEW_SIZE && option->getWidth() >= MINIMUM_PREVIEW_SIZE)
			{
				Timber::tag(TAG).i(L"Adding size: " + option->getWidth() + L"x" + option->getHeight());
				bigEnough.push_back(option);
			}
			else
			{
				Timber::tag(TAG).i(L"Not adding size: " + option->getWidth() + L"x" + option->getHeight());
			}
		}

		// Pick the smallest of those, assuming we found any
		if (bigEnough.size() > 0)
		{
			CompareSizesByArea tempVar();

//====================================================================================================
//End of the allowed output for the Free Edition of Java to C++ Converter.

//To purchase the Premium Edition, visit our website:
//https://www.tangiblesoftwaresolutions.com/order/order-java-to-cplus.html
//====================================================================================================
