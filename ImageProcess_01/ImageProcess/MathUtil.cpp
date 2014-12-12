// MathUtil.cpp: implementation of the CMathUtil class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ImageProcess.h"
#include "MathUtil.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMathUtil::CMathUtil()
{

}

CMathUtil::~CMathUtil()
{

}

bool CMathUtil::Normalization(const BYTE *src, double *dst, const int length, const int maxValue, const int minValue)
{
	if(src == NULL || dst == NULL) return false;

	for(int i = 0; i < length; ++i) dst[i] = (double)(src[i] - minValue) / (maxValue - minValue);

	return true;
}

double CMathUtil::Max(const double a, const double b)
{
	return (a>b)?a:b;
}

double CMathUtil::Min(const double a, const double b)
{
	return (a<b)?a:b;
}

bool CMathUtil::Normalization(const int *src, double *dst, const int length, const int maxValue, const int minValue)
{
	if(src == NULL || dst == NULL) return false;

	for(int i = 0; i < length; ++i) dst[i] = (double)(src[i] - minValue) / (maxValue - minValue);

	return true;
}

bool CMathUtil::AntiNormalization(const double *src, BYTE *dst, const int length, const int maxValue, const int minValue)
{
	if(src == NULL || dst == NULL) return false;

	for(int i = 0; i < length; ++i) dst[i] = (BYTE)(minValue + (maxValue - minValue) * src[i]);

	return true;
}
