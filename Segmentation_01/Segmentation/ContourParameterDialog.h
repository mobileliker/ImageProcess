#if !defined(AFX_CONTOURPARAMETERDIALOG_H__A65B8368_0779_45F2_95CD_71CDF45351B4__INCLUDED_)
#define AFX_CONTOURPARAMETERDIALOG_H__A65B8368_0779_45F2_95CD_71CDF45351B4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ContourParameterDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CContourParameterDialog dialog

class CContourParameterDialog : public CDialog
{
// Construction
public:
	CContourParameterDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CContourParameterDialog)
	enum { IDD = IDD_DIALOG_CONTOURPARAMETER };
	int		m_x;
	int		m_y;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CContourParameterDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CContourParameterDialog)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONTOURPARAMETERDIALOG_H__A65B8368_0779_45F2_95CD_71CDF45351B4__INCLUDED_)
