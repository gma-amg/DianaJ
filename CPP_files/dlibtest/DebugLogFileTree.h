#pragma once

#include <string>
#include <stdexcept>
#include "exceptionhelper.h"
#include "../stringbuilder.h"

//JAVA TO C++ CONVERTER NOTE: Forward class declarations:
namespace com::tzutalin::dlibtest { class LogWriterWorker; }

/*
 * Copyright (c) 2017-present. Tzutalin
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

	//import android.support.annotation.NonNull;


	using BufferedWriter = java::io::BufferedWriter;
	using WeakReference = java::lang::ref::WeakReference;
	using BlockingQueue = java::util::concurrent::BlockingQueue;

	using Timber = timber::log::Timber;

	/**
	 * Created by tzutalin on 2017/2/23.
	 */
	class DebugLogFileTree : public Timber::DebugTree
	{

	private:
		static const std::wstring TWO_SPACE;
		const std::wstring mLogDir;
		const std::wstring mFilePath;
		LogWriterWorker *const mLogWriterWorker;

	public:
		virtual ~DebugLogFileTree()
		{
			delete mLogWriterWorker;
		}

		DebugLogFileTree(const std::wstring &dir);

	protected:
		void log(int priority, const std::wstring &tag, const std::wstring &message, std::runtime_error t) override;

	private:
		std::wstring formatLog(int priority, const std::wstring &tag, const std::wstring &message, std::runtime_error throwable);

		std::wstring getStackTraceString(std::runtime_error tr);

		std::wstring getThreadSignature();

		std::wstring getTimeStamp();

	public:
		virtual std::wstring getPriorityString(int priority);

	private:
		class LogWriterWorker : public Runnable
		{
		private:
			WeakReference<DebugLogFileTree*> *mWeakRef;
			BufferedWriter *mBufferedWriter;
			BlockingQueue<std::wstring> *mQueue;

		public:
			virtual ~LogWriterWorker()
			{
				delete mWeakRef;
				delete mBufferedWriter;
				delete mQueue;
			}

//JAVA TO C++ CONVERTER TODO TASK: Most Java annotations will not have direct C++ equivalents:
//ORIGINAL LINE: public void start(@NonNull DebugLogFileTree tree)
			virtual void start(DebugLogFileTree *tree);

			// Producer on any thread
//JAVA TO C++ CONVERTER TODO TASK: Most Java annotations will not have direct C++ equivalents:
//ORIGINAL LINE: public void put(@NonNull String msg)
			virtual void put(const std::wstring &msg);

			// Consumer on LogWriterWorker's thread
			void run() override;

		private:
			bool isStart();

			bool isLogFileOpen();

//JAVA TO C++ CONVERTER TODO TASK: Most Java annotations will not have direct C++ equivalents:
//ORIGINAL LINE: private boolean open(@NonNull String newFileName)
			bool open(const std::wstring &newFileName);

			bool close();

//JAVA TO C++ CONVERTER TODO TASK: Most Java annotations will not have direct C++ equivalents:
//ORIGINAL LINE: private void appendLog(@NonNull String flattenedLog)
			void appendLog(const std::wstring &flattenedLog);
		};
	};


}
