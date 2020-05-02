// ComplexCalc.cpp : implementation file
//

#include "stdafx.h"
#include "ex_05_complex_calc.h"
#include "ComplexCalcDialog.h"

#include <string>
#include <sstream>
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
	ON_BN_CLICKED( IDC_MULT, &CComplexCalc::OnBnClickedMult )
	ON_BN_CLICKED( IDC_DIV, &CComplexCalc::OnBnClickedDiv )
	ON_BN_CLICKED( IDC_MOD_FIRST, &CComplexCalc::OnBnClickedModFirst )
	ON_BN_CLICKED( IDC_MOD_SECOND, &CComplexCalc::OnBnClickedModSecond )
	ON_BN_CLICKED( IDC_COUPLED_FIRST, &CComplexCalc::OnBnClickedCoupledFirst )
	ON_BN_CLICKED( IDC_COUPLED_SECOND, &CComplexCalc::OnBnClickedCoupledSecond )
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
	UpdateData();
	USES_CONVERSION;
	std::stringstream ss( W2A( m_firstComplex ) );
	CCanonComplex first(CComplex(0, 0));
	CCanonComplex second(CComplex( 0, 0 ));
	ss >> first;
	ss.clear();
	ss.str( W2A( m_secondComplex ) );
	ss >> second;
	CCanonComplex result = first + second;
	ss.clear();
	ss.str("");
	ss << result;
	CWnd* pWnd = GetDlgItem( IDC_RESULT );
	pWnd->SetWindowTextW( CA2T(ss.str().c_str()) );
}


void CComplexCalc::OnBnClickedSub()
{
	UpdateData();
	USES_CONVERSION;
	std::stringstream ss( W2A( m_firstComplex ) );
	CCanonComplex first( CComplex( 0, 0 ) );
	CCanonComplex second( CComplex( 0, 0 ) );
	ss >> first;
	ss.clear();
	ss.str( W2A( m_secondComplex ) );
	ss >> second;
	CCanonComplex result = first - second;
	ss.clear();
	ss.str( "" );
	ss << result;
	CWnd* pWnd = GetDlgItem( IDC_RESULT );
	pWnd->SetWindowTextW( CA2T( ss.str().c_str() ) );
}


void CComplexCalc::OnBnClickedMult()
{
	UpdateData();
	USES_CONVERSION;
	std::stringstream ss( W2A( m_firstComplex ) );
	CCanonComplex first( CComplex( 0, 0 ) );
	CCanonComplex second( CComplex( 0, 0 ) );
	ss >> first;
	ss.clear();
	ss.str( W2A( m_secondComplex ) );
	ss >> second;
	CCanonComplex result = first * second;
	ss.clear();
	ss.str( "" );
	ss << result;
	CWnd* pWnd = GetDlgItem( IDC_RESULT );
	pWnd->SetWindowTextW( CA2T( ss.str().c_str() ) );
}


void CComplexCalc::OnBnClickedDiv()
{
	UpdateData();
	USES_CONVERSION;
	std::stringstream ss( W2A( m_firstComplex ) );
	CCanonComplex first( CComplex( 0, 0 ) );
	CCanonComplex second( CComplex( 0, 0 ) );
	ss >> first;
	ss.clear();
	ss.str( W2A( m_secondComplex ) );
	ss >> second;
	CCanonComplex result = first / second;
	ss.clear();
	ss.str( "" );
	ss << result;
	CWnd* pWnd = GetDlgItem( IDC_RESULT );
	pWnd->SetWindowTextW( CA2T( ss.str().c_str() ) );
}


void CComplexCalc::OnBnClickedModFirst()
{
	UpdateData();
	USES_CONVERSION;
	std::stringstream ss( W2A( m_firstComplex ) );
	CCanonComplex c( CComplex( 0, 0 ) );
	ss >> c;
	double mod = c.Module();
	CString str;
	str.Format( L"%f", mod );
	CWnd* pWnd = GetDlgItem( IDC_RESULT );
	pWnd->SetWindowTextW( str );
}


void CComplexCalc::OnBnClickedModSecond()
{
	UpdateData();
	USES_CONVERSION;
	std::stringstream ss( W2A( m_secondComplex ) );
	CCanonComplex c( CComplex( 0, 0 ) );
	ss >> c;
	double mod = c.Module();
	CString str;
	str.Format( L"%f", mod );
	CWnd* pWnd = GetDlgItem( IDC_RESULT );
	pWnd->SetWindowTextW( str );
}


void CComplexCalc::OnBnClickedCoupledFirst()
{
	UpdateData();
	USES_CONVERSION;
	std::stringstream ss( W2A( m_firstComplex ) );
	CCanonComplex c( CComplex( 0, 0 ) );
	ss >> c;
	c = c.Coupled();
	ss.clear();
	ss.str( "" );
	ss << c;
	CWnd* pWnd = GetDlgItem( IDC_RESULT );
	pWnd->SetWindowTextW( CA2T( ss.str().c_str() ) );
}


void CComplexCalc::OnBnClickedCoupledSecond()
{
	UpdateData();
	USES_CONVERSION;
	std::stringstream ss( W2A( m_secondComplex ) );
	CCanonComplex c( CComplex( 0, 0 ) );
	ss >> c;
	c = c.Coupled();
	ss.clear();
	ss.str( "" );
	ss << c;
	CWnd* pWnd = GetDlgItem( IDC_RESULT );
	pWnd->SetWindowTextW( CA2T( ss.str().c_str() ) );
}
