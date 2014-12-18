// Binaryzation.cpp: implementation of the CBinaryzation class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ImageProcess.h"
#include "Binaryzation.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CBinaryzation::CBinaryzation()
{

}

CBinaryzation::~CBinaryzation()
{

}

int CBinaryzation::OTSU(const BYTE *src, const int height, const int width)
{
	//int width = frame->width;
	//int height = frame->height;
	const int GrayScale = 255;
	int pixelCount[GrayScale];
	double pixelPro[GrayScale];
	int i, j, pixelSum = width * height, threshold = 0;

	for(i = 0; i < GrayScale; i++)
	{
		pixelCount[i] = 0;
		pixelPro[i] = 0;
	}

	//统计灰度级中每个像素在整幅图像中的个数
	for(i = 0; i < height; i++)
	{
		for(j = 0;j < width;j++)
		{
			pixelCount[(int)src[i * width + j]]++;
		}
	}
	
	//计算每个像素在整幅图像中的比例
	for(i = 0; i < GrayScale; i++)
	{
		pixelPro[i] = (double)pixelCount[i] / pixelSum;
	}

	//遍历灰度级[0,255]
	double w0, w1, u0tmp, u1tmp, u0, u1, u, 
			deltaTmp, deltaMax = 0;
	for(i = 0; i < GrayScale; i++)
	{
		w0 = w1 = u0tmp = u1tmp = u0 = u1 = u = deltaTmp = 0;
		for(j = 0; j < GrayScale; j++)
		{
			if(j <= i)   //背景部分
			{
				w0 += pixelPro[j];
				u0tmp += j * pixelPro[j];
			}
			else   //前景部分
			{
				w1 += pixelPro[j];
				u1tmp += j * pixelPro[j];
			}
		}
		u0 = u0tmp / w0;
		u1 = u1tmp / w1;
		u = u0tmp + u1tmp;
		deltaTmp = 
			w0 * pow((u0 - u), 2) + w1 * pow((u1 - u), 2);
		if(deltaTmp > deltaMax)
		{
			deltaMax = deltaTmp;
			threshold = i;
		}
	}
	return threshold;
}

int CBinaryzation::OTSU(const BYTE *src, const int height, const int width, const BYTE *mark)
{	
	//int width = frame->width;
	//int height = frame->height;
	const int GrayScale = 255;
	int pixelCount[GrayScale];
	double pixelPro[GrayScale];
	int i, j, pixelSum = width * height, threshold = 0;

	for(i = 0; i < GrayScale; i++)
	{
		pixelCount[i] = 0;
		pixelPro[i] = 0;
	}

	//统计灰度级中每个像素在整幅图像中的个数
	for(i = 0; i < height; i++)
	{
		for(j = 0;j < width;j++)
		{
			if(mark[i *width + j] == 0)
				pixelCount[(int)src[i * width + j]]++;
		}
	}
	
	//计算每个像素在整幅图像中的比例
	for(i = 0; i < GrayScale; i++)
	{
		pixelPro[i] = (double)pixelCount[i] / pixelSum;
	}

	//遍历灰度级[0,255]
	double w0, w1, u0tmp, u1tmp, u0, u1, u, 
			deltaTmp, deltaMax = 0;
	for(i = 0; i < GrayScale; i++)
	{
		w0 = w1 = u0tmp = u1tmp = u0 = u1 = u = deltaTmp = 0;
		for(j = 0; j < GrayScale; j++)
		{
			if(j <= i)   //背景部分
			{
				w0 += pixelPro[j];
				u0tmp += j * pixelPro[j];
			}
			else   //前景部分
			{
				w1 += pixelPro[j];
				u1tmp += j * pixelPro[j];
			}
		}
		u0 = u0tmp / w0;
		u1 = u1tmp / w1;
		u = u0tmp + u1tmp;
		deltaTmp = 
			w0 * pow((u0 - u), 2) + w1 * pow((u1 - u), 2);
		if(deltaTmp > deltaMax)
		{
			deltaMax = deltaTmp;
			threshold = i;
		}
	}
	return threshold;
}
