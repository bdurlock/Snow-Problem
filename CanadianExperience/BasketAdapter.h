/**
* \file TreeAdapter.h
*
* \author Brett Durlock
*
* \brief An adapater for the Basket Library
*/

#pragma once
#include "Drawable.h"
#include "Basket.h"
#include <memory>

/**
* \brief An adapater for the Basket Library.
*/
class CBasketAdapter : public CDrawable
{
public:
	/// The constructor
	CBasketAdapter(const std::wstring &name);

	/// Virtual destructor
	virtual ~CBasketAdapter();

	/// Default constructor deleted
	CBasketAdapter() = delete;
	/** \brief Copy constructor disabled */
	CBasketAdapter(const CBasketAdapter &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CBasketAdapter &) = delete;

	/**
	* Sets the key frame
	* \param frame the frame you're setting
	*/
	void SetKeyFrame(int frame) { mInitialFrame = frame; }

	/**
	* Sets the position
	* \param x the x location
	* \param y the y location
	*/
	void SetPosition(int x, int y) {}

	/**
	* Draws the image
	* \param graphics the graphics that's provided
	*/
	virtual void Draw(Gdiplus::Graphics *graphics) override;

	/**
	* Sets the basket
	* \param basket the basket object you're connecting to
	*/
	void SetBasket(std::shared_ptr<CBasket> basket) { mBasket = basket; }

	/**
	* Sees if it was clicked on
	* \param pos the position of the mouse
	* \return bool of if it was clicked on. It's false always.
	*/
	bool HitTest(Gdiplus::Point pos) { return false; }

	/**
	* Adds fruit to the baskset
	* \param fruit the fruit you're adding
	*/
	void AddToBasket(std::vector<std::shared_ptr<CFruit>> fruit) { mBasket->AddToBasket(fruit); }

private:
	/// The initial draw frame
	int mInitialFrame;

	/// The basket object
	std::shared_ptr<CBasket> mBasket = nullptr;
};

