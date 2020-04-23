#pragma once


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
};
