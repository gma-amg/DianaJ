#include "ImageRequester.h"

namespace com::tzutalin::dlibtest
{
	using Context = android::content::Context;
	using Bitmap = android::graphics::Bitmap;
	using DisplayMetrics = android::util::DisplayMetrics;
	using LruCache = android::util::LruCache;
	using RequestQueue = com::android::volley::RequestQueue;
	using ImageLoader = com::android::volley::toolbox::ImageLoader;
	using NetworkImageView = com::android::volley::toolbox::NetworkImageView;
	using Volley = com::android::volley::toolbox::Volley;
ImageRequester *ImageRequester::instance = nullptr;

	ImageRequester::ImageRequester(Context *ctx) : context(ctx), requestQueue(Volley::newRequestQueue(context)), imageLoader(new ImageLoader(requestQueue, new ImageLoader::ImageCache()), maxByteSize(calculateMaxByteSize())
	{
		this->requestQueue->start();
		{
							final LruCache<std::wstring, Bitmap*> lruCache = new LruCacheAnonymousInnerClass(this, maxByteSize);

						public:
							synchronized Bitmap getBitmap(std::wstring url)
							{
								return lruCache->get(url);
							}

							synchronized void putBitmap(std::wstring url, Bitmap bitmap)
							{
								lruCache::put(url, bitmap);
							}
		}
						);
	}

	ImageRequester::LruCacheAnonymousInnerClass::LruCacheAnonymousInnerClass(ImageRequester *outerInstance, int maxByteSize) : android::util::LruCache<String, android::graphics::Bitmap>(maxByteSize), outerInstance(outerInstance)
	{
	}

	int ImageRequester::LruCacheAnonymousInnerClass::sizeOf(const std::wstring &url, Bitmap *bitmap)
	{
		return bitmap->getByteCount();
	}

	ImageRequester *ImageRequester::getInstance(Context *ctx)
	{
		if (instance == nullptr)
		{
			instance = new ImageRequester(ctx);
		}
		return instance;
	}

	void ImageRequester::setImageFromUrl(NetworkImageView *networkImageView, const std::wstring &url)
	{
		networkImageView->setImageUrl(url, imageLoader);
	}

	int ImageRequester::calculateMaxByteSize()
	{
		DisplayMetrics *displayMetrics = context->getResources().getDisplayMetrics();
		constexpr int screenBytes = displayMetrics->widthPixels * displayMetrics->heightPixels * 4;
		return screenBytes * 3;
	}
}
