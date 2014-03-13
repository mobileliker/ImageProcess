// SkeletonDoc.cpp : implementation of the CSkeletonDoc class
//

#include "stdafx.h"
#include "Skeleton.h"

#include "SkeletonDoc.h"
#include "SelectSizeDialog.h"
#include "SelectThresholdDialog.h"

#include "fstream.h"
#include "queue"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using std::queue;

/////////////////////////////////////////////////////////////////////////////
// CSkeletonDoc

IMPLEMENT_DYNCREATE(CSkeletonDoc, CDocument)

BEGIN_MESSAGE_MAP(CSkeletonDoc, CDocument)
	//{{AFX_MSG_MAP(CSkeletonDoc)
	ON_COMMAND(ID_MENUITEM_GETBCANNELS, OnMenuitemGetbcannels)
	ON_COMMAND(ID_MENUITEM_GETSMOOTHIMAGE, OnMenuitemGetsmoothimage)
	ON_COMMAND(ID_MENUITEM_GETTHRESHOLDIMAGEOSTU, OnMenuitemGetthresholdimageostu)
	ON_COMMAND(ID_MENUITEM_GETTHRESHOLDIMAGEMANNAL, OnMenuitemGetthresholdimagemannal)
	ON_COMMAND(ID_MENUITEM_GETTHINIMAGE, OnMenuitemGetthinimage)
	ON_COMMAND(ID_MENUITEM_GETTHINIMAGEZHANG, OnMenuitemGetthinimagezhang)
	ON_COMMAND(ID_MENUITEM_GETTHINIMAGEROSEENFELD, OnMenuitemGetthinimageroseenfeld)
	ON_COMMAND(ID_MENUITEM_GETGRAYIMAGE, OnMenuitemGetgrayimage)
	ON_COMMAND(ID_MENUITEM_GETTHINIMAGEDISTANCE, OnMenuitemGetthinimagedistance)
	ON_COMMAND(ID_MENUITEM_ROOTGETTHRESHOLDIMAGEOSTU, OnMenuitemRootgetthresholdimageostu)
	ON_COMMAND(ID_MENUITEM_ROOTGETTHRESHOLDIMAGEMANNAL, OnMenuitemRootgetthresholdimagemannal)
	ON_COMMAND(ID_MENUITEM_GETISOLATEPOINT, OnMenuitemGetisolatepoint)
	ON_COMMAND(ID_MENUITEM_COMPLETEISOLATE, OnMenuitemCompleteisolate)
	ON_COMMAND(ID_MENUITEM_GETENDPOINT, OnMenuitemGetendpoint)
	ON_COMMAND(ID_MENUITEM_COMPLETEEND, OnMenuitemCompleteend)
	ON_COMMAND(ID_MENUITEM_GETBRACH, OnMenuitemGetbrach)
	ON_COMMAND(ID_MENUITEM_CALBRACHDATA, OnMenuitemCalbrachdata)
	ON_COMMAND(ID_MENUITEM_ALL, OnMenuitemAll)
	ON_COMMAND(ID_MENUITEM_COMPLETEMANNAL, OnMenuitemCompletemannal)
	ON_COMMAND(ID_MENUITEM_SAVEIMAGE, OnMenuitemSaveimage)
	ON_COMMAND(ID_MENUITEM_SOYBEANGETGRAYIMAGE, OnMenuitemSoybeangetgrayimage)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSkeletonDoc construction/destruction

CSkeletonDoc::CSkeletonDoc()
{
	// TODO: add one-time construction code here
	m_bmannal = FALSE;
}

CSkeletonDoc::~CSkeletonDoc()
{
}

BOOL CSkeletonDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSkeletonDoc serialization

void CSkeletonDoc::Serialize(CArchive& ar)
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
// CSkeletonDoc diagnostics

#ifdef _DEBUG
void CSkeletonDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSkeletonDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

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
 


/////////////////////////////////////////////////////////////////////////////
// CSkeletonDoc commands

BOOL CSkeletonDoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;

	// TODO: Add your specialized creation code here
	if(CheckExtendName(lpszPathName,"bmp"))
	{
		this->type_flag = 0;
		m_image.Load(lpszPathName);
	}
	else if(CheckExtendName(lpszPathName,"avi"))
	{
		this->type_flag = 1;
		m_capture = cvCreateFileCapture(lpszPathName);
		IplImage *pImg = cvQueryFrame(m_capture);
		m_image.CopyOf(pImg);
	}
	else
	{
		AfxMessageBox("The File Format isn't supported.");
	}

	return TRUE;
}

