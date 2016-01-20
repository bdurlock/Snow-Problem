/**
* \file DrOwenFactory.h
*
* \author Brett Durlock
*
* Factory class that builds the Dr Owen character
*/

#pragma once

#include <memory>
#include "ActorFactory.h"
#include "Actor.h"

#pragma once

/**
* Factory class that builds the Dr Owen character
*/
class CDrOwenFactory : public CActorFactory
{
public:
	CDrOwenFactory();
	virtual ~CDrOwenFactory();

	std::shared_ptr<CActor> Create();
};

