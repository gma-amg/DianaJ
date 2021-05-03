//====================================================================================================
//The Free Edition of Java to C++ Converter limits conversion output to 100 lines per file.

//To purchase the Premium Edition, visit our website:
//https://www.tangiblesoftwaresolutions.com/order/order-java-to-cplus.html
//====================================================================================================

#include "DebugLogFileTree.h"

namespace com::tzutalin::dlibtest
{
	using TextUtils = android::text::TextUtils;
	using Log = android::util::Log;
	using NonNull = androidx::annotation::NonNull;
	using BufferedWriter = java::io::BufferedWriter;
	using File = java::io::File;
	using FileWriter = java::io::FileWriter;
	using IOException = java::io::IOException;
	using PrintWriter = java::io::PrintWriter;
	using StringWriter = java::io::StringWriter;
	using WeakReference = java::lang::ref::WeakReference;
	using UnknownHostException = java::net::UnknownHostException;
	using SimpleDateFormat = java::text::SimpleDateFormat;
	using Date = java::util::Date;
	using BlockingQueue = java::util::concurrent::BlockingQueue;
	using LinkedBlockingQueue = java::util::concurrent::LinkedBlockingQueue;
	using Timber = timber::log::Timber;
const std::wstring DebugLogFileTree::TWO_SPACE = L"  ";

	DebugLogFileTree::DebugLogFileTree(const std::wstring &dir) : mLogDir(dir), mFilePath(mLogDir + File::separator + L"dlib.log"), mLogWriterWorker(new LogWriterWorker())
	{
		mLogWriterWorker->start(this);
	}

	void DebugLogFileTree::log(int priority, const std::wstring &tag, const std::wstring &message, std::runtime_error t)
	{
		timber::log::Timber::DebugTree::log(priority, tag, message, t);
		mLogWriterWorker->put(formatLog(priority, tag, message, t));
	}

	std::wstring DebugLogFileTree::formatLog(int priority, const std::wstring &tag, const std::wstring &message, std::runtime_error throwable)
	{
		StringBuilder *sb = new StringBuilder();
		if (throwable != nullptr && message == L"")
		{
			message = getStackTraceString(throwable);
		}
		if (message == L"")
		{
			message = L"No message/exception is set";
		}

		sb->append(getTimeStamp())->append(TWO_SPACE);
		sb->append(getThreadSignature())->append(TWO_SPACE);
		sb->append(tag)->append(L":")->append(getPriorityString(priority))->append(TWO_SPACE);
		sb->append(message);

		delete sb;
		return sb->toString();
	}

	std::wstring DebugLogFileTree::getStackTraceString(std::runtime_error tr)
	{
		if (tr == nullptr)
		{
			return L"";
		}

		// This is to reduce the amount of log spew that apps do in the non-error
		// condition of the network being unavailable.
		std::runtime_error t = tr;
		while (t != nullptr)
		{
			if (dynamic_cast<UnknownHostException*>(t) != nullptr)
			{
				return L"";
			}
			t = t.getCause();
		}

		StringWriter *sw = new StringWriter();
		PrintWriter *pw = new PrintWriter(sw);
		tr.printStackTrace(pw);
		pw->flush();

//JAVA TO C++ CONVERTER TODO TASK: A 'delete pw' statement was not added since pw was passed to a method or constructor. Handle memory management manually.
//JAVA TO C++ CONVERTER TODO TASK: A 'delete sw' statement was not added since sw was passed to a method or constructor. Handle memory management manually.
//JAVA TO C++ CONVERTER TODO TASK: There is no C++ equivalent to 'toString':
		return sw->toString();
	}

	std::wstring DebugLogFileTree::getThreadSignature()
	{
		Thread *t = Thread::currentThread();
		std::wstring name = t->getName();
		int id = android::os::Process::myTid();
		return std::wstring::format(L"%s:%d", name, id);
	}

	std::wstring DebugLogFileTree::getTimeStamp()
	{
		SimpleDateFormat tempVar(L"HH:mm:ss.SSS");
		return (&tempVar)->format(Date());
	}

	std::wstring DebugLogFileTree::getPriorityString(int priority)
	{
		if (priority == Log::ASSERT)
		{
			return L"A";
		}
		else if (priority == Log::ERROR)
		{
			return L"E";
		}
		else if (priority == Log::WARN)
		{
			return L"W";
		}
		else if (priority == Log::INFO)
		{
			return L"I";
		}
		else if (priority == Log::DEBUG)
		{
			return L"D";
		}
		else if (priority == Log::VERBOSE)
		{
			return L"V";
		}
		return L"";
	}

//JAVA TO C++ CONVERTER TODO TASK: Most Java annotations will not have direct C++ equivalents:
//ORIGINAL LINE: public void start(@NonNull DebugLogFileTree tree)
	void DebugLogFileTree::LogWriterWorker::start(DebugLogFileTree *tree)
	{
		if (isStart() == false)
		{
			mWeakRef = new WeakReference<DebugLogFileTree*>(tree);
			mQueue = new LinkedBlockingQueue<std::wstring>();
			Thread tempVar(this);
			(&tempVar)->start();
		}
	}

//JAVA TO C++ CONVERTER TODO TASK: Most Java annotations will not have direct C++ equivalents:
//ORIGINAL LINE: public void put(@NonNull String msg)
	void DebugLogFileTree::LogWriterWorker::put(const std::wstring &msg)
	{
		if (mQueue == nullptr)
		{
			return;
		}
		try
		{
			mQueue->put(msg);
		}
		catch (const InterruptedException &e)
		{
			e->printStackTrace();
		}
	}

	void DebugLogFileTree::LogWriterWorker::run()
	{
		// Open a new log file
		if (isLogFileOpen() == false)
		{
			open(mWeakRef->get().mFilePath);
		}
		std::wstring log;
		try
		{
			while ((log = mQueue->take()) != L"")
			{
				appendLog(log);
			}
		}
		catch (const InterruptedException &e)
		{
			e->printStackTrace();
		}
//JAVA TO C++ CONVERTER TODO TASK: There is no C++ equivalent to the exception 'finally' clause:
		finally
		{
			mQueue->clear();
			mQueue = nullptr;
			close();
		}
	}

	bool DebugLogFileTree::LogWriterWorker::isStart()
	{
		return mQueue != nullptr;
	}

	bool DebugLogFileTree::LogWriterWorker::isLogFileOpen()
	{
		return mBufferedWriter != nullptr;
	}

//JAVA TO C++ CONVERTER TODO TASK: Most Java annotations will not have direct C++ equivalents:
//ORIGINAL LINE: private boolean open(@NonNull String newFileName)

//====================================================================================================
//End of the allowed output for the Free Edition of Java to C++ Converter.

//To purchase the Premium Edition, visit our website:
//https://www.tangiblesoftwaresolutions.com/order/order-java-to-cplus.html
//====================================================================================================
