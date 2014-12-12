// LicensePlateRecognitionMain.cpp: implementation of the CLicensePlateRecognitionMain class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ImageProcess.h"
#include "LicensePlateRecognitionMain.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CLicensePlateRecognitionMain::CLicensePlateRecognitionMain()
{

}

CLicensePlateRecognitionMain::CLicensePlateRecognitionMain(BYTE *_imgData, int _width, int _height)
{
	m_imgData = _imgData;
	m_width = _width;
	m_height = _height;
}

CLicensePlateRecognitionMain::~CLicensePlateRecognitionMain()
{

}


void CLicensePlateRecognitionMain::init(BYTE* const imgData, const int height, const int width)
{
	//if(m_imgData != NULL) delete [] m_imgData;
	m_imgData = imgData;
	m_height = height;
	m_width = width;
}

bool CLicensePlateRecognitionMain::LPR_HSVGray(const BYTE *r, const BYTE *g, const BYTE *b, const int width, const int height, BYTE *mg)//mg means mark_gray
{
	int x,y;

	int flag = true;

	int *h = new int[width * height];
	double *s = new double[width * height];
	double *v = new double[width * height];

	memset(mg, 0, sizeof(BYTE) * width * height);

	if(CColorTransform::RGB2HSV(r, g, b, h, s, v, width, height))
	{
		for(y = 0;y < height; ++y)
		{
			for(x = 0; x < width; ++x)
			{
				int i = y * width + x;
				if(h[i] >= 178 && h[i] <= 240 && s[i] >= 0.45 && s[i] <= 1 && v[i] >= 0.15 && v[i] <=1.0) mg[i] = 255;
				if(h[i] >= 25 && h[i] <= 90 && s[i] >= 0.29 && s[i] <= 1 && v[i] >= 0.1 && v[i] <= 1.0) mg[i] = 128;
			}
		}
	}
	else flag = false;


	delete [] v;
	delete [] s;
	delete [] h;

	return true;
}

BYTE* CLicensePlateRecognitionMain::HSVGray()
{
	BYTE *r = new BYTE[m_width * m_height];
	BYTE *g = new BYTE[m_width * m_height];
	BYTE *b = new BYTE[m_width * m_height];

	for(int i = 0; i < m_width * m_height; ++i)
	{
		r[i] = m_imgData[i * 3];
		g[i] = m_imgData[i * 3 + 1];
		b[i] = m_imgData[i * 3 + 2];
	}

	//if(m_mg != NULL) delete [] m_mg;
	m_mg = new BYTE[m_width * m_height];

	CLicensePlateRecognitionMain::LPR_HSVGray(r,g,b,m_width,m_height,m_mg);

	delete [] b;
	delete [] g;
	delete [] r;

	return m_mg;
}


bool CLicensePlateRecognitionMain::LPR_Morphology(const BYTE *src, BYTE *dst, const int height, const int width,const int iterator)
{
	int y, x;
	int yy, xx;
	int n_x, n_y;
	int i;
	const int size = 5;

	BYTE *dst1 = new BYTE[height * width];

	if(!CImageFilter::MedianFilter(src, dst1, height, width, 3)) return false;

	


	BYTE *dst2 = new BYTE[height * width];
	
	bool flag;
	for(i = 0; i < iterator; ++i)
	{	
		flag = false;

		//Dilate
		n_x = 5;
		n_y = 2;
		memset(dst2, 0, sizeof(BYTE) * width * height);
		for(y = n_y + size; y < height - n_y - size; ++y)
		{
			for(x = n_x + size; x < width - n_x - size; ++x)
			{
				for(yy = -n_y; yy <= n_y; ++yy)
				{
					for(xx = -n_x; xx <= n_x; ++xx)
					{
						if(dst1[(y + yy) * width + (x + xx)] != 0) break;
					}
					if(xx <= n_x) break;
				}
				if(yy <= n_y)
				{
					dst2[y * width + x] = dst1[(y + yy) * width + (x + xx)];
					flag = true;
				}
				else dst2[y * width + x] = 0;
			}
		}

		//Erode
		n_x = 2;
		n_y = 2;

		memset(dst, 0, sizeof(BYTE) * width * height);
		for(y = n_y + size; y < height - n_y - size; ++y)
		{
			for(x = n_x + size; x < width - n_x - size; ++x)
			{
				for(yy = -n_y; yy <= n_y; ++yy)
				{
					for(xx = -n_x; xx <= n_x; ++xx)
					{
						if(dst2[(y + yy) * width + (x + xx)] == 0) break;
					}
					if(xx <= n_x) break;
				}
				if(yy <= n_y)
				{
					dst[y * width + x] = 0;
					flag = true;
				}
				else dst[y * width + x] = dst2[(y + yy) * width + (x + xx)];
			}
		}

		if(!flag) break;
		
		memcpy(dst1, dst, sizeof(BYTE) * width * height);
	}



	delete [] dst2;

	delete [] dst1;

	return true;
}

