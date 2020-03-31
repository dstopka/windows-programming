
// animationView.cpp : implementation of the CanimationView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "ex_02_animation.h"
#endif

#include "animationDoc.h"
#include "animationView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CanimationView

IMPLEMENT_DYNCREATE(CanimationView, CView)

BEGIN_MESSAGE_MAP(CanimationView, CView)
END_MESSAGE_MAP()

// CanimationView construction/destruction

CanimationView::CanimationView()
{
	// TODO: add construction code here

}

CanimationView::~CanimationView()
{
}

BOOL CanimationView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CanimationView drawing

void CanimationView::OnDraw(CDC* /*pDC*/)
{
	CanimationDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CanimationView diagnostics

#ifdef _DEBUG
void CanimationView::AssertValid() const
{
	CView::AssertValid();
}

void CanimationView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CanimationDoc* CanimationView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CanimationDoc)));
	return (CanimationDoc*)m_pDocument;
}
#endif //_DEBUG


// CanimationView message handlers
