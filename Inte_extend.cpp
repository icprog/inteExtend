// Inte_extend.cpp: ����Ŀ�ļ���
#include "goujian.h"
#include "stdafx.h"
#include "intel_start.h"
#include "intel_main.h"
using namespace Inte_extend;
int FindProcess( char * pName)
		{
			int number = 0;
			PROCESSENTRY32 pe32;
			pe32.dwSize = sizeof(pe32); 
			HANDLE hProcessSnap = ::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
			BOOL bMore = ::Process32First(hProcessSnap, &pe32);

			while(bMore)
			{
				char exeFileName[260];
				WideCharToMultiByte( CP_ACP, 0, pe32.szExeFile, -1,  
					exeFileName, 256, NULL, NULL );   
				if(stricmp( pName ,exeFileName)==0)
				{
					number++;
				}
				bMore = ::Process32Next(hProcessSnap, &pe32);
			}
			return number;
		}
[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// �ڴ����κοؼ�֮ǰ���� Windows XP ���ӻ�Ч��

				
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 
	if( FindProcess ( "Inte_extend.exe") > 1)
		return 0;
	// ���������ڲ�������
	Application::Run(gcnew intel_main ());//intel_start
	return 0;
}
