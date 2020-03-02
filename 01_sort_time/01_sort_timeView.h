
// 01_sort_timeView.h : interface of the SortTimeView class
//

#pragma once
#include "Chart.h"

class SortTimeView : public CView
{
protected: // create from serialization only
	SortTimeView();
	DECLARE_DYNCREATE( SortTimeView)

// Attributes
public:
	CMy01_sort_timeDoc* GetDocument() const;
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual ~SortTimeView();

	afx_msg void OnSortAll();
	afx_msg void OnSortSimple();
	afx_msg void OnSortEfficient();
	afx_msg void OnUpdateSortAll( CCmdUI *pCmdUI );
	afx_msg void OnUpdateSortSimple( CCmdUI *pCmdUI );
	afx_msg void OnUpdateSortEfficient( CCmdUI *pCmdUI );
	
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

private:
	Chart chart;
	ColorRect crectan;
	std::shared_ptr<CRect> clientRect;
	bool allSorts;
	bool efficientSorts;
	bool simpleSorts;
};

#ifndef _DEBUG  // debug version in 01_sort_timeView.cpp
inline CMy01_sort_timeDoc* SortTimeView::GetDocument() const
   { return reinterpret_cast<CMy01_sort_timeDoc*>(m_pDocument); }
#endif

