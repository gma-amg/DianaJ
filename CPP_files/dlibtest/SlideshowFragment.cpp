#include "SlideshowFragment.h"

namespace com::tzutalin::dlibtest
{
	using Bundle = android::os::Bundle;
	using LayoutInflater = android::view::LayoutInflater;
	using View = android::view::View;
	using ViewGroup = android::view::ViewGroup;
	using TextView = android::widget::TextView;
	using NonNull = androidx::annotation::NonNull;
	using Nullable = androidx::annotation::Nullable;
	using Fragment = androidx::fragment::app::Fragment;
	using Observer = androidx::lifecycle::Observer;
	using ViewModelProviders = androidx::lifecycle::ViewModelProviders;

//JAVA TO C++ CONVERTER TODO TASK: Most Java annotations will not have direct C++ equivalents:
//ORIGINAL LINE: public android.view.View onCreateView(@NonNull LayoutInflater inflater, android.view.ViewGroup container, android.os.Bundle savedInstanceState)
	View *SlideshowFragment::onCreateView(LayoutInflater *inflater, ViewGroup *container, Bundle *savedInstanceState)
	{
//JAVA TO C++ CONVERTER TODO TASK: There is no C++ equivalent to the Java 'class' method:
		slideshowViewModel = ViewModelProviders::of(this)->get(SlideshowViewModel::class);
		View *root = inflater->inflate(R::layout::fragment_slideshow, container, false);
		TextView * const textView = root->findViewById(R::id::text_slideshow);
//JAVA TO C++ CONVERTER TODO TASK: Most Java annotations will not have direct C++ equivalents:
//ORIGINAL LINE: slideshowViewModel.getText().observe(getViewLifecycleOwner(), new androidx.lifecycle.Observer<String>()
		ObserverAnonymousInnerClass tempVar(this, textView);
		slideshowViewModel->getText()->observe(getViewLifecycleOwner(), &tempVar);
		return root;
	}

	SlideshowFragment::ObserverAnonymousInnerClass::ObserverAnonymousInnerClass(SlideshowFragment *outerInstance, TextView *textView) : outerInstance(outerInstance)
	{
		this->textView = textView;
	}

//JAVA TO C++ CONVERTER TODO TASK: Most Java annotations will not have direct C++ equivalents:
//ORIGINAL LINE: @Override public void onChanged(@Nullable String s)
	void SlideshowFragment::ObserverAnonymousInnerClass::onChanged(const std::wstring &s)
	{
		textView->setText(s);
	}
}
