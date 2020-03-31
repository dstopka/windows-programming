
// animationView.h : interface of the CanimationView class
//

#pragma once


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
};

#ifndef _DEBUG  // debug version in animationView.cpp
inline CanimationDoc* CanimationView::GetDocument() const
   { return reinterpret_cast<CanimationDoc*>(m_pDocument); }
#endif

