//====================================================================================================
//The Free Edition of Java to C++ Converter limits conversion output to 100 lines per file.

//To purchase the Premium Edition, visit our website:
//https://www.tangiblesoftwaresolutions.com/order/order-java-to-cplus.html
//====================================================================================================

#include "CartRecyclerViewAdapter.h"
#include "ItemSessionManager.h"

namespace com::tzutalin::dlibtest
{
	using Context = android::content::Context;
	using Color = android::graphics::Color;
	using Drawable = android::graphics::drawable::Drawable;
	using LayoutInflater = android::view::LayoutInflater;
	using View = android::view::View;
	using ViewGroup = android::view::ViewGroup;
	using Button = android::widget::Button;
	using ImageView = android::widget::ImageView;
	using TextView = android::widget::TextView;
	using Toast = android::widget::Toast;
	using Field = java::lang::reflect::Field;
	using ArrayList = java::util::ArrayList;
	using RecyclerView = androidx::recyclerview::widget::RecyclerView;

	CartRecyclerViewAdapter::CartRecyclerViewAdapter(Context *context2, std::vector<std::wstring> &productName, std::vector<std::wstring> &productQuantity, std::vector<Drawable*> &drawableImage)
	{
		context1 = context2;
		this->productName = productName;
		this->productQuantity = productQuantity;
		this->drawableImage = drawableImage;
	}

	CartRecyclerViewAdapter::CartRecyclerViewAdapter(Context *context2, std::vector<std::wstring> &productNameArr, std::vector<std::wstring> &productQuantityArr, std::vector<Drawable*> &drawableImageArr, std::vector<std::wstring> &productUrl)
	{
		context1 = context2;
		this->productNameArr = productNameArr;
		this->productQuantityArr = productQuantityArr;
		this->drawableImageArr = drawableImageArr;
		this->productUrl = productUrl;
	}

	CartRecyclerViewAdapter::ViewHolder::ViewHolder(View *v) : androidx::recyclerview::widget::RecyclerView::ViewHolder(v)
	{
		productImage = itemView::findViewById(R::id::product_image);
		productName = static_cast<TextView*>(v->findViewById(R::id::product_name));
		productQuantity = static_cast<TextView*>(v->findViewById(R::id::product_quantity));

		button = static_cast<TextView*>(v->findViewById(R::id::button));
		deleteButton = static_cast<Button*>(v->findViewById(R::id::button));
		// continueButton= (Button) v.findViewById(R.id.continue_btn);
	}

	CartRecyclerViewAdapter::ViewHolder *CartRecyclerViewAdapter::onCreateViewHolder(ViewGroup *parent, int viewType)
	{
		LayoutInflater *inflater = LayoutInflater::from(parent->getContext());
		View *row;
		++count;
		//Check fot view Type inflate layout according to it
		if (count == 1)
		{
			std::wcout << L" Header instance created " << count << std::endl;
			row = LayoutInflater::from(context1).inflate(R::layout::cart_row_header, parent, false);
			return new HeaderHolder(this, row);
		}
		else if (count == productNameArr.size())
		{
			std::wcout << L" Footer instance created " << count << std::endl;
			row = LayoutInflater::from(context1).inflate(R::layout::footer, parent, false);
			return new FooterHolder(this, row);
		}
		else
		{
			std::wcout << L" item instance created " << count << std::endl;
			row = LayoutInflater::from(context1).inflate(R::layout::cart_recycler_view_items, parent, false);
			ViewHolder *viewHolder1 = new ViewHolder(row);

//JAVA TO C++ CONVERTER TODO TASK: A 'delete viewHolder1' statement was not added since viewHolder1 was used in a 'return' or 'throw' statement.
			return viewHolder1;
		}
	}