BOOL CSkeletonDoc::OnSaveDocument(LPCTSTR lpszPathName) 
{
	// TODO: Add your specialized code here and/or call the base class
	m_image.Save(lpszPathName);

	return CDocument::OnSaveDocument(lpszPathName);
}

void CSkeletonDoc::OnMenuitemGetbcannels() 
{
	// TODO: Add your command handler code here
	IplImage *pImg = m_image.GetImage();

	IplImage *r_image = cvCreateImage(cvGetSize(pImg),IPL_DEPTH_8U,1);
	IplImage *g_image = cvCreateImage(cvGetSize(pImg),IPL_DEPTH_8U,1);
	b_image = cvCreateImage(cvGetSize(pImg),IPL_DEPTH_8U,1);

	cvSplit(pImg,r_image,g_image,b_image,NULL);

	//cvNamedWindow("R Cannels");
	//cvShowImage("R Cannels",r_image);

	//cvNamedWindow("G Cannels");
	//cvShowImage("G Cannels",g_image);

	cvNamedWindow("B Cannels");
	cvShowImage("B Cannels",b_image);

	cvReleaseImage(&r_image);
	cvReleaseImage(&g_image);

}

void CSkeletonDoc::OnMenuitemGetsmoothimage() 
{
	// TODO: Add your command handler code here
	smooth_image = cvCreateImage(cvGetSize(b_image),IPL_DEPTH_8U,1);

	int size = 3;

	CSelectSizeDialog dialog;
	dialog.m_size = size;

	if(dialog.DoModal() == IDOK)
	{
		size = dialog.m_size;
	}
	else return;

	cvSmooth(b_image,smooth_image,CV_MEDIAN,size,size,0,0);

	cvNamedWindow("Smooth Filter Image");
	cvShowImage("Smooth Filter Image",smooth_image);
}

void CSkeletonDoc::OnMenuitemGetthresholdimageostu() 
{
	// TODO: Add your command handler code here

	threshold_image = cvCreateImage(cvGetSize(smooth_image),IPL_DEPTH_8U,1);

	cvThreshold(smooth_image,threshold_image,1,255,CV_THRESH_OTSU);

	cvNamedWindow("Threshold Image(OSTU)");
	cvShowImage("Threshold Image(OSTU)",threshold_image);
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


void CSkeletonDoc::OnMenuitemGetthresholdimagemannal() 
{
	// TODO: Add your command handler code here
	threshold_image = cvCreateImage(cvGetSize(smooth_image),IPL_DEPTH_8U,1);
	IplImage *thin_image = cvCreateImage(cvGetSize(smooth_image),IPL_DEPTH_8U,1);

	//cal threshold reference value
	int hist_size = 256;
	int hist_height = 256;
	float range[] = {0,255};
	float* ranges[] = {range};

	CvHistogram *s_hist = cvCreateHist(1,&hist_size,CV_HIST_ARRAY,ranges,1);//create
	cvCalcHist(&smooth_image,s_hist,0,0);
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
	}

	if(threshold_type == 0)
	{
		cvThreshold(smooth_image,threshold_image,threshold,255,CV_THRESH_BINARY);
	}
	else
	{
		cvThreshold(smooth_image,threshold_image,threshold,255,CV_THRESH_BINARY_INV);
	}


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


	cvNamedWindow("Threshold Image(Mannal)");
	cvShowImage("Threshold Image(Mannal)",threshold_image);


}

