// SegmentationDoc.cpp : implementation of the CSegmentationDoc class
//

#include "stdafx.h"
#include "Segmentation.h"

#include "SegmentationDoc.h"
#include "OpeningParameterDialog.h"
#include "WatershedParameterDialog.h"
#include "ContourParameterDialog.h"

#include "queue"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSegmentationDoc

IMPLEMENT_DYNCREATE(CSegmentationDoc, CDocument)

BEGIN_MESSAGE_MAP(CSegmentationDoc, CDocument)
	//{{AFX_MSG_MAP(CSegmentationDoc)
	ON_COMMAND(ID_MENUITEM_CANNY, OnMenuitemCanny)
	ON_COMMAND(ID_MENUITEM_GETSCANNELS, OnMenuitemGetscannels)
	ON_COMMAND(ID_MENUITEM_GETSHISTOGRAM, OnMenuitemGetshistogram)
	ON_COMMAND(ID_MENUITEM_GETSOSTUTHRESHOLD, OnMenuitemGetsostuthreshold)
	ON_COMMAND(ID_MENUITEM_GETSFLAGIMAGE, OnMenuitemGetsflagimage)
	ON_COMMAND(ID_MENUITEM_GETSFLAGIMAGEOPENING, OnMenuitemGetsflagimageopening)
	ON_COMMAND(ID_MENUITEM_GETGRADIENT, OnMenuitemGetgradient)
	ON_COMMAND(ID_MENUITEM_GETGRADIENTFLAG, OnMenuitemGetgradientflag)
	ON_COMMAND(ID_MENUITEM_GETWATERSHEDOPENCV, OnMenuitemGetwatershedopencv)
	ON_COMMAND(ID_MENUITEM_GETMAXIMUMPOINT, OnMenuitemGetmaximumpoint)
	ON_COMMAND(ID_MENUITEM_GETORIGINALSEGMENTATIONOPENCV, OnMenuitemGetoriginalsegmentationopencv)
	ON_COMMAND(ID_MENUITEM_GETSSEGMENTATIONOPENCV, OnMenuitemGetssegmentationopencv)
	ON_COMMAND(ID_MENUITEM_GETRCANNELS, OnMenuitemGetrcannels)
	ON_COMMAND(ID_MENUITEM_GETRSEGMENTATIONOPENCV, OnMenuitemGetrsegmentationopencv)
	ON_COMMAND(ID_MENUITEM_GETMORPHOLOGYGRADIENT, OnMenuitemGetmorphologygradient)
	ON_COMMAND(ID_MENUITEM_GETCONTOURLINEMANUAL, OnMenuitemGetcontourlinemanual)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSegmentationDoc construction/destruction

CSegmentationDoc::CSegmentationDoc()
{
	// TODO: add one-time construction code here

}

CSegmentationDoc::~CSegmentationDoc()
{
}

BOOL CSegmentationDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSegmentationDoc serialization

void CSegmentationDoc::Serialize(CArchive& ar)
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
// CSegmentationDoc diagnostics

#ifdef _DEBUG
void CSegmentationDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSegmentationDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSegmentationDoc commands

BOOL CSegmentationDoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;

	// TODO: Add your specialized creation code here
	m_image.Load(lpszPathName);

	//IplImage *pImg;
	//pImg = cvLoadImage(lpszPathName,1);
	//m_image.CopyOf(pImg);

	return TRUE;
}

BOOL CSegmentationDoc::OnSaveDocument(LPCTSTR lpszPathName) 
{
	// TODO: Add your specialized code here and/or call the base class
	m_image.Save(lpszPathName);
	
	return CDocument::OnSaveDocument(lpszPathName);
}

void CSegmentationDoc::OnMenuitemCanny() 
{
	// TODO: Add your command handler code here
	IplImage *pImg;
	pImg = m_image.GetImage();
	IplImage *gray = cvCreateImage(cvGetSize(pImg),pImg->depth,1);
	cvCvtColor(pImg,gray,CV_BGR2GRAY);
	cvConvertImage(gray,m_image.GetImage(),CV_GRAY2RGB);

	//cvCanny(pImg,pImg,50,150,3);
	cvReleaseImage(&pImg);
	UpdateAllViews(NULL);
}

