#pragma once

#include "ItemCartModel.h"
#include <string>
#include <unordered_map>
#include <vector>
#include <any>

namespace com::tzutalin::dlibtest
{

	using Application = android::app::Application;
	using Drawable = android::graphics::drawable::Drawable;

	using ArrayList = java::util::ArrayList;
	using HashMap = java::util::HashMap;

	class AppData : public Application
	{

	private:
		Drawable *image;
		int imageId = 0;
		std::any tag;
		std::wstring rightSideImageId;
		std::wstring leftSideImageId;
		std::wstring menuItem;
		std::wstring height;
		std::wstring width;

		std::wstring itemName;
		std::vector<std::wstring> productAddedToCart;
		std::vector<std::wstring> productRemovedFromCart;
		std::unordered_map<std::wstring, Drawable*> imageAddedToCart;
		std::unordered_map<int, ItemCartModel*> productDetails;

	public:
		virtual ~AppData()
		{
			delete image;
		}

		virtual std::wstring getRightSideImageId();

		virtual void setRightSideImageId(const std::wstring &imageId);

		virtual std::wstring getLeftSideImageId();

		virtual void setLeftSideImageId(const std::wstring &imageId);

		virtual int getImageId();

		virtual void setImageId(int imageId);
		virtual Drawable *getImage();

		virtual void setImage(Drawable *image);

		virtual std::any getTag();

		virtual void setTag(std::any tag);

		virtual std::wstring getMenuItem();

		virtual void setMenuItem(const std::wstring &menuItem);

		virtual std::wstring getHeight();

		virtual void setHeight(const std::wstring &height);

		virtual std::wstring getWidth();

		virtual void setWidth(const std::wstring &width);

		virtual std::unordered_map<std::wstring, Drawable*> getImageAddedToCart();

		virtual void setImageAddedToCart(std::unordered_map<std::wstring, Drawable*> &imageAddedToCart);

		virtual std::wstring getItemName();

		virtual void setItemName(const std::wstring &itemName);

		virtual std::vector<std::wstring> getProductAddedToCart();

		virtual void setProductAddedToCart(std::vector<std::wstring> &productAddedToCart);

		virtual std::vector<std::wstring> getProductRemovedFromCart();

		virtual void setProductRemovedFromCart(std::vector<std::wstring> &productRemovedFromCart);

		virtual std::unordered_map<int, ItemCartModel*> getProductDetails();

		virtual void setProductDetails(std::unordered_map<int, ItemCartModel*> &productDetails);
	};

}
