
// 01_toolbarView.cpp : implementation of the Cex_01_toolbarView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "ex_01_toolbar.h"
#endif

#include "ex_01_toolbarDoc.h"
#include "01_toolbarView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cex_01_toolbarView

IMPLEMENT_DYNCREATE(Cex_01_toolbarView, CView)

BEGIN_MESSAGE_MAP(Cex_01_toolbarView, CView)
END_MESSAGE_MAP()

// Cex_01_toolbarView construction/destruction

Cex_01_toolbarView::Cex_01_toolbarView()
{
	// TODO: add construction code here

}

Cex_01_toolbarView::~Cex_01_toolbarView()
{
}

BOOL Cex_01_toolbarView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Cex_01_toolbarView drawing

void Cex_01_toolbarView::OnDraw(CDC* /*pDC*/)
{
	Cex_01_toolbarDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// Cex_01_toolbarView diagnostics

#ifdef _DEBUG
void Cex_01_toolbarView::AssertValid() const
{
	CView::AssertValid();
}

void Cex_01_toolbarView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cex_01_toolbarDoc* Cex_01_toolbarView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cex_01_toolbarDoc)));
	return (Cex_01_toolbarDoc*)m_pDocument;
}
#endif //_DEBUG


// Cex_01_toolbarView message handlers
