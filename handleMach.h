#pragma once
#include "comBase.h"
#include "stdlib.h"
#include "time.h"
//#include "controlMachine.h"
//#include "controlMachine.h"
#using <System.Drawing.dll>
#using <System.Windows.Forms.dll>
#using <System.dll>

namespace Inte_extend {


	using namespace System::Security::Permissions;

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
	/// handleMach 摘要
	/// </summary>
	public ref class handleMach : public System::Windows::Forms::Form
	{
	public:
		handleMach(void)
			: AllOilIn(false)
			, AllOilOut(false)
		{
			bInOil  = false;
			bOutOil = false;
			bInOil2  = false;
			bOutOil2 = false;
			connectStatus = false;
			 timeTickCount = 0;
			 OPCBusy = 0;
			InitializeComponent();
			
			//
			//TODO: 在此处添加构造函数代码
			//
		}

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~handleMach()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::Form ^ ParentForm1;
	public: static combase^  p_comBase = gcnew combase;
	//private: controlMachine^ m_controlMachine=gcnew controlMachine; 
	private: System::Windows::Forms::Button^  butt_inOil;
	private: System::Boolean bInOil,bOutOil,connectStatus,bInOil2,bOutOil2,AllOilIn,AllOilOut;
	
	private: System::Int32 timeTickCount;
	protected: 

	protected: 
	private: System::Windows::Forms::Button^  butt_outOil;
	private: System::Windows::Forms::Label^  label1;
	public: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Panel^  panel1;
	//private: System::Windows::Forms::Button^ button_handleReportExcel;
	public: 
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  butt_outOil2;
	private: System::Windows::Forms::Button^  butt_inOil2;


	private: System::Windows::Forms::Button^  button1;
	private: System::ComponentModel::IContainer^  components;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::Button^  btn_AllOilOut;
	private: System::Windows::Forms::Button^  btn_AllOilIn;
	private: System::Windows::Forms::Label^  label3;
			 //	private: System::Windows::Forms::Button^  handleReportExcel;

	public: System::Int32 OPCBusy;
	private:
		/// <summary>
		/// 必需的设计器变量。
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要
		/// 使用代码编辑器修改此方法的内容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(handleMach::typeid));
			this->butt_inOil = (gcnew System::Windows::Forms::Button());
			this->butt_outOil = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->butt_outOil2 = (gcnew System::Windows::Forms::Button());
			this->butt_inOil2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->btn_AllOilOut = (gcnew System::Windows::Forms::Button());
			this->btn_AllOilIn = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// butt_inOil
			// 
			this->butt_inOil->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->butt_inOil->Location = System::Drawing::Point(21, 46);
			this->butt_inOil->Name = L"butt_inOil";
			this->butt_inOil->Size = System::Drawing::Size(129, 41);
			this->butt_inOil->TabIndex = 0;
			this->butt_inOil->Text = L"手动进油";
			this->butt_inOil->UseVisualStyleBackColor = true;
			this->butt_inOil->Click += gcnew System::EventHandler(this, &handleMach::butt_inOil_Click);
			// 
			// butt_outOil
			// 
			this->butt_outOil->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->butt_outOil->Location = System::Drawing::Point(194, 46);
			this->butt_outOil->Name = L"butt_outOil";
			this->butt_outOil->Size = System::Drawing::Size(130, 41);
			this->butt_outOil->TabIndex = 1;
			this->butt_outOil->Text = L"手动回油";
			this->butt_outOil->UseVisualStyleBackColor = true;
			this->butt_outOil->Click += gcnew System::EventHandler(this, &handleMach::butt_outOil_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label1->ForeColor = System::Drawing::Color::Red;
			this->label1->Location = System::Drawing::Point(7, 6);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(200, 19);
			this->label1->TabIndex = 2;
			this->label1->Text = L"千斤顶1状态：无操作";
			// 
			// timer1
			// 
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &handleMach::timer1_Tick);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->butt_outOil);
			this->panel1->Controls->Add(this->butt_inOil);
			this->panel1->Location = System::Drawing::Point(8, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(346, 102);
			this->panel1->TabIndex = 3;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->label2);
			this->panel2->Controls->Add(this->butt_outOil2);
			this->panel2->Controls->Add(this->butt_inOil2);
			this->panel2->Location = System::Drawing::Point(8, 115);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(346, 102);
			this->panel2->TabIndex = 4;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label2->ForeColor = System::Drawing::Color::Red;
			this->label2->Location = System::Drawing::Point(7, 6);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(200, 19);
			this->label2->TabIndex = 2;
			this->label2->Text = L"千斤顶2状态：无操作";
			// 
			// butt_outOil2
			// 
			this->butt_outOil2->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->butt_outOil2->Location = System::Drawing::Point(194, 46);
			this->butt_outOil2->Name = L"butt_outOil2";
			this->butt_outOil2->Size = System::Drawing::Size(130, 41);
			this->butt_outOil2->TabIndex = 1;
			this->butt_outOil2->Text = L"手动回油";
			this->butt_outOil2->UseVisualStyleBackColor = true;
			this->butt_outOil2->Click += gcnew System::EventHandler(this, &handleMach::butt_outOil2_Click);
			// 
			// butt_inOil2
			// 
			this->butt_inOil2->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->butt_inOil2->Location = System::Drawing::Point(21, 46);
			this->butt_inOil2->Name = L"butt_inOil2";
			this->butt_inOil2->Size = System::Drawing::Size(129, 41);
			this->butt_inOil2->TabIndex = 0;
			this->butt_inOil2->Text = L"手动进油";
			this->butt_inOil2->UseVisualStyleBackColor = true;
			this->butt_inOil2->Click += gcnew System::EventHandler(this, &handleMach::butt_inOil2_Click);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->button1->Location = System::Drawing::Point(113, 326);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(130, 41);
			this->button1->TabIndex = 7;
			this->button1->Text = L"退  出";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &handleMach::button1_Click);
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->label3);
			this->panel3->Controls->Add(this->btn_AllOilOut);
			this->panel3->Controls->Add(this->btn_AllOilIn);
			this->panel3->Location = System::Drawing::Point(8, 218);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(346, 102);
			this->panel3->TabIndex = 5;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label3->ForeColor = System::Drawing::Color::Red;
			this->label3->Location = System::Drawing::Point(7, 7);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(262, 19);
			this->label3->TabIndex = 2;
			this->label3->Text = L"主,从机千斤顶状态: 无操作";
			// 
			// btn_AllOilOut
			// 
			this->btn_AllOilOut->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->btn_AllOilOut->Location = System::Drawing::Point(194, 46);
			this->btn_AllOilOut->Name = L"btn_AllOilOut";
			this->btn_AllOilOut->Size = System::Drawing::Size(129, 41);
			this->btn_AllOilOut->TabIndex = 1;
			this->btn_AllOilOut->Text = L"主从机回油";
			this->btn_AllOilOut->UseVisualStyleBackColor = true;
			this->btn_AllOilOut->Click += gcnew System::EventHandler(this, &handleMach::btn_AllOilOut_Click);
			// 
			// btn_AllOilIn
			// 
			this->btn_AllOilIn->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->btn_AllOilIn->Location = System::Drawing::Point(21, 46);
			this->btn_AllOilIn->Name = L"btn_AllOilIn";
			this->btn_AllOilIn->Size = System::Drawing::Size(129, 41);
			this->btn_AllOilIn->TabIndex = 0;
			this->btn_AllOilIn->Text = L"主从机进油";
			this->btn_AllOilIn->UseVisualStyleBackColor = true;
			this->btn_AllOilIn->Click += gcnew System::EventHandler(this, &handleMach::btn_AllOilIn_Click);
			// 
			// handleMach
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(360, 370);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"handleMach";
			this->Text = L"手动调试";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &handleMach::handleMach_FormClosing);
			this->Shown += gcnew System::EventHandler(this, &handleMach::handleMach_Shown);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void butt_inOil_Click(System::Object^  sender, System::EventArgs^  e) {
		if( bInOil == false){
			 this->p_comBase->opcWriteData[22] = true;  //回方式
			 this->p_comBase->opcWriteData[23] = false;  //回
			 this->p_comBase->opcWriteData[24] = true;  //
		}
		else {
			 this->p_comBase->opcWriteData[22] = false;  //回方式
			 this->p_comBase->opcWriteData[23] = false;  //回
			 this->p_comBase->opcWriteData[24] = false;  //

		}
		this->p_comBase->gRInit = 0;
		this->p_comBase->gOpcOperation = WRITE_OPC;
		this->p_comBase->gOpcDataId   = IDW_OTHER;
		ReleaseSemaphore( this->p_comBase->semaphore,1,NULL);
	 }
	private: System::Void butt_outOil_Click(System::Object^  sender, System::EventArgs^  e) {
		
			 this->p_comBase->gRInit = 0;
			 this->p_comBase->gOpcOperation = WRITE_OPC;
	 		 this->p_comBase->gOpcDataId   = IDW_OTHER;
			if( bOutOil == false ){
				 this->p_comBase->opcWriteData[22] = true;  //回方式
				 this->p_comBase->opcWriteData[23] = true;  //回
				 this->p_comBase->opcWriteData[24] = false;  //
			}
			else{
				 this->p_comBase->opcWriteData[22] = false;  //回方式
				 this->p_comBase->opcWriteData[23] = false;  //回
				 this->p_comBase->opcWriteData[24] = false;  //

			}
		ReleaseSemaphore( this->p_comBase->semaphore,1,NULL);
	 }

