
// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "03_trees.h"

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


std::vector<UINT>CMainFrame::m_buttonsIDs =
{
	ID_TREE_MAKE,
	ID_TREE_CLEAR,
	ID_TREE_DRAW,
	ID_TREE_PRINTINORDER
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
/*
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}
	*/
	if ( !m_wndToolBar.Create( this ) ||
		!m_wndToolBar.LoadBitmap( IDR_MAINFRAME ) ||
		!m_wndToolBar.SetButtons( &m_buttonsIDs[0], m_buttonsIDs.size() ) )
	{
		TRACE0( "Failed to create status bar\n" );
		return -1;      // fail to create
	}

	CToolBarCtrl& BarCtrl = m_wndToolBar.GetToolBarCtrl();
	BarCtrl.SetBitmapSize( CSize( 25, 25 ) );
	BarCtrl.SetButtonSize( CSize( 33, 32 ) );


	if ( !m_wndStatusBar.Create( this ) )
	{
		TRACE0( "Failed to create status bar\n" );
		return -1;      // fail to create
	}
	m_wndStatusBar.SetIndicators( indicators, sizeof( indicators ) / sizeof( UINT ) );

	// TODO: Delete these three lines if you don't want the toolbar to be dockable
	m_wndToolBar.EnableDocking( CBRS_ALIGN_ANY );
	EnableDocking( CBRS_ALIGN_ANY );
	DockControlBar( &m_wndToolBar );


	return 0;
}

void CMainFrame::resetButton( bool state, int idx )
{
	const int buttonIx = m_buttonsIDs.size() + idx;
	UINT button = m_buttonsIDs[idx + 2];
	if ( state )
		m_wndToolBar.SetButtonInfo( idx + 2, button, TBBS_BUTTON, buttonIx );
	else
		m_wndToolBar.SetButtonInfo( idx + 2, button, TBBS_BUTTON, idx + 2 );

	m_wndToolBar.Invalidate();
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
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

