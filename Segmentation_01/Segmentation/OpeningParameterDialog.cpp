// OpeningParameterDialog.cpp : implementation file
//

#include "stdafx.h"
#include "Segmentation.h"
#include "OpeningParameterDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COpeningParameterDialog dialog


COpeningParameterDialog::COpeningParameterDialog(CWnd* pParent /*=NULL*/)
	: CDialog(COpeningParameterDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(COpeningParameterDialog)
	m_circle_scope = 0;
	m_times = 0;
	//}}AFX_DATA_INIT
}


void COpeningParameterDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COpeningParameterDialog)
	DDX_Text(pDX, IDC_EDIT_CIRCLESCOPE, m_circle_scope);
	DDX_Text(pDX, IDC_EDIT_TIMES, m_times);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(COpeningParameterDialog, CDialog)
	//{{AFX_MSG_MAP(COpeningParameterDialog)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COpeningParameterDialog message handlers
