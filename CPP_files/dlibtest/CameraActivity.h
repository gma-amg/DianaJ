#pragma once

#include <string>
#include <unordered_map>
#include <vector>

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

	using Activity = android::app::Activity;
	using Intent = android::content::Intent;
	using Bundle = android::os::Bundle;
	using View = android::view::View;


	/**
	 * Created by darrenl on 2016/5/20.
	 */
	class CameraActivity : public Activity
	{

	private:
		static int OVERLAY_PERMISSION_REQ_CODE;
		static constexpr int CAMERA_PIC_REQUEST = 2500;

	protected:
		void onCreate(Bundle *const savedInstanceState) override;

		void onActivityResult(int requestCode, int resultCode, Intent *data) override;
	//    @Override
	//    protected void onActivityResult(int requestCode, int resultCode, Intent data){
	//        if(requestCode == CAMERA_PIC_REQUEST){
	//            Bitmap image = (Bitmap) data.getExtras().get("data");
	//            ImageView imageView = (ImageView) findViewById(R.id.imageView2);
	//            imageView.setImageBitmap(image);
	//        }
	//    }


	public:
		virtual void addToCart(View *view);

	};
}
