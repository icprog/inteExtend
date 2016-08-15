/*****************************************************************
 
	读取或者保存INI文件类
 
*****************************************************************/

#if !defined(AFX_INIFILE_H__33CAF5C6_7820_43EB_8D84_42CC1856C35C__INCLUDED_)
#define AFX_INIFILE_H__33CAF5C6_7820_43EB_8D84_42CC1856C35C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <afx.h>
class CIniFile  
{
public:
	void SetFileName(CString FileName);

	void WriteFileString(CString Section, CString Item, CString Value);
	CString GetFileString(CString Section, CString Item, CString Value);

	CString GetString(CString Section, CString Item, CString Value);
	int GetInt(CString Section, CString Item, int Value);
	float GetFloat(CString Section, CString Item, float Value);

	void SetString(CString Section, CString Item, CString Value);
	void SetInt(CString Section, CString Item, int Value);
	void SetFloat(CString Section, CString Item, float Value);

	BOOL WriteIniFile();
	BOOL ReadIniFile();

	CIniFile();
	virtual ~CIniFile();

	//ini file
	CString m_sFileName;
	CStdioFile IniFile;
	BOOL  m_bFileExist;
	CStringArray FileContainer;

};

#endif // !defined(AFX_INIFILE_H__33CAF5C6_7820_43EB_8D84_42CC1856C35C__INCLUDED_)
