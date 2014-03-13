// ImageProcessDoc.cpp : implementation of the CImageProcessDoc class
//

#include "stdafx.h"
#include "ImageProcess.h"

#include "ImageProcessDoc.h"

#include <fstream.h>
#include <vector>
#include <queue>

#include "SelectThresholdDialog.h"
#include "SelectRGBChannelDialog.h"
#include "SelectHSVChannelDialog.h"
#include "SelectSize.h"
#include "SlectCalculateStyleDialog.h"
#include "SelectRotateDialog.h"

#include <vfw.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using std::vector;
using std::queue;

/////////////////////////////////////////////////////////////////////////////
// CImageProcessDoc

IMPLEMENT_DYNCREATE(CImageProcessDoc, CDocument)

BEGIN_MESSAGE_MAP(CImageProcessDoc, CDocument)
	//{{AFX_MSG_MAP(CImageProcessDoc)
	ON_COMMAND(ID_MENUITEM_GETGRAYIMAGE, OnMenuitemGetgrayimage)
	ON_COMMAND(ID_MENUITEM_SOYBEANGETGRAYIMAGE, OnMenuitemSoybeangetgrayimage)
	ON_COMMAND(ID_MENUITEM_GETTHRESHOLDIMAGEOTSU, OnMenuitemGetthresholdimageotsu)
	ON_COMMAND(ID_MENUITEM_SOYBEANGETTHRESHOLDIMAGEOTSU, OnMenuitemSoybeangetthresholdimageotsu)
	ON_COMMAND(ID_MENUITEM_GETTHRESHOLDIMAGEMANNAL, OnMenuitemGetthresholdimagemannal)
	ON_COMMAND(ID_MENUITEM_SOYBEANGETTHRESHOLDIMAGEMANNAL, OnMenuitemSoybeangetthresholdimagemannal)
	ON_COMMAND(ID_MENUITEM_SOYBEANRUNALLPRETREATMENT, OnMenuitemSoybeanrunallpretreatment)
	ON_COMMAND(ID_MENUITEM_GETTHINIMAGEMORPHOLOGY, OnMenuitemGetthinimagemorphology)
	ON_COMMAND(ID_MENUITEM_GETREVERSEIMAGE, OnMenuitemGetreverseimage)
	ON_COMMAND(ID_MENUITEM_SOYBEANGETTHINIMAGEMORPHOLOGY, OnMenuitemSoybeangetthinimagemorphology)
	ON_COMMAND(ID_MENUITEM_GETTHINIMAGEZHANG, OnMenuitemGetthinimagezhang)
	ON_COMMAND(ID_MENUITEM_SOYBEANGETTHINIMAGEZHANG, OnMenuitemSoybeangetthinimagezhang)
	ON_COMMAND(ID_MENUITEM_GETTHINIMAGEROSEENFELD, OnMenuitemGetthinimageroseenfeld)
	ON_COMMAND(ID_MENUITEM_GETTHINIMAGEDiSTANCE, OnMENUITEMGETTHINIMAGEDiSTANCE)
	ON_COMMAND(ID_MENUITEM_SOYBEANGETTHINIMAGEROSENFELD, OnMenuitemSoybeangetthinimagerosenfeld)
	ON_COMMAND(ID_MENUITEM_SOYBEANGETTHINIMAGEDISTANCE, OnMenuitemSoybeangetthinimagedistance)
	ON_COMMAND(ID_MENUITEM_GETSEGMENTATIONIMAGECANNY, OnMenuitemGetsegmentationimagecanny)
	ON_COMMAND(ID_MENUITEM_SOYBEANGETSEGMENTATIONIMAGECANNY, OnMenuitemSoybeangetsegmentationimagecanny)
	ON_COMMAND(ID_MENUITEM_GETSEGMENTATIONIMAGESOBEL, OnMenuitemGetsegmentationimagesobel)
	ON_COMMAND(ID_MENUITEM_SOYBEANGETSEGMENTATIONIMAGESOBEL, OnMenuitemSoybeangetsegmentationimagesobel)
	ON_COMMAND(ID_MENUITEM_COMPLETEISOLATEPOINT, OnMenuitemCompleteisolatepoint)
	ON_COMMAND(ID_MENUITEM_GETALLIMAGEPOINT, OnMenuitemGetallimagepoint)
	ON_COMMAND(ID_MENUITEM_SOYBEANCOMPLETEISOLATIONPOINT, OnMenuitemSoybeancompleteisolationpoint)
	ON_COMMAND(ID_MENUITEM_SoybeanCompleteEndPoint, OnMENUITEMSoybeanCompleteEndPoint)
	ON_COMMAND(ID_MENUITEM_SOYBEANCOMPLETEMANNAL, OnMenuitemSoybeancompletemannal)
	ON_COMMAND(ID_MENUITEM_SOYBEANCALCULATEBARCHDATA, OnMenuitemSoybeancalculatebarchdata)
	ON_COMMAND(ID_MENUITEM_SOYBEANCOMPLETEAUTO, OnMenuitemSoybeancompleteauto)
	ON_COMMAND(ID_MENUITEM_ZHANGEXTENDPRETREATMENT, OnMenuitemZhangextendpretreatment)
	ON_COMMAND(ID_MENUITEM_ZHANGEXTENDZHANG, OnMenuitemZhangextendzhang)
	ON_COMMAND(ID_MENUITEM_ZHANGEXTENDSINGLEPIXEL, OnMenuitemZhangextendsinglepixel)
	ON_COMMAND(ID_MENUITEM_LICENSEPLATEGETGRAYIMAGE, OnMenuitemLicenseplategetgrayimage)
	ON_COMMAND(ID_MENUITEM_GETRGBCHANNELIMAGE, OnMenuitemGetrgbchannelimage)
	ON_COMMAND(ID_MENUITEM_LINCENSEPLATEGETRGBCHANNELIMAGE, OnMenuitemLincenseplategetrgbchannelimage)
	ON_COMMAND(ID_MENUITEM_GETHSVCHANNELIMAGE, OnMenuitemGethsvchannelimage)
	ON_COMMAND(ID_MENUITEM_LICENSEPLATEGETHSVCHANNELIMAGE, OnMenuitemLicenseplategethsvchannelimage)
	ON_COMMAND(ID_MENUITEM_ROBERTOPERATOR, OnMenuitemRobertoperator)
	ON_COMMAND(ID_MENUITEM_SMOOTHFILTERING, OnMenuitemSmoothfiltering)
	ON_COMMAND(ID_MENUITEM_PREWITTOPERATOR, OnMenuitemPrewittoperator)
	ON_COMMAND(ID_MENUITEM_LICENSEPLATEROBERTOPERATOR, OnMenuitemLicenseplaterobertoperator)
	ON_COMMAND(ID_MENUITEM_SOYBEANGETSEGMENTATIONIMAGEROBERT, OnMenuitemSoybeangetsegmentationimagerobert)
	ON_COMMAND(ID_MENUITEM_SOYBEANGETSMOOTHIMAGE, OnMenuitemSoybeangetsmoothimage)
	ON_COMMAND(ID_MENUITEM_SOYBEANRUNALLPRETREATMENTSEGMATATION, OnMenuitemSoybeanrunallpretreatmentsegmatation)
	ON_COMMAND(ID_MENUITEM_SOYBEANGETSEGMENTATIONIMAGEPREWiTT, OnMENUITEMSOYBEANGETSEGMENTATIONIMAGEPREWiTT)
	ON_COMMAND(ID_MENUITEM_LICENSEPLATEPREWITTOPERATOR, OnMenuitemLicenseplateprewittoperator)
	ON_COMMAND(ID_MENUITEM_LicensePlateSobelOperator, OnMENUITEMLicensePlateSobelOperator)
	ON_COMMAND(ID_MENUITEM_LICENSEPLATECANNYOPERATOR, OnMenuitemLicenseplatecannyoperator)
	ON_COMMAND(ID_MENUITEM_GETHisTOGRAM, OnMENUITEMGETHisTOGRAM)
	ON_COMMAND(ID_MENUITEM_BINARIZATIONMODE, OnMenuitemBinarizationmode)
	ON_COMMAND(ID_MENUITEM_BINARIZATIONMAXENTROPY, OnMenuitemBinarizationmaxentropy)
	ON_COMMAND(ID_MENUITEM_BINARIZATIONITERATION, OnMenuitemBinarizationiteration)
	ON_COMMAND(ID_MENUITEM_SOYBEANGETTHRESHOLDIMAGEMAXENTROPY, OnMenuitemSoybeangetthresholdimagemaxentropy)
	ON_COMMAND(ID_MENUITEM_SOYBEANGETTHRESHOLDIMAGEITERATOR, OnMenuitemSoybeangetthresholdimageiterator)
	ON_COMMAND(ID_MENUITEM_ROTATE, OnMenuitemRotate)
	ON_COMMAND(ID_MENUITEM_OUTPUTALLPOINT, OnMenuitemOutputallpoint)
	ON_COMMAND(ID_MENUITEM_VIDEOGRAY, OnMenuitemVideogray)
	ON_COMMAND(ID_MENUITEM_GETVIDEOINFO, OnMenuitemGetvideoinfo)
	ON_COMMAND(ID_MENUITEM_GETALLIMIAGE, OnMenuitemGetallimiage)
	ON_COMMAND(ID_MENUITEM_VIDEOROTATE, OnMenuitemVideorotate)
	ON_COMMAND(ID_MENUITEM_VIDEOREVERSE, OnMenuitemVideoreverse)
	ON_COMMAND(ID_MENUITEM_VIDEOGETRGBCHANNEL, OnMenuitemVideogetrgbchannel)
	ON_COMMAND(ID_MENUITEM_VIDEOSMOOTHFILTER, OnMenuitemVideosmoothfilter)
	ON_COMMAND(ID_MENUITEM_VIDEOBINARATIONOSTU, OnMenuitemVideobinarationostu)
	ON_COMMAND(ID_MENUITEM_VIDEOBINARATIONMAXENTROPY, OnMenuitemVideobinarationmaxentropy)
	ON_COMMAND(ID_MENUITEM_VIDEOBINARIZATIONITERATION, OnMenuitemVideobinarizationiteration)
	ON_COMMAND(ID_MENUITEM_VIDEOGETTHINIMAGEMORPHOLOGY, OnMenuitemVideogetthinimagemorphology)
	ON_COMMAND(ID_MENUITEM_VIDEOGETTHINIMAGEZHANG, OnMenuitemVideogetthinimagezhang)
	ON_COMMAND(ID_MENUITEM_VIDEOGETTHINIMAGEROSENFELD, OnMenuitemVideogetthinimagerosenfeld)
	ON_COMMAND(ID_MENUITEM_VIDEOGETTHINIMAGEDISTANCE, OnMenuitemVideogetthinimagedistance)
	ON_COMMAND(ID_MENUITEM_VIDEOCANNYOPERATOR, OnMenuitemVideocannyoperator)
	ON_COMMAND(ID_MENUITEM_VIDEOSOBELOPERATOR, OnMenuitemVideosobeloperator)
	ON_COMMAND(ID_MENUITEM_VIDEOROBERTOPERATOR, OnMenuitemVideorobertoperator)
	ON_COMMAND(ID_MENUITEM_VIDEOPREWITTOPERATOR, OnMenuitemVideoprewittoperator)
	ON_COMMAND(ID_MENUITEM_GETTHINIMAGEQTA, OnMenuitemGetthinimageqta)
	ON_COMMAND(ID_MENUITEM_GETTHINIMAGEHILDITCH, OnMenuitemGetthinimagehilditch)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CImageProcessDoc construction/destruction

CImageProcessDoc::CImageProcessDoc()
{
	// TODO: add one-time construction code here
	m_bmannal = FALSE;
}

CImageProcessDoc::~CImageProcessDoc()
{
}

BOOL CImageProcessDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CImageProcessDoc serialization

void CImageProcessDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CImageProcessDoc diagnostics

#ifdef _DEBUG
void CImageProcessDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CImageProcessDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CImageProcessDoc commands

//manul add
bool CheckExtendName(const char *pszStr,const char *pszExd)
{ 
 char *pt=(char*)pszStr;
 
 pt +=strlen(pszStr);
 while(pt!=(char*)pszStr && *pt-- !='.');

 if(*(++pt) !='.')
  return false;
 pt++;

  //将比较字符和传入的后缀名转为小写
 if(strcmp(_strlwr(pt),_strlwr((char *)pszExd))==0)
 {
  return true;
 }
 else
 { 
  return false;
 }
}


BOOL CImageProcessDoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;
	
	// TODO: Add your specialized creation code here
	if(CheckExtendName(lpszPathName,"bmp") || CheckExtendName(lpszPathName,"jpg"))
	{
		this->type_flag = STYLE_IMAGE;
		m_image.Load(lpszPathName);
	}	
	else if(CheckExtendName(lpszPathName,"avi"))
	{
		this->type_flag = STYLE_VIDEO;

		m_capture = cvCreateFileCapture(lpszPathName);

		m_frame_count = cvGetCaptureProperty(m_capture,CV_CAP_PROP_FRAME_COUNT);
		m_frames = new IplImage*[m_frame_count];

		IplImage *lp_frame;
		for(int i = 0; i < m_frame_count; ++i)
		{
			lp_frame = cvQueryFrame(m_capture);
			
			m_frames[i] = cvCloneImage(lp_frame);
			/*m_frames[i] = cvCreateImage(cvGetSize(lp_frame),IPL_DEPTH_8U,3);
			for(int y = 0; y < lp_frame->height; ++y)
			{
				for(int x = 0; x < lp_frame->width; ++x)
				{
					CvScalar scalar = cvGet2D(lp_frame,y,x);
					cvSet2D(m_frames[i],y,x,scalar);
				}
			}*/
		}
		m_image.CopyOf(m_frames[0],m_frames[0]->nChannels);
	}
	else
	{
		AfxMessageBox("The File Format isn't supported.");
	}
	
	return TRUE;
}

void fix_saveavi_error(IplImage * src,IplImage *dst)
{
	int y,x;
	for(y = 0; y < src->height; ++y)
	{
		for(x = 0; x < src->width; ++x)
		{
			CvScalar scalar = cvGet2D(src,y,x);
			cvSet2D(dst,y,(x + src->width / 2) % src->width,scalar);
		}
	}
	return;
}

BOOL CImageProcessDoc::OnSaveDocument(LPCTSTR lpszPathName) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(type_flag == STYLE_IMAGE) m_image.Save(lpszPathName);
	else
	{
		CvVideoWriter *writer;
		writer = cvCreateVideoWriter(lpszPathName,cvGetCaptureProperty(m_capture,CV_CAP_PROP_FOURCC),
			cvGetCaptureProperty(m_capture,CV_CAP_PROP_FPS),
			cvSize(cvGetCaptureProperty(m_capture,CV_CAP_PROP_FRAME_WIDTH),cvGetCaptureProperty(m_capture,CV_CAP_PROP_FRAME_HEIGHT)),
			1);

		IplImage* lp_frame;

		for(int i = 0; i < m_frame_count; ++i)
		{
			 cvWriteFrame(writer,m_frames[i]);
		}

		cvReleaseVideoWriter(&writer);
	}

	return TRUE;

	//return CDocument::OnSaveDocument(lpszPathName);
}

void CImageProcessDoc::OnMenuitemGetgrayimage() 
{
	// TODO: Add your command handler code here

	IplImage *pImg = m_image.GetImage();
	
	DWORD start_time = GetTickCount();

	IplImage *gray_image = cvCreateImage(cvGetSize(pImg),IPL_DEPTH_8U,1);

	cvCvtColor(pImg,gray_image,CV_RGB2GRAY);
		
	if(gray_image->origin != pImg->origin) {gray_image->origin = pImg->origin;}

	DWORD end_time = GetTickCount();


	/*int x,y;
	CvScalar scalar;
	ofstream outfile1("D://log/gray_image_point.txt");
	for(x = 0; x < gray_image->width; x++)
	{
		for(y = 0; y < gray_image->height; y++)
		{
			scalar = cvGet2D(gray_image,y,x);
			outfile1<<"x="<<x<<",y="<<y<<",value="<<scalar.val[0]<<endl;
		}
	}
	outfile1.close();*/

	m_image.CopyOf(gray_image,gray_image->nChannels);

	cvSaveImage("D://log/gray_image.bmp",gray_image);

	UpdateAllViews(NULL);

	timeSpan = end_time - start_time;

	//AfxMessageBox("Finish Get Gray Image.");
}

void CImageProcessDoc::OnMenuitemSoybeangetgrayimage() 
{
	// TODO: Add your command handler code here
	if(type_flag == STYLE_VIDEO)
	{
		OnMenuitemVideogray();
		if(v_timeSpan.size() != 0)
		{
			ofstream res_file("D://log/res_time.txt");

			double total_timeSpan = 0.0;
			for(int i = 0; i < v_timeSpan.size(); ++i)
			{
				total_timeSpan += v_timeSpan[i];
				res_file << "frameNum = " << i << " , timeSpan = " << v_timeSpan[i] << " ms" << endl;
			}
			res_file.close();
		
			char str[200];
			sprintf(str,"Finish Get Gray Image.Use time:%lf ms",total_timeSpan);
			AfxMessageBox(str);
		}

	}
	else if(type_flag == STYLE_IMAGE)
	{
		timeSpan = -1.0;

		OnMenuitemGetgrayimage();

		if(timeSpan != -1.0)
		{
			ofstream res_file("D://log/res_time.txt");
			res_file << timeSpan << " ms" << endl;
			res_file << timeSpan / 1000 << " s" << endl;
			res_file.close();

			char str[200];
			sprintf(str,"Finish Get Gray Image.Total Use time:%lf ms",timeSpan);
			AfxMessageBox(str);
		}
	}


}

void CImageProcessDoc::OnMenuitemGetthresholdimageotsu() 
{
	// TODO: Add your command handler code here
	IplImage *pImg = m_image.GetImage();

	IplImage *threshold_image = cvCreateImage(cvGetSize(pImg),IPL_DEPTH_8U,3);
	if(threshold_image->origin != pImg->origin) threshold_image->origin == pImg->origin;

	DWORD start_time = GetTickCount();
	cvThreshold(pImg,threshold_image,1,255,CV_THRESH_OTSU);
	DWORD end_time = GetTickCount();

	/*int x,y;
	CvScalar scalar;
	ofstream outfile1("D://log/threshold_image_point.txt");
	for(x = 0; x < threshold_image->width; x++)
	{
		for(y = 0; y < threshold_image->height; y++)
		{
			scalar = cvGet2D(threshold_image,y,x);
			outfile1<<"x="<<x<<",y="<<y<<",value="<<scalar.val[0]<<endl;
		}
	}
	outfile1.close();*/

	m_image.CopyOf(threshold_image,threshold_image->nChannels);

	cvSaveImage("D://log/threshold_image.bmp",threshold_image);

	UpdateAllViews(NULL);

	timeSpan = end_time - start_time;

	//AfxMessageBox("Finish Get threshold Image(OTSU).");
}

void CImageProcessDoc::OnMenuitemSoybeangetthresholdimageotsu() 
{
	// TODO: Add your command handler code here
	if(type_flag == STYLE_VIDEO)
	{
		OnMenuitemVideobinarationostu();
		if(v_timeSpan.size() != 0)
		{
			ofstream res_file("D://log/res_time.txt");

			double total_timeSpan = 0.0;
			for(int i = 0; i < v_timeSpan.size(); ++i)
			{
				total_timeSpan += v_timeSpan[i];
				res_file << "frameNum = " << i << " , timeSpan = " << v_timeSpan[i] << " ms" << endl;
			}
			res_file.close();
		
			char str[200];
			sprintf(str,"Finish Get threshold Image(OTSU)Use time:%lf ms",total_timeSpan);
			AfxMessageBox(str);
		}

	}
	else if(type_flag == STYLE_IMAGE)
	{
		timeSpan = -1.0;

		OnMenuitemGetthresholdimageotsu();

		if(timeSpan != -1.0)
		{
			ofstream res_file("D://log/res_time.txt");
			res_file << timeSpan << " ms" << endl;
			res_file << timeSpan / 1000 << " s" << endl;
			res_file.close();

			char str[200];
			sprintf(str,"Finish Get threshold Image(OTSU).Use time:%lf ms",timeSpan);
			AfxMessageBox(str);
		}
	}
}

static double
icvGetThreshVal_Otsu( const CvHistogram* hist )
{
    double max_val = 0;
    
    CV_FUNCNAME( "icvGetThreshVal_Otsu" );

    __BEGIN__;

    int i, count;
    const float* h;
    double sum = 0, mu = 0;
    bool uniform = false;
    double low = 0, high = 0, delta = 0;
    float* nu_thresh = 0;
    double mu1 = 0, q1 = 0;
    double max_sigma = 0;

    if( !CV_IS_HIST(hist) || CV_IS_SPARSE_HIST(hist) || hist->mat.dims != 1 )
        CV_ERROR( CV_StsBadArg,
        "The histogram in Otsu method must be a valid dense 1D histogram" );

    count = hist->mat.dim[0].size;
    h = (float*)cvPtr1D( hist->bins, 0 );

    if( !CV_HIST_HAS_RANGES(hist) || CV_IS_UNIFORM_HIST(hist) )
    {
        if( CV_HIST_HAS_RANGES(hist) )
        {
            low = hist->thresh[0][0];
            high = hist->thresh[0][1];
        }
        else
        {
            low = 0;
            high = count;
        }

        delta = (high-low)/count;
        low += delta*0.5;
        uniform = true;
    }
    else
        nu_thresh = hist->thresh2[0];

    for( i = 0; i < count; i++ )
    {
        sum += h[i];
        if( uniform )
            mu += (i*delta + low)*h[i];
        else
            mu += (nu_thresh[i*2] + nu_thresh[i*2+1])*0.5*h[i];
    }
    
    sum = fabs(sum) > FLT_EPSILON ? 1./sum : 0;
    mu *= sum;

    mu1 = 0;
    q1 = 0;

    for( i = 0; i < count; i++ )
    {
        double p_i, q2, mu2, val_i, sigma;

        p_i = h[i]*sum;
        mu1 *= q1;
        q1 += p_i;
        q2 = 1. - q1;

        if( MIN(q1,q2) < FLT_EPSILON || MAX(q1,q2) > 1. - FLT_EPSILON )
            continue;

        if( uniform )
            val_i = i*delta + low;
        else
            val_i = (nu_thresh[i*2] + nu_thresh[i*2+1])*0.5;

        mu1 = (mu1 + val_i*p_i)/q1;
        mu2 = (mu - q1*mu1)/q2;
        sigma = q1*q2*(mu1 - mu2)*(mu1 - mu2);
        if( sigma > max_sigma )
        {
            max_sigma = sigma;
            max_val = val_i;
        }
    }

    __END__;

    return max_val;
}

