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

void CVeinProcess::Denoising()
{
	m_mg2 = cvCreateImage(cvGetSize(m_mg1), m_mg1->depth, m_mg1->nChannels);
	cvSmooth(m_mg1, m_mg2, CV_MEDIAN);
}

void CVeinProcess::OTSU()
{
	m_mg3 = cvCreateImage(cvGetSize(m_mg2), m_mg2->depth, m_mg2->nChannels);
	cvThreshold(m_mg2, m_mg3, 1, 255, CV_THRESH_OTSU);
}

void CVeinProcess::Location()
{
	int y, x;

	int left = m_mg3->width - 1, right = 0;
	int top = m_mg3->height - 1, bottom = 0;
	for(y = 0; y < m_mg3->height; ++y)
	{
		for(x = 0; x < m_mg3->width; ++x)
		{
			CvScalar scalar = cvGet2D(m_mg3, y, x);
			if(0 == scalar.val[0])
			{
				if(left > x) left = x;
				if(right < x) right = x;
				if(top > y) top = y;
				if(bottom < y) bottom = y;
			}
		}
	}

	int dst_height = bottom - top + 1;
	int dst_width = right - left + 1;
	m_dst1 = cvCreateImage(cvSize(dst_width, dst_height), m_mg2->depth, m_mg2->nChannels);
	m_mg4 = cvCreateImage(cvSize(dst_width, dst_height), m_mg2->depth, m_mg2->nChannels);

	for(y = 0; y < dst_height; ++y)
	{
		for(x = 0; x < dst_width; ++x)
		{
			CvScalar s1 = cvGet2D(m_mg2, y + top, x + left);
			cvSet2D(m_dst1, y, x, s1);

			CvScalar s2 = cvGet2D(m_mg3, y + top, x + left);
			cvSet2D(m_mg4, y, x, s2);
		}
	}
}

void CVeinProcess::OTSU2()
{
	int y, x;

	BYTE *src = new BYTE[m_dst1->width * m_dst1->height];
	BYTE *mark = new BYTE[m_mg4->width * m_mg4->height];

	for(y = 0; y < m_dst1->height; ++y)
	{
		for(x = 0; x < m_dst1->width; ++x)
		{
			CvScalar s1 = cvGet2D(m_dst1, y, x);
			src[y * m_dst1->width + x] = (BYTE)s1.val[0];

			CvScalar s2 = cvGet2D(m_mg4, y, x);
			mark[y * m_mg4->width + x] = (BYTE)s2.val[0];
		}
	}

	int value = CBinaryzation::OTSU(src, m_dst1->height, m_dst1->width, mark);

	m_dst2 = cvCreateImage(cvGetSize(m_dst1), m_dst1->depth, m_dst1->nChannels);
	cvZero(m_dst2);
	for(y = 0; y < m_dst1->height; ++y)
	{
		for(x = 0; x < m_dst1->width; ++x)
		{
			CvScalar scalar = cvGet2D(m_dst1, y, x);
			if(value < scalar.val[0]) scalar.val[0] = 255;
			cvSet2D(m_dst2, y, x, scalar);
		}
	}

	delete [] src;
	delete [] mark;
}
