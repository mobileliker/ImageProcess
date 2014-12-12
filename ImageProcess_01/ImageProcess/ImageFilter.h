// ImageFilter.h: interface for the CImageFilter class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_IMAGEFILTER_H__2C5E7937_C519_4014_98C9_FF574382308F__INCLUDED_)
#define AFX_IMAGEFILTER_H__2C5E7937_C519_4014_98C9_FF574382308F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CImageFilter  
{
public:
	static bool MedianFilter(const BYTE *src, BYTE *dst, const int height, const int width, const int size);
	static bool MedianFilter(const BYTE *src, BYTE *dst, const int height, const int width, const int channel,  const int size);
	CImageFilter();
	virtual ~CImageFilter();

};

#endif // !defined(AFX_IMAGEFILTER_H__2C5E7937_C519_4014_98C9_FF574382308F__INCLUDED_)