void CImageProcessDoc::OnMenuitemGetthresholdimagemannal() 
{
	// TODO: Add your command handler code here
	IplImage *pImg = m_image.GetImage();
	
	IplImage* r_plane = cvCreateImage( cvGetSize(pImg), 8, 1 );
	IplImage* g_plane = cvCreateImage( cvGetSize(pImg), 8, 1 );
	IplImage* b_plane = cvCreateImage( cvGetSize(pImg), 8, 1 );
	cvSplit(pImg,r_plane,g_plane,b_plane,0);

	IplImage *threshold_image = cvCreateImage(cvGetSize(r_plane),IPL_DEPTH_8U,1);

	//cal threshold reference value
	int hist_size = 256;
	int hist_height = 256;
	int hist_sizes[] = {hist_size};
	float range[] = {0,255};
	float* ranges[] = {range};


	CvHistogram *s_hist = cvCreateHist(1,hist_sizes,CV_HIST_ARRAY,ranges,1);//create
	cvCalcHist(&r_plane,s_hist,0,0);
	cvNormalizeHist(s_hist,1.0);

	double threshold = icvGetThreshVal_Otsu(s_hist);
	cvReleaseHist(&s_hist);
	int threshold_type = 0;

	CSelectThresholdDialog dialog;
	dialog.m_threshold = threshold;
	dialog.m_threshold_type = threshold_type;


	if(dialog.DoModal() == IDOK)
	{
		threshold = dialog.m_threshold;
		threshold_type = dialog.m_threshold_type;

		
		DWORD start_time = GetTickCount();
		if(threshold_type == 0)
		{
			cvThreshold(r_plane,threshold_image,threshold,255,CV_THRESH_BINARY);
		}
		else
		{
			cvThreshold(r_plane,threshold_image,threshold,255,CV_THRESH_BINARY_INV);
		}
		DWORD end_time = GetTickCount();

		//int x,y;
		//CvScalar scalar;
		//ofstream outfile1("D://log/threshold_image_point.txt");
		//for(x = 0; x < threshold_image->width; x++)
		//{
		//	for(y = 0; y < threshold_image->height; y++)
		//	{
		//		scalar = cvGet2D(threshold_image,y,x);
		//		outfile1<<"x="<<x<<",y="<<y<<",value="<<scalar.val[0]<<endl;
		//	}
		//}
		//outfile1.close();

		m_image.CopyOf(threshold_image,threshold_image->nChannels);

		cvSaveImage("D://log/threshold_image.bmp",threshold_image);

		UpdateAllViews(NULL);

		timeSpan = end_time - start_time;

		//AfxMessageBox("Finish Get threshold Image(Mannal).");
	}


}

void CImageProcessDoc::OnMenuitemSoybeangetthresholdimagemannal() 
{
	// TODO: Add your command handler code here
	timeSpan = -1.0;

	OnMenuitemGetthresholdimagemannal();

	if(timeSpan != -1.0)
	{
		ofstream res_file("D://log/res_time.txt");
		res_file << timeSpan << " ms" << endl;
		res_file << timeSpan / 1000 << " s" << endl;
		res_file.close();

		char str[200];
		sprintf(str,"Finish Get threshold Image(Mannal).Use time:%lf ms",timeSpan);
		AfxMessageBox(str);
	}
}

void CImageProcessDoc::OnMenuitemSoybeanrunallpretreatment() 
{
	// TODO: Add your command handler code here
	OnMenuitemSoybeangetgrayimage();
	OnMenuitemSoybeangetthresholdimageotsu();
}

void CImageProcessDoc::OnMenuitemGetreverseimage() 
{
	// TODO: Add your command handler code here
	IplImage *pImg = m_image.GetImage();

	DWORD start_time = GetTickCount();
	cvNot(pImg,pImg);
	DWORD end_time = GetTickCount();

	cvSaveImage("D://log/Reverse_image.bmp",pImg);

	UpdateAllViews(NULL);

	timeSpan = end_time - start_time;
}


void cvThin( IplImage* src, IplImage* dst, int iterations=1)
{
 CvSize size = cvGetSize(src);

 cvCopy(src, dst);
    int n = 0,i = 0,j = 0;
 for(n=0; n<iterations; n++)
 {
  IplImage* t_image = cvCloneImage(dst);
  for(i=0; i<size.height;  i++)
  {
   for(j=0; j<size.width; j++)
   {
    if(CV_IMAGE_ELEM(t_image,byte,i,j)==1)
    {
     int ap=0;
     int p2 = (i==0)?0:CV_IMAGE_ELEM(t_image,byte, i-1, j);
     int p3 = (i==0 || j==size.width-1)?0:CV_IMAGE_ELEM(t_image,byte, i-1, j+1);
     if (p2==0 && p3==1)
     {
      ap++;
     }
     int p4 = (j==size.width-1)?0:CV_IMAGE_ELEM(t_image,byte,i,j+1);
     if(p3==0 && p4==1)
     {
      ap++;
     }
     int p5 = (i==size.height-1 || j==size.width-1)?0:CV_IMAGE_ELEM(t_image,byte,i+1,j+1);
     if(p4==0 && p5==1)
     {
      ap++;
     }
     int p6 = (i==size.height-1)?0:CV_IMAGE_ELEM(t_image,byte,i+1,j);
     if(p5==0 && p6==1)
     {
      ap++;
     }
     int p7 = (i==size.height-1 || j==0)?0:CV_IMAGE_ELEM(t_image,byte,i+1,j-1);
     if(p6==0 && p7==1)
     {
      ap++;
     }
     int p8 = (j==0)?0:CV_IMAGE_ELEM(t_image,byte,i,j-1);
     if(p7==0 && p8==1)
     {
      ap++;
     }
     int p9 = (i==0 || j==0)?0:CV_IMAGE_ELEM(t_image,byte,i-1,j-1);
     if(p8==0 && p9==1)
     {
      ap++;
     }
     if(p9==0 && p2==1)
     {
      ap++;
     }
     if((p2+p3+p4+p5+p6+p7+p8+p9)>1 && (p2+p3+p4+p5+p6+p7+p8+p9)<7)
     {
      if(ap==1)
      {
       if(!(p2 && p4 && p6))
       {
        if(!(p4 && p6 && p8))
        {
         CV_IMAGE_ELEM(dst,byte,i,j)=0;
        }
       }
      }
     }

    }
   }
  }
  cvReleaseImage(&t_image);
  t_image = cvCloneImage(dst);
  for(i=0; i<size.height;  i++)
  {
   for(int j=0; j<size.width; j++)
   {
    if(CV_IMAGE_ELEM(t_image,byte,i,j)==1)
    {
     int ap=0;
     int p2 = (i==0)?0:CV_IMAGE_ELEM(t_image,byte, i-1, j);
     int p3 = (i==0 || j==size.width-1)?0:CV_IMAGE_ELEM(t_image,byte, i-1, j+1);
     if (p2==0 && p3==1)
     {
      ap++;
     }
     int p4 = (j==size.width-1)?0:CV_IMAGE_ELEM(t_image,byte,i,j+1);
     if(p3==0 && p4==1)
     {
      ap++;
     }
     int p5 = (i==size.height-1 || j==size.width-1)?0:CV_IMAGE_ELEM(t_image,byte,i+1,j+1);
     if(p4==0 && p5==1)
     {
      ap++;
     }
     int p6 = (i==size.height-1)?0:CV_IMAGE_ELEM(t_image,byte,i+1,j);
     if(p5==0 && p6==1)
     {
      ap++;
     }
     int p7 = (i==size.height-1 || j==0)?0:CV_IMAGE_ELEM(t_image,byte,i+1,j-1);
     if(p6==0 && p7==1)
     {
      ap++;
     }
     int p8 = (j==0)?0:CV_IMAGE_ELEM(t_image,byte,i,j-1);
     if(p7==0 && p8==1)
     {
      ap++;
     }
     int p9 = (i==0 || j==0)?0:CV_IMAGE_ELEM(t_image,byte,i-1,j-1);
     if(p8==0 && p9==1)
     {
      ap++;
     }
     if(p9==0 && p2==1)
     {
      ap++;
     }
     if((p2+p3+p4+p5+p6+p7+p8+p9)>1 && (p2+p3+p4+p5+p6+p7+p8+p9)<7)
     {
      if(ap==1)
      {
       if(p2*p4*p8==0)
       {
        if(p2*p6*p8==0)
        {
         CV_IMAGE_ELEM(dst, byte,i,j)=0;
        }
       }
      }
     }                   
    }

   }

  }           
  cvReleaseImage(&t_image);
 }

}

void CImageProcessDoc::OnMenuitemGetthinimagemorphology() 
{
	// TODO: Add your command handler code here
	IplImage *pImg = m_image.GetImage();
	
	IplImage* r_plane = cvCreateImage( cvGetSize(pImg), 8, 1 );
	IplImage* g_plane = cvCreateImage( cvGetSize(pImg), 8, 1 );
	IplImage* b_plane = cvCreateImage( cvGetSize(pImg), 8, 1 );

	if(r_plane->origin != pImg->origin) r_plane->origin = pImg->origin;
	if(g_plane->origin != pImg->origin) g_plane->origin = pImg->origin;
	if(b_plane->origin != pImg->origin) b_plane->origin = pImg->origin;

	cvSplit(pImg,r_plane,g_plane,b_plane,0);

	DWORD start_time = GetTickCount();

	IplImage *thin_image = cvCreateImage(cvGetSize(r_plane),IPL_DEPTH_8U,1);
	IplImage *tmp_image = cvCreateImage(cvGetSize(r_plane),IPL_DEPTH_8U,1);

	if(thin_image->origin != r_plane->origin) thin_image->origin = r_plane->origin;
	if(tmp_image->origin != r_plane->origin) tmp_image->origin = r_plane->origin;

	cvConvertScale(r_plane,tmp_image,1.0/255.0);

	cvThin(tmp_image,thin_image,8);
	cvConvertScale(thin_image,thin_image,255.0);

	DWORD end_time = GetTickCount();

	m_image.CopyOf(thin_image,thin_image->nChannels);

	cvSaveImage("D://log/thin_image_morphology.bmp",thin_image);

	UpdateAllViews(NULL);

	cvReleaseImage(&tmp_image);

	timeSpan = end_time - start_time;
}


void CImageProcessDoc::OnMenuitemSoybeangetthinimagemorphology() 
{	
	if(type_flag == STYLE_VIDEO)
	{
		OnMenuitemVideoreverse();
		OnMenuitemVideogetthinimagemorphology();
		vector<double> temp_v_timeSpan = v_timeSpan;
		OnMenuitemVideoreverse();
		v_timeSpan = temp_v_timeSpan;

		if(v_timeSpan.size() != 0)
		{
			ofstream res_file("D://log/res_time.txt");

			double total_timeSpan = 0.0;
			for(int i = 0; i < v_timeSpan.size(); ++i)
			{
				total_timeSpan += v_timeSpan[i];
				res_file << "frameNum = " << i << " , timeSpan = " << v_timeSpan[i] << " ms" << endl;
			}
			res_file.close();
		
			char str[200];
			sprintf(str,"Finish Get Thin Image(Morphology)Use time:%lf ms",total_timeSpan);
			AfxMessageBox(str);
		}
	}
	else if(type_flag == STYLE_IMAGE)
	{
		OnMenuitemGetreverseimage();
		timeSpan = -1.0;
		OnMenuitemGetthinimagemorphology();
		double temp_timeSpan = timeSpan;
		OnMenuitemGetreverseimage();
		timeSpan = temp_timeSpan;
		if(timeSpan != -1.0)
		{
			ofstream res_file("D://log/res_time.txt");
			res_file << timeSpan << " ms" << endl;
			res_file << timeSpan / 1000 << " s" << endl;
			res_file.close();

			char str[200];
			sprintf(str,"Finish Get Thin Image(Morphology)Use time:%lf ms",timeSpan);
			AfxMessageBox(str);
		}
	}


	
}

//source : http://blog.sina.com.cn/s/blog_6f611c3001017y5m.html
void ZhangThinning(int w,int h,BYTE *imgBuf)

{

    int neighbor[8];

 

    BYTE *mark=new BYTE[w*h];

    memset(mark,0,w*h);

 

    BOOL loop=TRUE;

    int x,y,k;

    int markNum=0;

 

    while(loop)

    {

       loop=FALSE;

 

       //第一步

       markNum=0;

       for(y=1;y<h-1;y++)

       {

           for(x=1;x<w-1;x++)

           {

              //条件1：p必须是前景点

              if(imgBuf[y*w+x]==0 ) continue;

 

              neighbor[0]= imgBuf[y*w+x+1] ;

              neighbor[1]= imgBuf[(y-1)*w+x+1];

              neighbor[2]= imgBuf[(y-1)*w+x];

              neighbor[3]= imgBuf[(y-1)*w+x-1];

              neighbor[4]= imgBuf[y*w+x-1];

              neighbor[5]= imgBuf[(y+1)*w+x-1];

              neighbor[6]= imgBuf[(y+1)*w+x];

              neighbor[7]= imgBuf[(y+1)*w+x+1];

 

              //条件2：2<=N(p）<=6

              int np=(neighbor[0]+neighbor[1]+neighbor[2]+neighbor[3]+neighbor[4]+neighbor[5]+neighbor[6]+neighbor[7])/255;

              if(np<2 || np>6) continue;

 

              //条件3：S(p）=1

              int sp=0;

              for(int i=1;i<8;i++)

              {

                  if(neighbor[i]-neighbor[i-1]==255)

                     sp++;

              }

              if(neighbor[0]-neighbor[7]==255)

                  sp++;            

              if(sp!=1) continue;

 

              //条件4：p2*p0*p6=0

              if(neighbor[2]&neighbor[0]&neighbor[6]!=0)

                  continue;

                //条件5：p0*p6*p4=0

              if(neighbor[0]&neighbor[6]&neighbor[4]!=0)

                  continue;

 

 

              //标记删除

              mark[w*y+x]=1;   

              markNum++;

              loop=TRUE;

           }

       }

 

       //将标记删除的点置为背景色

       if(markNum>0)

       {

           for(y=0;y<h;y++)

           {

              for(x=0;x<w;x++)

              {

                  k=y*w+x;

                  if(mark[k]==1)

                  {

                     imgBuf[k]=0;

                  }

              }

           }

       }

      

 

       //第二步

        markNum=0;

       for(y=1;y<h-1;y++)

       {

           for(x=1;x<w-1;x++)

           {

              //条件1：p必须是前景点

              if(imgBuf[y*w+x]==0 ) continue;

 

              neighbor[0]= imgBuf[y*w+x+1] ;

              neighbor[1]= imgBuf[(y-1)*w+x+1];

              neighbor[2]= imgBuf[(y-1)*w+x];

              neighbor[3]= imgBuf[(y-1)*w+x-1];

              neighbor[4]= imgBuf[y*w+x-1];

              neighbor[5]= imgBuf[(y+1)*w+x-1];

              neighbor[6]= imgBuf[(y+1)*w+x];

              neighbor[7]= imgBuf[(y+1)*w+x+1];

 

              //条件2：<=N(p)<=6

              int np=(neighbor[0]+neighbor[1]+neighbor[2]+neighbor[3]+neighbor[4]+neighbor[5]+neighbor[6]+neighbor[7])/255;

              if(np<2 || np>6) continue;

 

              //条件3：S(p)=1

              int sp=0;

              for(int i=1;i<8;i++)

              {

                  if(neighbor[i]-neighbor[i-1]==255)

                     sp++;

              }

              if(neighbor[0]-neighbor[7]==255)

                  sp++;

              if(sp!=1) continue;

 

              //条件4：p2*p0*p4==0

              if(neighbor[2]&neighbor[0]&neighbor[4]!=0)

                  continue;

              //条件5：p2*p6*p4==0

              if(neighbor[2]&neighbor[6]&neighbor[4]!=0)

                  continue;

 

              //标记删除

              mark[w*y+x]=1;   

              markNum++;

              loop=TRUE;

           }

       }

 

       //将标记删除的点置为背景色

       for(y=0;y<h;y++)

       {

           for(x=0;x<w;x++)

           {

              k=y*w+x;

              if(mark[k]==1)

              {

                  imgBuf[k]=0;

              }

           }

       }

 

    } 

}


void CImageProcessDoc::OnMenuitemGetthinimagezhang() 
{
	// TODO: Add your command handler code here
	IplImage *pImg = m_image.GetImage();

	IplImage* r_plane = cvCreateImage( cvGetSize(pImg), 8, 1 );
	IplImage* g_plane = cvCreateImage( cvGetSize(pImg), 8, 1 );
	IplImage* b_plane = cvCreateImage( cvGetSize(pImg), 8, 1 );

	if(r_plane->origin != pImg->origin) r_plane->origin == pImg->origin;
	if(g_plane->origin != pImg->origin) g_plane->origin == pImg->origin;
	if(b_plane->origin != pImg->origin) b_plane->origin == pImg->origin;

	cvSplit(pImg,r_plane,g_plane,b_plane,0);

	IplImage *thin_image = cvCreateImage(cvGetSize(r_plane),IPL_DEPTH_8U,1);
	if(thin_image->origin != r_plane->origin) thin_image->origin = r_plane->origin;

	BYTE *imgBuf = new BYTE[r_plane->width * r_plane->height];
	int x,y;
	CvScalar scalar;
	for(x = 0; x < r_plane->width; x++)
	{
		for(y = 0; y < r_plane->height; y++)
		{
			scalar = cvGet2D(r_plane,y,x);
			imgBuf[y*r_plane->width+x]=(char)scalar.val[0];
		}
	}

	DWORD start_time = GetTickCount();

	ZhangThinning(r_plane->width,r_plane->height,imgBuf);

	DWORD end_time = GetTickCount();

	for(x = 0; x < r_plane->width; x++)
	{
		for(y = 0; y < r_plane->height; y++)
		{
			scalar = cvGet2D(r_plane,y,x);
			scalar.val[0] = imgBuf[y*r_plane->width+x];
			cvSet2D(thin_image,y,x,scalar);
		}
	}

	m_image.CopyOf(thin_image,thin_image->nChannels);

	cvSaveImage("D://log/thin_image_zhang.bmp",thin_image);

	UpdateAllViews(NULL);

	delete[] imgBuf;

	timeSpan = end_time - start_time;
}

void CImageProcessDoc::OnMenuitemSoybeangetthinimagezhang() 
{
	if(type_flag == STYLE_VIDEO)
	{
		OnMenuitemVideoreverse();
		OnMenuitemVideogetthinimagezhang();
		vector<double> temp_v_timeSpan = v_timeSpan;
		OnMenuitemVideoreverse();
		v_timeSpan = temp_v_timeSpan;

		if(v_timeSpan.size() != 0)
		{
			ofstream res_file("D://log/res_time.txt");

			double total_timeSpan = 0.0;
			for(int i = 0; i < v_timeSpan.size(); ++i)
			{
				total_timeSpan += v_timeSpan[i];
				res_file << "frameNum = " << i << " , timeSpan = " << v_timeSpan[i] << " ms" << endl;
			}
			res_file.close();
		
			char str[200];
			sprintf(str,"Finish Get thin Image(Zhang).Use time:%lf ms",total_timeSpan);
			AfxMessageBox(str);
		}
	}
	else if(type_flag == STYLE_IMAGE)
	{
		OnMenuitemGetreverseimage();
		timeSpan = -1.0;
		OnMenuitemGetthinimagezhang();
		double temp_timeSpan = timeSpan;
		OnMenuitemGetreverseimage();
		timeSpan = temp_timeSpan;
		if(timeSpan != -1.0)
		{
			ofstream res_file("D://log/res_time.txt");
			res_file << timeSpan << " ms" << endl;
			res_file << timeSpan / 1000 << " s" << endl;
			res_file.close();

			char str[200];
			sprintf(str,"Finish Get Thin Image(Zhang).Use time:%lf ms",timeSpan);
			AfxMessageBox(str);
		}
	}


}

void thinnerRosenfeld(void *image, unsigned long lx, unsigned long ly)
{

    char *f, *g;
    char n[10];
    char a[5] = {0, -1, 1, 0, 0};
    char b[5] = {0, 0, 0, 1, -1};
    char nrnd, cond, n48, n26, n24, n46, n68, n82, n123, n345, n567, n781;
    short k, shori;
    unsigned long i, j;
    long ii, jj, kk, kk1, kk2, kk3, size;
    size = (long)lx * (long)ly;

    g = (char *)malloc(size);
    if(g==NULL)
    {
        return;
    }

    f = (char *)image;
    for(kk=0l; kk<size; kk++)
    {
        g[kk] = f[kk];
    }

    do
    {
        shori = 0;
        for(k=1; k<=4; k++)
        {
            for(i=1; i<lx-1; i++)
            {
                ii = i + a[k];

                for(j=1; j<ly-1; j++)
                {
                    kk = i*ly + j;

                    if(!f[kk])
                        continue;

                    jj = j + b[k];
                    kk1 = ii*ly + jj;

                    if(f[kk1])
                        continue;

                    kk1 = kk - ly -1;
                    kk2 = kk1 + 1;
                    kk3 = kk2 + 1;
                    n[3] = f[kk1];
                    n[2] = f[kk2];
                    n[1] = f[kk3];
                    kk1 = kk - 1;
                    kk3 = kk + 1;
                    n[4] = f[kk1];
                    n[8] = f[kk3];
                    kk1 = kk + ly - 1;
                    kk2 = kk1 + 1;
                    kk3 = kk2 + 1;
                    n[5] = f[kk1];
                    n[6] = f[kk2];
                    n[7] = f[kk3];

                    nrnd = n[1] + n[2] + n[3] + n[4]
                        +n[5] + n[6] + n[7] + n[8];
                    if(nrnd<=1)
                        continue;

                    cond = 0;
                    n48 = n[4] + n[8];
                    n26 = n[2] + n[6];
                    n24 = n[2] + n[4];
                    n46 = n[4] + n[6];
                    n68 = n[6] + n[8];
                    n82 = n[8] + n[2];
                    n123 = n[1] + n[2] + n[3];
                    n345 = n[3] + n[4] + n[5];
                    n567 = n[5] + n[6] + n[7];
                    n781 = n[7] + n[8] + n[1];

                    if(n[2]==1 && n48==0 && n567>0)
                    {
                        if(!cond)
                            continue;
                        g[kk] = 0;
                        shori = 1;
                        continue;
                    }

                    if(n[6]==1 && n48==0 && n123>0)
                    {
                        if(!cond)
                            continue;
                        g[kk] = 0;
                        shori = 1;
                        continue;
                    }

                    if(n[8]==1 && n26==0 && n345>0)
                    {
                        if(!cond)
                            continue;
                        g[kk] = 0;
                        shori = 1;
                        continue;
                    }

                    if(n[4]==1 && n26==0 && n781>0)
                    {
                        if(!cond)
                            continue;
                        g[kk] = 0;
                        shori = 1;
                        continue;
                    }

                    if(n[5]==1 && n46==0)
                    {
                        if(!cond)
                            continue;
                        g[kk] = 0;
                        shori = 1;
                        continue;
                    }

                    if(n[7]==1 && n68==0)
                    {
                        if(!cond)
                            continue;
                        g[kk] = 0;
                        shori = 1;
                        continue;
                    }

                    if(n[1]==1 && n82==0)
                    {
                        if(!cond)
                            continue;
                        g[kk] = 0;
                        shori = 1;
                        continue;
                    }

                    if(n[3]==1 && n24==0)
                    {
                        if(!cond)
                            continue;
                        g[kk] = 0;
                        shori = 1;
                        continue;
                    }

                    cond = 1;
                    if(!cond)
                        continue;
                    g[kk] = 0;
                    shori = 1;
                }
            }

            for(i=0; i<lx; i++)
            {
                for(j=0; j<ly; j++)
                {
                    kk = i*ly + j;
                    f[kk] = g[kk];
                }
            }
        }
    }while(shori);

    free(g);
} 

bool Rosenfeld(LPSTR lpDIBBits, LONG lWidth, LONG lHeight)
{
LPSTR lpSrc;
    int i,j;

    //建立存储区存放2值矩阵
BYTE *image = (BYTE*)malloc(lWidth*lHeight*sizeof(BYTE));

//给2值矩阵赋值

for(i=0;i<lHeight;i++)
{
    for(j=0;j<lWidth;j++)
{
      lpSrc=lpDIBBits+i*lWidth+j;
    
      if(*lpSrc==0)
      image[i*lWidth+j]=1;

  else
         image[i*lWidth+j]=0;
}
}
   thinnerRosenfeld(image,lHeight,lWidth);

   //将结果赋值到原图像中

   for(i=0;i<lHeight;i++)
   {
     for(j=0;j<lWidth;j++)
 {
   lpSrc=lpDIBBits+i*lWidth+j;

       if(image[i*lWidth+j]==1)
   *lpSrc=(BYTE)0;

   else
       *lpSrc=(BYTE)255;
 }
   
   }


 //清空内存
   free(image);
   ::GlobalUnlock ((HGLOBAL)lpDIBBits);

return true;
}


