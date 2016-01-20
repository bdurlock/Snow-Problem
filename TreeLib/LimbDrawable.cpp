/**
 * \file LimbDrawable.cpp
 *
 * \author Brett Durlock
 */

#include "stdafx.h"
#include "LimbDrawable.h"
#include "PseudoRandom.h"
#include "BaseTree.h"

#include <math.h>

using namespace Gdiplus;

/// The rate of growth for the tree
const double GrowthRate = 5;

CLimbDrawable::~CLimbDrawable()
{
}

void CLimbDrawable::SetEnd(double angle, double x, double y)
{
	double dx = cos(angle) * mLength;
	double dy = sin(angle) * mLength;

	mLimbEnd.X = x + dx;
	mLimbEnd.Y = y + dy;
}

void CLimbDrawable::Grow(double grow)
{
	double delta = 1 / 30;
	double growRate = pow((1.0 + GrowthRate), grow);
	int LimbDepth = this->GetDepth();
	if (mLength < (200.0/LimbDepth) && mWidth < (20.0/LimbDepth))
	{
		mLength *= growRate;
		mWidth *= growRate;
	}

	if (!this->GetChildren().empty())
	{
		for (auto child : this->GetChildren())
		{
			child->Grow(grow);
		}
	}
	if (mLength >= mSpawnLength && !mGrown)
	{
		this->Create();
		mGrown = true;
	}
}

void CLimbDrawable::Draw(Gdiplus::Graphics *graphics, double angle, double x, double y)
{
	double windspeed = mTree->GetWindSpeed() * 0.001 * this->GetDepth();

	double useAngle = angle + this->GetRotation() + windspeed;

	double dx = cos(useAngle) * mLength;
	double dy = sin(useAngle) * mLength;

	this->SetStart(x ,y);
	this->SetEnd(useAngle, x, y);

	Pen pen(mColor, (REAL)mWidth);
	pen.SetEndCap(LineCapRound);
	//graphics->DrawLine(&pen, mLimbStart.X, mLimbStart.Y, mLimbEnd.X, mLimbEnd.Y);
	graphics->DrawLine(&pen, (REAL)x, (REAL)y, (REAL)(x + dx), (REAL)(y + dy));

	double inc = 1;

	if (!this->GetChildren().empty())
	{
		for (auto child : this->GetChildren())
		{
			child->Draw(graphics, child->GetRotation(), (x + dx), (y + dy));
		}
	}
}
