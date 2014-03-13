// SegmentationView.cpp : implementation of the CSegmentationView class
//

#include "stdafx.h"
#include "Segmentation.h"

#include "SegmentationDoc.h"
#include "SegmentationView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSegmentationView

IMPLEMENT_DYNCREATE(CSegmentationView, CView)

BEGIN_MESSAGE_MAP(CSegmentationView, CView)
	//{{AFX_MSG_MAP(CSegmentationView)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSegmentationView construction/destruction

CSegmentationView::CSegmentationView()
{
	// TODO: add construction code here

}

CSegmentationView::~CSegmentationView()
{
}

BOOL CSegmentationView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSegmentationView drawing

void CSegmentationView::OnDraw(CDC* pDC)
{
	CSegmentationDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CImage & img = pDoc->m_image;
	CRect r;
	GetClientRect (&r);
	r.SetRect(0,0,img.Width(),img.Height());
	img.DrawToHDC(pDC->GetSafeHdc(),r);
}

/////////////////////////////////////////////////////////////////////////////
// CSegmentationView printing

BOOL CSegmentationView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSegmentationView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSegmentationView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CSegmentationView diagnostics

#ifdef _DEBUG
void CSegmentationView::AssertValid() const
{
	CView::AssertValid();
}

void CSegmentationView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSegmentationDoc* CSegmentationView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSegmentationDoc)));
	return (CSegmentationDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSegmentationView message handlers

