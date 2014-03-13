// VideoReadTestView.h : interface of the CVideoReadTestView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_VIDEOREADTESTVIEW_H__76AEAE8E_7E71_4FAC_836C_2F078AC48CED__INCLUDED_)
#define AFX_VIDEOREADTESTVIEW_H__76AEAE8E_7E71_4FAC_836C_2F078AC48CED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CVideoReadTestView : public CView
{
protected: // create from serialization only
	CVideoReadTestView();
	DECLARE_DYNCREATE(CVideoReadTestView)

// Attributes
public:
	CVideoReadTestDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVideoReadTestView)
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
	virtual ~CVideoReadTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CVideoReadTestView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in VideoReadTestView.cpp
inline CVideoReadTestDoc* CVideoReadTestView::GetDocument()
   { return (CVideoReadTestDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIDEOREADTESTVIEW_H__76AEAE8E_7E71_4FAC_836C_2F078AC48CED__INCLUDED_)
