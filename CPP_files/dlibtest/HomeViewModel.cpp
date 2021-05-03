#include "HomeViewModel.h"

namespace com::tzutalin::dlibtest
{
	using LiveData = androidx::lifecycle::LiveData;
	using MutableLiveData = androidx::lifecycle::MutableLiveData;
	using ViewModel = androidx::lifecycle::ViewModel;

	HomeViewModel::HomeViewModel()
	{
		mText = new MutableLiveData<std::wstring>();
		mText->setValue(L"Discover Jewelry That's Perfect For You");
	}

	LiveData<std::wstring> *HomeViewModel::getText()
	{
		return mText;
	}
}
