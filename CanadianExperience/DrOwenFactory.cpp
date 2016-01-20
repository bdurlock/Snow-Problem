/**
* \file DrOwenFactory.cpp
*
* \author Brett Durlock
*/

#include "stdafx.h"
#include "DrOwenFactory.h"
#include "PolyDrawable.h"
#include "ImageDrawable.h"
#include "HeadTop.h"

using namespace std;
using namespace Gdiplus;

CDrOwenFactory::CDrOwenFactory()
{
}


CDrOwenFactory::~CDrOwenFactory()
{
}

/** This is a concrete factory method that creates our Dr Owen actor.
* \returns Pointer to an actor object.
*/
std::shared_ptr<CActor> CDrOwenFactory::Create()
{
	shared_ptr<CActor> actor = make_shared<CActor>(L"Owen");

	auto body = make_shared<CImageDrawable>(L"Body", L"images/owen_body.png");
	body->SetCenter(Point(44, 138));
	body->SetPosition(Point(-300, -450));
	actor->SetRoot(body);

	auto lleg = make_shared<CImageDrawable>(L"Left Leg", L"images/owen_lleg.png");
	lleg->SetCenter(Point(90, 250));
	lleg->SetPosition(Point(50, 115));
	body->AddChild(lleg);

	auto rleg = make_shared<CImageDrawable>(L"Right Leg", L"images/owen_rleg.png");
	rleg->SetCenter(Point(50, 250));
	rleg->SetPosition(Point(10, 115));
	body->AddChild(rleg);

	auto headb = make_shared<CImageDrawable>(L"Head Bottom", L"images/owen_headb.png");
	headb->SetCenter(Point(75, 60));
	headb->SetPosition(Point(31, -79));
	body->AddChild(headb);

	auto headt = make_shared<CHeadTop>(L"Head Top", L"images/owen_headt.png");
	std::wstring eyes = std::wstring(L"owen");
	headt->SetOwen();
	headt->SetCenter(Point(75, 45));
	headt->SetPosition(Point(0, -15));
	headb->AddChild(headt);

	auto larm = make_shared<CImageDrawable>(L"Left Arm", L"images/owen_larm.png");
	larm->SetCenter(Point(115, 100));
	larm->SetPosition(Point(72, -38));
	body->AddChild(larm);


	auto rarm = make_shared<CImageDrawable>(L"Right Arm", L"images/owen_rarm.png");
	rarm->SetCenter(Point(30, 100));
	rarm->SetPosition(Point(-16, -38));
	body->AddChild(rarm);


	actor->AddDrawable(larm);
	actor->AddDrawable(rarm);
	actor->AddDrawable(rleg);
	actor->AddDrawable(lleg);
	actor->AddDrawable(body);
	actor->AddDrawable(headb);
	actor->AddDrawable(headt);

	return actor;
}