private: System::Void butt_inOil2_Click(System::Object^  sender, System::EventArgs^  e) {
	if( bInOil2 == false){
			 this->p_comBase->opcWriteData[SINGLE_OPC_NUM + 22] = true;  //回方式
			 this->p_comBase->opcWriteData[SINGLE_OPC_NUM + 23] = false;  //回
			 this->p_comBase->opcWriteData[SINGLE_OPC_NUM + 24] = true;  //
	}
	else {
		 	 this->p_comBase->gRInit = 0;
			 this->p_comBase->opcWriteData[SINGLE_OPC_NUM + 22] = false;  //回方式
			 this->p_comBase->opcWriteData[SINGLE_OPC_NUM + 23] = false;  //回
			 this->p_comBase->opcWriteData[SINGLE_OPC_NUM + 24] = false;  //
	}
	this->p_comBase->gRInit = 0;
	this->p_comBase->gOpcOperation = WRITE_OPC;
	this->p_comBase->gOpcDataId   = IDW_OTHER;
	ReleaseSemaphore( this->p_comBase->semaphore,1,NULL);
}
/*private: System::Void button_handleReportExcel_Click(System::Object^ sender,System::EventArgs^ e)
		 {
			if( ZhangLaStatus == ZHANGLA_RUN ) 
			{ //"暂 停 张 拉"
				if(1==(int)MessageBox::Show("是否停止张拉,生成表格?","张拉信息",MessageBoxButtons::YesNo))
				{
					setZhangLaData( CurzhangLaSeq , false , 3); 
					ZhangLaStatus = ZHANGLA_TRYPAUSE;
					retryCount = 0;
					ExcelReport();
				}
				return ;
			}
		}	*/
