/**
 * \file TreeFactory.cpp
 *
 * \author Charles Owen
 *
 * You are allowed to change this file.
 */

#include "stdafx.h"
#include "TreeFactory.h"
#include "Tree.h"
#include "BaseTree.h"
#include "Basket.h"
#include "DerivedBasket.h"
#include "LimbDrawable.h"

using namespace std;

/**
 * Constructor
 */
CTreeFactory::CTreeFactory()
{
}


/**
 * Destructor
 */
CTreeFactory::~CTreeFactory()
{
}


/**
 * Create a Tree object
 * \returns Object of type CTree
 */
std::shared_ptr<CTree> CTreeFactory::CreateTree()
{
	shared_ptr<CBaseTree> tree = make_shared<CBaseTree>();
	return tree;
}


/**
 * Create a Basket object
 * \returns Object of type CBasket
 */
std::shared_ptr<CBasket> CTreeFactory::CreateBasket()
{
	shared_ptr<CDerivedBasket> basket = make_shared<CDerivedBasket>();
	return basket;
}

