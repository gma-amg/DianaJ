#pragma once

namespace com::tzutalin::dlibtest
{

	using Rect = android::graphics::Rect;
	using View = android::view::View;

	using RecyclerView = androidx::recyclerview::widget::RecyclerView;

	/**
	 * Custom item decoration for a vertical {@link ProductGridFragment} {@link RecyclerView}. Adds a
	 * small amount of padding to the left of grid items, and a large amount of padding to the right.
	 */
	class ProductGridItemDecoration : public RecyclerView::ItemDecoration
	{
	private:
		int largePadding = 0;
		int smallPadding = 0;

	public:
		ProductGridItemDecoration(int largePadding, int smallPadding);

		void getItemOffsets(Rect *outRect, View *view, RecyclerView *parent, RecyclerView::State *state) override;
	};

}
