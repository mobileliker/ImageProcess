// SelectSizeDialog.cpp : implementation file
//

#include "stdafx.h"
#include "Skeleton.h"
#include "SelectSizeDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSelectSizeDialog dialog


CSelectSizeDialog::CSelectSizeDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CSelectSizeDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSelectSizeDialog)
	m_size = 0;
	//}}AFX_DATA_INIT
}


void CSelectSizeDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSelectSizeDialog)
	DDX_Text(pDX, IDC_FILTERSIZE, m_size);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSelectSizeDialog, CDialog)
	//{{AFX_MSG_MAP(CSelectSizeDialog)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSelectSizeDialog message handlers