void CImageProcessDoc::OnMenuitemGetthinimageroseenfeld() 
{
	// TODO: Add your command handler code here
	IplImage *pImg = m_image.GetImage();

	cvNot(pImg,pImg);

	IplImage* r_plane = cvCreateImage( cvGetSize(pImg), 8, 1 );
	IplImage* g_plane = cvCreateImage( cvGetSize(pImg), 8, 1 );
	IplImage* b_plane = cvCreateImage( cvGetSize(pImg), 8, 1 );

	if(r_plane->origin != pImg->origin) r_plane->origin = pImg->origin;
	if(g_plane->origin != pImg->origin) g_plane->origin = pImg->origin;
	if(b_plane->origin != pImg->origin) b_plane->origin = pImg->origin;

	cvSplit(pImg,r_plane,g_plane,b_plane,0);

	IplImage *thin_image = cvCreateImage(cvGetSize(r_plane),IPL_DEPTH_8U,1);

	if(thin_image->origin != r_plane->origin) thin_image->origin = r_plane->origin;

	BYTE *imgBuf = new BYTE[r_plane->width * r_plane->height];
	int x,y;
	CvScalar scalar;
	for(x = 0; x < r_plane->width; x++)
	{
		for(y = 0; y < r_plane->height; y++)
		{
			scalar = cvGet2D(r_plane,y,x);
			imgBuf[y*r_plane->width+x]=(char)scalar.val[0];
		}
	}

	DWORD start_time = GetTickCount();

	Rosenfeld((char *)imgBuf, r_plane->width,r_plane->height);

	DWORD end_time = GetTickCount();

	for(x = 0; x < r_plane->width; x++)
	{
		for(y = 0; y < r_plane->height; y++)
		{
			scalar = cvGet2D(r_plane,y,x);
			scalar.val[0] = imgBuf[y*r_plane->width+x];
			cvSet2D(thin_image,y,x,scalar);
		}
	}

	m_image.CopyOf(thin_image,thin_image->nChannels);

	cvSaveImage("D://log/thin_image_rosenfeld.bmp",thin_image);

	cvNot(pImg,pImg);

	UpdateAllViews(NULL);

	delete[] imgBuf;

	timeSpan = end_time - start_time;
}

void CImageProcessDoc::OnMenuitemSoybeangetthinimagerosenfeld() 
{	
	if(type_flag == STYLE_VIDEO)
	{
		OnMenuitemVideoreverse();
		OnMenuitemVideogetthinimagerosenfeld();
		vector<double> temp_v_timeSpan = v_timeSpan;
		OnMenuitemVideoreverse();
		v_timeSpan = temp_v_timeSpan;

		if(v_timeSpan.size() != 0)
		{
			ofstream res_file("D://log/res_time.txt");

			double total_timeSpan = 0.0;
			for(int i = 0; i < v_timeSpan.size(); ++i)
			{
				total_timeSpan += v_timeSpan[i];
				res_file << "frameNum = " << i << " , timeSpan = " << v_timeSpan[i] << " ms" << endl;
			}
			res_file.close();
		
			char str[200];
			sprintf(str,"Finish Get Thin Image(Rosenfeld).Use time:%lf ms",total_timeSpan);
			AfxMessageBox(str);
		}
	}
	else if(type_flag == STYLE_IMAGE)
	{
		OnMenuitemGetreverseimage();
		timeSpan = -1.0;
		OnMenuitemGetthinimageroseenfeld();
		double temp_timeSpan = timeSpan;
		OnMenuitemGetreverseimage();
		timeSpan = temp_timeSpan;
		if(timeSpan != -1.0)
		{
			ofstream res_file("D://log/res_time.txt");
			res_file << timeSpan << " ms" << endl;
			res_file << timeSpan / 1000 << " s" << endl;
			res_file.close();

			char str[200];
			sprintf(str,"Finish Get Thin Image(Resenfeld).Use time:%lf ms",timeSpan);
			AfxMessageBox(str);
		}
	}

}

void CImageProcessDoc::OnMENUITEMGETTHINIMAGEDiSTANCE() 
{
	// TODO: Add your command handler code here

	DWORD start_time = GetTickCount();

	//Get Convolution Kernel
    CvMat kern00, kern45, kern90, kern135;
	float L0[]={
            -1,-1,-1,-1,-1,
            0, 0, 0, 0, 0,
            2, 2, 2, 2, 2,
            0, 0, 0, 0, 0,
            -1,-1,-1,-1,-1
    };
    float L45[]={
            0,-1,-1, 0, 2,
            -1,-1, 0, 2, 0,
            -1, 0, 2, 0,-1,
            0, 2, 0,-1,-1,
            2, 0,-1,-1, 0
    };
    float L90[]={
            -1, 0, 2, 0,-1,
            -1, 0, 2, 0,-1,
            -1, 0, 2, 0,-1,
            -1, 0, 2, 0,-1,
            -1, 0, 2, 0,-1
    };
    float L135[]={
            2, 0,-1,-1, 0,
            0, 2, 0,-1,-1,
            -1, 0, 2, 0,-1,
            -1,-1, 0, 2, 0,
            0,-1,-1, 0, 2
    };
    cvInitMatHeader(&kern00,5,5,CV_32FC1,L0);
    cvInitMatHeader(&kern45,5,5,CV_32FC1,L45);
    cvInitMatHeader(&kern90,5,5,CV_32FC1,L90);
    cvInitMatHeader(&kern135,5,5,CV_32FC1,L135);

	//Distance Transform
	IplImage *pImg = m_image.GetImage();

	IplImage* r_plane = cvCreateImage( cvGetSize(pImg), 8, 1 );
	IplImage* g_plane = cvCreateImage( cvGetSize(pImg), 8, 1 );
	IplImage* b_plane = cvCreateImage( cvGetSize(pImg), 8, 1 );

	if(r_plane->origin != pImg->origin) r_plane->origin == pImg->origin;
	if(g_plane->origin != pImg->origin) g_plane->origin == pImg->origin;
	if(b_plane->origin != pImg->origin) b_plane->origin == pImg->origin;

	cvSplit(pImg,r_plane,g_plane,b_plane,0);

    IplImage *distsrc;
    distsrc=cvCreateImage(cvGetSize(r_plane),IPL_DEPTH_32F,1);
	if(distsrc->origin != r_plane->origin) distsrc->origin = r_plane->origin;

	cvDistTransform(r_plane,distsrc,CV_DIST_L2,5);

	//filter or Convolution
    IplImage *S00;
    IplImage *S45;
    IplImage *S90;
    IplImage *S135;
	S00=cvCreateImage(cvGetSize(r_plane),IPL_DEPTH_32F,1);
    S45=cvCreateImage(cvGetSize(r_plane),IPL_DEPTH_32F,1);
    S90=cvCreateImage(cvGetSize(r_plane),IPL_DEPTH_32F,1);
    S135=cvCreateImage(cvGetSize(r_plane),IPL_DEPTH_32F,1);

	if(S00->origin != r_plane->origin) S00->origin = r_plane->origin;
	if(S45->origin != r_plane->origin) S45->origin = r_plane->origin;
	if(S90->origin != r_plane->origin) S90->origin = r_plane->origin;
	if(S135->origin != r_plane->origin) S135->origin = r_plane->origin;

	cvFilter2D(distsrc,S00,&kern00);
    cvFilter2D(distsrc,S45,&kern45);
    cvFilter2D(distsrc,S90,&kern90);
    cvFilter2D(distsrc,S135,&kern135);

	//Calculator max value
	   //
    //Smax = MAX(S00,S45,S90,S135)
    //     / Smax, Smax >= 0
    // g = |
    //     \ 0 , others
    //
    IplImage *out;
    out=cvCreateImage(cvGetSize(r_plane),IPL_DEPTH_32F,1);
	if(out->origin != r_plane->origin) out->origin = r_plane->origin;

    float Smax=0;
    for (int y=0; y < out->height; y++){
        for (int x=0; x< out->width; x++){
            Smax = MAX(
                MAX(((float*)(S00->imageData + y* S00->widthStep))[x], ((float*)(S45->imageData + y* S45->widthStep))[x]),
                MAX(((float*)(S90->imageData + y* S90->widthStep))[x], ((float*)(S135->imageData + y* S135->widthStep))[x]));
                ((float*)(out->imageData + y* out->widthStep))[x] = Smax > 0 ? Smax: 0.0;
        }
    }

	//Threshold
    cvThreshold(out,out,7,1,CV_THRESH_BINARY);

	DWORD end_time = GetTickCount();

	//int x;
	//CvScalar scalar;
	//ofstream outfile1("D://log/thin_image_point.txt");
	//for(x = 0; x < out->width; x++)
	//{
	//	for(y = 0; y < out->height; y++)
	//	{
	//		scalar = cvGet2D(out,y,x);
	//		outfile1<<"x="<<x<<",y="<<y<<",value="<<scalar.val[0]<<endl;
	//	}
	//}
	//outfile1.close();
	
	m_image.CopyOf(out,out->nChannels);

	cvSaveImage("D://log/thin_image_distance.bmp",pImg);

	UpdateAllViews(NULL);

	cvReleaseImage(&S00);
	cvReleaseImage(&S45);
	cvReleaseImage(&S90);
	cvReleaseImage(&S135);
	cvReleaseImage(&distsrc);
	cvReleaseImage(&out);	

	timeSpan = end_time - start_time;
}



void CImageProcessDoc::OnMenuitemSoybeangetthinimagedistance() 
{
	// TODO: Add your command handler code here
	if(type_flag == STYLE_VIDEO)
	{
		OnMenuitemVideoreverse();
		OnMenuitemVideogetthinimagedistance();
		vector<double> temp_v_timeSpan = v_timeSpan;
		OnMenuitemVideoreverse();
		v_timeSpan = temp_v_timeSpan;

		if(v_timeSpan.size() != 0)
		{
			ofstream res_file("D://log/res_time.txt");

			double total_timeSpan = 0.0;
			for(int i = 0; i < v_timeSpan.size(); ++i)
			{
				total_timeSpan += v_timeSpan[i];
				res_file << "frameNum = " << i << " , timeSpan = " << v_timeSpan[i] << " ms" << endl;
			}
			res_file.close();
		
			char str[200];
			sprintf(str,"Finish Get Thin Image(Distance).Use time:%lf ms",total_timeSpan);
			AfxMessageBox(str);
		}
	}
	else if(type_flag == STYLE_IMAGE)
	{
		OnMenuitemGetreverseimage();
		timeSpan = -1.0;
		OnMENUITEMGETTHINIMAGEDiSTANCE();
		double temp_timeSpan = timeSpan;
		OnMenuitemGetreverseimage();
		timeSpan = temp_timeSpan;
		if(timeSpan != -1.0)
		{
			ofstream res_file("D://log/res_time.txt");
			res_file << timeSpan << " ms" << endl;
			res_file << timeSpan / 1000 << " s" << endl;
			res_file.close();

			char str[200];
			sprintf(str,"Finish Get Thin Image(Distance).Use time:%lf ms",timeSpan);
			AfxMessageBox(str);
		}
	}

	
}

void CImageProcessDoc::OnMenuitemGetsegmentationimagecanny() 
{
	// TODO: Add your command handler code here
	IplImage *pImg = m_image.GetImage();

	IplImage* r_plane = cvCreateImage( cvGetSize(pImg), 8, 1 );
	IplImage* g_plane = cvCreateImage( cvGetSize(pImg), 8, 1 );
	IplImage* b_plane = cvCreateImage( cvGetSize(pImg), 8, 1 );
	cvSplit(pImg,r_plane,g_plane,b_plane,0);

	DWORD start_time = GetTickCount();

	IplImage *seg_image = cvCreateImage(cvGetSize(r_plane),IPL_DEPTH_8U,1);

	cvCanny(r_plane,seg_image,50,150,3);

	DWORD end_time = GetTickCount();

	//cvNamedWindow("Segmentation Image(Canny)");
	//cvShowImage("Segmentation Image(Canny)",seg_image);
	
	m_image.CopyOf(seg_image,seg_image->nChannels);

	cvSaveImage("D://log/segmentation_image_canny.bmp",seg_image);

	UpdateAllViews(NULL);

	timeSpan = end_time - start_time;
}

void CImageProcessDoc::OnMenuitemSoybeangetsegmentationimagecanny() 
{
	// TODO: Add your command handler code here
	if(type_flag == STYLE_VIDEO)
	{
		//OnMenuitemVideoreverse();
		OnMenuitemVideocannyoperator();
		vector<double> temp_v_timeSpan = v_timeSpan;
		OnMenuitemVideoreverse();
		v_timeSpan = temp_v_timeSpan;

		if(v_timeSpan.size() != 0)
		{
			ofstream res_file("D://log/res_time.txt");

			double total_timeSpan = 0.0;
			for(int i = 0; i < v_timeSpan.size(); ++i)
			{
				total_timeSpan += v_timeSpan[i];
				res_file << "frameNum = " << i << " , timeSpan = " << v_timeSpan[i] << " ms" << endl;
			}
			res_file.close();
		
			char str[200];
			sprintf(str,"Finish Get Segmentation Image(Canny).Use time:%lf ms",total_timeSpan);
			AfxMessageBox(str);
		}
	}
	else if(type_flag == STYLE_IMAGE)
	{
		OnMenuitemGetreverseimage();
		timeSpan = -1.0;
		OnMenuitemGetsegmentationimagecanny();
		double temp_timeSpan = timeSpan;
		OnMenuitemGetreverseimage();
		timeSpan = temp_timeSpan;
		if(timeSpan != -1.0)
		{
			ofstream res_file("D://log/res_time.txt");
			res_file << timeSpan << " ms" << endl;
			res_file << timeSpan / 1000 << " s" << endl;
			res_file.close();

			char str[200];
			sprintf(str,"Finish Get Segmentation Image(Canny).Use time:%lf ms",timeSpan);
			AfxMessageBox(str);
		}
	}

}


void CImageProcessDoc::OnMenuitemGetsegmentationimagesobel() 
{
	// TODO: Add your command handler code here
	CSlectCalculateStyleDialog dialog;
	dialog.m_style = 3;

	if(dialog.DoModal() == IDOK)
	{
		IplImage *pImg = m_image.GetImage();

		IplImage* r_plane = cvCreateImage( cvGetSize(pImg), 8, 1 );
		IplImage* g_plane = cvCreateImage( cvGetSize(pImg), 8, 1 );
		IplImage* b_plane = cvCreateImage( cvGetSize(pImg), 8, 1 );
		cvSplit(pImg,r_plane,g_plane,b_plane,0);

		if(r_plane->origin != pImg->origin) r_plane->origin = pImg->origin;
		if(g_plane->origin != pImg->origin) g_plane->origin = pImg->origin;
		if(b_plane->origin != pImg->origin) b_plane->origin = pImg->origin;

		DWORD start_time = GetTickCount();

		IplImage *seg_image = cvCreateImage(cvGetSize(r_plane),IPL_DEPTH_8U,1);

		IplImage *seg_image_x = cvCreateImage(cvGetSize(r_plane),IPL_DEPTH_8U,1);
		IplImage *seg_image_y = cvCreateImage(cvGetSize(r_plane),IPL_DEPTH_8U,1);

		if(seg_image->origin != r_plane->origin) seg_image->origin = r_plane->origin;
		if(seg_image_x->origin != r_plane->origin) seg_image_x->origin = r_plane->origin;
		if(seg_image_y->origin != r_plane->origin) seg_image_y->origin = r_plane->origin;

		cvSobel(r_plane,seg_image_x,1,0,3);
		cvSobel(r_plane,seg_image_y,0,1,3);

		int y,x;
		if(dialog.m_style == 0)	{cvCopy(seg_image_x,seg_image);}
		else if(dialog.m_style == 1) {cvCopy(seg_image_y,seg_image);}
		else if(dialog.m_style == 2)
		{
			for(y = 0; y < seg_image->height; ++y)
			{
				for(x = 0; x < seg_image->width; ++x)
				{
					CvScalar s_x = cvGet2D(seg_image_x,y,x);
					CvScalar s_y = cvGet2D(seg_image_y,y,x);
					CvScalar scalar = cvGet2D(seg_image,y,x);

					scalar.val[0] = s_x.val[0] > s_y.val[0] ? s_x.val[0] : s_y.val[0];
					cvSet2D(seg_image,y,x,scalar);
				}
			}
		}
		else
		{
			for(y = 0; y < seg_image->height; ++y)
			{
				for(x = 0; x < seg_image->width; ++x)
				{
					CvScalar s_x = cvGet2D(seg_image_x,y,x);
					CvScalar s_y = cvGet2D(seg_image_y,y,x);
					CvScalar scalar = cvGet2D(seg_image,y,x);

					int count = (int)s_x.val[0] + s_y.val[0];
					if(count > 255) count = 255;
					scalar.val[0] = count;
					cvSet2D(seg_image,y,x,scalar);
				}
			}
		}

		DWORD end_time = GetTickCount();

		//cvNamedWindow("Segmentation Image(Canny)");
		//cvShowImage("Segmentation Image(Canny)",seg_image);
		
		m_image.CopyOf(seg_image,seg_image->nChannels);

		cvSaveImage("D://log/segmentation_image_canny.bmp",seg_image);

		UpdateAllViews(NULL);

		timeSpan = end_time - start_time;
	}

}

void CImageProcessDoc::OnMenuitemSoybeangetsegmentationimagesobel() 
{
	// TODO: Add your command handler code here
	if(type_flag == STYLE_VIDEO)
	{
		OnMenuitemVideosobeloperator();
		vector<double> temp_v_timeSpan = v_timeSpan;
		OnMenuitemVideoreverse();
		OnMenuitemVideobinarationostu();
		v_timeSpan = temp_v_timeSpan;

		if(v_timeSpan.size() != 0)
		{
			ofstream res_file("D://log/res_time.txt");

			double total_timeSpan = 0.0;
			for(int i = 0; i < v_timeSpan.size(); ++i)
			{
				total_timeSpan += v_timeSpan[i];
				res_file << "frameNum = " << i << " , timeSpan = " << v_timeSpan[i] << " ms" << endl;
			}
			res_file.close();
		
			char str[200];
			sprintf(str,"Finish Get Segmentation Image(Sobel).Use time:%lf ms",total_timeSpan);
			AfxMessageBox(str);
		}
	}
	else if(type_flag == STYLE_IMAGE)
	{
		timeSpan = -1.0;
		OnMenuitemGetsegmentationimagesobel();
		double temp_timeSpan = timeSpan;
		OnMenuitemGetreverseimage();
		temp_timeSpan += timeSpan;
		OnMenuitemGetthresholdimageotsu();
		timeSpan += temp_timeSpan;

		if(timeSpan != -1.0)
		{
			ofstream res_file("D://log/res_time.txt");
			res_file << timeSpan << " ms" << endl;
			res_file << timeSpan / 1000 << " s" << endl;
			res_file.close();

			char str[200];
			sprintf(str,"Finish Get Segmentation Image(Sobel).Use time:%lf ms",timeSpan);
			AfxMessageBox(str);
		}
	}

}

void CImageProcessDoc::OnMenuitemCompleteisolatepoint() 
{
	AfxMessageBox("Never finish The Permission");
}

void CImageProcessDoc::OnMenuitemGetallimagepoint() 
{
	// TODO: Add your command handler code here
	IplImage *pImg = m_image.GetImage();

	DWORD start_time;
	DWORD end_time;

	int x,y,z;
	CvScalar scalar;

	start_time = GetTickCount();
	ofstream outfile1("D://log/image_point.txt");
	for(x = 0; x < pImg->width; x++)
	{
		for(y = 0; y < pImg->height; y++)
		{
			scalar = cvGet2D(pImg,y,x);
			outfile1<<"x="<<x<<",y="<<y<<",value=";
			for(z = 0; z < pImg->nChannels; ++z) outfile1<< " " << scalar.val[z];
			outfile1<<endl;
		}
	}
	outfile1.close();

	end_time = GetTickCount();
	timeSpan = end_time - start_time;

	/*ofstream timefile("D://log/time_record.txt");
	timefile << timeSpan << "ms" << endl;
	timefile << timeSpan/1000 << "s" << endl;
	timefile.close();*/

	AfxMessageBox("Finish Get All Image Point");
}

