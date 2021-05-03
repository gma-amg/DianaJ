#include "ProductGridFragment.h"
#include "AppData.h"
#include "ProductCardRecyclerViewAdapter.h"
#include "ProductEntry.h"
#include "ProductGridItemDecoration.h"

namespace com::tzutalin::dlibtest
{
	using Context = android::content::Context;
	using Bundle = android::os::Bundle;
	using Log = android::util::Log;
	using LayoutInflater = android::view::LayoutInflater;
	using Menu = android::view::Menu;
	using MenuInflater = android::view::MenuInflater;
	using View = android::view::View;
	using ViewGroup = android::view::ViewGroup;
	using NonNull = androidx::annotation::NonNull;
	using Fragment = androidx::fragment::app::Fragment;
	using NavController = androidx::navigation::NavController;
	using Navigation = androidx::navigation::Navigation;
	using GridLayoutManager = androidx::recyclerview::widget::GridLayoutManager;
	using RecyclerView = androidx::recyclerview::widget::RecyclerView;

	void ProductGridFragment::onCreate(Bundle *savedInstanceState)
	{
		androidx::fragment::app::Fragment::onCreate(savedInstanceState);
		setHasOptionsMenu(true);
	}

//JAVA TO C++ CONVERTER TODO TASK: Most Java annotations will not have direct C++ equivalents:
//ORIGINAL LINE: @Override public android.view.View onCreateView(@NonNull LayoutInflater inflater, android.view.ViewGroup container, android.os.Bundle savedInstanceState)
	View *ProductGridFragment::onCreateView(LayoutInflater *inflater, ViewGroup *container, Bundle *savedInstanceState)
	{
		NavController *navController = Navigation::findNavController(getActivity(), R::id::nav_host_fragment);
		std::wstring menuLabel = static_cast<std::wstring>(navController->getCurrentDestination().getLabel());
		AppData * const appData = static_cast<AppData*>(getActivity().getApplicationContext());
		appData->setMenuItem(menuLabel);

		// Inflate the layout for this fragment with the ProductGrid theme
		View *view = inflater->inflate(R::layout::shr_product_grid_fragment, container, false);

		// Set up the RecyclerView
		RecyclerView *recyclerView = view->findViewById(R::id::recycler_view);
		recyclerView->setHasFixedSize(true);
		GridLayoutManager tempVar(getContext(), 2, RecyclerView::VERTICAL, false);
		recyclerView->setLayoutManager(&tempVar);
		Context *ctx = recyclerView->getContext();
		ProductCardRecyclerViewAdapter *adapter = new ProductCardRecyclerViewAdapter(ProductEntry::initProductEntryList(getResources(),menuLabel),ctx,menuLabel, appData);
		recyclerView->setAdapter(adapter);
		int largePadding = getResources().getDimensionPixelSize(R::dimen::shr_product_grid_spacing);
		int smallPadding = getResources().getDimensionPixelSize(R::dimen::shr_product_grid_spacing_small);
		ProductGridItemDecoration tempVar2(largePadding, smallPadding);
		recyclerView->addItemDecoration(&tempVar2);

//JAVA TO C++ CONVERTER TODO TASK: A 'delete adapter' statement was not added since adapter was passed to a method or constructor. Handle memory management manually.
		return view;
	}

	void ProductGridFragment::onCreateOptionsMenu(Menu *menu, MenuInflater *menuInflater)
	{
		menuInflater->inflate(R::menu::shr_toolbar_menu, menu);
		androidx::fragment::app::Fragment::onCreateOptionsMenu(menu, menuInflater);
	}
}
