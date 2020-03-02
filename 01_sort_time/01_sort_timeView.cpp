
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
	SortTimeView* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	GetClientRect( this->clientRect.get() );
	this->chart.getGrid()->calculateLines( this->clientRect );
	this->chart.getGrid()->paint( pDC );

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

SortTimeView* SortTimeView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS( SortTimeView)));
	return (SortTimeView*)m_pDocument;
}
#endif //_DEBUG


// SortTimeView message handlers


void SortTimeView::OnSortAll()
{
	// TODO: Add your command handler code here
}


void SortTimeView::OnSortSimple()
{
	// TODO: Add your command handler code here
}


void SortTimeView::OnSortEfficient()
{
	// TODO: Add your command handler code here
}


void SortTimeView::OnUpdateSortAll( CCmdUI *pCmdUI )
{
	// TODO: Add your command update UI handler code here
}


void SortTimeView::OnUpdateSortSimple( CCmdUI *pCmdUI )
{
	// TODO: Add your command update UI handler code here
}


void SortTimeView::OnUpdateSortEfficient( CCmdUI *pCmdUI )
{
	// TODO: Add your command update UI handler code here
}
