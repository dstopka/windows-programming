// FlowerShop.cpp : implementation file
//

#include "stdafx.h"
#include "ex_04_flower_shop.h"
#include "FlowerShop.h"
#include "afxdialogex.h"


// CFlowerShop dialog

IMPLEMENT_DYNAMIC(CFlowerShop, CDialog)

CFlowerShop::CFlowerShop(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_FLOWERSHP, pParent)
	, m_nPackageKind( 2 )
	, m_nDiscount( 0 )
	, m_nTulip( 0 )
	, m_nFreesia( 0 )
	, m_nRose( 0 )
{

}

CFlowerShop::~CFlowerShop()
{
}

void CFlowerShop::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange( pDX );
	DDX_Radio( pDX, IDC_FOIL, m_nPackageKind );
	DDX_Text( pDX, IDC_DISC, m_nDiscount );
	DDX_Text( pDX, IDC_TULIP, m_nTulip );
	DDX_Text( pDX, IDC_FREZ, m_nFreesia );
	DDX_Text( pDX, IDC_ROSE, m_nRose );
	DDX_Control( pDX, IDC_SPIN_FREZ, m_SpinFreesia );
	DDX_Control( pDX, IDC_SPIN_ROSE, m_SpinRose );
	DDX_Control( pDX, IDC_SPIN_TULIP, m_SpinTulip );
}


BEGIN_MESSAGE_MAP(CFlowerShop, CDialog)
	ON_BN_CLICKED( IDC_CALCULATE, &CFlowerShop::OnCalculate )
END_MESSAGE_MAP()


// CFlowerShop message handlers


BOOL CFlowerShop::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_SpinTulip.SetRange( 0, 100 );
	m_SpinRose.SetRange( 0, 100 );
	m_SpinFreesia.SetRange( 0, 100 );
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


void CFlowerShop::OnCalculate()
{
	UpdateData();
	double nPayment = 0;
	nPayment += m_nTulip * 4;
	nPayment += m_nRose * 3;
	nPayment += m_nFreesia * 2;
	if ( m_nPackageKind == 0 )
		nPayment += 2;
	else if ( m_nPackageKind == 1 )
		nPayment += 1;
	if ( m_nDiscount )
		nPayment *= (100.0 - m_nDiscount) / 100;
	CString str;
	str.Format( L"%.2f", nPayment );
	CWnd* pWnd = GetDlgItem( IDC_RESULT );
	pWnd->SetWindowTextW( str );
}
