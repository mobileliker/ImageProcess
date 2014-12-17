// VeinProcess.cpp: implementation of the CVeinProcess class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ImageProcess.h"
#include "VeinProcess.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CVeinProcess::CVeinProcess()
{

}

CVeinProcess::~CVeinProcess()
{

}

void CVeinProcess::init(IplImage *src)
{
	m_src = cvCreateImage(cvGetSize(src), src->depth, src->nChannels);
	cvCopy(src, m_src);
}

void CVeinProcess::channelizing()
{
	
	m_mg1 = cvCreateImage(cvGetSize(m_src), IPL_DEPTH_8U, 1);
	cvCvtColor(m_src, m_mg1, CV_RGB2GRAY);
}
