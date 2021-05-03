#pragma once

//====================================================================================================
//The Free Edition of Java to C++ Converter limits conversion output to 100 lines per file.

//To purchase the Premium Edition, visit our website:
//https://www.tangiblesoftwaresolutions.com/order/order-java-to-cplus.html
//====================================================================================================

#include "TrasparentTitleView.h"
#include "FloatingCameraWindow.h"
#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <optional>
#include <mutex>
#include "../tangible_filesystem.h"

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

	using Context = android::content::Context;
	using AssetManager = android::content::res::AssetManager;
	using Bitmap = android::graphics::Bitmap;
	using Paint = android::graphics::Paint;
	using Point = android::graphics::Point;
	using Image = android::media::Image;
	using ImageReader = android::media::ImageReader;
	using OnImageAvailableListener = android::media::ImageReader::OnImageAvailableListener;
	using Handler = android::os::Handler;


	using FaceDet = com::tzutalin::dlib::FaceDet;
	using VisionDetRet = com::tzutalin::dlib::VisionDetRet;


	using Mat = org::opencv::core::Mat;
	using MatOfByte = org::opencv::core::MatOfByte;
	using MatOfFloat = org::opencv::core::MatOfFloat;
	using MatOfPoint2f = org::opencv::core::MatOfPoint2f;
	using Size = org::opencv::core::Size;
	using TermCriteria = org::opencv::core::TermCriteria;

	using ArrayList = java::util::ArrayList;
	using List = java::util::List;

//JAVA TO C++ CONVERTER TODO TASK: The Java 'import static' statement cannot be converted to C++:
//	import static org.opencv.core.CvType.CV_32F;

	/**
	 * Class that takes in preview frames and converts the image to Bitmaps to process with dlib lib.
	 */
//JAVA TO C++ CONVERTER TODO TASK: Most Java annotations will not have direct C++ equivalents:
//ORIGINAL LINE: @RequiresApi(api = Build.VERSION_CODES.KITKAT) public class OnGetImageListener implements android.media.ImageReader.OnImageAvailableListener
	class OnGetImageListener : public ImageReader::OnImageAvailableListener
	{
	private:
		static constexpr bool SAVE_PREVIEW_BITMAP = false;

		//324, 648, 972, 1296, 224, 448, 672, 976, 1344
		static constexpr int INPUT_SIZE = 976;
		static const std::wstring EARRING;
		static const std::wstring NECKWEAR;
		static const std::wstring CHAIN;
		static const std::wstring NECKLACE;
		static const std::wstring TAG;
		float resizeRatio = 4.5f;
		double mmToPixel = 3.779;

		//stabilization
		static constexpr int NUM_FRAMES_FOR_FPS = 100;
		int maxLevel = 5;
		//Initial value, actual value calculated after 100 frames
		int fps = 10;
		int sigma = 100;
		Size *winSize = new Size();
		Image *image = nullptr;
		long long tickCount = 0;

		std::vector<org::opencv::core::Point*> points = std::vector<org::opencv::core::Point*>();
		std::vector<org::opencv::core::Point*> pointsPrev = std::vector<org::opencv::core::Point*>();
		std::vector<org::opencv::core::Point*> pointsNeck = std::vector<org::opencv::core::Point*>();
		std::vector<org::opencv::core::Point*> pointsPrevNeck = std::vector<org::opencv::core::Point*>();
		std::vector<Point*> imageLandmarks = std::vector<Point*>();
		std::vector<Point*> newImageLandmarks = std::vector<Point*>();

		bool isFirstFrame = true;
		int imagePreviewWidth = 0;
		int imagePreviewHeight = 0;
		Mat *mRGBframe = new Mat();
		Mat *mGrayframe = new Mat();
		Mat *imageRGBframe = new Mat();
		Mat *imageGrayframe = new Mat();

		MatOfByte *status = new MatOfByte();
		MatOfFloat *err = new MatOfFloat();
		MatOfPoint2f *pointsPrevArr = new MatOfPoint2f();
		MatOfPoint2f *pointsArr = new MatOfPoint2f();
		MatOfPoint2f *pointsPrevArrNeck = new MatOfPoint2f();
		MatOfPoint2f *pointsArrNeck = new MatOfPoint2f();
		std::vector<org::opencv::core::Point*> opencvLandmarks = std::vector<org::opencv::core::Point*>();
		std::vector<org::opencv::core::Point*> newOpencvLandmarks = std::vector<org::opencv::core::Point*>();
		TermCriteria *termCriteria = new TermCriteria();

		Mat *prevGrayframe = new Mat();
		Mat *currGrayframe = new Mat();

		int mScreenRotation = 0;
		std::vector<VisionDetRet*> results;
		std::vector<VisionDetRet*> neckResults;
		int mPreviewWdith = 0;
		int mPreviewHeight = 0;
		std::vector<std::vector<signed char>> mYUVBytes;
		std::vector<int> mRGBBytes;
		Bitmap *mRGBframeBitmap = nullptr;
		Bitmap *mCroppedBitmap = nullptr;
		Bitmap *mResizedBitmap = nullptr;
		Bitmap *mInversedBipmap = nullptr;
		bool mIsComputing = false;
		Handler *mInferenceHandler;

		Context *mContext;
		FaceDet *mFaceDet;
		FaceDet *mNeckDet;
		TrasparentTitleView *mTransparentTitleView;
		FloatingCameraWindow *mWindow;
		Paint *mFaceLandmarkPaint;
		int mframeNum = 0;

	public:
		virtual ~OnGetImageListener()
		{
			delete winSize;
			delete image;
			delete mRGBframe;
			delete mGrayframe;
			delete imageRGBframe;
			delete imageGrayframe;
			delete status;
			delete err;
			delete pointsPrevArr;
			delete pointsArr;
			delete pointsPrevArrNeck;
			delete pointsArrNeck;
			delete termCriteria;
			delete prevGrayframe;
			delete currGrayframe;
			delete mRGBframeBitmap;

//====================================================================================================
//End of the allowed output for the Free Edition of Java to C++ Converter.

//To purchase the Premium Edition, visit our website:
//https://www.tangiblesoftwaresolutions.com/order/order-java-to-cplus.html
//====================================================================================================
