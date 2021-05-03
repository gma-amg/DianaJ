#pragma once

#include <string>

namespace com::tzutalin::dlibtest
{

	using LiveData = androidx::lifecycle::LiveData;
	using MutableLiveData = androidx::lifecycle::MutableLiveData;
	using ViewModel = androidx::lifecycle::ViewModel;

	class SlideshowViewModel : public ViewModel
	{

	private:
		MutableLiveData<std::wstring> *mText;

	public:
		virtual ~SlideshowViewModel()
		{
			delete mText;
		}

		SlideshowViewModel();

		virtual LiveData<std::wstring> *getText();
	};
}
