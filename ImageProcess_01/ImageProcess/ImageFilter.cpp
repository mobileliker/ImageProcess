// ImageFilter.cpp: implementation of the CImageFilter class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ImageProcess.h"
#include "ImageFilter.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CImageFilter::CImageFilter()
{

}

CImageFilter::~CImageFilter()
{

}
int cmp(const void*a, const void *b)
{
	return *(BYTE *)a - *(BYTE *)b;
}

bool CImageFilter::MedianFilter(const BYTE *src, BYTE *dst, const int height, const int width, const int channel, const int size)
{
	int i, x, y, k;

	//size must odd integer
	if(size % 2 == 0) return false;

	const int idx_x[] = {0, 1, 1, 1, 0, -1, -1, -1};
	const int idx_y[] = {-1, -1, 0, 1, 1, 1, 0, -1};
	const int idx_num = 8;

	BYTE arr_p[idx_num + 1];
	for(y = size / 2; y < height - size / 2; ++y)
	{
		for(x = size / 2; x < width - size / 2; ++x)
		{
			for(k = 0; k < channel; ++k)
			{
				arr_p[0] = src[(y * width + x) * channel + k];
				for(i = 0; i < idx_num; ++i) arr_p[1 + i] = src[((y + idx_y[i]) * width + (x + idx_x[i])) * channel + k];
				qsort(arr_p, idx_num + 1, sizeof(BYTE), cmp);
				dst[(y * width + x) * channel + k] = arr_p[size * size / 2];
			}
		}
	}

	return true;
}

bool CImageFilter::MedianFilter(const BYTE *src, BYTE *dst, const int height, const int width, const int size)
{
	return CImageFilter::MedianFilter(src, dst, height, width, 1, size);
}
