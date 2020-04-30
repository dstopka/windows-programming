
// ComplexCalcView.h : interface of the CComplexCalcView class
//

#pragma once
#include "ComplexCalcDialog.h"

class CComplexCalcView : public CView
{
protected: // create from serialization only
	CComplexCalcView();
	DECLARE_DYNCREATE(CComplexCalcView)

// Attributes
public:
	CComplexCalcDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CComplexCalcView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnComplexCalc();
};

#ifndef _DEBUG  // debug version in ComplexCalcView.cpp
inline CComplexCalcDoc* CComplexCalcView::GetDocument() const
   { return reinterpret_cast<CComplexCalcDoc*>(m_pDocument); }
#endif

