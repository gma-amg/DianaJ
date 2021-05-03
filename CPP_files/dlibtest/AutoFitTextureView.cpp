#include "AutoFitTextureView.h"

namespace com::tzutalin::dlibtest
{
	using Context = android::content::Context;
	using AttributeSet = android::util::AttributeSet;
	using TextureView = android::view::TextureView;

	AutoFitTextureView::AutoFitTextureView(Context *const context) : AutoFitTextureView(context, nullptr)
	{
	}

	AutoFitTextureView::AutoFitTextureView(Context *const context, AttributeSet *const attrs) : AutoFitTextureView(context, attrs, 0)
	{
	}

	AutoFitTextureView::AutoFitTextureView(Context *const context, AttributeSet *const attrs, int const defStyle) : android::view::TextureView(context, attrs, defStyle)
	{
	}

	void AutoFitTextureView::setAspectRatio(int const width, int const height)
	{
	  if (width < 0 || height < 0)
	  {
		throw std::invalid_argument("Size cannot be negative.");
	  }
	  mRatioWidth = width;
	  mRatioHeight = height;
	  requestLayout();
	}

	void AutoFitTextureView::onMeasure(int const widthMeasureSpec, int const heightMeasureSpec)
	{
	  android::view::TextureView::onMeasure(widthMeasureSpec, heightMeasureSpec);
	  constexpr int width = MeasureSpec::getSize(widthMeasureSpec);
	  constexpr int height = MeasureSpec::getSize(heightMeasureSpec);
	  if (0 == mRatioWidth || 0 == mRatioHeight)
	  {
		setMeasuredDimension(width, height);
	  }
	  else
	  {
		if (width < height * mRatioWidth / mRatioHeight)
		{
		  setMeasuredDimension(width, width * mRatioHeight / mRatioWidth);
		}
		else
		{
		  setMeasuredDimension(height * mRatioWidth / mRatioHeight, height);
		}
	  }
	}
}
