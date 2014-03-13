// SelectSize.cpp : implementation file
//

#include "stdafx.h"
#include "ImageProcess.h"
#include "SelectSize.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSelectSize dialog


CSelectSize::CSelectSize(CWnd* pParent /*=NULL*/)
	: CDialog(CSelectSize::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSelectSize)
	m_size = 0;
	//}}AFX_DATA_INIT
}


void CSelectSize::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSelectSize)
	DDX_Text(pDX, IDC_EDIT_SIZE, m_size);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSelectSize, CDialog)
	//{{AFX_MSG_MAP(CSelectSize)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSelectSize message handlers
