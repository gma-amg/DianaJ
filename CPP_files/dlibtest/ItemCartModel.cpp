#include "ItemCartModel.h"

namespace com::tzutalin::dlibtest
{
	using Drawable = android::graphics::drawable::Drawable;

	std::wstring ItemCartModel::getItemImages()
	{
		return itemImages;
	}

	void ItemCartModel::setItemImages(const std::wstring &itemImages)
	{
		this->itemImages = itemImages;
	}

	std::wstring ItemCartModel::getItemName()
	{
		return itemName;
	}

	void ItemCartModel::setItemName(const std::wstring &itemName)
	{
		this->itemName = itemName;
	}

	int ItemCartModel::getItemPrice()
	{
		return itemPrice;
	}

	void ItemCartModel::setItemPrice(int itemPrice)
	{
		this->itemPrice = itemPrice;
	}

	int ItemCartModel::getItemQuantity()
	{
		return itemQuantity;
	}

	void ItemCartModel::setItemQuantity(int itemQuantity)
	{
		this->itemQuantity = itemQuantity;
	}
}
