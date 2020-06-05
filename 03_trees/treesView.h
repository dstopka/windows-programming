
// treesView.h : interface of the CMyTreesView class
//

#pragma once
#include <memory>


class CMyTreesView : public CView
{
protected: // create from serialization only
	CMyTreesView();
	DECLARE_DYNCREATE(CMyTreesView)

// Attributes
public:
	CMyTreesDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CMyTreesView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

private:
	std::shared_ptr<CRect> clientRect_;
	CMyTreesDoc* document_;
	bool print_;
public:
	afx_msg void OnTreeMake();
	afx_msg void OnTreePrint();
	afx_msg void OnTreeAddNode();
	afx_msg void OnTreeRobson();
};

#ifndef _DEBUG  // debug version in treesView.cpp
inline CMyTreesDoc* CMyTreesView::GetDocument() const
   { return reinterpret_cast<CMyTreesDoc*>(m_pDocument); }
#endif

