
// ex_01_toolbar.h : main header file for the ex_01_toolbar application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// Cex_01_toolbarApp:
// See ex_01_toolbar.cpp for the implementation of this class
//

class Cex_01_toolbarApp : public CWinApp
{
public:
	Cex_01_toolbarApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cex_01_toolbarApp theApp;
