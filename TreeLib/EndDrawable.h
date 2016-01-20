/**
 * \file EndDrawable.h
 *
 * \author Brett Durlock
 *
 * 
 */

#pragma once

#include "PartDrawable.h"

class CBaseTree;

using namespace Gdiplus;

/** Draws the ends of branches, including the leafs and fruit
 */
class CEndDrawable :
	public CPartDrawable
{
public:
	/**
	* Constructor
	* \param tree the tree that this drawable belongs to
	*/
	CEndDrawable(CBaseTree *tree) : CPartDrawable(tree){}

	/// destructor
	virtual ~CEndDrawable();

	/// Default constructor deleted
	CEndDrawable() = delete;
	/** \brief Copy constructor disabled */
	CEndDrawable(const CEndDrawable &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CEndDrawable &) = delete;

	/**
	* Grows the end
	* \param grow the growth rate
	*/
	virtual void Grow(double grow) = 0;

	/**
	* Draws the object
	* \param graphics the graphics
	* \param angle the angle of rotation
	* \param x the x location
	* \param y the y location
	*/
	virtual void Draw(Gdiplus::Graphics *graphics, double angle, double x, double y) = 0;

	/**
	* Sets the center of the object
	* \param x the x location
	* \param y the y location
	*/
	virtual void SetCenter(int x, int y) { mCenter.X = x; mCenter.Y = y; }

	/**
	* Gets the center
	* \return the center point
	*/
	Gdiplus::Point GetCenter() { return mCenter; }

private:
	/// The center of the image
	Gdiplus::Point mCenter = Gdiplus::Point(0, 0);

	/// The image for this drawable
	std::unique_ptr<Gdiplus::Bitmap> mImage;
};

