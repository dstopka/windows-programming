
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
	bool draw_;
	bool insert_;
	bool robson_;
	bool treeIsEmpty_;
	std::shared_ptr<CFont> fontObj_;
public:
	afx_msg void OnTreeMake();
	afx_msg void OnTreePrint();
	afx_msg void OnTreeAddNode();
	afx_msg void OnTreeRobson();
	afx_msg void OnTreeDraw();
	afx_msg void OnTreeClear();
	afx_msg void OnUpdateTreeMake( CCmdUI *pCmdUI );
	afx_msg void OnHScroll( UINT nSBCode, UINT nPos, CScrollBar* pScrollBar );
	afx_msg void OnVScroll( UINT nSBCode, UINT nPos, CScrollBar* pScrollBar );
};

#ifndef _DEBUG  // debug version in treesView.cpp
inline CMyTreesDoc* CMyTreesView::GetDocument() const
   { return reinterpret_cast<CMyTreesDoc*>(m_pDocument); }
#endif

