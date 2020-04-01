
// 02_balls_animation.h : main header file for the 02_balls_animation application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMyBallsAnimationApp:
// See 02_balls_animation.cpp for the implementation of this class
//

class CMyBallsAnimationApp : public CWinApp
{
public:
	CMyBallsAnimationApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMyBallsAnimationApp theApp;
