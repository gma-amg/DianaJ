#include "CartMain.h"
#include "ItemSessionManager.h"
#include "CartRecyclerViewAdapter.h"
#include "ItemCartModel.h"
#include "AppData.h"

namespace com::tzutalin::dlibtest
{
	using Context = android::content::Context;
	using Intent = android::content::Intent;
	using Drawable = android::graphics::drawable::Drawable;
	using Bundle = android::os::Bundle;
	using LayoutInflater = android::view::LayoutInflater;
	using Menu = android::view::Menu;
	using MenuInflater = android::view::MenuInflater;
	using View = android::view::View;
	using ViewGroup = android::view::ViewGroup;
	using Button = android::widget::Button;
	using ArrayList = java::util::ArrayList;
	using HashMap = java::util::HashMap;
	using Map = java::util::Map;
	using NonNull = androidx::annotation::NonNull;
	using Fragment = androidx::fragment::app::Fragment;
	using FragmentTransaction = androidx::fragment::app::FragmentTransaction;
	using GridLayoutManager = androidx::recyclerview::widget::GridLayoutManager;
	using RecyclerView = androidx::recyclerview::widget::RecyclerView;

	void CartMain::onCreate(Bundle *savedInstanceState)
	{
		androidx::fragment::app::Fragment::onCreate(savedInstanceState);
		setHasOptionsMenu(true);
	}

//JAVA TO C++ CONVERTER TODO TASK: Most Java annotations will not have direct C++ equivalents:
//ORIGINAL LINE: @Override public android.view.View onCreateView(@NonNull LayoutInflater inflater, android.view.ViewGroup container, android.os.Bundle savedInstanceState)
	View *CartMain::onCreateView(LayoutInflater *inflater, ViewGroup *container, Bundle *savedInstanceState)
	{
		// Inflate the layout for this fragment with the ProductGrid theme
		View *view = inflater->inflate(R::layout::shr_product_grid_fragment, container, false);
		// Set up the RecyclerView
		RecyclerView *recyclerView = view->findViewById(R::id::recycler_view);
		recyclerView->setHasFixedSize(true);
		GridLayoutManager tempVar(getContext(), 1, RecyclerView::VERTICAL, false);
		recyclerView->setLayoutManager(&tempVar);
		Context *ctx = recyclerView->getContext();

		ItemSessionManager *session = ItemSessionManager::getInstance(ctx);
	   // ArrayList<ItemCartModel> itemSelectedArr = session.loadData();
		std::wstring message = L"";
		setTableData(ctx);
		std::vector<std::wstring> productName1(productName.size());
		std::vector<std::wstring> productQuantity1(productQuantity.size());
		std::vector<Drawable*> drawableImage1(productName.size());
		if (productName.size() == 1)
		{
			  //productName1[0] = "No Item";
			  //productQuantity1[0] = "Found";
			 noRecordFound(productName1, productQuantity1, drawableImage1);
		}
		else
		{
			for (int i = 0; i < productName.size(); i++)
			{
				productName1[i] = productName[i];
				productQuantity1[i] = productQuantity[i];
				drawableImage1[i] = drawableImages[i];
			}
		}

		productName.push_back(L"Footer");
		productQuantity.push_back(L"Footer");
		drawableImages.push_back(nullptr);
		productUrl.push_back(nullptr);

		//Toast.makeText(ctx,"Added to Cart "+ itemSelectedArr.size() +" "+ message, Toast.LENGTH_SHORT).show();
		// CartRecyclerViewAdapter adapter = new CartRecyclerViewAdapter(ctx, productName1, productQuantity1, drawableImage1);
		CartRecyclerViewAdapter *adapter = new CartRecyclerViewAdapter(ctx, productName, productQuantity, drawableImages, productUrl);
		recyclerView->setAdapter(adapter);
		int largePadding = getResources().getDimensionPixelSize(R::dimen::shr_product_grid_spacing);
		int smallPadding = getResources().getDimensionPixelSize(R::dimen::shr_product_grid_spacing_small);
		//recyclerView.addItemDecoration(new ProductGridItemDecoration(largePadding, smallPadding));

//JAVA TO C++ CONVERTER TODO TASK: A 'delete adapter' statement was not added since adapter was passed to a method or constructor. Handle memory management manually.
		return view;
	}

	void CartMain::onCreateOptionsMenu(Menu *menu, MenuInflater *menuInflater)
	{
		menuInflater->inflate(R::menu::shr_toolbar_menu, menu);
		androidx::fragment::app::Fragment::onCreateOptionsMenu(menu, menuInflater);
	}

	void CartMain::setTableData(Context *ctx)
	{
		ItemSessionManager *session = ItemSessionManager::getInstance(ctx);
		std::vector<ItemCartModel*> itemSelectedArr = session->loadData();
		AppData * const appData = static_cast<AppData*>(getActivity().getApplicationContext());
		std::unordered_map<std::wstring, Drawable*> drImages = appData->getImageAddedToCart();
		std::vector<Drawable*> drImages1;
		productUrl = std::vector<std::wstring>();
		productUrl.push_back(nullptr);

		std::wstring message = L"";
		std::unordered_map<std::wstring, int> itemData;
		for (int i = 0; i < itemSelectedArr.size(); i++)
		{
			if (itemData.empty())
			{
				itemData.emplace(itemSelectedArr[i]->getItemName(), itemSelectedArr[i]->getItemQuantity());
				productUrl.push_back(itemSelectedArr[i]->getItemImages());
			}
			else
			{
				if (itemData.find(itemSelectedArr[i]->getItemName()) != itemData.end())
				{
					int count = itemData[itemSelectedArr[i]->getItemName()];
					itemData.erase(itemSelectedArr[i]->getItemName());
					itemData.emplace(itemSelectedArr[i]->getItemName(), itemSelectedArr[i]->getItemQuantity() + count);
				}
				else
				{
					itemData.emplace(itemSelectedArr[i]->getItemName(), itemSelectedArr[i]->getItemQuantity());
					productUrl.push_back(itemSelectedArr[i]->getItemImages());
				}
			}
		}
		std::vector<std::wstring> addItemToCart;
		productName = std::vector<std::wstring>();
		productQuantity = std::vector<std::wstring>();
		addItemToCart = std::vector<std::wstring>();
		drawableImages = std::vector<Drawable>();

		productName.push_back(L"Name");
		productQuantity.push_back(L"Qty");
		addItemToCart.push_back(L"Button");
		drawableImages.push_back(nullptr);

		//ArrayList<String> getRemovedItemArr = null;//session.getItemRemovedFromCart();
		for (auto entry : itemData)
		{
			productName.push_back(entry.first);
			productQuantity.push_back(L"" + entry.second);
			drawableImages.push_back(drImages[entry.first]);
			addItemToCart.push_back(entry.first);
		}
		session->setItemAddedToCart(addItemToCart);

	}

	void CartMain::noRecordFound(std::vector<std::wstring> &productName1, std::vector<std::wstring> &productQuantity1, std::vector<Drawable*> &drawableImage1)
	{
		productName1[0] = L"No Item";
		productQuantity1[0] = L"Found";
		drawableImage1[0] = nullptr;
	}
}