private: System::Void butt_outOil2_Click(System::Object^  sender, System::EventArgs^  e) {
		if( bOutOil2 == false ){
			 this->p_comBase->opcWriteData[SINGLE_OPC_NUM + 22] = true;  //回方式
			 this->p_comBase->opcWriteData[SINGLE_OPC_NUM + 23] = true;  //回
			 this->p_comBase->opcWriteData[SINGLE_OPC_NUM + 24] = false;  //
		}
		else{
		 
			 this->p_comBase->opcWriteData[SINGLE_OPC_NUM + 22] = false;  //回方式
			 this->p_comBase->opcWriteData[SINGLE_OPC_NUM + 23] = false;  //回
			 this->p_comBase->opcWriteData[SINGLE_OPC_NUM + 24] = false;  //
		}
		this->p_comBase->gRInit = 0;
		this->p_comBase->gOpcOperation = WRITE_OPC;
		this->p_comBase->gOpcDataId   = IDW_OTHER;
		ReleaseSemaphore( this->p_comBase->semaphore,1,NULL);

			
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		timeTickCount ++ ;
	//	if( timeTickCount % 3 == 0 )
		try {
		if((this->p_comBase->opcReadData[24]->Quality  == 192) && (this->p_comBase->opcReadData[24]->DataValue->ToString()->ToLower() == "true")
			 && (this->p_comBase->opcReadData[22]->Quality  == 192) && (this->p_comBase->opcReadData[22]->DataValue->ToString()->ToLower() == "true")) {
			 this->label1->Text = L"千斤顶1状态：进油";
			 bInOil = true;
			 bOutOil = false;
			 this->butt_inOil->Text = L"停止进油";
			 this->butt_outOil->Text = L"手动回油";
			 this->butt_outOil->Enabled = false;
			 this->butt_inOil->Enabled = true;
		 }
		
		 if(    (this->p_comBase->opcReadData[24]->Quality  == 192) && (this->p_comBase->opcReadData[24]->DataValue->ToString()->ToLower() == "false")
			 && (this->p_comBase->opcReadData[22]->Quality  == 192) && (this->p_comBase->opcReadData[22]->DataValue->ToString()->ToLower() == "false")
			 && (this->p_comBase->opcReadData[23]->Quality	== 192) && (this->p_comBase->opcReadData[23]->DataValue->ToString()->ToLower() == "false"))
		 {
			 this->label1->Text = L"千斤顶1状态：无操作";
			 bInOil = false;
			 bOutOil = false;
			 this->butt_inOil->Text = L"手动进油";
			 this->butt_outOil->Text = L"手动回油";
			 this->butt_outOil->Enabled = true;
			 this->butt_inOil->Enabled = true;
		 }
		 else if ((this->p_comBase->opcReadData[24]->Quality  == 192) && (this->p_comBase->opcReadData[24]->DataValue->ToString()->ToLower() == "false")
			 && (this->p_comBase->opcReadData[22]->Quality  == 192) && (this->p_comBase->opcReadData[22]->DataValue->ToString()->ToLower() == "true")
			 && (this->p_comBase->opcReadData[23]->Quality	== 192) && (this->p_comBase->opcReadData[23]->DataValue->ToString()->ToLower() == "false"))
		 {
			 this->label1->Text = L"千斤顶1状态：无操作";
			 bInOil = false;
			 bOutOil = false;
			 this->butt_inOil->Text = L"手动进油";
			 this->butt_outOil->Text = L"手动回油";
			 this->butt_outOil->Enabled = true;
			 this->butt_inOil->Enabled = true;
			 this->p_comBase->opcWriteData[22] = false;  //回方式
			 this->p_comBase->opcWriteData[23] = false;  //回
			 this->p_comBase->opcWriteData[24] = false;
			 this->p_comBase->gRInit = 0;
			 this->p_comBase->gOpcOperation = WRITE_OPC;
			 this->p_comBase->gOpcDataId   = IDW_OTHER;
			 ReleaseSemaphore( this->p_comBase->semaphore,1,NULL);
		 }

		  if((this->p_comBase->opcReadData[23]->Quality  == 192) && (this->p_comBase->opcReadData[23]->DataValue->ToString()->ToLower() == "true")
				 && (this->p_comBase->opcReadData[22]->Quality  == 192) && (this->p_comBase->opcReadData[22]->DataValue->ToString()->ToLower() == "true")) {
				 this->label1->Text = L"千斤顶1状态：回油";
				 bInOil = false;
				 bOutOil = true;
				 this->butt_inOil->Text = L"手动进油";
				 this->butt_outOil->Text = L"停止回油";
				 this->butt_inOil->Enabled = false;
				 this->butt_outOil->Enabled = true;
			 }
		  
		 if((this->p_comBase->opcReadData[SINGLE_OPC_NUM + 24]->Quality  == 192) && (this->p_comBase->opcReadData[SINGLE_OPC_NUM + 24]->DataValue->ToString()->ToLower() == "true")
			 && (this->p_comBase->opcReadData[SINGLE_OPC_NUM + 22]->Quality  == 192) && (this->p_comBase->opcReadData[SINGLE_OPC_NUM + 22]->DataValue->ToString()->ToLower() == "true")) {
			 this->label2->Text = L"千斤顶2状态：进油";
			 bInOil2 = true;
			 bOutOil2 = false;
			 this->butt_inOil2->Text = L"停止进油";
			 this->butt_outOil2->Text = L"手动回油";
			 
			 this->butt_outOil2->Enabled = false;
			 this->butt_inOil2->Enabled = true;
		 	}

		  
		  if((this->p_comBase->opcReadData[SINGLE_OPC_NUM + 24]->Quality  == 192) && (this->p_comBase->opcReadData[SINGLE_OPC_NUM + 24]->DataValue->ToString()->ToLower() == "false")
			 && (this->p_comBase->opcReadData[SINGLE_OPC_NUM + 22]->Quality  == 192) && (this->p_comBase->opcReadData[SINGLE_OPC_NUM + 22]->DataValue->ToString()->ToLower() == "false")
			 && (this->p_comBase->opcReadData[SINGLE_OPC_NUM + 23]->Quality  == 192) && (this->p_comBase->opcReadData[SINGLE_OPC_NUM + 23]->DataValue->ToString()->ToLower() == "false"))
			  {
			 this->label2->Text = L"千斤顶2状态：无操作";
			 bInOil2 = false;
			 bOutOil2 = false;
			 this->butt_inOil2->Text = L"手动进油";
			 this->butt_outOil2->Text = L"手动回油";
			 this->butt_outOil2->Enabled = true;
			 this->butt_inOil2->Enabled = true;
			 }
		  else if ((this->p_comBase->opcReadData[SINGLE_OPC_NUM + 24]->Quality  == 192) && (this->p_comBase->opcReadData[SINGLE_OPC_NUM + 24]->DataValue->ToString()->ToLower() == "false")
			  && (this->p_comBase->opcReadData[SINGLE_OPC_NUM + 22]->Quality  == 192) && (this->p_comBase->opcReadData[SINGLE_OPC_NUM + 22]->DataValue->ToString()->ToLower() == "true")
			  && (this->p_comBase->opcReadData[SINGLE_OPC_NUM + 23]->Quality  == 192) && (this->p_comBase->opcReadData[SINGLE_OPC_NUM + 23]->DataValue->ToString()->ToLower() == "false"))
		  {
			  this->label2->Text = L"千斤顶2状态：无操作";
			  bInOil2 = false;
			  bOutOil2 = false;
			  this->butt_inOil2->Text = L"手动进油";
			  this->butt_outOil2->Text = L"手动回油";
			  this->butt_outOil2->Enabled = true;
			  this->butt_inOil2->Enabled = true;
			  this->p_comBase->opcWriteData[22+SINGLE_OPC_NUM] = false;  //回方式
			  this->p_comBase->opcWriteData[23+SINGLE_OPC_NUM] = false;  //回
			  this->p_comBase->opcWriteData[24+SINGLE_OPC_NUM] = false;
			  this->p_comBase->gRInit = 0;
			  this->p_comBase->gOpcOperation = WRITE_OPC;
			  this->p_comBase->gOpcDataId   = IDW_OTHER;
			  ReleaseSemaphore( this->p_comBase->semaphore,1,NULL);
		  }

			
			 if((this->p_comBase->opcReadData[SINGLE_OPC_NUM + 23]->Quality  == 192) && (this->p_comBase->opcReadData[SINGLE_OPC_NUM + 23]->DataValue->ToString()->ToLower() == "true")
				 && (this->p_comBase->opcReadData[SINGLE_OPC_NUM + 22]->Quality  == 192) && (this->p_comBase->opcReadData[SINGLE_OPC_NUM + 22]->DataValue->ToString()->ToLower() == "true")) {
				 this->label2->Text = L"千斤顶2状态：回油";
				 bInOil2 = false;
				 bOutOil2 = true;
				 this->butt_inOil2->Text = L"手动进油";
				 this->butt_outOil2->Text = L"停止回油";
				 this->butt_inOil2->Enabled = false;
				 this->butt_outOil2->Enabled = true;
			 }
			 //手动全进
			 if(    (this->p_comBase->opcReadData[24]->Quality  == 192) && (this->p_comBase->opcReadData[24]->DataValue->ToString()->ToLower() == "true")
				 && (this->p_comBase->opcReadData[22]->Quality  == 192) && (this->p_comBase->opcReadData[22]->DataValue->ToString()->ToLower() == "true")
				 && (this->p_comBase->opcReadData[SINGLE_OPC_NUM + 24]->Quality  == 192) && (this->p_comBase->opcReadData[SINGLE_OPC_NUM + 24]->DataValue->ToString()->ToLower() == "true")
				 && (this->p_comBase->opcReadData[SINGLE_OPC_NUM + 22]->Quality  == 192) && (this->p_comBase->opcReadData[SINGLE_OPC_NUM + 22]->DataValue->ToString()->ToLower() == "true")) {
					 this->label3->Text = L"主,从机千斤顶状态: 全进";
					 AllOilIn = true;
					 AllOilOut = false;
					 this->btn_AllOilIn->Text = L"停止进油";
					 this->btn_AllOilOut->Text = L"主从机回油";
					 this->btn_AllOilOut->Enabled=false;
					 this->btn_AllOilIn->Enabled=true;
			 }
			 //手动全退
			 if(    (this->p_comBase->opcReadData[23]->Quality  == 192) && (this->p_comBase->opcReadData[23]->DataValue->ToString()->ToLower() == "true")
				 && (this->p_comBase->opcReadData[22]->Quality  == 192) && (this->p_comBase->opcReadData[22]->DataValue->ToString()->ToLower() == "true")
				 && (this->p_comBase->opcReadData[SINGLE_OPC_NUM + 23]->Quality  == 192) && (this->p_comBase->opcReadData[SINGLE_OPC_NUM + 23]->DataValue->ToString()->ToLower() == "true")
				 && (this->p_comBase->opcReadData[SINGLE_OPC_NUM + 22]->Quality  == 192) && (this->p_comBase->opcReadData[SINGLE_OPC_NUM + 22]->DataValue->ToString()->ToLower() == "true")) {
					 this->label3->Text = L"主,从机千斤顶状态: 全退";
					 AllOilIn = false;
					 AllOilOut = true;
					 this->btn_AllOilIn->Text = L"主从机进油";
					 this->btn_AllOilOut->Text = L"停止回油";
					 this->btn_AllOilOut->Enabled=true;
					 this->btn_AllOilIn->Enabled=false;
			 }
			 if(    (this->p_comBase->opcReadData[24]->Quality  == 192) && (this->p_comBase->opcReadData[24]->DataValue->ToString()->ToLower() == "false")
				 && (this->p_comBase->opcReadData[22]->Quality  == 192) && (this->p_comBase->opcReadData[22]->DataValue->ToString()->ToLower() == "false")
				 && (this->p_comBase->opcReadData[23]->Quality	== 192) && (this->p_comBase->opcReadData[23]->DataValue->ToString()->ToLower() == "false")
				 && (this->p_comBase->opcReadData[SINGLE_OPC_NUM + 24]->Quality  == 192) && (this->p_comBase->opcReadData[SINGLE_OPC_NUM + 24]->DataValue->ToString()->ToLower() == "false")
				 && (this->p_comBase->opcReadData[SINGLE_OPC_NUM + 22]->Quality  == 192) && (this->p_comBase->opcReadData[SINGLE_OPC_NUM + 22]->DataValue->ToString()->ToLower() == "false")
				 && (this->p_comBase->opcReadData[SINGLE_OPC_NUM + 23]->Quality  == 192) && (this->p_comBase->opcReadData[SINGLE_OPC_NUM + 23]->DataValue->ToString()->ToLower() == "false"))
				 {
					 this->label3->Text = L"主,从机千斤顶状态: 无操作";
					 AllOilIn = false;
					 AllOilOut = false;
					 this->btn_AllOilIn->Text = L"主从机进油";
					 this->btn_AllOilOut->Text = L"主从机回油";
					 this->btn_AllOilOut->Enabled = true;
					 this->btn_AllOilIn->Enabled = true;
			 }
			 else if ((this->p_comBase->opcReadData[24]->Quality  == 192) && (this->p_comBase->opcReadData[24]->DataValue->ToString()->ToLower() == "false")
				 && (this->p_comBase->opcReadData[22]->Quality  == 192) && (this->p_comBase->opcReadData[22]->DataValue->ToString()->ToLower() == "true")
				 && (this->p_comBase->opcReadData[23]->Quality	== 192) && (this->p_comBase->opcReadData[23]->DataValue->ToString()->ToLower() == "false")
				 && (this->p_comBase->opcReadData[SINGLE_OPC_NUM + 24]->Quality  == 192) && (this->p_comBase->opcReadData[SINGLE_OPC_NUM + 24]->DataValue->ToString()->ToLower() == "false")
				 && (this->p_comBase->opcReadData[SINGLE_OPC_NUM + 22]->Quality  == 192) && (this->p_comBase->opcReadData[SINGLE_OPC_NUM + 22]->DataValue->ToString()->ToLower() == "true")
				 && (this->p_comBase->opcReadData[SINGLE_OPC_NUM + 23]->Quality  == 192) && (this->p_comBase->opcReadData[SINGLE_OPC_NUM + 23]->DataValue->ToString()->ToLower() == "false") )
			 {
				 this->label3->Text = L"主,从机千斤顶状态: 无操作";
				 AllOilIn = false;
				 AllOilOut = false;
				 this->btn_AllOilIn->Text = L"主从机进油";
				 this->btn_AllOilOut->Text = L"主从机回油";
				 this->btn_AllOilOut->Enabled = true;
				 this->btn_AllOilIn->Enabled = true;
				 this->p_comBase->opcWriteData[22] = false;  //回方式
				 this->p_comBase->opcWriteData[23] = false;  //回
				 this->p_comBase->opcWriteData[24] = false;
				 this->p_comBase->opcWriteData[22+SINGLE_OPC_NUM] = false;  //回方式
				 this->p_comBase->opcWriteData[23+SINGLE_OPC_NUM] = false;  //回
				 this->p_comBase->opcWriteData[24+SINGLE_OPC_NUM] = false;
				 this->p_comBase->gRInit = 0;
				 this->p_comBase->gOpcOperation = WRITE_OPC;
				 this->p_comBase->gOpcDataId   = IDW_OTHER;
				 ReleaseSemaphore( this->p_comBase->semaphore,1,NULL);
			 }
				 }
	catch(Exception ^ ex) {
	}


 }
