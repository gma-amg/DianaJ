#include "ProductCardRecyclerViewAdapter.h"
#include "ItemSessionManager.h"

namespace com::tzutalin::dlibtest
{
	using Context = android::content::Context;
	using Drawable = android::graphics::drawable::Drawable;
	using Log = android::util::Log;
	using LayoutInflater = android::view::LayoutInflater;
	using View = android::view::View;
	using ViewGroup = android::view::ViewGroup;
	using ImageView = android::widget::ImageView;
	using Toast = android::widget::Toast;
	using Field = java::lang::reflect::Field;
	using ArrayList = java::util::ArrayList;
	using HashMap = java::util::HashMap;
	using List = java::util::List;
	using NonNull = androidx::annotation::NonNull;
	using RecyclerView = androidx::recyclerview::widget::RecyclerView;
const std::wstring ProductCardRecyclerViewAdapter::TAG = L"PrdCardRecyclerViewAdp";

	ProductCardRecyclerViewAdapter::ProductCardRecyclerViewAdapter(std::vector<ProductEntry*> &productList, Context *ctx, const std::wstring &menuItemId)
	{
		this->productList = productList;
		imageRequester = ImageRequester::getInstance(ctx);
		this->menuItemId = menuItemId;
	}

	ProductCardRecyclerViewAdapter::ProductCardRecyclerViewAdapter(std::vector<ProductEntry*> &productList, Context *ctx, const std::wstring &menuItemId, AppData *appData)
	{
		this->productList = productList;
		imageRequester = ImageRequester::getInstance(ctx);
		this->menuItemId = menuItemId;
		this->appData = appData;
		productDetails = std::unordered_map<int, ItemCartModel>();
	}

//JAVA TO C++ CONVERTER TODO TASK: Most Java annotations will not have direct C++ equivalents:
//ORIGINAL LINE: @NonNull @Override public ProductCardViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType)
	ProductCardViewHolder *ProductCardRecyclerViewAdapter::onCreateViewHolder(ViewGroup *parent, int viewType)
	{
		View *layoutView = LayoutInflater::from(parent->getContext()).inflate(R::layout::shr_product_card, parent, false);
		return new ProductCardViewHolder(layoutView);
	}

//JAVA TO C++ CONVERTER TODO TASK: Most Java annotations will not have direct C++ equivalents:
//ORIGINAL LINE: @Override public void onBindViewHolder(@NonNull ProductCardViewHolder holder, int position)
	void ProductCardRecyclerViewAdapter::onBindViewHolder(ProductCardViewHolder *holder, int position)
	{
//JAVA TO C++ CONVERTER TODO TASK: There is no C++ equivalent to the Java 'class' method:
		std::vector<Field*> drawables = R::drawable::class->getDeclaredFields();
		std::vector<Field*> jewel;
		for (auto f : drawables)
		{
			try
			{
				if (menuItemId == L"Earrings")
				{
					if (f->getName()->contains(L"stud") || f->getName()->contains(L"drops"))
					{
						jewel.push_back(f);
					}
				}
				else if (menuItemId == L"Neck Jewellery")
				{
					if (f->getName()->contains(L"necklace") || f->getName()->contains(L"chain"))
					{
						jewel.push_back(f);
					}
				}
			}
			catch (const std::runtime_error &e)
			{
				e.printStackTrace();
			}
		}

		if (!productList.empty() && position < productList.size())
		{
			ProductEntry *product = productList[position];
			holder->productTitle->setText(product->title);
			holder->productTitle->setContentDescription(product->url);
			holder->productPrice->setContentDescription(product->description);
			holder->productPrice->setText(product->price);
			holder->productHeight->setText(product->height);
			holder->productWidth->setText(product->width);
			holder->productButton->setId(index);
			holder->productImage->setImageDrawable(holder->itemView.getContext().getResources().getDrawable(holder->itemView.getContext().getResources().getIdentifier(jewel[position]->getName(), L"drawable", holder->itemView.getContext().getPackageName())));

			ItemCartModel *itemCartModel = new ItemCartModel();
			itemCartModel->setItemName(product->title);
			itemCartModel->setItemImages(jewel[position]->getName());
			//itemCartModel.setItemPrice(product.price);
			productDetails.emplace(index, itemCartModel);
			appData->setProductDetails(productDetails);
			++index;

//JAVA TO C++ CONVERTER TODO TASK: A 'delete itemCartModel' statement was not added since itemCartModel was passed to a method or constructor. Handle memory management manually.
		}

		OnClickListenerAnonymousInnerClass tempVar(this);
		holder->productButton->setOnClickListener(&tempVar);
	}

	ProductCardRecyclerViewAdapter::OnClickListenerAnonymousInnerClass::OnClickListenerAnonymousInnerClass(ProductCardRecyclerViewAdapter *outerInstance) : outerInstance(outerInstance)
	{
	}

	void ProductCardRecyclerViewAdapter::OnClickListenerAnonymousInnerClass::onClick(View *layout)
	{
		std::wcout << L"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << std::endl;

		int id = layout->getId();
		std::wcout << L"************************** " << id << std::endl;



		//final AppData appData = (AppData) getApplicationContext();
		std::unordered_map<int, ItemCartModel*> productDetails = outerInstance->appData->getProductDetails();
		ItemCartModel *itemCartModelStr = productDetails[id];
		std::wstring itemName = itemCartModelStr->getItemName();
		std::wcout << L"************************** " << itemName << std::endl;
		std::wstring itemImage = itemCartModelStr->getItemImages();
		std::wcout << L"************************** " << itemImage << std::endl;



			//        String itemName = appData.getItemName() ;

		Drawable *drImage = outerInstance->appData->getImage();
		std::unordered_map<std::wstring, Drawable*> drawableImages;
		std::vector<ItemCartModel*> itemSelected;
		Toast::makeText(layout->getContext(),L"Added to Cart",Toast::LENGTH_SHORT).show();
		ItemSessionManager *session = ItemSessionManager::getInstance(layout->getContext());
		ItemCartModel *itemCartModel = new ItemCartModel();
		itemCartModel->setItemName(itemName);
		itemCartModel->setItemQuantity(1);
		itemCartModel->setItemImages(itemImage);

		// get ArrayList Object
		itemSelected = session->loadData();
		itemSelected.push_back(itemCartModel);
		// session.removedFromCart(itemName);
		// set data to session object.
		session->addItemTOCart(itemSelected);
		// session.addItemToCart("Santosh");
		drawableImages = outerInstance->appData->getImageAddedToCart();
		if (drawableImages.empty())
		{
			drawableImages = std::unordered_map<std::wstring, Drawable>();
		}
		drawableImages.emplace(itemName, drImage);
		outerInstance->appData->setImageAddedToCart(drawableImages);

		//ArrayList<String> str = session.getUserDetails() ;
		// ArrayList<ItemCartModel> itemSelectedArr = session.loadData();
		// Toast.makeText(getApplicationContext(),"Added to Cart:"+ itemName,Toast.LENGTH_SHORT).show();
		//Intent intent = getIntent();
		//finish();
		//startActivity(intent);

//JAVA TO C++ CONVERTER TODO TASK: A 'delete itemCartModel' statement was not added since itemCartModel was passed to a method or constructor. Handle memory management manually.
	}

	int ProductCardRecyclerViewAdapter::getItemCount()
	{
		return productList.size();
	}
}
