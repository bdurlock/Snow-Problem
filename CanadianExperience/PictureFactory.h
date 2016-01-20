/**
 * \file PictureFactory.h
 *
 * \author Charles B. Owen
 *
 * \brief A factory class that builds our picture.
 */

#pragma once

#include <memory>

#include "Picture.h"
#include "TreeAdapter.h"
#include "BasketAdapter.h"

/**
 * \brief A factory class that builds our picture.
 */
class CPictureFactory
{
public:
    CPictureFactory();
    virtual ~CPictureFactory();

	/**
	* Creates the picture
	* \return the picture
	*/
    std::shared_ptr<CPicture> Create();

	/**
	* Creates the first tree
	* \return the first tree
	*/
	std::shared_ptr<CTreeAdapter> GetTreeImage1() { return mTreeImage1; }

	/**
	* Creates the second tree
	* \return the second tree
	*/
	std::shared_ptr<CTreeAdapter> GetTreeImage2() { return mTreeImage2; }

	/**
	* Creates the basket
	* \return the basket
	*/
	std::shared_ptr<CBasketAdapter> GetBasketImage() { return mBasketImage; }

private:
	/// The first ree
	std::shared_ptr<CTreeAdapter> mTreeImage1;

	/// The second tree
	std::shared_ptr<CTreeAdapter> mTreeImage2;

	/// The basket
	std::shared_ptr<CBasketAdapter> mBasketImage;


};

