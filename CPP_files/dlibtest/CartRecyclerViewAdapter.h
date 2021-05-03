#pragma once

#include <string>
#include <vector>
#include <iostream>

//JAVA TO C++ CONVERTER NOTE: Forward class declarations:
namespace com::tzutalin::dlibtest { class ViewHolder; }

namespace com::tzutalin::dlibtest
{
	using Context = android::content::Context;
	using Drawable = android::graphics::drawable::Drawable;
	using View = android::view::View;
	using ViewGroup = android::view::ViewGroup;
	using Button = android::widget::Button;
	using ImageView = android::widget::ImageView;
	using TextView = android::widget::TextView;

	using ArrayList = java::util::ArrayList;

	using RecyclerView = androidx::recyclerview::widget::RecyclerView;

	/**
	 * Created by Santosh Suman on 2/14/2020.
	 */
	class CartRecyclerViewAdapter : public RecyclerView::Adapter<CartRecyclerViewAdapter::ViewHolder*>
	{
	public:
		std::vector<std::wstring> productName;
		std::vector<std::wstring> itemImages;
		std::vector<std::wstring> productQuantity;
		std::vector<Drawable*> drawableImage;
		std::wstring droImages;
		Context *context1;
		int count = 0;
		int num = 0;
		std::vector<std::wstring> productNameArr;
		std::vector<std::wstring> productQuantityArr;
		std::vector<Drawable*> drawableImageArr;
		std::vector<std::wstring> productUrl;

		virtual ~CartRecyclerViewAdapter()
		{
			delete context1;
		}

		CartRecyclerViewAdapter(Context *context2, std::vector<std::wstring> &productName, std::vector<std::wstring> &productQuantity, std::vector<Drawable*> &drawableImage);


		CartRecyclerViewAdapter(Context *context2, std::vector<std::wstring> &productNameArr, std::vector<std::wstring> &productQuantityArr, std::vector<Drawable*> &drawableImageArr, std::vector<std::wstring> &productUrl);

	public:
		class ViewHolder : public RecyclerView::ViewHolder
		{

		public:
			ImageView *productImage;
			TextView *productName;
			TextView *productQuantity;
			TextView *button;
		private:
			Button *deleteButton;
			Button *continueButton;

		public:
			TextView *headProductImage;
			TextView *headProductName;
			TextView *headProductQuantity;
			TextView *headButton;


			virtual ~ViewHolder()
			{
				delete productImage;
				delete productName;
				delete productQuantity;
				delete button;
				delete deleteButton;
				delete continueButton;
				delete headProductImage;
				delete headProductName;
				delete headProductQuantity;
				delete headButton;
			}

			ViewHolder(View *v);
		};

	public:
		ViewHolder *onCreateViewHolder(ViewGroup *parent, int viewType) override;

		void onBindViewHolder(ViewHolder *const Vholder, int position) override;

	private:
		class OnClickListenerAnonymousInnerClass : public View::OnClickListener
		{
		private:
			CartRecyclerViewAdapter *outerInstance;

			com::tzutalin::dlibtest::CartRecyclerViewAdapter::ViewHolder *Vholder;

		public:
			virtual ~OnClickListenerAnonymousInnerClass()
			{
				delete outerInstance;
				delete Vholder;
			}

			OnClickListenerAnonymousInnerClass(CartRecyclerViewAdapter *outerInstance, com::tzutalin::dlibtest::CartRecyclerViewAdapter::ViewHolder *Vholder);

			void onClick(View *v) override;
		};

	public:
		int getItemCount() override;


		//header holder
	private:
		class HeaderHolder : public ViewHolder
		{
		private:
			CartRecyclerViewAdapter *outerInstance;

		public:
			virtual ~HeaderHolder()
			{
				delete outerInstance;
			}

			HeaderHolder(CartRecyclerViewAdapter *outerInstance, View *itemView);
		};


		//footer holder
	private:
		class FooterHolder : public ViewHolder
		{
		private:
			CartRecyclerViewAdapter *outerInstance;

			Button *continueButton;
		public:
			virtual ~FooterHolder()
			{
				delete continueButton;
				delete outerInstance;
			}

			FooterHolder(CartRecyclerViewAdapter *outerInstance, View *itemView);
		};


	};
}
