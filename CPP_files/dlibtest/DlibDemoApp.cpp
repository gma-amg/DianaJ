#include "DlibDemoApp.h"

namespace com::tzutalin::dlibtest
{
	using Application = android::app::Application;
	using Log = android::util::Log;
	using Timber = timber::log::Timber;

	void DlibDemoApp::onCreate()
	{
		android::app::Application::onCreate();

		if (BuildConfig::DEBUG)
		{
			Timber::DebugTree tempVar();
			Timber::plant(&tempVar);
			//Timber.plant(new DebugLogFileTree(Environment.getExternalStorageDirectory().toString()));
		}
		else
		{
			ReleaseTree tempVar2();
			Timber::plant(&tempVar2);
		}
	}

	void DlibDemoApp::ReleaseTree::log(int priority, const std::wstring &tag, const std::wstring &message, std::runtime_error t)
	{
		if (priority == Log::VERBOSE || priority == Log::DEBUG)
		{
			return;
		}
		timber::log::Timber::DebugTree::log(priority, tag, message, t);
	}
}
