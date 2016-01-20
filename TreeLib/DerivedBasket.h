/**
 * \file DerivedBasket.h
 *
 * \author Brett Durlock
 *
 * 
 */

#pragma once
#include "Basket.h"
#include "PseudoRandom.h"

class CFruit;


/** Derived from the basket class so it can be implemented
 */
class CDerivedBasket :
	public CBasket
{
public:
	CDerivedBasket();
	virtual ~CDerivedBasket();

	/** \brief Copy constructor disabled */
	CDerivedBasket(const CDerivedBasket &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CDerivedBasket &) = delete;

	/**
	* Set the position for the basket.
	* \param x X location (pixels)
	* \param y Y location (pixels)
	*/
	virtual void SetBasketLocation(int x, int y);

	/**
	* Draw the tree at the currently specified location
	* \param graphics GDI+ Graphics object
	*/
	virtual void DrawBasket(Gdiplus::Graphics *graphics);

	/**
	* Add fruit to the basket
	* \param fruit Vector of fruit objects
	*/
	virtual void AddToBasket(std::vector < std::shared_ptr<CFruit>> fruit);

	/**
	* Empty all fruit from the basket
	*/
	virtual void EmptyBasket();

private:
	/// The image file for the front
	const std::wstring &ImageFront = L"images/basket-front.png";

	/// The image for the fruit drawable
	Gdiplus::Bitmap *mImageFront = (Gdiplus::Bitmap::FromFile(ImageFront.c_str()));

	/// The image file for the back
	const std::wstring &ImageBack = L"images/basket.png";

	/// The image for the fruit drawable
	Gdiplus::Bitmap *mImageBack = (Gdiplus::Bitmap::FromFile(ImageBack.c_str()));

	/// The collection of fruit in the basket
	std::vector < std::shared_ptr<CFruit>> mFruit;

	/// The file for the fruit image
	const std::wstring &fruitfile = L"images/fruit.png";

	/// The image for the leaf drawable
	Gdiplus::Bitmap *mFruitImage = (Gdiplus::Bitmap::FromFile(fruitfile.c_str()));

	int mSeed = 69;  ///< Tree seed

	/// The x location of the basket
	int mX = 50;

	/// The y location of the basket
	int mY = 500;

	///Random number
	CPseudoRandom mRandom = CPseudoRandom(mSeed);
};

