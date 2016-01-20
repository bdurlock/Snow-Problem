/**
 * \file LeafDrawable.cpp
 *
 * \author Brett Durlock
 */

#include "stdafx.h"
#include "LeafDrawable.h"
#include "BaseTree.h"
#include <string>
#include <memory>

using namespace std;
using namespace Gdiplus;

/// Constant growth rate
const double GrowthRate = 3;

/// Constant ratio to convert radians to degrees
const double RtoD = 57.295779513;

CLeafDrawable::~CLeafDrawable()
{
}

void CLeafDrawable::Draw(Gdiplus::Graphics *graphics, double angle, double x, double y)
{
	auto state = graphics->Save();
	graphics->TranslateTransform(x, y);
	graphics->RotateTransform((float)(angle * RtoD)+180);
	mImage = mTree->GetLeafImage();
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

void CLeafDrawable::Grow(double grow)
{
	double delta = 1 / 30;
	double growRate = pow((1.0 + GrowthRate), grow);
	int LimbDepth = this->GetDepth();
	if (mScale < 0.3)
	{
		mScale *= growRate;
	}
}