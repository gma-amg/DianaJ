#pragma once

namespace com::tzutalin::dlibtest
{

	using Button = android::widget::Button;
	using ImageView = android::widget::ImageView;
	using TextView = android::widget::TextView;


	using RecyclerView = androidx::recyclerview::widget::RecyclerView;

	class ProductCardViewHolder : public RecyclerView::ViewHolder
	{

	public:
		ImageView *productImage;
		TextView *productTitle;
		TextView *productPrice;
		TextView *productHeight;
		TextView *productWidth;
		Button *productButton;

		virtual ~ProductCardViewHolder()
		{
			delete productImage;
			delete productTitle;
			delete productPrice;
			delete productHeight;
			delete productWidth;
			delete productButton;
		}

//JAVA TO C++ CONVERTER TODO TASK: Most Java annotations will not have direct C++ equivalents:
//ORIGINAL LINE: public ProductCardViewHolder(@NonNull View itemView)
		ProductCardViewHolder(View *itemView);
	};

}
