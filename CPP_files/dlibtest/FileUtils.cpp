#include "FileUtils.h"

namespace com::tzutalin::dlibtest
{
	using Context = android::content::Context;
	using NonNull = androidx::annotation::NonNull;
	using RawRes = androidx::annotation::RawRes;
	using FileOutputStream = java::io::FileOutputStream;
	using IOException = java::io::IOException;
	using InputStream = java::io::InputStream;

//JAVA TO C++ CONVERTER TODO TASK: Most Java annotations will not have direct C++ equivalents:
//ORIGINAL LINE: @NonNull public static final void copyFileFromRawToOthers(@NonNull final android.content.Context context, @RawRes int id, @NonNull final String targetPath)
	void FileUtils::copyFileFromRawToOthers(Context *const context, int id, const std::wstring &targetPath)
	{
		InputStream *in = context->getResources().openRawResource(id);
		FileOutputStream *out = nullptr;
		try
		{
			out = new FileOutputStream(targetPath);
			std::vector<signed char> buff(1024);
			int read = 0;
			while ((read = in->read(buff)) > 0)
			{
				out->write(buff, 0, read);
			}
		}
		catch (const std::runtime_error &e)
		{
			e.printStackTrace();
		}
//JAVA TO C++ CONVERTER TODO TASK: There is no C++ equivalent to the exception 'finally' clause:
		finally
		{
			try
			{
				if (in != nullptr)
				{
					in->close();
				}
				if (out != nullptr)
				{
					out->close();
				}
			}
			catch (const IOException &e)
			{
				e->printStackTrace();
			}
		}

//JAVA TO C++ CONVERTER TODO TASK: A 'delete out' statement was not added since out was passed to a method or constructor. Handle memory management manually.
	}
}
