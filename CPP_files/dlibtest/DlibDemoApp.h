#pragma once

#include <string>
#include <stdexcept>

/*
 * Copyright (c) 2017. Tzutalin
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

namespace com::tzutalin::dlibtest
{

	using Application = android::app::Application;

	using Timber = timber::log::Timber;

	/**
	 * Created by tzutalin on 2017/2/23.
	 */
	class DlibDemoApp : public Application
	{
	public:
		void onCreate() override;

		/**
		 * A tree which logs important information
		 */
	private:
		class ReleaseTree : public Timber::DebugTree
		{
		protected:
			void log(int priority, const std::wstring &tag, const std::wstring &message, std::runtime_error t) override;
		};
	};

}
