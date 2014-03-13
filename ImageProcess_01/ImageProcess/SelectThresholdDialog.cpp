// SelectThresholdDialog.cpp : implementation file
//

#include "stdafx.h"
#include "ImageProcess.h"
#include "SelectThresholdDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSelectThresholdDialog dialog


CSelectThresholdDialog::CSelectThresholdDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CSelectThresholdDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSelectThresholdDialog)
	m_threshold = 0.0;
	m_threshold_type = -1;
	//}}AFX_DATA_INIT
}


void CSelectThresholdDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSelectThresholdDialog)
	DDX_Text(pDX, IDC_THRESHOLD, m_threshold);
	DDX_Radio(pDX, IDC_RADIO_AES, m_threshold_type);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSelectThresholdDialog, CDialog)
	//{{AFX_MSG_MAP(CSelectThresholdDialog)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSelectThresholdDialog message handlers
