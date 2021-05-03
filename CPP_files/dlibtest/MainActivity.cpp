//====================================================================================================
//The Free Edition of Java to C++ Converter limits conversion output to 100 lines per file.
#include "MainActivity.h"
#include "CameraActivity.h"
#include "CompleteShoppingActivity.h"

namespace com::tzutalin::dlibtest
{
	using Manifest = android::Manifest;
	using Activity = android::app::Activity;
	using Intent = android::content::Intent;
	using PackageManager = android::content::pm::PackageManager;
	using Bundle = android::os::Bundle;
	using Environment = android::os::Environment;
	using MenuItem = android::view::MenuItem;
	using View = android::view::View;
	using Menu = android::view::Menu;
	using Button = android::widget::Button;
	using FrameLayout = android::widget::FrameLayout;
	using ImageView = android::widget::ImageView;
	using TextView = android::widget::TextView;
	using Toast = android::widget::Toast;
	using NonNull = androidx::annotation::NonNull;
	using NavigationView = com::google::android::material::navigation::NavigationView;
	using ActionBarDrawerToggle = androidx::appcompat::app::ActionBarDrawerToggle;
	using ActivityCompat = androidx::core::app::ActivityCompat;
	using NavController = androidx::navigation::NavController;
	using Navigation = androidx::navigation::Navigation;
	using AppBarConfiguration = androidx::navigation::ui::AppBarConfiguration;
	using NavigationUI = androidx::navigation::ui::NavigationUI;
	using DrawerLayout = androidx::drawerlayout::widget::DrawerLayout;
	using AppCompatActivity = androidx::appcompat::app::AppCompatActivity;
	using Toolbar = androidx::appcompat::widget::Toolbar;
	using BindView = butterknife::BindView;
	using DebugLog = hugo::weaving::DebugLog;

	void MainActivity::onCreate(Bundle *savedInstanceState)
	{
		androidx::appcompat::app::AppCompatActivity::onCreate(savedInstanceState);
		isExternalStorageWritable();
		isExternalStorageReadable();
		verifyStoragePermissions(MainActivity::this);
		System::loadLibrary(L"android_dlib");
		System::loadLibrary(L"opencv_java4");
		//        jniNativeClassInit();
		std::wstring arch = System::getProperty(L"os.arch");
		//        Log.d("MAinActivity","Architecture of mobile"+arch);
		setContentView(R::layout::activity_main);
		Toolbar *toolbar = findViewById(R::id::toolbar);
		setSupportActionBar(toolbar);
		DrawerLayout *drawer = findViewById(R::id::drawer_layout);
		NavigationView *navigationView = findViewById(R::id::nav_view);
		// Passing each menu ID as a set of Ids because each
		// menu should be considered as top level destinations.
		AppBarConfiguration::Builder tempVar(R::id::nav_home, R::id::nav_gallery, R::id::nav_slideshow);
		mAppBarConfiguration = (&tempVar)->setDrawerLayout(drawer).build();
		NavController *navController = Navigation::findNavController(this, R::id::nav_host_fragment);
		NavigationUI::setupActionBarWithNavController(this, navController, mAppBarConfiguration);
		NavigationUI::setupWithNavController(navigationView, navController);
		AppData * const appData = static_cast<AppData*>(getApplicationContext());
		globalVar = appData;
		//        ButterKnife.bind(this);
		//        setupUi();
	}

	bool MainActivity::onCreateOptionsMenu(Menu *menu)
	{
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R::menu::main, menu);
		return true;
	}

	bool MainActivity::onSupportNavigateUp()
	{
		NavController *navController = Navigation::findNavController(this, R::id::nav_host_fragment);
		return NavigationUI::navigateUp(navController, mAppBarConfiguration) || androidx::appcompat::app::AppCompatActivity::onSupportNavigateUp();
	}


	bool MainActivity::isExternalStorageWritable()
	{
		std::wstring state = Environment::getExternalStorageState();
		if (Environment::MEDIA_MOUNTED::equals(state))
		{
			return true;
		}
		return false;
	}

	bool MainActivity::isExternalStorageReadable()
	{
		std::wstring state = Environment::getExternalStorageState();
		if (Environment::MEDIA_MOUNTED::equals(state) || Environment::MEDIA_MOUNTED_READ_ONLY::equals(state))
		{
			return true;
		}
		return false;
	}

	void MainActivity::cameraActivity(View *layout)
	{
		TextView *productTitle = layout->findViewById(R::id::product_title);
		TextView *productPrice = layout->findViewById(R::id::product_price);
		TextView *productHeight = layout->findViewById(R::id::product_height);
		TextView *productWidth = layout->findViewById(R::id::product_width);
		ImageView *imageView = layout->findViewById(R::id::product_image);

		CharSequence *leftSide = productTitle->getContentDescription();
		globalVar->setLeftSideImageId(leftSide->toString());
		globalVar->setItemName(productTitle->getText()->toString());
		//String str =  ;

		CharSequence *rightSide = productPrice->getContentDescription();
		globalVar->setRightSideImageId(rightSide->toString());

		CharSequence *height = productHeight->getText();
		globalVar->setHeight(height->toString());

		CharSequence *width = productWidth->getText();
		globalVar->setWidth(width->toString());

		globalVar->setImage(imageView->getDrawable());

		Intent *cardIntent = new Intent(this, CameraActivity::class);
		startActivity(cardIntent);

	}

std::vector<std::wstring> MainActivity::PERMISSIONS_STORAGE = {android::Manifest::permission::READ_EXTERNAL_STORAGE, android::Manifest::permission::WRITE_EXTERNAL_STORAGE, android::Manifest::permission::SYSTEM_ALERT_WINDOW};

	void MainActivity::verifyStoragePermissions(Activity *activity)
	{
		int permission = ActivityCompat::checkSelfPermission(activity, Manifest::permission::WRITE_EXTERNAL_STORAGE);
		if (permission != PackageManager::PERMISSION_GRANTED)
		{
			ActivityCompat::requestPermissions(activity, PERMISSIONS_STORAGE, REQUEST_EXTERNAL_STORAGE);
		}

	}

	void MainActivity::setupUi()
	{
	   nav_view = findViewById(R::id::drawer_layout);
	   mToggle = new ActionBarDrawerToggle(this,nav_view, myToolbar, R::string::open, R::string->close);
	   nav_view->addDrawerListener(mToggle);
	   nav_view->setClickable(true);
		setSupportActionBar(myToolbar);
		setupNavigationView();
		mToggle->setDrawerIndicatorEnabled(true);
		mToggle->syncState();
	   // toolbarTitle.setText("Home");
		//        navigationView.getMenu().setGroupVisible(R.id.earring_group,  false);

	}

	void MainActivity::setupNavigationView()
	{
		OnNavigationItemSelectedListenerAnonymousInnerClass tempVar(this);
		navigationView->setNavigationItemSelectedListener(&tempVar);
	}

	MainActivity::OnNavigationItemSelectedListenerAnonymousInnerClass::OnNavigationItemSelectedListenerAnonymousInnerClass(MainActivity *outerInstance) : outerInstance(outerInstance)
	{
	}

