#pragma once

//====================================================================================================
//The Free Edition of Java to C++ Converter limits conversion output to 100 lines per file.

//To purchase the Premium Edition, visit our website:
//https://www.tangiblesoftwaresolutions.com/order/order-java-to-cplus.html
//====================================================================================================

#include "TrasparentTitleView.h"
#include "AutoFitTextureView.h"
#include "OnGetImageListener.h"
#include <string>
#include <vector>
#include <stdexcept>
#include <optional>
#include "exceptionhelper.h"
#include <cassert>

/*
 * Copyright 2016-present Tzutalin
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

namespace com::tzutalin::dlibtest
{

	using Dialog = android::app::Dialog;
	using DialogFragment = android::app::DialogFragment;
	using Fragment = android::app::Fragment;
	using CameraCaptureSession = android::hardware::camera2::CameraCaptureSession;
	using CameraDevice = android::hardware::camera2::CameraDevice;
	using CaptureRequest = android::hardware::camera2::CaptureRequest;
	using ImageReader = android::media::ImageReader;
	using Bundle = android::os::Bundle;
	using Handler = android::os::Handler;
	using HandlerThread = android::os::HandlerThread;
	using Size = android::util::Size;
	using SparseIntArray = android::util::SparseIntArray;
	using LayoutInflater = android::view::LayoutInflater;
	using TextureView = android::view::TextureView;
	using View = android::view::View;
	using ViewGroup = android::view::ViewGroup;


	using Comparator = java::util::Comparator;
	using Semaphore = java::util::concurrent::Semaphore;


//JAVA TO C++ CONVERTER TODO TASK: Most Java annotations will not have direct C++ equivalents:
//ORIGINAL LINE: @RequiresApi(api = Build.VERSION_CODES.LOLLIPOP) public class CameraConnectionFragment extends android.app.Fragment
	class CameraConnectionFragment : public Fragment
	{

		/**
		 * The camera preview size will be chosen to be the smallest frame by pixel size capable of
		 * containing a DESIRED_SIZE x DESIRED_SIZE square.
		 */
	private:
		static constexpr int MINIMUM_PREVIEW_SIZE = 320;
		static const std::wstring TAG;

		TrasparentTitleView *mScoreView;

		/**
		 * Conversion from screen rotation to JPEG orientation.
		 */
		static const SparseIntArray *ORIENTATIONS;
		static const std::wstring FRAGMENT_DIALOG;

		private:
			class StaticConstructor
			{
			public:
				StaticConstructor();
			};

		private:
			static CameraConnectionFragment::StaticConstructor staticConstructor;


		/**
		 * {@link android.view.TextureView.SurfaceTextureListener} handles several lifecycle events on a
		 * {@link TextureView}.
		 */
		TextureView::SurfaceTextureListener *const surfaceTextureListener = new SurfaceTextureListenerAnonymousInnerClass();

	private:
		class SurfaceTextureListenerAnonymousInnerClass : public TextureView::SurfaceTextureListener
		{
		public:
			void onSurfaceTextureAvailable(SurfaceTexture *const texture, int const width, int const height) override;

			void onSurfaceTextureSizeChanged(SurfaceTexture *const texture, int const width, int const height) override;

			bool onSurfaceTextureDestroyed(SurfaceTexture *const texture) override;

			void onSurfaceTextureUpdated(SurfaceTexture *const texture) override;
		};

		/**
		 * ID of the current {@link CameraDevice}.
		 */
	private:
		std::wstring cameraId;

		/**
		 * An {@link AutoFitTextureView} for camera preview.
		 */
		AutoFitTextureView *textureView;

		/**
		 * A {@link CameraCaptureSession } for camera preview.
		 */
		CameraCaptureSession *captureSession;

		/**
		 * A reference to the opened {@link CameraDevice}.
		 */
		CameraDevice *cameraDevice;

		/**
		 * The {@link android.util.Size} of camera preview.
		 */
		Size *previewSize;

		/**
		 * {@link android.hardware.camera2.CameraDevice.StateCallback}
		 * is called when {@link CameraDevice} changes its state.
		 */
		CameraDevice::StateCallback *const stateCallback = new StateCallbackAnonymousInnerClass();

	private:
		class StateCallbackAnonymousInnerClass : public CameraDevice::StateCallback
		{
		public:
			void onOpened(CameraDevice *const cd) override;

			void onDisconnected(CameraDevice *const cd) override;

			void onError(CameraDevice *const cd, int const error) override;
		};

		/**
		 * An additional thread for running tasks that shouldn't block the UI.
		 */
	private:
		HandlerThread *backgroundThread;

		/**
		 * A {@link Handler} for running tasks in the background.
		 */
		Handler *backgroundHandler;

		/**
		 * An additional thread for running inference so as not to block the camera.
		 */
		HandlerThread *inferenceThread;

		/**
		 * A {@link Handler} for running tasks in the background.
		 */
		Handler *inferenceHandler;

		/**
		 * An {@link ImageReader} that handles preview frame capture.
		 */
		ImageReader *previewReader;

		/**
		 * {@link android.hardware.camera2.CaptureRequest.Builder} for the camera preview
		 */
		CaptureRequest::Builder *previewRequestBuilder;

		/**
		 * {@link CaptureRequest} generated by {@link #previewRequestBuilder}
		 */
		CaptureRequest *previewRequest;

		/**
		 * A {@link Semaphore} to prevent the app from exiting before closing the camera.
		 */
		Semaphore *const cameraOpenCloseLock = new Semaphore(1);

		/**
		 * Shows a {@link Toast} on the UI thread.
		 *
		 * @param text The message to show
		 */
	public:
		virtual ~CameraConnectionFragment()
		{
			delete mScoreView;
			delete surfaceTextureListener;
			delete textureView;
			delete captureSession;
			delete cameraDevice;
			delete previewSize;
			delete stateCallback;
			delete backgroundThread;
			delete backgroundHandler;
			delete inferenceThread;
			delete inferenceHandler;
			delete previewReader;
			delete previewRequestBuilder;
			delete previewRequest;
			delete cameraOpenCloseLock;
			delete mOnGetPreviewListener;
			delete captureCallback;
		}

	private:
		void showToast(const std::wstring &text);

		/**
		 * Given {@code choices} of {@code Size}s supported by a camera, chooses the smallest one whose
		 * width and height are at least as large as the respective requested values, and whose aspect
		 * ratio matches with the specified value.
		 *
		 * @param choices     The list of sizes that the camera supports for the intended output class
		 * @param width       The minimum desired width
		 * @param height      The minimum desired height
		 * @param aspectRatio The aspect ratio
		 * @return The optimal {@code Size}, or an arbitrary one if none were big enough
		 */
