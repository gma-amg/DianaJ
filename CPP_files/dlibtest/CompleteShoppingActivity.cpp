#include "CompleteShoppingActivity.h"
#include "MainActivity.h"

namespace com::tzutalin::dlibtest
{
	using AppCompatActivity = androidx::appcompat::app::AppCompatActivity;
	using Intent = android::content::Intent;
	using Bundle = android::os::Bundle;
	using View = android::view::View;
	using Button = android::widget::Button;
	using Toast = android::widget::Toast;

	void CompleteShoppingActivity::onCreate(Bundle *savedInstanceState)
	{
		androidx::appcompat::app::AppCompatActivity::onCreate(savedInstanceState);
		setContentView(R::layout::complete_shopping);
	}

	void CompleteShoppingActivity::homeButton(View *view)
	{
			btn_back = findViewById(R::id::back_button);
			Toast::makeText(view->getContext(), L"Home page", Toast::LENGTH_SHORT).show();
//JAVA TO C++ CONVERTER TODO TASK: There is no C++ equivalent to the Java 'class' method:
			Intent *intent = new Intent(CompleteShoppingActivity::this,MainActivity::class);
			startActivity(intent);

//JAVA TO C++ CONVERTER TODO TASK: A 'delete intent' statement was not added since intent was passed to a method or constructor. Handle memory management manually.
	}
}
