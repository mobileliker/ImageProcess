// Canny.h: interface for the CCanny class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CANNY_H__DAEF7CF2_E126_4D13_A2C6_FD69C4F70208__INCLUDED_)
#define AFX_CANNY_H__DAEF7CF2_E126_4D13_A2C6_FD69C4F70208__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CCanny  
{
public:
	CCanny();
	virtual ~CCanny();

	void CreatGauss(double sigma, double **pdKernel, int *pnWidowSize);
	void GaussianSmooth(SIZE sz, LPBYTE pGray, LPBYTE pResult, double sigma);
	void Grad(SIZE sz, LPBYTE pGray, int *pGradX, int *pGradY, int *pMag);	
	void NonmaxSuppress(int *pMag, int *pGradX, int *pGradY, SIZE sz, LPBYTE pNSRst);	
	void EstimateThreshold(int *pMag, SIZE sz, int *pThrHigh, int *pThrLow, LPBYTE pGray,
          double dRatHigh, double dRatLow);
	void Hysteresis(int *pMag, SIZE sz, double dRatLow, double dRatHigh, LPBYTE pResult);
	void TraceEdge(int y, int x, int nThrLow, LPBYTE pResult, int *pMag, SIZE sz);
	void Canny(LPBYTE pGray, SIZE sz, double sigma, double dRatLow,
       double dRatHigh, LPBYTE pResult);

};

#endif // !defined(AFX_CANNY_H__DAEF7CF2_E126_4D13_A2C6_FD69C4F70208__INCLUDED_)
