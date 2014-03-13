// Segmentation.h : main header file for the SEGMENTATION application
//

#if !defined(AFX_SEGMENTATION_H__889230BC_D73E_45E8_9B29_F825BB77733A__INCLUDED_)
#define AFX_SEGMENTATION_H__889230BC_D73E_45E8_9B29_F825BB77733A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CSegmentationApp:
// See Segmentation.cpp for the implementation of this class
//

class CSegmentationApp : public CWinApp
{
public:
	CSegmentationApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSegmentationApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CSegmentationApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SEGMENTATION_H__889230BC_D73E_45E8_9B29_F825BB77733A__INCLUDED_)
