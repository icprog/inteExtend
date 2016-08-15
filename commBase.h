#pragma once
#include "systemSet.h"
#include "handleMach.h"
#include "public.h"
#define itemNum 32
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
	/// controlMachine 摘要
	/// </summary>
	public ref class commBase : public System::Windows::Forms::Form
	{
	public:
		commBase(void)
		{
			//InitializeComponent();
			//this->IsMdiContainer= true;
			//
			//TODO: 在此处添加构造函数代码
			//
		}
	public:	static System::Int32  zhangLaCount, bDataInit, bConnectServer;
	public:	static System::String^ ipAdd = "";
	public: static	array<float>^ huiGuiXiShu = gcnew array<float>(8);//4个张拉仪,目前支持2个张拉仪
	public:  static	array<System::String^>^ str_holeInfo = gcnew array<System::String^>(holeInfoNum); //孔名，根数，张拉控制力，理论伸长量
	public:  static	array<System::String^>^ str_LiangInfo = gcnew array<System::String^>(3); //梁号，加载速度，初应力，
	public:  static	array<System::String^>^ str_ShunXunInfo = gcnew array<System::String^>(zhangLaSeqNum); 


	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~commBase()
		{
			commRemoveItem();
			try{
				if(  TheGrp )
					TheGrp->Remove(false);
			}
			catch(Exception ^ ex) {
				MessageBox::Show(ex->ToString(),"断开连接失败", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
			}

			TheGrp = nullptr;
			try{
				if( TheSrv != nullptr )
					TheSrv->Disconnect();
			}
			catch(Exception ^ ex) {
				MessageBox::Show(ex->ToString(),"断开连接失败", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
			}
			if (components)
			{
				delete components;
			}
		}
		static	 OpcServer ^		TheSrv = nullptr;
		static	 OpcGroup^			TheGrp= nullptr;
	public:			 static array<OPCItemDef ^>^ ItemDefs = gcnew array<OPCItemDef^>(itemNum); 
	public:			 static array<OPCItemResult ^>^ rItm = gcnew array<OPCItemResult^>(itemNum); 
	public:		 	static array<OPCItemState ^>^ opcReadData = gcnew array<OPCItemState^>(itemNum); 
	public:			 static array<Object ^>^ opcWriteData = gcnew array<Object^>(itemNum);
	public:			 static array<Int32 ,1>^ arrErr = gcnew array<Int32>(itemNum);
	public:			 static array<Int32 ,1>^ HandlesSrv = gcnew array<Int32>(itemNum);
			 
static		array<System::String ^> ^ ItemA = { 
									":1000:0301,v0.7,BOOL,R",//PLC与下位机通信ok 
									
									":1000:0301,VW70,INT,R" ,  //保压合格时间        0
									":1000:0301,VD34,DWORD,R" ,//上位机控制力值显示
									":1000:0301,VD38,DWORD,R" ,//上位机油压目标值显示
									":1000:0301,VD14,DWORD,R" ,//位移最终数据
									":1000:0301,VD10,DWORD,R" ,//油压最终数据
									
									":1000:0301,V4.0,BOOL,R" ,//张拉仪第1行程结束  5
									":1000:0301,V3.0,BOOL,R" ,//张拉仪第1行程进油 
									
									":1000:0301,V4.1,BOOL,R" ,//张拉仪第2行程结束
									":1000:0301,V3.1,BOOL,R" ,//张拉仪第2行程进油
									
									":1000:0301,V4.2,BOOL,R" ,//张拉仪第3行程结束 9
									":1000:0301,V3.2,BOOL,R" ,//张拉仪第3行程进油
									":1000:0301,V3.3,BOOL,R" ,//张拉仪进入保压     
									
									":1000:0301,V3.5,BOOL,RW", //张拉仪保压完成   12
									
									":1000:0301,vd340,DWORD,RW",//张拉初始频率  13
									":1000:0301,vd352,DWORD,RW",//张拉退顶频率
									":1000:0301,vd356,DWORD,RW",//手动操作频率
									":1000:0301,vd348,DWORD,RW",//接近目标频率  
									":1000:0301,vd344,DWORD,RW",//保压补偿频率   17
				 					":1000:0301,vd360,DWORD,RW",//变频调压精度
				 					":1000:0301,vd300,DWORD,RW",//回归方程a系数
				 					":1000:0301,vd304,DWORD,RW",//回归方程b系数  20

									
									":1000:0301,V0.0,BOOL,RW" ,//手动进回油方式 21
									":1000:0301,V0.2,BOOL,RW" ,//手动回油指令  
									":1000:0301,V0.1,BOOL,RW" ,//手动进油指令  23


									":1000:0301,v1.0,BOOL,RW",//PLC与下位机通信连接    24
									":1000:0301,vw48,INT,RW",//上位机通信发送的随机数									
				 					":1000:0301,vd312,DWORD,RW",//张拉第1行程控制力    
				 					":1000:0301,vd316,DWORD,RW",//张拉第2行程控制力
				 					":1000:0301,vd320,DWORD,RW",//张拉第3行程控制力
									":1000:0301,V3.4,BOOL,RW" ,//张拉仪开始张拉
									":1000:0301,VD42,DWORD,RW" //张拉加载速度        30
									};



	private:
		/// <summary>
		/// 必需的设计器变量。
		/// </summary>
		System::ComponentModel::Container ^components;

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
public: System::Void commRemoveItem(){
	if(ItemDefs &&  ( ItemDefs[0] || ItemDefs[1] ) ){
		if( TheGrp )
			TheGrp->RemoveItems(HandlesSrv, arrErr);
	}
	for(int i = 0; i < itemNum; i++) {
		if( ItemDefs )
			ItemDefs[i] = nullptr;
		HandlesSrv[i] = 0;
	}
	
}
public: System::Int32 commAddtem( int num){
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
		MessageBox::Show(ex->Message);

	}
	return haveErr;
	
}

private: System::Int32 commSynRead( int len){
	int haveErr = 0;
	if( bConnectServer == 0)
		return 1;
	int i = 0;

	if(TheSrv && TheGrp && HandlesSrv[0] ) 
	try
	{
		TheGrp->SyncRead (OPCDATASOURCE::OPC_DS_DEVICE, HandlesSrv, opcReadData);
		for( i = 0; i < len; i++) {
			if( opcReadData[i]->Quality == 192)
				;
				//toolStripStatusLabel4->Text = toolStripStatusLabel4->Text + opcReadData[i]->DataValue->ToString() + " ";
			//else
			//	toolStripStatusLabel4->Text = GetQualityText( opcReadData[i]->Quality );
		}
	}
	catch(Exception ^ ex) {
		MessageBox::Show(ex->Message);
		haveErr = 1;
	}
	return haveErr;
}

private: System::Int32 commSynWrite( int len){
	int haveErr = 0;
	if( bConnectServer == 0)
		return 1;
	//int i = 0;

	if(TheSrv && TheGrp && HandlesSrv) 
	try
	{
		TheGrp->SyncWrite(HandlesSrv, opcWriteData, arrErr);
		//for( i = 0; i < len; i++)
			//if ( arrErr[i]  )
				//toolStripStatusLabel4->Text = toolStripStatusLabel4->Text +  System::Convert::ToString( i+1 ) + "写数据失败";
	}
	catch(Exception ^ ex) {
		MessageBox::Show(ex->Message);
	}

	return haveErr;
}

private: System::Void commDataInit(){
	int i = 0;
	if( ItemDefs == nullptr)
		ItemDefs = gcnew array<OPCItemDef^>( itemNum ); 
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
	
}
private: System::Int32 connectServ(){
	int errCode = 0;
	String^ ServerProgID = "S7200.OPCServer" ;  // ProgID of OPC server
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
		TheSrv = nullptr;
		errCode = 1;
	}
	try
	{
		if(TheSrv && (TheGrp == nullptr)) {
			TheGrp = TheSrv->AddGroup("grp1", true, 900);
			TheGrp->SetEnable( true );
		}
	}
	catch(Exception ^ ex) {
		TheGrp = nullptr;
		errCode = 2;
	}
	return errCode;
}

public: System::Int32 writeInitData( int rInit){  //频率,系数,,13-20
static int initdataItem = 0;
	int errCode = 0;
	if( bConnectServer == 0)
		return 1;
	//commRemoveItem();
	if( initdataItem == 0 || rInit) {
		for(int i = 0; i < itemNum; i++) {
			ItemDefs[i ] = gcnew OPCItemDef( ipAdd + ItemA[i], false, 1234 + i, VarEnum::VT_EMPTY);
			opcWriteData[i] = i * 2;
		}
		if( rInit )
			commRemoveItem( );
		commAddtem( itemNum );
		initdataItem = 1;
	}
	//0-12  read data   
	commSynRead( itemNum ); //opcWriteData = opcReadData;
	commSynWrite( itemNum );
	commSynRead( itemNum );

	return 0;
}


private: System::Void commBase_Load(System::Object^  sender, System::EventArgs^  e) {
			
			if( !bDataInit ) {
				commDataInit();
				bDataInit = 1; 
			}
			if( connectServ() == 0 )
				bConnectServer = 1;
			else
				bConnectServer = 0;
		 }
};
}