BYTE * CLicensePlateRecognitionMain::Morphology()
{
	m_mg2 = new BYTE[m_width * m_height];

	CLicensePlateRecognitionMain::LPR_Morphology(m_mg, m_mg2, m_height, m_width, 1);

	return m_mg2;
}



BYTE * CLicensePlateRecognitionMain::CoarseLocation()
{	
	int y, x;
	int i;
	const int ex_point = 5;
	const int size = 5;

	m_mg3 = new BYTE[m_width * m_height * 3];

	std::vector<Area> v_area = CLicensePlateRecognitionMain::LPR_CoarseLocation(m_mg2, m_height, m_width);

	m_area = v_area[0];
	int min_area = (m_area.right - m_area.left) * (m_area.bottom - m_area.top);
	for(i = 1; i < v_area.size(); ++i)
	{
		int area_area = (v_area[i].right - v_area[i].left) * (v_area[i].bottom - v_area[i].top);
		if(min_area > area_area)
		{
			m_area = v_area[i];
			min_area = area_area;
		}
	}

	memset(m_mg3, 0, sizeof(BYTE) * m_width * m_height * 3);

	//extend area
	m_area.top = (m_area.top - ex_point >= size) ? m_area.top - ex_point : size;
	m_area.bottom = (m_area.bottom + ex_point < m_height - size) ? m_area.bottom + ex_point : m_height - size - 1;
	m_area.left = (m_area.left - ex_point >= size) ? m_area.left - ex_point : size;
	m_area.right = (m_area.right + ex_point < m_width - size) ? m_area.right + ex_point : m_width - size - 1;


	for(y = m_area.top; y <= m_area.bottom; ++y)
	{
		for(x = m_area.left; x <= m_area.right; ++x)
		{
			for(i = 0; i < 3; ++i)	m_mg3[(y * m_width + x) * 3 + i] = m_imgData[(y * m_width + x) * 3 + i];
		}
	}

	return m_mg3;
}



std::vector<Area> CLicensePlateRecognitionMain::LPR_CoarseLocation(const BYTE *src, const int height, const int width)
{
	std::vector<Area> v_area;

	int y,x;
	const int size = 5;
	int i;

	int *arr_mark = new int[width * height];
	memset(arr_mark, 0, sizeof(int) * width * height);


	int idx_flag = 1;
	for(y = size; y < height - size; ++y)
	{
		for(x = size; x < width - size; ++x)
		{
			if(src[y * width + x] != 0 && arr_mark[y * width + x] == 0)
			{
				Area area;
				area.left = x;
				area.right = x;
				area.top = y;
				area.bottom = y;

				std::queue<Point> q_point;
				Point p;
				p.x = x;
				p.y = y;
				arr_mark[y * width + x] = idx_flag;
				q_point.push(p);

				int idx_x[] = {0, -1, 0, 1};
				int idx_y[] = {-1, 0, 1, 0};
				int idx_n = 4;

				while(!q_point.empty())
				{
					p = q_point.front();
					q_point.pop();

					if(area.left > p.x) area.left = p.x;
					if(area.right < p.x) area.right = p.x;
					if(area.top > p.y) area.top = p.y;
					if(area.bottom < p.y) area.bottom = p.y;

					for(i = 0; i < idx_n; ++i)
					{
						if((p.y + idx_y[i]) < size || (p.y + idx_y[i]) >= (height - size) || (p.x + idx_x[i]) < size || (p.x + idx_x[i]) >= (width - size)) continue;
						if(src[(p.y + idx_y[i]) * width + (p.x + idx_x[i])] != 0 && arr_mark[(p.y + idx_y[i]) * width + (p.x + idx_x[i])] == 0)
						{
							Point pp;
							pp.x = p.x + idx_x[i];
							pp.y = p.y + idx_y[i];
							arr_mark[(p.y + idx_y[i]) * width + (p.x + idx_x[i])] = idx_flag;
							q_point.push(pp);
						}
					}
				}

				if((area.right - area.left) * (area.bottom - area.top) >= 1500 
					&& 1.5 * (area.bottom - area.top) <= (area.right - area.left)
					&& (area.right - area.left) <= 5.5 * (area.bottom - area.top))
				v_area.push_back(area);
				idx_flag++;
			}
		}
	}


	//CString filePath;
	//char szFilter[] = {"Text Files (*.txt)|*.txt||"};
	//CFileDialog dlg(FALSE,"txt","image_parameter",OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,szFilter,NULL);

	//if(dlg.DoModal() == IDOK)
	//{
	//	filePath = dlg.GetFileName();
	
	//	//AfxMessageBox(filePath);

	//	ofstream ipfile(filePath);

	//	for(i = 0; i < v_area.size(); ++i)
	//	{
	//		Area area = v_area[i];
	//		ipfile << (area.right - area.left) * (area.bottom - area.top) << endl;

	//	}

	//	ipfile.close();



	//	AfxMessageBox("Finish GetImageParameter");
	//}

	delete [] arr_mark;

	//return true;
	return v_area;
}

