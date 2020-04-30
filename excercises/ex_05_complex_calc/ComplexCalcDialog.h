#pragma once
#include "CanonComplex.h"


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
	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClickedSub();
	afx_msg void OnBnClickedMod();
	afx_msg void OnBnClickedMult();
	afx_msg void OnBnClickedDiv();
	afx_msg void OnBnClickedCoup();
private:
	CCanonComplex m_firstComplex;
	CCanonComplex m_secondComplex;
};
