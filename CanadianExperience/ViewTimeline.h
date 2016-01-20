/**
 * \file ViewTimeline.h
 *
 * \author Charles B. Owen
 *
 * \brief View window for the animation timeline
 */

#pragma once

#include "PictureObserver.h"

class CMainFrame;

/** \brief View window for the animation timeline */
class CViewTimeline : public CScrollView, public CPictureObserver
{
	DECLARE_DYNCREATE(CViewTimeline)

public:
    static const int Height = 90;      ///< Height to make this window

    /** \brief Set the mainFrame pointer
    * \param mainFrame Pointer to the CMainFrame window */
    void SetMainFrame(CMainFrame *mainFrame) { mMainFrame = mainFrame; }

    virtual void UpdateObserver() override;

protected:
	CViewTimeline();           // protected constructor used by dynamic creation
	virtual ~CViewTimeline();


protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	virtual void OnInitialUpdate();     // first time after construct

	DECLARE_MESSAGE_MAP()

public:
    afx_msg BOOL OnEraseBkgnd(CDC* pDC);

private:
    /// The main frame window that uses this view
    CMainFrame  *mMainFrame;

    /// Bitmap image for the pointer
    std::unique_ptr<Gdiplus::Bitmap> mPointer;

    /// Flag to indicate we are moving the pointer
    bool      mMovingPointer = false;

	long long mLastTime;    ///< Last time we read the timer
	double mTimeFreq;       ///< Rate the timer updates

	bool mStop = true;		///< Stops the animation

	/// True until the first time we draw
	bool mFirstDraw = false;

public:
    afx_msg void OnMouseMove(UINT nFlags, CPoint point);
    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
    afx_msg void OnEditSetkeyframe();
    afx_msg void OnEditDeletekeyframe();
    afx_msg void OnFileSaveas();
    afx_msg void OnFileOpen32782();
	/**
	* Plays the animation
	*/
	afx_msg void OnPlayPlay();
	/**
	* Plays the animation from the beginning
	*/
	afx_msg void OnPlayPlayfrombeginning();
	/**
	* Stops the animation
	*/
	afx_msg void OnPlayStop();
	/**
	* it's the timer
	* \param nIDEvent I don't even know
	*/
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	/**
	* Harvests the tree
	*/
	afx_msg void OnTreeHarvest();
};