void CImageProcessDoc::OnMenuitemSoybeancompleteisolationpoint() 
{
	// TODO: Add your command handler code here
	if(type_flag == STYLE_IMAGE)
	{

		int x,y;
		IplImage *lp_frame;
		CvScalar p1,p2,p3,p4,p5,p6,p7,p8,p9;
		int idx_frame = 0;
		ofstream outfile1("D://log/isolate_image_point.txt");

		vector<int> isolate_point_frame;
		vector<int> isolate_point_x;
		vector<int> isolate_point_y;


		IplImage *pImg = m_image.GetImage();
		IplImage* r_plane = cvCreateImage( cvGetSize(pImg), 8, 1 );
		IplImage* g_plane = cvCreateImage( cvGetSize(pImg), 8, 1 );
		IplImage* b_plane = cvCreateImage( cvGetSize(pImg), 8, 1 );
		cvSplit(pImg,r_plane,g_plane,b_plane,0);

		DWORD start_time = GetTickCount();

		//get isolation point
		for(x = 1; x < pImg->width - 1; x++)
		{
			for(y = 1; y < pImg->height - 1; y++)
			{
				p1 = cvGet2D(pImg,y - 1,x - 1);
				p2 = cvGet2D(pImg,y - 1,x);
				p3 = cvGet2D(pImg,y - 1,x + 1);

				p4 = cvGet2D(pImg,y,x - 1);
				p5 = cvGet2D(pImg,y,x);
				p6 = cvGet2D(pImg,y,x + 1);

				p7 = cvGet2D(pImg,y + 1,x - 1);
				p8 = cvGet2D(pImg,y + 1,x);
				p9 = cvGet2D(pImg,y + 1,x + 1);

				if(p5.val[0] == 0 && p1.val[0] == 255 && p2.val[0] == 255 && p3.val[0] == 255 
					&& p4.val[0] == 255 && p6.val[0] == 255 && p7.val[0] == 255 && p8.val[0] == 255 && p9.val[0] == 255)
				{
					outfile1<<"x="<<x<<",y="<<y<<endl;
					isolate_point_x.push_back(x);
					isolate_point_y.push_back(y);
				}
			}
		}
		outfile1.close();

		int val1 = 6;

		int i,j,ix,iy;
		CvScalar scalar;
		ofstream outfile2("D://log/complete_isolate_result.txt");

		for(int idx = 0; idx != isolate_point_x.size(); ++idx)
		{
			x = isolate_point_x[idx];
			y = isolate_point_y[idx];
			for(i = 2; i <= val1; ++i)
			{
				for(ix = x - i; ix <= x + i; ++ix)
				{
					if(ix < 0 || ix >= pImg->width) continue;
					iy = y - i;
					if(iy >= 0 && iy < pImg->height)
					{
						scalar = cvGet2D(pImg,iy,ix);
						if(scalar.val[0] == 0) break;
					}


					iy = y + i;
					if(iy >= 0 && iy < pImg->height)
					{
						scalar = cvGet2D(pImg,iy,ix);
						if(scalar.val[0] == 0) break;
					}

				}
				if(ix <= x + 1) break;

				for(iy = y - i; iy <= y + i; ++iy)
				{
					if(iy < 0 || iy >= pImg->height) continue;

					ix = x - i;
					if(ix >= 0 && ix < pImg->width)
					{
						scalar = cvGet2D(pImg,iy,ix);
						if(scalar.val[0] == 0) break;
					}
					ix = x + i;
					if(ix >= 0 && ix < pImg->width)
					{
						scalar = cvGet2D(pImg,iy,ix);
						if(scalar.val[0] == 0) break;
					}
				}
				if(iy <= y + i) break;
			}
			if(i <= val1)
			{
				outfile2<<"x="<<x<<",y="<<y<<",ix="<<ix<<",iy="<<iy<<endl;
				cvLine(pImg,cvPoint(x,y),cvPoint(ix,iy),CV_RGB(0,0,0));
			}
			else
			{
				cvSet2D(pImg,y,x,cvScalar(0));
			}

		}


		cvSaveImage("D://log/complete_isolate_image.bmp",pImg);

		outfile2.close();

		DWORD end_time = GetTickCount();
		
		timeSpan = end_time - start_time;

		UpdateAllViews(NULL);

		char str[200];
		sprintf(str,"Finish Complete Image(Isolate).Use time:%lf ms.",timeSpan);
		AfxMessageBox(str);
	}
	else if(type_flag == STYLE_VIDEO)
	{
		v_timeSpan.clear();

		CvVideoWriter *writer = cvCreateVideoWriter("D://log/video_binaration_iterate.avi",
			cvGetCaptureProperty(m_capture,CV_CAP_PROP_FOURCC),
			cvGetCaptureProperty(m_capture,CV_CAP_PROP_FPS),
			cvSize(int(cvGetCaptureProperty(m_capture,CV_CAP_PROP_FRAME_WIDTH)),(int)(cvGetCaptureProperty(m_capture,CV_CAP_PROP_FRAME_HEIGHT))),
			1);

		IplImage *lp_frame;
		for(int iii = 0; iii < m_frame_count; ++iii)
		{
			lp_frame = m_frames[iii];
			m_image.CopyOf(lp_frame,lp_frame->nChannels);

			timeSpan = -1.0;

			int x,y;
			IplImage *lp_frame;
			CvScalar p1,p2,p3,p4,p5,p6,p7,p8,p9;
			int idx_frame = 0;
			ofstream outfile1("D://log/isolate_image_point.txt");

			vector<int> isolate_point_frame;
			vector<int> isolate_point_x;
			vector<int> isolate_point_y;


			IplImage *pImg = m_image.GetImage();
			IplImage* r_plane = cvCreateImage( cvGetSize(pImg), 8, 1 );
			IplImage* g_plane = cvCreateImage( cvGetSize(pImg), 8, 1 );
			IplImage* b_plane = cvCreateImage( cvGetSize(pImg), 8, 1 );
			cvSplit(pImg,r_plane,g_plane,b_plane,0);

			if(r_plane->origin != pImg->origin) r_plane->origin = pImg->origin;
			if(g_plane->origin != pImg->origin) g_plane->origin = pImg->origin;
			if(b_plane->origin != pImg->origin) b_plane->origin = pImg->origin;

			DWORD start_time = GetTickCount();

			//get isolation point
			for(x = 1; x < pImg->width - 1; x++)
			{
				for(y = 1; y < pImg->height - 1; y++)
				{
					p1 = cvGet2D(pImg,y - 1,x - 1);
					p2 = cvGet2D(pImg,y - 1,x);
					p3 = cvGet2D(pImg,y - 1,x + 1);

					p4 = cvGet2D(pImg,y,x - 1);
					p5 = cvGet2D(pImg,y,x);
					p6 = cvGet2D(pImg,y,x + 1);

					p7 = cvGet2D(pImg,y + 1,x - 1);
					p8 = cvGet2D(pImg,y + 1,x);
					p9 = cvGet2D(pImg,y + 1,x + 1);

					if(p5.val[0] == 0 && p1.val[0] == 255 && p2.val[0] == 255 && p3.val[0] == 255 
						&& p4.val[0] == 255 && p6.val[0] == 255 && p7.val[0] == 255 && p8.val[0] == 255 && p9.val[0] == 255)
					{
						outfile1<<"x="<<x<<",y="<<y<<endl;
						isolate_point_x.push_back(x);
						isolate_point_y.push_back(y);
					}
				}
			}
			outfile1.close();

			int val1 = 6;

			int i,j,ix,iy;
			CvScalar scalar;
			ofstream outfile2("D://log/complete_isolate_result.txt");

			for(int idx = 0; idx != isolate_point_x.size(); ++idx)
			{
				x = isolate_point_x[idx];
				y = isolate_point_y[idx];
				for(i = 2; i <= val1; ++i)
				{
					for(ix = x - i; ix <= x + i; ++ix)
					{
						if(ix < 0 || ix >= pImg->width) continue;
						iy = y - i;
						if(iy >= 0 && iy < pImg->height)
						{
							scalar = cvGet2D(pImg,iy,ix);
							if(scalar.val[0] == 0) break;
						}


						iy = y + i;
						if(iy >= 0 && iy < pImg->height)
						{
							scalar = cvGet2D(pImg,iy,ix);
							if(scalar.val[0] == 0) break;
						}

					}
					if(ix <= x + 1) break;

					for(iy = y - i; iy <= y + i; ++iy)
					{
						if(iy < 0 || iy >= pImg->height) continue;

						ix = x - i;
						if(ix >= 0 && ix < pImg->width)
						{
							scalar = cvGet2D(pImg,iy,ix);
							if(scalar.val[0] == 0) break;
						}
						ix = x + i;
						if(ix >= 0 && ix < pImg->width)
						{
							scalar = cvGet2D(pImg,iy,ix);
							if(scalar.val[0] == 0) break;
						}
					}
					if(iy <= y + i) break;
				}
				if(i <= val1)
				{
					outfile2<<"x="<<x<<",y="<<y<<",ix="<<ix<<",iy="<<iy<<endl;
					cvLine(pImg,cvPoint(x,y),cvPoint(ix,iy),CV_RGB(0,0,0));
				}
				else
				{
					cvSet2D(pImg,y,x,cvScalar(0));
				}

			}


			cvSaveImage("D://log/complete_isolate_image.bmp",pImg);

			outfile2.close();

			DWORD end_time = GetTickCount();
			
			timeSpan = end_time - start_time;

			UpdateAllViews(NULL);

			//char str[200];
			//sprintf(str,"Finish Complete Image(Isolate).Use time:%lf ms.",timeSpan);
			//AfxMessageBox(str);



			v_timeSpan.push_back(timeSpan);
			
			cvCopy(m_image.GetImage(),m_frames[iii]);
			cvWriteFrame(writer,m_frames[iii]);
		}
		
		cvReleaseVideoWriter(&writer);
		m_image.CopyOf(m_frames[0],m_frames[0]->nChannels);

		UpdateAllViews(NULL);	

		if(v_timeSpan.size() != 0)
		{
			ofstream res_file("D://log/res_time.txt");

			double total_timeSpan = 0.0;
			for(int i = 0; i < v_timeSpan.size(); ++i)
			{
				total_timeSpan += v_timeSpan[i];
				res_file << "frameNum = " << i << " , timeSpan = " << v_timeSpan[i] << " ms" << endl;
			}
			res_file.close();
		
			char str[200];
			sprintf(str,"Finish Complete Isolate Point.Use time:%lf ms",total_timeSpan);
			AfxMessageBox(str);
		}

	}


}

void CImageProcessDoc::OnMENUITEMSoybeanCompleteEndPoint() 
{
	// TODO: Add your command handler code here

	if(type_flag == STYLE_IMAGE)
	{
		int x,y;
		IplImage *lp_frame;
		CvScalar p1,p2,p3,p4,p5,p6,p7,p8,p9;
		int idx_frame = 0;
		ofstream outfile1("D://log/endpoint_image_point.txt");

		vector<int> end_point_frame;
		vector<int> end_point_x;
		vector<int> end_point_y;

		IplImage *pImg = m_image.GetImage();

		DWORD start_time = GetTickCount();

		for(x = 1; x < pImg->width - 1; x++)
		{
			for(y = 1; y < pImg->height - 1; y++)
			{
				p1 = cvGet2D(pImg,y - 1,x - 1);
				p2 = cvGet2D(pImg,y - 1,x);
				p3 = cvGet2D(pImg,y - 1,x + 1);

				p4 = cvGet2D(pImg,y,x - 1);
				p5 = cvGet2D(pImg,y,x);
				p6 = cvGet2D(pImg,y,x + 1);

				p7 = cvGet2D(pImg,y + 1,x - 1);
				p8 = cvGet2D(pImg,y + 1,x);
				p9 = cvGet2D(pImg,y + 1,x + 1);

				if(p5.val[0] == 0 && (p1.val[0] + p2.val[0] + p3.val[0] + p4.val[0] + p6.val[0] + p7.val[0] + p8.val[0] + p9.val[0]) == 7 * 255)
				{
					outfile1<<"x="<<x<<",y="<<y<<endl;
					end_point_x.push_back(x);
					end_point_y.push_back(y);
				}
			}
		}
		outfile1.close();

		int val1 = 5;//搜索的长度
		int val2 = 2;//匹配的宽度
		int val3 = 3;//匹配的个数

		int idx_x[]={-1,0,1,1,1,0,-1,-1};
		int idx_y[]={-1,-1,-1,0,1,1,1,0};

		int i,j;

		int xi,yi;
		int temp_x,temp_y;
		int idx;
		CvScalar scalar;

		int count;

		ofstream outfile2("D://log/complete_end_result.txt");

		for(idx = 0; idx < end_point_x.size(); ++idx)
		{
			x = end_point_x[idx];
			y = end_point_y[idx];

			for(int k = 0; k < 8; k++)
			{
				scalar = cvGet2D(pImg,y+idx_y[k],x+idx_x[k]);
				if(scalar.val[0] == 0)
				{
					count = 0;
					temp_x = -1; temp_y = -1;
					for(i = 2; i < val1; ++i)
					{
						for(j = -val2; j <= val2; ++j)
						{
							yi = y - idx_y[k] * i + idx_y[(k + 2) % 8] * j;
							xi = x - idx_x[k] * i + idx_x[(k + 2) % 8] * j;
							if(yi >= 0 && yi < pImg->height && xi >= 0 && xi < pImg->width)
							{
								p1 = cvGet2D(pImg,yi,xi);
								if(p1.val[0] == 0)
								{
									if(temp_x == -1) {temp_x = xi;temp_y = yi;}
									++count;
									break;
								}
							}
						}
						if(j <= val2) break;
					}
					if(i < val1)
					{
						outfile2<<"x="<<x<<",y="<<y<<",temp_x="<<temp_x<<",temp_y="<<temp_y<<endl;
						cvLine(pImg,cvPoint(x,y),cvPoint(temp_x,temp_y),CV_RGB(0,0,0));
					}
				}
			}

		}

		DWORD end_time = GetTickCount();

		//cvNamedWindow("Complete Image(EndPoint)");
		//cvShowImage("Complete Image(EndPoint)",pImg);
		cvSaveImage("D://log/complete_end_image.bmp",pImg);

		timeSpan = end_time - start_time;

		outfile2.close();
		UpdateAllViews(NULL);

		char str[200];
		sprintf(str,"Finish Get End Point.Use time: %lf ms.",timeSpan);
		AfxMessageBox(str);
	}
	else if(type_flag == STYLE_VIDEO)
	{
		v_timeSpan.clear();

		CvVideoWriter *writer = cvCreateVideoWriter("D://log/video_binaration_iterate.avi",
			cvGetCaptureProperty(m_capture,CV_CAP_PROP_FOURCC),
			cvGetCaptureProperty(m_capture,CV_CAP_PROP_FPS),
			cvSize(int(cvGetCaptureProperty(m_capture,CV_CAP_PROP_FRAME_WIDTH)),(int)(cvGetCaptureProperty(m_capture,CV_CAP_PROP_FRAME_HEIGHT))),
			1);

		IplImage *lp_frame;
		for(int iii = 0; iii < m_frame_count; ++iii)
		{
			lp_frame = m_frames[iii];
			m_image.CopyOf(lp_frame,lp_frame->nChannels);

			timeSpan = -1.0;

			int x,y;
			IplImage *lp_frame;
			CvScalar p1,p2,p3,p4,p5,p6,p7,p8,p9;
			int idx_frame = 0;
			ofstream outfile1("D://log/endpoint_image_point.txt");

			vector<int> end_point_frame;
			vector<int> end_point_x;
			vector<int> end_point_y;

			IplImage *pImg = m_image.GetImage();

			DWORD start_time = GetTickCount();

			for(x = 1; x < pImg->width - 1; x++)
			{
				for(y = 1; y < pImg->height - 1; y++)
				{
					p1 = cvGet2D(pImg,y - 1,x - 1);
					p2 = cvGet2D(pImg,y - 1,x);
					p3 = cvGet2D(pImg,y - 1,x + 1);

					p4 = cvGet2D(pImg,y,x - 1);
					p5 = cvGet2D(pImg,y,x);
					p6 = cvGet2D(pImg,y,x + 1);

					p7 = cvGet2D(pImg,y + 1,x - 1);
					p8 = cvGet2D(pImg,y + 1,x);
					p9 = cvGet2D(pImg,y + 1,x + 1);

					if(p5.val[0] == 0 && (p1.val[0] + p2.val[0] + p3.val[0] + p4.val[0] + p6.val[0] + p7.val[0] + p8.val[0] + p9.val[0]) == 7 * 255)
					{
						outfile1<<"x="<<x<<",y="<<y<<endl;
						end_point_x.push_back(x);
						end_point_y.push_back(y);
					}
				}
			}
			outfile1.close();

			int val1 = 5;//搜索的长度
			int val2 = 2;//匹配的宽度
			int val3 = 3;//匹配的个数

			int idx_x[]={-1,0,1,1,1,0,-1,-1};
			int idx_y[]={-1,-1,-1,0,1,1,1,0};

			int i,j;

			int xi,yi;
			int temp_x,temp_y;
			int idx;
			CvScalar scalar;

			int count;

			ofstream outfile2("D://log/complete_end_result.txt");

			for(idx = 0; idx < end_point_x.size(); ++idx)
			{
				x = end_point_x[idx];
				y = end_point_y[idx];

				for(int k = 0; k < 8; k++)
				{
					scalar = cvGet2D(pImg,y+idx_y[k],x+idx_x[k]);
					if(scalar.val[0] == 0)
					{
						count = 0;
						temp_x = -1; temp_y = -1;
						for(i = 2; i < val1; ++i)
						{
							for(j = -val2; j <= val2; ++j)
							{
								yi = y - idx_y[k] * i + idx_y[(k + 2) % 8] * j;
								xi = x - idx_x[k] * i + idx_x[(k + 2) % 8] * j;
								if(yi >= 0 && yi < pImg->height && xi >= 0 && xi < pImg->width)
								{
									p1 = cvGet2D(pImg,yi,xi);
									if(p1.val[0] == 0)
									{
										if(temp_x == -1) {temp_x = xi;temp_y = yi;}
										++count;
										break;
									}
								}
							}
							if(j <= val2) break;
						}
						if(i < val1)
						{
							outfile2<<"x="<<x<<",y="<<y<<",temp_x="<<temp_x<<",temp_y="<<temp_y<<endl;
							cvLine(pImg,cvPoint(x,y),cvPoint(temp_x,temp_y),CV_RGB(0,0,0));
						}
					}
				}

			}

			DWORD end_time = GetTickCount();

			//cvNamedWindow("Complete Image(EndPoint)");
			//cvShowImage("Complete Image(EndPoint)",pImg);
			cvSaveImage("D://log/complete_end_image.bmp",pImg);

			timeSpan = end_time - start_time;

			outfile2.close();
			UpdateAllViews(NULL);

			//char str[200];
			//sprintf(str,"Finish Get End Point.Use time: %lf ms.",timeSpan);
			//AfxMessageBox(str);

			v_timeSpan.push_back(timeSpan);
			
			cvCopy(m_image.GetImage(),m_frames[iii]);
			cvWriteFrame(writer,m_frames[iii]);
		}
		
		cvReleaseVideoWriter(&writer);
		m_image.CopyOf(m_frames[0],m_frames[0]->nChannels);

		UpdateAllViews(NULL);	

		if(v_timeSpan.size() != 0)
		{
			ofstream res_file("D://log/res_time.txt");

			double total_timeSpan = 0.0;
			for(int i = 0; i < v_timeSpan.size(); ++i)
			{
				total_timeSpan += v_timeSpan[i];
				res_file << "frameNum = " << i << " , timeSpan = " << v_timeSpan[i] << " ms" << endl;
			}
			res_file.close();
		
			char str[200];
			sprintf(str,"Finish Complete Isolate Point.Use time:%lf ms",total_timeSpan);
			AfxMessageBox(str);
		}

	}

}

void CImageProcessDoc::OnMenuitemSoybeancompletemannal() 
{
	// TODO: Add your command handler code here
	m_bmannal = !m_bmannal;
}

void CImageProcessDoc::DrawLine(CvPoint p1,CvPoint p2)
{
	IplImage *pImg = m_image.GetImage();
	cvLine(pImg,p1,p2,CV_RGB(0,0,0));
	UpdateAllViews(NULL);
}

