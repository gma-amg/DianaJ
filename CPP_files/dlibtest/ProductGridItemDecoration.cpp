#include "ProductGridItemDecoration.h"

namespace com::tzutalin::dlibtest
{
	using Rect = android::graphics::Rect;
	using View = android::view::View;
	using RecyclerView = androidx::recyclerview::widget::RecyclerView;

	ProductGridItemDecoration::ProductGridItemDecoration(int largePadding, int smallPadding)
	{
		this->largePadding = largePadding;
		this->smallPadding = smallPadding;
	}

	void ProductGridItemDecoration::getItemOffsets(Rect *outRect, View *view, RecyclerView *parent, RecyclerView::State *state)
	{
		outRect->left = smallPadding;
		outRect->right = smallPadding;
		outRect->top = largePadding;
		outRect->bottom = largePadding;
	}
}
