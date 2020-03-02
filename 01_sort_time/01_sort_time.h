
// 01_sort_time.h : main header file for the 01_sort_time application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMy01_sort_timeApp:
// See 01_sort_time.cpp for the implementation of this class
//

class CMy01_sort_timeApp : public CWinApp
{
public:
	CMy01_sort_timeApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy01_sort_timeApp theApp;
