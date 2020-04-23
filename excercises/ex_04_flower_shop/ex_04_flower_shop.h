
// ex_04_flower_shop.h : main header file for the ex_04_flower_shop application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CFlowerShopApp:
// See ex_04_flower_shop.cpp for the implementation of this class
//

class CFlowerShopApp : public CWinApp
{
public:
	CFlowerShopApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CFlowerShopApp theApp;
