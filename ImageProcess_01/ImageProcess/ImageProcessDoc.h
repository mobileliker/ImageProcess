// ImageProcessDoc.h : interface of the CImageProcessDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_IMAGEPROCESSDOC_H__5AFF4837_EFEA_4027_8C3C_A211055B9C53__INCLUDED_)
#define AFX_IMAGEPROCESSDOC_H__5AFF4837_EFEA_4027_8C3C_A211055B9C53__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define STYLE_IMAGE 0
#define STYLE_VIDEO 1

#include <vector>

using std::vector;

class CImageProcessDoc : public CDocument
{
protected: // create from serialization only
	CImageProcessDoc();
	DECLARE_DYNCREATE(CImageProcessDoc)

// Attributes
public:
	CvCapture *m_capture;
	CImage m_image;

	IplImage **m_frames;
	int m_frame_count;

	int type_flag;
	bool m_bmannal;

	double timeSpan;
	vector<double> v_timeSpan;

// Operations
public:
	void DrawLine(CvPoint p1,CvPoint p2);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CImageProcessDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CImageProcessDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CImageProcessDoc)
	afx_msg void OnMenuitemGetgrayimage();
	afx_msg void OnMenuitemSoybeangetgrayimage();
	afx_msg void OnMenuitemGetthresholdimageotsu();
	afx_msg void OnMenuitemSoybeangetthresholdimageotsu();
	afx_msg void OnMenuitemGetthresholdimagemannal();
	afx_msg void OnMenuitemSoybeangetthresholdimagemannal();
	afx_msg void OnMenuitemSoybeanrunallpretreatment();
	afx_msg void OnMenuitemGetthinimagemorphology();
	afx_msg void OnMenuitemGetreverseimage();
	afx_msg void OnMenuitemSoybeangetthinimagemorphology();
	afx_msg void OnMenuitemGetthinimagezhang();
	afx_msg void OnMenuitemSoybeangetthinimagezhang();
	afx_msg void OnMenuitemGetthinimageroseenfeld();
	afx_msg void OnMENUITEMGETTHINIMAGEDiSTANCE();
	afx_msg void OnMenuitemSoybeangetthinimagerosenfeld();
	afx_msg void OnMenuitemSoybeangetthinimagedistance();
	afx_msg void OnMenuitemGetsegmentationimagecanny();
	afx_msg void OnMenuitemSoybeangetsegmentationimagecanny();
	afx_msg void OnMenuitemGetsegmentationimagesobel();
	afx_msg void OnMenuitemSoybeangetsegmentationimagesobel();
	afx_msg void OnMenuitemCompleteisolatepoint();
	afx_msg void OnMenuitemGetallimagepoint();
	afx_msg void OnMenuitemSoybeancompleteisolationpoint();
	afx_msg void OnMENUITEMSoybeanCompleteEndPoint();
	afx_msg void OnMenuitemSoybeancompletemannal();
	afx_msg void OnMenuitemSoybeancalculatebarchdata();
	afx_msg void OnMenuitemSoybeancompleteauto();
	afx_msg void OnMenuitemZhangextendpretreatment();
	afx_msg void OnMenuitemZhangextendzhang();
	afx_msg void OnMenuitemZhangextendsinglepixel();
	afx_msg void OnMenuitemLicenseplategetgrayimage();
	afx_msg void OnMenuitemGetrgbchannelimage();
	afx_msg void OnMenuitemLincenseplategetrgbchannelimage();
	afx_msg void OnMenuitemGethsvchannelimage();
	afx_msg void OnMenuitemLicenseplategethsvchannelimage();
	afx_msg void OnMenuitemRobertoperator();
	afx_msg void OnMenuitemSmoothfiltering();
	afx_msg void OnMenuitemPrewittoperator();
	afx_msg void OnMenuitemLicenseplaterobertoperator();
	afx_msg void OnMenuitemSoybeangetsegmentationimagerobert();
	afx_msg void OnMenuitemSoybeangetsmoothimage();
	afx_msg void OnMenuitemSoybeanrunallpretreatmentsegmatation();
	afx_msg void OnMENUITEMSOYBEANGETSEGMENTATIONIMAGEPREWiTT();
	afx_msg void OnMenuitemLicenseplateprewittoperator();
	afx_msg void OnMENUITEMLicensePlateSobelOperator();
	afx_msg void OnMenuitemLicenseplatecannyoperator();
	afx_msg void OnMENUITEMGETHisTOGRAM();
	afx_msg void OnMenuitemBinarizationmode();
	afx_msg void OnMenuitemBinarizationmaxentropy();
	afx_msg void OnMenuitemBinarizationiteration();
	afx_msg void OnMenuitemSoybeangetthresholdimagemaxentropy();
	afx_msg void OnMenuitemSoybeangetthresholdimageiterator();
	afx_msg void OnMenuitemRotate();
	afx_msg void OnMenuitemOutputallpoint();
	afx_msg void OnMenuitemVideogray();
	afx_msg void OnMenuitemGetvideoinfo();
	afx_msg void OnMenuitemGetallimiage();
	afx_msg void OnMenuitemVideorotate();
	afx_msg void OnMenuitemVideoreverse();
	afx_msg void OnMenuitemVideogetrgbchannel();
	afx_msg void OnMenuitemVideosmoothfilter();
	afx_msg void OnMenuitemVideobinarationostu();
	afx_msg void OnMenuitemVideobinarationmaxentropy();
	afx_msg void OnMenuitemVideobinarizationiteration();
	afx_msg void OnMenuitemVideogetthinimagemorphology();
	afx_msg void OnMenuitemVideogetthinimagezhang();
	afx_msg void OnMenuitemVideogetthinimagerosenfeld();
	afx_msg void OnMenuitemVideogetthinimagedistance();
	afx_msg void OnMenuitemVideocannyoperator();
	afx_msg void OnMenuitemVideosobeloperator();
	afx_msg void OnMenuitemVideorobertoperator();
	afx_msg void OnMenuitemVideoprewittoperator();
	afx_msg void OnMenuitemGetthinimageqta();
	afx_msg void OnMenuitemGetthinimagehilditch();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IMAGEPROCESSDOC_H__5AFF4837_EFEA_4027_8C3C_A211055B9C53__INCLUDED_)
