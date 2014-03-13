// SelectRotateDialog.cpp : implementation file
//

#include "stdafx.h"
#include "ImageProcess.h"
#include "SelectRotateDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSelectRotateDialog dialog


CSelectRotateDialog::CSelectRotateDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CSelectRotateDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSelectRotateDialog)
	m_angle = 0;
	m_clockwise = -1;
	//}}AFX_DATA_INIT
}


void CSelectRotateDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSelectRotateDialog)
	DDX_Text(pDX, IDC_EDIT_ANGLE, m_angle);
	DDX_Radio(pDX, IDC_RADIO_CLOCKWISE, m_clockwise);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSelectRotateDialog, CDialog)
	//{{AFX_MSG_MAP(CSelectRotateDialog)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSelectRotateDialog message handlers
