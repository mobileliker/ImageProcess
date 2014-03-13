// VideoReadTestView.cpp : implementation of the CVideoReadTestView class
//

#include "stdafx.h"
#include "VideoReadTest.h"

#include "VideoReadTestDoc.h"
#include "VideoReadTestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CVideoReadTestView

IMPLEMENT_DYNCREATE(CVideoReadTestView, CView)

BEGIN_MESSAGE_MAP(CVideoReadTestView, CView)
	//{{AFX_MSG_MAP(CVideoReadTestView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVideoReadTestView construction/destruction

CVideoReadTestView::CVideoReadTestView()
{
	// TODO: add construction code here

}

CVideoReadTestView::~CVideoReadTestView()
{
}

BOOL CVideoReadTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CVideoReadTestView drawing

void CVideoReadTestView::OnDraw(CDC* pDC)
{
	CVideoReadTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

	CImage & img = pDoc->m_image;
	CRect r;
	GetClientRect (&r);
	r.SetRect(0,0,img.Width(),img.Height());
	img.DrawToHDC(pDC->GetSafeHdc(),r);

}

/////////////////////////////////////////////////////////////////////////////
// CVideoReadTestView printing

BOOL CVideoReadTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CVideoReadTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CVideoReadTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CVideoReadTestView diagnostics

#ifdef _DEBUG
void CVideoReadTestView::AssertValid() const
{
	CView::AssertValid();
}

void CVideoReadTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CVideoReadTestDoc* CVideoReadTestView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CVideoReadTestDoc)));
	return (CVideoReadTestDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CVideoReadTestView message handlers
