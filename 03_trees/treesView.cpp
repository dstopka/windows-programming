
// treesView.cpp : implementation of the CMyTreesView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "03_trees.h"
#endif

#include "treesDoc.h"
#include "treesView.h"

#include "MainFrm.h"
#include "ThreadedBinaryTree.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMyTreesView

IMPLEMENT_DYNCREATE( CMyTreesView, CView )

BEGIN_MESSAGE_MAP( CMyTreesView, CView )
	ON_COMMAND( ID_TREE_MAKE, &CMyTreesView::OnTreeMake )
	ON_COMMAND( ID_TREE_PRINTINORDER, &CMyTreesView::OnTreePrint )
	ON_COMMAND( ID_TREE_ADDNODE, &CMyTreesView::OnTreeAddNode )
	ON_COMMAND( ID_TREE_ROBSON, &CMyTreesView::OnTreeRobson )
	ON_COMMAND( ID_TREE_DRAW, &CMyTreesView::OnTreeDraw )
	ON_COMMAND( ID_TREE_CLEAR, &CMyTreesView::OnTreeClear )
	ON_UPDATE_COMMAND_UI( ID_TREE_MAKE, &CMyTreesView::OnUpdateTreeMake )
END_MESSAGE_MAP()

// CMyTreesView construction/destruction

CMyTreesView::CMyTreesView()
{
	clientRect_ = std::make_shared<CRect>();
	fontObj_ = std::make_shared<CFont>();
	draw_ = false;
	print_ = false;
	treeIsEmpty_ = true;
	insert_ = false;
	LOGFONT logFont;
	memset( &logFont, 0, sizeof( LOGFONT ) );
	lstrcpy( logFont.lfFaceName, L"Consolas" );
	logFont.lfCharSet = DEFAULT_CHARSET;
	logFont.lfWeight = FW_REGULAR;
	logFont.lfHeight = 18;
	logFont.lfWidth = 18;
	if ( !fontObj_->CreateFontIndirect( &logFont ) )
		TRACE0( "Could not create font for the trends\n" );
}

CMyTreesView::~CMyTreesView()
{
}

BOOL CMyTreesView::PreCreateWindow( CREATESTRUCT& cs )
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow( cs );
}

// CMyTreesView drawing

void CMyTreesView::OnDraw( CDC* pDC )
{
	document_ = GetDocument();
	ASSERT_VALID( document_ );
	if ( !document_ )
		return;
	GetClientRect( this->clientRect_.get() );

	if ( draw_ )
		document_->getTree().draw( clientRect_, pDC );
	if ( print_ )
	{
		CString outText( document_->getTree().printInOrder().c_str() );
		auto sz = pDC->GetTextExtent( outText );
		CFont* oldFont = static_cast<CFont*>(pDC->SelectObject( fontObj_.get() ));
		pDC->SetTextColor( RGB( 0, 0, 127 ) );
		pDC->TextOutW( 10, static_cast<int>(clientRect_->Height() - 2 - sz.cy), outText );
		pDC->SelectObject( oldFont );
		pDC->SetTextColor( RGB( 0, 0, 0 ) );
	}
	if ( insert_ )
	{
		int newKey;
		do
		{
			newKey = Random::random( MIN_VALUE, MAX_VALUE );
		} while ( document_->getTree().findKey( newKey ) );

		document_->getTree().insert( clientRect_, pDC, newKey );
		insert_ = false;
		Invalidate();
		UpdateWindow();
	}

}


// CMyTreesView diagnostics

#ifdef _DEBUG
void CMyTreesView::AssertValid() const
{
	CView::AssertValid();
}

void CMyTreesView::Dump( CDumpContext& dc ) const
{
	CView::Dump( dc );
}

CMyTreesDoc* CMyTreesView::GetDocument() const // non-debug version is inline
{
	ASSERT( m_pDocument->IsKindOf( RUNTIME_CLASS( CMyTreesDoc ) ) );
	return (CMyTreesDoc*)m_pDocument;
}
#endif //_DEBUG


// CMyTreesView message handlers


void CMyTreesView::OnTreeMake()
{
	if ( treeIsEmpty_ )
	{
		for ( auto i = 0; i < 15; i++ )
		{
			auto newKey = Random::random( MIN_VALUE, MAX_VALUE );
			if ( !document_->getTree().findKey( newKey ) )
			{
				document_->getTree().insert( newKey );
			}
			else
			{
				i--;
			}
		}
		treeIsEmpty_ = false;
		Invalidate();
		UpdateWindow();
	}
}


void CMyTreesView::OnTreePrint()
{
	print_ = !print_;
	CMainFrame* frame = static_cast<CMainFrame*>(GetParentFrame());
	frame->resetButton( print_, 1 );
	Invalidate();
	UpdateWindow();
}


void CMyTreesView::OnTreeAddNode()
{
	insert_ = true;
	Invalidate();
	UpdateWindow();
}


void CMyTreesView::OnTreeRobson()
{
	// TODO: Add your command handler code here
}


void CMyTreesView::OnTreeDraw()
{
	draw_ = !draw_;
	CMainFrame* frame = static_cast<CMainFrame*>(GetParentFrame());
	frame->resetButton( draw_, 0 );
	Invalidate();
	UpdateWindow();
}


void CMyTreesView::OnTreeClear()
{
	treeIsEmpty_ = true;
	document_->getTree().clear();
	Invalidate();
	UpdateWindow();
}


void CMyTreesView::OnUpdateTreeMake( CCmdUI *pCmdUI )
{
	pCmdUI->Enable( treeIsEmpty_ );
}
