#if !defined(AFX_SLECTCALCULATESTYLEDIALOG_H__31A9AD46_FBA4_4341_9526_8C1539B688A7__INCLUDED_)
#define AFX_SLECTCALCULATESTYLEDIALOG_H__31A9AD46_FBA4_4341_9526_8C1539B688A7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SlectCalculateStyleDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSlectCalculateStyleDialog dialog

class CSlectCalculateStyleDialog : public CDialog
{
// Construction
public:
	CSlectCalculateStyleDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSlectCalculateStyleDialog)
	enum { IDD = IDD_DIALOG_SELECTCALSTYLE };
	int		m_style;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSlectCalculateStyleDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSlectCalculateStyleDialog)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SLECTCALCULATESTYLEDIALOG_H__31A9AD46_FBA4_4341_9526_8C1539B688A7__INCLUDED_)
