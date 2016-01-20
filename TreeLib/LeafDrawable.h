/**
 * \file LeafDrawable.h
 *
 * \author Brett Durlock
 *
 * Draws a leaf
 */

#pragma once
#include "EndDrawable.h"
#include "BaseTree.h"
#include <memory>

using namespace Gdiplus;


/** Draws the leafs
 */
class CLeafDrawable : 
	public CEndDrawable
{
public:
	/**
	* Constructor
	* \param tree the tree that this leaf belongs to
	*/
	CLeafDrawable(CBaseTree *tree) : CEndDrawable(tree) { mTree = tree; }

	/// Virtual destructor
	virtual ~CLeafDrawable();

	/// Default constructor disabled
	CLeafDrawable() = delete;
	/** \brief Copy constructor disabled */
	CLeafDrawable(const CLeafDrawable &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CLeafDrawable &) = delete;

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

private:
	/// The image for this drawable
	Gdiplus::Bitmap *mImage;

	/// The tree that this leaf belongs to
	CBaseTree *mTree;

	/// The location of this tree
	Gdiplus::Point mPoint = Gdiplus::Point(0, 0);

	/// The scale of the leaf intially
	double mScale = .01;
};

