#pragma once
#include "public.h"

#include <windows.h>  
#include "psapi.h"  
#include"stdio.h"
#include<conio.h> 
#include<process.h>
#include<winbase.h>

#include <PROCESS.H>

#define grp2Num 3
namespace Inte_extend {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace System::Runtime::InteropServices;
	using namespace System::Threading;

	using namespace OPC::Common;
	using namespace OPC::Data::Interface;
	using namespace OPC::Data;
	/// <summary>
	/// combase ժҪ
	/// </summary>
	public ref class combase : public System::Windows::Forms::Form
	{
	public:
		combase(void)
		{
			debugNotice = 0;
			InitializeComponent();
			//
			//TODO: �ڴ˴���ӹ��캯������
			//
		}
	public:	static HANDLE semaphore; 
	public:	static HANDLE semaphoreComp; 
	public: static int gRInit;
	public: static int gOpcOperation;
	public: static int gOpcDataId;
	public : static int exitPro;
	
	public:	static System::Int32 debugNotice;
	public:	static System::Int32  zhangLaCount, bDataInit, bConnectServer;
	public:	static System::String^ ipAdd = "";
	public:	static System::String^ ipAdd2 = "";
	public: static	array<float>^ huiGuiXiShu = gcnew array<float>(8);//4��������,Ŀǰ֧��2��������
	public:  static	array<System::String^>^ str_holeInfo = gcnew array<System::String^>(holeInfoNum); //�����������������������������쳤��
	public:  static	array<System::String^>^ str_LiangInfo = gcnew array<System::String^>(3); //���ţ������ٶȣ���Ӧ����
	public:  static	array<System::String^>^ str_ShunXunInfo = gcnew array<System::String^>(zhangLaSeqNum); 
			 static	 OpcServer ^		TheSrv = nullptr;
			 static	 OpcGroup^			TheGrp= nullptr;
	public:			 static array<OPCItemDef ^>^ ItemDefs = gcnew array<OPCItemDef^>(itemNum); 
	public:			 static array<OPCItemResult ^>^ rItm = gcnew array<OPCItemResult^>(itemNum); 
	public:		 	static array<OPCItemState ^>^ opcReadData = gcnew array<OPCItemState^>(itemNum); 
	public:			 static array<Object ^>^ opcWriteData = gcnew array<Object^>(itemNum);
	public:			 static array<Int32 ,1>^ arrErr = gcnew array<Int32>(itemNum);
	public:			 static array<Int32 ,1>^ HandlesSrv = gcnew array<Int32>(itemNum);

	static	OpcGroup^		   TheGrpParameter= nullptr;
	public:			 static array<OPCItemDef ^>^ ItemDefsParameter = gcnew array<OPCItemDef^>(ParameterNum); 
	public:			 static array<OPCItemResult ^>^ rItmParameter = gcnew array<OPCItemResult^>(ParameterNum); 
	public:		 	static array<OPCItemState ^>^ opcReadDataParameter = gcnew array<OPCItemState^>(ParameterNum); 
	public:			 static array<Object ^>^ opcWriteDataParameter = gcnew array<Object^>(ParameterNum);
	public:			 static array<Int32 ,1>^ arrErrParameter = gcnew array<Int32>(ParameterNum);
	public:			 static array<Int32 ,1>^ HandlesSrvParameter= gcnew array<Int32>(ParameterNum);


		static	OpcGroup^		   TheGrpParameter2= nullptr;
	public:			 static array<OPCItemDef ^>^ ItemDefsParameter2 = gcnew array<OPCItemDef^>(ParameterNum); 
	public:			 static array<OPCItemResult ^>^ rItmParameter2 = gcnew array<OPCItemResult^>(ParameterNum); 
	public:		 	static array<OPCItemState ^>^ opcReadDataParameter2 = gcnew array<OPCItemState^>(ParameterNum); 
	public:			 static array<Object ^>^ opcWriteDataParameter2 = gcnew array<Object^>(ParameterNum);
	public:			 static array<Int32 ,1>^ arrErrParameter2 = gcnew array<Int32>(ParameterNum);
	public:			 static array<Int32 ,1>^ HandlesSrvParameter2 = gcnew array<Int32>(ParameterNum);

	static	OpcGroup^		   TheGrpRandom = nullptr;
	public:			 static array<OPCItemDef ^>^ ItemDefsRandom = gcnew array<OPCItemDef^>( 2 ); 
	public:			 static array<OPCItemResult ^>^ rItmRandom = gcnew array<OPCItemResult^>( 2 ); 
	public:			 static array<Object ^>^ opcWriteDataRandom = gcnew array<Object^>( 2 );
	public:			 static array<Int32 ,1>^ arrErrRandom = gcnew array<Int32>( 2 );
	public:			 static array<Int32 ,1>^ HandlesSrvRandom = gcnew array<Int32>( 2 );

	/*
		static		array<System::String ^> ^ ItemAParameter = { 
								 ":1000:0301,V3.4,BOOL,RW" ,//�����ǿ�ʼ����  39
								 ":1000:0301,vd340,REAL,RW",//������ʼƵ��	0
								 ":1000:0301,vd352,REAL,RW",//�����˶�Ƶ��
								 ":1000:0301,vd356,REAL,RW",//�ֶ�����Ƶ��
								 ":1000:0301,vd348,REAL,RW",//�ӽ�Ŀ��Ƶ��	
								 ":1000:0301,vd344,REAL,RW",//��ѹ����Ƶ��	 4
								 ":1000:0301,vd360,REAL,RW",//��Ƶ��ѹ����
								 ":1000:0301,vd300,REAL,RW",//�ع鷽��aϵ��
								 ":1000:0301,vd304,REAL,RW",//�ع鷽��bϵ��  7
		
		
								 ":1000:0301,V0.0,BOOL,RW" ,//�ֶ������ͷ�ʽ 8
								 ":1000:0301,V0.2,BOOL,RW" ,//�ֶ�����ָ��	
								 ":1000:0301,V0.1,BOOL,RW" ,//�ֶ�����ָ��	10
		
								 ":1000:0301,vd312,REAL,RW",//������1�г̿�����    11
								 ":1000:0301,vd316,REAL,RW",//������2�г̿�����
								 ":1000:0301,vd320,REAL,RW",//������3�г̿�����
								 ":1000:0301,VD42,REAL,RW", //���������ٶ�		  14
								 
								 ":1000:0301,v1.0,BOOL,RW",//PLC����λ��ͨ������	15
								 ":1000:0301,vw48,INT,RW",//��λ��ͨ�ŷ��͵������	16
		
							 };
	
		static		array<System::String ^> ^ ItemA = { 
							 ":1000:0301,v0.7,BOOL,R",//PLC����λ��ͨ��ok 
	
							 ":1000:0301,VW70,INT,R" ,	//��ѹ�ϸ�ʱ��		  1
							 ":1000:0301,VD34,REAL,R" ,//��λ��������ֵ��ʾ
							 ":1000:0301,VD38,REAL,R" ,//��λ����ѹĿ��ֵ��ʾ
							 ":1000:0301,VD14,REAL,R" ,//λ����������
							 ":1000:0301,VD10,REAL,R" ,//��ѹ��������
	
							 ":1000:0301,V4.0,BOOL,R" ,//�����ǵ�1�г̽���	6
							 ":1000:0301,V3.0,BOOL,R" ,//�����ǵ�1�г̽��� 
	
							 ":1000:0301,V4.1,BOOL,R" ,//�����ǵ�2�г̽���
							 ":1000:0301,V3.1,BOOL,R" ,//�����ǵ�2�г̽���
	
							 ":1000:0301,V4.2,BOOL,R" ,//�����ǵ�3�г̽��� 10
							 ":1000:0301,V3.2,BOOL,R" ,//�����ǵ�3�г̽���
							 ":1000:0301,V3.3,BOOL,R" ,//�����ǽ��뱣ѹ 	
	
							 ":1000:0301,V3.5,BOOL,R", //�����Ǳ�ѹ���   13
	
							 ":1000:0301,vd340,REAL,RW",//������ʼƵ��	14
							 ":1000:0301,vd352,REAL,RW",//�����˶�Ƶ��
							 ":1000:0301,vd356,REAL,RW",//�ֶ�����Ƶ��
							 ":1000:0301,vd348,REAL,RW",//�ӽ�Ŀ��Ƶ��	
							 ":1000:0301,vd344,REAL,RW",//��ѹ����Ƶ��	 18
							 ":1000:0301,vd360,REAL,RW",//��Ƶ��ѹ����
							 ":1000:0301,vd300,REAL,RW",//�ع鷽��aϵ��
							 ":1000:0301,vd304,REAL,RW",//�ع鷽��bϵ��  21
	
	
							 ":1000:0301,V0.0,BOOL,RW" ,//�ֶ������ͷ�ʽ 22
							 ":1000:0301,V0.2,BOOL,RW" ,//�ֶ�����ָ��	
							 ":1000:0301,V0.1,BOOL,RW" ,//�ֶ�����ָ��	24
	
	
							 ":1000:0301,v1.0,BOOL,RW",//PLC����λ��ͨ������	25
							 ":1000:0301,vw48,INT,RW",//��λ��ͨ�ŷ��͵������									
							 ":1000:0301,vd312,REAL,RW",//������1�г̿�����    
							 ":1000:0301,vd316,REAL,RW",//������2�г̿�����
							 ":1000:0301,vd320,REAL,RW",//������3�г̿�����
							 ":1000:0301,V3.6,BOOL,RW" ,//������״̬��λ  39  30
							 ":1000:0301,VD42,REAL,RW", //���������ٶ�		  31
							 
							 ":1000:0301,V0.5,BOOL,R" ,//ѹ���������쳣   32
							 ":1000:0301,V0.6,BOOL,R" ,//λ�ƴ������쳣
							 ":1000:0301,T53,BOOL,R" ,//���ӻ�λ�Ʋ�ֵ����	34
							 
							 ":1000:0301,VD74,REAL,RW" ,//�����쳤��  35
							 ":1000:0301,I0.0,BOOL,R" ,//ϵͳ��ͣ	36
							  ":1000:0301,V0.3,BOOL,R" ,//�Զ�����ָ��	37
							 ":1000:0301,V0.4,BOOL,R" ,//�Զ�����ָ��  ,picturebox	38
							 
							 ":1000:0301,V3.4,BOOL,RW" ,//�����ǿ�ʼ����  39
							
						 };
		
	
		*/
		

	static		array<System::String ^> ^ ItemAParameter = { 
							 ":0201:0201,V3.4,BOOL,RW" ,//�����ǿ�ʼ����  0
							 ":0201:0201,V2.1,BOOL,RW",//���������ź�
							 ":0201:0201,vd340,REAL,RW",//������ʼƵ��	1
							 ":0201:0201,vd352,REAL,RW",//�����˶�Ƶ��
							 ":0201:0201,vd356,REAL,RW",//�ֶ�����Ƶ��
							 ":0201:0201,vd348,REAL,RW",//�ӽ�Ŀ��Ƶ��	
							 ":0201:0201,vd344,REAL,RW",//��ѹ����Ƶ��	 5
							 ":0201:0201,vd360,REAL,RW",//��Ƶ��ѹ����
							 ":0201:0201,vd300,REAL,RW",//�ع鷽��aϵ��
							 ":0201:0201,vd304,REAL,RW",//�ع鷽��bϵ��  8
	
	
							 ":0201:0201,V0.0,BOOL,RW" ,//�ֶ������ͷ�ʽ 9
							 ":0201:0201,V0.2,BOOL,RW" ,//�ֶ�����ָ��	
							 ":0201:0201,V0.1,BOOL,RW" ,//�ֶ�����ָ��	11
	
							 ":0201:0201,vd312,REAL,RW",//������1�г̿�����    12
							 ":0201:0201,vd316,REAL,RW",//������2�г̿�����
							 ":0201:0201,vd320,REAL,RW",//������3�г̿�����
							 ":0201:0201,VD42,REAL,RW", //���������ٶ�		  15
							 
							 ":0201:0201,v1.0,BOOL,RW",//PLC����λ��ͨ������	16
							 ":0201:0201,vw48,INT,RW",//��λ��ͨ�ŷ��͵������	17
						 };
	
		static		array<System::String ^> ^ ItemBParameter = { 
							 ":0201:0201,V1100.4,BOOL,RW" ,//�����ǿ�ʼ����  39
							  ":0201:0201,vd1131,REAL,RW",//������ʼƵ��  14
							 ":0201:0201,vd1151,REAL,RW",//�����˶�Ƶ��
							 ":0201:0201,vd1127,REAL,RW",//�ֶ�����Ƶ��
							 
							 ":0201:0201,vd1119,REAL,RW",//�ӽ�Ŀ��Ƶ��  
							 
							 ":0201:0201,vd1103, REAL,RW",//��ѹ����Ƶ��   18
							 ":0201:0201,vd1107, REAL,RW",//��Ƶ��ѹ����
							 
							 ":0201:0201,vd1111,REAL,RW",//�ع鷽��aϵ��
							 ":0201:0201,vd1115,REAL,RW",//�ع鷽��bϵ��  21

							  ":0201:0201,V1100.2,BOOL,RW" ,//�ֶ������ͷ�ʽ 22
							 ":0201:0201,V1100.1,BOOL,RW" ,//�ֶ�����ָ��  
							 ":0201:0201,V1100.3,BOOL,RW" ,//�ֶ�����ָ��  24

							 ":0201:0201,vd1135,REAL,RW",//������1�г̿����� 						 
							 ":0201:0201,vd1139,REAL,RW",//������2�г̿�����						 
							 ":0201:0201,vd1143,REAL,RW",//������3�г̿�����
							 
							 ":0201:0201,v1100.0,BOOL,RW",//PLC����λ��ͨ������    25
							 
							 ":0201:0201,vw1101,INT,RW",//��λ��ͨ�ŷ��͵������	
	
						 };

	static		array<System::String ^> ^ ItemA = { 
						 ":0201:0201,v0.7,BOOL,R",//PLC����λ��ͨ��ok 

						 ":0201:0201,VW70,INT,R" ,  //��ѹ�ϸ�ʱ��        1
						 ":0201:0201,VD34,REAL,R" ,//��λ��������ֵ��ʾ
						 ":0201:0201,VD38,REAL,R" ,//��λ����ѹĿ��ֵ��ʾ
						 ":0201:0201,VD14,REAL,R" ,//λ����������
						 ":0201:0201,VD10,REAL,R" ,//��ѹ��������

						 ":0201:0201,V4.0,BOOL,R" ,//�����ǵ�1�г̽���  6
						 ":0201:0201,V3.0,BOOL,R" ,//�����ǵ�1�г̽��� 

						 ":0201:0201,V4.1,BOOL,R" ,//�����ǵ�2�г̽���
						 ":0201:0201,V3.1,BOOL,R" ,//�����ǵ�2�г̽���

						 ":0201:0201,V4.2,BOOL,R" ,//�����ǵ�3�г̽��� 10
						 ":0201:0201,V3.2,BOOL,R" ,//�����ǵ�3�г̽���
						 ":0201:0201,V3.3,BOOL,R" ,//�����ǽ��뱣ѹ     

						 ":0201:0201,V3.5,BOOL,R", //�����Ǳ�ѹ���   13

						 ":0201:0201,vd340,REAL,RW",//������ʼƵ��  14
						 ":0201:0201,vd352,REAL,RW",//�����˶�Ƶ��
						 ":0201:0201,vd356,REAL,RW",//�ֶ�����Ƶ��
						 ":0201:0201,vd348,REAL,RW",//�ӽ�Ŀ��Ƶ��  
						 ":0201:0201,vd344,REAL,RW",//��ѹ����Ƶ��   18
						 ":0201:0201,vd360,REAL,RW",//��Ƶ��ѹ����
						 ":0201:0201,vd300,REAL,RW",//�ع鷽��aϵ��
						 ":0201:0201,vd304,REAL,RW",//�ع鷽��bϵ��  21


						 ":0201:0201,V0.0,BOOL,RW" ,//�ֶ������ͷ�ʽ 22
						 ":0201:0201,V0.2,BOOL,RW" ,//�ֶ�����ָ��  
						 ":0201:0201,V0.1,BOOL,RW" ,//�ֶ�����ָ��  24


						 ":0201:0201,v1.0,BOOL,RW",//PLC����λ��ͨ������    25
						 ":0201:0201,vw48,INT,RW",//��λ��ͨ�ŷ��͵������									
						 ":0201:0201,vd312,REAL,RW",//������1�г̿�����    
						 ":0201:0201,vd316,REAL,RW",//������2�г̿�����
						 ":0201:0201,vd320,REAL,RW",//������3�г̿�����
						 ":0201:0201,V3.6,BOOL,RW" ,//������״̬��λ    30
						 ":0201:0201,VD42,REAL,RW", //���������ٶ�        31
						 
						 ":0201:0201,V0.5,BOOL,R" ,//ѹ���������쳣   32
						 ":0201:0201,V0.6,BOOL,R" ,//λ�ƴ������쳣
						 ":0201:0201,v1.6,BOOL,R" ,//���ӻ�λ�Ʋ�ֵ����  34
						 
						 ":0201:0201,VD74,REAL,RW" ,//�����쳤��  35
						 ":0201:0201,I0.0,BOOL,R" ,//ϵͳ��ͣ   36
						  ":0201:0201,V0.3,BOOL,R" ,//�Զ�����ָ��  37
						 ":0201:0201,V0.4,BOOL,R" ,//�Զ�����ָ��  ,picturebox  38
						 ":0201:0201,V3.4,BOOL,RW" ,//�����ǿ�ʼ����  39

//�ӻ�
						 ":0201:0201,v1000.0,BOOL,R",//PLC����λ��ͨ��ok 
						 ":0201:0201,VW1003,INT,R" ,  //��ѹ�ϸ�ʱ��        1
						 ":0201:0201,VD1005,REAL,R" ,//��λ��������ֵ��ʾ
						 ":0201:0201,VD1009,REAL,R" ,//��λ����ѹĿ��ֵ��ʾ
						 ":0201:0201,VD1013,REAL,R" ,//λ����������
						 
						 ":0201:0201,VD1017,REAL,R" ,//��ѹ��������
						 ":0201:0201,V1000.6,BOOL,R" ,//�����ǵ�1�г̽���  6
						 ":0201:0201,V1000.7,BOOL,R" ,//�����ǵ�1�г̽��� 
						 ":0201:0201,V1001.0,BOOL,R" ,//�����ǵ�2�г̽���
						 ":0201:0201,V1001.1,BOOL,R" ,//�����ǵ�2�г̽���

						 ":0201:0201,V1001.2,BOOL,R" ,//�����ǵ�3�г̽��� 10
						 ":0201:0201,V1001.3,BOOL,R" ,//�����ǵ�3�г̽���
						 ":0201:0201,V1001.4,BOOL,R" ,//�����ǽ��뱣ѹ     
						 ":0201:0201,V1000.5,BOOL,R", //�����Ǳ�ѹ���   13
						 ":0201:0201,vd1131,REAL,RW",//������ʼƵ��  14
						 
						 ":0201:0201,vd1151,REAL,RW",//�����˶�Ƶ��
						 ":0201:0201,vd1127,REAL,RW",//�ֶ�����Ƶ��
						 ":0201:0201,vd1119,REAL,RW",//�ӽ�Ŀ��Ƶ��  
						 ":0201:0201,vd1103, REAL,RW",//��ѹ����Ƶ��   18
						 ":0201:0201,vd1107, REAL,RW",//��Ƶ��ѹ����
						 
						 ":0201:0201,vd1111,REAL,RW",//�ع鷽��aϵ��
						 ":0201:0201,vd1115,REAL,RW",//�ع鷽��bϵ��  21
						 
						 ":0201:0201,V1100.2,BOOL,RW" ,//�ֶ������ͷ�ʽ 22
						 ":0201:0201,V1100.1,BOOL,RW" ,//�ֶ�����ָ��  
						 ":0201:0201,V1100.3,BOOL,RW" ,//�ֶ�����ָ��  24
						 
						 ":0201:0201,v1100.0,BOOL,RW",//PLC����λ��ͨ������    25
						 ":0201:0201,vw1101,INT,RW",//��λ��ͨ�ŷ��͵������	
						 ":0201:0201,vd1135,REAL,RW",//������1�г̿����� 						 
						 ":0201:0201,vd1139,REAL,RW",//������2�г̿�����						 
						 ":0201:0201,vd1143,REAL,RW",//������3�г̿�����
						 
						 ":0201:0201,V1100.5,BOOL,RW" ,//������״̬��λ  39  30
						 ":0201:0201,VD1147,REAL,RW", //���������ٶ�        31
						 ":0201:0201,V1000.4,BOOL,R" ,//ѹ���������쳣   32
						 ":0201:0201,V1000.2,BOOL,R" ,//λ�ƴ������쳣
						 ":0201:0201,T52,BOOL,R" ,//���ӻ�λ�Ʋ�ֵ����  34
						 
						 ":0201:0201,VD1123,REAL,RW" ,//�����쳤��  35
						 ":0201:0201,V1000.3,BOOL,R" ,//ϵͳ��ͣ   36
						  ":0201:0201,V1001.6,BOOL,R" ,//�Զ�����ָ��  37
						 ":0201:0201,V1001.5,BOOL,R" ,//�Զ�����ָ��  ,picturebox  38
						 ":0201:0201,V1100.4,BOOL,RW" ,//�����ǿ�ʼ����  39
						
					 };
					 
					 
	protected:
		/// <summary>
		/// ������������ʹ�õ���Դ��
		/// </summary>
		~combase()
		{
			commRemoveItem();
			try{
				if(  TheGrp )
					TheGrp->Remove(false);
			}
			catch(Exception ^ ex) {
				MessageBox::Show(ex->ToString(),"�Ͽ�����ʧ��", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
			}

			TheGrp = nullptr;
			try{
				if( TheSrv != nullptr )
					TheSrv->Disconnect();
			}
			catch(Exception ^ ex) {
				MessageBox::Show(ex->ToString(),"�Ͽ�����ʧ��", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
			}
			
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// ����������������
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����֧������ķ��� - ��Ҫ
		/// ʹ�ô���༭���޸Ĵ˷��������ݡ�
		/// </summary>
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// combase
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(292, 262);
			this->Name = L"combase";
			this->Text = L"combase";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &combase::combase_FormClosing);
			this->Load += gcnew System::EventHandler(this, &combase::combase_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
		public: System::String ^	 GetQualityText( short  Quality  ) {
					System::String ^ retrunStr;
					switch( Quality ) {
					case 0 : retrunStr = "BAD";
						break;
					case 64 : retrunStr = "UNCERTAIN";
						break;
					case 192 : retrunStr = "GOOD";
						break;
					case 8 : retrunStr = "NOT_CONNECTED";
						break;
					case 13 : retrunStr = "DEVICE_FAILURE";
						break;
					case 16 : retrunStr = "SENSOR_FAILURE";
						break;
					case 20 : retrunStr = "LAST_KNOWN";
						break;
					case 24 : retrunStr = "COMM_FAILURE";
						break;
					case 28 : retrunStr = "OUT_OF_SERVICE";
						break;
					case 132 : retrunStr = "LAST_USABLE";
						break;
					case 144 : retrunStr = "SENSOR_CAL";
						break;
					case 148 : retrunStr = "EGU_EXCEEDED";
						break;
					case 152 : retrunStr = "SUB_NORMAL";
						break;
					case 216 : retrunStr = "LOCAL_OVERRIDE";
						break;
					default : retrunStr = "UNKNOWN QUALITY";
						break;
					}
					return retrunStr;
				}
//�ӻ��Ƴ���Ŀ
public: System::Void commRemoveItem(){
	
#ifdef debug_noMachine
					return ;
			#endif
			if(ItemDefs &&  ( ItemDefs[0] || ItemDefs[1] ) ){
				if( TheGrp )
					TheGrp->RemoveItems(HandlesSrv, arrErr);
			}
			for(int i = 0; i < itemNum; i++) {
				if( ItemDefs )
					ItemDefs[i] = nullptr;
				HandlesSrv[i] = 0;
			}

			if(ItemDefsParameter &&  ( ItemDefsParameter[0] ) ){
				if( TheGrpParameter )
					TheGrpParameter->RemoveItems(HandlesSrvParameter, arrErrParameter);
			}
			for(int i = 0; i < ParameterNum; i++) {
				if( ItemDefsParameter )
					ItemDefsParameter[i] = nullptr;
				HandlesSrvParameter[i] = 0;
			}

			if(ItemDefsParameter2 &&  ( ItemDefsParameter2[0]  ) ){
				if( TheGrpParameter2 )
					TheGrpParameter2->RemoveItems(HandlesSrvParameter2, arrErrParameter2);
			}
			for(int i = 0; i < ParameterNum; i++) {
				if( ItemDefsParameter2 )
					ItemDefsParameter2[i] = nullptr;
				HandlesSrvParameter2[i] = 0;
			}

			if(ItemDefsRandom &&  ( ItemDefsRandom[0]  ) ){
				if( TheGrpRandom )
					TheGrpRandom->RemoveItems(HandlesSrvRandom, arrErrRandom);
			}
			for(int i = 0; i < 2; i++) {
				if( ItemDefsRandom )
					ItemDefsRandom[i] = nullptr;
				HandlesSrvRandom[i] = 0;
			}

		}
//�ӻ����XXX
public: System::Int32 commAddtem( int num){
	
#ifdef debug_noMachine
					return 0;
			#endif
			static bool warning = false;
			int haveErr = 0;
			if( bConnectServer == 0)
				return 1;
			int i = 0;
			try
			{
				if(TheSrv && TheGrp ) {
					TheGrp->AddItems(ItemDefs, rItm);
					int haveErr = 0;
					for( i = 0; i < num; i++) {
						if(( rItm != nullptr) && (rItm[i]->Error) ) {
							haveErr = 1;
							HandlesSrv[i] = 0;
						}
						else 
							HandlesSrv[i] = rItm[i]->HandleServer;
					}
				}
			}
			catch(Exception ^ ex) {
				if( warning == false)
		//		MessageBox::Show(ex->Message,"AddItems");
				warning = true;

			}
			
			try
			{
				if(TheSrv && TheGrpParameter ) {
					TheGrpParameter->AddItems(ItemDefsParameter, rItmParameter);
					int haveErr = 0;
					for( i = 0; i < ParameterNum; i++) {
						if(( rItmParameter != nullptr) && (rItmParameter[i]->Error) ) {
							haveErr = 1;
							HandlesSrvParameter[i] = 0;
						}
						else 
							HandlesSrvParameter[i] = rItmParameter[i]->HandleServer;
					}
				}
			}
			catch(Exception ^ ex) {
				if( warning == false)
			//	MessageBox::Show(ex->Message,"AddItems");
				warning = true;

			}	

			try
			{
				if(TheSrv && TheGrpParameter2 ) {
					TheGrpParameter2->AddItems(ItemDefsParameter2, rItmParameter2);
					int haveErr = 0;
					for( i = 0; i < ParameterNum; i++) {
						if(( rItmParameter2 != nullptr) && (rItmParameter2[i]->Error) ) {
							haveErr = 1;
							HandlesSrvParameter2[i] = 0;
						}
						else 
							HandlesSrvParameter2[i] = rItmParameter2[i]->HandleServer;
					}
				}
			}
			catch(Exception ^ ex) {
				if( warning == false)
			//	MessageBox::Show(ex->Message,"AddItems");
				warning = true;

			}	

			try
			{
				if(TheSrv && TheGrpRandom ) {
					TheGrpRandom->AddItems(ItemDefsRandom, rItmRandom );
					int haveErr = 0;
					for( i = 0; i < 2; i++) {
						if(( rItmRandom != nullptr) && (rItmRandom[i]->Error) ) {
							haveErr = 1;
							HandlesSrvRandom[i] = 0;
						}
						else 
							HandlesSrvRandom[i] = rItmRandom[i]->HandleServer;
					}
				}
			}
			catch(Exception ^ ex) {
				if( warning == false)
			//	MessageBox::Show(ex->Message,"AddItems");
				warning = true;

			}	
			
			return haveErr;

		}
//�ӻ�������
public: System::Int32 commSynRead( int len){
	
#ifdef debug_noMachine
					return 0;
			#endif
			static bool warning = false;
			 int haveErr = 0;
			 if( bConnectServer == 0)
				 return 1;
			 int i = 0;
			if(  len & IDR_OTHER){
				 if(TheSrv && TheGrp && HandlesSrv[0] ) 
					 try
				 {
				 #ifndef debug_noMachine 
					 TheGrp->SyncRead (OPCDATASOURCE::OPC_DS_DEVICE, HandlesSrv, opcReadData);
				 #else
				  if( debugNotice ++ < 2)
				 	MessageBox::Show("simulate read");
				 #endif
				 }
				 catch(Exception ^ ex) {
					 if( warning == false)
						MessageBox::Show(ex->Message,"SyncRead");
						warning = true;
					 haveErr = 1;
				 }
			}

			 if(  len & IDR_START1 ) {
				 if(TheSrv && TheGrpParameter && HandlesSrvParameter[0] ) 
					 try
				 {
				 #ifndef debug_noMachine 
					 TheGrpParameter->SyncRead (OPCDATASOURCE::OPC_DS_DEVICE, HandlesSrvParameter, opcReadDataParameter);
				 #else
				  if( debugNotice ++ < 2)
				 	MessageBox::Show("simulate read");
				 #endif
				 }
				 catch(Exception ^ ex) {
					if( warning == false)
				MessageBox::Show(ex->Message,"SyncRead");
				warning = true;
					 haveErr = 1;
				 }
			}

			 if(  len & IDR_START2 ) {
				 if(TheSrv && TheGrpParameter2 && HandlesSrvParameter2[0] ) 
					 try
				 {
				 #ifndef debug_noMachine 
					 TheGrpParameter2->SyncRead (OPCDATASOURCE::OPC_DS_DEVICE, HandlesSrvParameter2, opcReadDataParameter2);
				 #else
				  if( debugNotice ++ < 2)
				 	MessageBox::Show("simulate read");
				 #endif
				 }
				 catch(Exception ^ ex) {
					if( warning == false)
				MessageBox::Show(ex->Message,"SyncRead");
				warning = true;
					 haveErr = 1;
				 }
			}
			
			 
			 return haveErr;
		 }
//�ӻ�д����
public: System::Int32 commSynWrite( int len){
	
#ifdef debug_noMachine
					return 0;
			#endif
					static bool warning = false;
			 int haveErr = 0;
			 if( bConnectServer == 0)
				 return 1;
			 //int i = 0;
			if( len & IDW_OTHER){
				 if(TheSrv && TheGrp && HandlesSrv) 
					 try
				 {
				 	#ifndef debug_noMachine 
					 TheGrp->SyncWrite(HandlesSrv, opcWriteData, arrErr);
					 #else
					 if( debugNotice ++ < 2)
				 		MessageBox::Show("simulate write");
					#endif
				 }
				 catch(Exception ^ ex) {
					if( warning == false)
				MessageBox::Show(ex->Message,"SyncWrite");
				warning = true;
				 }
			}
			
			if( len  & IDW_START1){
				 if(TheSrv && TheGrpParameter && HandlesSrvParameter) 
					  try
				  {
	 	#ifndef debug_noMachine 
					  TheGrpParameter->SyncWrite(HandlesSrvParameter, opcWriteDataParameter, arrErrParameter);
		#endif
				  }
				  catch(Exception ^ ex) {
					 if( warning == false)
				MessageBox::Show(ex->Message,"SyncWrite");
				warning = true;
				  }
			}
			
			if( len  & IDW_START2){
				 if(TheSrv && TheGrpParameter2 && HandlesSrvParameter2) 
					  try
				  {
	 	#ifndef debug_noMachine 
					  TheGrpParameter2->SyncWrite(HandlesSrvParameter2, opcWriteDataParameter2, arrErrParameter2);
		#endif
				  }
				  catch(Exception ^ ex) {
					  if( warning == false)
				MessageBox::Show(ex->Message,"SyncWrite");
				warning = true;
				  }
			}
			
			if( len  & IDW_RANDOM){
				 if(TheSrv && TheGrpRandom && HandlesSrvRandom ) 
					  try
				  {
	 	#ifndef debug_noMachine 
					  TheGrpRandom->SyncWrite(HandlesSrvRandom, opcWriteDataRandom, arrErrRandom );
		#endif
				  }
				  catch(Exception ^ ex) {
					  if( warning == false)
				MessageBox::Show(ex->Message,"SyncWrite");
				warning = true;
				  }
			}

			 return haveErr;
		 }
//�ӻ���ʼ��
private: System::Void commDataInit(){
	
		//	#ifdef debug_noMachine
		//		return ;
		//	#endif
			 int i = 0;
			 if( ItemDefs == nullptr)
				 ItemDefs = gcnew array<OPCItemDef^>( itemNum ); //itemNum=39*2,SINGLE_NUM=39;
			 if( rItm == nullptr)
				 rItm = gcnew array<OPCItemResult^>(itemNum);
			 for( i = 0; i < itemNum; i++) {
				 //ItemDefs[i] = gcnew OPCItemDef( ItemA[i], false, 1234 + i, VarEnum::VT_EMPTY);
				 rItm[i] = gcnew OPCItemResult();
			 }
			 if( opcReadData == nullptr)
				 opcReadData = gcnew array<OPCItemState^>( itemNum ); 
			 for( i = 0; i < itemNum; i++) {
				 opcReadData[i] = gcnew OPCItemState;
				 opcWriteData[i] = gcnew Object;
			 }

			 if( ItemDefsParameter == nullptr)
				 ItemDefsParameter = gcnew array<OPCItemDef^>( ParameterNum ); 
			 if( rItmParameter == nullptr)
				 rItmParameter = gcnew array<OPCItemResult^>(ParameterNum);
			 for( i = 0; i < ParameterNum; i++) {
				 rItmParameter[i] = gcnew OPCItemResult();
			 }
			 if( opcReadDataParameter == nullptr)
				 opcReadDataParameter = gcnew array<OPCItemState^>( ParameterNum ); 
			 for( i = 0; i < ParameterNum; i++) {
				 opcWriteDataParameter[i] = gcnew Object;
				 opcReadDataParameter[i] = gcnew OPCItemState;
			 }

			 if( ItemDefsParameter2 == nullptr)
				 ItemDefsParameter2 = gcnew array<OPCItemDef^>( ParameterNum ); 
			 if( rItmParameter2 == nullptr)
				 rItmParameter2 = gcnew array<OPCItemResult^>(ParameterNum);
			 for( i = 0; i < ParameterNum; i++) {
				 rItmParameter2[i] = gcnew OPCItemResult();
			 }
			 if( opcReadDataParameter2 == nullptr)
				 opcReadDataParameter2 = gcnew array<OPCItemState^>( ParameterNum ); 
			 for( i = 0; i < ParameterNum; i++) {
				 opcWriteDataParameter2[i] = gcnew Object;
				 opcReadDataParameter2[i] = gcnew OPCItemState;
			 }

			 if( ItemDefsRandom == nullptr)
				 ItemDefsRandom = gcnew array<OPCItemDef^>( 2 ); 
			 if( rItmRandom == nullptr)
				 rItmRandom = gcnew array<OPCItemResult^>(2);
			 for( i = 0; i < 2; i++) {
				 rItmRandom[i] = gcnew OPCItemResult();
			 }
			 for( i = 0; i < 2; i++) {
				 opcWriteDataRandom[i] = gcnew Object;
			 }

		 }
//���ӷ�����
private: System::Int32 connectServ(){
	
//#ifdef debug_noMachine
//					return 0;
//			#endif
			 int errCode = 0;
			 String^ ServerProgID = "S7200SMART.OPCServer" ;  // ProgID of OPC server:   S7200.OPCServer
			 if( bConnectServer == 1)
				 return 0;
			 try
			 {
				 if( TheSrv == nullptr){
					 TheSrv = gcnew OpcServer();
				 }
				 TheSrv->Connect ( ServerProgID);
			 }
			 catch(Exception ^ ex) {
			/*	 MessageBox::Show(ex->Message,"gcnew OpcServer");
				 TheSrv = nullptr;
				 errCode = 1; */
			 }
			 try
			 {
				 if(TheSrv && (TheGrp == nullptr)) {
					 TheGrp = TheSrv->AddGroup("grp1", false, 900);
					 TheGrp->SetEnable( true );
				 }
				 if(TheSrv && (TheGrpParameter == nullptr)) {
					 TheGrpParameter = TheSrv->AddGroup("grp2", false, 900);
					 TheGrpParameter->SetEnable( true );
				 }

				 if(TheSrv && (TheGrpParameter2 == nullptr)) {
					 TheGrpParameter2 = TheSrv->AddGroup("grp3", false, 900);
					 TheGrpParameter2->SetEnable( true );
				 }

				 if(TheSrv && (TheGrpRandom == nullptr)) {
					 TheGrpRandom = TheSrv->AddGroup("grp4", false, 900);
					 TheGrpRandom->SetEnable( true );
				 }
				 
			 }
			 catch(Exception ^ ex) {
				 //MessageBox::Show(ex->Message);
				 TheGrp = nullptr;
				 errCode = 2;
			 }
			 return errCode;
		 }
//�̺߳���
	private:  System::Void	 WINAPI MyThreadProc1( )
		{
			do
			{
				WaitForSingleObject(semaphore,INFINITE);
				
				#ifdef debug_noMachine
					System::String^ strNotice = " " ; 
					if( gOpcOperation & WRITE_OPC )
						strNotice += "  WRITE_OPC";

					if( gOpcOperation & READ_OPC )
						strNotice += "  READ_OPC";

					if( gOpcDataId & IDR_START1 )
						strNotice += "  ��ʼ1";

					if( gOpcDataId & IDR_START2 )
						strNotice += "  ��ʼ2";

					if( gOpcDataId & IDR_RANDOM)
						strNotice += "  random";

					if( gOpcDataId & IDR_OTHER)
						strNotice += "  other";
					
				 	//MessageBox::Show( "com server:gRinit:" +  System::Convert::ToString( gRInit ) + strNotice );
				#else
					static int initdataItem = 0;
					int errCode = 0;
					if( bConnectServer == 0) {
						ReleaseSemaphore( semaphoreComp,1,NULL);
						continue;
						}
				//commRemoveItem();
					if( initdataItem == 0 || gRInit) {
						if( gRInit )
							commRemoveItem( );
						int i = 0;
						
						for( i = 0; i < itemNum/2; i++) {
							ItemDefs[i ] = gcnew OPCItemDef( ipAdd + ItemA[i], false, 1234 + i, VarEnum::VT_EMPTY);
						}
						for( ; i < itemNum ; i++) {
							ItemDefs[i ] = gcnew OPCItemDef( ipAdd + ItemA[i + 1], false, 1234 + i, VarEnum::VT_EMPTY);
						}

						for( i = 0; i < ParameterNum; i++) {
							ItemDefsParameter[i ] = gcnew OPCItemDef( ipAdd + ItemAParameter[i], false, 2234 + i, VarEnum::VT_EMPTY);
						}
						for( i = 0; i < ParameterNum ; i++) {
							ItemDefsParameter2[i ] = gcnew OPCItemDef( ipAdd + ItemBParameter[i], false, 3234 + i, VarEnum::VT_EMPTY);
						}

						ItemDefsRandom[ 0 ] = gcnew OPCItemDef( ipAdd + ItemA[ 26 ], false, 4234  , VarEnum::VT_EMPTY);
						ItemDefsRandom[ 1 ] = gcnew OPCItemDef( ipAdd + ItemA[ SINGLE_OPC_NUM + 27 ], false, 4235 , VarEnum::VT_EMPTY);
						
						commAddtem( itemNum );
						initdataItem = 1;
					}
					//0-12  read data   
					if( gOpcOperation & WRITE_OPC  )
						commSynWrite ( gOpcDataId );
					
					if( gOpcOperation & READ_OPC )
						commSynRead( gOpcDataId );

					ReleaseSemaphore( semaphoreComp,1,NULL);
				#endif
			}while(!exitPro);
			return ;
		}
//������ʼ��
	public: System::Int32 combase_Init(  ) {
				#ifdef debug_noMachine
				if( !bDataInit && this) {
					try{
					semaphoreComp =  CreateSemaphore(NULL,0,1,NULL);   
					semaphore = CreateSemaphore(NULL,0,1,NULL);   
					if( semaphore ){
						Thread^ th = gcnew Thread(gcnew ThreadStart(this, &Inte_extend::combase::MyThreadProc1));
						th->Start();
					}
					else 
						MessageBox::Show( "creat communication error!" );
					bDataInit = 1; 
					}
					catch(Exception ^ ex) {
					}

				}
					return bDataInit;
				#endif
					try {
				 if( !bDataInit  && this) {
					 commDataInit();
					 bDataInit = 1; 
					 
					semaphoreComp =  CreateSemaphore(NULL,0,1,NULL);   
					 semaphore = CreateSemaphore(NULL,0,1,NULL);  
					 Sleep(300);
					 if( semaphore ){
						 Thread^ th = gcnew Thread(gcnew ThreadStart(this, &Inte_extend::combase::MyThreadProc1));
						 Sleep(300);
						 th->Start();
					 }
					 else 
						MessageBox::Show( "creat communication error!" );
				 }
				 if( this){
				 if( connectServ() == 0 )
					 bConnectServer = 1;
				 else
					 bConnectServer = 0;
				 }
				}
				catch(Exception ^ ex) {
				}
				 return bConnectServer;
			 }

//��������
	private: System::Void combase_Load(System::Object^  sender, System::EventArgs^  e) {
			Control::CheckForIllegalCrossThreadCalls = false; 
			 }
//��������ر�
private: System::Void combase_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {

		 }
};
}
