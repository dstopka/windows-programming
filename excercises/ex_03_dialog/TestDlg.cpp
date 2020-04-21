// TestDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ex_03_dialog.h"
#include "TestDlg.h"
#include "afxdialogex.h"


// CTestDlg dialog

IMPLEMENT_DYNAMIC(CTestDlg, CDialog)

CTestDlg::CTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_TEST, pParent)
	, m_nNum( 0 )
	, m_nAcceptanceKind( 0 )
	, m_bFirst( FALSE )
	, m_bSecond( FALSE )
	, m_bThird( FALSE )
	, m_nLectureKind( 0 )
{

}

CTestDlg::~CTestDlg()
{
}

void CTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange( pDX );
	DDX_Control( pDX, IDC_DATANUM, m_nNum );
	DDX_Control( pDX, IDC_EGZ, m_nAcceptanceKind );
	DDX_Control( pDX, IDC_FIRST, m_bFirst );
	DDX_Control( pDX, IDC_LETTERS, m_ComboLetters );
	DDX_Control( pDX, IDC_SECOND, m_bSecond );
	DDX_Control( pDX, IDC_THIRD, m_bThird );
	DDX_Control( pDX, IDC_WYKL, m_nLectureKind );
}


BEGIN_MESSAGE_MAP(CTestDlg, CDialog)
END_MESSAGE_MAP()


// CTestDlg message handlers
