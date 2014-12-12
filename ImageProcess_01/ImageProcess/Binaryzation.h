// Binaryzation.h: interface for the CBinaryzation class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BINARYZATION_H__A1BCF6EA_9934_4E7C_B328_373C169DDCBF__INCLUDED_)
#define AFX_BINARYZATION_H__A1BCF6EA_9934_4E7C_B328_373C169DDCBF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CBinaryzation  
{
public:
	static int OTSU(const BYTE *src, const int height, const int width);
	CBinaryzation();
	virtual ~CBinaryzation();

};

#endif // !defined(AFX_BINARYZATION_H__A1BCF6EA_9934_4E7C_B328_373C169DDCBF__INCLUDED_)
