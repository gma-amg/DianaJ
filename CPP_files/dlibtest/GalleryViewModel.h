#pragma once

#include <string>

namespace com::tzutalin::dlibtest
{

	using LiveData = androidx::lifecycle::LiveData;
	using MutableLiveData = androidx::lifecycle::MutableLiveData;
	using ViewModel = androidx::lifecycle::ViewModel;

	class GalleryViewModel : public ViewModel
	{

	private:
		MutableLiveData<std::wstring> *mText;

	public:
		virtual ~GalleryViewModel()
		{
			delete mText;
		}

		GalleryViewModel();

		virtual LiveData<std::wstring> *getText();
	};
}
