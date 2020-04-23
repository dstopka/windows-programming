#pragma once
#include "afxcmn.h"


// CFlowerShop dialog

class CFlowerShop : public CDialog
{
	DECLARE_DYNAMIC(CFlowerShop)

public:
	CFlowerShop(CWnd* pParent = NULL);   // standard constructor
	virtual ~CFlowerShop();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FLOWERSHP };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
private:
	int m_nPackageKind;
	int m_nDiscount;
	int m_nTulip;
	int m_nFreesia;
	int m_nRose;
	CSpinButtonCtrl m_SpinFreesia;
	CSpinButtonCtrl m_SpinRose;
	CSpinButtonCtrl m_SpinTulip;
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnCalculate();
};
