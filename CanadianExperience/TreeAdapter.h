/**
* \file TreeAdapter.h
*
* \author Brett Durlock
*
* \brief An adapater for the Tree Library
*/

#pragma once
#include "Drawable.h"
#include "Tree.h"

/**
* \brief An adapater for the Tree Library.
*/
class CTreeAdapter : public CDrawable
{
public:
	/**
	* constructor
	* \param name the name of the tree that you're creating
	*/
	CTreeAdapter(const std::wstring &name);

	/// Virtual destructor
	virtual ~CTreeAdapter();

	/** \brief Default constructor disabled */
	CTreeAdapter() = delete;
	/** \brief Copy constructor disabled */
	CTreeAdapter(const CTreeAdapter &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CTreeAdapter &) = delete;

	/**
	* Sets the key frame of the tree
	* \param frame the frame that you're setting
	*/
	virtual void SetKeyFrame(int frame);

	/**
	* Sets the position of the tree
	* \param x the x location
	* \param y the y location
	*/
	void SetPosition(int x, int y);

	/**
	* calls the tree lib draw function
	* \param graphics the gdiplus graphics
	*/
	virtual void Draw(Gdiplus::Graphics *graphics) override;

	/**
	* Sets the tree that we're working on
	* \param tree the tree
	*/
	void SetTree(std::shared_ptr<CTree> tree) { mTree = tree; }

	/**
	* tests for mouse clicks
	* \param pos the position of the mouse
	* \return false always
	*/
	bool HitTest(Gdiplus::Point pos) { return false; }

	/**
	* Sets the timeline that we're working on
	* \param timeline the timeline that we're setting
	*/
	void SetTimeline(CTimeline *timeline) { mTimeline = timeline; CDrawable::SetTimeline(timeline); }

	/**
	* Sets the seed for our random number
	* \param seed the seed for our random number
	*/
	void SetSeed(int seed) { mTree->SetSeed(seed); mSeed = seed; }

	/**
	* Gets the seed for the random number
	* \return the seed
	*/
	int GetSeed() { return mSeed; }

	/**
	* Calls the tree harvest function
	* \return the fruit that is harvested
	*/
	std::vector<std::shared_ptr<CFruit>> Harvest() { return mTree->Harvest(); }

	/**
	* Shows the dialogue box, for setting the seeds
	*/
	void ShowDialogBox();



private:
	/// The x location
	double mX = 0;

	/// The y location
	double mY = 0;

	/// The intial frame for the tree
	int mInitialFrame = 0;

	/// The timeline that we're working on 
	CTimeline *mTimeline = nullptr;

	/// The tree that we're working on
	std::shared_ptr<CTree> mTree = nullptr;

	/// The seed for the random numbers
	int mSeed;
};