void CSegmentationDoc::OnMenuitemGetscannels() 
{
	// TODO: Add your command handler code here
	int x,y;
	CvScalar scalar;

	IplImage *img_rgb,*img_hsv;
	img_rgb = cvCreateImage(cvGetSize(m_image.GetImage()),IPL_DEPTH_32F,3);
	img_hsv = cvCreateImage(cvGetSize(m_image.GetImage()),IPL_DEPTH_32F,3);

	cvConvertScale(m_image.GetImage(),img_rgb);

	cvCvtColor(img_rgb,img_hsv,CV_BGR2HSV);

	IplImage *h,*s,*v,*h_8u,*s_8u,*v_8u;
	h = cvCreateImage(cvGetSize(img_hsv),IPL_DEPTH_32F,1);
	s = cvCreateImage(cvGetSize(img_hsv),IPL_DEPTH_32F,1);
	v = cvCreateImage(cvGetSize(img_hsv),IPL_DEPTH_32F,1);
	h_8u = cvCreateImage(cvGetSize(img_rgb),8,1);
	s_8u = cvCreateImage(cvGetSize(img_rgb),8,1);
	v_8u = cvCreateImage(cvGetSize(img_rgb),8,1);

	cvSplit(img_hsv,h,s,v,NULL);
	cvConvertScale(v,v_8u);
	cvConvertScale(s,s_8u,255.0);
	cvConvertScale(h,h_8u,255.0/360.0);

	//cvNamedWindow("H Cannels");
	//cvShowImage("H Cannels",h_8u);

	//cvNamedWindow("S Cannels");
	//cvShowImage("S Cannels",s_8u);

	cvNamedWindow("V Cannels");
	cvShowImage("V Cannels",v_8u);

	//reshape image
	//IplImage * tmp_img = cvCreateImage(cvGetSize(s_8u),8,1);
	//cvCopy(s_8u,tmp_img,NULL);
	//CvMat mat_hdr;
	//IplImage s_img_hdr;
	//cvReshape(tmp_img,&mat_hdr,0,m_image.GetImage()->width);
	//s_img = cvGetImage(&mat_hdr,&s_img_hdr);

	//s_img = cvCreateImage(cvGetSize(s_8u),8,1);
	s_img = cvCreateImage(cvGetSize(v_8u),8,1);
	cvCopy(v_8u,s_img,NULL);

	//save answer
	//ofstream outfile1("D://log/s_img_point.txt");
	//for(y = 0; y < s_img->height; y++)
	//{
	//	for(x = 0; x < s_img->width; x++)
	//	{
	//		scalar = cvGet2D(s_img,y,x);
	//		outfile1<<"x="<<x<<",y="<<y<<",value="<<scalar.val[0]<<endl;
	//	}
	//}
	//outfile1.close();

	cvReleaseImage(&h);
	cvReleaseImage(&s);
	cvReleaseImage(&v);
	cvReleaseImage(&h_8u);
	cvReleaseImage(&s_8u);
	cvReleaseImage(&v_8u);

	cvReleaseImage(&img_rgb);
	cvReleaseImage(&img_hsv);


}

