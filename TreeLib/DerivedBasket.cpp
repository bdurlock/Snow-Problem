/**
 * \file DerivedBasket.cpp
 *
 * \author Brett Durlock
 */

#include "stdafx.h"
#include "DerivedBasket.h"
#include "Fruit.h"
#include "FruitDrawable.h"
#include <memory>

using namespace Gdiplus;

CDerivedBasket::CDerivedBasket()
{
}


CDerivedBasket::~CDerivedBasket()
{
}

/**
* Set the position for the basket.
* \param x X location (pixels)
* \param y Y location (pixels)
*/
void CDerivedBasket::SetBasketLocation(int x, int y)
{
	mX = x;
	mY = y;
}

/**
* Draw the tree at the currently specified location
* \param graphics GDI+ Graphics object
*/
void CDerivedBasket::DrawBasket(Gdiplus::Graphics *graphics)
{
	auto state = graphics->Save();
	graphics->TranslateTransform(10, 300);
	float BackWidth = mImageBack->GetWidth();
	float BackHeight = mImageBack->GetHeight();
	float FrontWidth = mImageFront->GetWidth();
	float FrontHeight = mImageFront->GetHeight();
	graphics->DrawImage(mImageBack, (float)BackWidth/2, (float)BackHeight/2, BackWidth, BackHeight);

	//for (auto fruit : mFruit)
	for (int i = 0; i < mFruit.size(); i++)
	{
		mRandom = CPseudoRandom(i);
		double rotation = mRandom.Random(-45.0, 45.0);
		double dx = mRandom.Random(-30.0, 30.0);
		double dy = mRandom.Random(-10.0, 10.0);

		auto statebasket = graphics->Save();
		graphics->TranslateTransform(120, 120);
		graphics->RotateTransform(180 + rotation);
		float width = mFruitImage->GetWidth();
		float height = mFruitImage->GetHeight();
		graphics->DrawImage(mFruitImage,
			(float)(-23 + dx),
			(float)(-15 + dy),
			width*.4,
			height*.4);
		graphics->Restore(statebasket);
	}

	graphics->DrawImage(mImageFront, (float)BackWidth / 2, (float)BackHeight / 2, FrontWidth, FrontHeight);

	graphics->Restore(state);
}

/**
* Add fruit to the basket
* \param fruit Vector of fruit objects
*/
void CDerivedBasket::AddToBasket(std::vector < std::shared_ptr<CFruit>> fruit)
{
	for (auto indfruit : fruit)
	{
		mFruit.push_back(indfruit);
	}
}

/**
* Empty all fruit from the basket
*/
void CDerivedBasket::EmptyBasket()
{
	mFruit.clear();
}