void CSkeletonDoc::OnMenuitemGetthinimage() 
{
	// TODO: Add your command handler code here
	thin_image = cvCreateImage(cvGetSize(threshold_image),IPL_DEPTH_8U,1);
	IplImage *tmp_image = cvCreateImage(cvGetSize(threshold_image),IPL_DEPTH_8U,1);
	cvConvertScale(threshold_image,tmp_image,1.0/255.0);

	cvThin(tmp_image,thin_image,8);
	cvConvertScale(thin_image,thin_image,255.0);

	cvNamedWindow("Threshold Image");
	cvShowImage("Threshold Image",threshold_image);

	cvNamedWindow("Thin Image");
	cvShowImage("Thin Image",thin_image);

	cvReleaseImage(&tmp_image);

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


void CSkeletonDoc::OnMenuitemGetthinimagezhang() 
{
	// TODO: Add your command handler code here
	thin_image = cvCreateImage(cvGetSize(threshold_image),IPL_DEPTH_8U,1);

	BYTE *imgBuf = new BYTE[threshold_image->width * threshold_image->height];
	int x,y;
	CvScalar scalar;
	for(x = 0; x < threshold_image->width; x++)
	{
		for(y = 0; y < threshold_image->height; y++)
		{
			scalar = cvGet2D(threshold_image,y,x);
			imgBuf[y*threshold_image->width+x]=(char)scalar.val[0];
		}
	}

	ZhangThinning(threshold_image->width,threshold_image->height,imgBuf);

	for(x = 0; x < threshold_image->width; x++)
	{
		for(y = 0; y < threshold_image->height; y++)
		{
			scalar = cvGet2D(threshold_image,y,x);
			scalar.val[0] = imgBuf[y*threshold_image->width+x];
			cvSet2D(thin_image,y,x,scalar);
		}
	}

	cvNamedWindow("Thin Image(Zhang)");
	cvShowImage("Thin Image(Zhang)",thin_image);

	delete[] imgBuf;
}

/////////////////////////////////////////////////////////////////////////
//Rosenfeld细化算法
//功能：对图象进行细化
//参数：image：代表图象的一维数组
//      lx：图象宽度
//      ly：图象高度
//      无返回值
void ThinnerRosenfeld(void *image, unsigned long lx, unsigned long ly)
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
        printf("error in alocating mmeory!/n");
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

void icvRosenfeldThin(BYTE* src,int w,int h)
{
	BYTE p1,p2,p3,p4,p5,p6,p7,p8,p9;
	int flag;
	int x,y;

	BYTE *tmp = new BYTE[w*h];
	//memcpy(tmp,src,sizeof(BYTE)*w*h);
	for(x = 0; x < w; x++){for(y = 0; y < h; y++){tmp[y*w+x]=src[y*w+x];}}

	int count = 0;
	do
	{
		flag = 0;
		for(x = 1; x < w-1; x++)
		{
			for(y = 1; y < h-1; y++)
			{
				if(src[y*w+x])
				{
					p1 = src[y*w+x];
					p2 = src[(y-1)*w+x];p3 = src[(y-1)*w+(x-1)];p4 = src[y*w+(x-1)];p5 = src[(y+1)*w+(x-1)];
					p6 = src[(y+1)*w+x];p7 = src[(y+1)*w+x];p8 = src[y*w+(x+1)];p9 = src[(y-1)*w+(x+1)];

					if(!p2 || !p4 || !p6 || !p8)
					{
						if(!p2 && !p6 && (p7+p8+p9)>=1) {tmp[y*w+x] = 0; flag = 1; count++;}
						else if(!p4 && !p8 && (p5+p6+p7)>=1) {tmp[y*w+x] = 0; flag = 1; count++;}
						else if(!p2 && !p6 && (p3+p4+p5)>=1) {tmp[y*w+x] = 0; flag = 1; count++;}
						else if(!p4 && !p8 && (p9+p2+p3)>=1) {tmp[y*w+x] = 0; flag = 1; count++;}
						else if(!p4 && !p6 && p5) {tmp[y*w+x] = 0; flag = 1; count++;}
						else if(!p2 && !p4 && p3) {tmp[y*w+x] = 0; flag = 1; count++;}
						else if(!p8 && !p2 && p9) {tmp[y*w+x] = 0; flag = 1; count++;}
						else if(!p6 && !p8 && p7) {tmp[y*w+x] = 0; flag = 1; count++;}
					}
				}
			}
		}
		//memcpy(src,tmp,sizeof(BYTE)*w*h);		
		for(x = 0; x < w; x++){for(y = 0; y < h; y++){src[y*w+x]=tmp[y*w+x];}}
	}while(flag);

	delete[] tmp;
}

void CSkeletonDoc::OnMenuitemGetthinimageroseenfeld() 
{
	// TODO: Add your command handler code here
	thin_image = cvCreateImage(cvGetSize(threshold_image),IPL_DEPTH_8U,1);
	cvZero(thin_image);
	IplImage *tmp_image = cvCreateImage(cvGetSize(threshold_image),IPL_DEPTH_8U,1);
	cvConvertScale(threshold_image,tmp_image,1.0/255.0);

	BYTE *imgBuf = new BYTE[tmp_image->width * tmp_image->height];
	memset(imgBuf,0,sizeof(BYTE)*tmp_image->width * tmp_image->height);
	int x,y;
	CvScalar scalar;
	for(x = 0; x < tmp_image->width; x++)
	{
		for(y = 0; y < tmp_image->height; y++)
		{
			scalar = cvGet2D(tmp_image,y,x);
			imgBuf[y*tmp_image->width+x] = (BYTE)scalar.val[0];
		}
	}

	icvRosenfeldThin(imgBuf,tmp_image->width,tmp_image->height);

	for(x = 0; x < tmp_image->width; x++)
	{
		for(y = 0; y < tmp_image->height; y++)
		{
			scalar = cvGet2D(tmp_image,y,x);
			scalar.val[0] = imgBuf[y*tmp_image->width+x];
			cvSet2D(tmp_image,y,x,scalar);
		}
	}

	cvConvertScale(tmp_image,thin_image,255.0);
	cvNamedWindow("Thin Image(Rosenfeld)");
	cvShowImage("Thin Image(Rosenfeld)",thin_image);

	delete[] imgBuf;

}

void CSkeletonDoc::OnMenuitemGetgrayimage() 
{
	// TODO: Add your command handler code here
	IplImage *pImg = m_image.GetImage();

	gray_image = cvCreateImage(cvGetSize(pImg),IPL_DEPTH_8U,1);
	cvCvtColor(pImg,gray_image,CV_RGB2GRAY);

	if(gray_image->origin != pImg->origin)
	{
		gray_image->origin = pImg->origin;
	}

	//int x,y;
	//CvScalar scalar;
	//ofstream outfile1("D://log/gray_image_point.txt");
	//for(x = 0; x < gray_image->width; x++)
	//{
	//	for(y = 0; y < gray_image->height; y++)
	//	{
	//		scalar = cvGet2D(gray_image,y,x);
	//		outfile1<<"x="<<x<<",y="<<y<<",value="<<scalar.val[0]<<endl;
	//	}
	//}
	//outfile1.close();

	cvNamedWindow("Gray Image");
	cvShowImage("Gray Image",gray_image);

}


void CSkeletonDoc::OnMenuitemRootgetthresholdimageostu() 
{
	// TODO: Add your command handler code here
	threshold_image = cvCreateImage(cvGetSize(gray_image),IPL_DEPTH_8U,1);

	cvThreshold(gray_image,threshold_image,1,255,CV_THRESH_OTSU);

	cvNamedWindow("Threshold Image(OTSU)");
	cvShowImage("Threshold Image(OTSU)",threshold_image);

}

void CSkeletonDoc::OnMenuitemRootgetthresholdimagemannal() 
{
	// TODO: Add your command handler code here
	threshold_image = cvCreateImage(cvGetSize(gray_image),IPL_DEPTH_8U,1);
	IplImage *thin_image = cvCreateImage(cvGetSize(gray_image),IPL_DEPTH_8U,1);

	//cal threshold reference value
	int hist_size = 256;
	int hist_height = 256;
	float range[] = {0,255};
	float* ranges[] = {range};

	CvHistogram *s_hist = cvCreateHist(1,&hist_size,CV_HIST_ARRAY,ranges,1);//create
	cvCalcHist(&gray_image,s_hist,0,0);
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

		if(threshold_type == 0)
		{
			cvThreshold(gray_image,threshold_image,threshold,255,CV_THRESH_BINARY);
		}
		else
		{
			cvThreshold(gray_image,threshold_image,threshold,255,CV_THRESH_BINARY_INV);
		}

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


		cvNamedWindow("Threshold Image(Mannal)");
		cvShowImage("Threshold Image(Mannal)",threshold_image);

		cvSaveImage("threshold.png",threshold_image);


	}

}

