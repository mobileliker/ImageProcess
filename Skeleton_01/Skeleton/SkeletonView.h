// SkeletonView.h : interface of the CSkeletonView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SKELETONVIEW_H__5C07FC8D_EFB6_44F1_A4C0_99AE66D3932E__INCLUDED_)
#define AFX_SKELETONVIEW_H__5C07FC8D_EFB6_44F1_A4C0_99AE66D3932E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSkeletonView : public CView
{
protected: // create from serialization only
	CSkeletonView();
	DECLARE_DYNCREATE(CSkeletonView)

// Attributes
public:
	CSkeletonDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSkeletonView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	CPoint m_originpoint;
	BOOL m_bDraw;
	virtual ~CSkeletonView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSkeletonView)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in SkeletonView.cpp
inline CSkeletonDoc* CSkeletonView::GetDocument()
   { return (CSkeletonDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SKELETONVIEW_H__5C07FC8D_EFB6_44F1_A4C0_99AE66D3932E__INCLUDED_)
