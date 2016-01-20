/**
 * \file PictureFactory.cpp
 *
 * \author Charles B. Owen
 */

#include "stdafx.h"
#include "PictureFactory.h"
#include "HaroldFactory.h"
#include "SpartyFactory.h"
#include "DrOwenFactory.h"
#include "LightsaberFactory.h"
#include "TreeFactory.h"
#include "ImageDrawable.h"
#include "BasketAdapter.h"
#include "TreeAdapter.h"

using namespace std;
using namespace Gdiplus;

CPictureFactory::CPictureFactory()
{
}


CPictureFactory::~CPictureFactory()
{
}


/*! \brief Factory method to create a new picture.
* \returns The created picture
*/
std::shared_ptr<CPicture> CPictureFactory::Create()
{
	shared_ptr<CPicture> picture = make_shared<CPicture>();

	// Create the background and add it
	auto background = make_shared<CActor>(L"Background");
	background->SetClickable(false);
	background->SetPosition(Point(-100, 0));
	auto backgroundI = make_shared<CImageDrawable>(L"Background", L"images/Background.png");
	background->AddDrawable(backgroundI);
	background->SetRoot(backgroundI);
	picture->AddActor(background);

	CTreeFactory tfactory;

	//Create the Basket
	auto basket = tfactory.CreateBasket();
	auto basket1 = make_shared<CActor>(L"Basket");
	basket1->SetClickable(false);
	mBasketImage = make_shared<CBasketAdapter>(L"Basket");
	mBasketImage->SetBasket(basket);
	basket1->AddDrawable(mBasketImage);
	picture->AddActor(basket1);


	// Create the Tree and add it
	auto tree = tfactory.CreateTree();
	auto tree1 = make_shared<CActor>(L"tree");
	tree1->SetClickable(false);
	mTreeImage1 = make_shared<CTreeAdapter>(L"tree");
	mTreeImage1->SetTimeline(picture->GetTimeline());
	mTreeImage1->SetPosition(600, 500);
	mTreeImage1->SetKeyFrame(150);
	mTreeImage1->SetTree(tree);
	tree1->AddDrawable(mTreeImage1);
	picture->AddActor(tree1);

	// Create the second Tree and add it
	auto tree3 = tfactory.CreateTree();
	auto tree4 = make_shared<CActor>(L"tree");
	tree4->SetClickable(false);
	mTreeImage2 = make_shared<CTreeAdapter>(L"tree");
	tree->SetSeed(50);
	mTreeImage2->SetTimeline(picture->GetTimeline());
	mTreeImage2->SetPosition(800, 450);
	mTreeImage1->SetKeyFrame(30);
	mTreeImage2->SetTree(tree3);
	tree4->AddDrawable(mTreeImage2);
	picture->AddActor(tree4);

	// Create and add Harold
	CHaroldFactory factory;
	auto harold = factory.Create();

	// Create and add Dr. Owen
	CDrOwenFactory owenfactory;
	auto drowen = owenfactory.Create();

	// Create the Lightsaber
	CLightsaberFactory saberfactory;
	auto lightsaber = saberfactory.Create();

	// This is where Harold will start out.
	harold->SetPosition(Point(500, 500));

	// This is where Dr. Owen will start out
	drowen->SetPosition(Point(550, 650));

	// This is where the lightsaber will start out
	lightsaber->SetPosition(Point(545, 750));

	picture->AddActor(harold);
	picture->AddActor(lightsaber);
	picture->AddActor(drowen);

	return picture;
}
