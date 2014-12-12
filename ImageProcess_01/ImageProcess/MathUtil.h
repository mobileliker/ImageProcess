// MathUtil.h: interface for the CMathUtil class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MATHUTIL_H__112105C3_8A82_4E53_8486_9696A8E7D8FC__INCLUDED_)
#define AFX_MATHUTIL_H__112105C3_8A82_4E53_8486_9696A8E7D8FC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMathUtil  
{
public:
	static bool AntiNormalization(const double *src,BYTE *dst,const int length,const int maxValue,const int minValue);
	static bool Normalization(const int *src,double *dst,const int length,const int maxValue,const int minValue);
	static double Min(const double a,const double b);
	static double Max(const double a, const double b);
	static bool Normalization(const BYTE *src,double *dst,const int length,const int maxValue,const int minValue);
	CMathUtil();
	virtual ~CMathUtil();

};

#endif // !defined(AFX_MATHUTIL_H__112105C3_8A82_4E53_8486_9696A8E7D8FC__INCLUDED_)
