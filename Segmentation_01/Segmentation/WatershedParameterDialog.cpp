// WatershedParameterDialog.cpp : implementation file
//

#include "stdafx.h"
#include "Segmentation.h"
#include "WatershedParameterDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWatershedParameterDialog dialog


CWatershedParameterDialog::CWatershedParameterDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CWatershedParameterDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWatershedParameterDialog)
	m_x1 = 0;
	m_x2 = 0;
	m_y1 = 0;
	m_y2 = 0;
	//}}AFX_DATA_INIT
}


void CWatershedParameterDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWatershedParameterDialog)
	DDX_Text(pDX, IDC_EDIT_X1, m_x1);
	DDX_Text(pDX, IDC_EDIT_X2, m_x2);
	DDX_Text(pDX, IDC_EDIT_Y1, m_y1);
	DDX_Text(pDX, IDC_EDIT_Y2, m_y2);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CWatershedParameterDialog, CDialog)
	//{{AFX_MSG_MAP(CWatershedParameterDialog)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWatershedParameterDialog message handlers