void CImageProcessDoc::OnMenuitemSoybeancalculatebarchdata() 
{
	// TODO: Add your command handler code here

	if(type_flag == STYLE_IMAGE)
	{
		int idx_x[]={-1,0,1,1,1,0,-1,-1};
		int idx_y[]={-1,-1,-1,0,1,1,1,0};
		ofstream outfile1("D://log/brach_point.txt");

		int x,y,i,j;
		CvScalar scalar,s1;
		int temp_x,temp_y;


		IplImage *pImg = m_image.GetImage();
		for(x = 1; x < pImg->width-1; ++x)
		{
			for(y = 1; y < pImg->height - 1; ++y)
			{
				scalar = cvGet2D(pImg,y,x);
				if(scalar.val[0] == 0)
				{
					int count = 0;
					for(i = 0; i < 8; ++i)
					{
						temp_x = x + idx_x[i];
						temp_y = y + idx_y[i];

						s1 = cvGet2D(pImg,temp_y,temp_x);
						if(s1.val[0] == 0) ++count;
					}
					if(count > 2)
					{
						outfile1<<"x="<<x<<",y="<<y<<",brach NO.="<<(count-1)<<endl;
					}
				}
			}
		}

		outfile1.close();

		int count_brach = 0;

		//int x,y;
		int pre_x,pre_y;
		//int temp_x,temp_y;
		int next_x,next_y;
		int count;
		int a_x,a_y;
		int b_x,b_y;
		//CvScalar scalar,s1;
		//int i,j;
		int pre_idx;
		int start_x,start_y;


		queue<int> q_x;
		queue<int> q_y;
		queue<int> q_pre_x;
		queue<int> q_pre_y;

		vector<vector<int> > v_v_brach_x;
		vector<vector<int> > v_v_brach_y;

		//int idx_x[]={1,1,0,-1,-1,-1,0,1};
		//int idx_y[]={0,-1,-1,-1,0,1,1,1};
		//int idx_x[] = {0,-1,1,0};
		//int idx_y[] = {-1,0,0,1};
		int num_idx = 8;

		int *adj = new int[num_idx];

		ofstream outfile2("D://log/show_brach_root.txt");


		IplImage *show_image = cvCreateImage(cvGetSize(pImg),IPL_DEPTH_8U,1);
		cvZero(show_image);

		int *mark = new int[pImg->width * pImg->height];
		memset(mark,0,sizeof(int)*pImg->width*pImg->height);
			
		//find start end point
		for(x = 1; x < pImg->width-1; ++x)
		{
			for(y = 1; y < pImg->height - 1; ++y)
			{
				scalar = cvGet2D(pImg,y,x);
				if(scalar.val[0] == 0)
				{
					count = 0;
					for(i = 0; i < num_idx; ++i)
					{
						temp_x = x + idx_x[i];
						temp_y = y + idx_y[i];

						s1 = cvGet2D(pImg,temp_y,temp_x);
						if(s1.val[0] == 0)
						{
							++count;
							next_x = temp_x;
							next_y = temp_y;
						}
								
					}
					if(count == 1)
					{
						q_x.push(next_x);
						q_y.push(next_y);
						q_pre_x.push(x);
						q_pre_y.push(y);
						//outfile2<<"pre_x="<<x<<",pre_y="<<y<<",x="<<next_x<<",y="<<next_y<<endl;
						//break;
					}
				}
			}
			if(y < pImg->height - 1) break;
		}
		int brach_length;
		while(!q_x.empty())
		{
			pre_x = q_pre_x.front();
			pre_y = q_pre_y.front();
			x = q_x.front();
			y = q_y.front();
			q_pre_x.pop();
			q_pre_y.pop();
			q_x.pop();
			q_y.pop();

			vector<int> v_brach_x;
			vector<int> v_brach_y;

			if(mark[y * pImg->width + x] == 1) continue;

			start_x = pre_x;
			start_y = pre_y;

			outfile2<<"("<<pre_x<<","<<pre_y<<") ";
			v_brach_x.push_back(pre_x);
			v_brach_y.push_back(pre_y);
			brach_length = 1;

			while(1)
			{	
				if(x < 0 || x >= pImg->height || y < 0 || y >= pImg->width) break;

				if(mark[y * pImg->width + x] == 0) mark[y * pImg->width + x] = 1;
				else break;

				outfile2<<"("<<x<<","<<y<<") ";
				v_brach_x.push_back(x);
				v_brach_y.push_back(y);
				++brach_length;

				memset(adj,0,sizeof(int)*num_idx);
				count = 0;
				for(i = 0; i < num_idx; ++i)
				{
					temp_x = x + idx_x[i];
					temp_y = y + idx_y[i];

					if(temp_x < 0 || temp_x >= pImg->width || temp_y < 0 || temp_y >=pImg->height) continue;
						
					if(temp_x != pre_x || temp_y != pre_y)
					{
						s1 = cvGet2D(pImg,temp_y,temp_x);
						if(s1.val[0] == 0)
						{
							adj[i] = 1;
							++count;
						}
					}
					else
					{
						adj[i] = -1;
						pre_idx = i;
					}
				}
				if(count == 1)
				{
					for(i = 0; i < num_idx; ++i)
					{
						if(adj[i] == 1)
						{
							pre_x = x;
							pre_y = y;
							x = x + idx_x[i];
							y = y + idx_y[i];
							break;
						}
					}
				}
				else if(count >= 2)
				{
					pre_idx = (pre_idx + num_idx/2) % num_idx;
					for(i = 0; i < num_idx/2; ++i)
					{
						if(adj[(pre_idx - i + num_idx) % num_idx] == 1)
						{
							next_x = x + idx_x[(pre_idx - i + num_idx) % num_idx];
							next_y = y + idx_y[(pre_idx - i + num_idx) % num_idx];
							adj[(pre_idx - i + num_idx) % num_idx] = -1;
							outfile2<<endl;
							break;
						}
						else if(adj[(pre_idx + i) % num_idx] == 1)
						{
							next_x = x + idx_x[(pre_idx + i) % num_idx];
							next_y = y + idx_y[(pre_idx + i) % num_idx];
							adj[(pre_idx + i) % num_idx] = -1;
							outfile2<<endl;
							break;
						}
					}
					int brach_count = 0;
					for(i = 0; i < num_idx/2; ++i)
					{
						if(adj[i * 2] == 1 && adj[(i * 2 - 1 + num_idx) % num_idx] != -1 && adj[(i * 2 + 1) % num_idx] != -1)
						{
							++brach_count;
						}
						if(adj[1 + i * 2] == 1 && adj[i * 2] == 0 && adj[(i * 2 + 2) % num_idx] == 0)
						{
							++brach_count;
						}
					}
					if(brach_count > 1 && false)
					{
						mark[y * pImg->width + x] = 0;
					}
					else
					{
						for(i = 0; i < num_idx/2; ++i)
						{
							if(adj[i * 2] == 1 && adj[(i * 2 - 1 + num_idx) % num_idx] != -1 && adj[(i * 2 + 1) % num_idx] != -1)
							{
								q_pre_x.push(x);
								q_pre_y.push(y);
								q_x.push(x + idx_x[i * 2]);
								q_y.push(y + idx_y[i * 2]);
							}
							if(adj[1 + i * 2] == 1 && adj[i * 2] == 0 && adj[(i * 2 + 2) % num_idx] == 0)
							{
								q_pre_x.push(x);
								q_pre_y.push(y);
								q_x.push(x + idx_x[1 + i * 2]);
								q_y.push(y + idx_y[1 + i * 2]);
							}
						}
					}

						
					pre_x = x;
					pre_y = y;
					x = next_x;
					y = next_y;
				}
				else break;
			}
			outfile2<<endl;
			outfile2<<"brach_length="<<brach_length<<endl;
			outfile2<<endl;

			v_v_brach_x.push_back(v_brach_x);
			v_v_brach_y.push_back(v_brach_y);

			cvLine(show_image,cvPoint(start_x,start_y),cvPoint(x,y),CV_RGB(255,255,255));
		
		}


		cvNamedWindow("Brach Image");
		cvShowImage("Brach Image",show_image);


		outfile2.close();
		UpdateAllViews(NULL);
		delete []adj;

		//Post processing
		int val1 = 10;
		int v_i,v_j;
		ofstream outfile3("D://log/show_brach_root_merger.txt");

		IplImage *show_image2 = cvCreateImage(cvGetSize(pImg),IPL_DEPTH_8U,1);
		cvZero(show_image2);
		
		/*for(v_i = 0; v_i != v_v_brach_x.size(); ++v_i)
		{
			for(v_j = v_i + 1; v_j != v_v_brach_x.size(); ++v_j)
			{
				if(abs(v_v_brach_x[v_i][0] - v_v_brach_x[v_j][v_v_brach_x[v_j].size() - 1]) <= val1 
					&& abs(v_v_brach_y[v_i][0] - v_v_brach_y[v_j][v_v_brach_y[v_j].size() - 1]) <= val1)
				{
					vector<int> v_brach_merg_x;
					vector<int> v_brach_merg_y;

					v_brach_merg_x.insert(v_brach_merg_x.end(),v_v_brach_x[v_j].begin(),v_v_brach_x[v_j].end());
					v_brach_merg_x.insert(v_brach_merg_x.end(),v_v_brach_x[v_i].begin(),v_v_brach_x[v_i].end());


					v_brach_merg_y.insert(v_brach_merg_y.end(),v_v_brach_y[v_j].begin(),v_v_brach_y[v_j].end());
					v_brach_merg_y.insert(v_brach_merg_y.end(),v_v_brach_y[v_i].begin(),v_v_brach_y[v_i].end());

					v_v_brach_x.erase(&v_v_brach_x[v_j]);
					v_v_brach_x.erase(&v_v_brach_x[v_i]);
					v_v_brach_x.insert(&v_v_brach_x[v_i],v_brach_merg_x);

					v_v_brach_y.erase(&v_v_brach_y[v_j]);
					v_v_brach_y.erase(&v_v_brach_y[v_i]);
					v_v_brach_y.insert(&v_v_brach_y[v_i],v_brach_merg_y);
					break;
				}
				
				if(abs( v_v_brach_x[v_i][v_v_brach_x[v_i].size() - 1] - v_v_brach_x[v_j][0]) <= val1
					&& abs( v_v_brach_y[v_i][v_v_brach_y[v_i].size() - 1] - v_v_brach_y[v_j][0]) <= val1)
				{
					vector<int> v_brach_merg_x;
					vector<int> v_brach_merg_y;

					v_brach_merg_x.insert(v_brach_merg_x.end(),v_v_brach_x[v_i].begin(),v_v_brach_x[v_i].end());
					v_brach_merg_x.insert(v_brach_merg_x.end(),v_v_brach_x[v_j].begin(),v_v_brach_x[v_j].end());


					v_brach_merg_y.insert(v_brach_merg_y.end(),v_v_brach_y[v_i].begin(),v_v_brach_y[v_i].end());
					v_brach_merg_y.insert(v_brach_merg_y.end(),v_v_brach_y[v_j].begin(),v_v_brach_y[v_j].end());

					v_v_brach_x.erase(&v_v_brach_x[v_j]);
					v_v_brach_x.erase(&v_v_brach_x[v_i]);
					v_v_brach_x.insert(&v_v_brach_x[v_i],v_brach_merg_x);

					v_v_brach_y.erase(&v_v_brach_y[v_j]);
					v_v_brach_y.erase(&v_v_brach_y[v_i]);
					v_v_brach_y.insert(&v_v_brach_y[v_i],v_brach_merg_y);
					break;
				}
			}
		}*/

		outfile3 << "Brach Numuber Total:" << v_v_brach_x.size() << endl;
		outfile3 << endl;
		for(v_i = 0; v_i != v_v_brach_x.size(); ++v_i)
		{
			outfile3 << "Brach " << (v_i + 1) << " :" << endl;
			outfile3 << "Brach Length:" << v_v_brach_x[v_i].size() << endl;

			cvLine(show_image2,cvPoint(v_v_brach_x[v_i][0],v_v_brach_y[v_i][0]),cvPoint(v_v_brach_x[v_i][v_v_brach_x[v_i].size() - 1],v_v_brach_y[v_i][v_v_brach_y[v_i].size() - 1]),CV_RGB(255,255,255));

			for(v_j = 0; v_j != v_v_brach_x[v_i].size(); ++v_j)
			{
				outfile3 << "(" << v_v_brach_x[v_i][v_j] << "," << v_v_brach_y[v_i][v_j] << ")";
			}
			outfile3 << endl;
		}
		outfile3.close();

		//cvNamedWindow("Brach Image(merger)");
		//cvShowImage("Brach Image(merger)",show_image2);

		AfxMessageBox("Finish.");
	}
	else if(type_flag == STYLE_VIDEO)
	{
		ofstream outfile1("D://log/brach_point.txt");
		
		ofstream outfile2("D://log/show_brach_root.txt");
		
		ofstream outfile3("D://log/show_brach_root_merger.txt");

		int frame_total_branch = 0;

		for(int iii = 0; iii < m_frame_count; ++iii)
		{
			IplImage *lp_frame = m_frames[iii];
			m_image.CopyOf(lp_frame,lp_frame->nChannels);

			
			int idx_x[]={-1,0,1,1,1,0,-1,-1};
			int idx_y[]={-1,-1,-1,0,1,1,1,0};

			int x,y,i,j;
			CvScalar scalar,s1;
			int temp_x,temp_y;


			IplImage *pImg = m_image.GetImage();
			for(x = 1; x < pImg->width-1; ++x)
			{
				for(y = 1; y < pImg->height - 1; ++y)
				{
					scalar = cvGet2D(pImg,y,x);
					if(scalar.val[0] == 0)
					{
						int count = 0;
						for(i = 0; i < 8; ++i)
						{
							temp_x = x + idx_x[i];
							temp_y = y + idx_y[i];

							s1 = cvGet2D(pImg,temp_y,temp_x);
							if(s1.val[0] == 0) ++count;
						}
						if(count > 2)
						{
							outfile1<<"frameNum = " << iii << " ,x="<<x<<",y="<<y<<",brach NO.="<<(count-1)<<endl;
						}
					}
				}
			}


			int count_brach = 0;

			//int x,y;
			int pre_x,pre_y;
			//int temp_x,temp_y;
			int next_x,next_y;
			int count;
			int a_x,a_y;
			int b_x,b_y;
			//CvScalar scalar,s1;
			//int i,j;
			int pre_idx;
			int start_x,start_y;


			queue<int> q_x;
			queue<int> q_y;
			queue<int> q_pre_x;
			queue<int> q_pre_y;

			vector<vector<int> > v_v_brach_x;
			vector<vector<int> > v_v_brach_y;

			//int idx_x[]={1,1,0,-1,-1,-1,0,1};
			//int idx_y[]={0,-1,-1,-1,0,1,1,1};
			//int idx_x[] = {0,-1,1,0};
			//int idx_y[] = {-1,0,0,1};
			int num_idx = 8;

			int *adj = new int[num_idx];

			outfile2 << "frameNum = " << iii << endl;
			outfile2 << endl;

			IplImage *show_image = cvCreateImage(cvGetSize(pImg),IPL_DEPTH_8U,1);
			cvZero(show_image);

			int *mark = new int[pImg->width * pImg->height];
			memset(mark,0,sizeof(int)*pImg->width*pImg->height);
				
			//find start end point
			for(x = 1; x < pImg->width-1; ++x)
			{
				for(y = 1; y < pImg->height - 1; ++y)
				{
					scalar = cvGet2D(pImg,y,x);
					if(scalar.val[0] == 0)
					{
						count = 0;
						for(i = 0; i < num_idx; ++i)
						{
							temp_x = x + idx_x[i];
							temp_y = y + idx_y[i];

							s1 = cvGet2D(pImg,temp_y,temp_x);
							if(s1.val[0] == 0)
							{
								++count;
								next_x = temp_x;
								next_y = temp_y;
							}
									
						}
						if(count == 1)
						{
							q_x.push(next_x);
							q_y.push(next_y);
							q_pre_x.push(x);
							q_pre_y.push(y);
							//outfile2<<"pre_x="<<x<<",pre_y="<<y<<",x="<<next_x<<",y="<<next_y<<endl;
							//break;
						}
					}
				}
				if(y < pImg->height - 1) break;
			}
			int brach_length;
			while(!q_x.empty())
			{
				pre_x = q_pre_x.front();
				pre_y = q_pre_y.front();
				x = q_x.front();
				y = q_y.front();
				q_pre_x.pop();
				q_pre_y.pop();
				q_x.pop();
				q_y.pop();

				vector<int> v_brach_x;
				vector<int> v_brach_y;

				if(mark[y * pImg->width + x] == 1) continue;

				start_x = pre_x;
				start_y = pre_y;

				outfile2<<"("<<pre_x<<","<<pre_y<<") ";
				v_brach_x.push_back(pre_x);
				v_brach_y.push_back(pre_y);
				brach_length = 1;

				while(1)
				{	
					if(x < 0 || x >= pImg->height || y < 0 || y >= pImg->width) break;

					if(mark[y * pImg->width + x] == 0) mark[y * pImg->width + x] = 1;
					else break;

					outfile2<<"("<<x<<","<<y<<") ";
					v_brach_x.push_back(x);
					v_brach_y.push_back(y);
					++brach_length;

					memset(adj,0,sizeof(int)*num_idx);
					count = 0;
					for(i = 0; i < num_idx; ++i)
					{
						temp_x = x + idx_x[i];
						temp_y = y + idx_y[i];

						if(temp_x < 0 || temp_x >= pImg->width || temp_y < 0 || temp_y >=pImg->height) continue;
							
						if(temp_x != pre_x || temp_y != pre_y)
						{
							s1 = cvGet2D(pImg,temp_y,temp_x);
							if(s1.val[0] == 0)
							{
								adj[i] = 1;
								++count;
							}
						}
						else
						{
							adj[i] = -1;
							pre_idx = i;
						}
					}
					if(count == 1)
					{
						for(i = 0; i < num_idx; ++i)
						{
							if(adj[i] == 1)
							{
								pre_x = x;
								pre_y = y;
								x = x + idx_x[i];
								y = y + idx_y[i];
								break;
							}
						}
					}
					else if(count >= 2)
					{
						pre_idx = (pre_idx + num_idx/2) % num_idx;
						for(i = 0; i < num_idx/2; ++i)
						{
							if(adj[(pre_idx - i + num_idx) % num_idx] == 1)
							{
								next_x = x + idx_x[(pre_idx - i + num_idx) % num_idx];
								next_y = y + idx_y[(pre_idx - i + num_idx) % num_idx];
								adj[(pre_idx - i + num_idx) % num_idx] = -1;
								outfile2<<endl;
								break;
							}
							else if(adj[(pre_idx + i) % num_idx] == 1)
							{
								next_x = x + idx_x[(pre_idx + i) % num_idx];
								next_y = y + idx_y[(pre_idx + i) % num_idx];
								adj[(pre_idx + i) % num_idx] = -1;
								outfile2<<endl;
								break;
							}
						}
						int brach_count = 0;
						for(i = 0; i < num_idx/2; ++i)
						{
							if(adj[i * 2] == 1 && adj[(i * 2 - 1 + num_idx) % num_idx] != -1 && adj[(i * 2 + 1) % num_idx] != -1)
							{
								++brach_count;
							}
							if(adj[1 + i * 2] == 1 && adj[i * 2] == 0 && adj[(i * 2 + 2) % num_idx] == 0)
							{
								++brach_count;
							}
						}
						if(brach_count > 1 && false)
						{
							mark[y * pImg->width + x] = 0;
						}
						else
						{
							for(i = 0; i < num_idx/2; ++i)
							{
								if(adj[i * 2] == 1 && adj[(i * 2 - 1 + num_idx) % num_idx] != -1 && adj[(i * 2 + 1) % num_idx] != -1)
								{
									q_pre_x.push(x);
									q_pre_y.push(y);
									q_x.push(x + idx_x[i * 2]);
									q_y.push(y + idx_y[i * 2]);
								}
								if(adj[1 + i * 2] == 1 && adj[i * 2] == 0 && adj[(i * 2 + 2) % num_idx] == 0)
								{
									q_pre_x.push(x);
									q_pre_y.push(y);
									q_x.push(x + idx_x[1 + i * 2]);
									q_y.push(y + idx_y[1 + i * 2]);
								}
							}
						}

							
						pre_x = x;
						pre_y = y;
						x = next_x;
						y = next_y;
					}
					else break;
				}
				outfile2<<endl;
				outfile2<<"brach_length="<<brach_length<<endl;
				outfile2 << "-------------------------------------------------------------------------" << endl;
				outfile2<<endl;

				v_v_brach_x.push_back(v_brach_x);
				v_v_brach_y.push_back(v_brach_y);

				cvLine(show_image,cvPoint(start_x,start_y),cvPoint(x,y),CV_RGB(255,255,255));
			
			}


			//cvNamedWindow("Brach Image");
			//cvShowImage("Brach Image",show_image);


			UpdateAllViews(NULL);
			delete []adj;

			//Post processing
			int val1 = 10;
			int v_i,v_j;
			outfile3 << "frameNum = " << iii << endl;
			outfile3 << endl;

			IplImage *show_image2 = cvCreateImage(cvGetSize(pImg),IPL_DEPTH_8U,1);
			cvZero(show_image2);
			
			/*for(v_i = 0; v_i != v_v_brach_x.size(); ++v_i)
			{
				for(v_j = v_i + 1; v_j != v_v_brach_x.size(); ++v_j)
				{
					if(abs(v_v_brach_x[v_i][0] - v_v_brach_x[v_j][v_v_brach_x[v_j].size() - 1]) <= val1 
						&& abs(v_v_brach_y[v_i][0] - v_v_brach_y[v_j][v_v_brach_y[v_j].size() - 1]) <= val1)
					{
						vector<int> v_brach_merg_x;
						vector<int> v_brach_merg_y;

						v_brach_merg_x.insert(v_brach_merg_x.end(),v_v_brach_x[v_j].begin(),v_v_brach_x[v_j].end());
						v_brach_merg_x.insert(v_brach_merg_x.end(),v_v_brach_x[v_i].begin(),v_v_brach_x[v_i].end());


						v_brach_merg_y.insert(v_brach_merg_y.end(),v_v_brach_y[v_j].begin(),v_v_brach_y[v_j].end());
						v_brach_merg_y.insert(v_brach_merg_y.end(),v_v_brach_y[v_i].begin(),v_v_brach_y[v_i].end());

						v_v_brach_x.erase(&v_v_brach_x[v_j]);
						v_v_brach_x.erase(&v_v_brach_x[v_i]);
						v_v_brach_x.insert(&v_v_brach_x[v_i],v_brach_merg_x);

						v_v_brach_y.erase(&v_v_brach_y[v_j]);
						v_v_brach_y.erase(&v_v_brach_y[v_i]);
						v_v_brach_y.insert(&v_v_brach_y[v_i],v_brach_merg_y);
						break;
					}
					
					if(abs( v_v_brach_x[v_i][v_v_brach_x[v_i].size() - 1] - v_v_brach_x[v_j][0]) <= val1
						&& abs( v_v_brach_y[v_i][v_v_brach_y[v_i].size() - 1] - v_v_brach_y[v_j][0]) <= val1)
					{
						vector<int> v_brach_merg_x;
						vector<int> v_brach_merg_y;

						v_brach_merg_x.insert(v_brach_merg_x.end(),v_v_brach_x[v_i].begin(),v_v_brach_x[v_i].end());
						v_brach_merg_x.insert(v_brach_merg_x.end(),v_v_brach_x[v_j].begin(),v_v_brach_x[v_j].end());


						v_brach_merg_y.insert(v_brach_merg_y.end(),v_v_brach_y[v_i].begin(),v_v_brach_y[v_i].end());
						v_brach_merg_y.insert(v_brach_merg_y.end(),v_v_brach_y[v_j].begin(),v_v_brach_y[v_j].end());

						v_v_brach_x.erase(&v_v_brach_x[v_j]);
						v_v_brach_x.erase(&v_v_brach_x[v_i]);
						v_v_brach_x.insert(&v_v_brach_x[v_i],v_brach_merg_x);

						v_v_brach_y.erase(&v_v_brach_y[v_j]);
						v_v_brach_y.erase(&v_v_brach_y[v_i]);
						v_v_brach_y.insert(&v_v_brach_y[v_i],v_brach_merg_y);
						break;
					}
				}
			}*/

			frame_total_branch += v_v_brach_x.size();
			outfile3 << "Brach Numuber Total:" << v_v_brach_x.size() << endl;
			outfile3 << endl;
			for(v_i = 0; v_i != v_v_brach_x.size(); ++v_i)
			{
				outfile3 << "Brach " << (v_i + 1) << " :" << endl;
				outfile3 << "Brach Length:" << v_v_brach_x[v_i].size() << endl;

				cvLine(show_image2,cvPoint(v_v_brach_x[v_i][0],v_v_brach_y[v_i][0]),cvPoint(v_v_brach_x[v_i][v_v_brach_x[v_i].size() - 1],v_v_brach_y[v_i][v_v_brach_y[v_i].size() - 1]),CV_RGB(255,255,255));

				for(v_j = 0; v_j != v_v_brach_x[v_i].size(); ++v_j)
				{
					outfile3 << "(" << v_v_brach_x[v_i][v_j] << "," << v_v_brach_y[v_i][v_j] << ")";
				}
				outfile3 << endl;
			}
			outfile3 << "---------------------------------------------------------------" << endl;

			//cvNamedWindow("Brach Image(merger)");
			//cvShowImage("Brach Image(merger)",show_image2);

			//AfxMessageBox("Finish.");

		}	

		outfile3 << "Average brach Num:" << frame_total_branch/m_frame_count << endl;
		
		outfile1.close();
		
		outfile2.close();
		
		outfile3.close();

		AfxMessageBox("Finish.");
	}



}

void CImageProcessDoc::OnMenuitemSoybeancompleteauto() 
{
	// TODO: Add your command handler code here
	OnMenuitemSoybeancompleteisolationpoint();
	OnMENUITEMSoybeanCompleteEndPoint();

}

void CImageProcessDoc::OnMenuitemZhangextendpretreatment() 
{
	// TODO: Add your command handler code here
	OnMenuitemGetgrayimage();
	OnMenuitemGetthresholdimageotsu();

	AfxMessageBox("Finish Zhang Extend Pretreatment");
}

void CImageProcessDoc::OnMenuitemZhangextendzhang() 
{
	// TODO: Add your command handler code here
	OnMenuitemGetreverseimage();
	OnMenuitemGetthinimagezhang();
	OnMenuitemGetreverseimage();

	AfxMessageBox("Finish Get Thin Image(Zhang)");
}

void CImageProcessDoc::OnMenuitemZhangextendsinglepixel() 
{
	// TODO: Add your command handler code here
	OnMenuitemGetreverseimage();

	int x,y;
	int i;
	CvScalar scalar;

	int idx_x[] = {0,1,1,1,0,-1,-1,-1};
	int idx_y[] = {-1,-1,0,1,1,1,0,-1};

	ofstream outfile1("D://log/single_pixel_point.txt");


	IplImage *pImg = m_image.GetImage();

	cvConvertScale(pImg,pImg,1.0/255);

	bool **mark = new bool*[pImg->height];
	bool **del_mark = new bool*[pImg->height];
	for(y = 0; y < pImg->height; ++y)
	{
		mark[y] = new bool[pImg->width];
		del_mark[y] = new bool[pImg->width];
		memset(mark[y],0,sizeof(bool) * pImg->width);
		memset(del_mark[y],0,sizeof(bool) * pImg->width);
	}

	for(y = 1; y < pImg -> height - 1; ++y)
	{
		for(x = 1; x < pImg -> width - 1; ++x)
		{
			scalar = cvGet2D(pImg,y,x);

			//outfile1 << "x = " << x << " , y = " << y << " ,value = " << scalar.val[0] << endl;

			if(scalar.val[0] && mark[y][x] == false)
			{
				queue<CPoint> q_point;
				q_point.push(CPoint(x,y));
				mark[y][x] = true;

				int flag;
				while(!q_point.empty())
				{
					flag = 0;
					CPoint point = q_point.front();
					q_point.pop();
					x = point.x;
					y = point.y;
					
					int temp_x,temp_y;
					for(i = 1; i < 8; i += 2)
					{
						temp_x = x + idx_x[i];
						temp_y = y + idx_y[i];

						if(temp_x < 0 || temp_x >= pImg -> width || temp_y < 0 || temp_y >= pImg -> height) continue;

						scalar = cvGet2D(pImg,temp_y,temp_x);

						if(scalar.val[0])
						{
							q_point.push(CPoint(temp_x,temp_y));
							flag = 1;
							scalar.val[0] = 1 - scalar.val[0];
							cvSet2D(pImg,temp_y,temp_x,scalar);

						}
					}

					if(flag)
					{
						for(i = 0; i < 8; i += 2)
						{
							temp_x = x + idx_x[i];
							temp_y = y + idx_y[i];

							if(temp_x < 0 || temp_x >= pImg -> width || temp_y < 0 || temp_y >= pImg -> height) continue;

							scalar = cvGet2D(pImg,temp_y,temp_x);

							if(scalar.val[0])
							{
								del_mark[temp_y][temp_x] = true;
								//scalar.val[0] = 1 - scalar.val[0];
								//cvSet2D(pImg,temp_y,temp_x,scalar);
							}
							
						}
					}
					else
					{
						for(i = 0; i < 8; i += 2)
						{
							temp_x = x + idx_x[i];
							temp_x = y + idx_y[i];

							if(temp_x < 0 || temp_x >= pImg -> width || temp_y < 0 || temp_y >= pImg -> height) continue;

							scalar = cvGet2D(pImg,temp_y,temp_x);

							if(scalar.val[0] && mark[temp_y][temp_x] == false)
							{
								q_point.push(CPoint(temp_x,temp_y));
								mark[temp_y][temp_x] = true;
							}
						}
					}
				}
			}
		}
	}

	for(i = 0; i < pImg->height; ++i)
	{
		delete [] mark[i];
		delete [] del_mark[i];
	}
	delete [] mark;

	cvConvertScale(pImg,pImg,255.0/1);

	outfile1.close();

	OnMenuitemGetreverseimage();

	AfxMessageBox("Finish Single Pixel");

}

void CImageProcessDoc::OnMenuitemLicenseplategetgrayimage() 
{
	// TODO: Add your command handler code here
	OnMenuitemGetgrayimage();

	AfxMessageBox("Finish Get Gray Image");
}

