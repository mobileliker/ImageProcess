// VeinProcess.h: interface for the CVeinProcess class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_VEINPROCESS_H__C863E319_2D42_4711_BC59_6D4BCB1F1ABD__INCLUDED_)
#define AFX_VEINPROCESS_H__C863E319_2D42_4711_BC59_6D4BCB1F1ABD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "highgui.h"
#include "cv.h"
#include "cxcore.h"

#include "Binaryzation.h"

class CVeinProcess  
{
public:
	IplImage *m_dst2;
	IplImage *m_mg4;
	IplImage *m_dst1;
	void OTSU2();
	void Location();
	void OTSU();
	void Denoising();
	void channelizing();
	void init(IplImage *src);
	IplImage *m_src;
	IplImage *m_mg1;
	IplImage *m_mg2;
	IplImage *m_mg3;
	CVeinProcess();
	virtual ~CVeinProcess();

};

#endif // !defined(AFX_VEINPROCESS_H__C863E319_2D42_4711_BC59_6D4BCB1F1ABD__INCLUDED_)