//JAVA TO C++ CONVERTER TODO TASK: Most Java annotations will not have direct C++ equivalents:
//ORIGINAL LINE: @SuppressLint("LongLogTag") @DebugLog private static android.util.Size chooseOptimalSize(final android.util.Size[] choices, final int width, final int height, final android.util.Size aspectRatio)
		static Size *chooseOptimalSize(std::vector<Size*> &choices, int const width, int const height, Size *const aspectRatio);

	public:
		static CameraConnectionFragment *newInstance();

		View *onCreateView(LayoutInflater *const inflater, ViewGroup *const container, Bundle *const savedInstanceState) override;

		void onViewCreated(View *const view, Bundle *const savedInstanceState) override;

		void onActivityCreated(Bundle *const savedInstanceState) override;

		void onResume() override;

		void onPause() override;

		/**
		 * Sets up member variables related to camera.
		 *
		 * @param width  The width of available size for camera preview
		 * @param height The height of available size for camera preview
		 */
	private:
//JAVA TO C++ CONVERTER TODO TASK: Most Java annotations will not have direct C++ equivalents:
//ORIGINAL LINE: @RequiresApi(api = android.os.Build.VERSION_CODES.LOLLIPOP) @DebugLog @SuppressLint("LongLogTag") private void setUpCameraOutputs(final int width, final int height)
		void setUpCameraOutputs(int const width, int const height);

		/**
		 * Opens the camera specified by {@link CameraConnectionFragment#cameraId}.
		 */
//JAVA TO C++ CONVERTER TODO TASK: Most Java annotations will not have direct C++ equivalents:
//ORIGINAL LINE: @SuppressLint("LongLogTag") @DebugLog private void openCamera(final int width, final int height)
		void openCamera(int const width, int const height);

		/**
		 * Closes the current {@link CameraDevice}.
		 */
//JAVA TO C++ CONVERTER TODO TASK: Most Java annotations will not have direct C++ equivalents:
//ORIGINAL LINE: @DebugLog private void closeCamera()
		void closeCamera();

		/**
		 * Starts a background thread and its {@link Handler}.
		 */
//JAVA TO C++ CONVERTER TODO TASK: Most Java annotations will not have direct C++ equivalents:
//ORIGINAL LINE: @DebugLog private void startBackgroundThread()
		void startBackgroundThread();

		/**
		 * Stops the background thread and its {@link Handler}.
		 */
//JAVA TO C++ CONVERTER TODO TASK: Most Java annotations will not have direct C++ equivalents:
//ORIGINAL LINE: @SuppressLint("LongLogTag") @DebugLog private void stopBackgroundThread()
		void stopBackgroundThread();


//====================================================================================================
//End of the allowed output for the Free Edition of Java to C++ Converter.

//To purchase the Premium Edition, visit our website:
//https://www.tangiblesoftwaresolutions.com/order/order-java-to-cplus.html
//====================================================================================================
