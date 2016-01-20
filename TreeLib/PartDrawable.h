/**
 * \file PartDrawable.h
 *
 * \author Brett Durlock
 *
 * 
 */

#pragma once

#include <memory>
#include <vector>
#include "PseudoRandom.h"

class CBaseTree;


/** The drawable for all parts of the tree, including limbs, fruit, and leafs.
 */
class CPartDrawable
{
public:
	/**
	* Constructor
	* \param tree the tree that this part belongs to
	*/
	CPartDrawable(CBaseTree *tree) : mTree(tree) {}

	/// destructor
	virtual ~CPartDrawable();

	/// default constructor deleted
	CPartDrawable() = delete;
	/** \brief Copy constructor disabled */
	CPartDrawable(const CPartDrawable &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CPartDrawable &) = delete;

	/**
	* Draws the object
	* \param graphics the graphics
	* \param angle the angle of rotation
	* \param x the x location
	* \param y the y location
	*/
	virtual void Draw(Gdiplus::Graphics *graphics, double angle, double x, double y) = 0;

	/**
	* Grows the end
	* \param grow the growth rate
	*/
	virtual void Grow(double grow) = 0;

	/**
	* Sets the tree this belongs to
	* \param tree the tree that you're setting
	*/
	void SetTree(CBaseTree *tree) { mTree = tree; }

	/**
	* Adds a child
	* \param child the child you're adding
	*/
	void AddChild(std::shared_ptr<CPartDrawable> child);

	/**
	* Sets the parent
	* \param parent the parent of this object
	*/
	void SetParent(CPartDrawable *parent) { mParent = parent; }

	/**
	* returns the children
	* \return the children
	*/
	std::vector<std::shared_ptr<CPartDrawable>> GetChildren() { return mChildren; }

	/**
	* Gets the x location of the part
	* \return the x location
	*/
	int GetX() { return mX; }

	/**
	* Gets the y location of the part
	* \return the y location
	*/
	int GetY() { return mY; }

	/**
	* Gets the parent of the part
	* \return parent
	*/
	CPartDrawable* GetParent() { return mParent; }

	/**
	* Gets the current frame
	* \return the frame
	*/
	int GetFrame() { return mFrame; }

	/**
	* Creates the next part
	*/
	void Create();

	/**
	* Sets the depth of the part
	* \param depth the depth of the part.
	*/
	void SetDepth(int depth) { mDepth = depth; }

	/**
	* Gets the depth of the part
	* \return the depth
	*/
	int GetDepth() { return mDepth; }

	/**
	* Sets the rotation of the part
	* \param rot the rotation value
	*/
	void SetRotation(double rot) { mRotation = rot; }

	/**
	* Gets the rotation of the part
	* \return the rotation value
	*/
	double GetRotation() { return mRotation; }

	/**
	* Sets the windspeed of the part
	* \param speed the speed that you're setting
	*/
	void SetWindSpeed(double speed) { mWindSpeed = speed; }

	/**
	* Gets the tree that this belonds to
	* \return the tree
	*/
	virtual CBaseTree* GetTree() { return mTree; }

	/**
	* Sets the x location of the part
	* \param x the x location
	*/
	void SetX(int x) { mX = x; }

	/**
	* Sets the y location of the part
	* \param y the y location
	*/
	void SetY(int y) { mY = y; }


private:

	int mX = 0;     ///< Tree X location
	int mY = 0;     ///< Tree Y location

	int mFrame = 0; ///< Current frame

	/// The rotation value
	double mRotation = 0;

	/// The windspeed of the tree
	double mWindSpeed = 0;

	int mDepth = 1;		///< The depth of the part

	/// Tree pointer
	CBaseTree *mTree = nullptr;

	CPartDrawable *mParent = nullptr;	///< The parent of the part
	std::vector<std::shared_ptr<CPartDrawable>> mChildren;	///< The parent of the part

	/// Random seed (not used)
	int mSeed = 0;

	/// The random number generator
	CPseudoRandom mRandom = CPseudoRandom(mSeed);
};

