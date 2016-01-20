/**
 * \file BasketAdapter.cpp
 *
 * \author Brett Durlock
 */

#include "stdafx.h"
#include "BasketAdapter.h"

using namespace Gdiplus;

CBasketAdapter::CBasketAdapter(const std::wstring &name) : CDrawable(name)
{

}

CBasketAdapter::~CBasketAdapter()
{
}

void CBasketAdapter::Draw(Gdiplus::Graphics *graphics)
{
	mBasket->DrawBasket(graphics);
}