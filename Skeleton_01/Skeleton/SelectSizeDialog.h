#if !defined(AFX_SELECTSIZEDIALOG_H__1CBCD7DC_4ED8_4DDE_B4B4_AB1C95B0C47B__INCLUDED_)
#define AFX_SELECTSIZEDIALOG_H__1CBCD7DC_4ED8_4DDE_B4B4_AB1C95B0C47B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SelectSizeDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSelectSizeDialog dialog

class CSelectSizeDialog : public CDialog
{
// Construction
public:
	CSelectSizeDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSelectSizeDialog)
	enum { IDD = IDD_DIALOG_SELECTSIZE };
	int		m_size;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSelectSizeDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSelectSizeDialog)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SELECTSIZEDIALOG_H__1CBCD7DC_4ED8_4DDE_B4B4_AB1C95B0C47B__INCLUDED_)
