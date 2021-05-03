#pragma once

#include <stdexcept>

/*
 * Copyright 2016-present Tzutalin
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

namespace com::tzutalin::dlibtest
{

	using Context = android::content::Context;
	using AttributeSet = android::util::AttributeSet;
	using TextureView = android::view::TextureView;

	/**
	 * A {@link TextureView} that can be adjusted to a specified aspect ratio.
	 */
	class AutoFitTextureView : public TextureView
	{
  private:
	  int mRatioWidth = 0;
	  int mRatioHeight = 0;

  public:
	  AutoFitTextureView(Context *const context);

	  AutoFitTextureView(Context *const context, AttributeSet *const attrs);

	  AutoFitTextureView(Context *const context, AttributeSet *const attrs, int const defStyle);

	  /**
	   * Sets the aspect ratio for this view. The size of the view will be measured based on the ratio
	   * calculated from the parameters. Note that the actual sizes of parameters don't matter, that
	   * is, calling setAspectRatio(2, 3) and setAspectRatio(4, 6) make the same result.
	   *
	   * @param width  Relative horizontal size
	   * @param height Relative vertical size
	   */
	  virtual void setAspectRatio(int const width, int const height);

  protected:
	  void onMeasure(int const widthMeasureSpec, int const heightMeasureSpec) override;
	};

}
