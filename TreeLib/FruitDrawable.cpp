/**
 * \file FruitDrawable.cpp
 *
 * \author Brett Durlock
 */

#include "stdafx.h"
#include "FruitDrawable.h"
#include "PseudoRandom.h"
#include "BaseTree.h"
#include "Fruit.h"

/// Constant growth rate
const double GrowthRate = 3;

/// Constant ratio to convert radians to degrees
const double RtoD = 57.295779513;

CFruitDrawable::~CFruitDrawable()
{
}

void CFruitDrawable::Draw(Gdiplus::Graphics *graphics, double angle, double x, double y)
{
	if (!mTree->GetHarvested())
	{
		auto state = graphics->Save();
		graphics->TranslateTransform(x, y);
		graphics->RotateTransform((float)(angle * RtoD + 180));
		mImage = mTree->GetFruitImage();
		float width = mImage->GetWidth();
		float height = mImage->GetHeight();
		float centerx = this->GetCenter().X - (50 * mScale);
		float centery = this->GetCenter().Y - (90 * mScale);
		graphics->DrawImage(mImage,
			centerx,
			centery,
			width * mScale,
			height * mScale);
		graphics->Restore(state);
	}
}

void CFruitDrawable::Grow(double grow)
{
	double delta = 1 / 30;
	double growRate = pow((1.0 + GrowthRate), grow);
	int LimbDepth = this->GetDepth();
	if (mScale < 0.2)
	{
		mScale *= growRate;
	}
}

void CFruitDrawable::SetBasketPosition(int x, int y)
{

}

void CFruitDrawable::DrawInBasket(Gdiplus::Graphics *graphics, int x, int y)
{
	auto state = graphics->Save();
	graphics->TranslateTransform(x, y);
	mImage = mTree->GetFruitImage();
	float width = mImage->GetWidth();
	float height = mImage->GetHeight();
	float centerx = this->GetCenter().X - (50 * mScale);
	float centery = this->GetCenter().Y - (90 * mScale);
	graphics->DrawImage(mImage,
		centerx,
		centery,
		width * mScale,
		height * mScale);
	graphics->Restore(state);
}