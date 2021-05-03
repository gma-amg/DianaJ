#include "ProductCardViewHolder.h"

namespace com::tzutalin::dlibtest
{
	using View = android::view::View;
	using Button = android::widget::Button;
	using ImageView = android::widget::ImageView;
	using TextView = android::widget::TextView;
	using NetworkImageView = com::android::volley::toolbox::NetworkImageView;
	using NonNull = androidx::annotation::NonNull;
	using RecyclerView = androidx::recyclerview::widget::RecyclerView;

//JAVA TO C++ CONVERTER TODO TASK: Most Java annotations will not have direct C++ equivalents:
//ORIGINAL LINE: public ProductCardViewHolder(@NonNull View itemView)
	ProductCardViewHolder::ProductCardViewHolder(View *itemView) : androidx::recyclerview::widget::RecyclerView::ViewHolder(itemView)
	{
		productImage = itemView->findViewById(R::id::product_image);
		productTitle = itemView->findViewById(R::id::product_title);
		productPrice = itemView->findViewById(R::id::product_price);
		productHeight = itemView->findViewById(R::id::product_height);
		productWidth = itemView->findViewById(R::id::product_width);
		productButton = itemView->findViewById(R::id::button);
	}
}
