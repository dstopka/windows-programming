// ComplexCalc.cpp : implementation file
//

#include "stdafx.h"
#include "ex_05_complex_calc.h"
#include "ComplexCalcDialog.h"
#include "afxdialogex.h"


// CComplexCalc dialog

IMPLEMENT_DYNAMIC(CComplexCalc, CDialog)

CComplexCalc::CComplexCalc(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_COMPLEX_CALC, pParent)
{

}

CComplexCalc::~CComplexCalc()
{
}

void CComplexCalc::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange( pDX );
	DDX_Text( pDX, IDC_FIRST, m_firstComplex );
	DDX_Text( pDX, IDC_SECOND, m_secondComplex );
}


BEGIN_MESSAGE_MAP(CComplexCalc, CDialog)
	ON_BN_CLICKED( IDC_ADD, &CComplexCalc::OnBnClickedAdd )
	ON_BN_CLICKED( IDC_SUB, &CComplexCalc::OnBnClickedSub )
	ON_BN_CLICKED( IDC_MOD, &CComplexCalc::OnBnClickedMod )
	ON_BN_CLICKED( IDC_MULT, &CComplexCalc::OnBnClickedMult )
	ON_BN_CLICKED( IDC_DIV, &CComplexCalc::OnBnClickedDiv )
	ON_BN_CLICKED( IDC_COUP, &CComplexCalc::OnBnClickedCoup )
END_MESSAGE_MAP()


// CComplexCalc message handlers


BOOL CComplexCalc::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


void CComplexCalc::OnBnClickedAdd()
{
	// TODO: Add your control notification handler code here
}


void CComplexCalc::OnBnClickedSub()
{
	// TODO: Add your control notification handler code here
}


void CComplexCalc::OnBnClickedMod()
{
	// TODO: Add your control notification handler code here
}


void CComplexCalc::OnBnClickedMult()
{
	// TODO: Add your control notification handler code here
}


void CComplexCalc::OnBnClickedDiv()
{
	// TODO: Add your control notification handler code here
}


void CComplexCalc::OnBnClickedCoup()
{
	// TODO: Add your control notification handler code here
}