void CImageProcessDoc::OnMenuitemGetrgbchannelimage() 
{
	// TODO: Add your command handler code here
	int i;

	IplImage *pImg = m_image.GetImage();

	CSelectRGBChannelDialog dialog;
	dialog.m_channel = 2;

	if(dialog.DoModal() == IDOK)
	{
		IplImage* channel_img[3];

		for(i = 0;i < 3; ++i)
		{
			channel_img[i] = cvCreateImage(cvGetSize(pImg),pImg->depth,1);
			if(channel_img[i]->origin != pImg->origin) channel_img[i]->origin = pImg->origin;
		}


		DWORD start_time = GetTickCount();
		cvSplit(pImg,channel_img[0],channel_img[1],channel_img[2],0);
		DWORD end_time = GetTickCount();


		char channel_names[] = "RGB";
		for(i = 0; i < 3; ++i)
		{
			char str[100];
			sprintf(str,"D://log/%c_channel_image.bmp",channel_names[i]);
			cvSaveImage(str,channel_img[i]);

			//sprintf(str,"%c Channel Image",channel_names[i]);
			//cvNamedWindow(str);
			//cvShowImage(str,channel_img[i]);
		}

		m_image.CopyOf(channel_img[dialog.m_channel],channel_img[dialog.m_channel]->nChannels);

		UpdateAllViews(NULL);

		timeSpan = end_time - start_time;
	}

}

void CImageProcessDoc::OnMenuitemLincenseplategetrgbchannelimage() 
{
	// TODO: Add your command handler code here
	OnMenuitemGetrgbchannelimage();

	AfxMessageBox("Finish Get RGB Channel Image");
}

void CImageProcessDoc::OnMenuitemGethsvchannelimage() 
{
	// TODO: Add your command handler code here
	int x,y;
	int i;
	CvScalar scalar;

	CSelectHSVChannelDialog dialog;
	dialog.m_channel = 2;
	//dialog.SetChannelsName("H","S","V");

	if(dialog.DoModal() == IDOK)
	{

		IplImage *pImg = m_image.GetImage();

		DWORD start_time = GetTickCount();
		IplImage *img_rgb = cvCreateImage(cvGetSize(pImg),IPL_DEPTH_32F,3);
		IplImage *img_hsv = cvCreateImage(cvGetSize(pImg),IPL_DEPTH_32F,3);

		cvConvertScale(pImg,img_rgb);

		cvCvtColor(img_rgb,img_hsv,CV_BGR2HSV);

		IplImage* channel_image_32f[3];
		IplImage* channel_image_8u[3];

		for(i = 0; i < 3; ++i)
		{
			channel_image_32f[i] = cvCreateImage(cvGetSize(img_hsv),IPL_DEPTH_32F,1);
			channel_image_8u[i] = cvCreateImage(cvGetSize(img_hsv),IPL_DEPTH_8U,1);
		}

		cvSplit(img_hsv,channel_image_32f[0],channel_image_32f[1],channel_image_32f[2],NULL);

		cvConvertScale(channel_image_32f[0],channel_image_8u[0]);
		cvConvertScale(channel_image_32f[1],channel_image_8u[1],255.0);
		cvConvertScale(channel_image_32f[2],channel_image_8u[2],255.0/360.0);

		DWORD end_time = GetTickCount();

		char channel_names[] = "HSV";
		for(i = 0; i < 3; ++i)
		{
				char str[100];
				sprintf(str,"D://log/%c_channel_image.bmp",channel_names[i]);
				cvSaveImage(str,channel_image_8u[i]);

				//sprintf(str,"%c Channel Image",channel_names[i]);
				//cvNamedWindow(str);
				//cvShowImage(str,channel_image_8u[i]);
		}

		m_image.CopyOf(channel_image_8u[dialog.m_channel],channel_image_8u[dialog.m_channel]->nChannels);

		UpdateAllViews(NULL);

		for(i = 0; i < 3; ++i)
		{
			cvReleaseImage(&channel_image_32f[i]);
			cvReleaseImage(&channel_image_8u[i]);
		}

		timeSpan = end_time - start_time;
	}

}

void CImageProcessDoc::OnMenuitemLicenseplategethsvchannelimage() 
{
	// TODO: Add your command handler code here
	OnMenuitemGethsvchannelimage();

	AfxMessageBox("Finish Get HSV Channel Image");
	
}


void RobertOperator(BYTE **img_data,const int height,const int width)
{
	int y,x;

	//resize;
	BYTE **src = new BYTE*[height + 2];
	src[0] = new BYTE[width + 2];
	src[0][0] = img_data[0][0];
	memcpy(&src[0][1],img_data[0],sizeof(BYTE) * width);
	src[0][width + 1] = img_data[0][width - 1];

	for(y = 1; y <= height; ++y)
	{
		src[y] = new BYTE[width + 2];
		src[y][0] = img_data[y - 1][0];
		memcpy(&src[y][1],img_data[y - 1],sizeof(BYTE) * width);
		src[y][width + 1] = img_data[y - 1][width - 1];
	}

	src[height + 1] = new BYTE[width + 2];
	src[height + 1][0] = img_data[height - 1][0];
	memcpy(&src[height + 1][1],img_data[height - 1],sizeof(BYTE) * width);
	src[height + 1][width + 1] = img_data[height - 1][width - 1];

	int sum;
	for(y = 1; y <= height; ++y)
	{
		for(x = 1; x <= width; ++x)
		{
			sum = abs(src[y][x] + src[y][x + 1] - src[y + 1][x + 1] - src[y + 1][x]);
			if(sum > 255) sum = 255;
			img_data[y - 1][x - 1] = sum;
		}
	}

	return;

}


void CImageProcessDoc::OnMenuitemRobertoperator() 
{
	// TODO: Add your command handler code here
	int i;
	int y,x;
	CvScalar scalar;

	IplImage *pImg = m_image.GetImage();

	IplImage* channel_img[3];

	for(i = 0; i < 3; ++i)
	{
		channel_img[i] = cvCreateImage( cvGetSize(pImg), 8, 1 );
		if(channel_img[i]->origin != pImg->origin) channel_img[i]->origin = pImg->origin;
	}
	cvSplit(pImg,channel_img[0],channel_img[1],channel_img[2],0);

	BYTE **img_data = new BYTE*[channel_img[0]->height];
	for(y = 0; y < channel_img[0]->height; ++y)
	{
		img_data[y] = new BYTE[channel_img[0]->width];
		for(x = 0; x < channel_img[0]->width; ++x)
		{
			scalar = cvGet2D(channel_img[0],y,x);
			img_data[y][x] = scalar.val[0];
		}
	}

	DWORD start_time = GetTickCount();
	RobertOperator(img_data,channel_img[0]->height,channel_img[0]->width);
	DWORD end_time = GetTickCount();

	for(y = 0; y < channel_img[0]->height; ++y)
	{
		for(x = 0; x < channel_img[0]->width; ++x)
		{
			scalar = cvGet2D(channel_img[0],y,x);
			scalar.val[0] = img_data[y][x];
			cvSet2D(channel_img[0],y,x,scalar);
		}
	}

	m_image.CopyOf(channel_img[0],channel_img[0]->nChannels);

	UpdateAllViews(NULL);

	timeSpan = end_time - start_time;

}

void CImageProcessDoc::OnMenuitemLicenseplaterobertoperator() 
{
	// TODO: Add your command handler code here
	OnMenuitemRobertoperator();
	OnMenuitemGetthresholdimageotsu();

	AfxMessageBox("Finish Robert Operator");
}


void CImageProcessDoc::OnMenuitemSoybeangetsegmentationimagerobert() 
{
	// TODO: Add your command handler code here
	if(type_flag == STYLE_VIDEO)
	{
		OnMenuitemVideorobertoperator();
		vector<double> temp_v_timeSpan = v_timeSpan;
		OnMenuitemVideoreverse();
		OnMenuitemVideobinarationostu();
		v_timeSpan = temp_v_timeSpan;

		if(v_timeSpan.size() != 0)
		{
			ofstream res_file("D://log/res_time.txt");

			double total_timeSpan = 0.0;
			for(int i = 0; i < v_timeSpan.size(); ++i)
			{
				total_timeSpan += v_timeSpan[i];
				res_file << "frameNum = " << i << " , timeSpan = " << v_timeSpan[i] << " ms" << endl;
			}
			res_file.close();
		
			char str[200];
			sprintf(str,"Finish Get Segmentation Image(Robert).Use time:%lf ms",total_timeSpan);
			AfxMessageBox(str);
		}
	}
	else if(type_flag == STYLE_IMAGE)
	{
		timeSpan = -1.0;
		OnMenuitemRobertoperator();
		double temp_timeSpan = timeSpan;
		OnMenuitemGetreverseimage();
		temp_timeSpan += timeSpan;
		OnMenuitemGetthresholdimageotsu();
		timeSpan += temp_timeSpan;

		if(timeSpan != -1.0)
		{
			ofstream res_file("D://log/res_time.txt");
			res_file << timeSpan << " ms" << endl;
			res_file << timeSpan / 1000 << " s" << endl;
			res_file.close();

			char str[200];
			sprintf(str,"Finish Robert Operator.Use time:%lf ms",timeSpan);
			AfxMessageBox(str);
		}
	}
}



void CImageProcessDoc::OnMenuitemSmoothfiltering() 
{
	// TODO: Add your command handler code here
	int i;

	IplImage *pImg = m_image.GetImage();

	IplImage* channel_img[3];

	for(i = 0; i < 3; ++i)
	{
		channel_img[i] = cvCreateImage( cvGetSize(pImg), 8, 1 );
		if(channel_img[i]->origin != pImg->origin) channel_img[i]->origin = pImg->origin;
	}
	cvSplit(pImg,channel_img[0],channel_img[1],channel_img[2],0);

	int size = 3;

	CSelectSize dialog;
	dialog.m_size = size;

	if(dialog.DoModal() == IDOK)
	{
		size = dialog.m_size;

		DWORD start_time = GetTickCount();

		IplImage *smooth_image = cvCreateImage(cvGetSize(channel_img[0]),channel_img[0]->depth,1);
		if(smooth_image->origin != channel_img[0]->origin) smooth_image->origin = channel_img[0]->origin;

		cvSmooth(channel_img[0],smooth_image,CV_MEDIAN,size,size,0,0);

		DWORD end_time = GetTickCount();

		m_image.CopyOf(smooth_image,smooth_image->nChannels);

		for(i = 0; i < 3; ++i) cvReleaseImage(&channel_img[i]);
		cvReleaseImage(&smooth_image);

		timeSpan = end_time - start_time;
	}


}

//0 represent x,1 represent y,2 represent max,3 represent sun
void PrewittOperator(BYTE **img_data,const int height,const int width,int direction)
{

	int y,x;
	int i,j;

	//resize;
	BYTE **src = new BYTE*[height + 2];

	src[0] = new BYTE[width + 2];
	src[0][0] = img_data[0][0];
	memcpy(&src[0][1],img_data[0],sizeof(BYTE) * width);
	src[0][width + 1] = img_data[0][width - 1];

	for(y = 1; y <= height; ++y)
	{
		src[y] = new BYTE[width + 2];
		src[y][0] = img_data[y - 1][0];
		memcpy(&src[y][1],img_data[y - 1],sizeof(BYTE) * width);
		src[y][width + 1] = img_data[y - 1][width - 1];
	}

	src[height + 1] = new BYTE[width + 2];
	src[height + 1][0] = img_data[height - 1][0];
	memcpy(&src[height + 1][1],img_data[height - 1],sizeof(BYTE) * width);
	src[height + 1][width + 1] = img_data[height - 1][width - 1];

	for(y = 1; y <= height; ++y)
	{
		for(x = 1; x <= width; ++x)
		{
			BYTE p1 = src[y - 1][x - 1];
			BYTE p2 = src[y - 1][x];
			BYTE p3 = src[y - 1][x + 1];
			BYTE p4 = src[y][x - 1];
			BYTE p5 = src[y][x];
			BYTE p6 = src[y][x + 1];
			BYTE p7 = src[y + 1][x - 1];
			BYTE p8 = src[y + 1][x];
			BYTE p9 = src[y + 1][x + 1];

			int count_x = abs(((int)p3 + p6 + p9) - (p1 + p4 + p8));//x
			int count_y = abs(((int)p7 + p8 + p9) - (p1 + p2 + p3));//y

			int count;
			if(direction == 0) count = count_x;
			else if(direction == 1) count = count_y;
			else if(direction == 2) count = count_x > count_y ? count_x : count_y;
			else count = count_x + count_y;

			if(count > 255) img_data[y - 1][x - 1] = 255;
			else img_data[y - 1][x - 1] = count;
		}
	}
}

void CImageProcessDoc::OnMenuitemPrewittoperator() 
{
	// TODO: Add your command handler code here
	int i;
	int y,x;
	CvScalar scalar;

	CSlectCalculateStyleDialog dialog;
	dialog.m_style = 3;

	if(dialog.DoModal() == IDOK)
	{
		IplImage *pImg = m_image.GetImage();

		IplImage* channel_img[3];

		for(i = 0; i < 3; ++i)
		{
			channel_img[i] = cvCreateImage( cvGetSize(pImg), 8, 1 );
			if(channel_img[i]->origin != pImg->origin) channel_img[i]->origin = pImg->origin;
		}
		cvSplit(pImg,channel_img[0],channel_img[1],channel_img[2],0);

		BYTE **img_data = new BYTE*[channel_img[0]->height];
		for(y = 0; y < channel_img[0]->height; ++y)
		{
			img_data[y] = new BYTE[channel_img[0]->width];
			for(x = 0; x < channel_img[0]->width; ++x)
			{
				scalar = cvGet2D(channel_img[0],y,x);
				img_data[y][x] = scalar.val[0];
			}
		}

		DWORD start_time = GetTickCount();
		PrewittOperator(img_data,channel_img[0]->height,channel_img[0]->width,dialog.m_style);
		DWORD end_time = GetTickCount();

		for(y = 0; y < channel_img[0]->height; ++y)
		{
			for(x = 0; x < channel_img[0]->width; ++x)
			{
				scalar = cvGet2D(channel_img[0],y,x);
				scalar.val[0] = img_data[y][x];
				cvSet2D(channel_img[0],y,x,scalar);
			}
		}

		m_image.CopyOf(channel_img[0],channel_img[0]->nChannels);

		UpdateAllViews(NULL);

		timeSpan = end_time - start_time;
	}

}



void CImageProcessDoc::OnMenuitemSoybeangetsmoothimage() 
{
	// TODO: Add your command handler code here
	if(type_flag == STYLE_VIDEO)
	{
		OnMenuitemVideosmoothfilter();
		if(v_timeSpan.size() != 0)
		{
			ofstream res_file("D://log/res_time.txt");

			double total_timeSpan = 0.0;
			for(int i = 0; i < v_timeSpan.size(); ++i)
			{
				total_timeSpan += v_timeSpan[i];
				res_file << "frameNum = " << i << " , timeSpan = " << v_timeSpan[i] << " ms" << endl;
			}
			res_file.close();
		
			char str[200];
			sprintf(str,"Finish Smooth Filter.Use time:%lf ms",total_timeSpan);
			AfxMessageBox(str);
		}

	}
	else if(type_flag == STYLE_IMAGE)
	{
		timeSpan = -1.0;

		OnMenuitemSmoothfiltering();

		if(timeSpan != -1.0)
		{
			ofstream res_file("D://log/res_time.txt");
			res_file << timeSpan << " ms" << endl;
			res_file << timeSpan / 1000 << " s" << endl;
			res_file.close();

			char str[200];
			sprintf(str,"Finish Smooth Filter.Use time:%lf ms",timeSpan);
			AfxMessageBox(str);
		}
	}
}

void CImageProcessDoc::OnMenuitemSoybeanrunallpretreatmentsegmatation() 
{
	// TODO: Add your command handler code here
	OnMenuitemSoybeangetgrayimage();

	OnMenuitemSmoothfiltering();
	
}

void CImageProcessDoc::OnMENUITEMSOYBEANGETSEGMENTATIONIMAGEPREWiTT() 
{
	// TODO: Add your command handler code here
	if(type_flag == STYLE_VIDEO)
	{
		OnMenuitemVideoprewittoperator();
		vector<double> temp_v_timeSpan = v_timeSpan;
		OnMenuitemVideoreverse();
		OnMenuitemVideobinarationostu();
		v_timeSpan = temp_v_timeSpan;

		if(v_timeSpan.size() != 0)
		{
			ofstream res_file("D://log/res_time.txt");

			double total_timeSpan = 0.0;
			for(int i = 0; i < v_timeSpan.size(); ++i)
			{
				total_timeSpan += v_timeSpan[i];
				res_file << "frameNum = " << i << " , timeSpan = " << v_timeSpan[i] << " ms" << endl;
			}
			res_file.close();
		
			char str[200];
			sprintf(str,"Finish Get Segmentation Image(Prewitt).Use time:%lf ms",total_timeSpan);
			AfxMessageBox(str);
		}
	}
	else if(type_flag == STYLE_IMAGE)
	{
		timeSpan = -1.0;
		OnMenuitemPrewittoperator();
		double temp_timeSpan = timeSpan;
		OnMenuitemGetreverseimage();
		temp_timeSpan += timeSpan;
		OnMenuitemGetthresholdimageotsu();
		timeSpan += temp_timeSpan;

		if(timeSpan != -1.0)
		{
			ofstream res_file("D://log/res_time.txt");
			res_file << timeSpan << " ms" << endl;
			res_file << timeSpan / 1000 << " s" << endl;
			res_file.close();

			char str[200];
			sprintf(str,"Finish Get Segmentation Image(Prewitt).Use time:%lf ms",timeSpan);
			AfxMessageBox(str);
		}
	}
}

void CImageProcessDoc::OnMenuitemLicenseplateprewittoperator() 
{
	// TODO: Add your command handler code here
	OnMenuitemPrewittoperator();
	OnMenuitemGetthresholdimageotsu();
}

void CImageProcessDoc::OnMENUITEMLicensePlateSobelOperator() 
{
	// TODO: Add your command handler code here
	OnMenuitemGetsegmentationimagesobel();
	OnMenuitemGetthresholdimageotsu();
}

void CImageProcessDoc::OnMenuitemLicenseplatecannyoperator() 
{
	// TODO: Add your command handler code here
	OnMenuitemGetsegmentationimagecanny();
	OnMenuitemGetthresholdimageotsu();

}

void CImageProcessDoc::OnMENUITEMGETHisTOGRAM() 
{
	// TODO: Add your command handler code here
	int i;

	IplImage *pImg = m_image.GetImage();

	IplImage* channel_img[3];

	for(i = 0; i < 3; ++i) channel_img[i] = cvCreateImage( cvGetSize(pImg), 8, 1 );
	cvSplit(pImg,channel_img[0],channel_img[1],channel_img[2],0);

	DWORD start_time = GetTickCount();

	int hist_size = 256;
	int hist_height = 256;
	float range[] = {0,255};
	float* ranges[] = {range};

	CvHistogram *s_hist = cvCreateHist(1,&hist_size,CV_HIST_ARRAY,ranges,1);//create
	cvCalcHist(&channel_img[0],s_hist,0,0);
	cvNormalizeHist(s_hist,1.0);

	//show histtogram

	int scale = 2;  
    //创建一张一维直方图的“图”，横坐标为灰度级，纵坐标为像素个数（*scale）  
    IplImage* hist_image = cvCreateImage(cvSize(hist_size*scale,hist_height),8,3);  
    cvZero(hist_image);  

    //统计直方图中的最大直方块  
    float max_value = 0;  
    cvGetMinMaxHistValue(s_hist, 0,&max_value,0,0);  
      
    //分别将每个直方块的值绘制到图中  
    for(i=0;i<hist_size;i++)  
    {  
        float bin_val = cvQueryHistValue_1D(s_hist,i); //像素i的概率  
        int intensity = cvRound(bin_val*hist_height/max_value);  //要绘制的高度  
        cvRectangle(hist_image,  
            cvPoint(i*scale,hist_height-1),  
            cvPoint((i+1)*scale - 1, hist_height - intensity),  
            CV_RGB(255,255,255));    
    } 

	DWORD end_time = GetTickCount();

    cvNamedWindow("S Histogram", 1);  
    cvShowImage("S Histogram", hist_image);  
  
    cvWaitKey(0);  
	cvReleaseImage(&hist_image);

	timeSpan = end_time - start_time;
}

void CImageProcessDoc::OnMenuitemBinarizationmode() 
{
	// TODO: Add your command handler code here
	int i,j;
	int x,y;
	CvScalar scalar;

	IplImage *pImg = m_image.GetImage();
	
	IplImage* channel_img[3];

	for(i = 0; i < 3; ++i) channel_img[i] = cvCreateImage( cvGetSize(pImg), 8, 1 );
	cvSplit(pImg,channel_img[0],channel_img[1],channel_img[2],0);

	IplImage *src = channel_img[0];

	DWORD start_time = GetTickCount();

	//Get Histgram
	int *arr_hist = new int[256];
	memset(arr_hist,0,sizeof(int) * 256);
	for(y = 0; y < src->height; ++y)
	{
		for(x = 0; x < src->width; ++x)
		{
			scalar = cvGet2D(src,y,x);
			arr_hist[(int)(scalar.val[0])]++;
		}
	}
	//double avg_hist = sum_hist / (src->height * src->width);

	/*ofstream outfile1("D://log/hist_num.txt");
	for(i = 0; i < 256; ++i) outfile1 << "i = " << i << ",num = " << arr_hist[i] << endl;
	outfile1.close();*/

	double val1 = 0.025;
	double c_val1 = src->height * src->width / 256 * val1;

	//find left peak
	int left_peak;
	for(i = 1; i < 256; ++i)
	{
		if(arr_hist[i - 1] > arr_hist[i])
		{
			for(j = i + 1; j < 256; ++j)
			{
				if(arr_hist[j - 1] <= arr_hist[j]) break;
			}
			if(arr_hist[j] - arr_hist[i] > c_val1) break;
			else i = j;
		}
	}
	left_peak = i;

	int right_peak;
	for(i = 256 - 1 - 1; i >= 0; --i)
	{
		if(arr_hist[i + 1] > arr_hist[i])
		{
			for(j = i - 1; j >= 0; --j)
			{
				if(arr_hist[j + 1] <= arr_hist[j]) break;
			}
			if(arr_hist[i] - arr_hist[j] > c_val1) break;
			else i = j;
		}
	}
	right_peak = i;

	if(left_peak >= right_peak)
	{
		AfxMessageBox("The Image doesn't have two peaks.So it Could not use MODE method");
	}
	else
	{
		int trough_idx = left_peak;
		for(i = left_peak;i <= right_peak; ++i)
		{
			if(arr_hist[trough_idx] > arr_hist[i]) trough_idx = i;
		}
		int trough = arr_hist[trough_idx];
		
		for(y = 0; y < src->height; ++y)
		{
			for(x = 0; x < src->width; ++x)
			{
				scalar = cvGet2D(src,y,x);
				if(scalar.val[0] <= trough) scalar.val[0] = 0;
				else scalar.val[0] = 256;
				cvSet2D(src,y,x,scalar);
			}
		}

		m_image.CopyOf(src,src->nChannels);

		UpdateAllViews(NULL);
	}

	DWORD end_time = GetTickCount();

	timeSpan = end_time - start_time;

	delete [] arr_hist;
	
}

int HistogramBins = 256;
float HistogramRange1[2]={0,255};
float *HistogramRange[1]={&HistogramRange1[0]};
typedef enum {back,object} entropy_state;

double caculateCurrentEntropy(CvHistogram * Histogram1,int cur_threshold,entropy_state state)
{
	int start,end;
	int i;

	if(state == back)
	{
		start = 0;end = cur_threshold;
	}
	else
	{
		start = cur_threshold;end = 256;
	}
	int total = 0;
	for(i=start;i<end;i++)
	{
		total += (int)cvQueryHistValue_1D(Histogram1,i);
	}
	double cur_entropy = 0.0;
	for(i=start;i<end;i++)
	{
		if((int)cvQueryHistValue_1D(Histogram1,i)==0)
		{
		continue;
		}
		double percentage = cvQueryHistValue_1D(Histogram1,i)/total;
		cur_entropy += -percentage*logf(percentage);
	}
	return cur_entropy;
}

