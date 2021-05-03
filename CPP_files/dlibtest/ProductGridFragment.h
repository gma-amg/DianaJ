#pragma once

#include <string>

namespace com::tzutalin::dlibtest
{

	using Bundle = android::os::Bundle;
	using LayoutInflater = android::view::LayoutInflater;
	using Menu = android::view::Menu;
	using MenuInflater = android::view::MenuInflater;
	using View = android::view::View;
	using ViewGroup = android::view::ViewGroup;

	using Fragment = androidx::fragment::app::Fragment;

	class ProductGridFragment : public Fragment
	{

	public:
		void onCreate(Bundle *savedInstanceState) override;

//JAVA TO C++ CONVERTER TODO TASK: Most Java annotations will not have direct C++ equivalents:
//ORIGINAL LINE: @Override public android.view.View onCreateView(@NonNull LayoutInflater inflater, android.view.ViewGroup container, android.os.Bundle savedInstanceState)
		View *onCreateView(LayoutInflater *inflater, ViewGroup *container, Bundle *savedInstanceState) override;

		void onCreateOptionsMenu(Menu *menu, MenuInflater *menuInflater) override;

	};

}
