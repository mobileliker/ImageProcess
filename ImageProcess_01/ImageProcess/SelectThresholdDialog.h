#if !defined(AFX_SELECTTHRESHOLDDIALOG_H__C6D05CE4_DFC6_4D63_9FD9_80B7DF9ADC3B__INCLUDED_)
#define AFX_SELECTTHRESHOLDDIALOG_H__C6D05CE4_DFC6_4D63_9FD9_80B7DF9ADC3B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SelectThresholdDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSelectThresholdDialog dialog

class CSelectThresholdDialog : public CDialog
{
// Construction
public:
	CSelectThresholdDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSelectThresholdDialog)
	enum { IDD = IDD_DIALOG_SELECTTHRESHOLD };
	double	m_threshold;
	int		m_threshold_type;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSelectThresholdDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSelectThresholdDialog)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SELECTTHRESHOLDDIALOG_H__C6D05CE4_DFC6_4D63_9FD9_80B7DF9ADC3B__INCLUDED_)
