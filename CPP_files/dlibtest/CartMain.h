#pragma once

#include <string>
#include <unordered_map>
#include <vector>

namespace com::tzutalin::dlibtest
{

	using Context = android::content::Context;
	using Drawable = android::graphics::drawable::Drawable;
	using Bundle = android::os::Bundle;
	using LayoutInflater = android::view::LayoutInflater;
	using Menu = android::view::Menu;
	using MenuInflater = android::view::MenuInflater;
	using View = android::view::View;
	using ViewGroup = android::view::ViewGroup;
	using Button = android::widget::Button;

	using ArrayList = java::util::ArrayList;
	using Fragment = androidx::fragment::app::Fragment;
	using RecyclerView = androidx::recyclerview::widget::RecyclerView;

	class CartMain : public Fragment
	{
	public:
		RecyclerView *recyclerView;
		Context *context;
		RecyclerView::Adapter *recyclerView_Adapter;
		RecyclerView::LayoutManager *recyclerViewLayoutManager;
		std::vector<std::wstring> productName;
		std::vector<Drawable*> drawableImages;
		std::vector<std::wstring> productQuantity;
		std::vector<std::wstring> productUrl;
		std::wstring drImages = L"";
		Button *btn_continue;

		virtual ~CartMain()
		{
			delete recyclerView;
			delete context;
			delete recyclerView_Adapter;
			delete recyclerViewLayoutManager;
			delete btn_continue;
		}

		void onCreate(Bundle *savedInstanceState) override;

//JAVA TO C++ CONVERTER TODO TASK: Most Java annotations will not have direct C++ equivalents:
//ORIGINAL LINE: @Override public android.view.View onCreateView(@NonNull LayoutInflater inflater, android.view.ViewGroup container, android.os.Bundle savedInstanceState)
		View *onCreateView(LayoutInflater *inflater, ViewGroup *container, Bundle *savedInstanceState) override;


		void onCreateOptionsMenu(Menu *menu, MenuInflater *menuInflater) override;

	private:
		void setTableData(Context *ctx);

		public:
			virtual void noRecordFound(std::vector<std::wstring> &productName1, std::vector<std::wstring> &productQuantity1, std::vector<Drawable*> &drawableImage1);
	};
}