void CSkeletonDoc::OnMenuitemGetthinimagedistance() 
{
	// TODO: Add your command handler code here

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
    IplImage *distsrc;
    distsrc=cvCreateImage(cvGetSize(threshold_image),IPL_DEPTH_32F,1);
	cvDistTransform(threshold_image,distsrc,CV_DIST_L2,5);

	//filter or Convolution
    IplImage *S00;
    IplImage *S45;
    IplImage *S90;
    IplImage *S135;
	S00=cvCreateImage(cvGetSize(threshold_image),IPL_DEPTH_32F,1);
    S45=cvCreateImage(cvGetSize(threshold_image),IPL_DEPTH_32F,1);
    S90=cvCreateImage(cvGetSize(threshold_image),IPL_DEPTH_32F,1);
    S135=cvCreateImage(cvGetSize(threshold_image),IPL_DEPTH_32F,1);
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
    out=cvCreateImage(cvGetSize(threshold_image),IPL_DEPTH_32F,1);
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

	//show image
	cvNamedWindow("Thin Image(Distance)");
	cvShowImage("Thin Image(Distance)",out);

	cvReleaseImage(&S00);
	cvReleaseImage(&S45);
	cvReleaseImage(&S90);
	cvReleaseImage(&S135);
	cvReleaseImage(&distsrc);
	cvReleaseImage(&out);


}