private: System::Void handleMach_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		 this->p_comBase->opcWriteData[22] = false;  //回方式
		 this->p_comBase->opcWriteData[23] = false;  //回
		 this->p_comBase->opcWriteData[24] = false;  //
		 this->p_comBase->opcWriteData[SINGLE_OPC_NUM + 22] = false;  //回方式
		 this->p_comBase->opcWriteData[SINGLE_OPC_NUM + 23] = false;  //回
		 this->p_comBase->opcWriteData[SINGLE_OPC_NUM + 24] = false;  //
		 this->p_comBase->gRInit = 0;
		 this->p_comBase->gOpcOperation = WRITE_OPC;
		 this->p_comBase->gOpcDataId   = IDW_OTHER;
				 
		if( bInOil || bOutOil || bInOil2 || bOutOil2 )
			ReleaseSemaphore( this->p_comBase->semaphore,1,NULL);
			
		this->timer1->Enabled = false;
}

private: System::Void handleMach_Shown(System::Object^  sender, System::EventArgs^  e) {
			 this->timer1->Enabled = true;
		 }

private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
		 }

/*private: System::Void handleReportExcel_Click(System::Object^  sender, System::EventArgs^  e) {
			 ExcelReport();
		 }*/
private: System::Void btn_AllOilIn_Click(System::Object^  sender, System::EventArgs^  e) {
			 if( AllOilIn == false){
				 this->p_comBase->opcWriteData[22] = true;  //回方式
				 this->p_comBase->opcWriteData[23] = false;  //回
				 this->p_comBase->opcWriteData[24] = true;  //
				 this->p_comBase->opcWriteData[SINGLE_OPC_NUM + 22] = true;  //回方式
				 this->p_comBase->opcWriteData[SINGLE_OPC_NUM + 23] = false;  //回
				 this->p_comBase->opcWriteData[SINGLE_OPC_NUM + 24] = true;  //
			 }
			 else {
				 this->p_comBase->gRInit = 0;
				 this->p_comBase->opcWriteData[22] = false;  //回方式
				 this->p_comBase->opcWriteData[23] = false;  //回
				 this->p_comBase->opcWriteData[24] = false;  //
				 this->p_comBase->opcWriteData[SINGLE_OPC_NUM + 22] = false;  //回方式
				 this->p_comBase->opcWriteData[SINGLE_OPC_NUM + 23] = false;  //回
				 this->p_comBase->opcWriteData[SINGLE_OPC_NUM + 24] = false;  //
			 }
			 this->p_comBase->gRInit = 0;
			 this->p_comBase->gOpcOperation = WRITE_OPC;
			 this->p_comBase->gOpcDataId   = IDW_OTHER;
			 ReleaseSemaphore( this->p_comBase->semaphore,1,NULL);
		 }
