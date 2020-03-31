
// 01_toolbarView.h : interface of the Cex_01_toolbarView class
//

#pragma once


class Cex_01_toolbarView : public CView
{
protected: // create from serialization only
	Cex_01_toolbarView();
	DECLARE_DYNCREATE(Cex_01_toolbarView)

// Attributes
public:
	Cex_01_toolbarDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~Cex_01_toolbarView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in 01_toolbarView.cpp
inline Cex_01_toolbarDoc* Cex_01_toolbarView::GetDocument() const
   { return reinterpret_cast<Cex_01_toolbarDoc*>(m_pDocument); }
#endif

