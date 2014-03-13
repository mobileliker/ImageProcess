#if !defined(AFX_WATERSHEDPARAMETERDIALOG_H__EF48D33E_1E28_4C14_B009_A813398BDD0E__INCLUDED_)
#define AFX_WATERSHEDPARAMETERDIALOG_H__EF48D33E_1E28_4C14_B009_A813398BDD0E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WatershedParameterDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CWatershedParameterDialog dialog

class CWatershedParameterDialog : public CDialog
{
// Construction
public:
	CWatershedParameterDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CWatershedParameterDialog)
	enum { IDD = IDD_DIALOG_WATERSHED };
	int		m_x1;
	int		m_x2;
	int		m_y1;
	int		m_y2;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWatershedParameterDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CWatershedParameterDialog)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WATERSHEDPARAMETERDIALOG_H__EF48D33E_1E28_4C14_B009_A813398BDD0E__INCLUDED_)
