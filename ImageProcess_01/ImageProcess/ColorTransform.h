// ColorTransform.h: interface for the CColorTransform class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COLORTRANSFORM_H__C2BDDAE5_FF10_4CEF_9020_E11476151B0C__INCLUDED_)
#define AFX_COLORTRANSFORM_H__C2BDDAE5_FF10_4CEF_9020_E11476151B0C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MathUtil.h"

class CColorTransform  
{
public:
	static bool RGB2Gray(const BYTE *r, const BYTE *g,const BYTE *b,BYTE *gray, const int height, const int width);
	static bool RGB2HSV(const BYTE *r,const BYTE *g,const BYTE *b,int *h, double *s, double *v,const int width,const int height);
	CColorTransform();
	virtual ~CColorTransform();

private:
	static double MinRGB(const double r, const double g, const double b);
	static double MaxRGB(const double r, const double g, const double b);
	static bool RGBNormalization(const BYTE *r, const BYTE *g, const BYTE *b, double *dr, double *dg, double *db, const int width, const int height);
};

#endif // !defined(AFX_COLORTRANSFORM_H__C2BDDAE5_FF10_4CEF_9020_E11476151B0C__INCLUDED_)
