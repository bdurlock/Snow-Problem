/**
 * \file LimbDrawable.h
 *
 * \author Brett Durlock
 *
 * brief Draws the limbs
 */

#pragma once
#include "PartDrawable.h"

#include <vector>

/**
* \brief A drawable based on lines, for the limbs.
*
*/
class CLimbDrawable :
	public CPartDrawable
{
public:
	/**
	* Constructor
	* \param tree the tree that this limb belongs to
	*/
	CLimbDrawable(CBaseTree *tree) : CPartDrawable(tree)
	{
		mTree = tree;
	}

	/// virtual destructor
	virtual ~CLimbDrawable();

	/// Default constructor disabled
	CLimbDrawable() = delete;
	/** \brief Copy constructor disabled */
	CLimbDrawable(const CLimbDrawable &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CLimbDrawable &) = delete;

	/**
	* Draws the object
	* \param graphics the graphics
	* \param angle the angle of rotation
	* \param x the x location
	* \param y the y location
	*/
	virtual void Draw(Gdiplus::Graphics *graphics, double angle, double x, double y) override;

	/**
	* Grows the end
	* \param grow the growth rate
	*/
	virtual void Grow(double grow) override;

	/**
	* Sets the length of the limb
	* \param length the length that you're setting it to
	*/
	void SetLength(double length) { mLength = length; }

	/**
	* Sets the width of the limb
	* \param width the width that you're setting it to
	*/
	void SetWidth(double width) { mWidth = width; }

	/**
	* Sets the starting location, based of the parents end location
	* \param x the x location
	* \param y the y location
	*/
	void SetStart(double x, double y) { mLimbStart.X = x; mLimbStart.Y = y; }

	/**
	* Sets the ending location, based off the angle and length
	* \param angle the rotation
	* \param x the x location
	* \param y the y location
	*/
	void SetEnd(double angle, double x, double y);

	/**
	* returns the ending point of the object
	* \return the end point
	*/
	virtual Gdiplus::Point GetEnd() { return mLimbEnd; }

	/**
	* Sets the tree that this limb belongs to
	* \param tree the tree that you're setting
	*/
	void SetTree(CBaseTree *tree) { mTree = tree; }

private:
	/// The polygon color
	Gdiplus::Color mColor = Gdiplus::Color(139, 69, 19);

	/// Length of the limb
	double mLength = 3;

	/// The length a limb  must be before it has children
	double mSpawnLength = 10;

	/// The width of the limb
	double mWidth = .3;

	/// Grown boolean
	bool mGrown = false;

	/// limb starting point
	Gdiplus::Point mLimbStart;

	/// Limb ending point
	Gdiplus::Point mLimbEnd;

	/// The tree that this limb belongs to
	CBaseTree *mTree = nullptr;

	/// The windspeed of the tree
	double mWindSpeed;
};

