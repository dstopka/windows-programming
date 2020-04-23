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
{

}

CFlowerShop::~CFlowerShop()
{
}

void CFlowerShop::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CFlowerShop, CDialog)
END_MESSAGE_MAP()


// CFlowerShop message handlers
