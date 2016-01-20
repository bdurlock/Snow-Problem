/**
 * \file TreeAdapter.cpp
 *
 * \author Brett Durlock
 */

#include "stdafx.h"
#include "TreeAdapter.h"
#include "Timeline.h"
#include "TreeSeedDlg.h"
#include "resource.h"

using namespace Gdiplus;

CTreeAdapter::CTreeAdapter(const std::wstring &name) :CDrawable(name)
{

}

CTreeAdapter::~CTreeAdapter()
{
}

void CTreeAdapter::Draw(Gdiplus::Graphics *graphics)
{
	mTree->SetRootLocation(mX, mY);
	if (mTimeline->GetCurrentFrame() >= mInitialFrame)
		mTree->SetTreeFrame(mTimeline->GetCurrentFrame() - mInitialFrame);
	else
		mTree->SetTreeFrame(0);
	mTree->DrawTree(graphics);
}

void CTreeAdapter::SetPosition(int x, int y) 
{
	mX = x;
	mY = y;
}

void CTreeAdapter::SetKeyFrame(int frame)
{
	mInitialFrame = frame; 
	if (mTree != nullptr)
	{
		mTree->SetTreeFrame(frame);
		mSeed = mTree->GetSeed();
	}
}

void CTreeAdapter::ShowDialogBox()
{
	CTreeSeedDlg dlg(mTree);
	if (dlg.DoModal() == IDOK)
	{
		mTree->SetTreeFrame(0);
		mTree->SetTreeFrame(mTimeline->GetCurrentFrame());
	}
}