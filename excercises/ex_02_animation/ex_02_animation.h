
// ex_02_animation.h : main header file for the ex_02_animation application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CanimationApp:
// See ex_02_animation.cpp for the implementation of this class
//

class CanimationApp : public CWinApp
{
public:
	CanimationApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CanimationApp theApp;
