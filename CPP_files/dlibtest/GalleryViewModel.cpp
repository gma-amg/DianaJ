#include "GalleryViewModel.h"

namespace com::tzutalin::dlibtest
{
	using LiveData = androidx::lifecycle::LiveData;
	using MutableLiveData = androidx::lifecycle::MutableLiveData;
	using ViewModel = androidx::lifecycle::ViewModel;

	GalleryViewModel::GalleryViewModel()
	{
		mText = new MutableLiveData<std::wstring>();
		mText->setValue(L"This is gallery fragment");
	}

	LiveData<std::wstring> *GalleryViewModel::getText()
	{
		return mText;
	}
}
