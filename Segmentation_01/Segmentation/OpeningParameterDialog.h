#if !defined(AFX_OPENINGPARAMETERDIALOG_H__6E4149F9_48DC_45CD_B286_CE4A1AA9AB75__INCLUDED_)
#define AFX_OPENINGPARAMETERDIALOG_H__6E4149F9_48DC_45CD_B286_CE4A1AA9AB75__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OpeningParameterDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// COpeningParameterDialog dialog

class COpeningParameterDialog : public CDialog
{
// Construction
public:
	COpeningParameterDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(COpeningParameterDialog)
	enum { IDD = IDD_DIALOG_OPENINGPARAMETER };
	int		m_circle_scope;
	int		m_times;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COpeningParameterDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(COpeningParameterDialog)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPENINGPARAMETERDIALOG_H__6E4149F9_48DC_45CD_B286_CE4A1AA9AB75__INCLUDED_)
