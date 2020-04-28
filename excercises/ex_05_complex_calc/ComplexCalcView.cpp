
// ComplexCalcView.cpp : implementation of the CComplexCalcView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "ex_05_complex_calc.h"
#endif

#include "ComplexCalcDoc.h"
#include "ComplexCalcView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CComplexCalcView

IMPLEMENT_DYNCREATE(CComplexCalcView, CView)

BEGIN_MESSAGE_MAP(CComplexCalcView, CView)
END_MESSAGE_MAP()

// CComplexCalcView construction/destruction

CComplexCalcView::CComplexCalcView()
{
	// TODO: add construction code here

}

CComplexCalcView::~CComplexCalcView()
{
}

BOOL CComplexCalcView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CComplexCalcView drawing

void CComplexCalcView::OnDraw(CDC* /*pDC*/)
{
	CComplexCalcDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CComplexCalcView diagnostics

#ifdef _DEBUG
void CComplexCalcView::AssertValid() const
{
	CView::AssertValid();
}

void CComplexCalcView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CComplexCalcDoc* CComplexCalcView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CComplexCalcDoc)));
	return (CComplexCalcDoc*)m_pDocument;
}
#endif //_DEBUG


// CComplexCalcView message handlers
