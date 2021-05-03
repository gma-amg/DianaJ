#pragma once

#include "HomeViewModel.h"
#include <string>

namespace com::tzutalin::dlibtest
{

	using Bundle = android::os::Bundle;
	using View = android::view::View;
	using ViewGroup = android::view::ViewGroup;

	using Fragment = androidx::fragment::app::Fragment;

	class HomeFragment : public Fragment
	{

	private:
		HomeViewModel *homeViewModel;

	public:
		virtual ~HomeFragment()
		{
			delete homeViewModel;
		}

//JAVA TO C++ CONVERTER TODO TASK: Most Java annotations will not have direct C++ equivalents:
//ORIGINAL LINE: public android.view.View onCreateView(@NonNull LayoutInflater inflater, android.view.ViewGroup container, android.os.Bundle savedInstanceState)
		virtual View *onCreateView(LayoutInflater *inflater, ViewGroup *container, Bundle *savedInstanceState);

	private:
		class ObserverAnonymousInnerClass : public Observer<std::wstring>
		{
		private:
			HomeFragment *outerInstance;

			TextView *textView;

		public:
			virtual ~ObserverAnonymousInnerClass()
			{
				delete outerInstance;
				delete textView;
			}

			ObserverAnonymousInnerClass(HomeFragment *outerInstance, TextView *textView);

//JAVA TO C++ CONVERTER TODO TASK: Most Java annotations will not have direct C++ equivalents:
//ORIGINAL LINE: @Override public void onChanged(@Nullable String s)
			void onChanged(const std::wstring &s) override;
		};
	};

}
