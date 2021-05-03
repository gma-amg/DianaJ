#pragma once

#include <string>

namespace com::tzutalin::dlibtest
{

	using Context = android::content::Context;

	using RequestQueue = com::android::volley::RequestQueue;
	using ImageLoader = com::android::volley::toolbox::ImageLoader;
	using NetworkImageView = com::android::volley::toolbox::NetworkImageView;

	/**
	 * Class that handles image requests using Volley.
	 */
	class ImageRequester
	{
	private:
		static ImageRequester *instance;
		Context *const context;
		RequestQueue *const requestQueue;
		ImageLoader *const imageLoader;
		const int maxByteSize;

	public:
		virtual ~ImageRequester()
		{
			delete context;
			delete requestQueue;
			delete imageLoader;
		}

	private:
		ImageRequester(Context *ctx);

	private:
		class LruCacheAnonymousInnerClass : public LruCache<std::wstring, Bitmap*>
		{
		private:
			ImageRequester *outerInstance;

		public:
			virtual ~LruCacheAnonymousInnerClass()
			{
				delete outerInstance;
			}

			LruCacheAnonymousInnerClass(ImageRequester *outerInstance, int maxByteSize);

		protected:
			int sizeOf(const std::wstring &url, Bitmap *bitmap) override;
		};

		/**
		 * Get a static instance of ImageRequester
		 */
	public:
		static ImageRequester *getInstance(Context *ctx);

		/**
		 * Sets the image on the given {@link NetworkImageView} to the image at the given URL
		 *
		 * @param networkImageView {@link NetworkImageView} to set image on
		 * @param url              URL of the image
		 */
		virtual void setImageFromUrl(NetworkImageView *networkImageView, const std::wstring &url);

	private:
		int calculateMaxByteSize();
	};
}
