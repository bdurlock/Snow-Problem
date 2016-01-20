/**
* \file LightsaberFactory.cpp
*
* \author Brett Durlock
*/

#include "stdafx.h"
#include "LightsaberFactory.h"
#include "PolyDrawable.h"
#include "ImageDrawable.h"
#include "HeadTop.h"

using namespace Gdiplus;
using namespace std;


CLightsaberFactory::CLightsaberFactory()
{
}


CLightsaberFactory::~CLightsaberFactory()
{
}

/** This is a concrete factory method that creates our Lightsaber actor.
* \returns Pointer to an actor object.
*/
std::shared_ptr<CActor> CLightsaberFactory::Create()
{
	shared_ptr<CActor> actor = make_shared<CActor>(L"Lightsaber");

	auto hilt = make_shared<CImageDrawable>(L"Hilt", L"images/lightsaber_nolight.png");
	hilt->SetCenter(Point(44, 138));
	hilt->SetPosition(Point(-335, -435));
	hilt->SetRotation(2.85);
	actor->SetRoot(hilt);

	auto light = make_shared<CImageDrawable>(L"Light", L"images/lightsaber.png");
	light->SetCenter(Point(57, 130));
	light->SetPosition(Point(13, -8));
	hilt->AddChild(light);

	actor->AddDrawable(hilt);
	actor->AddDrawable(light);

	return actor;
}