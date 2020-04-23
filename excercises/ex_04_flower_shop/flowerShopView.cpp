
// flowerShopView.cpp : implementation of the CFlowerShopView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "ex_04_flower_shop.h"
#endif

#include "FlowerShopDoc.h"
#include "flowerShopView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFlowerShopView

IMPLEMENT_DYNCREATE(CFlowerShopView, CView)

BEGIN_MESSAGE_MAP(CFlowerShopView, CView)
END_MESSAGE_MAP()

// CFlowerShopView construction/destruction

CFlowerShopView::CFlowerShopView()
{
	// TODO: add construction code here

}

CFlowerShopView::~CFlowerShopView()
{
}

BOOL CFlowerShopView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CFlowerShopView drawing

void CFlowerShopView::OnDraw(CDC* /*pDC*/)
{
	CFlowerShopDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CFlowerShopView diagnostics

#ifdef _DEBUG
void CFlowerShopView::AssertValid() const
{
	CView::AssertValid();
}

void CFlowerShopView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFlowerShopDoc* CFlowerShopView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFlowerShopDoc)));
	return (CFlowerShopDoc*)m_pDocument;
}
#endif //_DEBUG


// CFlowerShopView message handlers
