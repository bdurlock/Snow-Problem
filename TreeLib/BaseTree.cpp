/**
 * \file BaseTree.cpp
 *
 * \author Brett Durlock
 */

#include "stdafx.h"
#include "BaseTree.h"
#include "LimbDrawable.h"
#include "PartDrawable.h"

#include <memory>


CBaseTree::CBaseTree()
{
	std::shared_ptr<CLimbDrawable> trunk = std::make_shared<CLimbDrawable>(this);
	mRoot = trunk;
	mRoot->SetRotation(-0.785);
	mRoot->SetX(mX);
	mRoot->SetY(mY);
}


CBaseTree::~CBaseTree()
{
}


/**
* Set the position for the root of the tree
* \param x X location (pixels)
* \param y Y location (pixels)
*/
void CBaseTree::SetRootLocation(int x, int y)
{
	mX = x;
	mY = y;
}

/**
* Set the current tree frame
* \param frame Frame number
*/
void CBaseTree::SetTreeFrame(int frame)
{
	if (frame < mCurrentFrame)
	{
		Reset();
	}

	while (mCurrentFrame < frame)
	{
		mCurrentFrame++;
		double grow = 1.0 / 30;
		mRoot->Grow(grow);

	}
}

/**
* Set  the wind speed
* \param speed Wind speed in miles per hour
*/
void CBaseTree::SetWindSpeed(double speed)
{
	mWindSpeed = speed;
}

/**
* Harvest all of the fruit
* \return Vector of objects of type CFruit
*/
std::vector<std::shared_ptr<CFruit>> CBaseTree::Harvest()
{
	mHarvested = true;
	mTempFruit.clear();
	for (auto fruit : mFruit)
	{
		mTempFruit.push_back(fruit);
	}
	mFruit.clear();
	return mTempFruit;
}

void CBaseTree::DrawTree(Gdiplus::Graphics *graphics)
{
	if (mRoot != nullptr)
	{
		mRoot->Draw(graphics, mRoot->GetRotation(), mX, mY);
	}
}

void CBaseTree::SetRoot(std::shared_ptr<CPartDrawable> drawable)
{
	mRoot = drawable;
}

void CBaseTree::Reset()
{
	mCurrentFrame = 0;
	mRoot = std::make_shared<CLimbDrawable>(this);
	mRoot->SetRotation(-0.785);
	mRoot->SetX(mX);
	mRoot->SetY(mY);
	mRandom.Reset();
	mHarvested = false;
}