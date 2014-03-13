#if !defined(AFX_SELECTRGBCHANNELDIALOG_H__154BCAD6_349B_4A2F_AA2D_F2C4D6B17DF5__INCLUDED_)
#define AFX_SELECTRGBCHANNELDIALOG_H__154BCAD6_349B_4A2F_AA2D_F2C4D6B17DF5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SelectRGBChannelDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSelectRGBChannelDialog dialog

class CSelectRGBChannelDialog : public CDialog
{
// Construction
public:
	CSelectRGBChannelDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSelectRGBChannelDialog)
	enum { IDD = IDD_DIALOG_SELECTRGBCHANNEL };
	int		m_channel;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSelectRGBChannelDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

//Function
public:



// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSelectRGBChannelDialog)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SELECTRGBCHANNELDIALOG_H__154BCAD6_349B_4A2F_AA2D_F2C4D6B17DF5__INCLUDED_)
