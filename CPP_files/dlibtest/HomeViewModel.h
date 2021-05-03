#pragma once

#include <string>

namespace com::tzutalin::dlibtest
{

	using LiveData = androidx::lifecycle::LiveData;
	using MutableLiveData = androidx::lifecycle::MutableLiveData;
	using ViewModel = androidx::lifecycle::ViewModel;

	class HomeViewModel : public ViewModel
	{

	private:
		MutableLiveData<std::wstring> *mText;

	public:
		virtual ~HomeViewModel()
		{
			delete mText;
		}

		HomeViewModel();

		virtual LiveData<std::wstring> *getText();
	};
}
