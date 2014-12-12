// LicensePlateRecognitionMain.h: interface for the CLicensePlateRecognitionMain class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LICENSEPLATERECOGNITIONMAIN_H__B1794F9E_AE6F_4128_B836_D0E0AF4E20A8__INCLUDED_)
#define AFX_LICENSEPLATERECOGNITIONMAIN_H__B1794F9E_AE6F_4128_B836_D0E0AF4E20A8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <vector>
#include <queue>

#include "ColorTransform.h"
#include "ImageFilter.h"
#include "Binaryzation.h"

struct Point
{
	int y;
	int x;
};
struct Area
{
	int left;
	int right;
	int top;
	int bottom;
};

class CLicensePlateRecognitionMain  
{
public:
	static bool LPR_OTSU(const BYTE *src, BYTE *dst, const int height, const int width);
	BYTE * OTSU();
	static bool LPR_Gray(const BYTE *r, const BYTE *g, const BYTE *b, const int height, const int width, BYTE* imgData2);
	BYTE* Gray();
	static std::vector<Area> LPR_CoarseLocation(const BYTE *src, const int height, const int width);
	BYTE * CoarseLocation();
	static bool LPR_Morphology(const BYTE *src, BYTE *dst,  const int height, const int width, const int iterator);
	BYTE * Morphology();
	void init(BYTE* const imgData, const int height, const int width);
	CLicensePlateRecognitionMain(BYTE *_imgData,int _width, int _height);
	static bool LPR_HSVGray(const BYTE *r, const BYTE *g, const BYTE *b, const int width, const int height, BYTE *mg);
	BYTE* HSVGray();
	CLicensePlateRecognitionMain();
	virtual ~CLicensePlateRecognitionMain();

private:
	BYTE * m_imgData2;
	BYTE * m_imgData3;
	BYTE * m_mg3;
	BYTE * m_mg2;
	int m_height;
	int m_width;
	BYTE* m_imgData;
	BYTE* m_mg;
	Area m_area;

};

#endif // !defined(AFX_LICENSEPLATERECOGNITIONMAIN_H__B1794F9E_AE6F_4128_B836_D0E0AF4E20A8__INCLUDED_)
