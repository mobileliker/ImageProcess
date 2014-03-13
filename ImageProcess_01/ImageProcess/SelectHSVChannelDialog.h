#if !defined(AFX_SELECTHSVCHANNELDIALOG_H__80A688BB_3404_4F6F_A274_3D31B73919F1__INCLUDED_)
#define AFX_SELECTHSVCHANNELDIALOG_H__80A688BB_3404_4F6F_A274_3D31B73919F1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SelectHSVChannelDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSelectHSVChannelDialog dialog

class CSelectHSVChannelDialog : public CDialog
{
// Construction
public:
	CSelectHSVChannelDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSelectHSVChannelDialog)
	enum { IDD = IDD_DIALOG_SELECTHSVCHANNEL };
	int		m_channel;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSelectHSVChannelDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSelectHSVChannelDialog)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SELECTHSVCHANNELDIALOG_H__80A688BB_3404_4F6F_A274_3D31B73919F1__INCLUDED_)
