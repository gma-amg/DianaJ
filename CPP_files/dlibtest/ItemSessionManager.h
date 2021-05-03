#pragma once

#include "ItemCartModel.h"
#include <string>
#include <vector>

namespace com::tzutalin::dlibtest
{
	using Context = android::content::Context;
	using SharedPreferences = android::content::SharedPreferences;
	using Editor = android::content::SharedPreferences::Editor;


	using ArrayList = java::util::ArrayList;

	class ItemSessionManager
	{
	public:
		SharedPreferences *pref;
		SharedPreferences::Editor *editor;
		std::vector<SharedPreferences::Editor*> arrEditor;
		Context *_context;
		int PRIVATE_MODE = 0;
	private:
		static const std::wstring PREFER_NAME;
		static const std::wstring IS_ITEM_ADDED;
	public:
		static const std::wstring KEY_ITEM_NAME;
	private:
		static const std::wstring ADD_ITEM_TO_CART;
		static const std::wstring ITEM_REMOVED_FROM_CART;
		static ItemSessionManager *singleInstance;

		std::vector<std::wstring> productAddedToCart;
	public:
		virtual ~ItemSessionManager()
		{
			delete pref;
			delete editor;
			delete _context;
		}

		virtual std::vector<std::wstring> getProductAddedToCart();
		virtual void setProductAddedToCart(std::vector<std::wstring> &productAddedToCart);

	private:
		std::vector<std::wstring> productRemovedFromCart;
	public:
		virtual std::vector<std::wstring> getProductRemovedFromCart();
		virtual void setProductRemovedFromCart(std::vector<std::wstring> &productRemovedFromCart);


		static ItemSessionManager *getInstance(Context *context);

		// Constructor
		ItemSessionManager(Context *context);

		//Create login session
		virtual void addItemToCart(const std::wstring &itemName);


		virtual std::vector<std::wstring> getUserDetails();

		virtual void addItemTOCart(std::vector<ItemCartModel*> &arrItem);

		virtual std::vector<ItemCartModel*> loadData();

	private:
		class TypeTokenAnonymousInnerClass : public TypeToken<std::vector<ItemCartModel*>>
		{
		private:
			ItemSessionManager *outerInstance;

		public:
			virtual ~TypeTokenAnonymousInnerClass()
			{
				delete outerInstance;
			}

			TypeTokenAnonymousInnerClass(ItemSessionManager *outerInstance);

		};
	public:
		virtual void removItemFromCart(const std::wstring &itemName);


		virtual void setItemAddedToCart(std::vector<std::wstring> &arrItem);

		virtual std::vector<std::wstring> getItemAddedToCart();

	private:
		class TypeTokenAnonymousInnerClass2 : public TypeToken<std::vector<std::wstring>>
		{
		private:
			ItemSessionManager *outerInstance;

		public:
			virtual ~TypeTokenAnonymousInnerClass2()
			{
				delete outerInstance;
			}

			TypeTokenAnonymousInnerClass2(ItemSessionManager *outerInstance);

		};

		/**
	
		 public void removeItemAddedToCart(String itemName){
		 SharedPreferences sharedPreferences = _context.getSharedPreferences(ADD_ITEM_TO_CART, PRIVATE_MODE);
		 Editor editor = sharedPreferences.edit() ;
		 // Storing login value as TRUE
		 editor.putBoolean(IS_ITEM_ADDED, true);
		 // Storing name in pref
		 editor.remove(itemName);
		 editor.clear();
		 // commit changes
		 editor.commit();
		 }
	
	
	
		 public void setItemRemovedFromCart(ArrayList<String> arrItem) {
		 SharedPreferences sharedPreferences = _context.getSharedPreferences(ITEM_REMOVED_FROM_CART, PRIVATE_MODE);
		 Editor editor = sharedPreferences.edit() ;
		 Gson gson = new Gson() ;
		 String json = gson.toJson(arrItem) ;
		 editor.putString("ITEM_REMOVED_FROM_CART", json) ;
		 editor.apply();
		 }
	
		 public ArrayList<String> getItemRemovedFromCart(){
		 ArrayList<String> arrItem = null;
		 SharedPreferences sharedPreferences = _context.getSharedPreferences(ITEM_REMOVED_FROM_CART, PRIVATE_MODE);
		 Gson gson = new Gson() ;
		 String json = sharedPreferences.getString("ITEM_REMOVED_FROM_CART", null) ;
		 Type type = new TypeToken<ArrayList<String>>() {}.getType();
		 arrItem  =  (ArrayList<String>) gson.fromJson(json, type) ;
		 if (arrItem == null) {
		 arrItem = new ArrayList();
		 }
		 return arrItem ;
		 }
	
		 public void removedFromCart(String itemName){
		 SharedPreferences sharedPreferences = _context.getSharedPreferences(ITEM_REMOVED_FROM_CART, PRIVATE_MODE);
		 //String json = sharedPreferences.getString("ITEM_REMOVED_FROM_CART", null) ;
		 String str = itemName ;
		 Editor editor = sharedPreferences.edit() ;
		 ArrayList<String> itemList = getItemRemovedFromCart() ;
		 itemList.remove(itemName) ;
		 Gson gson = new Gson() ;
		 String json = gson.toJson(itemList) ;
		 editor.putString("ITEM_REMOVED_FROM_CART", json) ;
		 editor.remove(itemName);
		 editor.apply();
		 editor.commit();
		 }
		 /**/

	};

}
