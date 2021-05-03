#pragma once

#include "ProductCardViewHolder.h"
#include "ProductEntry.h"
#include "ImageRequester.h"
#include "AppData.h"
#include "ItemCartModel.h"
#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <stdexcept>

namespace com::tzutalin::dlibtest
{

	using Context = android::content::Context;
	using ViewGroup = android::view::ViewGroup;

	using HashMap = java::util::HashMap;
	using List = java::util::List;

	using RecyclerView = androidx::recyclerview::widget::RecyclerView;

	/**
	 * Adapter used to show a simple grid of products.
	 */
	class ProductCardRecyclerViewAdapter : public RecyclerView::Adapter<ProductCardViewHolder*>
	{

	private:
		std::vector<ProductEntry*> productList;
		ImageRequester *imageRequester;
		static const std::wstring TAG;
		std::wstring menuItemId;
		AppData *appData;
	public:
		std::unordered_map<int, ItemCartModel*> productDetails;
		int index = 0;

		virtual ~ProductCardRecyclerViewAdapter()
		{
			delete imageRequester;
			delete appData;
		}

		ProductCardRecyclerViewAdapter(std::vector<ProductEntry*> &productList, Context *ctx, const std::wstring &menuItemId);

		ProductCardRecyclerViewAdapter(std::vector<ProductEntry*> &productList, Context *ctx, const std::wstring &menuItemId, AppData *appData);

//JAVA TO C++ CONVERTER TODO TASK: Most Java annotations will not have direct C++ equivalents:
//ORIGINAL LINE: @NonNull @Override public ProductCardViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType)
		ProductCardViewHolder *onCreateViewHolder(ViewGroup *parent, int viewType) override;

//JAVA TO C++ CONVERTER TODO TASK: Most Java annotations will not have direct C++ equivalents:
//ORIGINAL LINE: @Override public void onBindViewHolder(@NonNull ProductCardViewHolder holder, int position)
		void onBindViewHolder(ProductCardViewHolder *holder, int position) override;

	private:
		class OnClickListenerAnonymousInnerClass : public View::OnClickListener
		{
		private:
			ProductCardRecyclerViewAdapter *outerInstance;

		public:
			virtual ~OnClickListenerAnonymousInnerClass()
			{
				delete outerInstance;
			}

			OnClickListenerAnonymousInnerClass(ProductCardRecyclerViewAdapter *outerInstance);

			void onClick(View *layout) override;
		};

	public:
		int getItemCount() override;
	};

}
