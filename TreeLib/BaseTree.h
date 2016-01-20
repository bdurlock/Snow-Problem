/**
 * \file BaseTree.h
 *
 * \author Brett Durlock
 *
 * 
 */

/**
 * \file BaseTree.h
 *
 * \author Brett Durlock
 *
 * Class that allows us to change the Tree class
 */

#pragma once
#include "PartDrawable.h"
#include "Tree.h"
#include "PseudoRandom.h"
#include "LeafDrawable.h"

class CFruit;
class CLeafDrawable;
class CPartDrawable;
class CLimbDrawable;

/**
 * 	Class that creates the tree
 */
class CBaseTree : public CTree
{
public:
	CBaseTree();
	virtual ~CBaseTree();

	/** \brief Copy constructor disabled */
	CBaseTree(const CBaseTree &) = delete;

	/** \brief Assignment operator disabled */
	void operator=(const CBaseTree &) = delete;

	/**
	* Set the position for the root of the tree
	* \param x X location (pixels)
	* \param y Y location (pixels)
	*/
	virtual void SetRootLocation(int x, int y) override;

	/**
	* Draw the tree at the currently specified location
	* \param graphics GDI+ Graphics object
	*/
	virtual void DrawTree(Gdiplus::Graphics *graphics) override;

	/**
	* Set the current tree frame
	* \param frame Frame number
	*/
	virtual void SetTreeFrame(int frame) override;

	/**
	* Set  the wind speed
	* \param speed Wind speed in miles per hour
	*/
	virtual void SetWindSpeed(double speed) override;

	/**
	* Set the tree seed
	* \param seed An integer number. Each number makes a different tree
	*/
	virtual void SetSeed(int seed) override { mSeed = seed; mRandom = CPseudoRandom(mSeed); }

	/**
	* Get the current tree seed
	* \return Tree seed integer
	*/
	virtual int GetSeed() override { return mSeed; }

	/**
	* Harvest all of the fruit
	* \return Vector of objects of type CFruit
	*/
	virtual std::vector<std::shared_ptr<CFruit>> Harvest() override;

	/**
	* Adds the drawable to the image
	* \param drawable the drawable that you're adding
	*/
	void AddDrawable(std::shared_ptr<CPartDrawable> drawable);

	/**
	* Returns the wind speed
	* \return the windspeed double
	*/
	double GetWindSpeed() { return mWindSpeed; }

	/**
	* Sets the root of the tree
	* \param drawable the tree that you're setting as the root
	*/
	void SetRoot(std::shared_ptr<CPartDrawable> drawable);

	/**
	* Resets the tree, if the time goes backwards
	*/
	void Reset();

	/**
	* Gets the randomly generated number
	* \return the random number
	*/
	CPseudoRandom *GetRandom() { return &mRandom; }

	/**
	* Adds fruit to the tree
	* \param fruit the collection of fruit that you're adding
	*/
	void AddFruit(std::shared_ptr<CFruit> fruit) { mFruit.push_back(fruit); }

	/**
	* Gets all leafs of the tree
	* \return the leafs
	*/
	std::shared_ptr<CLeafDrawable> GetLeaf() { return mLeaf; }

	/**
	* returns the leaf image, so it's only loaded once
	* \return the image
	*/
	Gdiplus::Bitmap *GetLeafImage() { return mLeafImage; }


	/**
	* Adds the fruit image, so it's only loaded once
	* \return the iamge
	*/
	Gdiplus::Bitmap *GetFruitImage() { return mFruitImage; }

	/**
	* returns if it's harvested already or not
	* \return the bool
	*/
	bool GetHarvested() { return mHarvested; }


private:

	/// The image file for the leaf
	const std::wstring &leaffile = L"images/leaf.png";

	/// The image for the leaf drawable
	Gdiplus::Bitmap *mLeafImage = (Bitmap::FromFile(leaffile.c_str()));

	/// The image file for the fruit
	const std::wstring &fruitfile = L"images/fruit.png";

	/// The image for the fruit drawable
	Gdiplus::Bitmap *mFruitImage = (Bitmap::FromFile(fruitfile.c_str()));

	/// The root of our tree
	std::shared_ptr<CPartDrawable> mRoot;

	/// The beginning frame
	int mFrame;

	/// The current frame
	int mCurrentFrame = 0;

	/// Frame Rate
	int mFrameRate = 30;

	double mWindSpeed = 0;  ///< Wind speed

	int mSeed = 69;  ///< Tree seed

	bool mHarvested = false;    ///< Has it been harvested?

	/// x position
	double mX = 493;

	/// y position
	double mY = 551;

	/// a leaf
	std::shared_ptr<CLeafDrawable> mLeaf;

	/// all fruit on the tree
	std::vector<std::shared_ptr<CFruit>> mFruit;

	/// Temporary collection of fruit for transfer
	std::vector<std::shared_ptr<CFruit>> mTempFruit;

	/// Random number
	CPseudoRandom mRandom = CPseudoRandom(mSeed);
};

