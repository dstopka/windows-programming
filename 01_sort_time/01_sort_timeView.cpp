
// 01_sort_timeView.cpp : implementation of the CMy01_sort_timeView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "01_sort_time.h"
#endif

#include "01_sort_timeDoc.h"
#include "01_sort_timeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy01_sort_timeView

IMPLEMENT_DYNCREATE(CMy01_sort_timeView, CView)

BEGIN_MESSAGE_MAP(CMy01_sort_timeView, CView)
END_MESSAGE_MAP()

// CMy01_sort_timeView construction/destruction

CMy01_sort_timeView::CMy01_sort_timeView()
{
	// TODO: add construction code here

}

CMy01_sort_timeView::~CMy01_sort_timeView()
{
}

BOOL CMy01_sort_timeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMy01_sort_timeView drawing

void CMy01_sort_timeView::OnDraw(CDC* /*pDC*/)
{
	CMy01_sort_timeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CMy01_sort_timeView diagnostics

#ifdef _DEBUG
void CMy01_sort_timeView::AssertValid() const
{
	CView::AssertValid();
}

void CMy01_sort_timeView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy01_sort_timeDoc* CMy01_sort_timeView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy01_sort_timeDoc)));
	return (CMy01_sort_timeDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy01_sort_timeView message handlers
