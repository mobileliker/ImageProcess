// SegmentationView.h : interface of the CSegmentationView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SEGMENTATIONVIEW_H__B2584966_0D67_4044_84B7_28ADDBBBB55D__INCLUDED_)
#define AFX_SEGMENTATIONVIEW_H__B2584966_0D67_4044_84B7_28ADDBBBB55D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSegmentationView : public CView
{
protected: // create from serialization only
	CSegmentationView();
	DECLARE_DYNCREATE(CSegmentationView)

// Attributes
public:
	CSegmentationDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSegmentationView)
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
	virtual ~CSegmentationView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSegmentationView)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in SegmentationView.cpp
inline CSegmentationDoc* CSegmentationView::GetDocument()
   { return (CSegmentationDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SEGMENTATIONVIEW_H__B2584966_0D67_4044_84B7_28ADDBBBB55D__INCLUDED_)
