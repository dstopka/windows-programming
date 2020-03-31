
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
	ON_COMMAND( ID_START_STOP, &CanimationView::OnStartStop )
	ON_WM_DESTROY()
	ON_WM_TIMER()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

// CanimationView construction/destruction

void CALLBACK ZfxTimerProc(HWND hWnd, UINT nMsg, UINT nIDEvent, DWORD dwTime)
{
	::SendMessage( hWnd, WM_TIMER, 0, 0 );
}


CanimationView::CanimationView()
{
	ball_ = std::make_unique<CRect>( 20, 20, 20 + BALL_SIZE, 20 + BALL_SIZE );
	ballPen_ = std::make_unique<CPen>( PS_SOLID, 1, BLUE );
	ballBrush_ = std::make_unique<CBrush>( BLUE );
	ballOffX_ = 3;
	ballOffY_ = 1;
	isStart_ = FALSE;
	clientRect_ = std::make_unique<CRect>( 0, 0, 0, 0 );
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

void CanimationView::OnDraw(CDC* pDC)
{
	CanimationDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	/*
	CPen* oldPen = pDC->SelectObject( ballPen_.get() );
	CBrush* oldBrush = pDC->SelectObject( ballBrush_.get() );

	pDC->Ellipse( ball_.get() );
	pDC->SelectObject( oldPen );
	pDC->SelectObject( oldBrush );
	*/

	CDC memDC;
	bool b = memDC.CreateCompatibleDC( pDC );
	ASSERT( b );
	CBitmap bmp;
	b = bmp.CreateCompatibleBitmap( pDC, clientRect_->Width(), clientRect_->Height() );
	ASSERT( b );
	auto oldBitmap = memDC.SelectObject( &bmp );
	memDC.FillSolidRect( clientRect_.get(), RGB( 230, 230, 230 ) );

	CPen* oldPen = memDC.SelectObject( ballPen_.get() );
	CBrush* oldBrush = memDC.SelectObject( ballBrush_.get() );

	b = pDC->BitBlt( 0, 0, clientRect_->Width(), clientRect_->Height(), &memDC, 0, 0, SRCCOPY );
	ASSERT( b );

	memDC.SelectObject( oldBitmap );
	bmp.DeleteObject();
	memDC.DeleteDC();
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


void CanimationView::OnStartStop()
{
	isStart_ = !isStart_;
}


void CanimationView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	timerID_ = SetTimer( WM_USER + 1, 20, ZfxTimerProc );
}


void CanimationView::OnDestroy()
{
	KillTimer( timerID_ );
	CView::OnDestroy();
}


void CanimationView::OnTimer( UINT_PTR nIDEvent )
{
	if ( isStart_ )
	{
		ball_->OffsetRect( ballOffX_, ballOffY_ );
		Invalidate();
	}
	CView::OnTimer( nIDEvent );
}



BOOL CanimationView::OnEraseBkgnd( CDC* pDC )
{
	return 1;
	//return CView::OnEraseBkgnd( pDC );
}


void CanimationView::OnPrepareDC( CDC* pDC, CPrintInfo* pInfo )
{
	GetClientRect( clientRect_.get() );
	CView::OnPrepareDC( pDC, pInfo );
}
