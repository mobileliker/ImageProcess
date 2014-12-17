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

class CVeinProcess  
{
public:
	void channelizing();
	void init(IplImage *src);
	IplImage * m_src;
	IplImage * m_mg1;
	CVeinProcess();
	virtual ~CVeinProcess();

};

#endif // !defined(AFX_VEINPROCESS_H__C863E319_2D42_4711_BC59_6D4BCB1F1ABD__INCLUDED_)
