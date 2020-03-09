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

IMPLEMENT_DYNCREATE(SortTimeView, CView)

BEGIN_MESSAGE_MAP(SortTimeView, CView)
		ON_COMMAND(ID_SORT_ALL, &SortTimeView::OnSortAll)
		ON_COMMAND(ID_SORT_SIMPLE, &SortTimeView::OnSortSimple)
		ON_COMMAND(ID_SORT_EFFICIENT, &SortTimeView::OnSortEfficient)
		ON_UPDATE_COMMAND_UI(ID_SORT_ALL, &SortTimeView::OnUpdateSortAll)
		ON_UPDATE_COMMAND_UI(ID_SORT_SIMPLE, &SortTimeView::OnUpdateSortSimple)
		ON_UPDATE_COMMAND_UI(ID_SORT_EFFICIENT, &SortTimeView::OnUpdateSortEfficient)
END_MESSAGE_MAP()

// SortTimeView construction/destruction

SortTimeView::SortTimeView()
{
	this->clientRect_ = std::make_shared<CRect>();
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
	document_ = GetDocument();
	ASSERT_VALID(document_);
	if (!document_)
		return;
	GetClientRect(this->clientRect_.get());

	if (this->allSorts || this->simpleSorts | this->efficientSorts)
		document_->getChart().paint(this->clientRect_, pDC);

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
	return static_cast<CMy01_sort_timeDoc*>(m_pDocument);
}
#endif //_DEBUG


// SortTimeView message handlers


void SortTimeView::OnSortAll()
{
	allSorts = true;
	simpleSorts = false;
	efficientSorts = false;
	document_->getChart().setSortsType(ALL);
	Invalidate();
	UpdateWindow();
}


void SortTimeView::OnSortSimple()
{
	allSorts = false;
	simpleSorts = true;
	efficientSorts = false;
	document_->getChart().setSortsType(SIMPLE);
	Invalidate();
	UpdateWindow();
}


void SortTimeView::OnSortEfficient()
{
	allSorts = false;
	simpleSorts = false;
	efficientSorts = true;
	document_->getChart().setSortsType(EFFICIENT);
	Invalidate();
	UpdateWindow();
}


void SortTimeView::OnUpdateSortAll(CCmdUI* pCmdUI)
{
	pCmdUI->Enable(!allSorts);
}


void SortTimeView::OnUpdateSortSimple(CCmdUI* pCmdUI)
{
	pCmdUI->Enable(!simpleSorts);
}


void SortTimeView::OnUpdateSortEfficient(CCmdUI* pCmdUI)
{
	pCmdUI->Enable(!efficientSorts);
}