void CSegmentationDoc::OnMenuitemGetshistogram() 
{
	// TODO: Add your command handler code here

	int hist_size = 256;
	int hist_height = 256;
	float range[] = {0,255};
	float* ranges[] = {range};

	s_hist = cvCreateHist(1,&hist_size,CV_HIST_ARRAY,ranges,1);//create
	cvCalcHist(&s_img,s_hist,0,0);
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
    for(int i=0;i<hist_size;i++)  
    {  
        float bin_val = cvQueryHistValue_1D(s_hist,i); //像素i的概率  
        int intensity = cvRound(bin_val*hist_height/max_value);  //要绘制的高度  
        cvRectangle(hist_image,  
            cvPoint(i*scale,hist_height-1),  
            cvPoint((i+1)*scale - 1, hist_height - intensity),  
            CV_RGB(255,255,255));    
    }  
    cvNamedWindow("S Histogram", 1);  
    cvShowImage("S Histogram", hist_image);  
  
    cvWaitKey(0);  
	cvReleaseImage(&hist_image);

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

void CSegmentationDoc::OnMenuitemGetsostuthreshold() 
{

	s_threshold = icvGetThreshVal_Otsu(s_hist);

	char msg[200];
	sprintf(msg,"S Threshold is %f\n",s_threshold);
	AfxMessageBox(msg);

}

void CSegmentationDoc::OnMenuitemGetsflagimage() 
{
	// TODO: Add your command handler code here 
	int x,y;
	CvScalar scalar;
	
	/*//IplImage *s_img_scale = cvCreateImage(cvGetSize(s_img),IPL_DEPTH_32F,1);
	//cvNormalize(s_img,s_img_scale,1.0,0.0);
	//
	//ofstream outfile1("D://log/s_img_scale_point.txt");
	//for(y = 0; y < s_img_scale->height; y++)
	//{
	//	for(x = 0; x < s_img_scale->width; x++)
	//	{
	//		scalar = cvGet2D(s_img_scale,y,x);
	//		outfile1<<"x="<<x<<",y="<<y<<",value="<<scalar.val[0]<<endl;
	//	}
	//}
	//outfile1.close();

	
	s_flag_image = cvCreateImage(cvGetSize(s_img),8,1);
	cvThreshold(s_img,s_flag_image,(int)s_threshold,255,CV_THRESH_BINARY);

	cvNamedWindow("S FLAG");
	cvShowImage("S FLAG",s_flag_image);*/

	s_flag_image = cvCreateImage(cvGetSize(s_img),8,1);
	cvThreshold(s_img,s_flag_image,1,255,CV_THRESH_OTSU);
	
	cvNamedWindow("S FLAG");
	cvShowImage("S FLAG",s_flag_image);

	//cvNormalize(s_flag_image,s_flag_image,1.0,0.0,CV_MINMAX);
	//
	//ofstream outfile1("D://log/s_img_scale_point.txt");
	//for(y = 0; y < s_flag_image->height; y++)
	//{
	//	for(x = 0; x < s_flag_image->width; x++)
	//	{
	//		scalar = cvGet2D(s_flag_image,y,x);
	//		outfile1<<"x="<<x<<",y="<<y<<",value="<<scalar.val[0]<<endl;
	//	}
	//}
	//outfile1.close();

	
}

void CSegmentationDoc::OnMenuitemGetsflagimageopening() 
{
	// TODO: Add your command handler code here

	//IplImage *s_flag_image_scale = cvCreateImage(cvGetSize(s_flag_image),8,1);
	//cvNormalize(s_flag_image,s_flag_image_scale,1.0,0.0,CV_MINMAX);
	int range = 2;
	int it_time =2;

	//input opening parameter
	COpeningParameterDialog dialog;
	dialog.m_circle_scope = range;
	dialog.m_times = it_time;
	if(dialog.DoModal() == IDOK)
	{
		range = dialog.m_circle_scope;
		it_time = dialog.m_times;
	}
	else
	{
		return;
	}


	s_flag_open_image = cvCreateImage(cvGetSize(s_flag_image),8,1);
	IplImage *tmp_image = cvCreateImage(cvGetSize(s_flag_image),8,1); 
	

	IplConvKernel *ck = cvCreateStructuringElementEx(2*range+1,2*range+1,range,range,CV_SHAPE_ELLIPSE);
	cvMorphologyEx(s_flag_image,s_flag_open_image,tmp_image,ck,CV_MOP_OPEN,it_time);

	//int x,y;
	//CvScalar scalar;
	//ofstream outfile1("D://log/s_flag_open_image_point.txt");
	//for(y = 0; y < s_flag_open_image->height; y++)
	//{
	//	for(x = 0; x < s_flag_open_image->width; x++)
	//	{
	//		scalar = cvGet2D(s_flag_open_image,y,x);
	//		outfile1<<"x="<<x<<",y="<<y<<",value="<<scalar.val[0]<<endl;
	//	}
	//}
	//outfile1.close();

	cvNamedWindow("S FLAG(Opening)");
	cvShowImage("S FLAG(Opening)",s_flag_open_image);

	cvReleaseStructuringElement(&ck);
	cvReleaseImage(&tmp_image);

}

void CSegmentationDoc::OnMenuitemGetgradient() 
{
	// TODO: Add your command handler code here

	IplImage *gradient_image_x_16u = cvCreateImage(cvGetSize(s_img),IPL_DEPTH_16U,1);
	IplImage *gradient_image_y_16u = cvCreateImage(cvGetSize(s_img),IPL_DEPTH_16U,1);
	
	cvSobel(s_img,gradient_image_x_16u,1,0,3);
	cvSobel(s_img,gradient_image_y_16u,0,1,3);

	//IplImage *gradient_image_x = cvCreateImage(cvGetSize(gradient_image_x_16u),IPL_DEPTH_8U,1);
	//cvConvertScale(gradient_image_x_16u,gradient_image_x);
	//cvNamedWindow("Gradient Image(X dirction)");
	//cvShowImage("Gradient Image(X dirction)",gradient_image_x);
	//cvReleaseImage(&gradient_image_x);

	//IplImage *gradient_image_y = cvCreateImage(cvGetSize(gradient_image_y_16u),IPL_DEPTH_8U,1);
	//cvConvertScale(gradient_image_y_16u,gradient_image_y);
	//cvNamedWindow("Gradient Image(Y dirction)");
	//cvShowImage("Gradient Image(Y dirction)",gradient_image_y);
	//cvReleaseImage(&gradient_image_y);

	cvMul(gradient_image_x_16u,gradient_image_x_16u,gradient_image_x_16u,1.0);
	cvMul(gradient_image_y_16u,gradient_image_y_16u,gradient_image_y_16u,1.0);

	cvAdd(gradient_image_x_16u,gradient_image_y_16u,gradient_image_x_16u,0);

	IplImage *gradient_image_32F = cvCreateImage(cvGetSize(s_img),IPL_DEPTH_32F,1);
	
	int x,y;
	CvScalar scalar;
	for(y = 0; y < gradient_image_x_16u->height; y++)
	{
		for(x = 0; x < gradient_image_x_16u->width; x++)
		{
			scalar = cvGet2D(gradient_image_x_16u,y,x);
			scalar.val[0] = sqrt(scalar.val[0]);
			cvSet2D(gradient_image_32F,y,x,scalar);
		}
	}

	s_gradient_image = cvCreateImage(cvGetSize(s_img),IPL_DEPTH_8U,1);
	cvConvertScale(gradient_image_32F,s_gradient_image);

	cvNamedWindow("Gradient Image");
	cvShowImage("Gradient Image",s_gradient_image);

	cvReleaseImage(&gradient_image_x_16u);
	cvReleaseImage(&gradient_image_y_16u);
	cvReleaseImage(&gradient_image_32F);


}

void CSegmentationDoc::OnMenuitemGetgradientflag() 
{
	// TODO: Add your command handler code here
	s_gradient_flag_image = cvCreateImage(cvGetSize(s_gradient_image),IPL_DEPTH_8U,1);

	IplImage *s_flag_open_image_b = cvCreateImage(cvGetSize(s_flag_open_image),IPL_DEPTH_8U,1);
	cvConvertScale(s_flag_open_image,s_flag_open_image_b,1.0/255);


	cvMul(s_gradient_image,s_flag_open_image_b,s_gradient_flag_image,1.0);

	cvNamedWindow("Gradient Image(flag)");
	cvShowImage("Gradient Image(flag)",s_gradient_flag_image);

	cvReleaseImage(&s_flag_open_image_b);
}

void CSegmentationDoc::OnMenuitemGetwatershedopencv() 
{
	// TODO: Add your command handler code here
	CWatershedParameterDialog dialog;

	int x1=0,y1=0,x2=0,y2=0;
		
	dialog.m_x1 = 371;
	dialog.m_y1 = 63;
	dialog.m_x2 = 633;
	dialog.m_y2 = 208;


	if(dialog.DoModal() == IDOK)
	{
		x1 = dialog.m_x1;
		y1 = dialog.m_y1;
		x2 = dialog.m_x2;
		y2 = dialog.m_y2;
	}
	else return;

	IplImage *s_gradient_flag_image_3c = cvCreateImage(cvGetSize(s_gradient_flag_image),IPL_DEPTH_8U,3);
	cvCvtColor(s_gradient_flag_image, s_gradient_flag_image_3c, CV_GRAY2BGR);

	IplImage *mark_image = cvCreateImage(cvGetSize(s_gradient_flag_image),IPL_DEPTH_32S,1);
	cvZero(mark_image);

	CvScalar scalar;
	
	scalar.val[0] = 255;
	cvSet2D(mark_image,y1,x1,scalar);

	scalar.val[0] = 1;
	cvSet2D(mark_image,y2,x2,scalar);

	cvWatershed(s_gradient_flag_image_3c,mark_image);

	IplImage *mark_image_8u = cvCreateImage(cvGetSize(mark_image),IPL_DEPTH_8U,1);
	cvConvertScale(mark_image,mark_image_8u);

	cvNamedWindow("Watershed Image(OpenCV)");
	cvShowImage("Watershed Image(OpenCV)",mark_image_8u);

	//cvReleaseImage(&pImg);
	cvReleaseImage(&mark_image);

	//AfxMessageBox("finish.");

}

void CSegmentationDoc::OnMenuitemGetmaximumpoint() 
{
	// TODO: Add your command handler code here
	//s_gradient_flag_image
	IplImage *s_maximum_point_image = cvCreateImage(cvGetSize(s_gradient_flag_image),IPL_DEPTH_8U,1);
	cvZero(s_maximum_point_image);

	IplImage *s_minimum_point_image = cvCreateImage(cvGetSize(s_gradient_flag_image),IPL_DEPTH_8U,1);
	cvZero(s_minimum_point_image);

	CvScalar scalar;
	int x,y;

	for(y = 1; y < s_gradient_flag_image->height-1;y++)
	{
		for(x = 1; x < s_gradient_flag_image->width-1; x++)
		{
			//scalar = cvGet2D(s_gradient_flag_image,y,x);
			//cvSet2D(s_maximum_point_image,y,x,scalar);
			
			//int val = ((uchar *)(s_gradient_flag_image->imageData + s_gradient_flag_image->widthStep * x))[y];
			//int lv = ((uchar *)(s_gradient_flag_image->imageData + s_gradient_flag_image->widthStep * (x-1)))[y];
			//int rv = ((uchar *)(s_gradient_flag_image->imageData + s_gradient_flag_image->widthStep * (x+1)))[y];
			//int bv = ((uchar *)(s_gradient_flag_image->imageData + s_gradient_flag_image->widthStep * x))[y-1];
			//int av = ((uchar *)(s_gradient_flag_image->imageData + s_gradient_flag_image->widthStep * x))[y+1];

			scalar = cvGet2D(s_gradient_flag_image,y,x); int val = scalar.val[0];
			scalar = cvGet2D(s_gradient_flag_image,y,(x-1)); int lv = scalar.val[0];
			scalar = cvGet2D(s_gradient_flag_image,y,(x+1)); int rv = scalar.val[0];
			scalar = cvGet2D(s_gradient_flag_image,(y-1),x); int bv = scalar.val[0];
			scalar = cvGet2D(s_gradient_flag_image,(y+1),x); int av = scalar.val[0];

			if(val > lv && val > rv && val > bv && val > av)
			{	
				scalar = cvGet2D(s_maximum_point_image,y,x);
				scalar.val[0] = 255;
				cvSet2D(s_maximum_point_image,y,x,scalar);
			}		

			if(val < lv && val < rv && val < bv && val < av)
			{	
				scalar = cvGet2D(s_minimum_point_image,y,x);
				scalar.val[0] = 255;
				cvSet2D(s_minimum_point_image,y,x,scalar);
			}
	
		}
	}

	cvNamedWindow("Maximum Point Image");
	cvShowImage("Maximum Point Image",s_maximum_point_image);

	cvNamedWindow("Minimum Point Image");
	cvShowImage("Minimum Point Image",s_minimum_point_image);

	cvReleaseImage(&s_maximum_point_image);
	cvReleaseImage(&s_minimum_point_image);

}

void CSegmentationDoc::OnMenuitemGetoriginalsegmentationopencv() 
{
	// TODO: Add your command handler code here
	IplImage *pImg = m_image.GetImage();

	IplImage *mark_image = cvCreateImage(cvGetSize(s_gradient_flag_image),IPL_DEPTH_32S,1);
	cvZero(mark_image);

	CvScalar scalar;
	int x,y;

	int count = 1;
	for(x = 0; x < s_gradient_flag_image->width; x++)
	{
		for(y = 0; y < s_gradient_flag_image->height;y++)
		{
			//int val = ((uchar *)(s_gradient_flag_image->imageData + s_gradient_flag_image->widthStep * x))[y];
			//int lv = ((uchar *)(s_gradient_flag_image->imageData + s_gradient_flag_image->widthStep * (x-1)))[y];
			//int rv = ((uchar *)(s_gradient_flag_image->imageData + s_gradient_flag_image->widthStep * (x+1)))[y];
			//int bv = ((uchar *)(s_gradient_flag_image->imageData + s_gradient_flag_image->widthStep * x))[y-1];
			//int av = ((uchar *)(s_gradient_flag_image->imageData + s_gradient_flag_image->widthStep * x))[y+1];
			scalar = cvGet2D(s_gradient_flag_image,y,x); int val = scalar.val[0];
			scalar = cvGet2D(s_gradient_flag_image,y,(x-1)); int lv = scalar.val[0];
			scalar = cvGet2D(s_gradient_flag_image,y,(x+1)); int rv = scalar.val[0];
			scalar = cvGet2D(s_gradient_flag_image,(y-1),x); int bv = scalar.val[0];
			scalar = cvGet2D(s_gradient_flag_image,(y+1),x); int av = scalar.val[0];


			if(val < lv && val < rv && val < bv && val < av)
			{	
				scalar = cvGet2D(mark_image,y,x);
				scalar.val[0] = val;
				cvSet2D(mark_image,y,x,scalar);
			}
		}
	}

	cvWatershed(pImg,mark_image);

	IplImage *border_image = cvCreateImage(cvGetSize(mark_image),IPL_DEPTH_8U,1);
	cvZero(border_image);

	for(x = 0; x < border_image->width; x++)
	{
		for(y = 0; y < border_image->height;y++)
		{
			scalar = cvGet2D(mark_image,y,x);
			if(scalar.val[0] == -1)
			{
				scalar = cvGet2D(border_image,y,x);
				scalar.val[0] = 255;
				cvSet2D(border_image,y,x,scalar);
			}
		}
	}

	cvNamedWindow("Border Image(OpenCV)");
	cvShowImage("Border Image(OpenCV)",border_image);


	IplImage *mark_image_8u = cvCreateImage(cvGetSize(mark_image),IPL_DEPTH_8U,1);
	cvConvertScale(mark_image,mark_image_8u);

	cvNamedWindow("Watershed Image(OpenCV)");
	cvShowImage("Watershed Image(OpenCV)",mark_image_8u);

	cvReleaseImage(&mark_image);
	cvReleaseImage(&border_image);
}

void CSegmentationDoc::OnMenuitemGetssegmentationopencv() 
{
	// TODO: Add your command handler code here

	IplImage *mark_image = cvCreateImage(cvGetSize(s_gradient_flag_image),IPL_DEPTH_32S,1);
	cvZero(mark_image);

	CvScalar scalar;
	int x,y;

	int count = 1;
	for(x = 1; x < s_gradient_flag_image->width-1; x++)
	{
		for(y = 1; y < s_gradient_flag_image->height-1;y++)
		{
			//int val = ((uchar *)(s_gradient_flag_image->imageData + s_gradient_flag_image->widthStep * x))[y];
			//int lv = ((uchar *)(s_gradient_flag_image->imageData + s_gradient_flag_image->widthStep * (x-1)))[y];
			//int rv = ((uchar *)(s_gradient_flag_image->imageData + s_gradient_flag_image->widthStep * (x+1)))[y];
			//int bv = ((uchar *)(s_gradient_flag_image->imageData + s_gradient_flag_image->widthStep * x))[y-1];
			//int av = ((uchar *)(s_gradient_flag_image->imageData + s_gradient_flag_image->widthStep * x))[y+1];
			scalar = cvGet2D(s_gradient_flag_image,y,x); int val = scalar.val[0];
			scalar = cvGet2D(s_gradient_flag_image,y,(x-1)); int lv = scalar.val[0];
			scalar = cvGet2D(s_gradient_flag_image,y,(x+1)); int rv = scalar.val[0];
			scalar = cvGet2D(s_gradient_flag_image,(y-1),x); int bv = scalar.val[0];
			scalar = cvGet2D(s_gradient_flag_image,(y+1),x); int av = scalar.val[0];

			if(val <= lv && val <= rv && val <= bv && val <= av)
			{	
				scalar = cvGet2D(mark_image,y,x);
				if(val == 0)
				{
					scalar.val[0] = 1;
				}
				else
				{
					scalar.val[0] = 255;
				}
				cvSet2D(mark_image,y,x,scalar);
			}
		}
	}

	IplImage *s_gradient_flag_image_3c = cvCreateImage(cvGetSize(s_gradient_flag_image),IPL_DEPTH_8U,3);
	cvCvtColor(s_gradient_flag_image, s_gradient_flag_image_3c, CV_GRAY2BGR);

	cvWatershed(s_gradient_flag_image_3c,mark_image);

	border_image = cvCreateImage(cvGetSize(mark_image),IPL_DEPTH_8U,1);
	cvZero(border_image);

	for(x = 0; x < border_image->width; x++)
	{
		for(y = 0; y < border_image->height;y++)
		{
			scalar = cvGet2D(mark_image,y,x);
			if(scalar.val[0] == -1)
			{
				scalar = cvGet2D(border_image,y,x);
				scalar.val[0] = 255;
				cvSet2D(border_image,y,x,scalar);
			}
		}
	}


	//ofstream outfile1("D://log/border_image_point.txt");
	//for(y = 0; y < border_image->height; y++)
	//{
	//	for(x = 0; x < border_image->width; x++)
	//	{
	//		scalar = cvGet2D(border_image,y,x);
	//		outfile1<<"x="<<x<<",y="<<y<<",value="<<scalar.val[0]<<endl;
	//	}
	//}
	//outfile1.close();


	cvNamedWindow("Border Image(OpenCV)");
	cvShowImage("Border Image(OpenCV)",border_image);


	IplImage *mark_image_8u = cvCreateImage(cvGetSize(mark_image),IPL_DEPTH_8U,1);
	cvConvertScale(mark_image,mark_image_8u);

	cvNamedWindow("Watershed Image(OpenCV)");
	cvShowImage("Watershed Image(OpenCV)",mark_image_8u);

	cvReleaseImage(&mark_image);
	//cvReleaseImage(&border_image);
}

void CSegmentationDoc::OnMenuitemGetrcannels() 
{
	// TODO: Add your command handler code here
	IplImage *pImg = m_image.GetImage();

	r_img =cvCreateImage(cvGetSize(pImg),IPL_DEPTH_8U,1);
	IplImage *g_image =cvCreateImage(cvGetSize(pImg),IPL_DEPTH_8U,1);
	IplImage *b_image =cvCreateImage(cvGetSize(pImg),IPL_DEPTH_8U,1);

    cvSplit(pImg,r_img,g_image,b_image,NULL);  

	cvNamedWindow("R Cannels");
	cvShowImage("R Cannels",r_img);

	//cvNamedWindow("G Cannels");
	//cvShowImage("G Cannels",g_image);

	//cvNamedWindow("B Cannels");
	//cvShowImage("B Cannels",b_image);

	cvReleaseImage(&g_image);
	cvReleaseImage(&b_image);
}

void CSegmentationDoc::OnMenuitemGetrsegmentationopencv() 
{
	// TODO: Add your command handler code here
	IplImage *mark_image = cvCreateImage(cvGetSize(s_gradient_flag_image),IPL_DEPTH_32S,1);
	cvZero(mark_image);

	CvScalar scalar;
	int x,y;

	int count = 1;
	for(x = 0; x < s_gradient_flag_image->width; x++)
	{
		for(y = 0; y < s_gradient_flag_image->height;y++)
		{
			//int val = ((uchar *)(s_gradient_flag_image->imageData + s_gradient_flag_image->widthStep * x))[y];
			//int lv = ((uchar *)(s_gradient_flag_image->imageData + s_gradient_flag_image->widthStep * (x-1)))[y];
			//int rv = ((uchar *)(s_gradient_flag_image->imageData + s_gradient_flag_image->widthStep * (x+1)))[y];
			//int bv = ((uchar *)(s_gradient_flag_image->imageData + s_gradient_flag_image->widthStep * x))[y-1];
			//int av = ((uchar *)(s_gradient_flag_image->imageData + s_gradient_flag_image->widthStep * x))[y+1];
			scalar = cvGet2D(s_gradient_flag_image,y,x); int val = scalar.val[0];
			scalar = cvGet2D(s_gradient_flag_image,y,(x-1)); int lv = scalar.val[0];
			scalar = cvGet2D(s_gradient_flag_image,y,(x+1)); int rv = scalar.val[0];
			scalar = cvGet2D(s_gradient_flag_image,(y-1),x); int bv = scalar.val[0];
			scalar = cvGet2D(s_gradient_flag_image,(y+1),x); int av = scalar.val[0];

			if(val < lv && val < rv && val < bv && val < av)
			{	
				scalar = cvGet2D(mark_image,y,x);
				scalar.val[0] = val;
				cvSet2D(mark_image,y,x,scalar);
			}
		}
	}

	IplImage *r_img_3c = cvCreateImage(cvGetSize(r_img),IPL_DEPTH_8U,3);
	cvCvtColor(r_img, r_img_3c, CV_GRAY2BGR);

	cvWatershed(r_img_3c,mark_image);

	IplImage *border_image = cvCreateImage(cvGetSize(mark_image),IPL_DEPTH_8U,1);
	cvZero(border_image);

	for(x = 0; x < border_image->width; x++)
	{
		for(y = 0; y < border_image->height;y++)
		{
			scalar = cvGet2D(mark_image,y,x);
			if(scalar.val[0] == -1)
			{
				scalar = cvGet2D(border_image,y,x);
				scalar.val[0] = 255;
				cvSet2D(border_image,y,x,scalar);
			}
		}
	}

	cvNamedWindow("Border Image(OpenCV)");
	cvShowImage("Border Image(OpenCV)",border_image);


	IplImage *mark_image_8u = cvCreateImage(cvGetSize(mark_image),IPL_DEPTH_8U,1);
	cvConvertScale(mark_image,mark_image_8u);

	cvNamedWindow("R Cannels Watershed Image(OpenCV)");
	cvShowImage("R Cannels Watershed Image(OpenCV)",mark_image_8u);

	cvReleaseImage(&mark_image);
	cvReleaseImage(&border_image);
	cvReleaseImage(&r_img_3c);
}

void CSegmentationDoc::OnMenuitemGetmorphologygradient() 
{
	// TODO: Add your command handler code here

	s_gradient_image = cvCreateImage(cvGetSize(s_img),8,1);
	IplImage *tmp_image = cvCreateImage(cvGetSize(s_img),8,1); 
	
	cvMorphologyEx(s_img,s_gradient_image,tmp_image,NULL,CV_MOP_GRADIENT,1);

	cvNamedWindow("Graditent Image(Morphology)");
	cvShowImage("Graditent Image(Morphology)",s_gradient_image);

	cvReleaseImage(&tmp_image);
}

void CSegmentationDoc::OnMenuitemGetcontourlinemanual() 
{
	// TODO: Add your command handler code here
	CContourParameterDialog dialog;

	int x=s_img->width / 2,y=s_img->height / 2;

	dialog.m_x = x;
	dialog.m_y = y;


	if(dialog.DoModal() == IDOK)
	{
		x = dialog.m_x;
		y = dialog.m_y;
	}
	else return;

	IplImage *contour_image = cvCreateImage(cvGetSize(border_image),IPL_DEPTH_8U,1);
	cvZero(contour_image);
	
	int *mark = new int[border_image->height * border_image->width];
	memset(mark,0,border_image->height * border_image->width * sizeof(int));

	queue<int> xq;
	queue<int> yq;

	xq.push(x);
	yq.push(y);

	int idx_x[] = {-1,0,+1,0};
	int idx_y[] = {0,-1,0,+1};
	CvScalar scalar,s1;
	int count=0;
	while(!xq.empty())
	{

		x = xq.front();xq.pop();
		y = yq.front();yq.pop();

		if(mark[y*border_image->width+x] == 0)
		{
			mark[y*border_image->width+x] = 1;
		}
		else
		{
			continue;
		}

		if(x==0 || x==border_image->width-1 || y==0 || y==border_image->height-1) continue;

		for(int i = 0; i < 4; i++)
		{
			scalar = cvGet2D(border_image,(y+idx_y[i]),(x+idx_x[i]));
			if(scalar.val[0] == 0)
			{
				if(mark[(y+idx_y[i]) * border_image->width + (x+idx_x[i])] == 0)
				{
					xq.push((x+idx_x[i]));
					yq.push((y+idx_y[i]));
				}

			}
			else
			{
				s1 = cvGet2D(contour_image,(y+idx_y[i]),(x+idx_x[i]));
				s1.val[0] = 255;
				cvSet2D(contour_image,(y+idx_y[i]),(x+idx_x[i]),s1);
			}
		}

		//if(count++ > 10000) break; 
	}

	cvNamedWindow("Contour Image");
	cvShowImage("Contour Image",contour_image);

	delete []mark;
	cvReleaseImage(&contour_image);

}

//source : http://blog.sina.com.cn/s/blog_6f611c3001017y5m.html
/*void ZhangThinning(int w,int h,BYTE *imgBuf)

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

       for(y=1;y<<span style="line-height: 28px; color: rgb(1, 0, 1);">h-1;y++)

       {

           for(x=1;x<<span style="line-height: 28px; color: rgb(1, 0, 1);">w-1;x++)

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

           for(y=0;y<<span style="line-height: 28px; color: rgb(1, 0, 1);">h;y++)

           {

              for(x=0;x<<span style="line-height: 28px; color: rgb(1, 0, 1);">w;x++)

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

       for(y=1;y<<span style="line-height: 28px; color: rgb(1, 0, 1);">h-1;y++)

       {

           for(x=1;x<<span style="line-height: 28px; color: rgb(1, 0, 1);">w-1;x++)

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

       for(y=0;y<<span style="line-height: 28px; color: rgb(1, 0, 1);">h;y++)

       {

           for(x=0;x<<span style="line-height: 28px; color: rgb(1, 0, 1);">w;x++)

           {

              k=y*w+x;

              if(mark[k]==1)

              {

                  imgBuf[k]=0;

              }

           }

       }

 

    } 

}*/
