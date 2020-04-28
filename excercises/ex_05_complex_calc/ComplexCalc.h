#pragma once


// CComplexCalc dialog

class CComplexCalc : public CDialog
{
	DECLARE_DYNAMIC(CComplexCalc)

public:
	CComplexCalc(CWnd* pParent = NULL);   // standard constructor
	virtual ~CComplexCalc();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_COMPLEX_CALC };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
