// VideoReadTest.h : main header file for the VIDEOREADTEST application
//

#if !defined(AFX_VIDEOREADTEST_H__9961B251_F7CD_4D5C_94E0_AC2F4592C7BC__INCLUDED_)
#define AFX_VIDEOREADTEST_H__9961B251_F7CD_4D5C_94E0_AC2F4592C7BC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CVideoReadTestApp:
// See VideoReadTest.cpp for the implementation of this class
//

class CVideoReadTestApp : public CWinApp
{
public:
	CVideoReadTestApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVideoReadTestApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CVideoReadTestApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIDEOREADTEST_H__9961B251_F7CD_4D5C_94E0_AC2F4592C7BC__INCLUDED_)
