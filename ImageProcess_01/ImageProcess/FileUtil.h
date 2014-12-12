// FileUtil.h: interface for the CFileUtil class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FILEUTIL_H__E8C35136_83E0_4D7D_88F8_27932D2CC361__INCLUDED_)
#define AFX_FILEUTIL_H__E8C35136_83E0_4D7D_88F8_27932D2CC361__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CFileUtil  
{
public:
	static bool CheckExtendName(const char *pszStr,const char *pszExd);
	CFileUtil();
	virtual ~CFileUtil();

};

#endif // !defined(AFX_FILEUTIL_H__E8C35136_83E0_4D7D_88F8_27932D2CC361__INCLUDED_)
