
// dialogView.h : interface of the CDialogView class
//

#pragma once
#include "TestDlg.h"

class CDialogView : public CView
{
protected: // create from serialization only
	CDialogView();
	DECLARE_DYNCREATE(CDialogView)

// Attributes
public:
	CDialogDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CDialogView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDlgTest();
	afx_msg void OnUpdateDlgTest( CCmdUI *pCmdUI );
};

#ifndef _DEBUG  // debug version in dialogView.cpp
inline CDialogDoc* CDialogView::GetDocument() const
   { return reinterpret_cast<CDialogDoc*>(m_pDocument); }
#endif

