// ContourParameterDialog.cpp : implementation file
//

#include "stdafx.h"
#include "Segmentation.h"
#include "ContourParameterDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CContourParameterDialog dialog


CContourParameterDialog::CContourParameterDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CContourParameterDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CContourParameterDialog)
	m_x = 0;
	m_y = 0;
	//}}AFX_DATA_INIT
}


void CContourParameterDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CContourParameterDialog)
	DDX_Text(pDX, IDC_EDIT_X, m_x);
	DDX_Text(pDX, IDC_EDIT_Y, m_y);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CContourParameterDialog, CDialog)
	//{{AFX_MSG_MAP(CContourParameterDialog)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CContourParameterDialog message handlers
