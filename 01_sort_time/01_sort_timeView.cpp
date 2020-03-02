
// 01_sort_timeView.cpp : implementation of the SortTimeView class
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


// SortTimeView

IMPLEMENT_DYNCREATE( SortTimeView, CView)

BEGIN_MESSAGE_MAP( SortTimeView, CView)
	ON_COMMAND( ID_SORT_ALL, &SortTimeView::OnSortAll )
	ON_COMMAND( ID_SORT_SIMPLE, &SortTimeView::OnSortSimple )
	ON_COMMAND( ID_SORT_EFFICIENT, &SortTimeView::OnSortEfficient )
	ON_UPDATE_COMMAND_UI( ID_SORT_ALL, &SortTimeView::OnUpdateSortAll )
	ON_UPDATE_COMMAND_UI( ID_SORT_SIMPLE, &SortTimeView::OnUpdateSortSimple )
	ON_UPDATE_COMMAND_UI( ID_SORT_EFFICIENT, &SortTimeView::OnUpdateSortEfficient )
END_MESSAGE_MAP()

// SortTimeView construction/destruction

SortTimeView::SortTimeView()
{
	// TODO: add construction code here
	//this->chart = Chart();
	this->clientRect = std::make_shared<CRect>();
	this->crectan = CRect( 100, 100, 200, 200 );
	this->allSorts = false;
	this->simpleSorts = false;
	this->efficientSorts = false;
}

SortTimeView::~SortTimeView()
{
}

BOOL SortTimeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// SortTimeView drawing

void SortTimeView::OnDraw(CDC* pDC)
{
	CMy01_sort_timeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	GetClientRect( this->clientRect.get() );
	this->chart.getGrid().calculateLines( this->clientRect );
	this->chart.getGrid().paint( pDC );
	this->crectan.paint(pDC);

	// TODO: add draw code for native data here
}


// SortTimeView diagnostics

#ifdef _DEBUG
void SortTimeView::AssertValid() const
{
	CView::AssertValid();
}

void SortTimeView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy01_sort_timeDoc* SortTimeView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS( CMy01_sort_timeDoc )));
	return (CMy01_sort_timeDoc*)m_pDocument;
}
#endif //_DEBUG


// SortTimeView message handlers


void SortTimeView::OnSortAll()
{
	this->chart.getRects().clear();
	this->allSorts = true;
	this->simpleSorts = false;
	this->efficientSorts = false;
	Invalidate();
	UpdateWindow();
}


void SortTimeView::OnSortSimple()
{
	this->chart.getRects().clear();
	this->allSorts = false;
	this->simpleSorts = true;
	this->efficientSorts = false;
	Invalidate();
	UpdateWindow();
}


void SortTimeView::OnSortEfficient()
{
	this->chart.getRects().clear();
	this->allSorts = false;
	this->simpleSorts = false;
	this->efficientSorts = true;
	Invalidate();
	UpdateWindow();
}


void SortTimeView::OnUpdateSortAll( CCmdUI *pCmdUI )
{
	pCmdUI->Enable( !allSorts );
}


void SortTimeView::OnUpdateSortSimple( CCmdUI *pCmdUI )
{
	pCmdUI->Enable( !simpleSorts );
}


void SortTimeView::OnUpdateSortEfficient( CCmdUI *pCmdUI )
{
	pCmdUI->Enable( !efficientSorts );
}
