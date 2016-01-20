/**
* \file LightsaberFactory.h
*
* \author Brett Durlock
*
* Factory class that builds a lightsaber
*/

#include <memory>
#include "ActorFactory.h"
#include "Actor.h"

#pragma once

/**
* Factory class that builds a lightsaber
*/
class CLightsaberFactory : public CActorFactory
{
public:
	CLightsaberFactory();
	virtual ~CLightsaberFactory();

	std::shared_ptr<CActor> Create();
};