	void CartRecyclerViewAdapter::onBindViewHolder(ViewHolder *const Vholder, int position)
	{
		std::vector<Field*> studs;

		// Add footer section
		if (dynamic_cast<FooterHolder*>(Vholder) != nullptr)
		{
			std::wcout << L" Footer Added " << num << std::endl;
			FooterHolder *footerHolder = static_cast<FooterHolder*>(Vholder);
			//set data
			footerHolder->continueButton.setText(L"Continue");
			footerHolder->continueButton.setBackgroundColor(Color::WHITE);
			footerHolder->continueButton.setTextColor(Color::BLACK);
			footerHolder->continueButton.setEnabled(true);
			footerHolder->continueButton.setId(position);
		}
		// add header section
		else if (dynamic_cast<HeaderHolder*>(Vholder) != nullptr)
		{
			std::wcout << L" Header Added " << num << std::endl;
			HeaderHolder *headerHolder = static_cast<HeaderHolder*>(Vholder);
			headerHolder->headProductImage->setText(L"Image");
			headerHolder->headProductImage->setBackgroundColor(Color::WHITE);
			headerHolder->headProductImage->setTextColor(Color::BLACK);

			headerHolder->headProductName->setText(L"Name");
			headerHolder->headProductName->setBackgroundColor(Color::WHITE);
			headerHolder->headProductName->setTextColor(Color::BLACK);

			headerHolder->headProductQuantity->setText(L"Qty");
			headerHolder->headProductQuantity->setBackgroundColor(Color::WHITE);
			headerHolder->headProductQuantity->setTextColor(Color::BLACK);

			headerHolder->headButton->setText(L"Button");
			headerHolder->headButton->setBackgroundColor(Color::WHITE);
			headerHolder->headButton->setTextColor(Color::BLACK);

		}
		// add content/body
		else if (position != 0)
		{
			Vholder->productName->setText(productNameArr[position]);
			Vholder->productName->setTextColor(Color::BLACK);

			Vholder->productQuantity->setText(productQuantityArr[position]);
			Vholder->productQuantity->setTextColor(Color::BLACK);

			Vholder->button->setId(position);

			Vholder->productImage->setImageDrawable(drawableImageArr[position]);
			Vholder->productImage->setBackgroundColor(Color::WHITE);

			std::wcout << L"****************** " << productUrl[position] << std::endl;

//JAVA TO C++ CONVERTER TODO TASK: There is no C++ equivalent to 'toString':
			Vholder->productImage->setImageDrawable(Vholder->itemView.getContext().getResources().getDrawable(Vholder->itemView.getContext().getResources().getIdentifier(productUrl[position].toString(), L"drawable", Vholder->itemView.getContext().getPackageName())));


			OnClickListenerAnonymousInnerClass tempVar(this, Vholder);
			Vholder->button->setOnClickListener(&tempVar);
			if (num % 2 != 0)
			{
				Vholder->itemView.setBackgroundColor(Color::LTGRAY);
				Vholder->productImage->setBackgroundColor(Color::LTGRAY);
			}
		}
		++num;
	}

	CartRecyclerViewAdapter::OnClickListenerAnonymousInnerClass::OnClickListenerAnonymousInnerClass(CartRecyclerViewAdapter *outerInstance, com::tzutalin::dlibtest::CartRecyclerViewAdapter::ViewHolder *Vholder) : outerInstance(outerInstance)
	{
		this->Vholder = Vholder;
	}

	void CartRecyclerViewAdapter::OnClickListenerAnonymousInnerClass::onClick(View *v)
	{
		int id = v->getId();
		int index = Vholder->getAdapterPosition();
		// removeArrayIndex(index);

		// remove Item from the Array..
		outerInstance->productNameArr.erase(outerInstance->productNameArr.begin() + index);
		outerInstance->productQuantityArr.erase(outerInstance->productQuantityArr.begin() + index);
		outerInstance->drawableImageArr.erase(outerInstance->drawableImageArr.begin() + index);
		outerInstance->productUrl.erase(outerInstance->productUrl.begin() + index);

		ItemSessionManager *session = ItemSessionManager::getInstance(outerInstance->context1);
//JAVA TO C++ CONVERTER TODO TASK: There is no C++ equivalent to 'toString':
		std::wstring productName1 = session->getItemAddedToCart()[id].toString();

//====================================================================================================
//End of the allowed output for the Free Edition of Java to C++ Converter.

//To purchase the Premium Edition, visit our website:
//https://www.tangiblesoftwaresolutions.com/order/order-java-to-cplus.html
//====================================================================================================
