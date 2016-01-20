/**
* \file HeadTop.h
*
* \author Brett Durlock
*
* Class for the top of the head
*/

#pragma once

#include <string>
#include <memory>

#include "AnimChannelPoint.h"
#include "ImageDrawable.h"





/**
*  Class for the top of the head
*/
class CHeadTop : public CImageDrawable
{
public:
	CHeadTop(const std::wstring &name, const std::wstring &filename);
	virtual ~CHeadTop();

	/** \brief Default constructor disabled */
	CHeadTop() = delete;
	/** \brief Copy constructor disabled */
	CHeadTop(const CHeadTop &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CHeadTop &) = delete;

	/** Returns if it's movable or not
	* \returns a boolean*/
	virtual bool IsMovable() override { return true; }

	/** Draws the drawable object
	* \param graphics What is being drawn*/
	virtual void Draw(Gdiplus::Graphics* graphics) override;

	/** The point where an object originates from
	* \param p The point
	* \return the point*/
	Gdiplus::Point TransformPoint(Gdiplus::Point p);

	void DrawEyebrow(Gdiplus::Graphics *graphics, Gdiplus::Point p1, Gdiplus::Point p2);

	void DrawEye(Gdiplus::Graphics *graphics, Gdiplus::Point p1);

	/** Sets the bool for mOWen to be true*/
	void SetOwen() { mOwen = true; }

	/** Sets the bool for mHarold to be true*/
	void SetHarold() { mHarold = true; }

	virtual void SetActor(CActor *actor) override;

	void virtual SetKeyframe();
	void virtual GetKeyframe();
	void virtual SetTimeline(CTimeline *timeline);

private:
	/// draws Dr. Owen's eyes
	bool mOwen = false;

	/// draws Harold's eyes
	bool mHarold = false;

	/// File for Dr. Owen's eyes
	std::unique_ptr<Gdiplus::Bitmap> mOwenEyes;

	/// The animation channel for animating the position
	CAnimChannelPoint mPositionChannel;


};