void CSkeletonDoc::OnMenuitemGetisolatepoint() 
{
	// TODO: Add your command handler code here
	int x,y;
	IplImage *lp_frame;
	CvScalar p1,p2,p3,p4,p5,p6,p7,p8,p9;
	int idx_frame = 0;
	ofstream outfile1("D://log/isolate_image_point.txt");
	if(type_flag == 1)
	{
		isolate_point_frame.clear();
		isolate_point_x.clear();
		isolate_point_y.clear();

		lp_frame = cvQueryFrame(m_capture);
		while(lp_frame != NULL)
		{
			for(x = 1; x < lp_frame->width - 1; x++)
			{
				for(y = 1; y < lp_frame->height - 1; y++)
				{
					p1 = cvGet2D(lp_frame,y - 1,x - 1);
					p2 = cvGet2D(lp_frame,y - 1,x);
					p3 = cvGet2D(lp_frame,y - 1,x + 1);

					p4 = cvGet2D(lp_frame,y,x - 1);
					p5 = cvGet2D(lp_frame,y,x);
					p6 = cvGet2D(lp_frame,y,x + 1);

					p7 = cvGet2D(lp_frame,y + 1,x - 1);
					p8 = cvGet2D(lp_frame,y + 1,x);
					p9 = cvGet2D(lp_frame,y + 1,x + 1);

					if(p5.val[0] == 0 && p1.val[0] == 255 && p2.val[0] == 255 && p3.val[0] == 255 && p4.val[0] == 255 
						&& p6.val[0] == 255 && p7.val[0] == 255 && p8.val[0] == 255 && p9.val[0] == 255)
					{
						outfile1<<"frame="<<idx_frame<<",x="<<x<<",y="<<y<<endl;
						isolate_point_frame.push_back(idx_frame);
						isolate_point_x.push_back(x);
						isolate_point_y.push_back(y);
					}
				}
			}
			++idx_frame;
			lp_frame = cvQueryFrame(m_capture);
		}

	}
	else
	{
		isolate_point_frame.clear();
		isolate_point_x.clear();
		isolate_point_y.clear();

		IplImage *pImg = m_image.GetImage();

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
	}
	outfile1.close();
	UpdateAllViews(NULL);
	AfxMessageBox("Finish Get Isolate Point.");
}

void CSkeletonDoc::OnMenuitemCompleteisolate() 
{
	// TODO: Add your command handler code here
	int val1 = 6;

	int idx_frame,x,y;
	int i,j,ix,iy;
	CvScalar scalar;
	ofstream outfile1("D://log/complete_isolate_result.txt");
	if(type_flag == 0)
	{
		IplImage *pImg = m_image.GetImage();
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
					if(ix >= 0 && ix <= pImg->width)
					{
						scalar = cvGet2D(pImg,iy,ix);
						if(scalar.val[0] == 0) break;
					}

					ix = x + i;
					if(ix >= 0 && ix <= pImg->width)
					{
						scalar = cvGet2D(pImg,iy,ix);
						if(scalar.val[0] == 0) break;
					}
				}
				if(iy <= y + i) break;
			}
			if(i <= val1)
			{
				outfile1<<"x="<<x<<",y="<<y<<",ix="<<ix<<",iy="<<iy<<endl;
				cvLine(pImg,cvPoint(x,y),cvPoint(ix,iy),CV_RGB(0,0,0));
			}
			else
			{
				cvSet2D(pImg,y,x,cvScalar(0));
			}

		}
		AfxMessageBox("Finish Complete Image(Isolate)");
		//cvNamedWindow("Complete Image(Isolate)");
		//cvShowImage("Complete Image(Isolate)",pImg);
		cvSaveImage("D://log/complete_isolate_image.bmp",pImg);
	}
	else
	{

	}

	outfile1.close();
	UpdateAllViews(NULL);
}

