
// BallsAnimation.cpp : implementation of the CMyBallsAnimationView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "02_balls_animation.h"
#endif

#include "BallsAnimationDoc.h"
#include "BallsAnimationView.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMyBallsAnimationView

IMPLEMENT_DYNCREATE(CMyBallsAnimationView, CView)

BEGIN_MESSAGE_MAP(CMyBallsAnimationView, CView)
	ON_COMMAND( ID_BALL_ADD, &CMyBallsAnimationView::OnBallAdd )
	ON_COMMAND( ID_BALL_DELETE, &CMyBallsAnimationView::OnBallDelete )
	ON_COMMAND( ID_ANIMATION_START, &CMyBallsAnimationView::OnAnimationStart )
	ON_COMMAND( ID_ANIMATION_STOP, &CMyBallsAnimationView::OnAnimationStop )
	ON_COMMAND( ID_START_STOP, &CMyBallsAnimationView::OnStartStop )
	ON_UPDATE_COMMAND_UI( ID_ANIMATION_START, &CMyBallsAnimationView::OnUpdateAnimationStart )
	ON_UPDATE_COMMAND_UI( ID_ANIMATION_STOP, &CMyBallsAnimationView::OnUpdateAnimationStop )
	ON_WM_DESTROY()
	ON_WM_TIMER()
	ON_WM_ERASEBKGND()
	ON_WM_SIZE()
END_MESSAGE_MAP()

// CMyBallsAnimationView construction/destruction

CMyBallsAnimationView::CMyBallsAnimationView()
{
	isAnimation_ = false;
}

CMyBallsAnimationView::~CMyBallsAnimationView()
{
}

BOOL CMyBallsAnimationView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMyBallsAnimationView drawing

void CMyBallsAnimationView::OnDraw(CDC* pDC)
{
	document_ = GetDocument();
	ASSERT_VALID( document_ );
	if (!document_ )
		return;

	document_->getBallsField().paint( pDC );
}


// CMyBallsAnimationView diagnostics

#ifdef _DEBUG
void CMyBallsAnimationView::AssertValid() const
{
	CView::AssertValid();
}

void CMyBallsAnimationView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMyBallsAnimationDoc* CMyBallsAnimationView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyBallsAnimationDoc)));
	return static_cast<CMyBallsAnimationDoc*>(m_pDocument);
}
#endif //_DEBUG


// CMyBallsAnimationView message handlers


void CMyBallsAnimationView::OnBallAdd()
{
	document_->getBallsField().addBall();
}


void CMyBallsAnimationView::OnBallDelete()
{
	document_->getBallsField().deleteBall();
}


void CMyBallsAnimationView::OnAnimationStart()
{
	isAnimation_ = true;
	auto frame = static_cast<CMainFrame*>(GetParentFrame());
	frame->resetButton( isAnimation_ );
}


void CMyBallsAnimationView::OnAnimationStop()
{
	isAnimation_ = false;
	auto frame = static_cast<CMainFrame*>(GetParentFrame());
	frame->resetButton( isAnimation_ );
}


void CMyBallsAnimationView::OnUpdateAnimationStart( CCmdUI *pCmdUI )
{
	pCmdUI->Enable( !isAnimation_ );
}


void CMyBallsAnimationView::OnUpdateAnimationStop( CCmdUI *pCmdUI )
{
	pCmdUI->Enable( isAnimation_ );
}


void CMyBallsAnimationView::OnStartStop()
{
	isAnimation_ = !isAnimation_;
	auto frame = static_cast<CMainFrame*>(GetParentFrame());
	frame->resetButton( isAnimation_ );
}


void CMyBallsAnimationView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO: Add your specialized code here and/or call the base class
}


void CMyBallsAnimationView::OnDestroy()
{
	CView::OnDestroy();

	// TODO: Add your message handler code here
}


void CMyBallsAnimationView::OnTimer( UINT_PTR nIDEvent )
{
	// TODO: Add your message handler code here and/or call default

	CView::OnTimer( nIDEvent );
}


BOOL CMyBallsAnimationView::OnEraseBkgnd( CDC* pDC )
{
	// TODO: Add your message handler code here and/or call default

	return CView::OnEraseBkgnd( pDC );
}


void CMyBallsAnimationView::OnPrepareDC( CDC* pDC, CPrintInfo* pInfo )
{
	// TODO: Add your specialized code here and/or call the base class

	CView::OnPrepareDC( pDC, pInfo );
}


void CMyBallsAnimationView::OnSize( UINT nType, int cx, int cy )
{
	CView::OnSize( nType, cx, cy );

	// TODO: Add your message handler code here
}
