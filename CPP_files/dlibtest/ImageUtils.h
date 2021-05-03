#pragma once

#include <string>
#include <vector>
#include <stdexcept>

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

	using Bitmap = android::graphics::Bitmap;




	/**
	 * Utility class for manipulating images.
	 **/
	class ImageUtils
	{
	private:
//JAVA TO C++ CONVERTER TODO TASK: There is no C++ equivalent to the Java 'class' method:
		static const std::wstring TAG;

		/**
		 * Utility method to compute the allocated size in bytes of a YUV420SP image
		 * of the given dimensions.
		 */
	public:
		static int getYUVByteSize(int const width, int const height);

		/**
		 * Saves a Bitmap object to disk for analysis.
		 *
		 * @param bitmap The bitmap to save.
		 */
		static void saveBitmap(Bitmap *const bitmap);

		/**
		 * Converts YUV420 semi-planar data to ARGB 8888 data using the supplied width
		 * and height. The input and output must already be allocated and non-null.
		 * For efficiency, no error checking is performed.
		 *
		 * @param input    The array of YUV 4:2:0 input data.
		 * @param output   A pre-allocated array for the ARGB 8:8:8:8 output data.
		 * @param width    The width of the input image.
		 * @param height   The height of the input image.
		 * @param halfSize If true, downsample to 50% in each dimension, otherwise not.
		 */
//JAVA TO C++ CONVERTER NOTE: The following Java 'native' declaration was converted using the Microsoft-specific __declspec(dllimport):
//		public static native void convertYUV420SPToARGB8888(byte[] input, int[] output, int width, int height, boolean halfSize);
		__declspec(dllimport) static void convertYUV420SPToARGB8888(std::vector<signed char> &input, std::vector<int> &output, int width, int height, bool halfSize);

		/**
		 * Converts YUV420 semi-planar data to ARGB 8888 data using the supplied width
		 * and height. The input and output must already be allocated and non-null.
		 * For efficiency, no error checking is performed.
		 *
		 * @param y
		 * @param u
		 * @param v
		 * @param uvPixelStride
		 * @param width         The width of the input image.
		 * @param height        The height of the input image.
		 * @param halfSize      If true, downsample to 50% in each dimension, otherwise not.
		 * @param output        A pre-allocated array for the ARGB 8:8:8:8 output data.
		 */
//JAVA TO C++ CONVERTER NOTE: The following Java 'native' declaration was converted using the Microsoft-specific __declspec(dllimport):
//		public static native void convertYUV420ToARGB8888(byte[] y, byte[] u, byte[] v, int[] output, int width, int height, int yRowStride, int uvRowStride, int uvPixelStride, boolean halfSize);
//JAVA TO C++ CONVERTER TODO TASK: Most Java annotations will not have direct C++ equivalents:
//ORIGINAL LINE: @Keep public static native void convertYUV420ToARGB8888(byte[] y, byte[] u, byte[] v, int[] output, int width, int height, int yRowStride, int uvRowStride, int uvPixelStride, boolean halfSize);
		__declspec(dllimport) static void convertYUV420ToARGB8888(std::vector<signed char> &y, std::vector<signed char> &u, std::vector<signed char> &v, std::vector<int> &output, int width, int height, int yRowStride, int uvRowStride, int uvPixelStride, bool halfSize);

		/**
		 * Converts YUV420 semi-planar data to RGB 565 data using the supplied width
		 * and height. The input and output must already be allocated and non-null.
		 * For efficiency, no error checking is performed.
		 *
		 * @param input  The array of YUV 4:2:0 input data.
		 * @param output A pre-allocated array for the RGB 5:6:5 output data.
		 * @param width  The width of the input image.
		 * @param height The height of the input image.
		 */
//JAVA TO C++ CONVERTER NOTE: The following Java 'native' declaration was converted using the Microsoft-specific __declspec(dllimport):
//		public static native void convertYUV420SPToRGB565(byte[] input, byte[] output, int width, int height);
//JAVA TO C++ CONVERTER TODO TASK: Most Java annotations will not have direct C++ equivalents:
//ORIGINAL LINE: @Keep public static native void convertYUV420SPToRGB565(byte[] input, byte[] output, int width, int height);
		__declspec(dllimport) static void convertYUV420SPToRGB565(std::vector<signed char> &input, std::vector<signed char> &output, int width, int height);

		/**
		 * Converts 32-bit ARGB8888 image data to YUV420SP data.  This is useful, for
		 * instance, in creating data to feed the classes that rely on raw camera
		 * preview frames.
		 *
		 * @param input  An array of input pixels in ARGB8888 format.
		 * @param output A pre-allocated array for the YUV420SP output data.
		 * @param width  The width of the input image.
		 * @param height The height of the input image.
		 */
//JAVA TO C++ CONVERTER NOTE: The following Java 'native' declaration was converted using the Microsoft-specific __declspec(dllimport):
//		public static native void convertARGB8888ToYUV420SP(int[] input, byte[] output, int width, int height);
//JAVA TO C++ CONVERTER TODO TASK: Most Java annotations will not have direct C++ equivalents:
//ORIGINAL LINE: @Keep public static native void convertARGB8888ToYUV420SP(int[] input, byte[] output, int width, int height);
		__declspec(dllimport) static void convertARGB8888ToYUV420SP(std::vector<int> &input, std::vector<signed char> &output, int width, int height);

		/**
		 * Converts 16-bit RGB565 image data to YUV420SP data.  This is useful, for
		 * instance, in creating data to feed the classes that rely on raw camera
		 * preview frames.
		 *
		 * @param input  An array of input pixels in RGB565 format.
		 * @param output A pre-allocated array for the YUV420SP output data.
		 * @param width  The width of the input image.
		 * @param height The height of the input image.
		 */
//JAVA TO C++ CONVERTER NOTE: The following Java 'native' declaration was converted using the Microsoft-specific __declspec(dllimport):
//		public static native void convertRGB565ToYUV420SP(byte[] input, byte[] output, int width, int height);
//JAVA TO C++ CONVERTER TODO TASK: Most Java annotations will not have direct C++ equivalents:
//ORIGINAL LINE: @Keep public static native void convertRGB565ToYUV420SP(byte[] input, byte[] output, int width, int height);
		__declspec(dllimport) static void convertRGB565ToYUV420SP(std::vector<signed char> &input, std::vector<signed char> &output, int width, int height);
	};

}
