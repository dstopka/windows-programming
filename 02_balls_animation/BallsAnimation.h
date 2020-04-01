
// BallsAnimation.h : interface of the CMyBallsAnimationView class
//

#pragma once


class CMyBallsAnimationView : public CView
{
protected: // create from serialization only
	CMyBallsAnimationView();
	DECLARE_DYNCREATE(CMyBallsAnimationView)

// Attributes
public:
	CMyBallsAnimationDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CMyBallsAnimationView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in BallsAnimation.cpp
inline CMyBallsAnimationDoc* CMyBallsAnimationView::GetDocument() const
   { return reinterpret_cast<CMyBallsAnimationDoc*>(m_pDocument); }
#endif

