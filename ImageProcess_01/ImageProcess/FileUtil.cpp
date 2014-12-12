// FileUtil.cpp: implementation of the CFileUtil class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ImageProcess.h"
#include "FileUtil.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CFileUtil::CFileUtil()
{

}

CFileUtil::~CFileUtil()
{

}


bool CFileUtil::CheckExtendName(const char *pszStr, const char *pszExd)
{
	char *pt=(char*)pszStr;

	pt +=strlen(pszStr);
	while(pt!=(char*)pszStr && *pt-- !='.');
	
	if(*(++pt) !='.') return false;
	pt++;
	
	//���Ƚ��ַ��ʹ���ĺ�׺��תΪСд
	if(strcmp(_strlwr(pt),_strlwr((char *)pszExd))==0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
