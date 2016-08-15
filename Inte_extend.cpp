// Inte_extend.cpp: 主项目文件。
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
	// 在创建任何控件之前启用 Windows XP 可视化效果

				
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 
	if( FindProcess ( "Inte_extend.exe") > 1)
		return 0;
	// 创建主窗口并运行它
	Application::Run(gcnew intel_main ());//intel_start
	return 0;
}
