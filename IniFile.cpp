
#include "stdafx.h"
#include "IniFile.h"
#include "locale.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

#pragma warning(disable:4244)
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CIniFile::CIniFile()
{
	m_sFileName = "jcParameter";
}

CIniFile::~CIniFile()
{
	if(FileContainer.GetSize() > 0)
	{
		FileContainer.RemoveAll();
	}
}

void CIniFile::SetFileName(CString FileName)
{
	m_sFileName = FileName;
}

void CIniFile::SetInt(CString Section, CString Item, int Value)
{
	CString strtemp;
	strtemp.Format(_T("%d"),Value);
	//���浽FileContainer
	WriteFileString(Section, Item, strtemp);
	//���浽ini�ļ�
	WriteIniFile();
}

void CIniFile::SetString(CString Section, CString Item, CString Value)
{
	//���浽FileContainer
	WriteFileString(Section, Item, Value);
	//���浽ini�ļ�
	WriteIniFile();
}

void CIniFile::SetFloat(CString Section, CString Item, float Value)
{
	CString strtemp;
	strtemp.Format(_T("%e"),Value);
	//���浽FileContainer
	WriteFileString(Section, Item, strtemp);
	//���浽ini�ļ�
	WriteIniFile();
}

CString CIniFile::GetString(CString Section, CString Item, CString Value)
{
	return GetFileString(Section, Item, Value);
}

int CIniFile::GetInt(CString Section, CString Item, int Value)
{
	int nValve;
	CString strtemp;
	strtemp.Format(_T("%d"),Value);
	strtemp = GetFileString(Section, Item, strtemp);
	return _ttoi(strtemp);
}

float CIniFile::GetFloat(CString Section, CString Item, float Value)
{
	CString strtemp;
	strtemp.Format(_T("%f"),Value);
	strtemp = GetFileString(Section, Item, strtemp);
	return  _ttof(strtemp);
}

BOOL CIniFile::ReadIniFile()
{
	m_bFileExist = IniFile.Open(m_sFileName, CFile::modeRead);

	TCHAR* old_locale = _tcsdup( _tsetlocale(LC_CTYPE,NULL) );  
	_tsetlocale( LC_CTYPE, _T("chs")); 

	if(!m_bFileExist)
	{
		return FALSE;
	}

	CString strline;
	FileContainer.RemoveAll();

	//��IniFile�ļ����ݶ���FileContainer
	while(IniFile.ReadString(strline))
	{
		FileContainer.Add(strline);
	}

	IniFile.Close();
	_tsetlocale( LC_CTYPE, old_locale );  
	free( old_locale );  
	return TRUE;
}

BOOL CIniFile::WriteIniFile()
{
	m_bFileExist = IniFile.Open(m_sFileName, CFile::modeCreate| CFile::modeWrite);
	if(!m_bFileExist)
		return FALSE;
	
	CString strline;

	TCHAR* old_locale = _tcsdup( _tsetlocale(LC_CTYPE,NULL) );  
	_tsetlocale( LC_CTYPE, _T("chs")); 

	//��FileContainerд��IniFile�ļ�
	for(int i = 0; i< FileContainer.GetSize(); i++)
	{
		strline = FileContainer[i];
		IniFile.WriteString(strline+_T("\n"));
	}

	IniFile.Close();

	_tsetlocale( LC_CTYPE, old_locale );  
	free( old_locale );  

	return m_bFileExist;
}

CString CIniFile::GetFileString(CString Section, CString Item, CString Value)
{
	ReadIniFile();//���ļ�

	if(m_bFileExist == FALSE || FileContainer.GetSize() < 0)
		return Value;//�ļ��򿪳�����ļ�Ϊ�գ�����Ĭ��ֵ

	int i = 0;
	int iFileLines = FileContainer.GetSize();
	CString strline,str;

	while(i<iFileLines)
	{
		strline = FileContainer.GetAt(i++);

		strline.TrimLeft();
		if(strline.GetAt(0)=='[')//����Section����һ������Ϊ[
		{
			str=strline.Left(strline.Find(_T("]")));//ȥ��]�ұ�
			str=str.Right(str.GetLength()-str.Find(_T("["))-1);//ȥ��[���

			str.TrimLeft();
			str.TrimRight();

			if(Section == str)//�ҵ�Section
			{
				while(i<iFileLines)
				{
					strline = FileContainer.GetAt(i++);
					strline.TrimLeft();

					if(strline.GetAt(0)=='[')
						return Value;//���������һ��[]�����Ҳ���,����Ĭ��ֵ
					
					str = strline.Left(strline.Find(_T("=")));//ȥ��=�ұ�

					str.TrimLeft();
					str.TrimRight();

					if(Item == str)//�ҵ�Item
					{
						str=strline.Right(strline.GetLength()-strline.Find(_T("="))-1);//ȥ��=���

						str.TrimLeft();
						str.TrimRight();

						return str;
					}
				}
				return Value;//�Ҳ���,����Ĭ��ֵ
			}

		}

	}
	return Value;//�Ҳ���,����Ĭ��ֵ
}

void CIniFile::WriteFileString(CString Section, CString Item, CString Value)
{
	int i = 0;
	int iFileLines = FileContainer.GetSize();
	CString strline,str;

	while(i<iFileLines)
	{
		strline = FileContainer.GetAt(i++);

		strline.TrimLeft();
		if(strline.GetAt(0)=='[')//����Section����һ������Ϊ[
		{
			str=strline.Left(strline.Find(_T("]")));//ȥ��]�ұ�
			str=str.Right(str.GetLength()-str.Find(_T("["))-1);//ȥ��[���

			str.TrimLeft();
			str.TrimRight();

			if(Section == str)//�ҵ�Section
			{
				while(i<iFileLines)
				{
					strline = FileContainer.GetAt(i++);
					strline.TrimLeft();

					if(strline.GetAt(0)=='[')//���������һ��[]�����Ҳ���Item
					{
						break;
					}
					
					str = strline.Left(strline.Find(_T("=")));//ȥ��=�ұ�

					str.TrimLeft();
					str.TrimRight();

					if(Item == str)//�ҵ�Item
					{
						strline = Item + _T("=") + Value;
						FileContainer[i-1] = strline;
						return;
					}
				}
				//�Ҳ���Item
				strline = Item + _T("=") + Value;
				FileContainer.InsertAt(i-1, strline);
				return;

			}

		}

	}
	//�Ҳ���Section
	//ֱ����������Section��Item��Value
	FileContainer.Add(_T("[") + Section + _T("]"));
	FileContainer.Add(Item + _T("=") + Value);
	return;
}

