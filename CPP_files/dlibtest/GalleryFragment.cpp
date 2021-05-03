#include "GalleryFragment.h"
#include "CameraActivity.h"

namespace com::tzutalin::dlibtest
{
	using Intent = android::content::Intent;
	using Bundle = android::os::Bundle;
	using LayoutInflater = android::view::LayoutInflater;
	using View = android::view::View;
	using ViewGroup = android::view::ViewGroup;
	using ImageButton = android::widget::ImageButton;
	using TextView = android::widget::TextView;
	using NonNull = androidx::annotation::NonNull;
	using Nullable = androidx::annotation::Nullable;
	using Fragment = androidx::fragment::app::Fragment;
	using Observer = androidx::lifecycle::Observer;
	using ViewModelProviders = androidx::lifecycle::ViewModelProviders;

//JAVA TO C++ CONVERTER TODO TASK: Most Java annotations will not have direct C++ equivalents:
//ORIGINAL LINE: public android.view.View onCreateView(@NonNull LayoutInflater inflater, android.view.ViewGroup container, android.os.Bundle savedInstanceState)
	View *GalleryFragment::onCreateView(LayoutInflater *inflater, ViewGroup *container, Bundle *savedInstanceState)
	{

		AppData * const appData = static_cast<AppData*>(getActivity().getApplicationContext());

//JAVA TO C++ CONVERTER TODO TASK: There is no C++ equivalent to the Java 'class' method:
		galleryViewModel = ViewModelProviders::of(this)->get(GalleryViewModel::class);
		View *root = inflater->inflate(R::layout::fragment_gallery, container, false);

		ImageButton * const imgBt3 = root->findViewById(R::id::imageButton3);
		ImageButton * const imgBt4 = root->findViewById(R::id::imageButton4);
		ImageButton * const imgBt5 = root->findViewById(R::id::imageButton5);
		ImageButton * const imgBt6 = root->findViewById(R::id::imageButton6);


		OnClickListenerAnonymousInnerClass tempVar(this, appData, imgBt3);
		imgBt3->setOnClickListener(&tempVar);

		OnClickListenerAnonymousInnerClass2 tempVar2(this, appData, imgBt4);
		imgBt4->setOnClickListener(&tempVar2);

		OnClickListenerAnonymousInnerClass3 tempVar3(this, appData, imgBt5);
		imgBt5->setOnClickListener(&tempVar3);

		OnClickListenerAnonymousInnerClass4 tempVar4(this, appData, imgBt6);
		imgBt6->setOnClickListener(&tempVar4);

		return root;
	}

	GalleryFragment::OnClickListenerAnonymousInnerClass::OnClickListenerAnonymousInnerClass(GalleryFragment *outerInstance, com::tzutalin::dlibtest::AppData *appData, ImageButton *imgBt3) : outerInstance(outerInstance)
	{
		this->appData = appData;
		this->imgBt3 = imgBt3;
	}

	void GalleryFragment::OnClickListenerAnonymousInnerClass::onClick(View *v)
	{
		appData->setImage(imgBt3->getDrawable());
//JAVA TO C++ CONVERTER TODO TASK: There is no C++ equivalent to the Java 'class' method:
		Intent tempVar(getActivity(), CameraActivity::class);
		startActivity(&tempVar);
	}

	GalleryFragment::OnClickListenerAnonymousInnerClass2::OnClickListenerAnonymousInnerClass2(GalleryFragment *outerInstance, com::tzutalin::dlibtest::AppData *appData, ImageButton *imgBt4) : outerInstance(outerInstance)
	{
		this->appData = appData;
		this->imgBt4 = imgBt4;
	}

	void GalleryFragment::OnClickListenerAnonymousInnerClass2::onClick(View *v)
	{
		appData->setImage(imgBt4->getDrawable());
//JAVA TO C++ CONVERTER TODO TASK: There is no C++ equivalent to the Java 'class' method:
		Intent tempVar(getActivity(), CameraActivity::class);
		startActivity(&tempVar);
	}

	GalleryFragment::OnClickListenerAnonymousInnerClass3::OnClickListenerAnonymousInnerClass3(GalleryFragment *outerInstance, com::tzutalin::dlibtest::AppData *appData, ImageButton *imgBt5) : outerInstance(outerInstance)
	{
		this->appData = appData;
		this->imgBt5 = imgBt5;
	}

	void GalleryFragment::OnClickListenerAnonymousInnerClass3::onClick(View *v)
	{
		appData->setImage(imgBt5->getDrawable());
//JAVA TO C++ CONVERTER TODO TASK: There is no C++ equivalent to the Java 'class' method:
		Intent tempVar(getActivity(), CameraActivity::class);
		startActivity(&tempVar);
	}

	GalleryFragment::OnClickListenerAnonymousInnerClass4::OnClickListenerAnonymousInnerClass4(GalleryFragment *outerInstance, com::tzutalin::dlibtest::AppData *appData, ImageButton *imgBt6) : outerInstance(outerInstance)
	{
		this->appData = appData;
		this->imgBt6 = imgBt6;
	}

	void GalleryFragment::OnClickListenerAnonymousInnerClass4::onClick(View *v)
	{
		appData->setImage(imgBt6->getDrawable());
//JAVA TO C++ CONVERTER TODO TASK: There is no C++ equivalent to the Java 'class' method:
		Intent tempVar(getActivity(), CameraActivity::class);
		startActivity(&tempVar);
	}
}
