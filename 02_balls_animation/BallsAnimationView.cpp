
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
	ON_UPDATE_COMMAND_UI( ID_ANIMATION_START, &CMyBallsAnimationView::OnUpdateAnimationStart )
	ON_UPDATE_COMMAND_UI( ID_ANIMATION_STOP, &CMyBallsAnimationView::OnUpdateAnimationStop )
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

void CMyBallsAnimationView::OnDraw(CDC* /*pDC*/)
{
	CMyBallsAnimationDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
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
	return (CMyBallsAnimationDoc*)m_pDocument;
}
#endif //_DEBUG


// CMyBallsAnimationView message handlers


void CMyBallsAnimationView::OnBallAdd()
{
	// TODO: add ball
}


void CMyBallsAnimationView::OnBallDelete()
{
	// TODO: delete ball
}


void CMyBallsAnimationView::OnAnimationStart()
{
	isAnimation_ = true;
}


void CMyBallsAnimationView::OnAnimationStop()
{
	isAnimation_ = false;
}


void CMyBallsAnimationView::OnUpdateAnimationStart( CCmdUI *pCmdUI )
{
	pCmdUI->Enable( !isAnimation_ );
}


void CMyBallsAnimationView::OnUpdateAnimationStop( CCmdUI *pCmdUI )
{
	pCmdUI->Enable( isAnimation_ );
}
