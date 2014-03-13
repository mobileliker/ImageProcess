// SlectCalculateStyleDialog.cpp : implementation file
//

#include "stdafx.h"
#include "ImageProcess.h"
#include "SlectCalculateStyleDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSlectCalculateStyleDialog dialog


CSlectCalculateStyleDialog::CSlectCalculateStyleDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CSlectCalculateStyleDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSlectCalculateStyleDialog)
	m_style = -1;
	//}}AFX_DATA_INIT
}


void CSlectCalculateStyleDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSlectCalculateStyleDialog)
	DDX_Radio(pDX, IDC_RADIO_X, m_style);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSlectCalculateStyleDialog, CDialog)
	//{{AFX_MSG_MAP(CSlectCalculateStyleDialog)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSlectCalculateStyleDialog message handlers
