/**
 * \file PartDrawable.cpp
 *
 * \author Brett Durlock
 */

#include "stdafx.h"
#include "PartDrawable.h"
#include "LimbDrawable.h"
#include "LeafDrawable.h"
#include "FruitDrawable.h"
#include "Fruit.h"
#include "BaseTree.h"
#include <memory>

using namespace std;

void CPartDrawable::Create()
{
	CBaseTree *tree = GetTree();
	CPseudoRandom *rand = GetTree()->GetRandom();
	double depth = this->GetDepth();
	if (mDepth > 3 && rand->Random(0.0, 1.0) < 0.8)
	{
		auto leaf = std::make_shared<CLeafDrawable>(this->GetTree());
		leaf->SetRotation(rand->Random(-2.0, 2.0) + tree->GetWindSpeed());
		this->AddChild(leaf);
	}
	else if (mDepth <= 6)
	{
		auto limb = std::make_shared<CLimbDrawable>(this->GetTree());
		double rot2 = rand->Random(-0.5, 0.1);
		double parentrot2 = this->GetRotation();
		limb->SetRotation(parentrot2 + rot2 + tree->GetWindSpeed());
		int parentdepth = this->GetDepth();
		limb->SetDepth(parentdepth + 1);
		this->AddChild(limb);
	}

	if (mDepth > 4 && rand->Random(0.0, 1.0) < 0.1)
	{
		auto fruit = std::make_shared<CFruitDrawable>(this->GetTree());
		fruit->SetRotation(rand->Random(-0.5, 0.5) + tree->GetWindSpeed());
		this->AddChild(fruit);
		tree->AddFruit(fruit);
	}
	else if (mDepth <= 6)
	{
		auto limb = std::make_shared<CLimbDrawable>(this->GetTree());
		double rot4 = rand->Random(-0.1, 0.4);
		double parentrot2 = this->GetRotation();
		limb->SetRotation(parentrot2 + rot4 + tree->GetWindSpeed());
		int parentdepth = this->GetDepth();
		limb->SetDepth(parentdepth + 1);
		this->AddChild(limb);
	}

	if (mDepth <= 1 && rand->Random(0.0, 1.0) < 0.75)
	{
		auto limb = std::make_shared<CLimbDrawable>(this->GetTree());
		double rot4 = rand->Random(-0.6, 0.6);
		double parentrot2 = this->GetRotation();
		limb->SetRotation(parentrot2 + rot4 + tree->GetWindSpeed());
		int parentdepth = this->GetDepth();
		limb->SetDepth(parentdepth + 1);
		this->AddChild(limb);
	}
}

CPartDrawable::~CPartDrawable()
{
}

/**
* \brief Add a child drawable to this drawable
* \param child The child to add
*/
void CPartDrawable::AddChild(std::shared_ptr<CPartDrawable> child)
{
	this->mChildren.push_back(child);
	child->SetParent(this);
	child->SetTree(this->GetTree());
}


