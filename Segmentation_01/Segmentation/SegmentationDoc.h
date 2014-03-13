// SegmentationDoc.h : interface of the CSegmentationDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SEGMENTATIONDOC_H__24B6602A_476F_4ABF_8649_325EBE0FD91E__INCLUDED_)
#define AFX_SEGMENTATIONDOC_H__24B6602A_476F_4ABF_8649_325EBE0FD91E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "highgui.h"
#include "cv.h"
#include "cxcore.h"
#include <fstream>
#include "iostream"

using namespace std;

class CSegmentationDoc : public CDocument
{
protected: // create from serialization only
	CSegmentationDoc();
	DECLARE_DYNCREATE(CSegmentationDoc)

// Attributes
public:
	CImage m_image;
	IplImage *s_img;
	IplImage *r_img;
	CvHistogram* s_hist;
	double s_threshold;
	IplImage *s_flag_image;
	IplImage *s_flag_open_image;
	IplImage *s_gradient_image;
	IplImage *s_gradient_flag_image;
	IplImage *border_image;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSegmentationDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSegmentationDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSegmentationDoc)
	afx_msg void OnMenuitemCanny();
	afx_msg void OnMenuitemGetscannels();
	afx_msg void OnMenuitemGetshistogram();
	afx_msg void OnMenuitemGetsostuthreshold();
	afx_msg void OnMenuitemGetsflagimage();
	afx_msg void OnMenuitemGetsflagimageopening();
	afx_msg void OnMenuitemGetgradient();
	afx_msg void OnMenuitemGetgradientflag();
	afx_msg void OnMenuitemGetwatershedopencv();
	afx_msg void OnMenuitemGetmaximumpoint();
	afx_msg void OnMenuitemGetsegmentationopencv();
	afx_msg void OnMenuitemGetoriginalsegmentationopencv();
	afx_msg void OnMenuitemGetssegmentationopencv();
	afx_msg void OnMenuitemGetrcannels();
	afx_msg void OnMenuitemGetrsegmentationopencv();
	afx_msg void OnMenuitemGetmorphologygradient();
	afx_msg void OnMenuitemGetcontourlinemanual();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SEGMENTATIONDOC_H__24B6602A_476F_4ABF_8649_325EBE0FD91E__INCLUDED_)
