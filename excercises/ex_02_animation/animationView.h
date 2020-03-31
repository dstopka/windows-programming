
// animationView.h : interface of the CanimationView class
//

#pragma once
#include <memory>

#define BALL_SIZE 10
#define BLUE COLORREF RGB(0, 0, 255)

class CanimationView : public CView
{
protected: // create from serialization only
	CanimationView();
	DECLARE_DYNCREATE(CanimationView)

// Attributes
public:
	CanimationDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CanimationView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnStartStop();

private:
	UINT_PTR timerID_;
	std::unique_ptr<CRect> ball_;
	std::unique_ptr<CPen> ballPen_;
	std::unique_ptr<CBrush> ballBrush_;
	int ballOffX_;
	int ballOffY_;
	
public:
	virtual void OnInitialUpdate();
	afx_msg void OnDestroy();
	afx_msg void OnTimer( UINT_PTR nIDEvent );
};

#ifndef _DEBUG  // debug version in animationView.cpp
inline CanimationDoc* CanimationView::GetDocument() const
   { return reinterpret_cast<CanimationDoc*>(m_pDocument); }
#endif

