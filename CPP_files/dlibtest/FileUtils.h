#pragma once

#include <string>
#include <vector>
#include <stdexcept>
#include "exceptionhelper.h"

/*
 * Copyright 2016-present Tzutalin
 *
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
 */

namespace com::tzutalin::dlibtest
{

	using Context = android::content::Context;



	/**
	 * Created by Tzutalin on 2016/3/30.
	 */
	class FileUtils
	{
	public:
//JAVA TO C++ CONVERTER TODO TASK: Most Java annotations will not have direct C++ equivalents:
//ORIGINAL LINE: @NonNull public static final void copyFileFromRawToOthers(@NonNull final android.content.Context context, @RawRes int id, @NonNull final String targetPath)
		static void copyFileFromRawToOthers(Context *const context, int id, const std::wstring &targetPath) final;
	};

}