void CSkeletonDoc::OnMenuitemGetendpoint() 
{
	// TODO: Add your command handler code here
	int x,y;
	IplImage *lp_frame;
	CvScalar p1,p2,p3,p4,p5,p6,p7,p8,p9;
	int idx_frame = 0;
	ofstream outfile1("D://log/endpoint_image_point.txt");
	if(type_flag == 1)
	{
		end_point_frame.clear();
		end_point_x.clear();
		end_point_y.clear();

		lp_frame = cvQueryFrame(m_capture);
		while(lp_frame != NULL)
		{
			for(x = 1; x < lp_frame->width - 1; x++)
			{
				for(y = 1; y < lp_frame->height - 1; y++)
				{
					p1 = cvGet2D(lp_frame,y - 1,x - 1);
					p2 = cvGet2D(lp_frame,y - 1,x);
					p3 = cvGet2D(lp_frame,y - 1,x + 1);

					p4 = cvGet2D(lp_frame,y,x - 1);
					p5 = cvGet2D(lp_frame,y,x);
					p6 = cvGet2D(lp_frame,y,x + 1);

					p7 = cvGet2D(lp_frame,y + 1,x - 1);
					p8 = cvGet2D(lp_frame,y + 1,x);
					p9 = cvGet2D(lp_frame,y + 1,x + 1);

					if(p5.val[0] == 0 && (p1.val[0] + p2.val[0] + p3.val[0] + p4.val[0] + p6.val[0] + p7.val[0] + p8.val[0] + p9.val[0]) == 7 * 255)
					{
						outfile1<<"frame="<<idx_frame<<",x="<<x<<",y="<<y<<endl;
						end_point_frame.push_back(idx_frame);
						end_point_x.push_back(x);
						end_point_y.push_back(y);
					}
				}
			}
			++idx_frame;
			lp_frame = cvQueryFrame(m_capture);
		}

	}
	else
	{
		end_point_frame.clear();
		end_point_x.clear();
		end_point_y.clear();

		IplImage *pImg = m_image.GetImage();

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
	}
	outfile1.close();
	UpdateAllViews(NULL);
	AfxMessageBox("Finish Get End Point");
}

void CSkeletonDoc::OnMenuitemCompleteend() 
{
	// TODO: Add your command handler code here
	int val1 = 20;//搜索的长度
	int val2 = 2;//匹配的宽度
	int val3 = 3;//匹配的个数

	int idx_x[]={-1,0,1,1,1,0,-1,-1};
	int idx_y[]={-1,-1,-1,0,1,1,1,0};

	int i,j;
	int x,y;
	int xi,yi;
	int temp_x,temp_y;
	int idx;
	CvScalar scalar;
	CvScalar p1,p2;
	int count;

	ofstream outfile1("D://log/complete_end_result.txt");

	if(type_flag == 0)
	{
		IplImage *pImg = m_image.GetImage();
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
						outfile1<<"x="<<x<<",y="<<y<<",temp_x="<<temp_x<<",temp_y="<<temp_y<<endl;
						cvLine(pImg,cvPoint(x,y),cvPoint(temp_x,temp_y),CV_RGB(0,0,0));
					}
				}
			}

		}
		//cvNamedWindow("Complete Image(EndPoint)");
		//cvShowImage("Complete Image(EndPoint)",pImg);
		cvSaveImage("D://log/complete_end_image.bmp",pImg);
	}

	outfile1.close();
	UpdateAllViews(NULL);
	AfxMessageBox("Finish complete endpoint");

}

void CSkeletonDoc::OnMenuitemGetbrach() 
{

	// TODO: Add your command handler code here
	/*vector<int> v_x;
	vector<int> v_y;
	IplImage *mark_img;
	CvScalar scalar;
	CvScalar s1,s2;
	int adj[8];

	int i,j,x,y;
	int temp_x,temp_y;
	int xx,yy;

	int idx_x[]={-1,0,1,1,1,0,-1,-1};
	int idx_y[]={-1,-1,-1,0,1,1,1,0};

	ofstream outfile1("D://log/brach_point.txt");

	if(type_flag == 0)
	{
		IplImage *pImg = m_image.GetImage();
		int *mark_arr = new int[pImg->width * pImg->height];
		memset(mark_arr,0,sizeof(int) * pImg->width * pImg->height);

		//find all EndPoint
		for(x = 0; x < pImg->width; x++)
		{
			for(y = 0; y < pImg->height; y++)
			{
				scalar = cvGet2D(pImg,y,x);
				//outfile1<<"x="<<x<<",y="<<y<<",value="<<scalar.val[0]<<endl;
				if(scalar.val[0] == 0)
				{
					int count_adj = 0;
					for(i = 0; i < 8; ++i)
					{
						xx = x + idx_x[i];
						yy = y + idx_y[i];
						s1 = cvGet2D(pImg,y,x);
						if(s1.val[0] == 0) ++count_adj;
					}
					if(count_adj == 1)
					{
						v_x.push_back(x);
						v_y.push_back(y);
					}
				}
				
			}
		}

		delete []mark_arr;
	}

	outfile1.close();

	cvNamedWindow("Brach Image");
	cvShowImage("Brach Image",mark_img);

	//AfxMessageBox("Finish.");*/

	int idx_x[]={-1,0,1,1,1,0,-1,-1};
	int idx_y[]={-1,-1,-1,0,1,1,1,0};
	ofstream outfile1("D://log/brach_point.txt");

	int x,y,i,j;
	CvScalar scalar,s1;
	int temp_x,temp_y;

	if(type_flag == 0)
	{
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
	}
	
	outfile1.close();

	OnMenuitemGetendpoint();

}

