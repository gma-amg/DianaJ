#include "ImageUtils.h"

namespace com::tzutalin::dlibtest
{
	using Bitmap = android::graphics::Bitmap;
	using Environment = android::os::Environment;
	using Keep = androidx::annotation::Keep;
	using File = java::io::File;
	using FileOutputStream = java::io::FileOutputStream;
	using Timber = timber::log::Timber;
const std::wstring ImageUtils::TAG = ImageUtils::class->getSimpleName();

	int ImageUtils::getYUVByteSize(int const width, int const height)
	{
		// The luminance plane requires 1 byte per pixel.
		constexpr int ySize = width * height;

		// The UV plane works on 2x2 blocks, so dimensions with odd size must be rounded up.
		// Each 2x2 block takes 2 bytes to encode, one each for U and V.
		constexpr int uvSize = ((width + 1) / 2) * ((height + 1) / 2) * 2;

		return ySize + uvSize;
	}

	void ImageUtils::saveBitmap(Bitmap *const bitmap)
	{
		const std::wstring root = Environment::getExternalStorageDirectory().getAbsolutePath() + File::separator + L"dlib";
		Timber::tag(TAG).d(std::wstring::format(L"Saving %dx%d bitmap to %s.", bitmap->getWidth(), bitmap->getHeight(), root));
		File * const myDir = new File(root);

		if (!myDir->mkdirs())
		{
			Timber::tag(TAG).e(L"Make dir failed");
		}

		const std::wstring fname = L"preview.png";
		File * const file = new File(myDir, fname);
		if (file->exists())
		{
			file->delete();
		}
		try
		{
			FileOutputStream * const out = new FileOutputStream(file);
			bitmap->compress(Bitmap::CompressFormat::PNG, 99, out);
			out->flush();
			out->close();
		}
//JAVA TO C++ CONVERTER WARNING: 'final' catch parameters are not available in C++:
//ORIGINAL LINE: catch (final Exception e)
		catch (const std::runtime_error &e)
		{
			Timber::tag(TAG).e(L"Exception!", e);
		}
	}
}
