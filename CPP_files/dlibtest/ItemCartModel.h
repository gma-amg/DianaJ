#pragma once

#include <string>

namespace com::tzutalin::dlibtest
{


	class ItemCartModel
	{

	private:
		std::wstring itemImages;
		std::wstring itemName;
		int itemPrice = 0;
		int itemQuantity = 0;

	public:
		virtual std::wstring getItemImages();

		virtual void setItemImages(const std::wstring &itemImages);

		virtual std::wstring getItemName();

		virtual void setItemName(const std::wstring &itemName);

		virtual int getItemPrice();

		virtual void setItemPrice(int itemPrice);

		virtual int getItemQuantity();

		virtual void setItemQuantity(int itemQuantity);
	};

}