BYTE* CLicensePlateRecognitionMain::Gray()
{
	int y, x;
	int i;

	BYTE *r = new BYTE[m_width * m_height];
	BYTE *g = new BYTE[m_width * m_height];
	BYTE *b = new BYTE[m_width * m_height];

	//for(int i = 0; i < m_width * m_height; ++i)
	//{
	//	r[i] = m_imgData[i * 3];
	//	g[i] = m_imgData[i * 3 + 1];
	//	b[i] = m_imgData[i * 3 + 2];
	//}

	memset(r, 0, sizeof(BYTE) * m_width * m_height);
	memset(g, 0, sizeof(BYTE) * m_width * m_height);
	memset(b, 0, sizeof(BYTE) * m_width * m_height);

	for(y = m_area.top; y <= m_area.bottom; ++y)
	{
		for(x = m_area.left; x <= m_area.right; ++x)
		{
			i = y * m_width + x;
			r[i] = m_imgData[i * 3];
			g[i] = m_imgData[i * 3 + 1];
			b[i] = m_imgData[i * 3 + 2];
		}
	}
	

	//if(m_mg != NULL) delete [] m_mg;
	m_imgData2 = new BYTE[m_width * m_height];

	CLicensePlateRecognitionMain::LPR_Gray(r, g, b, m_height, m_width, m_imgData2);

	delete [] b;
	delete [] g;
	delete [] r;

	return m_imgData2;
}

bool CLicensePlateRecognitionMain::LPR_Gray(const BYTE *r, const BYTE *g, const BYTE *b, const int height, const int width, BYTE* imgData2)
{
	return CColorTransform::RGB2Gray(r, g, b, imgData2, height, width);
}




BYTE * CLicensePlateRecognitionMain::OTSU()
{
	BYTE *src = new BYTE[(m_area.bottom - m_area.top + 1) * (m_area.right - m_area.left + 1)];
	BYTE *dst = new BYTE[(m_area.bottom - m_area.top + 1) * (m_area.right - m_area.left + 1)];

	int y;
	for(y = m_area.top; y <= m_area.bottom; ++y)
	{
		memcpy(&src[(y - m_area.top) * (m_area.right - m_area.left + 1)], &m_imgData2[y * m_width + m_area.left], sizeof(BYTE) * (m_area.right - m_area.left + 1));
	}

	CLicensePlateRecognitionMain::LPR_OTSU(src, dst, m_area.bottom - m_area.top + 1, m_area.right - m_area.left + 1);

	m_imgData3 = new BYTE[m_width * m_height];
	memset(m_imgData3, 0, sizeof(BYTE) * m_width * m_height);

	for(y = m_area.top; y <= m_area.bottom; ++y)
	{
		memcpy(&m_imgData3[y * m_width + m_area.left], &dst[(y - m_area.top) * (m_area.right - m_area.left + 1)], sizeof(BYTE) * (m_area.right - m_area.left + 1));
	}

	delete [] dst;
	delete [] src;

	return m_imgData3;
}

bool CLicensePlateRecognitionMain::LPR_OTSU(const BYTE *src, BYTE *dst, const int height, const int width)
{
	int y, x;

	int threshold = CBinaryzation::OTSU(src, height, width);

	for(y = 0; y < height; ++y)
	{
		for(x = 0; x < width; ++x)
		{
			if(src[y * width + x] < threshold) dst[y * width + x] = 255;
			else dst[y * width + x] = 0;
		}
	}

	return true;
}