void MaxEntropy(IplImage *src,IplImage *dst)
{
	assert(src != NULL);
	assert(src->depth == 8 && dst->depth == 8);
	assert(src->nChannels == 1);
	CvHistogram * hist =
	cvCreateHist(1,&HistogramBins,CV_HIST_ARRAY,HistogramRange);
	cvCalcHist(&src,hist);
	double maxentropy = -1.0;
	int max_index = -1;
	for(int i=0;i<HistogramBins;i++)
	{
		double cur_entropy = caculateCurrentEntropy(hist,i,object)+
		caculateCurrentEntropy(hist,i,back);
		if(cur_entropy>maxentropy)
		{
			maxentropy = cur_entropy;
			max_index = i;
		}
	}
	cvThreshold(src, dst, (double)max_index,255, CV_THRESH_BINARY);
	cvReleaseHist(&hist);
}

void CImageProcessDoc::OnMenuitemBinarizationmaxentropy() 
{
	// TODO: Add your command handler code here
	IplImage *pImg = m_image.GetImage();
	
	IplImage* channel_img[3];

	for(int i = 0; i < 3; ++i)
	{
		channel_img[i] = cvCreateImage( cvGetSize(pImg), 8, 1 );
		if(channel_img[i]->origin != pImg->origin) channel_img[i]->origin = pImg->origin;
	}
	cvSplit(pImg,channel_img[0],channel_img[1],channel_img[2],0);

	DWORD start_time = GetTickCount();

	IplImage *src = channel_img[0];

	IplImage *dst = cvCreateImage(cvGetSize(src),IPL_DEPTH_8U,1);
	if(dst->origin != src->origin) dst->origin = src->origin;

	MaxEntropy(src,dst);

	DWORD end_time = GetTickCount();

	m_image.CopyOf(dst,dst->nChannels);

	UpdateAllViews(NULL);

	timeSpan = end_time - start_time;
}

/*======================================================================*/
/* 迭代法*/
/*======================================================================*/
// nMaxIter：最大迭代次数；nDiffRec：使用给定阀值确定的亮区与暗区平均灰度差异值
int DetectThreshold(IplImage*img, int nMaxIter, int& iDiffRec) //阀值分割：迭代法
{
	//图像信息
	int height = img->height;
	int width = img->width;
	int step = img->widthStep/sizeof(uchar);
	uchar *data = (uchar*)img->imageData;
	iDiffRec =0;
	int F[256]={ 0 }; //直方图数组
	int iTotalGray=0;//灰度值和
	int iTotalPixel =0;//像素数和
	byte bt;//某点的像素值
	uchar iThrehold,iNewThrehold;//阀值、新阀值
	uchar iMaxGrayValue=0,iMinGrayValue=255;//原图像中的最大灰度值和最小灰度	值
	uchar iMeanGrayValue1,iMeanGrayValue2;

	//获取(i,j)的值，存于直方图数组F
	for(int i=0;i<width;i++)
	{
		for(int j=0;j<height;j++)
		{
			CvScalar scalar =cvGet2D(img,j,i);
			bt = scalar.val[0];
			if(bt<iMinGrayValue)
			{
				iMinGrayValue = bt;
			}
			if(bt>iMaxGrayValue)
			{
				iMaxGrayValue = bt;
			}
			F[bt]++;
		}
	}
	iThrehold =0;//
	iNewThrehold = (iMinGrayValue+iMaxGrayValue)/2;//初始阀值
	iDiffRec = iMaxGrayValue - iMinGrayValue;
	for(int a=0;(abs(iThrehold-iNewThrehold)>0.5)&&a<nMaxIter;a++)//迭代中止条件
	{
		iThrehold = iNewThrehold;
		//小于当前阀值部分的平均灰度值
		for(int i=iMinGrayValue;i<iThrehold;i++)
		{
			iTotalGray += F[i]*i;//F[]存储图像信息
			iTotalPixel += F[i];
		}
		iMeanGrayValue1 = (uchar)(iTotalGray/iTotalPixel);

		//大于当前阀值部分的平均灰度值
		iTotalPixel =0;
		iTotalGray =0;
		for(int j=iThrehold+1;j<iMaxGrayValue;j++)
		{
			iTotalGray += F[j]*j;//F[]存储图像信息
			iTotalPixel += F[j];
		}
		iMeanGrayValue2 = (uchar)(iTotalGray/iTotalPixel);
		iNewThrehold = (iMeanGrayValue2+iMeanGrayValue1)/2; //新阀值
		iDiffRec = abs(iMeanGrayValue2 - iMeanGrayValue1);
	}

	//cout<<"The Threshold of this Image in imgIteration is:"<<iThrehold<<endl;
	return iThrehold;
}

void CImageProcessDoc::OnMenuitemBinarizationiteration() 
{
	// TODO: Add your command handler code here
	CvScalar scalar;

	IplImage *pImg = m_image.GetImage();
	
	IplImage* channel_img[3];

	for(int i = 0; i < 3; ++i)
	{
		channel_img[i] = cvCreateImage( cvGetSize(pImg), 8, 1 );
		if(channel_img[i]->origin != pImg->origin) channel_img[i]->origin = pImg->origin;
	}
	cvSplit(pImg,channel_img[0],channel_img[1],channel_img[2],0);

	IplImage *src = channel_img[0];

	//IplImage *dst = cvCreateImage(cvGetSize(src),IPL_DEPTH_8U,1);

	DWORD start_time = GetTickCount();

	int nMaxIter = 200;
	int iDiffRec;
	int threshold = DetectThreshold(src,nMaxIter,iDiffRec);

	int y,x;
	for(y = 0; y < src->height; ++y)
	{
		for(x = 0; x < src->width; ++x)
		{
			scalar = cvGet2D(src,y,x);
			if(scalar.val[0] <= threshold) scalar.val[0] = 0;
			else scalar.val[0] = 256;
			cvSet2D(src,y,x,scalar);
		}
	}

	DWORD end_time = GetTickCount();

	m_image.CopyOf(src,src->nChannels);

	UpdateAllViews(NULL);

	timeSpan = end_time - start_time;
}

void CImageProcessDoc::OnMenuitemSoybeangetthresholdimagemaxentropy() 
{
	// TODO: Add your command handler code here
	if(type_flag == STYLE_VIDEO)
	{
		OnMenuitemVideobinarationmaxentropy();
		if(v_timeSpan.size() != 0)
		{
			ofstream res_file("D://log/res_time.txt");

			double total_timeSpan = 0.0;
			for(int i = 0; i < v_timeSpan.size(); ++i)
			{
				total_timeSpan += v_timeSpan[i];
				res_file << "frameNum = " << i << " , timeSpan = " << v_timeSpan[i] << " ms" << endl;
			}
			res_file.close();
		
			char str[200];
			sprintf(str,"Finish Get threshold Image(Max Entropy).Use time:%lf ms",total_timeSpan);
			AfxMessageBox(str);
		}
	}
	else if(type_flag == STYLE_IMAGE)
	{
		timeSpan = -1.0;

		OnMenuitemBinarizationmaxentropy();

		if(timeSpan != -1.0)
		{
			ofstream res_file("D://log/res_time.txt");
			res_file << timeSpan << " ms" << endl;
			res_file << timeSpan / 1000 << " s" << endl;
			res_file.close();

			char str[200];
			sprintf(str,"Finish Get threshold Image(Max Entropy).Use time:%lf ms",timeSpan);
			AfxMessageBox(str);
		}
	}

}

void CImageProcessDoc::OnMenuitemSoybeangetthresholdimageiterator() 
{
	// TODO: Add your command handler code here
	if(type_flag == STYLE_VIDEO)
	{
		OnMenuitemVideobinarizationiteration();
		if(v_timeSpan.size() != 0)
		{
			ofstream res_file("D://log/res_time.txt");

			double total_timeSpan = 0.0;
			for(int i = 0; i < v_timeSpan.size(); ++i)
			{
				total_timeSpan += v_timeSpan[i];
				res_file << "frameNum = " << i << " , timeSpan = " << v_timeSpan[i] << " ms" << endl;
			}
			res_file.close();
		
			char str[200];
			sprintf(str,"Finish Get threshold Image(iterator).Use time:%lf ms",total_timeSpan);
			AfxMessageBox(str);
		}
	}
	else if(type_flag == STYLE_IMAGE)
	{
		timeSpan = -1.0;

		OnMenuitemBinarizationiteration();

		if(timeSpan != -1.0)
		{
			ofstream res_file("D://log/res_time.txt");
			res_file << timeSpan << " ms" << endl;
			res_file << timeSpan / 1000 << " s" << endl;
			res_file.close();

			char str[200];
			sprintf(str,"Finish Get threshold Image(Iterator).Use time:%lf ms",timeSpan);
			AfxMessageBox(str);
		}
	}



}

//clockwise 0 represent 
IplImage* rotateImage(IplImage* src, int angle, bool clockwise)
{
	int angle_direction;
	if(clockwise) angle_direction = 1; else angle_direction = -1;
	angle = (angle_direction * angle + 360) % 360;
	IplImage *src_temp;
	int angle_flag = angle / 90;
	int y,x;
	if(angle_flag == 1)
	{
		CvSize cvSize;
		cvSize.width = src->height;
		cvSize.height = src->width;
		src_temp = cvCreateImage(cvSize,src->depth,src->nChannels);
		if(src_temp->origin != src->origin) {src_temp->origin = src->origin;}
		for(y = 0; y < src_temp->height; ++y)
		{
			for(x = 0; x < src_temp->width; ++x)
			{
				CvScalar scalar = cvGet2D(src,x,y);
				cvSet2D(src_temp,y,src_temp->width - 1 - x,scalar);
			}
		}
	}
	else if(angle_flag == 2)
	{
		src_temp = cvCreateImage(cvGetSize(src),src->depth,src->nChannels);
		if(src_temp->origin != src->origin) {src_temp->origin = src->origin;}
		for(y = 0; y < src_temp->height; ++y)
		{
			for(x = 0; x < src_temp->width; ++x)
			{
				CvScalar scalar = cvGet2D(src,y,x);
				cvSet2D(src_temp,src_temp->height - 1 - y,src_temp->width - 1 - x,scalar);
			}
		}
	}
	else if(angle_flag == 3)
	{
		CvSize cvSize;
		cvSize.width = src->height;
		cvSize.height = src->width;
		src_temp = cvCreateImage(cvSize,src->depth,src->nChannels);
		if(src_temp->origin != src->origin) {src_temp->origin = src->origin;}
		for(y = 0; y < src_temp->height; ++y)
		{
			for(x = 0; x < src_temp->width; ++x)
			{
				CvScalar scalar = cvGet2D(src,x,y);
				cvSet2D(src_temp,src_temp->height - 1 - y,x,scalar);
			}
		}
	}
	else
	{
		CvSize cvSize;
		cvSize.width = src->width;
		cvSize.height = src->height;
		src_temp = cvCreateImage(cvSize,src->depth,src->nChannels);
		if(src_temp->origin != src->origin) {src_temp->origin = src->origin;}
		for(y = 0; y < src_temp->height; ++y)
		{
			for(x = 0; x < src_temp->width; ++x)
			{
				CvScalar scalar = cvGet2D(src,y,x);
				cvSet2D(src_temp,y,x,scalar);
			}
		}
	}

	angle = angle % 90;

	IplImage* dst = NULL;

	int width =
		(double)(src_temp->height * sin(angle * CV_PI / 180.0)) +
		(double)(src_temp->width * cos(angle * CV_PI / 180.0 ));
	int height =
		(double)(src_temp->height * cos(angle * CV_PI / 180.0)) +
		(double)(src_temp->width * sin(angle * CV_PI / 180.0 ));
	int tempLength = sqrt((double)src_temp->width * src_temp->width + src_temp->height * src_temp->height) + 10;
	int tempX = (tempLength + 1) / 2 - src_temp->width / 2;
	int tempY = (tempLength + 1) / 2 - src_temp->height / 2;
	int flag = -1;

	dst = cvCreateImage(cvSize(width, height), src_temp->depth, src_temp->nChannels);
	if(dst->origin != src_temp->origin) {dst->origin = src_temp->origin;}
	cvZero(dst);
	IplImage* temp = cvCreateImage(cvSize(tempLength, tempLength), src_temp->depth, src_temp->nChannels);
	if(temp->origin != src_temp->origin) {temp->origin = src_temp->origin;}
	cvZero(temp);

	cvSetImageROI(temp, cvRect(tempX, tempY, src_temp->width, src_temp->height));
	cvCopy(src_temp, temp, NULL);
	cvResetImageROI(temp);

	/*if (clockwise)
		flag = 1;*/
	flag = 1;

	float m[6];
	int w = temp->width;
	int h = temp->height;
	m[0] = (float) cos(flag * angle * CV_PI / 180.);
	m[1] = (float) sin(flag * angle * CV_PI / 180.);
	m[3] = -m[1];
	m[4] = m[0];
	// 将旋转中心移至图像中间
	m[2] = w * 0.5f;
	m[5] = h * 0.5f;
	//
	CvMat M = cvMat(2, 3, CV_32F, m);
	cvGetQuadrangleSubPix(temp, dst, &M);
	cvReleaseImage(&temp);
	cvReleaseImage(&src_temp);
	return dst;
}


void CImageProcessDoc::OnMenuitemRotate() 
{
	// TODO: Add your command handler code here
	
	IplImage *pImg = m_image.GetImage();

	IplImage *src = pImg;

	CSelectRotateDialog dialog;
	dialog.m_angle = 180;
	dialog.m_clockwise = 0;

	if(dialog.DoModal())
	{
		bool b_clockwise = !dialog.m_clockwise;	

		DWORD start_time = GetTickCount();
		IplImage *dst = rotateImage(src, dialog.m_angle,b_clockwise);
		DWORD end_time = GetTickCount();

		m_image.CopyOf(dst,dst->nChannels);

		UpdateAllViews(NULL);

		timeSpan = end_time - start_time;
	}
	
}

void CImageProcessDoc::OnMenuitemOutputallpoint() 
{
	// TODO: Add your command handler code here
	int y,x,z;
	int i;

	CvScalar scalar;

	DWORD start_time = GetTickCount();

	ofstream outfile1("D://log/video_point.txt");
	for(i = 0; i < m_frame_count; ++i)
	{
		for(y = 0; y < m_frames[i]->height; ++y)
		{
			for(x = 0; x < m_frames[i]->width; ++x)
			{
				scalar = cvGet2D(m_frames[i],y,x);

				outfile1 << "frameNum = " << i << ", x = " << x << ", y = " << y << ",value =";
				for(z = 0; z < m_frames[i]->nChannels; ++z) outfile1 << " " << scalar.val[z];
				outfile1 << endl;
			}
		}
	}
	outfile1.close();

	DWORD end_time =GetTickCount();

	timeSpan = end_time - start_time;

	char str[200];
	sprintf(str,"Finish Get All Video Point.Use time:%lf.",timeSpan);
	AfxMessageBox(str);
}

int current_frame = 10;
void CImageProcessDoc::OnMenuitemVideogray() 
{
	// TODO: Add your command handler code here
	v_timeSpan.clear();

	CvVideoWriter *writer = cvCreateVideoWriter("D://log/video_gray.avi",
		cvGetCaptureProperty(m_capture,CV_CAP_PROP_FOURCC),
		cvGetCaptureProperty(m_capture,CV_CAP_PROP_FPS),
		cvSize(int(cvGetCaptureProperty(m_capture,CV_CAP_PROP_FRAME_WIDTH)),(int)(cvGetCaptureProperty(m_capture,CV_CAP_PROP_FRAME_HEIGHT))),
		1);

	IplImage *lp_frame;
	for(int i = 0; i < m_frame_count; ++i)
	{
		lp_frame = m_frames[i];
		m_image.CopyOf(lp_frame,lp_frame->nChannels);

		timeSpan = -1.0;
		OnMenuitemGetgrayimage();
		v_timeSpan.push_back(timeSpan);
		
		cvCopy(m_image.GetImage(),m_frames[i]);
		cvWriteFrame(writer,m_frames[i]);
	}
	
	cvReleaseVideoWriter(&writer);
	m_image.CopyOf(m_frames[0],m_frames[0]->nChannels);

	UpdateAllViews(NULL);
	 
}

void CImageProcessDoc::OnMenuitemGetvideoinfo() 
{
	// TODO: Add your command handler code here
	DWORD start_time = GetTickCount();

	ofstream outfile1("D://log/video_info.txt");

	outfile1 << "CV_CAP_PROP_POS_FRAMES = " << cvGetCaptureProperty(m_capture,CV_CAP_PROP_POS_FRAMES) << endl;
	outfile1 << "CV_CAP_PROP_POS_AVI_RATIO = " << cvGetCaptureProperty(m_capture,CV_CAP_PROP_POS_AVI_RATIO) << endl;
	outfile1 << "CV_CAP_PROP_FRAME_WIDTH = " << cvGetCaptureProperty(m_capture,CV_CAP_PROP_FRAME_WIDTH) << endl;
	outfile1 << "CV_CAP_PROP_FRAME_HEIGHT = " << cvGetCaptureProperty(m_capture,CV_CAP_PROP_FRAME_HEIGHT) << endl;
	outfile1 << "CV_CAP_PROP_FPS = " << cvGetCaptureProperty(m_capture,CV_CAP_PROP_FPS) << endl;
	outfile1 << "CV_CAP_PROP_FOURCC = " << cvGetCaptureProperty(m_capture,CV_CAP_PROP_FOURCC) << endl;
	outfile1 << "CV_CAP_PROP_FRAME_COUNT = " << cvGetCaptureProperty(m_capture,CV_CAP_PROP_FRAME_COUNT) << endl;

	outfile1.close();

	DWORD end_time = GetTickCount();

	timeSpan = end_time - start_time;

	char str[200];
	sprintf(str,"Finish Get Video Information.Use time:%lf",timeSpan);
	AfxMessageBox(str);
	
}

void CImageProcessDoc::OnMenuitemGetallimiage() 
{
	// TODO: Add your command handler code here

	DWORD start_time = GetTickCount();

	for(int i = 0; i < m_frame_count; ++i)
	{
		char str[200];
		sprintf(str,"D://log/out/%d.bmp",i);
		cvSaveImage(str,m_frames[i]);
	}

	DWORD end_time = GetTickCount();

	timeSpan = end_time - start_time;

	char str[200];
	sprintf(str,"Finish Get All Image.Use time:%lf",timeSpan);
	AfxMessageBox(str);
}



void CImageProcessDoc::OnMenuitemVideorotate() 
{
	// TODO: Add your command handler code here
	v_timeSpan.clear();

	CvVideoWriter *writer = cvCreateVideoWriter("D://log/video_rotate.avi",
		cvGetCaptureProperty(m_capture,CV_CAP_PROP_FOURCC),
		cvGetCaptureProperty(m_capture,CV_CAP_PROP_FPS),
		cvSize(int(cvGetCaptureProperty(m_capture,CV_CAP_PROP_FRAME_WIDTH)),(int)(cvGetCaptureProperty(m_capture,CV_CAP_PROP_FRAME_HEIGHT))),
		1);

	IplImage *lp_frame;
	for(int i = 0; i < m_frame_count; ++i)
	{
		lp_frame = m_frames[i];
		m_image.CopyOf(lp_frame,lp_frame->nChannels);

		timeSpan = -1.0;
		OnMenuitemRotate();
		v_timeSpan.push_back(timeSpan);
		
		cvCopy(m_image.GetImage(),m_frames[i]);
		cvWriteFrame(writer,m_frames[i]);
	}
	
	cvReleaseVideoWriter(&writer);
	m_image.CopyOf(m_frames[0],m_frames[0]->nChannels);

	UpdateAllViews(NULL);
	 
}

void CImageProcessDoc::OnMenuitemVideoreverse() 
{
	// TODO: Add your command handler code here
	v_timeSpan.clear();

	CvVideoWriter *writer = cvCreateVideoWriter("D://log/video_reverse.avi",
		cvGetCaptureProperty(m_capture,CV_CAP_PROP_FOURCC),
		cvGetCaptureProperty(m_capture,CV_CAP_PROP_FPS),
		cvSize(int(cvGetCaptureProperty(m_capture,CV_CAP_PROP_FRAME_WIDTH)),(int)(cvGetCaptureProperty(m_capture,CV_CAP_PROP_FRAME_HEIGHT))),
		1);

	IplImage *lp_frame;
	for(int i = 0; i < m_frame_count; ++i)
	{
		lp_frame = m_frames[i];
		m_image.CopyOf(lp_frame,lp_frame->nChannels);

		timeSpan = -1.0;
		OnMenuitemGetreverseimage();
		v_timeSpan.push_back(timeSpan);
		
		cvCopy(m_image.GetImage(),m_frames[i]);
		cvWriteFrame(writer,m_frames[i]);
	}
	
	cvReleaseVideoWriter(&writer);
	m_image.CopyOf(m_frames[0],m_frames[0]->nChannels);

	UpdateAllViews(NULL);
}

void CImageProcessDoc::OnMenuitemVideogetrgbchannel() 
{
	// TODO: Add your command handler code here
	v_timeSpan.clear();

	CvVideoWriter *writer = cvCreateVideoWriter("D://log/video_channel.avi",
		cvGetCaptureProperty(m_capture,CV_CAP_PROP_FOURCC),
		cvGetCaptureProperty(m_capture,CV_CAP_PROP_FPS),
		cvSize(int(cvGetCaptureProperty(m_capture,CV_CAP_PROP_FRAME_WIDTH)),(int)(cvGetCaptureProperty(m_capture,CV_CAP_PROP_FRAME_HEIGHT))),
		1);

	IplImage *lp_frame;
	for(int i = 0; i < m_frame_count; ++i)
	{
		lp_frame = m_frames[i];
		m_image.CopyOf(lp_frame,lp_frame->nChannels);

		timeSpan = -1.0;
		OnMenuitemGetrgbchannelimage();
		v_timeSpan.push_back(timeSpan);
		
		cvCopy(m_image.GetImage(),m_frames[i]);
		cvWriteFrame(writer,m_frames[i]);
	}
	
	cvReleaseVideoWriter(&writer);
	m_image.CopyOf(m_frames[0],m_frames[0]->nChannels);

	UpdateAllViews(NULL);	
}

void CImageProcessDoc::OnMenuitemVideosmoothfilter() 
{
	// TODO: Add your command handler code here
	v_timeSpan.clear();

	CvVideoWriter *writer = cvCreateVideoWriter("D://log/video_smooth_filter.avi",
		cvGetCaptureProperty(m_capture,CV_CAP_PROP_FOURCC),
		cvGetCaptureProperty(m_capture,CV_CAP_PROP_FPS),
		cvSize(int(cvGetCaptureProperty(m_capture,CV_CAP_PROP_FRAME_WIDTH)),(int)(cvGetCaptureProperty(m_capture,CV_CAP_PROP_FRAME_HEIGHT))),
		1);

	IplImage *lp_frame;
	for(int i = 0; i < m_frame_count; ++i)
	{
		lp_frame = m_frames[i];
		m_image.CopyOf(lp_frame,lp_frame->nChannels);

		timeSpan = -1.0;
		OnMenuitemSmoothfiltering();
		v_timeSpan.push_back(timeSpan);
		
		cvCopy(m_image.GetImage(),m_frames[i]);
		cvWriteFrame(writer,m_frames[i]);
	}
	
	cvReleaseVideoWriter(&writer);
	m_image.CopyOf(m_frames[0],m_frames[0]->nChannels);

	UpdateAllViews(NULL);		
}