void CSkeletonDoc::OnMenuitemCalbrachdata() 
{
	// TODO: Add your command handler code here
	int count_brach = 0;

	int x,y;
	int pre_x,pre_y;
	int temp_x,temp_y;
	int next_x,next_y;
	int count;
	int a_x,a_y;
	int b_x,b_y;
	CvScalar scalar,s1;
	int i,j;
	int pre_idx;
	int start_x,start_y;


	queue<int> q_x;
	queue<int> q_y;
	queue<int> q_pre_x;
	queue<int> q_pre_y;

	int idx_x[]={1,1,0,-1,-1,-1,0,1};
	int idx_y[]={0,-1,-1,-1,0,1,1,1};
	//int idx_x[] = {0,-1,1,0};
	//int idx_y[] = {-1,0,0,1};
	int num_idx = 8;

	int *adj = new int[num_idx];

	ofstream outfile1("D://log/show_brach_root.txt");

	if(type_flag == 0)
	{
		IplImage *pImg = m_image.GetImage();

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
						//outfile1<<"pre_x="<<x<<",pre_y="<<y<<",x="<<next_x<<",y="<<next_y<<endl;
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

			start_x = pre_x;
			start_y = pre_y;

			outfile1<<"("<<pre_x<<","<<pre_y<<") ";
			brach_length = 1;

			while(1)
			{	
				if(mark[x * pImg->width + y] == 0) mark[x * pImg->width + y] = 1;
				else break;

				outfile1<<"("<<x<<","<<y<<") ";
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
				else if(count > 1)
				{
					pre_idx = (pre_idx + num_idx/2) % num_idx;
					for(i = 0; i < num_idx/2; ++i)
					{
						if(adj[(pre_idx - i * 2 + num_idx) % num_idx] == 1)
						{
							next_x = x + idx_x[(pre_idx - i * 2 + num_idx) % num_idx];
							next_y = y + idx_y[(pre_idx - i * 2 + num_idx) % num_idx];
							adj[(pre_idx - i * 2 + num_idx) % num_idx] = -1;
							outfile1<<endl;
							break;
						}
						else if(adj[(pre_idx + i * 2) % num_idx] == 1)
						{
							next_x = x + idx_x[(pre_idx + i * 2) % num_idx];
							next_y = y + idx_y[(pre_idx + i * 2) % num_idx];
							adj[(pre_idx + i * 2) % num_idx] = -1;
							outfile1<<endl;
							break;
						}
					}


					for(i = 0; i < num_idx/2; ++i)
					{
						if(adj[i * 2] == 1)
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
					
					pre_x = x;
					pre_y = y;
					x = next_x;
					y = next_y;
				}
				/*count = 0;
				for(i = 0; i < num_idx; ++i)
				{
					temp_x = x + idx_x[i];
					temp_y = y + idx_y[i];

					if(temp_x < 0 || temp_x >= pImg->width || temp_y < 0 || temp_y >=pImg->height) continue;

					s1 = cvGet2D(pImg,temp_y,temp_x);
					if(s1.val[0] == 0)
					{
						++count;
					}
				}
				
				if(count == 2)
				{
					for(i = 0; i < num_idx; ++i)
					{
						temp_x = x + idx_x[i];
						temp_y = y + idx_y[i];
						
						if(temp_x < 0 || temp_x >= pImg->width || temp_y < 0 || temp_y >=pImg->height) continue;
						
						s1 = cvGet2D(pImg,temp_y,temp_x);
						if(s1.val[0] == 0)
						{
							if(pre_x != temp_x || pre_y != temp_y)
							{
								pre_x = x;
								pre_y = y;
								x = temp_x;
								y = temp_y;
								break;
							}
						}
					}
					++brach_length;
					
				}
				else if(count > 2)
				{
					for(i = 0; i < num_idx; ++i)
					{
						temp_x = x + idx_x[i];
						temp_y = y + idx_y[i];

						if(temp_x < 0 || temp_x >= pImg->width || temp_y < 0 || temp_y >=pImg->height) continue;

						s1 = cvGet2D(pImg,temp_y,temp_x);
						if(s1.val[0] == 0)
						{
							if(pre_x != temp_x || pre_y != temp_y)
							{
								q_x.push(temp_x);
								q_y.push(temp_y);
								q_pre_x.push(x);
								q_pre_y.push(y);
								outfile1<<"add pre("<<x<<","<<y<<"),("<<temp_x<<","<<temp_y<<")"<<endl;
							}
						}
					}

					++brach_length;
					break;
				}*/
				/*else if(count > 2)
				{
					a_x = - (pre_x - x);
					a_y = - (pre_y - y);
					double min = 2;

					for(i = 0; i < num_idx; ++i)
					{
						temp_x = x + idx_x[i];
						temp_y = y + idx_y[i];

						if(temp_x < 0 || temp_x >= pImg->width || temp_y < 0 || temp_y >=pImg->height) continue;
						
						s1 = cvGet2D(pImg,temp_y,temp_x);
						if(s1.val[0] == 0)
						{
							if(pre_x != temp_x || pre_y != temp_y)
							{
								b_x = temp_x - x;
								b_y = temp_y - y;
								double temp_cos = 1.0 * (a_x * b_x + a_y * b_y) / (sqrt(a_x * a_x + a_y * a_y) * sqrt(b_x * b_x + b_y * b_y));
								if(temp_cos < min) {min = temp_cos;next_x = temp_x; next_y = temp_y;}
							}
						}
					}

					for(i = 0; i < num_idx; ++i)
					{
						temp_x = x + idx_x[i];
						temp_y = y + idx_y[i];

						if(temp_x < 0 || temp_x >= pImg->width || temp_y < 0 || temp_y >=pImg->height) continue;
						
						s1 = cvGet2D(pImg,temp_y,temp_x);
						if(s1.val[0] == 0)
						{
							if(pre_x != temp_x || pre_y != temp_y)
							{
								if(next_x != temp_x || next_y != temp_y)
								{
									q_pre_x.push(x);
									q_pre_y.push(y);
									q_x.push(temp_x);
									q_y.push(temp_y);
								}
							}
						}
					}

					pre_x = x;
					pre_y = y;
					x = next_x;
					y = next_y;
					++brach_length;

				}*/
				else break;
			}
			outfile1<<endl;
			outfile1<<"brach_length="<<brach_length<<endl;
			outfile1<<endl;

			cvLine(show_image,cvPoint(start_x,start_y),cvPoint(x,y),CV_RGB(255,255,255));
		
		}

		cvNamedWindow("Brach Image");
		cvShowImage("Brach Image",show_image);
	}

	outfile1.close();
	UpdateAllViews(NULL);
	delete []adj;

	AfxMessageBox("Finish.");

}

