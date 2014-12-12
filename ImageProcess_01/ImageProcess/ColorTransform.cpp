// ColorTransform.cpp: implementation of the CColorTransform class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ImageProcess.h"
#include "ColorTransform.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CColorTransform::CColorTransform()
{

}

CColorTransform::~CColorTransform()
{

}

bool CColorTransform::RGB2HSV(const BYTE *r, const BYTE *g, const BYTE *b, int *h, double *s, double *v, const int width, const int height)
{
	int i;

	if(r == NULL || g == NULL || b == NULL) return false;

	double *dr = new double[width * height];
	double *dg = new double[width * height];
	double *db = new double[width * height];

	if(!CColorTransform::RGBNormalization(r, g, b, dr, dg, db, width, height)) return false;

	//ofstream normalization_file("D://log/normalization_res.txt");
	//for(i = 0; i < width * height; ++i) normalization_file << "(" << (int)r[i] << "," << (int)g[i] << "," << (int)b[i] << ")" << "-->" << "(" << dr[i] << "," << dg[i] << "," << db[i] << ")" << endl;
	//normalization_file.close();

	for(i = 0; i < width * height; ++i)
	{
		double max_rgb = MaxRGB(dr[i],dg[i],db[i]);
		double min_rgb = MinRGB(dr[i],dg[i],db[i]);

		double temp_h;
		if(dr[i] == max_rgb) temp_h = (dg[i] - db[i]) / (max_rgb - min_rgb);
		else if(dg[i] == max_rgb) temp_h = 2 + (db[i] - dr[i]) / (max_rgb - min_rgb);
		else temp_h = 4 + (dr[i] - dg[i]) / (max_rgb - min_rgb);
		h[i] = ((int)(temp_h * 60) + 360) % 360;

		v[i] = max_rgb;

		s[i] = (max_rgb - min_rgb) / max_rgb;
		
	}

	delete [] dr;
	delete [] dg;
	delete [] db;

	return true;
}

bool CColorTransform::RGBNormalization(const BYTE *r, const BYTE *g, const BYTE *b, double *dr, double *dg, double *db, const int width, const int height)
{
	if(!CMathUtil::Normalization(r, dr, width * height, 255, 0)) return false;
	if(!CMathUtil::Normalization(g, dg, width * height, 255, 0)) return false;
	if(!CMathUtil::Normalization(b, db, width * height, 255, 0)) return false;
	return true;
}

double CColorTransform::MaxRGB(const double r, const double g, const double b)
{
	return CMathUtil::Max(CMathUtil::Max(r,g),b);
}

double CColorTransform::MinRGB(const double r, const double g, const double b)
{
	return CMathUtil::Min(CMathUtil::Min(r,g),b);
}

bool CColorTransform::RGB2Gray(const BYTE *r, const BYTE *g, const BYTE *b, BYTE *gray, const int height, const int width)
{
	int y, x;

	if(r == NULL || g == NULL || b == NULL) return false;

	for(y = 0; y < height; ++y)
	{
		for(x = 0; x < width; ++x)
		{
			int idx = y * width + x;
			gray[idx] = (r[idx] + g[idx] + b[idx]) / 3;
		}
	}
	return true;
}
