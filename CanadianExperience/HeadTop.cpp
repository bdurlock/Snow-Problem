/**
* \file HeadTop.cpp
*
* \author Brett Durlock
*/

#include "stdafx.h"
#include "HeadTop.h"
#include "Actor.h"
#include "Timeline.h"

#include <sstream>
#include <iomanip>

using namespace Gdiplus;
using namespace std;

/// Constant ratio to convert radians to degrees
const double RtoD = 57.295779513;

/// constant file name for Dr Owen's eyes
const std::wstring OwenEyes(L"images/owen_eyes.png");

/** Constructor
* \param name The drawable name
* \param filename The filename for the iamge */
CHeadTop::CHeadTop(const std::wstring &name, const std::wstring &filename) : CImageDrawable(name, filename)
{
	mImage = unique_ptr<Bitmap>(Bitmap::FromFile(filename.c_str()));
	if (mImage->GetLastStatus() != Ok)
	{
		wstring msg(L"Failed to open ");
		msg += filename;
		AfxMessageBox(msg.c_str());
	}
}

CHeadTop::~CHeadTop()
{
}

/**
* \brief Set the actor. This is where we set the channel name
* \param actor Actor to set
*/
void CHeadTop::SetActor(CActor *actor)
{
	CImageDrawable::SetActor(actor);

	// Set the channel name
	mPositionChannel.SetName(actor->GetName() + L":" + GetName() + L":position");

}

/** Transform a point from a location on the bitmap to
*  a location on the screen.
* \param  p Point to transform
* \returns Transformed point
*/
Gdiplus::Point CHeadTop::TransformPoint(Gdiplus::Point p)
{
	// Make p relative to the image center
	p = p - GetCenter();

	// Rotate as needed and offset
	return RotatePoint(p, mPlacedR) + mPlacedPosition;
}

void CHeadTop::Draw(Gdiplus::Graphics* graphics)
{
	CImageDrawable::Draw(graphics);

	Point p = TransformPoint(Point(50, 85));

	if (mHarold)
	{
		DrawEyebrow(graphics, Point(32, 63), Point(46, 61));
		DrawEyebrow(graphics, Point(64, 59), Point(77, 61));

		DrawEye(graphics, Point(42, 79));
		DrawEye(graphics, Point(69, 79));
	}

	if (mOwen)
	{
		auto state = graphics->Save();
		auto eyes = make_shared<CImageDrawable>(L"eyes", L"images/owen_eyes.png");
		mOwenEyes = unique_ptr<Bitmap>(Bitmap::FromFile(OwenEyes.c_str()));
		graphics->TranslateTransform(p.X, p.Y);
		graphics->RotateTransform((float)(-mPlacedR * RtoD));
		graphics->DrawImage(mOwenEyes.get(), -51, -80, 150, 380);
		graphics->Restore(state);
	}
}

/**
* Draw an eyebrow, automatically transforming the points
*
* Draw a line from (x1, y1) to (x2, y2) after transformation
* to the local coordinate system.
* \param graphics Graphics context to draw on
* \param p1 First point
* \param p2 Second point
*/
void CHeadTop::DrawEyebrow(Gdiplus::Graphics *graphics,
	Gdiplus::Point p1, Gdiplus::Point p2)
{
	Point eb1 = TransformPoint(p1);
	Point eb2 = TransformPoint(p2);

	Pen eyebrowPen(Color::Black, 2);
	graphics->DrawLine(&eyebrowPen, eb1, eb2);
}

/** Draw an eye using an Ellipse
* \param graphics The graphics context to draw on
* \param p1 Where to draw before transformation */
void CHeadTop::DrawEye(Gdiplus::Graphics *graphics, Gdiplus::Point p1)
{
	SolidBrush brush(Color::Black);

	Point e1 = TransformPoint(p1);

	float wid = 15.0f;
	float hit = 20.0f;

	auto state = graphics->Save();
	graphics->TranslateTransform((float)e1.X, (float)e1.Y);
	graphics->RotateTransform((float)(-mPlacedR * RtoD));
	graphics->FillEllipse(&brush, -wid / 2, -hit / 2, wid, hit);
	graphics->Restore(state);
}

/** Add the channels for this drawable to a timeline
* \param timeline The timeline class.
*/
void CHeadTop::SetTimeline(CTimeline *timeline)
{
	timeline->AddChannel(GetAngleChannel());
	timeline->AddChannel(&mPositionChannel);
}

/** \brief Set the keyframe based on the current status.
*/
void CHeadTop::SetKeyframe()
{
	GetAngleChannel()->SetKeyframe(GetRotation());
	mPositionChannel.SetKeyframe(GetPosition());
}

/** \brief Get the current channel from the animation system.
*/
void CHeadTop::GetKeyframe()
{
	if (mPositionChannel.IsValid())
		SetPosition(mPositionChannel.GetPoint());
	if (GetAngleChannel()->IsValid())
		SetRotation(GetAngleChannel()->GetAngle());
}