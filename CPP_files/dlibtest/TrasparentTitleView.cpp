#include "TrasparentTitleView.h"

namespace com::tzutalin::dlibtest
{
	using Context = android::content::Context;
	using Canvas = android::graphics::Canvas;
	using Paint = android::graphics::Paint;
	using AttributeSet = android::util::AttributeSet;
	using TypedValue = android::util::TypedValue;
	using View = android::view::View;
	using NonNull = androidx::annotation::NonNull;

	TrasparentTitleView::TrasparentTitleView(Context *const context, AttributeSet *const set) : android::view::View(context, set), mTextSizePx(TypedValue::applyDimension(TypedValue::COMPLEX_UNIT_DIP, TEXT_SIZE_DIP, getResources().getDisplayMetrics())), mFgPaint(new Paint()), mBgPaint(new Paint())
	{

		mFgPaint->setTextSize(mTextSizePx);

		mBgPaint->setColor(0xcc4285f4);
	}

//JAVA TO C++ CONVERTER TODO TASK: Most Java annotations will not have direct C++ equivalents:
//ORIGINAL LINE: @NonNull public void setText(@NonNull String text)
	void TrasparentTitleView::setText(const std::wstring &text)
	{
		this->mShowText = text;
		postInvalidate();
	}

	void TrasparentTitleView::onDraw(Canvas *const canvas)
	{
		constexpr int x = 10;
		int y = static_cast<int>(mFgPaint->getTextSize() * 1.5f);

		canvas->drawPaint(mBgPaint);

		if (mShowText != L"")
		{
			canvas->drawText(mShowText, x, y, mFgPaint);
		}
	}
}
