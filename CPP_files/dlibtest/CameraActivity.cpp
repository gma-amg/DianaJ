#include "CameraActivity.h"
#include "CameraConnectionFragment.h"
#include "AppData.h"
#include "ItemCartModel.h"
#include "ItemSessionManager.h"

namespace com::tzutalin::dlibtest
{
	using Activity = android::app::Activity;
	using Intent = android::content::Intent;
	using Bitmap = android::graphics::Bitmap;
	using Drawable = android::graphics::drawable::Drawable;
	using Uri = android::net::Uri;
	using Build = android::os::Build;
	using Bundle = android::os::Bundle;
	using MediaStore = android::provider::MediaStore;
	using Settings = android::provider::Settings;
	using View = android::view::View;
	using WindowManager = android::view::WindowManager;
	using ImageView = android::widget::ImageView;
	using Toast = android::widget::Toast;
	using ArrayList = java::util::ArrayList;
	using HashMap = java::util::HashMap;
int CameraActivity::OVERLAY_PERMISSION_REQ_CODE = 1;

	void CameraActivity::onCreate(Bundle *const savedInstanceState)
	{
		android::app::Activity::onCreate(savedInstanceState);
		getWindow().addFlags(WindowManager::LayoutParams::FLAG_KEEP_SCREEN_ON);

		setContentView(R::layout::activity_camera);

		if (Build::VERSION::SDK_INT >= Build::VERSION_CODES::M)
		{
			if (!Settings::canDrawOverlays(this->getApplicationContext()))
			{
				Intent *intent = new Intent(Settings::ACTION_MANAGE_OVERLAY_PERMISSION, Uri::parse(L"package:" + getPackageName()));
				intent->putExtra(MediaStore::EXTRA_OUTPUT, Uri::parse(L"package:" + getPackageName()));
				startActivityForResult(intent, OVERLAY_PERMISSION_REQ_CODE);

//JAVA TO C++ CONVERTER TODO TASK: A 'delete intent' statement was not added since intent was passed to a method or constructor. Handle memory management manually.
			}
		}
		//        Intent cameraIntent = new Intent(android.provider.MediaStore.ACTION_IMAGE_CAPTURE);
		//        startActivityForResult(cameraIntent, CAMERA_PIC_REQUEST);
		if (nullptr == savedInstanceState)
		{
			getFragmentManager().beginTransaction()->replace(R::id::container, CameraConnectionFragment::newInstance()).commit();
		}
	}

	void CameraActivity::onActivityResult(int requestCode, int resultCode, Intent *data)
	{
		if (requestCode == OVERLAY_PERMISSION_REQ_CODE)
		{
			if (Build::VERSION::SDK_INT >= Build::VERSION_CODES::M)
			{
				if (!Settings::canDrawOverlays(this->getApplicationContext()))
				{
					Toast::makeText(CameraActivity::this, L"CameraActivity\", \"SYSTEM_ALERT_WINDOW, permission not granted...", Toast::LENGTH_SHORT).show();
				}
				else
				{
					Intent *intent = getIntent();
					finish();
					startActivity(intent);
				}
			}
		}
	}

	void CameraActivity::addToCart(View *view)
	{
		AppData * const appData = static_cast<AppData*>(getApplicationContext());
		std::wstring itemName = appData->getItemName();
		Drawable *drImage = appData->getImage();
		std::unordered_map<std::wstring, Drawable*> drawableImages;
		std::vector<ItemCartModel*> itemSelected;

		Toast::makeText(getApplicationContext(),L"Added to Cart",Toast::LENGTH_SHORT).show();
		ItemSessionManager *session = ItemSessionManager::getInstance(getApplicationContext());
		ItemCartModel *itemCartModel = new ItemCartModel();
		itemCartModel->setItemName(itemName);
		itemCartModel->setItemQuantity(1);
		// get ArrayList Object
		itemSelected = session->loadData();

		itemSelected.push_back(itemCartModel);
		// session.removedFromCart(itemName);
		// set data to session object.
		session->addItemTOCart(itemSelected);
		// session.addItemToCart("Santosh");
		drawableImages = appData->getImageAddedToCart();
		if (drawableImages.empty())
		{
			drawableImages = std::unordered_map<std::wstring, Drawable>();
		}
		drawableImages.emplace(itemName, drImage);
		appData->setImageAddedToCart(drawableImages);


		//ArrayList<String> str = session.getUserDetails() ;
		// ArrayList<ItemCartModel> itemSelectedArr = session.loadData();

		Toast::makeText(getApplicationContext(),L"Added to Cart:" + itemName,Toast::LENGTH_SHORT).show();
		Intent *intent = getIntent();
		finish();
		startActivity(intent);

//JAVA TO C++ CONVERTER TODO TASK: A 'delete itemCartModel' statement was not added since itemCartModel was passed to a method or constructor. Handle memory management manually.
	}
}
