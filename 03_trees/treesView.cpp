
// treesView.cpp : implementation of the CMyTreesView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "03_trees.h"
#endif

#include "treesDoc.h"
#include "treesView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMyTreesView

IMPLEMENT_DYNCREATE(CMyTreesView, CView)

BEGIN_MESSAGE_MAP(CMyTreesView, CView)
END_MESSAGE_MAP()

// CMyTreesView construction/destruction

CMyTreesView::CMyTreesView()
{
	// TODO: add construction code here

}

CMyTreesView::~CMyTreesView()
{
}

BOOL CMyTreesView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMyTreesView drawing

void CMyTreesView::OnDraw(CDC* /*pDC*/)
{
	CMyTreesDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CMyTreesView diagnostics

#ifdef _DEBUG
void CMyTreesView::AssertValid() const
{
	CView::AssertValid();
}

void CMyTreesView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMyTreesDoc* CMyTreesView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyTreesDoc)));
	return (CMyTreesDoc*)m_pDocument;
}
#endif //_DEBUG


// CMyTreesView message handlers
