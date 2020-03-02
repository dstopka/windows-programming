
// 01_sort_timeView.h : interface of the CMy01_sort_timeView class
//

#pragma once


class CMy01_sort_timeView : public CView
{
protected: // create from serialization only
	CMy01_sort_timeView();
	DECLARE_DYNCREATE(CMy01_sort_timeView)

// Attributes
public:
	CMy01_sort_timeDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CMy01_sort_timeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in 01_sort_timeView.cpp
inline CMy01_sort_timeDoc* CMy01_sort_timeView::GetDocument() const
   { return reinterpret_cast<CMy01_sort_timeDoc*>(m_pDocument); }
#endif

