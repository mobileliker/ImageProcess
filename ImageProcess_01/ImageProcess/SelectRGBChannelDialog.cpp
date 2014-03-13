// SelectRGBChannelDialog.cpp : implementation file
//

#include "stdafx.h"
#include "ImageProcess.h"
#include "SelectRGBChannelDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSelectRGBChannelDialog dialog


CSelectRGBChannelDialog::CSelectRGBChannelDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CSelectRGBChannelDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSelectRGBChannelDialog)
	m_channel = -1;
	//}}AFX_DATA_INIT
}


void CSelectRGBChannelDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSelectRGBChannelDialog)
	DDX_Radio(pDX, IDC_RADIO_R, m_channel);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSelectRGBChannelDialog, CDialog)
	//{{AFX_MSG_MAP(CSelectRGBChannelDialog)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSelectRGBChannelDialog message handlers
