#include "ProductEntry.h"

namespace com::tzutalin::dlibtest
{
	using Resources = android::content::res::Resources;
	using Uri = android::net::Uri;
	using Log = android::util::Log;
	using Gson = com::google::gson::Gson;
	using TypeToken = com::google::gson::reflect::TypeToken;
	using BufferedReader = java::io::BufferedReader;
	using IOException = java::io::IOException;
	using InputStream = java::io::InputStream;
	using InputStreamReader = java::io::InputStreamReader;
	using Reader = java::io::Reader;
	using StringWriter = java::io::StringWriter;
	using Writer = java::io::Writer;
	using Type = java::lang::reflect::Type;
	using ArrayList = java::util::ArrayList;
	using List = java::util::List;
const std::wstring ProductEntry::TAG = ProductEntry::class->getSimpleName();

	ProductEntry::ProductEntry(const std::wstring &title, const std::wstring &dynamicUrl, const std::wstring &url, const std::wstring &price, const std::wstring &description, const std::wstring &height, const std::wstring &width) : title(title), dynamicUrl(Uri::parse(dynamicUrl)), url(url), price(price), description(description), height(height), width(width)
	{
	}

	std::vector<ProductEntry*> ProductEntry::initProductEntryList(Resources *resources, const std::wstring &menuItem)
	{
		InputStream *inputStream = nullptr;
		if (menuItem == L"Earrings")
		{
			inputStream = resources->openRawResource(R::raw::products);
		}
		else if (menuItem == L"Neck Jewellery")
		{
			inputStream = resources->openRawResource(R::raw::neckwearproducts);
		}
		Writer *writer = new StringWriter();
		std::vector<wchar_t> buffer(1024);
		try
		{
			InputStreamReader tempVar(inputStream, L"UTF-8");
			Reader *reader = new BufferedReader(&tempVar);
			int pointer;
			while ((pointer = reader->read(buffer)) != -1)
			{
				writer->write(buffer, 0, pointer);
			}

			delete reader;
		}
		catch (const IOException &exception)
		{
			Log::e(TAG, L"Error writing/reading from the JSON file.", exception);
		}
//JAVA TO C++ CONVERTER TODO TASK: There is no C++ equivalent to the exception 'finally' clause:
		finally
		{
			try
			{
				inputStream->close();
			}
			catch (const IOException &exception)
			{
				Log::e(TAG, L"Error closing the input stream.", exception);
			}
		}
//JAVA TO C++ CONVERTER TODO TASK: There is no C++ equivalent to 'toString':
		std::wstring jsonProductsString = writer->toString();
		Gson *gson = new Gson();
		TypeTokenAnonymousInnerClass tempVar2();
		Type *productListType = (&tempVar2)->getType();

		delete gson;
		delete writer;
		return gson->fromJson(jsonProductsString, productListType);
	}
}
