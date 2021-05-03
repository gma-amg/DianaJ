#include "SlideshowViewModel.h"

namespace com::tzutalin::dlibtest
{
	using LiveData = androidx::lifecycle::LiveData;
	using MutableLiveData = androidx::lifecycle::MutableLiveData;
	using ViewModel = androidx::lifecycle::ViewModel;

	SlideshowViewModel::SlideshowViewModel()
	{
		mText = new MutableLiveData<std::wstring>();
		mText->setValue(L"This is slideshow fragment");
	}

	LiveData<std::wstring> *SlideshowViewModel::getText()
	{
		return mText;
	}
}
