#pragma once

namespace com::tzutalin::dlibtest
{

	using AppCompatActivity = androidx::appcompat::app::AppCompatActivity;


	using Bundle = android::os::Bundle;
	using View = android::view::View;
	using Button = android::widget::Button;

	class CompleteShoppingActivity : public AppCompatActivity
	{
	public:
		Button *btn_back;
		virtual ~CompleteShoppingActivity()
		{
			delete btn_back;
		}

	protected:
		void onCreate(Bundle *savedInstanceState) override;

	public:
		virtual void homeButton(View *view);
	};
}
