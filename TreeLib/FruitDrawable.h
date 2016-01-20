/**
 * \file FruitDrawable.h
 *
 * \author Brett Durlock
 *
 * 
 */

#pragma once
#include "EndDrawable.h"
#include "Fruit.h"


/** Draws the fruit
 */
class CFruitDrawable :
	public CEndDrawable, public CFruit
{
public:
	/**
	* Constructor
	* \param tree the tree that this fruit belongs to
	*/
	CFruitDrawable(CBaseTree *tree) : CEndDrawable(tree) { mTree = tree; }

	/// The virtual destructor
	virtual ~CFruitDrawable();

	/** \brief Default constructor disabled */
	CFruitDrawable() = delete;
	/** \brief Copy constructor disabled */
	CFruitDrawable(const CFruitDrawable &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CFruitDrawable &) = delete;

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
	* Set the position of the fruit in the basket
	*
	* This position is relative to the basket, so
	* it will be added to the basket location passed
	* to DrawInBasket when we draw it
	* \param x X position in pixels
	* \param y Y position in pixels
	*/
	virtual void SetBasketPosition(int x, int y);

	/**
	* Draw the fruit in the basket
	* \param graphics The graphics object to draw on
	* \param x X location of the basket
	* \param y Y location of the basket
	*/
	virtual void DrawInBasket(Gdiplus::Graphics *graphics, int x, int y);

private:
	/// The image for this drawable
	Gdiplus::Bitmap *mImage;

	/// the tree that this fruit belongs to
	CBaseTree *mTree;

	/// point location of this fruit
	Gdiplus::Point mPoint = Gdiplus::Point(0, 0);

	/// The scale of the fruit initially
	double mScale = .01;
};

