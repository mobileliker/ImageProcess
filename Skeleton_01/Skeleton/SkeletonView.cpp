// SkeletonView.cpp : implementation of the CSkeletonView class
//

#include "stdafx.h"
#include "Skeleton.h"

#include "SkeletonDoc.h"
#include "SkeletonView.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSkeletonView

IMPLEMENT_DYNCREATE(CSkeletonView, CView)

BEGIN_MESSAGE_MAP(CSkeletonView, CView)
	//{{AFX_MSG_MAP(CSkeletonView)
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
// CSkeletonView construction/destruction

CSkeletonView::CSkeletonView()
{
	// TODO: add construction code here

}

CSkeletonView::~CSkeletonView()
{
}

BOOL CSkeletonView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSkeletonView drawing

void CSkeletonView::OnDraw(CDC* pDC)
{
	CSkeletonDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CImage & img = pDoc->m_image;
	CRect r;
	GetClientRect(&r);
	r.SetRect(0,0,img.Width(),img.Height());
	img.DrawToHDC(pDC->GetSafeHdc(),r);
}

/////////////////////////////////////////////////////////////////////////////
// CSkeletonView printing

BOOL CSkeletonView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSkeletonView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSkeletonView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CSkeletonView diagnostics

#ifdef _DEBUG
void CSkeletonView::AssertValid() const
{
	CView::AssertValid();
}

void CSkeletonView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSkeletonDoc* CSkeletonView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSkeletonDoc)));
	return (CSkeletonDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSkeletonView message handlers

void CSkeletonView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default

	char	buf[50];
	//////////////////////////////////////////////////////////////////////////
	// 显示鼠标现在的位置
	
	sprintf(buf, "X:%d  Y:%d", point.x, point.y);
	((CMainFrame *)(AfxGetMainWnd()))->m_wndStatusBar.SetPaneText(0, buf);

	CView::OnMouseMove(nFlags, point);
}

void CSkeletonView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CSkeletonDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	if(pDoc->m_bmannal)
	{
		m_originpoint = point;
	}
	
	CView::OnLButtonDown(nFlags, point);
}

void CSkeletonView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default

	//m_bDraw = FALSE;
	//CClientDC dc(this);
	//dc.MoveTo(m_originpoint.x,m_originpoint.y);
	//dc.LineTo(point.x,point.y);
	
	CSkeletonDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	if(pDoc->m_bmannal)
	{
		pDoc->DrawLine(cvPoint(m_originpoint.x,m_originpoint.y),cvPoint(point.x,point.y));
	}
	
	CView::OnLButtonUp(nFlags, point);
}
