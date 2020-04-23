
// flowerShopView.h : interface of the CFlowerShopView class
//

#pragma once

#include "FlowerShop.h"

class CFlowerShopView : public CView
{
protected: // create from serialization only
	CFlowerShopView();
	DECLARE_DYNCREATE(CFlowerShopView)

// Attributes
public:
	CFlowerShopDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CFlowerShopView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFlowerShop();
	afx_msg void OnUpdateFlowerShop( CCmdUI *pCmdUI );
};

#ifndef _DEBUG  // debug version in flowerShopView.cpp
inline CFlowerShopDoc* CFlowerShopView::GetDocument() const
   { return reinterpret_cast<CFlowerShopDoc*>(m_pDocument); }
#endif

