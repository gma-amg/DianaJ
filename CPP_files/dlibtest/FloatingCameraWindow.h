#pragma once

#include <string>
#include <stdexcept>

//JAVA TO C++ CONVERTER NOTE: Forward class declarations:
namespace com::tzutalin::dlibtest { class FloatCamView; }

/*
 *  Copyright (C) 2016-present Tzuta Lin
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  imitations under the License.
 */

namespace com::tzutalin::dlibtest
{

	using Context = android::content::Context;
	using Bitmap = android::graphics::Bitmap;
	using Handler = android::os::Handler;
	//import android.support.annotation.UiThread;
	using LayoutInflater = android::view::LayoutInflater;
	using WindowManager = android::view::WindowManager;
	using FrameLayout = android::widget::FrameLayout;
	using ImageView = android::widget::ImageView;
	using TextView = android::widget::TextView;


	using WeakReference = java::lang::ref::WeakReference;

	/**
	 * Created by Tzutalin on 2016/5/25
	 */
	class FloatingCameraWindow
	{
	private:
		static const std::wstring TAG;
		Context *mContext;
		WindowManager::LayoutParams *mWindowParam;
		WindowManager *mWindowManager;
		FloatCamView *mRootView;
		Handler *mUIHandler;

		int mWindowWidth = 0;
		int mWindowHeight = 0;

		int mScreenMaxWidth = 0;
		int mScreenMaxHeight = 0;

		float mScaleWidthRatio = 1.0f;
		float mScaleHeightRatio = 1.0f;

		static constexpr bool DEBUG = true;

	public:
		virtual ~FloatingCameraWindow()
		{
			delete mContext;
			delete mWindowParam;
			delete mWindowManager;
			delete mRootView;
			delete mUIHandler;
		}

		FloatingCameraWindow(Context *context);

		FloatingCameraWindow(Context *context, int windowWidth, int windowHeight);

	private:
		void init();

	public:
		virtual void release();

	private:
		WindowManager::LayoutParams *initWindowParameter();

	public:
		virtual void setRGBBitmap(Bitmap *const rgb);

		virtual void setFPS(float const fps);

		virtual void setMoreInformation(const std::wstring &info);

	private:
		void checkInit();

	private:
//JAVA TO C++ CONVERTER TODO TASK: Most Java annotations will not have direct C++ equivalents:
//ORIGINAL LINE: @UiThread private final class FloatCamView extends android.widget.FrameLayout
		class FloatCamView final : public FrameLayout
		{
		private:
			FloatingCameraWindow *outerInstance;

			WeakReference<FloatingCameraWindow*> *mWeakRef;
			static constexpr int MOVE_THRESHOLD = 10;
			int mLastX = 0;
			int mLastY = 0;
			int mFirstX = 0;
			int mFirstY = 0;
			LayoutInflater *mLayoutInflater;
			ImageView *mColorView;
			TextView *mFPSText;
			TextView *mInfoText;
			bool mIsMoving = false;

		public:
			virtual ~FloatCamView()
			{
				delete mWeakRef;
				delete mLayoutInflater;
				delete mColorView;
				delete mFPSText;
				delete mInfoText;
				delete outerInstance;
			}

			FloatCamView(FloatingCameraWindow *outerInstance, FloatingCameraWindow *window);

		private:
			class OnTouchListenerAnonymousInnerClass : public OnTouchListener
			{
			private:
				FloatCamView *outerInstance;

			public:
				virtual ~OnTouchListenerAnonymousInnerClass()
				{
					delete outerInstance;
				}

				OnTouchListenerAnonymousInnerClass(FloatCamView *outerInstance);

				bool onTouch(View *v, MotionEvent *event) override;
			};

	//        @Override
	//        public boolean onTouchEvent(MotionEvent event) {
	//            switch (event.getAction()) {
	//                case MotionEvent.ACTION_DOWN:
	//                    mLastX = (int) event.getRawX();
	//                    mLastY = (int) event.getRawY();
	//                    mFirstX = mLastX;
	//                    mFirstY = mLastY;
	//                    break;
	//                case MotionEvent.ACTION_MOVE:
	//                    int deltaX = (int) event.getRawX() - mLastX;
	//                    int deltaY = (int) event.getRawY() - mLastY;
	//                    mLastX = (int) event.getRawX();
	//                    mLastY = (int) event.getRawY();
	//                    int totalDeltaX = mLastX - mFirstX;
	//                    int totalDeltaY = mLastY - mFirstY;
	//
	//                    if (mIsMoving
	//                            || Math.abs(totalDeltaX) >= MOVE_THRESHOLD
	//                            || Math.abs(totalDeltaY) >= MOVE_THRESHOLD) {
	//                        mIsMoving = true;
	//                        WindowManager windowMgr = mWeakRef.get().mWindowManager;
	//                        WindowManager.LayoutParams parm = mWeakRef.get().mWindowParam;
	//                        if (event.getPointerCount() == 1 && windowMgr != null) {
	//                            parm.x -= deltaX;
	//                            parm.y -= deltaY;
	//                            windowMgr.updateViewLayout(this, parm);
	//                        }
	//                    }
	//                    break;
	//
	//                case MotionEvent.ACTION_UP:
	//                    mIsMoving = false;
	//                    break;
	//            }
	//            return true;
	//        }

		public:
			void setRGBImageView(Bitmap *rgb);

			void setFPS(float fps);

			void setMoreInformation(const std::wstring &info);
		};

	};

}
