
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
#include "ThreadedBinaryTree.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMyTreesView

IMPLEMENT_DYNCREATE(CMyTreesView, CView)

BEGIN_MESSAGE_MAP(CMyTreesView, CView)
	ON_COMMAND( ID_TREE_MAKETREE, &CMyTreesView::OnTreeMake )
	ON_COMMAND( ID_TREE_PRINTINORDER, &CMyTreesView::OnTreePrint )
	ON_COMMAND( ID_TREE_ADDNODE, &CMyTreesView::OnTreeAddNode )
	ON_COMMAND( ID_TREE_ROBSON, &CMyTreesView::OnTreeRobson )
END_MESSAGE_MAP()

// CMyTreesView construction/destruction

CMyTreesView::CMyTreesView()
{
	clientRect_ = std::make_shared<CRect>();
	print_ = false;
}

CMyTreesView::~CMyTreesView()
{
}

BOOL CMyTreesView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMyTreesView drawing

void CMyTreesView::OnDraw(CDC* pDC)
{
	document_ = GetDocument();
	ASSERT_VALID( document_ );
	if (!document_ )
		return;
	GetClientRect( this->clientRect_.get() );
	document_->getTree().draw( clientRect_, pDC );
	if ( print_ )
		document_->getTree().printInOrder(clientRect_, pDC);
}


// CMyTreesView diagnostics

#ifdef _DEBUG
void CMyTreesView::AssertValid() const
{
	CView::AssertValid();
}

void CMyTreesView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMyTreesDoc* CMyTreesView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyTreesDoc)));
	return (CMyTreesDoc*)m_pDocument;
}
#endif //_DEBUG


// CMyTreesView message handlers


void CMyTreesView::OnTreeMake()
{
	document_->getTree().make();
	for ( auto i = 0; i < 15; i++ )
	{
		auto newKey = Random::random( MIN_VALUE, MAX_VALUE );
		if ( !document_->getTree().findKey(newKey))
		{
			document_->getTree().insert( newKey);
		}
		else
		{
			i--;
		}
	}
	Invalidate();
	UpdateWindow();
}


void CMyTreesView::OnTreePrint()
{
	print_ = true;
	Invalidate();
	UpdateWindow();
}


void CMyTreesView::OnTreeAddNode()
{
	int newKey;
	do
	{
		newKey = Random::random( MIN_VALUE, MAX_VALUE );
	} while ( document_->getTree().findKey( newKey ) );

	document_->getTree().insert( newKey );

	Invalidate();
	UpdateWindow();
}


void CMyTreesView::OnTreeRobson()
{
	// TODO: Add your command handler code here
}