void CSkeletonDoc::DrawLine(CvPoint p1,CvPoint p2)
{
	IplImage *pImg = m_image.GetImage();
	cvLine(pImg,p1,p2,CV_RGB(0,0,0));
	UpdateAllViews(NULL);
}

void CSkeletonDoc::OnMenuitemAll() 
{
	// TODO: Add your command handler code here
	OnMenuitemGetisolatepoint();
	OnMenuitemCompleteisolate();
	OnMenuitemGetendpoint();
	OnMenuitemCompleteend();

}

void CSkeletonDoc::OnMenuitemCompletemannal() 
{
	// TODO: Add your command handler code here
	m_bmannal = !m_bmannal;
}

void CSkeletonDoc::OnMenuitemSaveimage() 
{
	// TODO: Add your command handler code here
	IplImage *pImg = m_image.GetImage();
	cvSaveImage("D://log/save_image.bmp",pImg);
	AfxMessageBox("Finish Save Image.");
}

void CSkeletonDoc::OnMenuitemSoybeangetgrayimage() 
{
	// TODO: Add your command handler code here
	IplImage *pImg = m_image.GetImage();

	int channel = pImg->nChannels;
	char str[200];
	sprintf(str,"%d",channel);
	AfxMessageBox(str);

	/*gray_image = cvCreateImage(cvGetSize(pImg),IPL_DEPTH_8U,1);
	cvCvtColor(pImg,gray_image,CV_RGB2GRAY);

	if(gray_image->origin != pImg->origin)
	{
		gray_image->origin = pImg->origin;
	}

	//int x,y;
	//CvScalar scalar;
	//ofstream outfile1("D://log/gray_image_point.txt");
	//for(x = 0; x < gray_image->width; x++)
	//{
	//	for(y = 0; y < gray_image->height; y++)
	//	{
	//		scalar = cvGet2D(gray_image,y,x);
	//		outfile1<<"x="<<x<<",y="<<y<<",value="<<scalar.val[0]<<endl;
	//	}
	//}
	//outfile1.close();

	cvNamedWindow("Gray Image");
	cvShowImage("Gray Image",gray_image);*/

}