private: System::Void btn_AllOilOut_Click(System::Object^  sender, System::EventArgs^  e) {
			 if( AllOilOut == false){
				 this->p_comBase->opcWriteData[22] = true;  //回方式
				 this->p_comBase->opcWriteData[23] = true;  //回
				 this->p_comBase->opcWriteData[24] = false;  //
				 this->p_comBase->opcWriteData[SINGLE_OPC_NUM + 22] = true;  //回方式
				 this->p_comBase->opcWriteData[SINGLE_OPC_NUM + 23] = true;  //回
				 this->p_comBase->opcWriteData[SINGLE_OPC_NUM + 24] = false;  //
			 }
			 else {
				 this->p_comBase->gRInit = 0;
				 this->p_comBase->opcWriteData[22] = false;  //回方式
				 this->p_comBase->opcWriteData[23] = false;  //回
				 this->p_comBase->opcWriteData[24] = false;  //
				 this->p_comBase->opcWriteData[SINGLE_OPC_NUM + 22] = false;  //回方式
				 this->p_comBase->opcWriteData[SINGLE_OPC_NUM + 23] = false;  //回
				 this->p_comBase->opcWriteData[SINGLE_OPC_NUM + 24] = false;  //
			 }
			 this->p_comBase->gRInit = 0;
			 this->p_comBase->gOpcOperation = WRITE_OPC;
			 this->p_comBase->gOpcDataId   = IDW_OTHER;
			 ReleaseSemaphore( this->p_comBase->semaphore,1,NULL);
		 }
};
}