void CImageProcessDoc::OnMenuitemVideobinarationostu() 
{
	// TODO: Add your command handler code here
	v_timeSpan.clear();

	CvVideoWriter *writer = cvCreateVideoWriter("D://log/video_binaration_otsu.avi",
		cvGetCaptureProperty(m_capture,CV_CAP_PROP_FOURCC),
		cvGetCaptureProperty(m_capture,CV_CAP_PROP_FPS),
		cvSize(int(cvGetCaptureProperty(m_capture,CV_CAP_PROP_FRAME_WIDTH)),(int)(cvGetCaptureProperty(m_capture,CV_CAP_PROP_FRAME_HEIGHT))),
		1);

	IplImage *lp_frame;
	for(int i = 0; i < m_frame_count; ++i)
	{
		lp_frame = m_frames[i];
		m_image.CopyOf(lp_frame,lp_frame->nChannels);

		timeSpan = -1.0;
		OnMenuitemGetthresholdimageotsu();
		v_timeSpan.push_back(timeSpan);
		
		cvCopy(m_image.GetImage(),m_frames[i]);
		cvWriteFrame(writer,m_frames[i]);
	}
	
	cvReleaseVideoWriter(&writer);
	m_image.CopyOf(m_frames[0],m_frames[0]->nChannels);

	UpdateAllViews(NULL);		
}

void CImageProcessDoc::OnMenuitemVideobinarationmaxentropy() 
{
	// TODO: Add your command handler code here
	v_timeSpan.clear();

	CvVideoWriter *writer = cvCreateVideoWriter("D://log/video_binaration_max_entropy.avi",
		cvGetCaptureProperty(m_capture,CV_CAP_PROP_FOURCC),
		cvGetCaptureProperty(m_capture,CV_CAP_PROP_FPS),
		cvSize(int(cvGetCaptureProperty(m_capture,CV_CAP_PROP_FRAME_WIDTH)),(int)(cvGetCaptureProperty(m_capture,CV_CAP_PROP_FRAME_HEIGHT))),
		1);

	IplImage *lp_frame;
	for(int i = 0; i < m_frame_count; ++i)
	{
		lp_frame = m_frames[i];
		m_image.CopyOf(lp_frame,lp_frame->nChannels);

		timeSpan = -1.0;
		OnMenuitemBinarizationmaxentropy();
		v_timeSpan.push_back(timeSpan);
		
		cvCopy(m_image.GetImage(),m_frames[i]);
		cvWriteFrame(writer,m_frames[i]);
	}
	
	cvReleaseVideoWriter(&writer);
	m_image.CopyOf(m_frames[0],m_frames[0]->nChannels);

	UpdateAllViews(NULL);			
}

void CImageProcessDoc::OnMenuitemVideobinarizationiteration() 
{
	// TODO: Add your command handler code here
	v_timeSpan.clear();

	CvVideoWriter *writer = cvCreateVideoWriter("D://log/video_binaration_iterate.avi",
		cvGetCaptureProperty(m_capture,CV_CAP_PROP_FOURCC),
		cvGetCaptureProperty(m_capture,CV_CAP_PROP_FPS),
		cvSize(int(cvGetCaptureProperty(m_capture,CV_CAP_PROP_FRAME_WIDTH)),(int)(cvGetCaptureProperty(m_capture,CV_CAP_PROP_FRAME_HEIGHT))),
		1);

	IplImage *lp_frame;
	for(int i = 0; i < m_frame_count; ++i)
	{
		lp_frame = m_frames[i];
		m_image.CopyOf(lp_frame,lp_frame->nChannels);

		timeSpan = -1.0;
		OnMenuitemBinarizationiteration();
		v_timeSpan.push_back(timeSpan);
		
		cvCopy(m_image.GetImage(),m_frames[i]);
		cvWriteFrame(writer,m_frames[i]);
	}
	
	cvReleaseVideoWriter(&writer);
	m_image.CopyOf(m_frames[0],m_frames[0]->nChannels);

	UpdateAllViews(NULL);	
}

void CImageProcessDoc::OnMenuitemVideogetthinimagemorphology() 
{
	// TODO: Add your command handler code here
	v_timeSpan.clear();

	CvVideoWriter *writer = cvCreateVideoWriter("D://log/video_thin_image_morphology.avi",
		cvGetCaptureProperty(m_capture,CV_CAP_PROP_FOURCC),
		cvGetCaptureProperty(m_capture,CV_CAP_PROP_FPS),
		cvSize(int(cvGetCaptureProperty(m_capture,CV_CAP_PROP_FRAME_WIDTH)),(int)(cvGetCaptureProperty(m_capture,CV_CAP_PROP_FRAME_HEIGHT))),
		1);

	IplImage *lp_frame;
	for(int i = 0; i < m_frame_count; ++i)
	{
		lp_frame = m_frames[i];
		m_image.CopyOf(lp_frame,lp_frame->nChannels);

		timeSpan = -1.0;
		OnMenuitemGetthinimagemorphology();
		v_timeSpan.push_back(timeSpan);
		
		cvCopy(m_image.GetImage(),m_frames[i]);
		cvWriteFrame(writer,m_frames[i]);
	}
	
	cvReleaseVideoWriter(&writer);
	m_image.CopyOf(m_frames[0],m_frames[0]->nChannels);

	UpdateAllViews(NULL);		
}

void CImageProcessDoc::OnMenuitemVideogetthinimagezhang() 
{
	v_timeSpan.clear();

	CvVideoWriter *writer = cvCreateVideoWriter("D://log/video_thin_image_zhang.avi",
		cvGetCaptureProperty(m_capture,CV_CAP_PROP_FOURCC),
		cvGetCaptureProperty(m_capture,CV_CAP_PROP_FPS),
		cvSize(int(cvGetCaptureProperty(m_capture,CV_CAP_PROP_FRAME_WIDTH)),(int)(cvGetCaptureProperty(m_capture,CV_CAP_PROP_FRAME_HEIGHT))),
		1);

	IplImage *lp_frame;
	for(int i = 0; i < m_frame_count; ++i)
	{
		lp_frame = m_frames[i];
		m_image.CopyOf(lp_frame,lp_frame->nChannels);

		timeSpan = -1.0;
		OnMenuitemGetthinimagezhang();
		v_timeSpan.push_back(timeSpan);
		
		cvCopy(m_image.GetImage(),m_frames[i]);
		cvWriteFrame(writer,m_frames[i]);
	}
	
	cvReleaseVideoWriter(&writer);
	m_image.CopyOf(m_frames[0],m_frames[0]->nChannels);

	UpdateAllViews(NULL);		
}

void CImageProcessDoc::OnMenuitemVideogetthinimagerosenfeld() 
{
	// TODO: Add your command handler code here
	v_timeSpan.clear();

	CvVideoWriter *writer = cvCreateVideoWriter("D://log/video_thin_image_rosenfeld.avi",
		cvGetCaptureProperty(m_capture,CV_CAP_PROP_FOURCC),
		cvGetCaptureProperty(m_capture,CV_CAP_PROP_FPS),
		cvSize(int(cvGetCaptureProperty(m_capture,CV_CAP_PROP_FRAME_WIDTH)),(int)(cvGetCaptureProperty(m_capture,CV_CAP_PROP_FRAME_HEIGHT))),
		1);

	IplImage *lp_frame;
	for(int i = 0; i < m_frame_count; ++i)
	{
		lp_frame = m_frames[i];
		m_image.CopyOf(lp_frame,lp_frame->nChannels);

		timeSpan = -1.0;
		OnMenuitemGetthinimageroseenfeld();
		v_timeSpan.push_back(timeSpan);
		
		cvCopy(m_image.GetImage(),m_frames[i]);
		cvWriteFrame(writer,m_frames[i]);
	}
	
	cvReleaseVideoWriter(&writer);
	m_image.CopyOf(m_frames[0],m_frames[0]->nChannels);

	UpdateAllViews(NULL);		
}

void CImageProcessDoc::OnMenuitemVideogetthinimagedistance() 
{	
	// TODO: Add your command handler code here
	v_timeSpan.clear();

	CvVideoWriter *writer = cvCreateVideoWriter("D://log/video_thin_image_distance.avi",
		cvGetCaptureProperty(m_capture,CV_CAP_PROP_FOURCC),
		cvGetCaptureProperty(m_capture,CV_CAP_PROP_FPS),
		cvSize(int(cvGetCaptureProperty(m_capture,CV_CAP_PROP_FRAME_WIDTH)),(int)(cvGetCaptureProperty(m_capture,CV_CAP_PROP_FRAME_HEIGHT))),
		1);

	IplImage *lp_frame;
	for(int i = 0; i < m_frame_count; ++i)
	{
		lp_frame = m_frames[i];
		m_image.CopyOf(lp_frame,lp_frame->nChannels);

		timeSpan = -1.0;
		OnMENUITEMGETTHINIMAGEDiSTANCE();
		v_timeSpan.push_back(timeSpan);
		
		cvCopy(m_image.GetImage(),m_frames[i]);
		cvWriteFrame(writer,m_frames[i]);
	}
	
	cvReleaseVideoWriter(&writer);
	m_image.CopyOf(m_frames[0],m_frames[0]->nChannels);

	UpdateAllViews(NULL);
	
}

void CImageProcessDoc::OnMenuitemVideocannyoperator() 
{
	// TODO: Add your command handler code here
	v_timeSpan.clear();

	CvVideoWriter *writer = cvCreateVideoWriter("D://log/video_segmatation_image_canny.avi",
		cvGetCaptureProperty(m_capture,CV_CAP_PROP_FOURCC),
		cvGetCaptureProperty(m_capture,CV_CAP_PROP_FPS),
		cvSize(int(cvGetCaptureProperty(m_capture,CV_CAP_PROP_FRAME_WIDTH)),(int)(cvGetCaptureProperty(m_capture,CV_CAP_PROP_FRAME_HEIGHT))),
		1);

	IplImage *lp_frame;
	for(int i = 0; i < m_frame_count; ++i)
	{
		lp_frame = m_frames[i];
		m_image.CopyOf(lp_frame,lp_frame->nChannels);

		timeSpan = -1.0;
		OnMenuitemGetsegmentationimagecanny();
		v_timeSpan.push_back(timeSpan);
		
		cvCopy(m_image.GetImage(),m_frames[i]);
		cvWriteFrame(writer,m_frames[i]);
	}
	
	cvReleaseVideoWriter(&writer);
	m_image.CopyOf(m_frames[0],m_frames[0]->nChannels);

	UpdateAllViews(NULL);
}

void CImageProcessDoc::OnMenuitemVideosobeloperator() 
{
	// TODO: Add your command handler code here
	v_timeSpan.clear();

	CvVideoWriter *writer = cvCreateVideoWriter("D://log/video_sobel_operator.avi",
		cvGetCaptureProperty(m_capture,CV_CAP_PROP_FOURCC),
		cvGetCaptureProperty(m_capture,CV_CAP_PROP_FPS),
		cvSize(int(cvGetCaptureProperty(m_capture,CV_CAP_PROP_FRAME_WIDTH)),(int)(cvGetCaptureProperty(m_capture,CV_CAP_PROP_FRAME_HEIGHT))),
		1);

	IplImage *lp_frame;
	for(int i = 0; i < m_frame_count; ++i)
	{
		lp_frame = m_frames[i];
		m_image.CopyOf(lp_frame,lp_frame->nChannels);

		timeSpan = -1.0;
		OnMenuitemGetsegmentationimagesobel();
		v_timeSpan.push_back(timeSpan);
		
		cvCopy(m_image.GetImage(),m_frames[i]);
		cvWriteFrame(writer,m_frames[i]);
	}
	
	cvReleaseVideoWriter(&writer);
	m_image.CopyOf(m_frames[0],m_frames[0]->nChannels);

	UpdateAllViews(NULL);
}

void CImageProcessDoc::OnMenuitemVideorobertoperator() 
{
	// TODO: Add your command handler code here
	v_timeSpan.clear();

	CvVideoWriter *writer = cvCreateVideoWriter("D://log/video_robert_operator.avi",
		cvGetCaptureProperty(m_capture,CV_CAP_PROP_FOURCC),
		cvGetCaptureProperty(m_capture,CV_CAP_PROP_FPS),
		cvSize(int(cvGetCaptureProperty(m_capture,CV_CAP_PROP_FRAME_WIDTH)),(int)(cvGetCaptureProperty(m_capture,CV_CAP_PROP_FRAME_HEIGHT))),
		1);

	IplImage *lp_frame;
	for(int i = 0; i < m_frame_count; ++i)
	{
		lp_frame = m_frames[i];
		m_image.CopyOf(lp_frame,lp_frame->nChannels);

		timeSpan = -1.0;
		OnMenuitemRobertoperator();
		v_timeSpan.push_back(timeSpan);
		
		cvCopy(m_image.GetImage(),m_frames[i]);
		cvWriteFrame(writer,m_frames[i]);
	}
	
	cvReleaseVideoWriter(&writer);
	m_image.CopyOf(m_frames[0],m_frames[0]->nChannels);

	UpdateAllViews(NULL);
	
}

void CImageProcessDoc::OnMenuitemVideoprewittoperator() 
{
	// TODO: Add your command handler code here
	v_timeSpan.clear();

	CvVideoWriter *writer = cvCreateVideoWriter("D://log/video_prewitt_operator.avi",
		cvGetCaptureProperty(m_capture,CV_CAP_PROP_FOURCC),
		cvGetCaptureProperty(m_capture,CV_CAP_PROP_FPS),
		cvSize(int(cvGetCaptureProperty(m_capture,CV_CAP_PROP_FRAME_WIDTH)),(int)(cvGetCaptureProperty(m_capture,CV_CAP_PROP_FRAME_HEIGHT))),
		1);

	IplImage *lp_frame;
	for(int i = 0; i < m_frame_count; ++i)
	{
		lp_frame = m_frames[i];
		m_image.CopyOf(lp_frame,lp_frame->nChannels);

		timeSpan = -1.0;
		OnMenuitemPrewittoperator();
		v_timeSpan.push_back(timeSpan);
		
		cvCopy(m_image.GetImage(),m_frames[i]);
		cvWriteFrame(writer,m_frames[i]);
	}
	
	cvReleaseVideoWriter(&writer);
	m_image.CopyOf(m_frames[0],m_frames[0]->nChannels);

	UpdateAllViews(NULL);
	
}

void QucikThinning(BYTE **img_data,int width,int height)
{
	int y,x;
	int i;

	//resize;
	BYTE **src = new BYTE*[height + 2];
	src[0] = new BYTE[width + 2];
	src[0][0] = img_data[0][0];
	memcpy(&src[0][1],img_data[0],sizeof(BYTE) * width);
	src[0][width + 1] = img_data[0][width - 1];

	for(y = 1; y <= height; ++y)
	{
		src[y] = new BYTE[width + 2];
		src[y][0] = img_data[y - 1][0];
		memcpy(&src[y][1],img_data[y - 1],sizeof(BYTE) * width);
		src[y][width + 1] = img_data[y - 1][width - 1];
	}

	src[height + 1] = new BYTE[width + 2];
	src[height + 1][0] = img_data[height - 1][0];
	memcpy(&src[height + 1][1],img_data[height - 1],sizeof(BYTE) * width);
	src[height + 1][width + 1] = img_data[height - 1][width - 1];

	int idx_x[] = {-1,0,1,1,1,0,-1,-1};
	int idx_y[] = {-1,-1,-1,0,1,1,1,0};


	int sum;
	int count = 0;
	for(y = 1; y <= height; ++y)
	{
		for(x = 1; x <= width; ++x)
		{
			if(src[y][x] == 1)
			{
				int sum4_p = 0;
				for(i = 1; i < 8; i+=2) sum4_p += src[y + idx_y[i]][x + idx_x[i]];
				if(sum4_p < 4)
				{
					int s1 = 0,s2 = 0;
					for(i = 0;i < 8; ++i)
					{
						s1 += src[y + idx_y[i]][x + idx_x[i]];
						s2 += abs(src[y + idx_y[(i + 1) % 8]][x + idx_x[(i + 1) % 8]] - src[y + idx_y[i]][x + idx_x[i]]);
					}
					if(s1 == 2 && s2 != 1 && s2 < 6)
					{
						++count;
						src[y][x] = 0;
						img_data[y - 1][x - 1] = 0;
						y = 1; x = 1;
					}
				}
			}
		}
	}

	char str[200];
	sprintf(str,"%d",count);
	AfxMessageBox(str);

	for(y = 0; y <= height + 1; ++y) delete src[y];
	delete [] src;

	return;
}

void CImageProcessDoc::OnMenuitemGetthinimageqta() 
{	
	// TODO: Add your command handler code here
	int i;
	int x,y;

	IplImage *pImg = m_image.GetImage();

	IplImage *channel_image[3];
	for(i = 0; i < 3; ++i)
	{
		channel_image[i] = cvCreateImage(cvGetSize(pImg),pImg->depth,1);
		channel_image[i]->origin = pImg->origin;
	}
	cvSplit(pImg,channel_image[0],channel_image[1],channel_image[2],0);

	IplImage *thin_image = cvCreateImage(cvGetSize(channel_image[0]),channel_image[0]->depth,1);
	thin_image->origin = channel_image[0]->origin;

	BYTE **img_data  = new BYTE*[channel_image[0]->height];
	for(i = 0; i < channel_image[0]->height; ++i) img_data[i] = new BYTE[channel_image[0]->width];

	for(y = 0; y < channel_image[0]->height; ++y)
	{
		for(x = 0; x < channel_image[0]->width; ++x)
		{
			CvScalar scalar = cvGet2D(channel_image[0],y,x);
			if(scalar.val[0] == 0) img_data[y][x] = 0;
			else img_data[y][x] = 1;
		}
	}

	DWORD start_time = GetTickCount();
	QucikThinning(img_data,channel_image[0]->width,channel_image[0]->height);
	DWORD end_time = GetTickCount();

	for(y = 0; y < channel_image[0]->height; ++y)
	{
		for(x = 0; x < channel_image[0]->width; ++x)
		{
			CvScalar scalar = cvGet2D(thin_image,y,x);
			if(img_data[y][x] == 0) scalar.val[0] = 0;
			else scalar.val[0] = 255;
			cvSet2D(thin_image,y,x,scalar);
		}
	}

	for(i = 0; i < channel_image[0]->height; ++i) delete [] img_data[i];
	delete [] img_data;

	m_image.CopyOf(thin_image,thin_image->nChannels);

	cvSaveImage("D://log/thin_image_rosenfeld.bmp",thin_image);

	UpdateAllViews(NULL);

	timeSpan = end_time - start_time;

}

//                                  p3  p2  p1
//*************计算近邻的连接数     p4  p   p0 
//                                  p5  p6  p7
int Get8Connectivity(int* neighbor)
{	
 
	//计算补集x^=1-x;
	for(int i=0;i<8;i++)
	{
		neighbor[i]=neighbor[i]==0?1:0;
	}	
	
	int count= neighbor[0]-(neighbor[0]&neighbor[1]&neighbor[2]);
	count+= neighbor[2]-(neighbor[2]&neighbor[3]&neighbor[4]);
	count+= neighbor[4]-(neighbor[4]&neighbor[5]&neighbor[6]);
	count+= neighbor[6]-(neighbor[6]&neighbor[7]&neighbor[0]);
 
	return count;
}
void HilditchThinning(int w,int h,BYTE *imgBuf)
{
	//           p3  p2  p1
	// 8近邻     p4  p   p0 
	//           p5  p6  p7
	int neighbor[8]; 
	BYTE *mask=new BYTE[w*h];
	memset(mask,0,w*h);
 
	BOOL loop=TRUE;
	int x,y,k,index;
 
	int loopNum = 0;
	while(loop)
	{
		loop=FALSE;
		loopNum++;
 
		for(y=0;y<h;y++)
		{
			for(x=0;x<w;x++)
			{
				index=y*w+x;
 
				//条件1：p必须是前景点
				if(imgBuf[index]==0 ) continue;
 
				neighbor[0]=x+1<w ? imgBuf[y*w+x+1] : 0;
				neighbor[1]=y-1>0&&x+1<w ? imgBuf[(y-1)*w+x+1] : 0;
				neighbor[2]=y-1>0 ? imgBuf[(y-1)*w+x] : 0;
				neighbor[3]=y-1>0&&x-1<0 ? imgBuf[(y-1)*w+x-1] : 0;
				neighbor[4]=x-1>0 ? imgBuf[y*w+x-1] : 0;
				neighbor[5]=x-1>0&&y+1<h ? imgBuf[(y+1)*w+x-1] : 0;
				neighbor[6]=y+1<h ? imgBuf[(y+1)*w+x] : 0;
				neighbor[7]=y+1<h&&x+1<w ? imgBuf[(y+1)*w+x+1] : 0;
 
				//条件2：p0,p2,p4,p6不全为前景色（否则把点p删了，图像空心）
				if(neighbor[0]&&neighbor[2]&&neighbor[4]&&neighbor[6])
					continue;
 
				//条件3：p0~p7中，至少有个为前景色
				//（若只有一个为，则为端点，若没有为的，则为孤立点）
				int count=0;
				for(int i=0;i<8;i++)
				{
					if(neighbor[i]==255)
						count++;
				}
				if(count<2)  
				{
					continue;
				}
 
				//条件4：p的八近邻连接数必须为1
				if(Get8Connectivity(neighbor)!=1) continue;
 
				//条件5：若p2已经被标记删除，则当p2为背景色时，P的连接数仍需为1
				k=(y-1)*w+x;
				if(y-1>0 && mask[k]==1)
				{				
					imgBuf[k]=0;
					if(Get8Connectivity(neighbor)!=1) continue;
					imgBuf[k]=1;
				}
 
				//条件6：若p4已经被标记删除，则当p4为背景色时，P的连接数仍需为1
				k=y*w+x-1;
				if(x-1>0 && mask[k]==1)
				{				
					imgBuf[k]=0;
					if(Get8Connectivity(neighbor)!=1) continue;
					imgBuf[k]=1;
				}
 
				//标记删除
				mask[w*y+x]=1;	
				loop=TRUE;
			}
		}
 
 
		//将标记删除的点置为背景色
		for(y=0;y<h;y++)
		{
			for(x=0;x<w;x++)
			{
				k=y*w+x;
				if(mask[k]==1) imgBuf[k]=0;
			}
		}	
 
 
	}
	
 
}


void CImageProcessDoc::OnMenuitemGetthinimagehilditch() 
{
	// TODO: Add your command handler code here
	int i;
	int x,y;

	IplImage *pImg = m_image.GetImage();

	IplImage *channel_image[3];
	for(i = 0; i < 3; ++i)
	{
		channel_image[i] = cvCreateImage(cvGetSize(pImg),pImg->depth,1);
		channel_image[i]->origin = pImg->origin;
	}
	cvSplit(pImg,channel_image[0],channel_image[1],channel_image[2],0);

	IplImage *thin_image = cvCreateImage(cvGetSize(channel_image[0]),channel_image[0]->depth,1);
	thin_image->origin = channel_image[0]->origin;

	BYTE *imgBuf  = new BYTE[channel_image[0]->height * channel_image[0]->width];

	for(y = 0; y < channel_image[0]->height; ++y)
	{
		for(x = 0; x < channel_image[0]->width; ++x)
		{
			CvScalar scalar = cvGet2D(channel_image[0],y,x);
			if(scalar.val[0] == 0) imgBuf[y * channel_image[0]->width + x] = 0;
			else imgBuf[y * channel_image[0]->width + x] = 255;
		}
	}



	DWORD start_time = GetTickCount();
	HilditchThinning(channel_image[0]->width,channel_image[0]->height,imgBuf);
	DWORD end_time = GetTickCount();

	for(y = 0; y < channel_image[0]->height; ++y)
	{
		for(x = 0; x < channel_image[0]->width; ++x)
		{
			CvScalar scalar = cvGet2D(thin_image,y,x);
			if(imgBuf[y * channel_image[0]->width + x] == 0) scalar.val[0] = 0;
			else scalar.val[0] = 255;
			cvSet2D(thin_image,y,x,scalar);
		}
	}

	delete [] imgBuf;

	m_image.CopyOf(thin_image,thin_image->nChannels);

	cvSaveImage("D://log/thin_image_rosenfeld.bmp",thin_image);

	UpdateAllViews(NULL);

	timeSpan = end_time - start_time;
}
