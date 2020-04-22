
// dialogView.cpp : implementation of the CDialogView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "ex_03_dialog.h"
#endif

#include "dialogDoc.h"
#include "dialogView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDialogView

IMPLEMENT_DYNCREATE(CDialogView, CView)

BEGIN_MESSAGE_MAP(CDialogView, CView)
	ON_COMMAND( ID_DLG_TEST, &CDialogView::OnDlgTest )
	ON_UPDATE_COMMAND_UI( ID_DLG_TEST, &CDialogView::OnUpdateDlgTest )
END_MESSAGE_MAP()

// CDialogView construction/destruction

CDialogView::CDialogView()
{
	// TODO: add construction code here

}

CDialogView::~CDialogView()
{
}

BOOL CDialogView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CDialogView drawing

void CDialogView::OnDraw(CDC* /*pDC*/)
{
	CDialogDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CDialogView diagnostics

#ifdef _DEBUG
void CDialogView::AssertValid() const
{
	CView::AssertValid();
}

void CDialogView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDialogDoc* CDialogView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDialogDoc)));
	return (CDialogDoc*)m_pDocument;
}
#endif //_DEBUG


// CDialogView message handlers


void CDialogView::OnDlgTest()
{
	CTestDlg dlg;
	if ( dlg.DoModal() == IDOK )
		AfxMessageBox( L"Ustawienia w oknie dialogowym zaakceptowane!" );
	else
		AfxMessageBox( L"Rezygnacja z ustawieñ" );
}


void CDialogView::OnUpdateDlgTest( CCmdUI *pCmdUI )
{
	pCmdUI->Enable( 1 );
}
