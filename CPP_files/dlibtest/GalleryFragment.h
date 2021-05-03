#pragma once

#include "GalleryViewModel.h"
#include "AppData.h"

namespace com::tzutalin::dlibtest
{

	using Bundle = android::os::Bundle;
	using View = android::view::View;
	using ViewGroup = android::view::ViewGroup;

	using Fragment = androidx::fragment::app::Fragment;

	class GalleryFragment : public Fragment
	{

	private:
		GalleryViewModel *galleryViewModel;

	public:
		virtual ~GalleryFragment()
		{
			delete galleryViewModel;
		}

//JAVA TO C++ CONVERTER TODO TASK: Most Java annotations will not have direct C++ equivalents:
//ORIGINAL LINE: public android.view.View onCreateView(@NonNull LayoutInflater inflater, android.view.ViewGroup container, android.os.Bundle savedInstanceState)
		virtual View *onCreateView(LayoutInflater *inflater, ViewGroup *container, Bundle *savedInstanceState);

	private:
		class OnClickListenerAnonymousInnerClass : public View::OnClickListener
		{
		private:
			GalleryFragment *outerInstance;

			com::tzutalin::dlibtest::AppData *appData;
			ImageButton *imgBt3;

		public:
			virtual ~OnClickListenerAnonymousInnerClass()
			{
				delete outerInstance;
				delete appData;
				delete imgBt3;
			}

			OnClickListenerAnonymousInnerClass(GalleryFragment *outerInstance, com::tzutalin::dlibtest::AppData *appData, ImageButton *imgBt3);

			void onClick(View *v) override;
		};

	private:
		class OnClickListenerAnonymousInnerClass2 : public View::OnClickListener
		{
		private:
			GalleryFragment *outerInstance;

			com::tzutalin::dlibtest::AppData *appData;
			ImageButton *imgBt4;

		public:
			virtual ~OnClickListenerAnonymousInnerClass2()
			{
				delete outerInstance;
				delete appData;
				delete imgBt4;
			}

			OnClickListenerAnonymousInnerClass2(GalleryFragment *outerInstance, com::tzutalin::dlibtest::AppData *appData, ImageButton *imgBt4);

			void onClick(View *v) override;
		};

	private:
		class OnClickListenerAnonymousInnerClass3 : public View::OnClickListener
		{
		private:
			GalleryFragment *outerInstance;

			com::tzutalin::dlibtest::AppData *appData;
			ImageButton *imgBt5;

		public:
			virtual ~OnClickListenerAnonymousInnerClass3()
			{
				delete outerInstance;
				delete appData;
				delete imgBt5;
			}

			OnClickListenerAnonymousInnerClass3(GalleryFragment *outerInstance, com::tzutalin::dlibtest::AppData *appData, ImageButton *imgBt5);

			void onClick(View *v) override;
		};

	private:
		class OnClickListenerAnonymousInnerClass4 : public View::OnClickListener
		{
		private:
			GalleryFragment *outerInstance;

			com::tzutalin::dlibtest::AppData *appData;
			ImageButton *imgBt6;

		public:
			virtual ~OnClickListenerAnonymousInnerClass4()
			{
				delete outerInstance;
				delete appData;
				delete imgBt6;
			}

			OnClickListenerAnonymousInnerClass4(GalleryFragment *outerInstance, com::tzutalin::dlibtest::AppData *appData, ImageButton *imgBt6);

			void onClick(View *v) override;
		};
	};

}
