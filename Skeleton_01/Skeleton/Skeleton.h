// Skeleton.h : main header file for the SKELETON application
//

#if !defined(AFX_SKELETON_H__E26B1C00_4920_4391_BDC0_3704830A45BF__INCLUDED_)
#define AFX_SKELETON_H__E26B1C00_4920_4391_BDC0_3704830A45BF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CSkeletonApp:
// See Skeleton.cpp for the implementation of this class
//

class CSkeletonApp : public CWinApp
{
public:
	CSkeletonApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSkeletonApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CSkeletonApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SKELETON_H__E26B1C00_4920_4391_BDC0_3704830A45BF__INCLUDED_)
