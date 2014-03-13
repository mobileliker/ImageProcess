// VideoReadTestDoc.h : interface of the CVideoReadTestDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_VIDEOREADTESTDOC_H__86DF90D0_171E_4C63_B0A0_B03B428ECC67__INCLUDED_)
#define AFX_VIDEOREADTESTDOC_H__86DF90D0_171E_4C63_B0A0_B03B428ECC67__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CVideoReadTestDoc : public CDocument
{
protected: // create from serialization only
	CVideoReadTestDoc();
	DECLARE_DYNCREATE(CVideoReadTestDoc)

// Attributes
public:
	CvCapture* capture;
	CImage m_image;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVideoReadTestDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CVideoReadTestDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CVideoReadTestDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:

};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIDEOREADTESTDOC_H__86DF90D0_171E_4C63_B0A0_B03B428ECC67__INCLUDED_)
