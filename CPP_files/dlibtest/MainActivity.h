#pragma once

#include "AppData.h"
#include <string>
#include <vector>

/*
 *  Copyright (C) 2015-present TzuTaLin
 */

namespace com::tzutalin::dlibtest
{

	using Manifest = android::Manifest;
	using Activity = android::app::Activity;
	using Bundle = android::os::Bundle;
	//import android.util.Log;
	using View = android::view::View;
	using Menu = android::view::Menu;
	using Button = android::widget::Button;
	using FrameLayout = android::widget::FrameLayout;

	using NavigationView = com::google::android::material::navigation::NavigationView;

	using ActionBarDrawerToggle = androidx::appcompat::app::ActionBarDrawerToggle;
	using AppBarConfiguration = androidx::navigation::ui::AppBarConfiguration;
	using DrawerLayout = androidx::drawerlayout::widget::DrawerLayout;
	using AppCompatActivity = androidx::appcompat::app::AppCompatActivity;
	using Toolbar = androidx::appcompat::widget::Toolbar;


	class MainActivity : public AppCompatActivity
	{

	private:
		DrawerLayout *nav_view;
		ActionBarDrawerToggle *mToggle;
		bool isMembersVisible = false;
	public:
//JAVA TO C++ CONVERTER TODO TASK: Most Java annotations will not have direct C++ equivalents:
//ORIGINAL LINE: @BindView(R.id.nav_view) com.google.android.material.navigation.NavigationView navigationView;
		NavigationView *navigationView;
//JAVA TO C++ CONVERTER TODO TASK: Most Java annotations will not have direct C++ equivalents:
//ORIGINAL LINE: @BindView(R.id.container) android.widget.FrameLayout container;
		FrameLayout *container;
//JAVA TO C++ CONVERTER TODO TASK: Most Java annotations will not have direct C++ equivalents:
//ORIGINAL LINE: @BindView(R.id.toolbar) androidx.appcompat.widget.Toolbar myToolbar;
		Toolbar *myToolbar;
	private:
		AppBarConfiguration *mAppBarConfiguration;
	public:
		AppData *globalVar;

		virtual ~MainActivity()
		{
			delete nav_view;
			delete mToggle;
			delete navigationView;
			delete container;
			delete myToolbar;
			delete mAppBarConfiguration;
			delete globalVar;
			delete btn_continue;
		}

	protected:
		void onCreate(Bundle *savedInstanceState) override;
	public:
		bool onCreateOptionsMenu(Menu *menu) override;

		bool onSupportNavigateUp() override;

	private:
//JAVA TO C++ CONVERTER TODO TASK: Most Java annotations will not have direct C++ equivalents:
//ORIGINAL LINE: @DebugLog private boolean isExternalStorageWritable()
		bool isExternalStorageWritable();

		/* Checks if external storage is available to at least read */
//JAVA TO C++ CONVERTER TODO TASK: Most Java annotations will not have direct C++ equivalents:
//ORIGINAL LINE: @DebugLog private boolean isExternalStorageReadable()
		bool isExternalStorageReadable();

	public:
		virtual void cameraActivity(View *layout);

	private:
		static constexpr int REQUEST_EXTERNAL_STORAGE = 1;
		static std::vector<std::wstring> PERMISSIONS_STORAGE;

	public:
		static void verifyStoragePermissions(Activity *activity);

	private:
		void setupUi();


	//    @Override
	//    public boolean onOptionsItemSelected(MenuItem item) {
	//        navigationView.setCheckedItem(R.id.switchToggleButton);
	//        navigationView.getMenu().performIdentifierAction(R.id.switchToggleButton, 0);
	//        System.out.println("############### Earring"+item.getItemId());
	//       /* switch(item.getItemId()){
	//            // Handle the non group menu items here
	//            case R.id.earring_group:
	//                // Set the text to bold style
	//
	//                return true;
	//            case R.id.neckware_group:
	//                // Set the text to normal style
	//
	//                return true;
	//            default:
	//                return super.onOptionsItemSelected(item);
	//        }*/
	//       if (mToggle.onOptionsItemSelected(item)) {
	//            return true;
	//        } else {
	//            return super.onOptionsItemSelected(item);
	//        }
	//    }
		void setupNavigationView();

	private:
		class OnNavigationItemSelectedListenerAnonymousInnerClass : public NavigationView::OnNavigationItemSelectedListener
		{
		private:
			MainActivity *outerInstance;

		public:
			virtual ~OnNavigationItemSelectedListenerAnonymousInnerClass()
			{
				delete outerInstance;
			}

			OnNavigationItemSelectedListenerAnonymousInnerClass(MainActivity *outerInstance);

//JAVA TO C++ CONVERTER TODO TASK: Most Java annotations will not have direct C++ equivalents:
//ORIGINAL LINE: @Override public boolean onNavigationItemSelected(@NonNull MenuItem item)
			bool onNavigationItemSelected(MenuItem *item) override;
		};
	//    private void switchScreen(int id) {
	//        switch (id) {
	//            case R.id.nav_home:
	//                container.removeAllViews();
	//                startActivity(new Intent(this, MainActivity.class));
	//               nav_view.closeDrawers();
	//                break;
	//
	//            case R.id.nav_slideshow:
	//                if (!isMembersVisible) {
	////                    navigationView.getMenu().setGroupVisible(R.id.neckware_group, true);
	//                    isMembersVisible = true;
	//                } else {
	////                    navigationView.getMenu().setGroupVisible(R.id.neckware_group, false);
	//                    isMembersVisible = false;
	//                }
	//                break;
	//            case R.id.necklace:
	//                Toast.makeText(MainActivity.this, "Necklace selected", Toast.LENGTH_SHORT).show();
	//                break;
	//            case R.id.chain:
	//                Toast.makeText(MainActivity.this, "Chain selected", Toast.LENGTH_SHORT).show();
	//                break;
	//            case R.id.mangalsutra:
	//                Toast.makeText(MainActivity.this, "Mangalsutra selected", Toast.LENGTH_SHORT).show();
	//                break;
	//
	//            case R.id.nav_gallery:
	//                if (!isMembersVisible) {
	////                    navigationView.getMenu().setGroupVisible(R.id.earring_group, true);
	//                    isMembersVisible = true;
	//                } else {
	////                    navigationView.getMenu().setGroupVisible(R.id.earring_group, false);
	//                    isMembersVisible = false;
	//                }
	//                break;
	//            case R.id.memberone:
	//                Toast.makeText(MainActivity.this, "Stud selected", Toast.LENGTH_SHORT).show();
	//                break;
	//            case R.id.membertwo:
	//                Toast.makeText(MainActivity.this, "Drop selected", Toast.LENGTH_SHORT).show();
	//                break;
	//            case R.id.memberthree:
	//                Toast.makeText(MainActivity.this, "Jumka selected", Toast.LENGTH_SHORT).show();
	//                break;
	//
	//            }
	//
	//    }





	public:
		Button *btn_continue;
		virtual void clickContinue(View *view);


	};

}
