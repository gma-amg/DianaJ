#include "AppData.h"

namespace com::tzutalin::dlibtest
{
	using Application = android::app::Application;
	using Drawable = android::graphics::drawable::Drawable;
	using ArrayList = java::util::ArrayList;
	using HashMap = java::util::HashMap;

	std::wstring AppData::getRightSideImageId()
	{
		return rightSideImageId;
	}

	void AppData::setRightSideImageId(const std::wstring &imageId)
	{
		this->rightSideImageId = imageId;
	}

	std::wstring AppData::getLeftSideImageId()
	{
		return leftSideImageId;
	}

	void AppData::setLeftSideImageId(const std::wstring &imageId)
	{
		this->leftSideImageId = imageId;
	}

	int AppData::getImageId()
	{
		return imageId;
	}

	void AppData::setImageId(int imageId)
	{
		this->imageId = imageId;
	}

	Drawable *AppData::getImage()
	{
		return image;
	}

	void AppData::setImage(Drawable *image)
	{
		this->image = image;
	}

	std::any AppData::getTag()
	{
		return tag;
	}

	void AppData::setTag(std::any tag)
	{
		this->tag = tag;
	}

	std::wstring AppData::getMenuItem()
	{
		return menuItem;
	}

	void AppData::setMenuItem(const std::wstring &menuItem)
	{
		this->menuItem = menuItem;
	}

	std::wstring AppData::getHeight()
	{
		return height;
	}

	void AppData::setHeight(const std::wstring &height)
	{
		this->height = height;
	}

	std::wstring AppData::getWidth()
	{
		return width;
	}

	void AppData::setWidth(const std::wstring &width)
	{
		this->width = width;
	}

	std::unordered_map<std::wstring, Drawable*> AppData::getImageAddedToCart()
	{
		return imageAddedToCart;
	}

	void AppData::setImageAddedToCart(std::unordered_map<std::wstring, Drawable*> &imageAddedToCart)
	{
		this->imageAddedToCart = imageAddedToCart;
	}

	std::wstring AppData::getItemName()
	{
		return itemName;
	}

	void AppData::setItemName(const std::wstring &itemName)
	{
		this->itemName = itemName;
	}

	std::vector<std::wstring> AppData::getProductAddedToCart()
	{
		return productAddedToCart;
	}

	void AppData::setProductAddedToCart(std::vector<std::wstring> &productAddedToCart)
	{
		this->productAddedToCart = productAddedToCart;
	}

	std::vector<std::wstring> AppData::getProductRemovedFromCart()
	{
		return productRemovedFromCart;
	}

	void AppData::setProductRemovedFromCart(std::vector<std::wstring> &productRemovedFromCart)
	{
		this->productRemovedFromCart = productRemovedFromCart;
	}

	std::unordered_map<int, ItemCartModel*> AppData::getProductDetails()
	{
		return productDetails;
	}

	void AppData::setProductDetails(std::unordered_map<int, ItemCartModel*> &productDetails)
	{
		this->productDetails = productDetails;
	}
}
