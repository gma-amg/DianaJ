#pragma once

#include <string>

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
	using Canvas = android::graphics::Canvas;
	using Paint = android::graphics::Paint;
	using AttributeSet = android::util::AttributeSet;
	using View = android::view::View;


	class TrasparentTitleView : public View
	{
	private:
		static constexpr float TEXT_SIZE_DIP = 24;
		std::wstring mShowText;
		const float mTextSizePx;
		Paint *const mFgPaint;
		Paint *const mBgPaint;

	public:
		virtual ~TrasparentTitleView()
		{
			delete mFgPaint;
			delete mBgPaint;
		}

		TrasparentTitleView(Context *const context, AttributeSet *const set);

//JAVA TO C++ CONVERTER TODO TASK: Most Java annotations will not have direct C++ equivalents:
//ORIGINAL LINE: @NonNull public void setText(@NonNull String text)
		virtual void setText(const std::wstring &text);

		void onDraw(Canvas *const canvas) override;
	};

}
