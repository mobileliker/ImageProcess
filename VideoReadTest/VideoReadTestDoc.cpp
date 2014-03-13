// VideoReadTestDoc.cpp : implementation of the CVideoReadTestDoc class
//

#include "stdafx.h"
#include "VideoReadTest.h"

#include "VideoReadTestDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CVideoReadTestDoc

IMPLEMENT_DYNCREATE(CVideoReadTestDoc, CDocument)

BEGIN_MESSAGE_MAP(CVideoReadTestDoc, CDocument)
	//{{AFX_MSG_MAP(CVideoReadTestDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVideoReadTestDoc construction/destruction

CVideoReadTestDoc::CVideoReadTestDoc()
{
	// TODO: add one-time construction code here

}

CVideoReadTestDoc::~CVideoReadTestDoc()
{
}

BOOL CVideoReadTestDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CVideoReadTestDoc serialization

void CVideoReadTestDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CVideoReadTestDoc diagnostics

#ifdef _DEBUG
void CVideoReadTestDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CVideoReadTestDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CVideoReadTestDoc commands

BOOL CVideoReadTestDoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;
	
	// TODO: Add your specialized creation code here
	capture = cvCreateFileCapture(lpszPathName);
	IplImage *pImg = cvQueryFrame(capture);
	m_image.CopyOf(pImg);
	
	return TRUE;
}

BOOL CVideoReadTestDoc::OnSaveDocument(LPCTSTR lpszPathName) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CDocument::OnSaveDocument(lpszPathName);
}




