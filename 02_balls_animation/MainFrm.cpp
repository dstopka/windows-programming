
// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "02_balls_animation.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

std::vector<UINT> CMainFrame::buttonsIDs_ =
{
	ID_BALL_ADD,
	ID_BALL_DELETE,
	ID_START_STOP
};

// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if ( !m_wndToolBar.Create( this ) ||
		!m_wndToolBar.LoadBitmap( IDR_MAINFRAME ) ||
		!m_wndToolBar.SetButtons( &buttonsIDs_[0], buttonsIDs_.size() ) )
	{
		TRACE0( "Failed to create status bar\n" );
		return -1;      // fail to create
	}

	CToolBarCtrl& BarCtrl = m_wndToolBar.GetToolBarCtrl();
	BarCtrl.SetBitmapSize( CSize( 30, 30 ) );
	BarCtrl.SetButtonSize( CSize( 38, 37 ) );

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO: Delete these three lines if you don't want the toolbar to be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);


	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

void CMainFrame::resetButton( bool button )
{
	const int buttonIx = buttonsIDs_.size();
	if ( button )
		m_wndToolBar.SetButtonInfo( 2, ID_START_STOP, TBBS_BUTTON, buttonIx );
	else
		m_wndToolBar.SetButtonInfo( 2, ID_START_STOP, TBBS_BUTTON, 2 );

	m_wndToolBar.Invalidate();
}

// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame message handlers

