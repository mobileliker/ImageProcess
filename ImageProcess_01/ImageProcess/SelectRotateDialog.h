#if !defined(AFX_SELECTROTATEDIALOG_H__F254A47D_7190_4A30_B035_25C7D3111879__INCLUDED_)
#define AFX_SELECTROTATEDIALOG_H__F254A47D_7190_4A30_B035_25C7D3111879__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SelectRotateDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSelectRotateDialog dialog

class CSelectRotateDialog : public CDialog
{
// Construction
public:
	CSelectRotateDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSelectRotateDialog)
	enum { IDD = IDD_DIALOG_SELECTROTATE };
	int		m_angle;
	int		m_clockwise;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSelectRotateDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSelectRotateDialog)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SELECTROTATEDIALOG_H__F254A47D_7190_4A30_B035_25C7D3111879__INCLUDED_)
