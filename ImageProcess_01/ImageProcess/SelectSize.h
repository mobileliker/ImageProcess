#if !defined(AFX_SELECTSIZE_H__5CAC7A05_DB20_4D69_B7E5_5B82FEB54DAC__INCLUDED_)
#define AFX_SELECTSIZE_H__5CAC7A05_DB20_4D69_B7E5_5B82FEB54DAC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SelectSize.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSelectSize dialog

class CSelectSize : public CDialog
{
// Construction
public:
	CSelectSize(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSelectSize)
	enum { IDD = IDD_DIALOG_SELECTSIZE };
	int		m_size;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSelectSize)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSelectSize)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SELECTSIZE_H__5CAC7A05_DB20_4D69_B7E5_5B82FEB54DAC__INCLUDED_)
