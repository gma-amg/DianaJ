//====================================================================================================
//The Free Edition of Java to C++ Converter limits conversion output to 100 lines per file.

//To purchase the Premium Edition, visit our website:
//https://www.tangiblesoftwaresolutions.com/order/order-java-to-cplus.html
//====================================================================================================

#include "ItemSessionManager.h"

namespace com::tzutalin::dlibtest
{
	using Context = android::content::Context;
	using SharedPreferences = android::content::SharedPreferences;
	using Editor = android::content::SharedPreferences::Editor;
	using Log = android::util::Log;
	using Gson = com::google::gson::Gson;
	using TypeToken = com::google::gson::reflect::TypeToken;
	using Type = java::lang::reflect::Type;
	using ArrayList = java::util::ArrayList;
const std::wstring ItemSessionManager::PREFER_NAME = L"AndroidExamplePref";
const std::wstring ItemSessionManager::IS_ITEM_ADDED = L"IsItemAdded";
const std::wstring ItemSessionManager::KEY_ITEM_NAME = L"item_added";
const std::wstring ItemSessionManager::ADD_ITEM_TO_CART = L"AddItemToCart";
const std::wstring ItemSessionManager::ITEM_REMOVED_FROM_CART = L"ItemRemovedFromCart";
ItemSessionManager *ItemSessionManager::singleInstance = nullptr;

	std::vector<std::wstring> ItemSessionManager::getProductAddedToCart()
	{
		return productAddedToCart;
	}

	void ItemSessionManager::setProductAddedToCart(std::vector<std::wstring> &productAddedToCart)
	{
		this->productAddedToCart = productAddedToCart;
	}

	std::vector<std::wstring> ItemSessionManager::getProductRemovedFromCart()
	{
		return productRemovedFromCart;
	}

	void ItemSessionManager::setProductRemovedFromCart(std::vector<std::wstring> &productRemovedFromCart)
	{
		this->productRemovedFromCart = productRemovedFromCart;
	}

	ItemSessionManager *ItemSessionManager::getInstance(Context *context)
	{
		if (singleInstance == nullptr)
		{
			singleInstance = new ItemSessionManager(context);
		}

		return singleInstance;
	}

	ItemSessionManager::ItemSessionManager(Context *context)
	{
		this->_context = context;
		pref = _context->getSharedPreferences(PREFER_NAME, PRIVATE_MODE);
		editor = pref->edit();
		editor->clear();
		editor->commit();

		pref = _context->getSharedPreferences(ADD_ITEM_TO_CART, PRIVATE_MODE);
		editor = pref->edit();
		editor->clear();
		editor->commit();

		pref = _context->getSharedPreferences(ITEM_REMOVED_FROM_CART, PRIVATE_MODE);
		editor = pref->edit();
		editor->clear();
		editor->commit();

	}

	void ItemSessionManager::addItemToCart(const std::wstring &itemName)
	{
		// Storing login value as TRUE
		editor->putBoolean(IS_ITEM_ADDED, true);

		// Storing name in pref
		editor->putString(KEY_ITEM_NAME, itemName);

		// commit changes
		editor->commit();
	}

	std::vector<std::wstring> ItemSessionManager::getUserDetails()
	{
		std::vector<std::wstring> user;
		Log::i(L"MyApplication", L"Set the session object.");
		user.push_back(pref->getString(KEY_ITEM_NAME, nullptr));
		return user;
	}

	void ItemSessionManager::addItemTOCart(std::vector<ItemCartModel*> &arrItem)
	{
		SharedPreferences *sharedPreferences = _context->getSharedPreferences(PREFER_NAME, PRIVATE_MODE);
		SharedPreferences::Editor *editor = sharedPreferences->edit();
		Gson *gson = new Gson();
		std::wstring json = gson->toJson(arrItem);
		editor->putString(L"Add_TO_CART", json);
		editor->apply();

		delete gson;
	}

	std::vector<ItemCartModel*> ItemSessionManager::loadData()
	{
		std::vector<ItemCartModel*> arrItem;
		SharedPreferences *sharedPreferences = _context->getSharedPreferences(PREFER_NAME, PRIVATE_MODE);
		SharedPreferences::Editor *editor = sharedPreferences->edit();
		Gson *gson = new Gson();
		std::wstring json = sharedPreferences->getString(L"Add_TO_CART", nullptr);
		TypeTokenAnonymousInnerClass tempVar(this);
		Type *type = (&tempVar)->getType();
		arrItem = static_cast<std::vector<ItemCartModel*>>(gson->fromJson(json, type));
		if (arrItem.empty())
		{
			arrItem = std::vector();
		}

		delete gson;
		return arrItem;

	}

	ItemSessionManager::TypeTokenAnonymousInnerClass::TypeTokenAnonymousInnerClass(ItemSessionManager *outerInstance) : outerInstance(outerInstance)
	{
	}

	void ItemSessionManager::removItemFromCart(const std::wstring &itemName)
	{
		SharedPreferences *sharedPreferences = _context->getSharedPreferences(PREFER_NAME, PRIVATE_MODE);
		//String json = sharedPreferences.getString("ITEM_REMOVED_FROM_CART", null) ;
		SharedPreferences::Editor *editor = sharedPreferences->edit();
		std::vector<ItemCartModel*> itemList = loadData();

		/***   // to remove 1 to 1 item from the cart
		 for (int i = 0; i< itemList.size(); i++) {
		 if( itemList.get(i).getItemName().equalsIgnoreCase(itemName)) {
		 itemList.remove(itemList.get(i)) ;
		 break;
		 }
		 }
		 /***/

		/***/
		// to remove all the item fom the cat
		for (int i = itemList.size() - 1; i >= 0; i--)
		{
//JAVA TO C++ CONVERTER TODO TASK: The following Java case-insensitive String method call is not converted:
			if (itemList[i]->getItemName().equalsIgnoreCase(itemName))
			{
//JAVA TO C++ CONVERTER TODO TASK: The Java Collection 'remove(Object)' method is not converted:
				itemList.remove(itemList[i]);
				// break;
			}
		}
		/***/

		//itemList.remove(itemList.get(count)) ;
		Gson *gson = new Gson();
		std::wstring json = gson->toJson(itemList);
		editor->clear();
		int num = itemList.size();
		editor->putString(L"Add_TO_CART", json);
		//editor.remove(itemName);
		editor->apply();
		editor->commit();

		delete gson;
	}

	void ItemSessionManager::setItemAddedToCart(std::vector<std::wstring> &arrItem)
	{
		SharedPreferences *sharedPreferences = _context->getSharedPreferences(ADD_ITEM_TO_CART, PRIVATE_MODE);
		SharedPreferences::Editor *editor = sharedPreferences->edit();
		Gson *gson = new Gson();
		std::wstring json = gson->toJson(arrItem);
		editor->putString(L"ITEM_Add_TO_CART", json);
		editor->apply();

		delete gson;
	}

	std::vector<std::wstring> ItemSessionManager::getItemAddedToCart()
	{
		std::vector<std::wstring> arrItem;
		SharedPreferences *sharedPreferences = _context->getSharedPreferences(ADD_ITEM_TO_CART, PRIVATE_MODE);
		Gson *gson = new Gson();
		std::wstring json = sharedPreferences->getString(L"ITEM_Add_TO_CART", nullptr);

//====================================================================================================
//End of the allowed output for the Free Edition of Java to C++ Converter.

//To purchase the Premium Edition, visit our website:
//https://www.tangiblesoftwaresolutions.com/order/order-java-to-cplus.html
//====================================================================================================
