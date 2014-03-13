// ImageProcessView.cpp : implementation of the CImageProcessView class
//

#include "stdafx.h"
#include "ImageProcess.h"

#include "ImageProcessDoc.h"
#include "ImageProcessView.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CImageProcessView

IMPLEMENT_DYNCREATE(CImageProcessView, CView)

BEGIN_MESSAGE_MAP(CImageProcessView, CView)
	//{{AFX_MSG_MAP(CImageProcessView)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CImageProcessView construction/destruction

CImageProcessView::CImageProcessView()
{
	// TODO: add construction code here

}

CImageProcessView::~CImageProcessView()
{
}

BOOL CImageProcessView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CImageProcessView drawing

void CImageProcessView::OnDraw(CDC* pDC)
{
	CImageProcessDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CImage & img = pDoc->m_image;
	CRect r;
	GetClientRect(&r);
	r.SetRect(0,0,img.Width(),img.Height());
	img.DrawToHDC(pDC->GetSafeHdc(),r);

}

/////////////////////////////////////////////////////////////////////////////
// CImageProcessView printing

BOOL CImageProcessView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CImageProcessView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CImageProcessView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CImageProcessView diagnostics

#ifdef _DEBUG
void CImageProcessView::AssertValid() const
{
	CView::AssertValid();
}

void CImageProcessView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CImageProcessDoc* CImageProcessView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CImageProcessDoc)));
	return (CImageProcessDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CImageProcessView message handlers

void CImageProcessView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	char	buf[50];
	sprintf(buf, "X:%d  Y:%d", point.x, point.y);
	((CMainFrame *)(AfxGetMainWnd()))->m_wndStatusBar.SetPaneText(0, buf);

	CView::OnMouseMove(nFlags, point);
}

void CImageProcessView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CImageProcessDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	if(pDoc->m_bmannal)
	{
		m_originpoint = point;
	}

	CView::OnLButtonDown(nFlags, point);
}

void CImageProcessView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
		
	CImageProcessDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	if(pDoc->m_bmannal)
	{
		pDoc->DrawLine(cvPoint(m_originpoint.x,m_originpoint.y),cvPoint(point.x,point.y));
	}
	

	CView::OnLButtonUp(nFlags, point);
}
