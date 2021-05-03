#pragma once

#include <string>
#include <vector>
#include "exceptionhelper.h"

namespace com::tzutalin::dlibtest
{

	using Resources = android::content::res::Resources;
	using Uri = android::net::Uri;


	using List = java::util::List;

	/**
	 * A product entry in the list of products.
	 */
	class ProductEntry
	{
	private:
//JAVA TO C++ CONVERTER TODO TASK: There is no C++ equivalent to the Java 'class' method:
		static const std::wstring TAG;

	public:
		const std::wstring title;
		Uri *const dynamicUrl;
		const std::wstring url;
		const std::wstring price;
		const std::wstring description;
		const std::wstring height;
		const std::wstring width;

		virtual ~ProductEntry()
		{
			delete dynamicUrl;
		}

		ProductEntry(const std::wstring &title, const std::wstring &dynamicUrl, const std::wstring &url, const std::wstring &price, const std::wstring &description, const std::wstring &height, const std::wstring &width);

		/**
		 * Loads a raw JSON at R.raw.products and converts it into a list of ProductEntry objects
		 */
		static std::vector<ProductEntry*> initProductEntryList(Resources *resources, const std::wstring &menuItem);

	private:
		class TypeTokenAnonymousInnerClass : public TypeToken<std::vector<ProductEntry*>>
		{
		};
	};
}
