// SkeletonDoc.h : interface of the CSkeletonDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SKELETONDOC_H__0127A8F6_9FD2_4E90_97B9_8C44A6E861C5__INCLUDED_)
#define AFX_SKELETONDOC_H__0127A8F6_9FD2_4E90_97B9_8C44A6E861C5__INCLUDED_

#include "highgui.h"
#include "cv.h"
#include "cxcore.h"
#include <vector>

using std::vector;

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSkeletonDoc : public CDocument
{
protected: // create from serialization only
	CSkeletonDoc();
	DECLARE_DYNCREATE(CSkeletonDoc)

// Attributes
public:
	CImage m_image;
	IplImage *b_image;
	IplImage *smooth_image;
	IplImage *threshold_image;
	IplImage *thin_image;
	IplImage *gray_image;

	CvCapture *m_capture;
	int type_flag;

	vector<int> isolate_point_frame;
	vector<int> isolate_point_x;
	vector<int> isolate_point_y;

	vector<int> end_point_frame;
	vector<int> end_point_x;
	vector<int> end_point_y;

	vector<int> brach_point_frame;
	vector<int> brach_point_x;
	vector<int> brach_point_y;

	bool m_bmannal;

// Operations
public:
	void DrawLine(CvPoint p1,CvPoint p2);
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSkeletonDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSkeletonDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSkeletonDoc)
	afx_msg void OnMenuitemGetbcannels();
	afx_msg void OnMenuitemGetsmoothimage();
	afx_msg void OnMenuitemGetthresholdimageostu();
	afx_msg void OnMenuitemGetthresholdimagemannal();
	afx_msg void OnMenuitemGetthinimage();
	afx_msg void OnMenuitemGetthinimagezhang();
	afx_msg void OnMenuitemGetthinimageroseenfeld();
	afx_msg void OnMenuitemGetgrayimage();
	afx_msg void OnMenuitemGetthinimagedistance();
	afx_msg void OnMenuitemRootgetthresholdimageostu();
	afx_msg void OnMenuitemRootgetthresholdimagemannal();
	afx_msg void OnMenuitemGetisolatepoint();
	afx_msg void OnMenuitemCompleteisolate();
	afx_msg void OnMenuitemGetendpoint();
	afx_msg void OnMenuitemCompleteend();
	afx_msg void OnMenuitemGetbrach();
	afx_msg void OnMenuitemCalbrachdata();
	afx_msg void OnMenuitemAll();
	afx_msg void OnMenuitemCompletemannal();
	afx_msg void OnMenuitemSaveimage();
	afx_msg void OnMenuitemSoybeangetgrayimage();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SKELETONDOC_H__0127A8F6_9FD2_4E90_97B9_8C44A6E861C5__INCLUDED_)
