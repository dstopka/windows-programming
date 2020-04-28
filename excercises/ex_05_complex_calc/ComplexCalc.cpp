// ComplexCalc.cpp : implementation file
//

#include "stdafx.h"
#include "ex_05_complex_calc.h"
#include "ComplexCalc.h"
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
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CComplexCalc, CDialog)
END_MESSAGE_MAP()


// CComplexCalc message handlers


BOOL CComplexCalc::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
