
// ex_05_complex_calc.h : main header file for the ex_05_complex_calc application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CComplexCalcApp:
// See ex_05_complex_calc.cpp for the implementation of this class
//

class CComplexCalcApp : public CWinApp
{
public:
	CComplexCalcApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CComplexCalcApp theApp;
