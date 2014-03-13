// SelectHSVChannelDialog.cpp : implementation file
//

#include "stdafx.h"
#include "ImageProcess.h"
#include "SelectHSVChannelDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSelectHSVChannelDialog dialog


CSelectHSVChannelDialog::CSelectHSVChannelDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CSelectHSVChannelDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSelectHSVChannelDialog)
	m_channel = -1;
	//}}AFX_DATA_INIT
}


void CSelectHSVChannelDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSelectHSVChannelDialog)
	DDX_Radio(pDX, IDC_RADIO_H, m_channel);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSelectHSVChannelDialog, CDialog)
	//{{AFX_MSG_MAP(CSelectHSVChannelDialog)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSelectHSVChannelDialog message handlers
