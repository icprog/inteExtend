#pragma once
#include "stdlib.h"
#include "time.h"
//#include "afxwin.h"

#include <stdio.h>

#using <mscorlib.dll>
#if _MSC_VER
#define snprintf _snprintf
#endif

#include <vcclr.h>
#include"resource.h"
#include <ctime>
#include "systemSet.h"
#include "historyForm.h"

#include "handleMach.h"
#include "public.h"
#include "ZhangLaParameterView.h"

#define grp2Num 3
#define GRAPH_WID  320
#define GRAPH_HEIT 220



#define GRAPH_GRID_NUM  5  


#define GRAPH_GRID_MPA  10 
#define GRAPH_GRID_MM  40  

#define GRAPH_GRID_Y_RATIO_MM  ((float) GRAPH_HEIT / GRAPH_GRID_NUM / GRAPH_GRID_MM)
#define GRAPH_GRID_Y_RATIO_MPA  ((float) GRAPH_HEIT / GRAPH_GRID_NUM / GRAPH_GRID_MPA)


#define DRAW_DATA_BUFF (4095*10) 

#define ZHANGLA_IDLE  	0
#define ZHANGLA_RUN  	1
#define ZHANGLA_PAUSE   2
#define ZHANGLA_TRYPAUSE  	3
#define ZHANGLA_TRYRUN  	4



#define OIL_IDLE 0
#define OIL_IN   1
#define OIL_OUT  2
#define OIL_ERR  3


#using <System.Drawing.dll>
#using <System.Windows.Forms.dll>
#using <System.dll>
//#using <Microsoft.Office.Interop.Excel.dll>

//#using <ZedGraph.dll>
#include "comBase.h"
namespace Inte_extend {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	using namespace System::Data::OleDb;
	using namespace System::Configuration;

	using namespace System::Runtime::InteropServices;
	using namespace System::Threading;
	//using namespace Microsoft::Office::Interop::Excel;

	//using namespace excel


	static struct DRAW_DATA drawData[DRAW_DATA_BUFF];

	/// <summary>
	/// controlMachine 摘要
	/// </summary>
	public ref class controlMachine : public System::Windows::Forms::Form
	{
	public:
		controlMachine(void)
		{
			pause_show1=false;
			pause_show2=false;
			system_pause1=false;
			system_pause2=false;
			konghao_over=false;
			Single_Zhangla=false;
			debugStatus = false;
			bConnected = false;
			bPauseByPLC = false;
			bShowed = false;
			ZhangLaStatus = ZHANGLA_IDLE;
			connectStatus = false;
			bDataInit = 0;
			CurzhangLaSeq = 0;
			timeTickCount = 0;
			errHeartBeat = 0;
			latestDefaultMpa = 0;
			latestDefaultMm = 0;
			latestDefaultMpa2 = 0;
			latestDefaultMm2 = 0;
			latestCountDown = 0;

			GRAPH_GRID_SECOND = 10;
			graph1_x = 17;
			preCurIndex = -1;
			graph1_y = GRAPH_HEIT + 25; //GRAPH_HEIT + 130;
			//			graph1_y = GRAPH_HEIT * 2 + 200; //GRAPH_HEIT * 2 + 160;

			bShowHandMach = false;
			ButtonPressed_d = 0;
			ButtonPressed = 0;

			bSendConnectCmd = 0;
			bShowedWindow = 0;
			startZhangLaMm1 = 0;
			startZhangLaMm2 = 0;

			InitializeComponent();
			//this->IsMdiContainer= true;
			//
			//TODO: 在此处添加构造函数代码
			//
		}
	private: System::Windows::Forms::ListBox^  listBox1;
	private: System::Windows::Forms::Button^  butt_handle;

	private: System::Windows::Forms::ListBox^  listBox2;
	public: static	array<float>^ huiGuiXiShu = gcnew array<float>(8);  
	public:  static	array<System::String^>^ str_holeInfo = gcnew array<System::String^>(holeInfoNum);  
	public:  static	array<System::String^>^ str_LiangInfo = gcnew array<System::String^>(3);  

	private: static	array<Boolean>^ multiZhangLa = gcnew array<Boolean>(zhangLaSeqNum); 
	private: static	array<float>^ curPercentKN = gcnew array<float>(zhangLaSeqNum); 
	private: static	array<float>^ accLen = gcnew array<float>(zhangLaSeqNum * 3); 
	private: static	array<float>^ accMpa = gcnew array<float>(zhangLaSeqNum * 3); 

	private: static	array<float>^ accLen2 = gcnew array<float>(zhangLaSeqNum * 3); 
	private: static	array<float>^ accMpa2 = gcnew array<float>(zhangLaSeqNum * 3); 

	private: float curXingCheng;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Button^  butt_connect;
	public: 
	public:  static	array<System::String^>^ str_ShunXunInfo = gcnew array<System::String^>(zhangLaSeqNum); 
	public:  static	array<System::String^>^ str_ExcelInfo = gcnew array<System::String^>( 20 ); 

	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::PictureBox^  pictureBox3;



	private: System::Windows::Forms::PictureBox^  pictureBox5;
	private: System::Windows::Forms::PictureBox^  pictureBox4;


	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::CheckBox^  checkBox_lenth;
	private: System::Windows::Forms::PictureBox^  pictureBox_Mpa2;
	private: System::Windows::Forms::PictureBox^  pictureBox_Mpa1;
	private: System::Windows::Forms::PictureBox^  pictureBox_MM1;
	private: System::Windows::Forms::PictureBox^  pictureBox_MM2;
	private: System::Windows::Forms::Button^  btn_handleReportExcel;
	private: System::Windows::Forms::Button^  btn_single;

	public: 
	private: System::String^  filePath ;//张拉数据保存文件名
	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~controlMachine()
		{
			ReleaseSemaphore( this->p_comBase->semaphore,1,NULL);

			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	protected: 
	public: combase^  p_comBase;
	private: System::Windows::Forms::Panel^  panel11;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;

	private: Int32 preCurIndex ;
	public: System::Int32  zhangLaCount, bDataInit, bSendConnectCmd;
	public: System::Int32  CurzhangLaSeq,bGenExcel;

	public: System::Int32 bShowedWindow,konghao_over ,curLiangType;
	private: System::Int32 timeTickCount;//latestCountDown:保压倒计时
	private: float  latestCountDown;

	private: float  startZhangLaMm1;
	private: float  startZhangLaMm2;

	public: float  LEN_SUB ;

	private: System::Int32 graph1_x,graph1_y;  

	private: System::Int32  GRAPH_GRID_SECOND ,  GRAPH_X_NUM ;  
			 //	private:  float GRAPH_GRID_Y_RATIO_MM , GRAPH_GRID_Y_RATIO_MPA;

	private: System::Int32 absReadOpcIndex, preItem; 
	private: float  latestDefaultMpa,latestDefaultMm; 
	private: float  latestDefaultMpa2,latestDefaultMm2; 
	private : System::Int32  machine1Oil;    
	private : System::Int32  machine2Oil;   
	private: System::Int32 errHeartBeat ; 
	private: float loadSpeed ;  
	private: Boolean  bConnected, bPauseByPLC;  
	private: System::Boolean debugStatus, bShowed,connectStatus, userChooseZhangla,Single_Zhangla,kong_over;  
	private: System::Boolean system_pause1,system_pause2,pause_show1,pause_show2;
	public: System::Int32 ZhangLaStatus;   
	private : System::Int32  retryCount;  
	public : System::String^ zhanglaSeq;
	public : System::String^ More_check;
	private: System::Int32 ButtonPressed,ButtonPressed_d ;
	public:  System::Int32 Main_Wnd_ButCurs;


	private: float len_total ; 
	private: float len_percent ;  
	private: System::Int32 listBox2Index;   
	private: System::UInt64 listBox2Noticed , warningDistance; 

	private: System::Int32 calculate_index;


	private: handleMach m_handleMach;
	private: Boolean  bShowHandMach;

	private: systemSet m_systemSet;
	private: historyForm m_historyForm;
	private: ZhangLaParameterView m_ZhangLaParameterView;



	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel1;
	private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel2;
	private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel3;
	private: System::Windows::Forms::ToolStripProgressBar^  toolStripProgressBar1;
	private: System::Windows::Forms::ToolStripStatusLabel^  toolStripConnectStatus;

	private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel5;
	private: System::Windows::Forms::Label^  label_outOil1;

	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label_d1Mpa;

	private: System::Windows::Forms::Label^  label_d1KN;

	private: System::Windows::Forms::LinkLabel^  linkLabel1;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;


	private: System::Windows::Forms::Label^  label_d1mm;


	private: System::Windows::Forms::Panel^  panel4;
	private: System::Windows::Forms::Label^  label_CountDown;
	private: System::Windows::Forms::Label^  label_CountDown_notice;


	private: System::Windows::Forms::Label^  label19;


	private: System::Windows::Forms::Label^  label18;


	private: System::Windows::Forms::TextBox^  textBox_liangHao;

	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::Panel^  panel5;
	private: System::Windows::Forms::Label^  label25;
	private: System::Windows::Forms::Panel^  panel7;

	private: System::Windows::Forms::Button^  button_Reset;

	private: System::Windows::Forms::Button^  button_history;

	private: System::Windows::Forms::Button^  button_zhangLaParameter;

	private: System::Windows::Forms::Button^  button_systemParameter;
			 //private:Graphics^ graph;




	private: System::Windows::Forms::Label^  label22;
	private: System::Windows::Forms::Panel^  panel6;
	private: System::Windows::Forms::Label^  label_percent;

	private: System::Windows::Forms::ProgressBar^  progressBar_percent;
	private: System::Windows::Forms::Label^  label_acture;


	private: System::Windows::Forms::ProgressBar^  progressBar_theory;
	private: System::Windows::Forms::Label^  label_theory;



	private: System::Windows::Forms::Button^  but_startZhang;

	private: System::Windows::Forms::PictureBox^  pictureBox1;


	private: System::Windows::Forms::Label^  label40;


	private: System::Windows::Forms::Label^  label43;
	private: System::Windows::Forms::Label^  label42;
	private: System::Windows::Forms::TextBox^  textBox_d1Mpa_des;

	private: System::Windows::Forms::Label^  label27;
	private: System::Windows::Forms::Panel^  panel2;


	private: System::Windows::Forms::Panel^  panel8;
	private: System::Windows::Forms::TextBox^  textBox_d2Mpa_des;
	private: System::Windows::Forms::Label^  label_d2mm;


	private: System::Windows::Forms::Label^  label31;
	private: System::Windows::Forms::Label^  label32;
	private: System::Windows::Forms::Label^  label_outOil2;



	private: System::Windows::Forms::Label^  label36;
	private: System::Windows::Forms::Label^  label37;
	private: System::Windows::Forms::Label^  label_d2Mpa;

	private: System::Windows::Forms::Label^  label_d2KN;

	private: System::Windows::Forms::Label^  label41;
	private: System::Windows::Forms::Label^  label44;
	private: System::Windows::Forms::Label^  label45;
	private: System::ComponentModel::IContainer^  components;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(controlMachine::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label43 = (gcnew System::Windows::Forms::Label());
			this->label42 = (gcnew System::Windows::Forms::Label());
			this->panel11 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->textBox_d1Mpa_des = (gcnew System::Windows::Forms::TextBox());
			this->label_d1mm = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label_outOil1 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label_d1Mpa = (gcnew System::Windows::Forms::Label());
			this->label_d1KN = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox_Mpa1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox_MM1 = (gcnew System::Windows::Forms::PictureBox());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->toolStripStatusLabel1 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->toolStripStatusLabel2 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->toolStripStatusLabel3 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->toolStripProgressBar1 = (gcnew System::Windows::Forms::ToolStripProgressBar());
			this->toolStripConnectStatus = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->toolStripStatusLabel5 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			this->label_CountDown = (gcnew System::Windows::Forms::Label());
			this->label_CountDown_notice = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->textBox_liangHao = (gcnew System::Windows::Forms::TextBox());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->checkBox_lenth = (gcnew System::Windows::Forms::CheckBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->btn_single = (gcnew System::Windows::Forms::Button());
			this->btn_handleReportExcel = (gcnew System::Windows::Forms::Button());
			this->butt_connect = (gcnew System::Windows::Forms::Button());
			this->butt_handle = (gcnew System::Windows::Forms::Button());
			this->button_Reset = (gcnew System::Windows::Forms::Button());
			this->button_history = (gcnew System::Windows::Forms::Button());
			this->button_zhangLaParameter = (gcnew System::Windows::Forms::Button());
			this->button_systemParameter = (gcnew System::Windows::Forms::Button());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->label_percent = (gcnew System::Windows::Forms::Label());
			this->progressBar_percent = (gcnew System::Windows::Forms::ProgressBar());
			this->label_acture = (gcnew System::Windows::Forms::Label());
			this->progressBar_theory = (gcnew System::Windows::Forms::ProgressBar());
			this->label_theory = (gcnew System::Windows::Forms::Label());
			this->but_startZhang = (gcnew System::Windows::Forms::Button());
			this->label40 = (gcnew System::Windows::Forms::Label());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->textBox_d2Mpa_des = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->label_d2mm = (gcnew System::Windows::Forms::Label());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->label_outOil2 = (gcnew System::Windows::Forms::Label());
			this->label36 = (gcnew System::Windows::Forms::Label());
			this->label37 = (gcnew System::Windows::Forms::Label());
			this->label_d2Mpa = (gcnew System::Windows::Forms::Label());
			this->label_d2KN = (gcnew System::Windows::Forms::Label());
			this->label41 = (gcnew System::Windows::Forms::Label());
			this->label44 = (gcnew System::Windows::Forms::Label());
			this->label45 = (gcnew System::Windows::Forms::Label());
			this->pictureBox_Mpa2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox_MM2 = (gcnew System::Windows::Forms::PictureBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1->SuspendLayout();
			this->panel11->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox_Mpa1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox_MM1))->BeginInit();
			this->statusStrip1->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->panel7->SuspendLayout();
			this->panel6->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel8->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox_Mpa2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox_MM2))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->label43);
			this->panel1->Controls->Add(this->label42);
			this->panel1->Controls->Add(this->panel11);
			this->panel1->Controls->Add(this->pictureBox_Mpa1);
			this->panel1->Controls->Add(this->pictureBox_MM1);
			this->panel1->Location = System::Drawing::Point(9, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(370, 660);
			this->panel1->TabIndex = 0;
			// 
			// label43
			// 
			this->label43->AutoSize = true;
			this->label43->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label43->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label43->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label43->Location = System::Drawing::Point(75, 390);
			this->label43->Name = L"label43";
			this->label43->Size = System::Drawing::Size(268, 16);
			this->label43->TabIndex = 14;
			this->label43->Text = L"张拉仪1 位移曲线:( 毫米 - 秒 )";
			// 
			// label42
			// 
			this->label42->AutoSize = true;
			this->label42->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label42->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label42->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label42->Location = System::Drawing::Point(75, 116);
			this->label42->Name = L"label42";
			this->label42->Size = System::Drawing::Size(261, 16);
			this->label42->TabIndex = 13;
			this->label42->Text = L"张拉仪1 压力曲线:( Mpa - 秒 )";
			// 
			// panel11
			// 
			this->panel11->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel11->Controls->Add(this->pictureBox3);
			this->panel11->Controls->Add(this->pictureBox2);
			this->panel11->Controls->Add(this->textBox_d1Mpa_des);
			this->panel11->Controls->Add(this->label_d1mm);
			this->panel11->Controls->Add(this->label11);
			this->panel11->Controls->Add(this->label12);
			this->panel11->Controls->Add(this->label_outOil1);
			this->panel11->Controls->Add(this->label7);
			this->panel11->Controls->Add(this->label6);
			this->panel11->Controls->Add(this->label_d1Mpa);
			this->panel11->Controls->Add(this->label_d1KN);
			this->panel11->Controls->Add(this->label3);
			this->panel11->Controls->Add(this->label2);
			this->panel11->Controls->Add(this->label1);
			this->panel11->Location = System::Drawing::Point(3, 4);
			this->panel11->Name = L"panel11";
			this->panel11->Size = System::Drawing::Size(362, 102);
			this->panel11->TabIndex = 0;
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(218, 53);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(42, 42);
			this->pictureBox3->TabIndex = 16;
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(219, 6);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(42, 42);
			this->pictureBox2->TabIndex = 15;
			this->pictureBox2->TabStop = false;
			// 
			// textBox_d1Mpa_des
			// 
			this->textBox_d1Mpa_des->Enabled = false;
			this->textBox_d1Mpa_des->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->textBox_d1Mpa_des->ForeColor = System::Drawing::Color::Red;
			this->textBox_d1Mpa_des->Location = System::Drawing::Point(40, 54);
			this->textBox_d1Mpa_des->Name = L"textBox_d1Mpa_des";
			this->textBox_d1Mpa_des->Size = System::Drawing::Size(53, 23);
			this->textBox_d1Mpa_des->TabIndex = 14;
			this->textBox_d1Mpa_des->Text = L"000.00";
			// 
			// label_d1mm
			// 
			this->label_d1mm->BackColor = System::Drawing::SystemColors::ControlText;
			this->label_d1mm->Font = (gcnew System::Drawing::Font(L"宋体", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label_d1mm->ForeColor = System::Drawing::Color::Yellow;
			this->label_d1mm->Location = System::Drawing::Point(275, 55);
			this->label_d1mm->Name = L"label_d1mm";
			this->label_d1mm->Size = System::Drawing::Size(80, 25);
			this->label_d1mm->TabIndex = 12;
			this->label_d1mm->Text = L"000.0";
			this->label_d1mm->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(299, 30);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(41, 12);
			this->label11->TabIndex = 11;
			this->label11->Text = L"( mm )";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label12->Location = System::Drawing::Point(300, 15);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(37, 14);
			this->label12->TabIndex = 10;
			this->label12->Text = L"位移";
			// 
			// label_outOil1
			// 
			this->label_outOil1->AutoSize = true;
			this->label_outOil1->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label_outOil1->Location = System::Drawing::Point(175, 60);
			this->label_outOil1->Name = L"label_outOil1";
			this->label_outOil1->Size = System::Drawing::Size(37, 14);
			this->label_outOil1->TabIndex = 7;
			this->label_outOil1->Text = L"退油";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label7->Location = System::Drawing::Point(176, 20);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(37, 14);
			this->label7->TabIndex = 6;
			this->label7->Text = L"进油";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(-1, 75);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(41, 12);
			this->label6->TabIndex = 5;
			this->label6->Text = L"(M Pa)";
			// 
			// label_d1Mpa
			// 
			this->label_d1Mpa->BackColor = System::Drawing::SystemColors::ControlText;
			this->label_d1Mpa->Font = (gcnew System::Drawing::Font(L"宋体", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label_d1Mpa->ForeColor = System::Drawing::Color::Yellow;
			this->label_d1Mpa->Location = System::Drawing::Point(94, 53);
			this->label_d1Mpa->Name = L"label_d1Mpa";
			this->label_d1Mpa->Size = System::Drawing::Size(80, 25);
			this->label_d1Mpa->TabIndex = 4;
			this->label_d1Mpa->Text = L"000.00";
			this->label_d1Mpa->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_d1KN
			// 
			this->label_d1KN->BackColor = System::Drawing::SystemColors::ControlText;
			this->label_d1KN->Font = (gcnew System::Drawing::Font(L"宋体", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label_d1KN->ForeColor = System::Drawing::Color::Yellow;
			this->label_d1KN->Location = System::Drawing::Point(42, 5);
			this->label_d1KN->Name = L"label_d1KN";
			this->label_d1KN->Size = System::Drawing::Size(127, 35);
			this->label_d1KN->TabIndex = 3;
			this->label_d1KN->Text = L"00000.0";
			this->label_d1KN->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"宋体", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label3->ForeColor = System::Drawing::Color::Red;
			this->label3->Location = System::Drawing::Point(-2, 56);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(44, 12);
			this->label3->TabIndex = 2;
			this->label3->Text = L"目标值";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(1, 30);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 12);
			this->label2->TabIndex = 1;
			this->label2->Text = L"(k N)";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label1->Location = System::Drawing::Point(-1, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(37, 14);
			this->label1->TabIndex = 0;
			this->label1->Text = L"力值";
			// 
			// pictureBox_Mpa1
			// 
			this->pictureBox_Mpa1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->pictureBox_Mpa1->Location = System::Drawing::Point(9, 112);
			this->pictureBox_Mpa1->Name = L"pictureBox_Mpa1";
			this->pictureBox_Mpa1->Size = System::Drawing::Size(350, 264);
			this->pictureBox_Mpa1->TabIndex = 20;
			this->pictureBox_Mpa1->TabStop = false;
			this->pictureBox_Mpa1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &controlMachine::pictureBox_Mpa1_Paint);
			// 
			// pictureBox_MM1
			// 
			this->pictureBox_MM1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->pictureBox_MM1->Location = System::Drawing::Point(9, 385);
			this->pictureBox_MM1->Name = L"pictureBox_MM1";
			this->pictureBox_MM1->Size = System::Drawing::Size(350, 264);
			this->pictureBox_MM1->TabIndex = 21;
			this->pictureBox_MM1->TabStop = false;
			this->pictureBox_MM1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &controlMachine::pictureBox_MM1_Paint);
			// 
			// statusStrip1
			// 
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {this->toolStripStatusLabel1, 
				this->toolStripStatusLabel2, this->toolStripStatusLabel3, this->toolStripProgressBar1, this->toolStripConnectStatus, this->toolStripStatusLabel5});
			this->statusStrip1->Location = System::Drawing::Point(0, 680);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(1016, 22);
			this->statusStrip1->TabIndex = 3;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// toolStripStatusLabel1
			// 
			this->toolStripStatusLabel1->Name = L"toolStripStatusLabel1";
			this->toolStripStatusLabel1->Size = System::Drawing::Size(104, 17);
			this->toolStripStatusLabel1->Text = L"湖南聚创欢迎您！";
			// 
			// toolStripStatusLabel2
			// 
			this->toolStripStatusLabel2->AutoSize = false;
			this->toolStripStatusLabel2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->toolStripStatusLabel2->ForeColor = System::Drawing::SystemColors::Control;
			this->toolStripStatusLabel2->Name = L"toolStripStatusLabel2";
			this->toolStripStatusLabel2->Size = System::Drawing::Size(77, 17);
			this->toolStripStatusLabel2->Text = L"          ";
			// 
			// toolStripStatusLabel3
			// 
			this->toolStripStatusLabel3->Name = L"toolStripStatusLabel3";
			this->toolStripStatusLabel3->Size = System::Drawing::Size(68, 17);
			this->toolStripStatusLabel3->Text = L"通信状态：";
			// 
			// toolStripProgressBar1
			// 
			this->toolStripProgressBar1->Name = L"toolStripProgressBar1";
			this->toolStripProgressBar1->Size = System::Drawing::Size(150, 16);
			// 
			// toolStripConnectStatus
			// 
			this->toolStripConnectStatus->AutoSize = false;
			this->toolStripConnectStatus->Name = L"toolStripConnectStatus";
			this->toolStripConnectStatus->Size = System::Drawing::Size(200, 17);
			this->toolStripConnectStatus->Text = L"  ";
			// 
			// toolStripStatusLabel5
			// 
			this->toolStripStatusLabel5->Name = L"toolStripStatusLabel5";
			this->toolStripStatusLabel5->Size = System::Drawing::Size(203, 17);
			this->toolStripStatusLabel5->Text = L"湖南聚创建筑科技有限公司1.15.3.18";
			// 
			// linkLabel1
			// 
			this->linkLabel1->AutoSize = true;
			this->linkLabel1->Location = System::Drawing::Point(802, 706);
			this->linkLabel1->Name = L"linkLabel1";
			this->linkLabel1->Size = System::Drawing::Size(113, 12);
			this->linkLabel1->TabIndex = 4;
			this->linkLabel1->TabStop = true;
			this->linkLabel1->Text = L"http://jochon.com/";
			// 
			// panel4
			// 
			this->panel4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel4->Controls->Add(this->listBox2);
			this->panel4->Controls->Add(this->label_CountDown);
			this->panel4->Controls->Add(this->label_CountDown_notice);
			this->panel4->Controls->Add(this->label19);
			this->panel4->Controls->Add(this->label18);
			this->panel4->Controls->Add(this->textBox_liangHao);
			this->panel4->Controls->Add(this->label17);
			this->panel4->Controls->Add(this->listBox1);
			this->panel4->Location = System::Drawing::Point(768, 14);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(235, 267);
			this->panel4->TabIndex = 2;
			// 
			// listBox2
			// 
			this->listBox2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->listBox2->Font = (gcnew System::Drawing::Font(L"宋体", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->listBox2->ForeColor = System::Drawing::Color::Red;
			this->listBox2->FormattingEnabled = true;
			this->listBox2->HorizontalScrollbar = true;
			this->listBox2->ItemHeight = 12;
			this->listBox2->Location = System::Drawing::Point(11, 152);
			this->listBox2->Name = L"listBox2";
			this->listBox2->Size = System::Drawing::Size(206, 86);
			this->listBox2->TabIndex = 15;
			// 
			// label_CountDown
			// 
			this->label_CountDown->AutoSize = true;
			this->label_CountDown->Font = (gcnew System::Drawing::Font(L"宋体", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label_CountDown->ForeColor = System::Drawing::Color::Red;
			this->label_CountDown->Location = System::Drawing::Point(138, 240);
			this->label_CountDown->Name = L"label_CountDown";
			this->label_CountDown->Size = System::Drawing::Size(42, 20);
			this->label_CountDown->TabIndex = 13;
			this->label_CountDown->Text = L"0 S";
			// 
			// label_CountDown_notice
			// 
			this->label_CountDown_notice->AutoSize = true;
			this->label_CountDown_notice->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label_CountDown_notice->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->label_CountDown_notice->Location = System::Drawing::Point(31, 243);
			this->label_CountDown_notice->Name = L"label_CountDown_notice";
			this->label_CountDown_notice->Size = System::Drawing::Size(110, 16);
			this->label_CountDown_notice->TabIndex = 12;
			this->label_CountDown_notice->Text = L"持荷倒计时：";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Font = (gcnew System::Drawing::Font(L"宋体", 9));
			this->label19->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->label19->Location = System::Drawing::Point(11, 139);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(53, 12);
			this->label19->TabIndex = 11;
			this->label19->Text = L"状态显示";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Font = (gcnew System::Drawing::Font(L"宋体", 9));
			this->label18->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->label18->Location = System::Drawing::Point(11, 41);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(53, 12);
			this->label18->TabIndex = 9;
			this->label18->Text = L"张拉步骤";
			// 
			// textBox_liangHao
			// 
			this->textBox_liangHao->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->textBox_liangHao->ForeColor = System::Drawing::Color::Red;
			this->textBox_liangHao->Location = System::Drawing::Point(62, 15);
			this->textBox_liangHao->Name = L"textBox_liangHao";
			this->textBox_liangHao->ReadOnly = true;
			this->textBox_liangHao->Size = System::Drawing::Size(155, 29);
			this->textBox_liangHao->TabIndex = 7;
			this->textBox_liangHao->Text = L"名称";
			this->textBox_liangHao->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label17->Location = System::Drawing::Point(15, 19);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(48, 16);
			this->label17->TabIndex = 1;
			this->label17->Text = L"梁号:";
			// 
			// listBox1
			// 
			this->listBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->listBox1->Enabled = false;
			this->listBox1->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->listBox1->ForeColor = System::Drawing::SystemColors::GrayText;
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 16;
			this->listBox1->Location = System::Drawing::Point(11, 55);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(206, 82);
			this->listBox1->TabIndex = 14;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->label15->Location = System::Drawing::Point(768, 10);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(53, 12);
			this->label15->TabIndex = 5;
			this->label15->Text = L"张拉状态";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->label16->Location = System::Drawing::Point(771, 285);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(53, 12);
			this->label16->TabIndex = 7;
			this->label16->Text = L"张拉控制";
			// 
			// panel5
			// 
			this->panel5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel5->Controls->Add(this->checkBox_lenth);
			this->panel5->Controls->Add(this->pictureBox1);
			this->panel5->Controls->Add(this->label25);
			this->panel5->Controls->Add(this->panel7);
			this->panel5->Controls->Add(this->label22);
			this->panel5->Controls->Add(this->panel6);
			this->panel5->Controls->Add(this->but_startZhang);
			this->panel5->Location = System::Drawing::Point(768, 288);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(236, 384);
			this->panel5->TabIndex = 6;
			// 
			// checkBox_lenth
			// 
			this->checkBox_lenth->AutoSize = true;
			this->checkBox_lenth->Location = System::Drawing::Point(163, 67);
			this->checkBox_lenth->Name = L"checkBox_lenth";
			this->checkBox_lenth->Size = System::Drawing::Size(48, 16);
			this->checkBox_lenth->TabIndex = 15;
			this->checkBox_lenth->Text = L"校核";
			this->checkBox_lenth->UseVisualStyleBackColor = true;
			this->checkBox_lenth->CheckedChanged += gcnew System::EventHandler(this, &controlMachine::checkBox_lenth_CheckedChanged);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(11, 337);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(212, 43);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 14;
			this->pictureBox1->TabStop = false;
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Font = (gcnew System::Drawing::Font(L"宋体", 9));
			this->label25->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->label25->Location = System::Drawing::Point(17, 180);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(53, 12);
			this->label25->TabIndex = 12;
			this->label25->Text = L"系统操作";
			// 
			// panel7
			// 
			this->panel7->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel7->Controls->Add(this->btn_single);
			this->panel7->Controls->Add(this->btn_handleReportExcel);
			this->panel7->Controls->Add(this->butt_connect);
			this->panel7->Controls->Add(this->butt_handle);
			this->panel7->Controls->Add(this->button_Reset);
			this->panel7->Controls->Add(this->button_history);
			this->panel7->Controls->Add(this->button_zhangLaParameter);
			this->panel7->Controls->Add(this->button_systemParameter);
			this->panel7->Location = System::Drawing::Point(12, 185);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(211, 146);
			this->panel7->TabIndex = 13;
			// 
			// btn_single
			// 
			this->btn_single->Font = (gcnew System::Drawing::Font(L"宋体", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->btn_single->Location = System::Drawing::Point(109, 110);
			this->btn_single->Name = L"btn_single";
			this->btn_single->Size = System::Drawing::Size(95, 31);
			this->btn_single->TabIndex = 10;
			this->btn_single->Text = L"启动单端张拉";
			this->btn_single->UseVisualStyleBackColor = false;
			this->btn_single->Click += gcnew System::EventHandler(this, &controlMachine::btn_single_Click);
			// 
			// btn_handleReportExcel
			// 
			this->btn_handleReportExcel->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->btn_handleReportExcel->Location = System::Drawing::Point(9, 110);
			this->btn_handleReportExcel->Name = L"btn_handleReportExcel";
			this->btn_handleReportExcel->Size = System::Drawing::Size(95, 31);
			this->btn_handleReportExcel->TabIndex = 9;
			this->btn_handleReportExcel->Text = L"手动制表";
			this->btn_handleReportExcel->UseVisualStyleBackColor = true;
			this->btn_handleReportExcel->Click += gcnew System::EventHandler(this, &controlMachine::btn_handleReportExcel_Click);
			// 
			// butt_connect
			// 
			this->butt_connect->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->butt_connect->Location = System::Drawing::Point(9, 6);
			this->butt_connect->Name = L"butt_connect";
			this->butt_connect->Size = System::Drawing::Size(95, 32);
			this->butt_connect->TabIndex = 8;
			this->butt_connect->Text = L"连接设备";
			this->butt_connect->UseVisualStyleBackColor = true;
			this->butt_connect->Click += gcnew System::EventHandler(this, &controlMachine::butt_connect_Click);
			// 
			// butt_handle
			// 
			this->butt_handle->Enabled = false;
			this->butt_handle->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->butt_handle->Location = System::Drawing::Point(109, 74);
			this->butt_handle->Name = L"butt_handle";
			this->butt_handle->Size = System::Drawing::Size(95, 32);
			this->butt_handle->TabIndex = 7;
			this->butt_handle->Text = L"手动操作";
			this->butt_handle->UseVisualStyleBackColor = true;
			this->butt_handle->Click += gcnew System::EventHandler(this, &controlMachine::butt_handle_Click);
			// 
			// button_Reset
			// 
			this->button_Reset->Enabled = false;
			this->button_Reset->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->button_Reset->Location = System::Drawing::Point(9, 75);
			this->button_Reset->Name = L"button_Reset";
			this->button_Reset->Size = System::Drawing::Size(95, 31);
			this->button_Reset->TabIndex = 5;
			this->button_Reset->Text = L"张拉复位";
			this->button_Reset->UseVisualStyleBackColor = true;
			this->button_Reset->Click += gcnew System::EventHandler(this, &controlMachine::button_Reset_Click);
			// 
			// button_history
			// 
			this->button_history->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->button_history->Location = System::Drawing::Point(109, 6);
			this->button_history->Name = L"button_history";
			this->button_history->Size = System::Drawing::Size(95, 32);
			this->button_history->TabIndex = 4;
			this->button_history->Text = L"历史记录";
			this->button_history->UseVisualStyleBackColor = true;
			this->button_history->Click += gcnew System::EventHandler(this, &controlMachine::button_history_Click);
			// 
			// button_zhangLaParameter
			// 
			this->button_zhangLaParameter->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->button_zhangLaParameter->Location = System::Drawing::Point(109, 40);
			this->button_zhangLaParameter->Name = L"button_zhangLaParameter";
			this->button_zhangLaParameter->Size = System::Drawing::Size(95, 32);
			this->button_zhangLaParameter->TabIndex = 3;
			this->button_zhangLaParameter->Text = L"张拉参数";
			this->button_zhangLaParameter->UseVisualStyleBackColor = true;
			this->button_zhangLaParameter->Click += gcnew System::EventHandler(this, &controlMachine::button4_Click);
			// 
			// button_systemParameter
			// 
			this->button_systemParameter->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->button_systemParameter->Location = System::Drawing::Point(9, 40);
			this->button_systemParameter->Name = L"button_systemParameter";
			this->button_systemParameter->Size = System::Drawing::Size(95, 32);
			this->button_systemParameter->TabIndex = 2;
			this->button_systemParameter->Text = L"系统参数";
			this->button_systemParameter->UseVisualStyleBackColor = true;
			this->button_systemParameter->Click += gcnew System::EventHandler(this, &controlMachine::button_systemParameter_Click);
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Font = (gcnew System::Drawing::Font(L"宋体", 9));
			this->label22->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->label22->Location = System::Drawing::Point(13, 63);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(65, 12);
			this->label22->TabIndex = 10;
			this->label22->Text = L"伸长量校核";
			// 
			// panel6
			// 
			this->panel6->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel6->Controls->Add(this->label_percent);
			this->panel6->Controls->Add(this->progressBar_percent);
			this->panel6->Controls->Add(this->label_acture);
			this->panel6->Controls->Add(this->progressBar_theory);
			this->panel6->Controls->Add(this->label_theory);
			this->panel6->Location = System::Drawing::Point(11, 72);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(211, 94);
			this->panel6->TabIndex = 11;
			// 
			// label_percent
			// 
			this->label_percent->AutoSize = true;
			this->label_percent->Font = (gcnew System::Drawing::Font(L"宋体", 9));
			this->label_percent->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->label_percent->Location = System::Drawing::Point(151, 53);
			this->label_percent->Name = L"label_percent";
			this->label_percent->Size = System::Drawing::Size(41, 12);
			this->label_percent->TabIndex = 12;
			this->label_percent->Text = L"(0.0%)";
			// 
			// progressBar_percent
			// 
			this->progressBar_percent->Location = System::Drawing::Point(11, 69);
			this->progressBar_percent->Name = L"progressBar_percent";
			this->progressBar_percent->Size = System::Drawing::Size(178, 17);
			this->progressBar_percent->TabIndex = 14;
			// 
			// label_acture
			// 
			this->label_acture->AutoSize = true;
			this->label_acture->Font = (gcnew System::Drawing::Font(L"宋体", 9));
			this->label_acture->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label_acture->ImageAlign = System::Drawing::ContentAlignment::TopLeft;
			this->label_acture->Location = System::Drawing::Point(9, 50);
			this->label_acture->Name = L"label_acture";
			this->label_acture->Size = System::Drawing::Size(101, 12);
			this->label_acture->TabIndex = 13;
			this->label_acture->Text = L"实际伸长量0.0 mm";
			// 
			// progressBar_theory
			// 
			this->progressBar_theory->Location = System::Drawing::Point(12, 27);
			this->progressBar_theory->Maximum = 350;
			this->progressBar_theory->Name = L"progressBar_theory";
			this->progressBar_theory->Size = System::Drawing::Size(178, 17);
			this->progressBar_theory->TabIndex = 12;
			// 
			// label_theory
			// 
			this->label_theory->AutoSize = true;
			this->label_theory->Font = (gcnew System::Drawing::Font(L"宋体", 9));
			this->label_theory->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label_theory->Location = System::Drawing::Point(10, 8);
			this->label_theory->Name = L"label_theory";
			this->label_theory->Size = System::Drawing::Size(101, 12);
			this->label_theory->TabIndex = 11;
			this->label_theory->Text = L"理论伸长量0.0 mm";
			// 
			// but_startZhang
			// 
			this->but_startZhang->Enabled = false;
			this->but_startZhang->Font = (gcnew System::Drawing::Font(L"宋体", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->but_startZhang->ForeColor = System::Drawing::SystemColors::Desktop;
			this->but_startZhang->Location = System::Drawing::Point(27, 16);
			this->but_startZhang->Name = L"but_startZhang";
			this->but_startZhang->Size = System::Drawing::Size(174, 44);
			this->but_startZhang->TabIndex = 0;
			this->but_startZhang->Text = L"开 始 张 拉";
			this->but_startZhang->UseVisualStyleBackColor = true;
			this->but_startZhang->Click += gcnew System::EventHandler(this, &controlMachine::but_startZhang_Click);
			// 
			// label40
			// 
			this->label40->AutoSize = true;
			this->label40->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->label40->Location = System::Drawing::Point(27, 3);
			this->label40->Name = L"label40";
			this->label40->Size = System::Drawing::Size(47, 12);
			this->label40->TabIndex = 9;
			this->label40->Text = L"千斤顶1";
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->label27->Location = System::Drawing::Point(387, 3);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(47, 12);
			this->label27->TabIndex = 11;
			this->label27->Text = L"千斤顶2";
			// 
			// panel2
			// 
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel2->Controls->Add(this->label5);
			this->panel2->Controls->Add(this->label4);
			this->panel2->Controls->Add(this->panel8);
			this->panel2->Controls->Add(this->pictureBox_Mpa2);
			this->panel2->Controls->Add(this->pictureBox_MM2);
			this->panel2->Location = System::Drawing::Point(389, 12);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(370, 660);
			this->panel2->TabIndex = 10;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label5->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label5->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label5->Location = System::Drawing::Point(75, 389);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(268, 16);
			this->label5->TabIndex = 18;
			this->label5->Text = L"张拉仪2 位移曲线:( 毫米 - 秒 )";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label4->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label4->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label4->Location = System::Drawing::Point(75, 115);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(261, 16);
			this->label4->TabIndex = 18;
			this->label4->Text = L"张拉仪2 压力曲线:( Mpa - 秒 )";
			// 
			// panel8
			// 
			this->panel8->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel8->Controls->Add(this->pictureBox5);
			this->panel8->Controls->Add(this->textBox_d2Mpa_des);
			this->panel8->Controls->Add(this->pictureBox4);
			this->panel8->Controls->Add(this->label_d2mm);
			this->panel8->Controls->Add(this->label31);
			this->panel8->Controls->Add(this->label32);
			this->panel8->Controls->Add(this->label_outOil2);
			this->panel8->Controls->Add(this->label36);
			this->panel8->Controls->Add(this->label37);
			this->panel8->Controls->Add(this->label_d2Mpa);
			this->panel8->Controls->Add(this->label_d2KN);
			this->panel8->Controls->Add(this->label41);
			this->panel8->Controls->Add(this->label44);
			this->panel8->Controls->Add(this->label45);
			this->panel8->Location = System::Drawing::Point(3, 4);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(362, 102);
			this->panel8->TabIndex = 0;
			// 
			// pictureBox5
			// 
			this->pictureBox5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox5->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox5.Image")));
			this->pictureBox5->Location = System::Drawing::Point(218, 52);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(42, 42);
			this->pictureBox5->TabIndex = 18;
			this->pictureBox5->TabStop = false;
			// 
			// textBox_d2Mpa_des
			// 
			this->textBox_d2Mpa_des->Enabled = false;
			this->textBox_d2Mpa_des->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->textBox_d2Mpa_des->ForeColor = System::Drawing::Color::Red;
			this->textBox_d2Mpa_des->Location = System::Drawing::Point(40, 54);
			this->textBox_d2Mpa_des->Name = L"textBox_d2Mpa_des";
			this->textBox_d2Mpa_des->Size = System::Drawing::Size(53, 23);
			this->textBox_d2Mpa_des->TabIndex = 14;
			this->textBox_d2Mpa_des->Text = L"000.00";
			// 
			// pictureBox4
			// 
			this->pictureBox4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox4.Image")));
			this->pictureBox4->Location = System::Drawing::Point(219, 5);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(42, 42);
			this->pictureBox4->TabIndex = 17;
			this->pictureBox4->TabStop = false;
			// 
			// label_d2mm
			// 
			this->label_d2mm->BackColor = System::Drawing::SystemColors::ControlText;
			this->label_d2mm->Font = (gcnew System::Drawing::Font(L"宋体", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label_d2mm->ForeColor = System::Drawing::Color::Yellow;
			this->label_d2mm->Location = System::Drawing::Point(274, 54);
			this->label_d2mm->Name = L"label_d2mm";
			this->label_d2mm->Size = System::Drawing::Size(80, 25);
			this->label_d2mm->TabIndex = 12;
			this->label_d2mm->Text = L"000.0";
			this->label_d2mm->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label31
			// 
			this->label31->AutoSize = true;
			this->label31->Location = System::Drawing::Point(287, 30);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(41, 12);
			this->label31->TabIndex = 11;
			this->label31->Text = L"( mm )";
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label32->Location = System::Drawing::Point(288, 15);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(37, 14);
			this->label32->TabIndex = 10;
			this->label32->Text = L"位移";
			// 
			// label_outOil2
			// 
			this->label_outOil2->AutoSize = true;
			this->label_outOil2->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label_outOil2->Location = System::Drawing::Point(175, 60);
			this->label_outOil2->Name = L"label_outOil2";
			this->label_outOil2->Size = System::Drawing::Size(37, 14);
			this->label_outOil2->TabIndex = 7;
			this->label_outOil2->Text = L"退油";
			// 
			// label36
			// 
			this->label36->AutoSize = true;
			this->label36->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label36->Location = System::Drawing::Point(176, 20);
			this->label36->Name = L"label36";
			this->label36->Size = System::Drawing::Size(37, 14);
			this->label36->TabIndex = 6;
			this->label36->Text = L"进油";
			// 
			// label37
			// 
			this->label37->AutoSize = true;
			this->label37->Location = System::Drawing::Point(-1, 75);
			this->label37->Name = L"label37";
			this->label37->Size = System::Drawing::Size(41, 12);
			this->label37->TabIndex = 5;
			this->label37->Text = L"(M Pa)";
			// 
			// label_d2Mpa
			// 
			this->label_d2Mpa->BackColor = System::Drawing::SystemColors::ControlText;
			this->label_d2Mpa->Font = (gcnew System::Drawing::Font(L"宋体", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label_d2Mpa->ForeColor = System::Drawing::Color::Yellow;
			this->label_d2Mpa->Location = System::Drawing::Point(94, 53);
			this->label_d2Mpa->Name = L"label_d2Mpa";
			this->label_d2Mpa->Size = System::Drawing::Size(80, 25);
			this->label_d2Mpa->TabIndex = 4;
			this->label_d2Mpa->Text = L"000.00";
			this->label_d2Mpa->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_d2KN
			// 
			this->label_d2KN->BackColor = System::Drawing::SystemColors::ControlText;
			this->label_d2KN->Font = (gcnew System::Drawing::Font(L"宋体", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label_d2KN->ForeColor = System::Drawing::Color::Yellow;
			this->label_d2KN->Location = System::Drawing::Point(42, 5);
			this->label_d2KN->Name = L"label_d2KN";
			this->label_d2KN->Size = System::Drawing::Size(127, 35);
			this->label_d2KN->TabIndex = 3;
			this->label_d2KN->Text = L"00000.0";
			this->label_d2KN->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label41
			// 
			this->label41->AutoSize = true;
			this->label41->Font = (gcnew System::Drawing::Font(L"宋体", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label41->ForeColor = System::Drawing::Color::Red;
			this->label41->Location = System::Drawing::Point(-2, 56);
			this->label41->Name = L"label41";
			this->label41->Size = System::Drawing::Size(44, 12);
			this->label41->TabIndex = 2;
			this->label41->Text = L"目标值";
			// 
			// label44
			// 
			this->label44->AutoSize = true;
			this->label44->Location = System::Drawing::Point(1, 30);
			this->label44->Name = L"label44";
			this->label44->Size = System::Drawing::Size(35, 12);
			this->label44->TabIndex = 1;
			this->label44->Text = L"(k N)";
			// 
			// label45
			// 
			this->label45->AutoSize = true;
			this->label45->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label45->Location = System::Drawing::Point(-1, 9);
			this->label45->Name = L"label45";
			this->label45->Size = System::Drawing::Size(37, 14);
			this->label45->TabIndex = 0;
			this->label45->Text = L"力值";
			// 
			// pictureBox_Mpa2
			// 
			this->pictureBox_Mpa2->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->pictureBox_Mpa2->Location = System::Drawing::Point(10, 112);
			this->pictureBox_Mpa2->Name = L"pictureBox_Mpa2";
			this->pictureBox_Mpa2->Size = System::Drawing::Size(350, 264);
			this->pictureBox_Mpa2->TabIndex = 19;
			this->pictureBox_Mpa2->TabStop = false;
			this->pictureBox_Mpa2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &controlMachine::pictureBox_Mpa2_Paint);
			// 
			// pictureBox_MM2
			// 
			this->pictureBox_MM2->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->pictureBox_MM2->Location = System::Drawing::Point(9, 385);
			this->pictureBox_MM2->Name = L"pictureBox_MM2";
			this->pictureBox_MM2->Size = System::Drawing::Size(350, 264);
			this->pictureBox_MM2->TabIndex = 20;
			this->pictureBox_MM2->TabStop = false;
			this->pictureBox_MM2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &controlMachine::pictureBox_MM2_Paint);
			// 
			// timer1
			// 
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &controlMachine::timer1_Tick);
			// 
			// controlMachine
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1016, 702);
			this->Controls->Add(this->label27);
			this->Controls->Add(this->label40);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->panel5);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->linkLabel1);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->panel2);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->KeyPreview = true;
			this->Name = L"controlMachine";
			this->Text = L"湖南聚创  -  预应力智能张拉控制系统";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->MinimumSizeChanged += gcnew System::EventHandler(this, &controlMachine::controlMachine_MinimumSizeChanged);
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &controlMachine::controlMachine_FormClosing);
			this->Load += gcnew System::EventHandler(this, &controlMachine::controlMachine_Load);
			this->Shown += gcnew System::EventHandler(this, &controlMachine::controlMachine_Shown);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &controlMachine::controlMachine_KeyDown);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel11->ResumeLayout(false);
			this->panel11->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox_Mpa1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox_MM1))->EndInit();
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->panel5->ResumeLayout(false);
			this->panel5->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->panel7->ResumeLayout(false);
			this->panel6->ResumeLayout(false);
			this->panel6->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel8->ResumeLayout(false);
			this->panel8->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox_Mpa2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox_MM2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button_systemParameter_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->timer1->Enabled = false;
				 m_systemSet.StartPosition =FormStartPosition::CenterParent ;
				 m_systemSet.ShowDialog();
				 if( connectStatus == true ) {
					 this->p_comBase->gRInit = 1;
					 this->p_comBase->gOpcOperation = WRITE_OPC;
					 this->p_comBase->gOpcDataId  = IDW_OTHER;
					 ReleaseSemaphore( this->p_comBase->semaphore,1,NULL);
				 }
				 this->timer1->Enabled = true;
				 // writeInitData( 0 );
			 }

	private: System::Void controlMachine_Load(System::Object^  sender, System::EventArgs^  e) {

				 //this->str_holeInfo
			 }
	private: System::Void butt_startTest_Click(System::Object^  sender, System::EventArgs^  e) {
				 debugStatus = !debugStatus;

				 //this->butt_handle->Enabled = debugStatus;
			 }
	private: System::Void butt_handle_Click(System::Object^  sender, System::EventArgs^  e) {
				if(  connectStatus != true ) {
					 MessageBox::Show("PLC连接断开，请先点击 [连接设备] 按钮!");
					 return;
				 }
				 m_handleMach.StartPosition =FormStartPosition::CenterParent ;
				 bShowHandMach = true;

				 this->label_outOil1->Text = L"回油";
				 this->label_outOil2->Text = L"回油";
				 //		 this->timer1->Enabled = false;
				 m_handleMach.ShowDialog(this );
				 bShowHandMach = false;
				 this->label_outOil1->Text = L"退油";
				 this->label_outOil2->Text = L"退油";

				 //		 this->timer1->Enabled = true;
			 }
	private: System::String ^   Round_float(float   number,   int   bit)  
			 {  
				 //	 System::String ^  s =  System::Convert::ToString( number );  
				 //	 System::String ^  s1 = System::Convert::ToString( bit ) ;
				 char a[20];
				 if( bit == 1)
					 snprintf(a, 6, "%.1f", number);
				 else
					 snprintf(a, 6, "%.2f", number);
				 System::String ^  s = Marshal::PtrToStringAnsi((IntPtr)a);

				 return  s;  

			 }

			 //200 ms
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
				 DateTime GetDateTimeInfo = DateTime::Now;
				 float tempData1,tempData2,tempData3,tempData4;
				 //this->button_Reset->Enabled=true;
				 try {
					 if( connectStatus  )
						 if( this->toolStripProgressBar1->Value  + 10 <= 100 )
							 this->toolStripProgressBar1->Value = this->toolStripProgressBar1->Value  + 10;
						 else
							 this->toolStripProgressBar1->Value = 0;
					 // timeTickCount = timeTickCount + 1;


					 isCommunicationOK();

					 // if( timeTickCount % 5 == 0)  //发送随机数
					 
						 if( bShowed && ( bDataInit == 0)){
							 this->p_comBase = this->m_handleMach.p_comBase;
							 this->m_systemSet.p_comBase = this->m_handleMach.p_comBase;
							 bDataInit = this->p_comBase->combase_Init();
							 if( bDataInit ) {
								 InitOpcWriteData();
							 }
						 }

						 try{

							 if( machine1Oil == OIL_IN ) {
								 this->pictureBox2->Image = Image::FromFile(  System::AppDomain::CurrentDomain->BaseDirectory->ToString() + L"\\Resources\\"+ L"in.JPG");
								 this->pictureBox3->Image = Image::FromFile(  System::AppDomain::CurrentDomain->BaseDirectory->ToString() + L"\\Resources\\"+ L"idle.JPG");
								 //this->label_d1mm->Text= Round_float(System::Convert::ToSingle(this->p_comBase->opcReadData[4]->DataValue)-startZhangLaMm1,1);
							 }
							 else if ( machine1Oil == OIL_OUT) {
								 String^ picPath =  System::AppDomain::CurrentDomain->BaseDirectory->ToString() + L"\\Resources\\"+ L"out.JPG";
								 this->pictureBox2->Image = Image::FromFile(  System::AppDomain::CurrentDomain->BaseDirectory->ToString() + L"\\Resources\\"+ L"idle.JPG");
								 this->pictureBox3->Image = Image::FromFile( picPath );
								 //this->label_d1mm->Text= Round_float(System::Convert::ToSingle(this->p_comBase->opcReadData[4]->DataValue),1);
								 //this->but_startZhang->Enabled = false;
							 }
							 else if ( machine1Oil == OIL_ERR) {
								 this->pictureBox2->Image = Image::FromFile(  System::AppDomain::CurrentDomain->BaseDirectory->ToString() + L"\\Resources\\"+ L"idle.JPG");
								 this->pictureBox3->Image = Image::FromFile(  System::AppDomain::CurrentDomain->BaseDirectory->ToString() + L"\\Resources\\"+ L"idle.JPG");
							 }
							 else if ( machine1Oil == OIL_IDLE) {
								 this->pictureBox2->Image = Image::FromFile(  System::AppDomain::CurrentDomain->BaseDirectory->ToString() + L"\\Resources\\"+ L"idle.JPG");
								 this->pictureBox3->Image = Image::FromFile(  System::AppDomain::CurrentDomain->BaseDirectory->ToString() + L"\\Resources\\"+ L"idle.JPG");
							 }

							 if( machine2Oil == OIL_IN ) {
								 this->pictureBox4->Image = Image::FromFile(  System::AppDomain::CurrentDomain->BaseDirectory->ToString() + L"\\Resources\\"+ L"in.JPG");
								 this->pictureBox5->Image = Image::FromFile(  System::AppDomain::CurrentDomain->BaseDirectory->ToString() + L"\\Resources\\"+ L"idle.JPG");
							 }
							 else if ( machine2Oil == OIL_OUT) {
								 String^ picPath =  System::AppDomain::CurrentDomain->BaseDirectory->ToString() + L"\\Resources\\"+ L"out.JPG";

								 this->pictureBox4->Image = Image::FromFile(  System::AppDomain::CurrentDomain->BaseDirectory->ToString() + L"\\Resources\\"+ L"idle.JPG");
								 this->pictureBox5->Image = Image::FromFile(  picPath );
								// this->but_startZhang->Enabled = false;
							 }
							 else if ( machine2Oil == OIL_ERR) {
								 this->pictureBox4->Image = Image::FromFile(  System::AppDomain::CurrentDomain->BaseDirectory->ToString() + L"\\Resources\\"+ L"idle.JPG");
								 this->pictureBox5->Image = Image::FromFile(  System::AppDomain::CurrentDomain->BaseDirectory->ToString() + L"\\Resources\\"+ L"idle.JPG");
							 }
							 else if ( machine2Oil == OIL_IDLE) {
								 this->pictureBox4->Image = Image::FromFile(  System::AppDomain::CurrentDomain->BaseDirectory->ToString() + L"\\Resources\\"+ L"idle.JPG");
								 this->pictureBox5->Image = Image::FromFile(  System::AppDomain::CurrentDomain->BaseDirectory->ToString() + L"\\Resources\\"+ L"idle.JPG");
							 }
							 if( ( machine1Oil == OIL_IDLE) && ( machine2Oil == OIL_IDLE) )
								 this->but_startZhang->Enabled = true;
						 }
						 catch( Exception ^ ex){
						 }

						 if (ZhangLaStatus == ZHANGLA_RUN) {
							 this->button_systemParameter->Enabled = false;
							 this->butt_handle->Enabled = false;
							 this->btn_single->Enabled=false;
							 this->but_startZhang->Text = L"暂 停 张 拉";
							 //	this->label_CountDown->Text  = System::Convert::ToString( absReadOpcIndex/5)+" S";

							 /*	if( absReadOpcIndex > GRAPH_X_NUM ) 
							 this->panel1->Refresh(); */
							 //Invalidate( ); 
							 this->pictureBox_MM1->Invalidate();
							 this->pictureBox_Mpa1->Invalidate();
							 this->pictureBox_MM2->Invalidate();
							 this->pictureBox_Mpa2->Invalidate();

							 if( startZhangLaMm1 < 0.001 )
								 try{
									 startZhangLaMm1 = System::Convert::ToSingle ( this->label_d1mm->Text) ;
							 }
							 catch(Exception ^ ex) {
								 startZhangLaMm1 = 0.001;
							 }
							 if( startZhangLaMm2 < 0.001 )
								 try{
									 startZhangLaMm2 = System::Convert::ToSingle ( this->label_d2mm->Text) ;
							 }
							 catch(Exception ^ ex) {
								 startZhangLaMm2 = 0.001;
							 } 
						 }
						 else  if( ZhangLaStatus == ZHANGLA_IDLE )  {
							 this->but_startZhang->Text = L"开 始 张 拉";
							 this->button_systemParameter->Enabled = true;
							 this->butt_handle->Enabled = true;
							 this->button_history->Enabled = true;
							 this->btn_single->Enabled=true;
							 
							 
							 startZhangLaMm1 = 0;
							 startZhangLaMm2 = 0;
						 }
						 else if( ZhangLaStatus == ZHANGLA_PAUSE ) {
							 this->but_startZhang->Text = L"继 续 张 拉";
							 this->button_systemParameter->Enabled = true;
							 this->butt_handle->Enabled = true;
							 this->button_history->Enabled = true;
							 this->btn_single->Enabled=true;
							 /*static System::Windows::Forms::DialogResult  r1;
							 if(!(trueData(38)&&trueData(SINGLE_OPC_NUM+38))&&trueData(13) && trueData(SINGLE_OPC_NUM + 13))
							 {
							 if(kong_over==false){
							 kong_over=true;
							 r1	=  MessageBox::Show(this->str_ShunXunInfo[konghao_over]+"张拉完成","张拉完成", MessageBoxButtons::OK);
							 if( r1 == System::Windows::Forms::DialogResult::OK){
							 if(CurzhangLaSeq+1<zhangLaCount)
							 CurzhangLaSeq++;
							 this->listBox1->SelectedIndex=CurzhangLaSeq;
							 konghao_over++;
							 this->label_d1mm->Text=Round_float(System::Convert::ToSingle( this->p_comBase->opcReadData[ 4]->DataValue ),1);
							 this->label_d2mm->Text=Round_float(System::Convert::ToSingle( this->p_comBase->opcReadData[SINGLE_OPC_NUM + 4]->DataValue ),1);
							 }
							 }
							 }*/
						 }
						 else if( ZhangLaStatus == ZHANGLA_TRYPAUSE ) {
							 if( falseData( 1 ) || falseData( 2 ))  {
								 ZhangLaStatus = ZHANGLA_PAUSE;
								 this->butt_handle->Enabled = true;
								 this->button_history->Enabled = true;
							 }
							 else if( retryCount++ > 15 ) {
								 this->listBox2->Items->Add("");
								 this->listBox2->SelectedIndex = listBox2Index ;
								 this->listBox2->Items[listBox2Index++] = "PLC张拉出错,不能暂停张拉!";
								 retryCount = 0;
								 ZhangLaStatus = ZHANGLA_RUN;
							 }
						 }
						 else if( ZhangLaStatus == ZHANGLA_TRYRUN) {
							 if (Single_Zhangla)
							 {
								if(trueDataZh(1))
								 ZhangLaStatus = ZHANGLA_RUN;
							 }
							 else
							 {
							 if( trueDataZh(1) && trueDataZh(2)) {
								 ZhangLaStatus = ZHANGLA_RUN;
								 this->button_history->Enabled = false;
							 }
							 }
							 if( retryCount++ > 15 ) {
								 retryCount = 0;
								 this->listBox2->Items->Add("");
								 this->listBox2->SelectedIndex = listBox2Index ;
								 this->listBox2->Items[listBox2Index++] = "PLC张拉出错,不能启动张拉!";
								 //ZhangLaStatus=ZHANGLA_RUN;
								 ZhangLaStatus = ZHANGLA_IDLE;
							 }
						 }


						 if(  (connectStatus == false) && (ZhangLaStatus == ZHANGLA_RUN) ){
							 ZhangLaStatus = ZHANGLA_PAUSE ;
							 this->but_startZhang->Text = L"继 续 张 拉";
						 }
					 
					 machine1Oil = OIL_IDLE;
					 machine2Oil = OIL_IDLE;
					 
					 if(  (connectStatus == true) ){  //张拉状态，查询数据  (ZhangLaStatus == ZHANGLA_RUN)
						/* ButtonPressed = trueData( 36) << 1 + trueData( SINGLE_OPC_NUM + 36 ) ;
						 if(ButtonPressed_d != ButtonPressed ) {
							 this->listBox2->Items->Add("");
							 if( ButtonPressed > 0) {
								 if( trueData( 36) && trueData( SINGLE_OPC_NUM + 36 ) )
									 this->listBox2->Items[listBox2Index++] = "主机、从机 系统暂停 按钮已按下!";
								 else if ( controlMachine::trueData( 36) )
									 this->listBox2->Items[listBox2Index++] = "主机 系统暂停 按钮已按下!";
								 else if ( controlMachine::trueData( SINGLE_OPC_NUM + 36) )
									 this->listBox2->Items[listBox2Index++] = "从机 系统暂停 按钮已按下!";
							 }
							 else
								 this->listBox2->Items[listBox2Index++] = "系统暂停 按钮已复位!";
							 ButtonPressed_d = ButtonPressed;
						 }*/
						 //WriteLastSet();
						 if (trueData(36)||trueData(SINGLE_OPC_NUM+36)&&(!system_pause1||!system_pause2))
						 {
							 
							 if ( controlMachine::trueData( 36)&& !pause_show1 ){
								 this->listBox2->Items->Add("");
								 this->listBox2->Items[listBox2Index++] = "主机 系统暂停 按钮已按下!";
								 this->listBox2->SelectedIndex++;
								 system_pause1=1;
								 pause_show1=1;
							 }
							 else if ( controlMachine::trueData( SINGLE_OPC_NUM + 36) && !pause_show2){
								 this->listBox2->Items->Add("");
								 this->listBox2->Items[listBox2Index++] = "从机 系统暂停 按钮已按下!";
								 this->listBox2->SelectedIndex++;
								 system_pause2=1;
								 pause_show2=1;
							 }
						 }
						 else if (system_pause1)
						 {
							 this->listBox2->Items->Add("");
							 if(!trueData(36)){
								 this->listBox2->Items[listBox2Index++] = "主机 系统暂停 按钮已复位!";
								 this->listBox2->SelectedIndex++;
								 system_pause1=0;
								 pause_show1=0;
							 }
						 }
						 else if(system_pause2)
						 {
							 this->listBox2->Items->Add("");
							 if(!trueData(SINGLE_OPC_NUM+36)){
								 this->listBox2->Items[listBox2Index++] = "从机 系统暂停 按钮已复位!";
								 this->listBox2->SelectedIndex++;
								 system_pause2=0;
								 pause_show2=0;
							 }
						 }
						 
#ifndef debug_noMachine2 
					//if(  (connectStatus == true) )
					
							 //if( timeTickCount % 5 != 0) 
							 
								 this->p_comBase->gRInit = 0;
								 this->p_comBase->gOpcOperation = READ_OPC;
								 this->p_comBase->gOpcDataId    = IDR_OTHER;  
								 this->p_comBase->gOpcDataId   |= IDR_START1;
								 if(!Single_Zhangla)
								 this->p_comBase->gOpcDataId   |= IDR_START2;
								 
								 SendRandomData(  );

								 ReleaseSemaphore( this->p_comBase->semaphore,1,NULL);

							 
							 //	else 
							 //if(p_comBase->opcReadData!=nullptr)
							   //降低界面刷新率

								 if(this->p_comBase->opcReadData[4]->Quality  == 192) { //位移
									  //(int )(System::Convert::ToSingle( this->p_comBase->opcReadData[4]->DataValue ) * 10 ) / 10.0;
									 
									 tempData1 =   System::Convert::ToSingle( this->p_comBase->opcReadData[4]->DataValue )- startZhangLaMm1 ;
									 if( tempData1  < 0 )
										 tempData1 = 0;
										this->label_d1mm->Text =  Round_float( tempData1,1 );
								 }

								 if(this->p_comBase->opcReadData[5]->Quality  == 192){ //油压
									 tempData2 =  System::Convert::ToSingle( this->p_comBase->opcReadData[5]->DataValue );
									 //if( timeTickCount % 5 == 0) 
									 this->label_d1Mpa->Text = Round_float( tempData2 ,2);
								 }

								 if(this->p_comBase->opcReadData[SINGLE_OPC_NUM + 4]->Quality  == 192) { //位移
									 tempData3 =  System::Convert::ToSingle( this->p_comBase->opcReadData[SINGLE_OPC_NUM + 4]->DataValue ) - startZhangLaMm2 ;
									 if( tempData3  < 0 )
										 tempData3 = 0;
									this->label_d2mm->Text = Round_float (tempData3 ,1);
										
								 }

								 if(this->p_comBase->opcReadData[SINGLE_OPC_NUM + 5]->Quality  == 192){ //油压
									 tempData4 = System::Convert::ToSingle( this->p_comBase->opcReadData[SINGLE_OPC_NUM + 5]->DataValue ) ;
									 //if( timeTickCount % 5 == 0) 
									 this->label_d2Mpa->Text = Round_float( tempData4 ,2);
								 }


								 if(ZhangLaStatus == ZHANGLA_RUN)		{
									 if(this->p_comBase->opcReadData[4]->Quality  == 192) { //位移
										 drawData[absReadOpcIndex].Mm = tempData1;
										 latestDefaultMm = drawData[absReadOpcIndex].Mm;
									 }
									 else
										 drawData[absReadOpcIndex].Mm = latestDefaultMm+startZhangLaMm1;

									 if(this->p_comBase->opcReadData[5]->Quality  == 192){ //油压
										 drawData[absReadOpcIndex].Mpa = tempData2;
										 latestDefaultMpa = drawData[absReadOpcIndex].Mpa;
									 }
									 else
										 drawData[absReadOpcIndex].Mpa = latestDefaultMpa;

									 if(this->p_comBase->opcReadData[SINGLE_OPC_NUM + 4]->Quality  == 192) { //位移
										 drawData[absReadOpcIndex].Mm2 = tempData3;
										 latestDefaultMm2 = drawData[absReadOpcIndex].Mm2;
									 }
									 else
										 drawData[absReadOpcIndex].Mm2 = latestDefaultMm2;
										 
									 if(this->p_comBase->opcReadData[SINGLE_OPC_NUM + 5]->Quality  == 192){ //油压
										 drawData[absReadOpcIndex].Mpa2 = tempData4;
										 latestDefaultMpa2 = drawData[absReadOpcIndex].Mpa2;
									 }
									 else
										 drawData[absReadOpcIndex].Mpa2 = latestDefaultMpa2;
										 
									 if( trueData(6) && !(listBox2Noticed & 1) ){
										 this->listBox2->Items->Add("");
										 listBox2Noticed = listBox2Noticed | 1;

										 this->listBox2->Items[listBox2Index++] = GetDateTimeInfo.ToLongTimeString() + " 主机 第一行程结束";

									 }
									 if( trueData( SINGLE_OPC_NUM + 6) && !(listBox2Noticed & 2) ){
										 listBox2Noticed = listBox2Noticed | 0x2;
										 this->listBox2->Items->Add("");

										 this->listBox2->Items[listBox2Index++] = GetDateTimeInfo.ToLongTimeString() + " 从机 第一行程结束"	;
									 }
									 if( (listBox2Noticed & 2) || (listBox2Noticed & 1) ) {
										 this->label_CountDown_notice->Enabled = true;
										 this->label_CountDown->Enabled = true;
										 if(this->p_comBase->opcReadData[1]->Quality  == 192) //保压合格时间  
											 latestCountDown = System::Convert::ToSingle( this->p_comBase->opcReadData[1]->DataValue->ToString() );
										 this->label_CountDown->Text  = System::Convert::ToString( latestCountDown );
										 if(System::Convert::ToSingle( this->p_comBase->opcReadData[1]->DataValue->ToString() )==1)
											 this->label_CountDown->Text = L"0 S";
									 }

									 if( trueData(7)  && !(listBox2Noticed & 0x4)) {
										 listBox2Noticed = listBox2Noticed | 0x4;

										 this->listBox2->Items->Add("");
										 this->listBox2->Items[listBox2Index++] =  GetDateTimeInfo.ToLongTimeString() +  " 第一行程进油" ;
									 }
									 if( trueData(8)  && !(listBox2Noticed & 0x8)) {
										 listBox2Noticed = listBox2Noticed | 0x8;

										 this->listBox2->Items->Add("");
										 this->listBox2->Items[listBox2Index++] =  GetDateTimeInfo.ToLongTimeString() +  " 主机 第二行程结束";
									 }
									 if( trueData(  SINGLE_OPC_NUM + 8)  && !(listBox2Noticed & 0x10 )) {
										 listBox2Noticed = listBox2Noticed | 0x10;
										 this->listBox2->Items->Add("");
										 this->listBox2->Items[listBox2Index++] =  GetDateTimeInfo.ToLongTimeString() +  " 从机 第二行程结束";

									 }
									 if( (listBox2Noticed & 8) || (listBox2Noticed & 0x10) ) {
										 this->label_CountDown_notice->Enabled = true;
										 this->label_CountDown->Enabled = true;
										 if(this->p_comBase->opcReadData[1]->Quality  == 192) //保压合格时间  
											 latestCountDown = System::Convert::ToSingle( this->p_comBase->opcReadData[1]->DataValue->ToString() );
										 this->label_CountDown->Text  = System::Convert::ToString(  latestCountDown );
										 if(System::Convert::ToSingle( this->p_comBase->opcReadData[1]->DataValue->ToString() )==1)
											 this->label_CountDown->Text = L"0 S";
									 }
									 if( trueData(9) && !(listBox2Noticed & 0x20) ) {
										 this->label_CountDown_notice->Enabled = false;
										 this->label_CountDown->Enabled = false;
										 listBox2Noticed = listBox2Noticed | 0x20;
										 curXingCheng = 1;
										 this->listBox2->Items->Add("");
										 this->listBox2->Items[listBox2Index++] =  GetDateTimeInfo.ToLongTimeString() +  " 第二行程进油" ;

									 }
									 checkBox_lenth->Enabled = listBox2Noticed & 0x20;

									 if( trueData(10) && !(listBox2Noticed & 0x40) ) {
										 listBox2Noticed = listBox2Noticed | 0x40;
										 this->listBox2->Items->Add("");
										 this->listBox2->Items[listBox2Index++] =  GetDateTimeInfo.ToLongTimeString() +  " 主机 第三行程结束";

									 }

									 if( trueData( SINGLE_OPC_NUM + 10) && !(listBox2Noticed & 0x80) ) {
										 listBox2Noticed = listBox2Noticed | 0x80;
										 this->listBox2->Items->Add("");
										 this->listBox2->Items[listBox2Index++] =  GetDateTimeInfo.ToLongTimeString() +  " 从机 第三行程结束";
									 }
									 if( curXingCheng < 3 ) {
										 accLen[ CurzhangLaSeq * 3 + curXingCheng] = latestDefaultMm;
										 accMpa[ CurzhangLaSeq * 3 + curXingCheng] = latestDefaultMpa;
										 accLen2[ CurzhangLaSeq * 3 + curXingCheng] = latestDefaultMm2;
										 accMpa2[ CurzhangLaSeq * 3 + curXingCheng] = latestDefaultMpa2;
									 }

									 if( trueData(11)  && !(listBox2Noticed & 0x100)) {
										 this->label_CountDown_notice->Enabled = false;
										 this->label_CountDown->Enabled = false;
										 listBox2Noticed = listBox2Noticed | 0x100;
										 curXingCheng = 2;
										 this->listBox2->Items->Add("");
										 this->listBox2->Items[listBox2Index++] =   GetDateTimeInfo.ToLongTimeString() + " 第三行程进油" ;

									 }
									 if( ( trueData( 36 ) ||  trueData(SINGLE_OPC_NUM +  36 )  )&& !(listBox2Noticed & 0x200) ) {
										 listBox2Noticed = listBox2Noticed | 0x200;

										 this->listBox2->Items->Add("");
										 if( trueData( 36 ) )
											 this->listBox2->Items[listBox2Index] =  GetDateTimeInfo.ToLongTimeString() + " 主机暂停" ;
										 if( trueData(SINGLE_OPC_NUM +  36 )  )
											 this->listBox2->Items[listBox2Index] = this->listBox2->Items[listBox2Index] + GetDateTimeInfo.ToLongTimeString() + " 从机暂停" ;
										 listBox2Index ++;
									 }
									 

									 if( ( trueData(13) && trueData(SINGLE_OPC_NUM + 13)) && !(listBox2Noticed & 0x800) ) { //保压完成

										 listBox2Noticed = listBox2Noticed | 0x800;


										 this->listBox2->Items->Add("");
										 this->listBox2->Items[listBox2Index++] =  GetDateTimeInfo.ToLongTimeString() +  " 顶1、2 保压完成" ;

									 }	
									 if( ( trueData(13) || trueData(SINGLE_OPC_NUM + 13) ) && !bGenExcel && ((listBox2Noticed & 0x40) || (listBox2Noticed & 0x80) || (listBox2Noticed & 0x10 ) || (listBox2Noticed & 0x8)) && ( CurzhangLaSeq + 1 >= zhangLaCount )) {  //( CurzhangLaSeq + 1 >= zhangLaCount ) && 
										
										 ExcelReport();
										 bGenExcel=1;
									 }

									 if( checkBox_lenth->Enabled && checkBox_lenth->Checked )
										 calcCurExtend(CurzhangLaSeq,1  );
									 if( trueData(12)  && !(listBox2Noticed & 0x1000)) {
										 listBox2Noticed = listBox2Noticed | 0x1000;

										 this->listBox2->Items->Add("");
										 this->listBox2->Items[listBox2Index++] =  GetDateTimeInfo.ToLongTimeString() + " 进入保压" ;

										 this->label_CountDown_notice->Text = L"持荷倒计时：";
									 }

									 if( listBox2Noticed & 0x1000) {
										 this->label_CountDown_notice->Enabled = true;
										 this->label_CountDown->Enabled = true;
										 if(this->p_comBase->opcReadData[1]->Quality  == 192) //保压合格时间  
											 latestCountDown = System::Convert::ToSingle( this->p_comBase->opcReadData[1]->DataValue->ToString() );
										 this->label_CountDown->Text  = System::Convert::ToString(  latestCountDown );
										 if(System::Convert::ToSingle( this->p_comBase->opcReadData[1]->DataValue->ToString() )==1)
											 this->label_CountDown->Text = L"0 S";
										 if( latestCountDown < 5 )//lg
											 curXingCheng = 3;
										 /*	if( (latestCountDown >= 298 ) && !bGenExcel) {  //( CurzhangLaSeq + 1 >= zhangLaCount ) && 
										 bGenExcel = 1;
										 ExcelReport();
										 }*/
									 }

									 if(  trueData( 32 )   && !(listBox2Noticed & 0x2000)) {
										 listBox2Noticed = listBox2Noticed | 0x2000;

										 this->listBox2->Items->Add("");

										 this->listBox2->Items[listBox2Index++] =  GetDateTimeInfo.ToLongTimeString() + " 主机 压力传感器异常" ;

										 this->p_comBase->opcWriteDataParameter[0]=false;
										 this->p_comBase->opcWriteDataParameter2[0]=false;
										 this->p_comBase->gRInit = 0;
										 this->p_comBase->gOpcOperation = WRITE_OPC;
										 this->p_comBase->gOpcDataId   = IDW_OTHER;
										 ReleaseSemaphore(this->p_comBase->semaphore,1,NULL);

										 ZhangLaStatus=ZHANGLA_PAUSE;
										 MessageBox::Show("主机压力传感器异常,请排除故障后,点击继续张拉!");
									 }
									 if(  trueData( 33 )  && !(listBox2Noticed & 0x4000)) {
										 listBox2Noticed = listBox2Noticed | 0x4000;

										 this->listBox2->Items->Add("");

										 this->listBox2->Items[listBox2Index++] =  GetDateTimeInfo.ToLongTimeString() + " 主机 位移传感器异常" ;

										 this->p_comBase->opcWriteDataParameter[0]=false;
										 this->p_comBase->opcWriteDataParameter2[0]=false;
										 ReleaseSemaphore(this->p_comBase->semaphore,1,NULL);

										 ZhangLaStatus=ZHANGLA_PAUSE;
										 MessageBox::Show("主机位移传感器异常,请排除故障后,点击继续张拉!");
									 }
									 if(  trueData(SINGLE_OPC_NUM + 32)  && !(listBox2Noticed & 0x8000)&&(Single_Zhangla==false)) {
										 listBox2Noticed = listBox2Noticed | 0x8000;

										 this->listBox2->Items->Add("");

										 this->listBox2->Items[listBox2Index++] =  GetDateTimeInfo.ToLongTimeString() + " 从机 压力传感器异常" ;

										 this->p_comBase->opcWriteDataParameter[0]=false;
										 this->p_comBase->opcWriteDataParameter2[0]=false;
										 ReleaseSemaphore(this->p_comBase->semaphore,1,NULL);

										 ZhangLaStatus=ZHANGLA_PAUSE;
										 MessageBox::Show("从机压力传感器异常,请排除故障后,点击继续张拉!");
									 }
									 if(  trueData(SINGLE_OPC_NUM + 33)  && !(listBox2Noticed & 0x10000)&&(Single_Zhangla==false)) {
										 listBox2Noticed = listBox2Noticed | 0x10000;

										 this->listBox2->Items->Add("");

										 this->listBox2->Items[listBox2Index++] =  GetDateTimeInfo.ToLongTimeString() + " 从机 位移传感器异常" ;

										 this->p_comBase->opcWriteDataParameter[0]=false;
										 this->p_comBase->opcWriteDataParameter2[0]=false;
										 ReleaseSemaphore(this->p_comBase->semaphore,1,NULL);

										 ZhangLaStatus=ZHANGLA_PAUSE;
										 MessageBox::Show("从机位移传感器异常,请排除故障后,点击继续张拉!");
									 }

									 if( ((listBox2Noticed & 0x800) ) && latestDefaultMpa < 1 && latestDefaultMpa2 < 1){//&&!(trueData(38)&&trueData(SINGLE_OPC_NUM+38)) ){
										// if( CurzhangLaSeq + 1 < zhangLaCount ) {
										//machine1Oil=OIL_OUT;
										//machine2Oil=OIL_OUT;
											 static System::Windows::Forms::DialogResult  r1;
											 if(!trueData(38)&& !trueData(SINGLE_OPC_NUM+38))//&&!this->p_comBase->opcWriteDataParameter[0] && !this->p_comBase->opcWriteDataParameter2[0])
											 {
												 if(kong_over==false&&!trueData(23)&&!trueData(SINGLE_OPC_NUM+23)){
													 kong_over=true;
													 r1	=  MessageBox::Show(this->str_ShunXunInfo[konghao_over]+"张拉完成","张拉完成", MessageBoxButtons::OK);
													 if( r1 == System::Windows::Forms::DialogResult::OK){
														 if(CurzhangLaSeq+1<zhangLaCount)
															 CurzhangLaSeq++;
														 this->listBox1->SelectedIndex=CurzhangLaSeq;
														 this->label_d1Mpa->Text=L"0.00";
														 this->label_d2Mpa->Text=L"0.00";
														 konghao_over++;
														 //if(CurzhangLaSeq+1>=zhangLaCount)
														 //ExcelReport();
														 ZhangLaStatus = ZHANGLA_IDLE;
													 }
												 }
											 }
										// }
										/* else {
											 
											 //ZhangLaStatus = ZHANGLA_IDLE;
										 }*/
										 saveDrawData(absReadOpcIndex,true);
									 }
									 else
										 saveDrawData(absReadOpcIndex,false);
									 /*							float distanceMM;
									 if( latestDefaultMm2 > latestDefaultMm )
									 distanceMM = latestDefaultMm2 - latestDefaultMm;
									 else
									 distanceMM = latestDefaultMm - latestDefaultMm2;
									 float distanceMMStand;
									 distanceMMStand = System::Convert::ToSingle(this->str_holeInfo[ temp + 3] * 0.06;
									 */						
									 if( (( trueData( 34 ) || trueData(SINGLE_OPC_NUM + 34 ) ) && !warningDistance)&&Single_Zhangla==false) { 
										 //			if( (distanceMM > distanceMMStand) && !warningDistance) { 
										 static System::Windows::Forms::DialogResult  r1;
										 ZhangLaStatus = ZHANGLA_PAUSE;
										 warningDistance = 1;
										 r1	=  MessageBox::Show("主从机位移差值超标，请问继续张拉吗?","张拉异常", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
										 if( r1 == System::Windows::Forms::DialogResult::OK){
											 this->p_comBase->opcWriteDataParameter[0] = true;  //开始张拉
											 this->p_comBase->opcWriteDataParameter2[0] = true;  //开始张拉
											 this->p_comBase->gRInit = 0;
											 this->p_comBase->gOpcOperation = WRITE_OPC;
											 this->p_comBase->gOpcDataId   = IDW_START2;
											 this->p_comBase->gOpcDataId  |= IDW_START1;

											 ReleaseSemaphore( this->p_comBase->semaphore,1,NULL);

											 ZhangLaStatus = ZHANGLA_TRYRUN;
										 }
										 return;
									 }
									 if( absReadOpcIndex + 1 < DRAW_DATA_BUFF ) {
										 absReadOpcIndex = absReadOpcIndex + 1;
									 }
									 else  { //save buffer data
										 MessageBox::Show("张拉时间太长导致数据溢出!","张拉异常", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
										 absReadOpcIndex = 0;
									 }
									 this->listBox2->SelectedIndex = listBox2Index - 1;

								 }
								 if( trueData( 37 ) || (bShowHandMach && trueData( 24) ) ) 
									 machine1Oil |= OIL_IN;
								 if( trueData( 38 ) || (bShowHandMach && trueData( 23) ) ) 
								 {
									 //ZhangLaStatus=ZHANGLA_RUN;
									 machine1Oil |= OIL_OUT;
								 }
								 if( trueData( SINGLE_OPC_NUM + 37 ) || (bShowHandMach && trueData(  SINGLE_OPC_NUM + 24) ) ) 
									 machine2Oil |= OIL_IN;
								 if( trueData( SINGLE_OPC_NUM + 38 ) || (bShowHandMach && trueData(  SINGLE_OPC_NUM + 23) ) ) 
								 {
									 //ZhangLaStatus=ZHANGLA_RUN;
									 machine2Oil |= OIL_OUT;
								 }
								 if(this->p_comBase->opcReadData[2]->Quality  == 192) { //控制力值
									 tempData1 = (System::Convert::ToSingle( this->p_comBase->opcReadData[ 5]->DataValue )
										 - this->huiGuiXiShu[1]) / ( this->huiGuiXiShu[0] ) ; //System::Convert::ToSingle( this->p_comBase->opcReadData[2]->DataValue);
									 tempData1 = ((int )(tempData1 * 10))/10.0;
									 if( tempData1 > 0)
										 this->label_d1KN->Text = System::Convert::ToString(  tempData1 );
								 }
								 if(this->p_comBase->opcReadData[3]->Quality  == 192) { //油压目标值
									 tempData1 = System::Convert::ToSingle(this->p_comBase->opcReadData[3]->DataValue);
									 tempData1 = ((int )(tempData1 * 100))/100.0;
									 this->textBox_d1Mpa_des->Text = System::Convert::ToString(  tempData1 );
									 if(ZhangLaStatus==ZHANGLA_IDLE)
										 this->textBox_d1Mpa_des->Text=L"000.00";
								 }

								 if(this->p_comBase->opcReadData[SINGLE_OPC_NUM + 2]->Quality  == 192){ //控制力值
									 tempData1 =  (System::Convert::ToSingle( this->p_comBase->opcReadData[SINGLE_OPC_NUM + 5]->DataValue )
										 - this->huiGuiXiShu[3]) / ( this->huiGuiXiShu[2] ) ;
									 tempData1 = ((int )(tempData1 * 10))/10.0;
									 if( tempData1 > 0)
										 this->label_d2KN->Text = System::Convert::ToString(  tempData1 );
								 }

								 if(this->p_comBase->opcReadData[SINGLE_OPC_NUM + 3]->Quality  == 192){  //油压目标值
									 tempData1 = System::Convert::ToSingle(this->p_comBase->opcReadData[SINGLE_OPC_NUM + 3]->DataValue) ;
									 tempData1 = ((int )(tempData1 * 100))/100.0;
									 this->textBox_d2Mpa_des->Text = System::Convert::ToString(  tempData1 );
									 if(ZhangLaStatus==ZHANGLA_IDLE)
										 this->textBox_d2Mpa_des->Text=L"000.00";
								 }


							 
							 drawData[absReadOpcIndex].AbsReadIndex = absReadOpcIndex;
							 }
					 else {
						 this->p_comBase->gRInit = 0;
						 this->p_comBase->gOpcOperation = READ_OPC;
						 this->p_comBase->gOpcDataId   = IDR_OTHER;
						 ReleaseSemaphore( this->p_comBase->semaphore,1,NULL);
					 }
#else  //debug purpose
						 if( (ZhangLaStatus == ZHANGLA_RUN) ) {
							 int simulateZhangLaseq = CurzhangLaSeq + 1;
							 drawData[absReadOpcIndex].AbsReadIndex = absReadOpcIndex;
							 drawData[absReadOpcIndex].Mpa = latestDefaultMpa;
							 drawData[absReadOpcIndex].Mpa2 = latestDefaultMpa2;
							 latestDefaultMpa = latestDefaultMpa + (float)((rand() % (simulateZhangLaseq ) + simulateZhangLaseq))/3.0;
							 latestDefaultMpa2 = latestDefaultMpa2 + (float)((rand() % (simulateZhangLaseq ) + simulateZhangLaseq))/2.8;
							 drawData[absReadOpcIndex].Mm = latestDefaultMm;
							 drawData[absReadOpcIndex].Mm2 = latestDefaultMm2;

							 tempData2 =  latestDefaultMpa ;
							 this->label_d1Mpa->Text = Round_float( latestDefaultMpa ,2);
							 this->label_d2Mpa->Text = Round_float( latestDefaultMpa2 ,2);

							 tempData2 =  latestDefaultMm;
							 this->label_d1mm->Text = Round_float( latestDefaultMm ,1);
							 this->label_d2mm->Text = Round_float( latestDefaultMm2 ,1);

							 tempData1 = ( latestDefaultMpa	- this->huiGuiXiShu[1]) / ( this->huiGuiXiShu[0] ) ; //System::Convert::ToSingle( this->p_comBase->opcReadData[2]->DataValue);
							 if( tempData1 > 0)
								 this->label_d1KN->Text =  Round_float( tempData1,1 );

							 tempData1 =  ( latestDefaultMpa2 - this->huiGuiXiShu[3]) / ( this->huiGuiXiShu[2] ) ;
							 if( tempData1 > 0)
								 this->label_d2KN->Text = Round_float( tempData1,1 );


							 latestDefaultMm =  latestDefaultMm + (float)((rand() % (simulateZhangLaseq + 3) + 1))/5.2;
							 latestDefaultMm2 = latestDefaultMm2 + (float)((rand() % (simulateZhangLaseq + 1) + 1))/3.5;

							 if( latestDefaultMpa < ( simulate_data*simulateZhangLaseq + simulate_data)  ) {
								 curXingCheng = 0;
							 }
							 else if( latestDefaultMpa < (simulate_data*simulateZhangLaseq + 2 * simulate_data)) {
								 curXingCheng = 1;
							 }
							 else if( latestDefaultMpa < ( simulate_data*simulateZhangLaseq + 3 * simulate_data)  ) {
								 curXingCheng = 2;
							 }
							 else if( latestDefaultMpa < ( simulate_data*simulateZhangLaseq + 4 * simulate_data)  ) {
								 curXingCheng = 3;
							 }
							 if( curXingCheng < 3 ) {
								 accLen[ CurzhangLaSeq * 3 + curXingCheng] = latestDefaultMm;
								 accLen2[ CurzhangLaSeq * 3 + curXingCheng] = latestDefaultMm2;
								 accMpa[ CurzhangLaSeq * 3 + curXingCheng] = latestDefaultMpa;
								 accMpa2[ CurzhangLaSeq * 3 + curXingCheng] = latestDefaultMpa2;
							 }

							 if( curXingCheng >= 1)
								 checkBox_lenth->Enabled = true;
							 else
								 checkBox_lenth->Enabled = false;

							 if( checkBox_lenth->Enabled && checkBox_lenth->Checked )
								 calcCurExtend(CurzhangLaSeq,1 );

							 if( (curXingCheng == 3) ) { //保压完成
								 latestDefaultMpa = 0;
								 //	latestDefaultMm = 0;
								 this->listBox2->Items[3] =  "保压完成";


								 listBox2Noticed = listBox2Noticed | 0x800;
								 ExcelReport();

								 ExcelReport();

								 if( CurzhangLaSeq + 1 < zhangLaCount ) {
									 CurzhangLaSeq ++;
									 ZhangLaStatus = ZHANGLA_PAUSE;
								 }
								 else {
									 ZhangLaStatus = ZHANGLA_IDLE;
									 CurzhangLaSeq = 0;
								 }
								 saveDrawData(absReadOpcIndex,true);

							 }
							 else
								 saveDrawData(absReadOpcIndex,false);

							 if( absReadOpcIndex + 1 < DRAW_DATA_BUFF )
								 absReadOpcIndex = absReadOpcIndex + 1;
							 else { //save buffer data
								 absReadOpcIndex = 0;
							 }
						 }
				 	}
					 
#endif
					 }
						 catch(Exception ^ ex) {
						 }

}
	private: System::Void btn_handleReportExcel_Click(System::Object^  sender, System::EventArgs^  e) {
			  try
			  {
				static System::Windows::Forms::DialogResult result;
				result=MessageBox::Show("是否要手动生成表格?","湖南聚创",MessageBoxButtons::YesNo);
				if(result==System::Windows::Forms::DialogResult::Yes)
				{
					if(ExcelReport()==true)
					{
						MessageBox::Show("手动制表成功!");
					}
				}
			  }
			  catch(Exception^ ex)
			  {
			  }
							  }				 
	private: System::Void checkBox_lenth_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
				 if( checkBox_lenth->Checked )
					 calcCurExtend(CurzhangLaSeq,1 );

			 }
			 //index : current zhangla sequence
	private: System::Boolean saveDrawData( int itemCount, bool forceWrite ){
				 if( forceWrite || (itemCount - preItem > 5) ) {

					 char * pFilePath = (char*)(void*)Marshal::StringToHGlobalAnsi(filePath);
					 FILE * fp =	 fopen( pFilePath ,"ab+");
					 if( fp ) {
						 fwrite( &drawData[preItem] , sizeof(struct DRAW_DATA) , itemCount - preItem, fp);
						 fclose(fp);
						 preItem = itemCount;
						 return true;
					 }
					 MessageBox::Show("文件保存失败!请检查配置的目录是否可写!");
					 return false;
				 }
			 }
	private: System::Boolean trueData( int index){
#ifdef debug_noMachine 
	if( (index == SINGLE_OPC_NUM +23 ) ||  (index == 23 ) || (index >= 32 && index <= 38) || ((index >= SINGLE_OPC_NUM + 32 && index <= SINGLE_OPC_NUM + 38)))
		return false;
	else
		return true;
#else
				 System::Boolean returnValue = false;
				 try{
					 returnValue =  ((this->p_comBase->opcReadData[index]->Quality  == 192) && 
						 (this->p_comBase->opcReadData[index]->DataValue->ToString()->ToLower() == "true") );
				 }
				 catch(Exception ^ ex) {
				 } 
				 return returnValue;
#endif
			 }
	private: System::Boolean falseData( int index){
#ifdef debug_noMachine 
				 return false;
#else
				 System::Boolean returnValue = false;
				 try{
					 if( index == 1 )
						 returnValue = ((this->p_comBase->opcReadDataParameter[0]->Quality  == 192) && 
						 (this->p_comBase->opcReadDataParameter[0]->DataValue->ToString()->ToLower() == "false") );
					 else
						 returnValue = ((this->p_comBase->opcReadDataParameter2[0]->Quality  == 192) && 
						 (this->p_comBase->opcReadDataParameter2[0]->DataValue->ToString()->ToLower() == "false") );
				 }
				 catch(Exception ^ ex) {
				 } 
				 return returnValue;


#endif
			 }
	private: System::Boolean trueDataZh( int index){
#ifdef debug_noMachine 
				 return true;
#else

				 System::Boolean returnValue = false;
				 try{
					 if( index == 1 )
						 if(Single_Zhangla)
							 returnValue=((this->p_comBase->opcReadDataParameter[1]->Quality == 192) &&
							 (this->p_comBase->opcReadDataParameter[1]->DataValue->ToString()->ToLower() == "true"));
						 else
						 returnValue = ((this->p_comBase->opcReadDataParameter[0]->Quality  == 192) && 
						 (this->p_comBase->opcReadDataParameter[0]->DataValue->ToString()->ToLower() == "true") );
					 else
						 returnValue = ((this->p_comBase->opcReadDataParameter2[0]->Quality  == 192) && 
						 (this->p_comBase->opcReadDataParameter2[0]->DataValue->ToString()->ToLower() == "true") );
				 }
				 catch(Exception ^ ex) {
				 } 
				 return returnValue;

#endif
			 }
	private: System::Void butt_connect_Click(System::Object^  sender, System::EventArgs^  e) {

				 if( !bDataInit )
					 bDataInit = this->p_comBase->combase_Init();
				 if( bDataInit && (bSendConnectCmd == 0) ) {
					 DateTime GetDateTimeInfo = DateTime::Now;
					 this->listBox2->Items[1] = GetDateTimeInfo.ToLongTimeString() +  "  连接设备!";
					 this->listBox2->SelectedIndex = 1;
					 if (Single_Zhangla)
					 {
						 this->p_comBase->opcWriteData[25] = true;  //通信连接,trig signal
						 this->p_comBase->opcWriteData[26] = rand();  //随机数
					 }
					 else
					 {
					 this->p_comBase->opcWriteData[ 26] = rand();  //随机数
					 this->p_comBase->opcWriteData[SINGLE_OPC_NUM + 26] = rand();  //随机数

					 this->p_comBase->opcWriteData[25] = true;  //通信连接,trig signal
					 this->p_comBase->opcWriteData[SINGLE_OPC_NUM + 25] = true;  //通信连接,trig signal
					 }
					 this->p_comBase->gRInit = 0;
					 this->p_comBase->gOpcOperation = WRITE_OPC;
					 this->p_comBase->gOpcDataId   = IDW_OTHER;
					 this->bSendConnectCmd = 1;

					 errHeartBeat = 0;
					 ReleaseSemaphore( this->p_comBase->semaphore,1,NULL);

					 // this->p_comBase->opcWriteData[25] = false;  //通信连接,trig signal
					 // this->p_comBase->opcWriteData[SINGLE_OPC_NUM + 25] = false;  //通信连接,trig signal
				 }

			 }
	private: System::Void isCommunicationOK()
			 {
				 DateTime GetDateTimeInfo = DateTime::Now;
				 if( (trueData(0)  == false) ||  (trueData(SINGLE_OPC_NUM) == false) )
				 errHeartBeat ++;
				 if(Single_Zhangla){
					 if (trueData(0))
					 {
						 this->bSendConnectCmd=0;
						 if (connectStatus==false)
						 {
							 this->listBox2->Items[2] = GetDateTimeInfo.ToLongTimeString() + " 张拉仪1连接成功!";
							 this->listBox2->SelectedIndex = 2;
						 }
						 but_startZhang->Enabled = true;
						 butt_connect->Enabled = false;
						 button_Reset->Enabled = true;
						 connectStatus = true;
						 errHeartBeat = 0;
					 }
					 else if(errHeartBeat >= 10 && ( connectStatus || this->bSendConnectCmd))
					 {
						 if(!trueData(0))
							 this->listBox2->Items[2] = GetDateTimeInfo.ToLongTimeString() +   " 张拉仪1 连接失败!";
						 this->listBox2->SelectedIndex = 2;
						 button_Reset->Enabled = false;
						 but_startZhang->Enabled = false;
						 connectStatus = false;
						 butt_connect->Enabled = true;
					 }
				 }
				else
				{
				 if( trueData(0) && trueData(SINGLE_OPC_NUM) && bSendConnectCmd){  

					 this->bSendConnectCmd = 0;

					 if( connectStatus == false ) {
						 this->listBox2->Items[2] = GetDateTimeInfo.ToLongTimeString() + " 张拉仪连接成功!";
						 //bConnected=true;
						 this->listBox2->SelectedIndex = 2;
					 }
					 but_startZhang->Enabled = true;
					 butt_connect->Enabled = false;
					 button_Reset->Enabled = true;
					 connectStatus = true;
					 errHeartBeat = 0;
					 //ReadSet();
					 //ZhangLaStatus=ZHANGLA_RUN;
				 }
				 else if ( errHeartBeat >= 5 && ( connectStatus || this->bSendConnectCmd) ) {

					 this->bSendConnectCmd = 0;

					 if(  (trueData(0) == false) && (trueData(SINGLE_OPC_NUM ) == false)  )
						 this->listBox2->Items[2] = GetDateTimeInfo.ToLongTimeString() +   " 张拉仪1,2 连接失败!";
					 else 	if(  (trueData(0) == false)  )
						 this->listBox2->Items[2] = GetDateTimeInfo.ToLongTimeString() +   " 张拉仪1 连接失败!";
					 else 
						 this->listBox2->Items[2] = GetDateTimeInfo.ToLongTimeString() +   " 张拉仪2 连接失败!";

					 this->listBox2->SelectedIndex = 2;
					 button_Reset->Enabled = false;
					 but_startZhang->Enabled = false;
					 connectStatus = false;
					 butt_connect->Enabled = true;
				 }
				}
			 }
			 //连接成功后，定时发送随机数
	private: System::Void SendRandomData(  ){
				 this->p_comBase->opcWriteDataRandom[0] = rand();  //随机数
				 this->p_comBase->opcWriteDataRandom[1] = this->p_comBase->opcWriteDataRandom[0];  //随机数
				 this->p_comBase->gRInit = 0;

				 this->p_comBase->gOpcOperation |= WRITE_OPC;
				 this->p_comBase->gOpcDataId   |= IDW_RANDOM;


				 // this->p_comBase->writeData( 0 ,READ_OPC, 1);
				 // this->p_comBase->writeData( 0 ,READ_OPC, 2);
			 }
	private: System::Void InitOpcWriteData(  ){
				 for(int i = 0; i < itemNum; i++ )
					 this->p_comBase->opcWriteData[i] = false;

				 m_systemSet.read_parameter();
				 this->p_comBase->opcWriteData[20] = this->huiGuiXiShu[0]; 
				 this->p_comBase->opcWriteData[21] = this->huiGuiXiShu[1]; 

				 this->p_comBase->opcWriteData[SINGLE_OPC_NUM + 20] = this->huiGuiXiShu[2]; 
				 this->p_comBase->opcWriteData[SINGLE_OPC_NUM + 21] = this->huiGuiXiShu[3]; 

				 this->p_comBase->opcWriteData[27] =  System::Convert::ToSingle("0");  
				 this->p_comBase->opcWriteData[28] = System::Convert::ToSingle("0"); 
				 this->p_comBase->opcWriteData[29] = System::Convert::ToSingle("0");

				 this->p_comBase->opcWriteData[SINGLE_OPC_NUM + 27] =  System::Convert::ToSingle("0"); 
				 this->p_comBase->opcWriteData[SINGLE_OPC_NUM + 28] = System::Convert::ToSingle("0"); 
				 this->p_comBase->opcWriteData[SINGLE_OPC_NUM + 29] = System::Convert::ToSingle("0");

				 this->p_comBase->opcWriteDataRandom[0] = rand();  
				 this->p_comBase->opcWriteDataRandom[1] = this->p_comBase->opcWriteDataRandom[0];  

			 }
			 //启动第几次张拉
	private: System::Void setZhangLaData( Int32 curIndex , System::Boolean bStart, Int32 dMask ){

				 filePath = m_systemSet.textBox1->Text + "\\" + this->textBox_liangHao->Text + "\\" 
					 + System::Convert::ToString( curIndex + 1) + "-" + m_ZhangLaParameterView.str_dataGrid[curIndex * 9 + 1] + ".jcd";
				 if(!Single_Zhangla)
				 {
				 this->p_comBase->opcWriteData[22] = false; 
				 this->p_comBase->opcWriteData[23] = false;  
				 this->p_comBase->opcWriteData[24] = false;  

				 this->p_comBase->opcWriteData[26] = rand();  //随机数
				 this->p_comBase->opcWriteData[27] =  m_ZhangLaParameterView.str_dataGrid[curIndex * 9 + 2]; 
				 this->p_comBase->opcWriteData[28] =  m_ZhangLaParameterView.str_dataGrid[curIndex * 9 + 4]; 
				 if(m_ZhangLaParameterView.str_dataGrid[curIndex * 9 + 6]->Length < 2)
					 this->p_comBase->opcWriteData[29] = "0";
				 else
					 this->p_comBase->opcWriteData[29] =  m_ZhangLaParameterView.str_dataGrid[curIndex * 9 + 6];  
				 if( dMask & 1 )
					 this->p_comBase->opcWriteDataParameter[0] = bStart;  
				 this->p_comBase->opcWriteData[31] = loadSpeed; 

				 this->p_comBase->opcWriteData[SINGLE_OPC_NUM + 22] = false; 
				 this->p_comBase->opcWriteData[SINGLE_OPC_NUM + 23] = false; 
				 this->p_comBase->opcWriteData[SINGLE_OPC_NUM + 24] = false; 

				 this->p_comBase->opcWriteData[SINGLE_OPC_NUM + 26] = rand(); 
				 this->p_comBase->opcWriteData[SINGLE_OPC_NUM + 27] =   m_ZhangLaParameterView.str_dataGrid[curIndex * 9 + 3]; 
				 this->p_comBase->opcWriteData[SINGLE_OPC_NUM + 28] =  m_ZhangLaParameterView.str_dataGrid[curIndex * 9 + 5]; 
				 if(m_ZhangLaParameterView.str_dataGrid[curIndex * 9 + 6]->Length < 2)
					 this->p_comBase->opcWriteData[SINGLE_OPC_NUM + 29] = "0";
				 else
					 this->p_comBase->opcWriteData[SINGLE_OPC_NUM + 29] =  m_ZhangLaParameterView.str_dataGrid[curIndex * 9 + 7]; 

				 if( dMask & 2 )
					 this->p_comBase->opcWriteDataParameter2[0] = bStart; 
				 this->p_comBase->opcWriteData[SINGLE_OPC_NUM + 31] = loadSpeed; 

				 this->p_comBase->opcWriteData[ 35 ] =  m_ZhangLaParameterView.str_dataGrid[curIndex * 9 + 8]; 
				 this->p_comBase->opcWriteData[SINGLE_OPC_NUM + 35] =  m_ZhangLaParameterView.str_dataGrid[curIndex * 9 + 8];

				 if( bStart )
					 listBox2Noticed = 0;
				 if( bStart ) {
					 warningDistance = 0;
					 //	 this->label_CountDown_notice->Text = L"张拉计时：";
					 //this->listBox1->SelectedIndex = curIndex;
					 checkBox_lenth->Checked = false;
				 }
				 }
				 else
				 {
					 this->p_comBase->opcWriteData[22] = false; 
					 this->p_comBase->opcWriteData[23] = false;  
					 this->p_comBase->opcWriteData[24] = false;  

					 this->p_comBase->opcWriteData[26] = rand();  //随机数
					 this->p_comBase->opcWriteData[27] =  m_ZhangLaParameterView.str_dataGrid[curIndex * 9 + 2]; 
					 this->p_comBase->opcWriteData[28] =  m_ZhangLaParameterView.str_dataGrid[curIndex * 9 + 4]; 
					 if(m_ZhangLaParameterView.str_dataGrid[curIndex * 9 + 6]->Length < 2)
						 this->p_comBase->opcWriteData[29] = "0";
					 else
						 this->p_comBase->opcWriteData[29] =  m_ZhangLaParameterView.str_dataGrid[curIndex * 9 + 6];  
					 if( dMask & 1 )
						 this->p_comBase->opcWriteDataParameter[0] =bStart;
						 this->p_comBase->opcWriteDataParameter[1] = bStart;
					// if( dMask & 2 )
						// this->p_comBase->opcWriteDataParameter2[0] = bStart; 
					 this->p_comBase->opcWriteData[31] = loadSpeed; 
					 this->p_comBase->opcWriteData[ 35 ] =  m_ZhangLaParameterView.str_dataGrid[curIndex * 9 + 8]; 
					 if( bStart ) {
						 listBox2Noticed = 0;
						 warningDistance = 0;
						 //	 this->label_CountDown_notice->Text = L"张拉计时：";
						 //this->listBox1->SelectedIndex = curIndex;
						 checkBox_lenth->Checked = false;
					 }
				 }
				 this->p_comBase->gRInit = 0;
				 this->p_comBase->gOpcOperation = WRITE_OPC;
				 this->p_comBase->gOpcDataId   = IDW_OTHER;
				 this->p_comBase->gOpcDataId   |= IDW_START1;
				 if(!Single_Zhangla)
				 this->p_comBase->gOpcDataId   |= IDW_START2;
				 ReleaseSemaphore( this->p_comBase->semaphore,1,NULL);
			 }
			 //开始张拉
	private: System::Void but_startZhang_Click(System::Object^  sender, System::EventArgs^  e) {
				 static int busy = 0; 
				 kong_over=false;
				 if( busy == 1)
					 return;
				 busy = 1;
				 if( connectStatus == false) {
					 MessageBox::Show("通信失败，请检测IP地址设置及网络连接！","智能张拉系统", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
					 busy = 0; 
					 return;
				 }
				 System::IO::Directory::CreateDirectory( m_systemSet.textBox1->Text + "\\" + this->textBox_liangHao->Text);
				 filePath = m_systemSet.textBox1->Text + "\\" + this->textBox_liangHao->Text + "\\" 
					 + System::Convert::ToString( CurzhangLaSeq + 1) + "-" + m_ZhangLaParameterView.str_dataGrid[CurzhangLaSeq * 9 + 1] + ".jcd";

				 GRAPH_GRID_SECOND = 10;

				 GRAPH_X_NUM = (GRAPH_GRID_SECOND * GRAPH_GRID_NUM ); 

				 if( (ZhangLaStatus == ZHANGLA_IDLE) || ( ZhangLaStatus == ZHANGLA_PAUSE) ) {  
					 if((ZhangLaStatus == ZHANGLA_IDLE) &&  File::Exists( filePath)) {
						 MessageBox::Show(filePath + " 张拉数据已存在！不能进行重复张拉！");
						 busy = 0; 
						 return ;
					 }

					 /*	if ( (machine1Oil == OIL_OUT) || ( machine2Oil == OIL_OUT) ){
					 MessageBox::Show( " 正在退油，请稍后点击张拉！");
					 busy = 0; 
					 return ;
					 }
					 */
					 //System.IO.File.Exists(); 检测文件是否存在

					 for( int i = 3; i < this->listBox2->Items->Count; i++ )
						 this->listBox2->Items[i] = "";
					 listBox2Index = 3;

					 if( preCurIndex != CurzhangLaSeq ) {
						 this->absReadOpcIndex = 0;
						 preItem = 0;
						 preCurIndex = CurzhangLaSeq ;
						 latestDefaultMm = 0;
						 latestDefaultMpa = 0;
						 latestDefaultMm2 = 0;
						 latestDefaultMpa2 = 0;
						 curXingCheng = 0;
						 bGenExcel = 0;

						 if( CurzhangLaSeq == 0)
							 for( int i = 0; i < zhangLaSeqNum * 3; i++) {
								 accLen[ i ] = 0;
								 accMpa[ i ] = 0;
								 accLen2[ i ] = 0;
								 accMpa2[ i ] = 0;
							 }
					 }
					 setZhangLaData( CurzhangLaSeq , true , 3); 
					 this->progressBar_theory->Maximum = System::Convert::ToSingle ( m_ZhangLaParameterView.str_dataGrid[CurzhangLaSeq * 9 + 8] );
					 progressBar_theory->Value = System::Convert::ToSingle ( m_ZhangLaParameterView.str_dataGrid[CurzhangLaSeq * 9 + 8] );
					 label_theory->Text = "理论伸长量: " + m_ZhangLaParameterView.str_dataGrid[CurzhangLaSeq * 9 + 8] + " mm";
					 len_percent = 0;
					 len_total = 0;
					 calculate_index = 0;

					 progressBar_percent->Value = len_percent;
					 label_acture->Text = "实际伸长量:  mm";
					 progressBar_percent->Value = 0;
					 label_percent->Text = " ";
					// startZhangLaMm1=0;
					// startZhangLaMm2=0;

					 retryCount = 0;
					 ZhangLaStatus = ZHANGLA_TRYRUN;

				 }
				 else  if( ZhangLaStatus == ZHANGLA_RUN ) { //"暂 停 张 拉"
					 setZhangLaData( CurzhangLaSeq , false , 3); 
					 ZhangLaStatus = ZHANGLA_TRYPAUSE;

					 retryCount = 0;

				 }
				 busy = 0;
			 }
	public : Void initZhangLaData () {
				 int i = 0,holeIndex;
				 float chuYingLi ; 
				 float destiKN ;  
				 float temp;

				 CurzhangLaSeq = 0;
				 bShowed = 1;

				 this->textBox_liangHao->Text = this->str_LiangInfo[0];
				 this->listBox1->Items->Clear();
				 try{
					 for( int i = 3; i < this->listBox2->Items->Count; i++ )
						 this->listBox2->Items[i] = "";
				 }catch( Exception ^ ex){

				 };
				 String ^ curHoleName ;
				 for(i = 0 ; i < zhangLaSeqNum; i++)
					 this->multiZhangLa[i] = false;
				 try{
					 loadSpeed = System::Convert::ToSingle(this->str_LiangInfo[1]->Replace("%",""))/(float)100.0;
					 chuYingLi =  System::Convert::ToSingle(this->str_LiangInfo[2]->Replace("%",""))/(float)100.0;
				 }
				 catch(Exception ^ ex) {
					 //MessageBox::Show(ex->Message);
				 } 
				 /*	try{
				 for(i = 0 ; i < zhangLaSeqNum; i++)
				 m_ZhangLaParameterView.str_dataGrid[0].Remove;
				 }
				 catch(Exception ^ ex) {
				 //MessageBox::Show(ex->Message);
				 } */
				 for( i = 0;i < zhangLaSeqNum; i ++ )
					 for(int j = 0;j < 9; j ++ )
						 m_ZhangLaParameterView.str_dataGrid[i * 9 + j] = "";

				 for(i = 0 ; i < zhangLaSeqNum; i++)
					 if( this->str_ShunXunInfo[i] && this->str_ShunXunInfo[i]->Length > 0 ) {
						 curHoleName = this->str_ShunXunInfo[i]->Substring( this->str_ShunXunInfo[i]->IndexOf("%") + 1);
						 m_ZhangLaParameterView.str_dataGrid[i * 9] =  "第" +  System::Convert::ToString(i+1) + "次";
						 m_ZhangLaParameterView.str_dataGrid[i * 9 + 1] =  curHoleName;

						 for(holeIndex = 0; holeIndex < holeInfoNum/4; holeIndex ++) {
							 if( this->str_holeInfo[holeIndex * 4] &&  this->str_holeInfo[holeIndex * 4]->Length > 0 ) {
								 String ^ compareHoleName = this->str_holeInfo[holeIndex * 4];
								 int minLen = curHoleName->Length > compareHoleName->Length
									 ? compareHoleName->Length : curHoleName->Length;
								 int resultCompare = String::Compare(compareHoleName,0,curHoleName,0,minLen,StringComparison::OrdinalIgnoreCase);

								 if ( (resultCompare == 0)	){
									 //	(this->str_holeInfo[holeIndex * 4]->Contains( curHoleName ) || curHoleName->Contains(this->str_holeInfo[holeIndex * 4]))){
									/* System::String^ s8;
									 //s1=nullptr;
									 StreamReader pfile("..//Debug//1.dat");
									 s8=pfile.ReadLine();*/
									 if(Main_Wnd_ButCurs!=9){
									 for (int i = 0; i < 3; i++) { 
										 More_check[i].ToString(); 
									 }
									 More_check=More_check[0].ToString()+More_check[1].ToString()+More_check[2].ToString();
									 float a=float::Parse(More_check);
									 a=a/100;
									 destiKN =  System::Convert::ToSingle(this->str_ShunXunInfo[i]->Substring(0, this->str_ShunXunInfo[i]->IndexOf("%"))) / (float)100.0 ;
									 temp =  System::Convert::ToSingle(this->str_holeInfo[holeIndex * 4 + 2] ) ;
									 if(this->multiZhangLa[holeIndex] == false) //初次张拉
									 {
										 this->multiZhangLa[holeIndex] = true;
										 m_ZhangLaParameterView.str_dataGrid[i * 9 + 2] =  System::Convert::ToString( System::Convert::ToSingle(temp * chuYingLi )*a);
										 m_ZhangLaParameterView.str_dataGrid[i * 9 + 4] =  System::Convert::ToString( System::Convert::ToSingle(temp  * chuYingLi * 2)*a );
										 m_ZhangLaParameterView.str_dataGrid[i * 9 + 6] =  System::Convert::ToString( System::Convert::ToSingle(temp * destiKN )*a );
										 this->curPercentKN[holeIndex] = destiKN;
									 }else {  //多次张拉
										 m_ZhangLaParameterView.str_dataGrid[i * 9 + 2] =  System::Convert::ToString( System::Convert::ToSingle(temp * this->curPercentKN[holeIndex] )*a);
										 m_ZhangLaParameterView.str_dataGrid[i * 9 + 4] =  System::Convert::ToString( System::Convert::ToSingle(temp * destiKN )*a);
										 m_ZhangLaParameterView.str_dataGrid[i * 9 + 6] =  "";
										 this->curPercentKN[holeIndex] = destiKN;
									 }
									 m_ZhangLaParameterView.str_dataGrid[i * 9 + 8] =  this->str_holeInfo[holeIndex * 4 + 3] ;

									 m_ZhangLaParameterView.str_dataGrid[i * 9 + 3] =  m_ZhangLaParameterView.str_dataGrid[i * 9 + 2];
									 m_ZhangLaParameterView.str_dataGrid[i * 9 + 5] =  m_ZhangLaParameterView.str_dataGrid[i * 9 + 4];
									 m_ZhangLaParameterView.str_dataGrid[i * 9 + 7] =  m_ZhangLaParameterView.str_dataGrid[i * 9 + 6];
									 break;
									 }
									 else
									 {
										 destiKN =  System::Convert::ToSingle(this->str_ShunXunInfo[i]->Substring(0, this->str_ShunXunInfo[i]->IndexOf("%"))) / (float)100.0 ;
										 temp =  System::Convert::ToSingle(this->str_holeInfo[holeIndex * 4 + 2] ) ;
										 if(this->multiZhangLa[holeIndex] == false) //初次张拉
										 {
											 this->multiZhangLa[holeIndex] = true;
											 m_ZhangLaParameterView.str_dataGrid[i * 9 + 2] =  System::Convert::ToString( System::Convert::ToSingle(temp * chuYingLi ));
											 m_ZhangLaParameterView.str_dataGrid[i * 9 + 4] =  System::Convert::ToString( System::Convert::ToSingle(temp  * chuYingLi * 2) );
											 m_ZhangLaParameterView.str_dataGrid[i * 9 + 6] =  System::Convert::ToString( System::Convert::ToSingle(temp * destiKN ) );
											 this->curPercentKN[holeIndex] = destiKN;
										 }else {  //多次张拉
											 m_ZhangLaParameterView.str_dataGrid[i * 9 + 2] =  System::Convert::ToString( System::Convert::ToSingle(temp * this->curPercentKN[holeIndex] ));
											 m_ZhangLaParameterView.str_dataGrid[i * 9 + 4] =  System::Convert::ToString( System::Convert::ToSingle(temp * destiKN ));
											 m_ZhangLaParameterView.str_dataGrid[i * 9 + 6] =  "";
											 this->curPercentKN[holeIndex] = destiKN;
										 }
										 m_ZhangLaParameterView.str_dataGrid[i * 9 + 8] =  this->str_holeInfo[holeIndex * 4 + 3] ;

										 m_ZhangLaParameterView.str_dataGrid[i * 9 + 3] =  m_ZhangLaParameterView.str_dataGrid[i * 9 + 2];
										 m_ZhangLaParameterView.str_dataGrid[i * 9 + 5] =  m_ZhangLaParameterView.str_dataGrid[i * 9 + 4];
										 m_ZhangLaParameterView.str_dataGrid[i * 9 + 7] =  m_ZhangLaParameterView.str_dataGrid[i * 9 + 6];
										 break;
									 }
								 }
							 }
						 }

						 if( i < 9 )
							 this->listBox1->Items->Add(  "第" +  System::Convert::ToString(i+1) + "次   --   " + this->str_ShunXunInfo[i] );
						 else
							 this->listBox1->Items->Add(  "第" +  System::Convert::ToString(i+1) + "次  --   " + this->str_ShunXunInfo[i] );
					 }
					 else
						 break;
				 zhangLaCount = i;
				 this->listBox1->SelectedIndex = 0;
				 this->listBox2->Items->Add("湖南聚创欢迎您！");
				 this->listBox2->SelectedIndex = 0;
				 listBox2Index = 3;
				 this->listBox2->Items->Add("");
				 this->listBox2->Items->Add("");
				 DateTime GetDateTimeInfo = DateTime::Now;


				 this->but_startZhang->Text = L"开 始 张 拉";
				 this->but_startZhang->Enabled = false;
				 this->button_systemParameter->Enabled = true;
				 this->butt_connect->Enabled = true;
				 this->butt_handle->Enabled = false;
				 this->button_Reset->Enabled = false;
			 }
	private: System::Void controlMachine_Shown(System::Object^  sender, System::EventArgs^  e) {
				 this->timer1->Enabled = true;
				 bShowedWindow = 1;

			 }
			 //张拉参数
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
				 m_ZhangLaParameterView.ShowDialog();
			 }
	public: System::Void ResetAll( ) {
				 this->p_comBase->opcWriteDataParameter2[0] = false; 
				 this->p_comBase->opcWriteDataParameter[0] = false; 

				 this->p_comBase->opcWriteData[ 30 ] = true; 
				 this->p_comBase->opcWriteData[SINGLE_OPC_NUM + 30 ] = true; 
				 this->p_comBase->gRInit = 0;
				 this->p_comBase->gOpcOperation = WRITE_OPC;
				 this->p_comBase->gOpcDataId   = IDW_OTHER;
				 ReleaseSemaphore( this->p_comBase->semaphore,1,NULL);
				 Sleep(1000);
				 this->p_comBase->opcWriteData[ 30 ] = false; 
				 this->p_comBase->opcWriteData[SINGLE_OPC_NUM + 30 ] = false; 
				 //File::Delete("..//Debug//1.dat");
				 system_pause2=0;
				 system_pause1=0;
				 pause_show1=0;
				 pause_show2=0;
				 konghao_over=0;
				 kong_over=false;
				 bSendConnectCmd = 0;
				 absReadOpcIndex = 0;
				 preItem = 0;
				 debugStatus = false;
				 bConnected = false;
				 bPauseByPLC = false;
				 bShowed = false;
				 ZhangLaStatus = ZHANGLA_IDLE;
				 connectStatus = false;
				 bDataInit = 0;
				 CurzhangLaSeq = 0;
				 this->listBox1->SelectedIndex=CurzhangLaSeq;
				 timeTickCount = 0;
				 errHeartBeat = 0;
				 latestDefaultMpa = 0;
				 latestDefaultMm = 0;
				 latestDefaultMpa2 = 0;
				 latestDefaultMm2 = 0;
				 preCurIndex = -1;
				 graph1_x = 25;
				 graph1_y = GRAPH_HEIT + 30; 
				 this->but_startZhang->Text = L"开 始 张 拉";
				 this->but_startZhang->Enabled = false;
				 this->button_systemParameter->Enabled = true;
				 this->butt_connect->Enabled = true;
				 this->butt_handle->Enabled = false;
				 this->button_Reset->Enabled = false;
				 this->label_d1KN->Text=L"00000.0";
				 this->label_d2KN->Text=L"00000.0";
				 this->textBox_d1Mpa_des->Text=L"000.00";
				 this->textBox_d2Mpa_des->Text=L"000.00";
				 this->label_d1Mpa->Text=L"000.00";
				 this->label_d2Mpa->Text=L"000.00";
				 this->label_d1mm->Text=L"000.0";
				 this->label_d2mm->Text=L"000.0";
				 this->listBox2->Items->Clear();
				 this->listBox2->Items->Add("湖南聚创欢迎您！");
				 listBox2Index = 3;
				 this->listBox2->SelectedIndex = 0;
				 this->listBox2->Items->Add("");
				 this->listBox2->Items->Add("");
				 this->listBox2->Items->Add("");
					 this->listBox2->Items->Add("");
					 this->listBox2->Items->Add("");
					 this->listBox2->Items->Add("");
			 }
	private: System::Void controlMachine_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
				 static System::Windows::Forms::DialogResult  r1;
				 if( ZhangLaStatus != ZHANGLA_IDLE ) {

					 r1	=  MessageBox::Show("张拉未完成，停止张拉并退出吗?","退出张拉", MessageBoxButtons::YesNoCancel, MessageBoxIcon::Asterisk , MessageBoxDefaultButton::Button3);
					 if( r1 == System::Windows::Forms::DialogResult::Yes){

						 Main_Wnd_ButCurs=0;
						 saveDrawData(absReadOpcIndex,true);
						 ResetAll( );
						 //timer1->Enabled=false;
						 bShowedWindow = 0;
						 //this->Hide();
						 //connectStatus=true;
						 
						 return;
					 }
					 else {
						 e->Cancel = true;
						 return;
					 }
				 }
				 ResetAll();
				 //this->timer1->Enabled=false;
				 //connectStatus=true;
				 //this->Hide();
				/* this->p_comBase->opcWriteData[25] = false;  //通信连接,trig signal
				 this->p_comBase->opcWriteData[SINGLE_OPC_NUM+25 ] = false;
				 this->p_comBase->opcWriteData[0]=false;
				 this->p_comBase->opcWriteData[SINGLE_OPC_NUM]=false;
				 this->p_comBase->gRInit = 0;
				 this->p_comBase->gOpcOperation = WRITE_OPC;
				 this->p_comBase->gOpcDataId   = IDW_OTHER;
				 this->bSendConnectCmd = 0;
				 ReleaseSemaphore( this->p_comBase->semaphore,1,NULL);*/
				 bShowedWindow = 0;
				 //this->Close();
				 return;


			 }
	private: System::Void controlMachine_MinimumSizeChanged(System::Object^  sender, System::EventArgs^  e) {

				 return;
			 }
	private: float calcCurExtend(int calculateHoleIndex, int bShow ) 
			  {
				  String ^ curHoleName ;
				  int CurzhangLaSeq_l = calculateHoleIndex ;
				  Boolean multiZh = false;
				  int holeIndex, i;

				  len_total = 0;
				  try{
					  //chuYingLi
					  // for(i = 0 ; i < zhangLaCount; i++)
					  i = 0 ;
					  curHoleName = m_ZhangLaParameterView.str_dataGrid[ CurzhangLaSeq_l * 9 + 1];
					  //accLen[ CurzhangLaSeq * 3]         accMpa[ CurzhangLaSeq * 3]
					  for(holeIndex = 0; holeIndex <= CurzhangLaSeq_l; holeIndex ++) {
						  String ^ compareHoleName = m_ZhangLaParameterView.str_dataGrid[holeIndex * 9 + 1];
						  int minLen = curHoleName->Length > compareHoleName->Length
							  ? compareHoleName->Length : curHoleName->Length;
						  int resultCompare = String::Compare(compareHoleName,0,curHoleName,0,minLen,StringComparison::OrdinalIgnoreCase);
						  // m_ZhangLaParameterView.str_dataGrid[holeIndex * 9 + 1]->Contains( curHoleName );
						  if( resultCompare == 0 ) 
							  if( multiZh == false) {
								  multiZh = true;
								  if( accLen[ holeIndex * 3 + 1] >= accLen[ holeIndex * 3 ])
									  len_total = len_total + ( accLen[ holeIndex * 3 + 1] - accLen[ holeIndex * 3 ]) * 2 ;
								  if( accLen2[ holeIndex * 3 + 1] >= accLen2[ holeIndex * 3 ])
									  len_total = len_total + ( accLen2[ holeIndex * 3 + 1] - accLen2[ holeIndex * 3 ]) * 2 ;

								  if( accLen[ holeIndex * 3 + 2] > (accLen[ holeIndex * 3 + 1] + LEN_SUB) )
									  len_total = len_total + ( accLen[ holeIndex * 3 + 2] - accLen[ holeIndex * 3 + 1]) - LEN_SUB ;
								  if( accLen2[ holeIndex * 3 + 2] > (accLen2[ holeIndex * 3 + 1] + LEN_SUB) )
									  len_total = len_total + ( accLen2[ holeIndex * 3 + 2] - accLen2[ holeIndex * 3 + 1]) - LEN_SUB ;
							  }
							  else {
								  if( accLen[ holeIndex * 3 + 1] > ( accLen[ holeIndex * 3 ] + LEN_SUB) )
									  len_total = len_total + ( accLen[ holeIndex * 3 + 1] - accLen[ holeIndex * 3 ]);// - LEN_SUB ;
								  if( accLen2[ holeIndex * 3 + 1] > ( accLen2[ holeIndex * 3 ] + LEN_SUB) )
									  len_total = len_total + ( accLen2[ holeIndex * 3 + 1] - accLen2[ holeIndex * 3 ]);// - LEN_SUB ;
							  }
					  }

					  len_total = (int)((len_total) * 100)/100.0;
					  len_percent = (int)((len_total/progressBar_theory->Value) * 100);

					  if( bShow ) {
						  label_acture->Text = "实际伸长量: " +  System::Convert::ToString ( len_total ) + " mm";
						  if( len_percent > 0)
							  progressBar_percent->Value = ((int) len_percent > 100) ? 100 : (int)len_percent;
						  else {
							  len_percent = 0;
							  progressBar_percent->Value = 0;
						  }
						  label_percent->Text = System::Convert::ToString ( len_percent ) + "%";
					  }
				  }
				  catch(Exception ^ ex) {
				  }
				  return len_total;


			  }
	private: Boolean readLiangInfo(String^ sqlString)  //读取梁号
					  {
						  Boolean retVal = false;
						  try {
							  System::String^ dataCon = L"Provider=Microsoft.Jet.OLEDB.4.0;Data Source=" + System::AppDomain::CurrentDomain->BaseDirectory->ToString() + L"\\张拉数据库.mdb;Persist Security Info=False;";
							  OleDbConnection ^connection = gcnew OleDbConnection( dataCon );

							  OleDbCommand^ command = gcnew OleDbCommand();

							  command->Connection = connection;
							  try
							  {
								  connection->Open();
								  command->Connection = connection;
								  // Execute the commands.
								  command->CommandText = sqlString;//"select * from table2";
								  OleDbDataReader^ reader   =   command->ExecuteReader();
								  array<System::Object^>^  meta = gcnew array<System::Object^>(52); 
								  retVal = reader->Read();
								  //int a=reader->GetValues(meta);
								  //MessageBox::Show(meta[30]->ToString());
								  //More_check=float::Parse(meta[30]->ToString());
								  reader->Close();
							  }
							  catch (Exception^ ex)
							  {
								  MessageBox::Show(ex->Message,"读数据库失败", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
							  }

							  connection->Close(); 
						  }
						  catch (Exception^ ex)
						  {
						  }
						  return retVal;
					  }
	private: static Boolean writeSql(String^ sqlString)
					 {
						 //	static int num = 0;
						 Boolean retVal = false;
						 try
						 {
							 System::String^ dataCon = L"Provider=Microsoft.Jet.OLEDB.4.0;Data Source=" + System::AppDomain::CurrentDomain->BaseDirectory->ToString() + L"\\张拉数据库.mdb;Persist Security Info=False;";
							 OleDbConnection ^connection = gcnew OleDbConnection( dataCon );
							 OleDbCommand^ command = gcnew OleDbCommand();
							 OleDbTransaction^ transaction = nullptr;

							 // Set the Connection to the new OleDbConnection.
							 command->Connection = connection;

							 // Open the connection and execute the transaction.
							 try
							 {
								 connection->Open();

								 // Start a local transaction with ReadCommitted isolation level.
								 transaction = connection->BeginTransaction(IsolationLevel::ReadCommitted);

								 // Assign transaction object for a pending local transaction.
								 command->Connection = connection;
								 command->Transaction = transaction;

								 // Execute the commands.
								 command->CommandText = sqlString;//"select * from table2";
								 // "Insert into table1 (lianghao, gongyi) VALUES ('100', 'Description')";
								 command->ExecuteNonQuery();

								 // Commit the transaction.
								 transaction->Commit();
								 retVal = true;
							 }
							 catch (Exception^ ex)
							 {
								 MessageBox::Show(ex->Message,"写数据库失败", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
								 try
								 {
									 // Attempt to roll back the transaction.
									 transaction->Rollback();
								 }
								 catch(Exception^ ex2)
								 {
									 MessageBox::Show(ex2->Message,"写数据库失败", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
								 }
							 }
							 //objDB->ChangeDatabase("INSERT INTO table1('张拉梁号','张拉工艺') VALUES ('6号梁','sechs')");
							 connection->Close(); 
						 }
						 catch (Exception^ ex)
						 {
						 }
						 return retVal;
					 }
	System::String ^ getXingChenName( int xinchen){
						 System::String ^ xingchenName;
						 if(xinchen == 0)
							 xingchenName = L"初始";
						 else
							 xingchenName = L"第" +  System::Convert::ToString(xinchen);

						 return xingchenName;
					 }
	private: System::Boolean ExcelReport(){
				 Microsoft::Office::Interop::Excel::Application ^ xlApp = gcnew Microsoft::Office::Interop::Excel::Application();
				 Object^ missing = System::Reflection::Missing::Value; 
				 int genHoleCount = CurzhangLaSeq + 1;
				 int bExitFile = 0;
				 Boolean bExitRecord;

				 bExitRecord = readLiangInfo(L"select * from 张拉表" + L" where 梁号 ='" + this->textBox_liangHao->Text + L"'");
				 System::String^ sqlStr = "";


				 System::String ^ fileNameXls = m_systemSet.textBox1->Text + "\\"  +  this->textBox_liangHao->Text + "\\"  + this->textBox_liangHao->Text + ".xls";
				 bExitFile =  File::Exists( fileNameXls );
				 if(xlApp == nullptr)
				 {
					 MessageBox::Show("无法创建Excel对象，可能您的机子未安装Excel");
					 return false;
				 }	
				 try{

					 Microsoft::Office::Interop::Excel::Workbooks^ wbs = xlApp->Workbooks;
					 Microsoft::Office::Interop::Excel::Workbook^ wb  ;
					 if ( bExitFile ) {
						 wb = wbs->Add( fileNameXls );  //(fileNameXls,missing ,missing ,missing,missing,missing,missing, missing,missing,false,false,missing,false,missing,missing);
						 File::Delete( fileNameXls );
					 }
					 else
						 wb = wbs->Add( System::AppDomain::CurrentDomain->BaseDirectory->ToString() +  "\\example.xls");
					 // , missing, true, missing, missing, missing, missing, missing, missing, true, missing, missing, missing, missing, missing);
					 Microsoft::Office::Interop::Excel::Worksheet^ ws = (Microsoft::Office::Interop::Excel::Worksheet^)wb->Worksheets[1];

					 int rowsint = ws->UsedRange->Cells->Rows->Count;
					 int columnsint = ws->UsedRange->Cells->Columns->Count;
					 int i,j;
					 ws->UsedRange->Cells[1,1] = this->str_ExcelInfo[0];
					 ws->UsedRange->Cells[3,1] = "施工单位： " + this->str_ExcelInfo[1]; 
					 ws->UsedRange->Cells[3,6] = "监理单位： " + this->str_ExcelInfo[2]; 
					 ws->UsedRange->Cells[3,10] = "土建合同号： " + this->str_ExcelInfo[3]; 
					 ws->UsedRange->Cells[4,3] =   this->str_ExcelInfo[4];
					 ws->UsedRange->Cells[4,8] =   this->str_ExcelInfo[5]; 
					 ws->UsedRange->Cells[5,3] =    this->textBox_liangHao->Text ;  
					 DateTime GetDateTimeInfo = DateTime::Now;
					 ws->UsedRange->Cells[5,8] =   GetDateTimeInfo.ToShortDateString(); 
					 ws->UsedRange->Cells[6,3] =   this->str_ExcelInfo[7] + "MPa";  
					 ws->UsedRange->Cells[6,5] =   this->str_ExcelInfo[18]+ "MPa";
					 ws->UsedRange->Cells[6,8] =	this->str_ExcelInfo[17] + "MPa";
					 ws->UsedRange->Cells[6,11] =   this->str_ExcelInfo[6] + "MPa"; 

					 ws->UsedRange->Cells[7,3] =   this->str_ExcelInfo[8];  
					 ws->UsedRange->Cells[7,8] =   this->str_ExcelInfo[9]; 

					 ws->UsedRange->Cells[8,3] =   this->str_ExcelInfo[10]; 
					 ws->UsedRange->Cells[8,8] =   this->str_ExcelInfo[11]; 

					 try{
						 //Microsoft::Office::Interop::Excel::Picture^ pics = (Microsoft::Office::Interop::Excel::Picture^) (ws->Pictures(1));
						 Microsoft::Office::Interop::Excel::Range^ oRange = (Microsoft::Office::Interop::Excel::Range^)ws->UsedRange->Cells[5,12];
						 /*
						 Image^ oImage = Image::FromFile( this->str_ExcelInfo[16] );
						 System::Windows::Forms::Clipboard::SetDataObject(oImage,true);
						 ws->Paste(oRange,this->str_ExcelInfo[16]);*/
						 ws->Shapes->AddPicture(this->str_ExcelInfo[16], Microsoft::Office::Core::MsoTriState::msoFalse ,  
							 Microsoft::Office::Core::MsoTriState::msoCTrue , 604, 69, 120, 50);
						 //张拉顺序示意图
					 }
					 catch(Exception ^ ex) {
					 }

					 String ^ curHoleName ;
					 String ^ HoleSeqName ;
					 String ^ xingChenSeqName ;

					 String ^ compareHoleName ;
					 int kongSerial = -1;
					 int xingChenSerial = 0; 
					 int holeIndex;
					 int firstCalcute;
					 int temp; 
					 float totalLen;

					 if( !bExitRecord ) {
						 sqlStr = sqlStr + L"Insert into 张拉表" 
							 + L" (梁号,张拉时间 , 张拉次数 ";
						 sqlStr = sqlStr + L") VALUES ( '" + this->textBox_liangHao->Text->Trim() + L"' , '"
							 + GetDateTimeInfo.ToShortDateString() + L"' , '"
							 + zhanglaSeq + L"  ')" ;
						 writeSql( sqlStr );
					 }


					 for(i = 0 ; i < genHoleCount; i++)
						 this->multiZhangLa[i] = false;   
					 //chuYingLi
					 for(i = 0 ; i < genHoleCount; i++)
					 {
						 curHoleName = m_ZhangLaParameterView.str_dataGrid[i * 9 + 1];
						 if( this->multiZhangLa[ i ] == true) 
							 continue;
						 kongSerial ++;
						 ws->UsedRange->Cells[10 + kongSerial * 4,1] = curHoleName;

						 xingChenSerial = 0; 
						 totalLen = 0;
						 firstCalcute = 1;
						 sqlStr = "";

						 HoleSeqName = L"孔" + System::Convert::ToString(kongSerial+1);

						 for(holeIndex = 0; holeIndex < zhangLaCount; holeIndex ++) {
							 if( this->str_holeInfo[holeIndex * 4] &&  this->str_holeInfo[holeIndex * 4]->Length > 0 ) {
								 compareHoleName =this->str_holeInfo[holeIndex * 4];
								 int minLen2 = curHoleName->Length > compareHoleName->Length
									 ? compareHoleName->Length : curHoleName->Length;
								 int resultCompare2 = String::Compare(compareHoleName,0,curHoleName,0,minLen2,StringComparison::OrdinalIgnoreCase);

								 if( resultCompare2== 0 ){ 
									 temp =  holeIndex * 4;  
									 break;
								 }
							 }
						 }
						 //accLen[ CurzhangLaSeq * 3]         accMpa[ CurzhangLaSeq * 3]
						 for(holeIndex = i; holeIndex < genHoleCount; holeIndex ++) {
							 compareHoleName = m_ZhangLaParameterView.str_dataGrid[holeIndex * 9 + 1];
							 float mpaToKn;
							 int minLen = curHoleName->Length > compareHoleName->Length
								 ? compareHoleName->Length : curHoleName->Length;
							 int resultCompare = String::Compare(compareHoleName,0,curHoleName,0,minLen,StringComparison::OrdinalIgnoreCase);
							 // m_ZhangLaParameterView.str_dataGrid[holeIndex * 9 + 1]->Contains( curHoleName );
							 if( resultCompare == 0 ) {

								 float theoryLali =	System::Convert::ToSingle(this->str_holeInfo[ temp + 2]);
								 totalLen = calcCurExtend(holeIndex,0 );
								 if( totalLen  > 0 )
									 ws->UsedRange->Cells[10 + kongSerial * 4, 10 ] = totalLen; 
								 if( sqlStr == "" )
									 sqlStr =  L"Update 张拉表"	+ L" SET " + HoleSeqName + "名称 = '"  + curHoleName;
								 if( this->multiZhangLa[ holeIndex ] == false) {
									 this->multiZhangLa[ holeIndex ] = true;
									 xingChenSeqName = getXingChenName( xingChenSerial );
									 if( accLen2[ holeIndex * 3] > 0 ) {
										 ws->UsedRange->Cells[10 + kongSerial * 4 + 3,4 + xingChenSerial] = accLen2[ holeIndex * 3];
										// sqlStr = sqlStr  + L"' , " + HoleSeqName  +  xingChenSeqName + "行程伸长量从 = '"  + accLen2[ holeIndex * 3] ;
									 }

									 if( accMpa2[ holeIndex * 3] > 0 ) {
										 mpaToKn = ((int)( (accMpa2[ holeIndex * 3] - System::Convert::ToSingle ( this->huiGuiXiShu[3] ) ) / System::Convert::ToSingle ( this->huiGuiXiShu[2] ) * 100 ) ) / 100.0;

										 ws->UsedRange->Cells[10 + kongSerial * 4 + 2,4 + xingChenSerial] = accMpa2[ holeIndex * 3] ;
										// sqlStr = sqlStr  + L"' , " + HoleSeqName  +  xingChenSeqName + "行程张拉力从 = '"  + mpaToKn;
									 }

									 if( accLen[ holeIndex * 3] > 0 ){
										 ws->UsedRange->Cells[10 + kongSerial * 4 + 1,4 + xingChenSerial] = accLen[ holeIndex * 3];
										// sqlStr = sqlStr  + L"' , " + HoleSeqName  +  xingChenSeqName + "行程伸长量主 = '"  + accLen[ holeIndex * 3] ;
									 }

									 if( accMpa[ holeIndex * 3] > 0 ) {
										 mpaToKn = ((int)(  (accMpa[ holeIndex * 3] - System::Convert::ToSingle ( this->huiGuiXiShu[1] ) ) / System::Convert::ToSingle ( this->huiGuiXiShu[0] ) * 100 ) ) / 100.0;

										 ws->UsedRange->Cells[10 + kongSerial * 4,4 + xingChenSerial] = accMpa[ holeIndex * 3] ;
										// sqlStr = sqlStr  + L"' , " + HoleSeqName  +  xingChenSeqName + "行程张拉力主 = '"  + mpaToKn;
									 }

									 xingChenSerial++;
									 xingChenSeqName = getXingChenName( xingChenSerial );
									 if( accLen2[ holeIndex * 3 + 1] > 0 ){
										 ws->UsedRange->Cells[10 + kongSerial * 4 + 3,4 + xingChenSerial] = accLen2[ holeIndex * 3 + 1];
										 //sqlStr = sqlStr  + L"' , " + HoleSeqName  +  xingChenSeqName + "行程伸长量从 = '"  + accLen2[ holeIndex * 3 + 1] ;
									 }

									 if( accMpa2[ holeIndex * 3 + 1] > 0 ){
										 mpaToKn = ((int)( (accMpa2[ holeIndex * 3 +1] - System::Convert::ToSingle ( this->huiGuiXiShu[3] ) ) / System::Convert::ToSingle ( this->huiGuiXiShu[2] ) * 100 ) ) / 100.0;

										 ws->UsedRange->Cells[10 + kongSerial * 4 + 2,4 + xingChenSerial] = accMpa2[ holeIndex * 3 +1] ;
										// sqlStr = sqlStr  + L"' , " + HoleSeqName  +  xingChenSeqName + "行程张拉力从 = '"  +  mpaToKn ;
										/* if( xingChenSerial == 4) {
											 sqlStr = sqlStr  + L"' ," + HoleSeqName  +	"理论张拉力从 = '"  + this->str_holeInfo[ temp + 2] ;
											 sqlStr = sqlStr  + L"' ," + HoleSeqName  +	"实际张拉力从 = '"  +  System::Convert::ToString(mpaToKn); 
											 sqlStr = sqlStr  + L"' ," + HoleSeqName  +	"张拉力误差从 = '"  +  System::Convert::ToString(mpaToKn - theoryLali); 
											 sqlStr = sqlStr  + L"' ," + HoleSeqName  +	"张拉力误差率从 = '"  +  System::Convert::ToString( ((int) ((mpaToKn - theoryLali)/theoryLali  * 10000) ) /10000.0);
										 }*/
									 }

									 if( accLen[ holeIndex * 3 + 1] > 0 ) {
										 ws->UsedRange->Cells[10 + kongSerial * 4 + 1,4 + xingChenSerial] = accLen[ holeIndex * 3 + 1];
										 //sqlStr = sqlStr  + L"' , " + HoleSeqName  +  xingChenSeqName + "行程伸长量主 = '"  + accLen[ holeIndex * 3 + 1] ;
									 }

									 if( accMpa[ holeIndex * 3 + 1] > 0 ) {
										 mpaToKn = ((int)( (accMpa[ holeIndex * 3 + 1] - System::Convert::ToSingle ( this->huiGuiXiShu[1] ) ) / System::Convert::ToSingle ( this->huiGuiXiShu[0] ) * 100 ) ) / 100.0;

										 ws->UsedRange->Cells[10 + kongSerial * 4,4 + xingChenSerial] = accMpa[ holeIndex * 3 + 1];
										// sqlStr = sqlStr  + L"' , " + HoleSeqName  +  xingChenSeqName + "行程张拉力主 = '"  +  mpaToKn;
										 if( xingChenSerial == 4) {
											// sqlStr = sqlStr  + L"' ," + HoleSeqName  +	"理论张拉力主 = '"  + this->str_holeInfo[ temp + 2] ;
											// sqlStr = sqlStr  + L"' ," + HoleSeqName  +	"实际张拉力主 = '"  +  System::Convert::ToString( mpaToKn ); 

											 float theoryLali =  System::Convert::ToSingle(this->str_holeInfo[ temp + 2]);
											// sqlStr = sqlStr  + L"' ," + HoleSeqName  +	"张拉力误差主 = '"  +  System::Convert::ToString(mpaToKn - theoryLali); 
											// sqlStr = sqlStr  + L"' ," + HoleSeqName  +	"张拉力误差率主 = '"  +  System::Convert::ToString( ((int) ((mpaToKn - theoryLali)/theoryLali  * 10000) ) /10000.0); 
										 }
									 }
									 sqlStr = sqlStr + L"' WHERE 梁号 ='" + this->textBox_liangHao->Text->Trim() + L"'";  
									 writeSql( sqlStr );
									 xingChenSerial++;
									 sqlStr =  L"Update 张拉表"	+ L" SET " + HoleSeqName + "名称 = '"  + curHoleName;

									 if( m_ZhangLaParameterView.str_dataGrid[holeIndex * 9 + 6]->Length > 1 &&
										 abs( (int)(System::Convert::ToSingle( m_ZhangLaParameterView.str_dataGrid[holeIndex * 9 + 6]) - System::Convert::ToSingle(this->str_holeInfo[ temp + 2] ) )) < 3  ){
											 xingChenSerial = xingChenSerial+2;
											 xingChenSeqName = getXingChenName( xingChenSerial );

											 if( accMpa[ holeIndex * 3 + 2] > 0 ) {
												 mpaToKn = ((int)( (accMpa[ holeIndex * 3 + 2] - System::Convert::ToSingle ( this->huiGuiXiShu[1] ) ) / System::Convert::ToSingle ( this->huiGuiXiShu[0] ) * 100 ) ) / 100.0;

												 ws->UsedRange->Cells[10 + kongSerial * 4,4 + xingChenSerial] = 		accMpa[ holeIndex * 3 + 2];
												// if( xingChenSerial < 5)
												//	 sqlStr = sqlStr  + L"' ," + HoleSeqName  +  xingChenSeqName + "行程张拉力主 = '"  + mpaToKn;

												// sqlStr = sqlStr  + L"' ," + HoleSeqName  +	"理论张拉力主 = '"  + this->str_holeInfo[ temp + 2] ;
												// sqlStr = sqlStr  + L"' ," + HoleSeqName  +	"实际张拉力主 = '"  +  System::Convert::ToString( mpaToKn ); 

												// sqlStr = sqlStr  + L"' ," + HoleSeqName  +	"张拉力误差主 = '"  +  System::Convert::ToString(mpaToKn - theoryLali); 
												// sqlStr = sqlStr  + L"' ," + HoleSeqName  +	"张拉力误差率主 = '"  +  System::Convert::ToString( ((int) ((mpaToKn - theoryLali)/theoryLali  * 10000) ) /10000.0); 

											 }

											 if( accLen[ holeIndex * 3 + 2] > 0 ) {
												 ws->UsedRange->Cells[10 + kongSerial * 4 + 1,4 + xingChenSerial] = accLen[ holeIndex * 3 + 2];
												// if( xingChenSerial < 5)
												//	 sqlStr = sqlStr  + L"' ," + HoleSeqName  +  xingChenSeqName + "行程伸长量主 = '"  + accLen[ holeIndex * 3 + 2] ;
											 }

											 if( accMpa2[ holeIndex * 3 + 2] > 0 ) {
												 mpaToKn = ((int)( (accMpa2[ holeIndex * 3 + 2] - System::Convert::ToSingle ( this->huiGuiXiShu[3] ) ) / System::Convert::ToSingle ( this->huiGuiXiShu[2] ) * 100 ) ) / 100.0;
												 ws->UsedRange->Cells[10 + kongSerial * 4 + 2,4 + xingChenSerial] = accMpa2[ holeIndex * 3 + 2] ;
												// if( xingChenSerial < 5)
												//	 sqlStr = sqlStr  + L"' ," + HoleSeqName  +  xingChenSeqName + "行程张拉力从 = '"  + mpaToKn ;

											//	 sqlStr = sqlStr  + L"' ," + HoleSeqName  +	"理论张拉力从 = '"  + this->str_holeInfo[ temp + 2] ;
											//	 sqlStr = sqlStr  + L"' ," + HoleSeqName  +	"实际张拉力从 = '"  +  System::Convert::ToString(mpaToKn); 
											//	 sqlStr = sqlStr  + L"' ," + HoleSeqName  +	"张拉力误差从 = '"  +  System::Convert::ToString(mpaToKn - theoryLali); 
											//	 sqlStr = sqlStr  + L"' ," + HoleSeqName  +	"张拉力误差率从 = '"  +  System::Convert::ToString( ((int) ((mpaToKn - theoryLali)/theoryLali  * 10000) ) /10000.0); 
											 }

											 if( accLen2[ holeIndex * 3 + 2] > 0 ){
												 ws->UsedRange->Cells[10 + kongSerial * 4 + 3,4 + xingChenSerial] = accLen2[ holeIndex * 3 + 2];
												// if( xingChenSerial < 5)
												//	 sqlStr = sqlStr  + L"' ," + HoleSeqName  +  xingChenSeqName + "行程伸长量从 = '"  + accLen2[ holeIndex * 3 + 2] ;
											 }

											 break;
									 }
									 else {
										 xingChenSeqName = getXingChenName( xingChenSerial );
										 if( accMpa2[ holeIndex * 3 + 2] > 0 ){
											 mpaToKn =((int)(  (accMpa2[ holeIndex * 3 + 2] - System::Convert::ToSingle ( this->huiGuiXiShu[3] ) ) / System::Convert::ToSingle ( this->huiGuiXiShu[2] ) * 100 ) ) / 100.0;

											 ws->UsedRange->Cells[10 + kongSerial * 4 + 2,4 + xingChenSerial] = accMpa2[ holeIndex * 3 + 2] ;
											// if( xingChenSerial < 5)
											//	 sqlStr = sqlStr  + L"' ," + HoleSeqName  +  xingChenSeqName + "行程张拉力从 = '"  + mpaToKn ;
										 }

										 if( accLen2[ holeIndex * 3 + 2] > 0 ){
											 ws->UsedRange->Cells[10 + kongSerial * 4 + 3,4 + xingChenSerial] = accLen2[ holeIndex * 3 + 2];
											// if( xingChenSerial < 5)
											//	 sqlStr = sqlStr  + L"' ," + HoleSeqName  +  xingChenSeqName + "行程伸长量从 = '"  + accLen2[ holeIndex * 3 + 2] ;
										 }

										 if( accMpa[ holeIndex * 3 + 2] > 0 ){
											 mpaToKn = ((int)( (accMpa[ holeIndex * 3 + 2] - System::Convert::ToSingle ( this->huiGuiXiShu[1] ) ) / System::Convert::ToSingle ( this->huiGuiXiShu[0] ) * 100 ) ) / 100.0;

											 ws->UsedRange->Cells[10 + kongSerial * 4,4 + xingChenSerial] = 	accMpa[ holeIndex * 3 + 2];
											// if( xingChenSerial < 5)
											//	 sqlStr = sqlStr  + L"' ," + HoleSeqName  +  xingChenSeqName + "行程张拉力主 = '"  +  mpaToKn;
										 }

										 if( accLen[ holeIndex * 3 + 2] > 0 ){
											 ws->UsedRange->Cells[10 + kongSerial * 4 + 1,4 + xingChenSerial] = accLen[ holeIndex * 3 + 2];
											// if( xingChenSerial < 5)
											//	 sqlStr = sqlStr  + L"' ," + HoleSeqName  +  xingChenSeqName + "行程伸长量主 = '"  + accLen[ holeIndex * 3 + 2] ;
										 }

										 xingChenSerial++;
									 }
								 }
							 }
						 }

						 sqlStr = sqlStr + L"' WHERE 梁号 ='" + this->textBox_liangHao->Text->Trim() + L"'";  

						 writeSql( sqlStr );

						 sqlStr =  L"Update 张拉表"	+ L" SET " + HoleSeqName + "名称 = '"  + curHoleName;

						 sqlStr = sqlStr  + L"' ," + HoleSeqName  +	"理论伸长量 = '"  + this->str_holeInfo[ temp + 3] ;
						 ws->UsedRange->Cells[10 + kongSerial * 4,9] = System::Convert::ToSingle(this->str_holeInfo[ temp + 2] );
						 ws->UsedRange->Cells[10 + kongSerial * 4 + 2,9] = System::Convert::ToSingle(this->str_holeInfo[ temp + 2] );
						 ws->UsedRange->Cells[10 + kongSerial * 4,11] = System::Convert::ToSingle(this->str_holeInfo[ temp + 3]) ;
						 if(  (System::Convert::ToSingle(this->str_holeInfo[ temp + 3]) > 0) && ( totalLen  > 0 ) ) {
							 float totalLenDis =  totalLen - System::Convert::ToSingle(this->str_holeInfo[ temp + 3]);
							 sqlStr = sqlStr  + L"' ," + HoleSeqName  +	"实际伸长量 = '"  + System::Convert::ToString(totalLen); 
							 sqlStr = sqlStr  + L"' ," + HoleSeqName  +	"误差伸长量 = '"  + System::Convert::ToString(totalLenDis); 
							 totalLenDis =((int)( ( totalLenDis ) / System::Convert::ToSingle(this->str_holeInfo[ temp + 3]) *100)) / 100.0;
							 sqlStr = sqlStr  + L"' ," + HoleSeqName  +	"伸长量误差率 = '"  + System::Convert::ToString(totalLenDis); 
							 ws->UsedRange->Cells[10 + kongSerial * 4, 12 ] =  totalLenDis * 100;  //延伸量误差
						 }

						 sqlStr = sqlStr + L"' WHERE 梁号 ='" + this->textBox_liangHao->Text->Trim() + L"'";  

						 writeSql( sqlStr );
					 }



					 //	 Microsoft::Office::Interop::Excel::Range^ range1 = (Microsoft::Office::Interop::Excel::Range ^)ws->Range( obPara1, obPara1);
					 //range1->Value = "lhg";
					 // range1->get(2);   System::Environment::CurrentDirectory + "\\data\\"
					 wb->Close(true,fileNameXls,true);
					 /*	 if ( bExitFile )
					 wb->Save();
					 else
					 wb->SaveAs ( fileNameXls , missing,  missing, missing, missing, missing, Microsoft::Office::Interop::Excel::XlSaveAsAccessMode::xlNoChange, missing, 3 , missing, missing, missing);
					 */
					 if( genHoleCount >= zhangLaCount) {
						 xlApp->Visible = true;  //xlApp->UserControl = true;

						 wb = wbs->Open(fileNameXls,missing ,true,missing,missing,missing,missing, missing,missing,false,false,missing,false,missing,missing);
						 ws = (Microsoft::Office::Interop::Excel::Worksheet^)wb->Worksheets[1];
						 ws->UsedRange->Cells[5,5] =  "";
					 }
				 }
				 catch (Exception ^ ex)
				 {

				 }


				 xlApp->Quit();  
				 return true;

			 }
	private: System::Void button_history_Click(System::Object^  sender, System::EventArgs^  e) {
				 OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
				 openFileDialog->InitialDirectory = m_systemSet.textBox1->Text + "\\" ;
				 openFileDialog->Filter="*.jcd|*.jcd";
				 //openFileDialog->RestoreDirectory = true;
				 openFileDialog->FilterIndex=1;
				 if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				 {
					 m_historyForm.pFilePath = (char*)(void*)Marshal::StringToHGlobalAnsi( openFileDialog->FileName );
					 m_historyForm.ShowDialog();
				 }

			 }
	private: System::Void button_Reset_Click(System::Object^  sender, System::EventArgs^  e) {
				// if( ZhangLaStatus != ZHANGLA_RUN ) 
				 //{
					 static System::Windows::Forms::DialogResult result;
					 result=MessageBox::Show("是否确定要复位?","复位信息",MessageBoxButtons::YesNo);
					 if(result==System::Windows::Forms::DialogResult::Yes)
					 {
						 ResetAll( );
						// File::Delete("..//Debug//1.dat");
					 }
					 return ;
				// }
				// else
				//	 MessageBox::Show("请先暂停张拉!");
			 }
	private: System::Void pictureBox_Mpa1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
				 int i = 0;
				 int iStart = 1;

				 if( absReadOpcIndex > GRAPH_X_NUM ) {
					 GRAPH_GRID_SECOND = GRAPH_GRID_SECOND  + 5;
					 GRAPH_X_NUM = (GRAPH_GRID_SECOND * GRAPH_GRID_NUM );
				 }
				 //Invalidate(new Rectangle(0, 0, 1, 1));

				 Graphics^ graph = e->Graphics; //this->panel_MPA->CreateGraphics();
				 float prefMpa,prefMm,fMpa,fMm;

				 Pen^ Pen_black= gcnew Pen( System::Drawing::Color::Black ,1);
				 Pen^ Pen_gray= gcnew Pen( System::Drawing::Color::LightGray ,1);
				 Pen^ Pen_dash= gcnew Pen( System::Drawing::Color::Gray ,1);
				 Pen^ RedPen= gcnew Pen( System::Drawing::Color::Red ,2);
				 Pen^ BluePen= gcnew Pen( System::Drawing::Color::Blue ,2);
				 Pen_dash->DashStyle = System::Drawing::Drawing2D::DashStyle::DashDotDot;
				 System::Drawing::Font^ drawFont = gcnew System::Drawing::Font( "Arial",11 );
				 SolidBrush^ drawBrush = gcnew SolidBrush( Color::Black );
				 SolidBrush^ drawBrushWhite = gcnew SolidBrush( Color::White );
				 SolidBrush^ drawBrushRed = gcnew SolidBrush( Color::Red );
				 System::Drawing::StringFormat^ drawVertical = gcnew System::Drawing::StringFormat(StringFormatFlags::DirectionVertical);

				 Pen^ forColorPen= gcnew Pen( System::Drawing::Color::Red );


				 graph->DrawLine(Pen_black,graph1_x,graph1_y,graph1_x + GRAPH_WID,graph1_y);
				 graph->DrawLine(Pen_black,graph1_x,graph1_y,graph1_x ,graph1_y - GRAPH_HEIT);
				 graph->DrawString(System::Convert::ToString( 0 ),drawFont,drawBrush ,PointF((float) (graph1_x - 10) , (float)(graph1_y - 1)) );
				 //graph->DrawString("时间( S )",drawFont,drawBrushRed ,PointF( (float)(graph1_x + 4 * GRAPH_WID/GRAPH_GRID_NUM + 10) , (float)graph1_y ));
				 //graph->DrawString("压力( M pa )",drawFont,drawBrushRed ,PointF( (float)(graph1_x - 20),(float)(graph1_y	-  GRAPH_HEIT) ) ,drawVertical);
				 for(i = 1; i < GRAPH_GRID_NUM + 1; i++) {
					 graph->DrawString(System::Convert::ToString( i * GRAPH_GRID_SECOND ),drawFont,drawBrush ,PointF( (float)(graph1_x - 5  + i * GRAPH_WID/GRAPH_GRID_NUM), (float)(graph1_y - 1)) );
					 graph->DrawString(System::Convert::ToString( i * GRAPH_GRID_MPA),drawFont,drawBrush ,PointF( (float)(graph1_x - 20),(float)(graph1_y	- i * GRAPH_HEIT/GRAPH_GRID_NUM - 14)) );

					 if( i < GRAPH_GRID_NUM ){
						 graph->DrawLine(Pen_gray,graph1_x + i * GRAPH_WID/GRAPH_GRID_NUM, graph1_y, graph1_x + i * GRAPH_WID/GRAPH_GRID_NUM, graph1_y - GRAPH_HEIT);
						 graph->DrawLine(Pen_gray,graph1_x,graph1_y	- i * GRAPH_HEIT/GRAPH_GRID_NUM,graph1_x + GRAPH_WID,graph1_y - i * GRAPH_HEIT/GRAPH_GRID_NUM);
					 }
					 else {
						 graph->DrawLine(Pen_dash,graph1_x + i * GRAPH_WID/GRAPH_GRID_NUM, graph1_y, graph1_x + i * GRAPH_WID/GRAPH_GRID_NUM, graph1_y - GRAPH_HEIT);
						 graph->DrawLine(Pen_dash,graph1_x,graph1_y  - i * GRAPH_HEIT/GRAPH_GRID_NUM,graph1_x + GRAPH_WID,graph1_y - i * GRAPH_HEIT/GRAPH_GRID_NUM);
					 }
				 }
				 for(i = iStart; i < absReadOpcIndex; i++) {
					 fMpa = drawData[i].Mpa;
					 prefMpa = drawData[i -1].Mpa;
					 graph->DrawLine(BluePen,(float)( graph1_x + (i - iStart) * GRAPH_WID/GRAPH_X_NUM ), graph1_y - prefMpa * GRAPH_GRID_Y_RATIO_MPA, (float)(graph1_x + (i - iStart + 1) * GRAPH_WID/(float)GRAPH_X_NUM ) + 1, graph1_y - fMpa  * GRAPH_GRID_Y_RATIO_MPA + 1);
				 }
				 /*try{
				 if( this->p_comBase->opcReadData[0]->Quality == 192 ) 
				 graph->DrawLine( RedPen, (float)graph1_x,(float) (graph1_y - System::Convert::ToSingle(this->textBox_d1Mpa_des->Text) * GRAPH_GRID_Y_RATIO_MPA),(float)(graph1_x + GRAPH_WID),(float)( graph1_y  - System::Convert::ToSingle(this->textBox_d1Mpa_des->Text) * GRAPH_GRID_Y_RATIO_MPA) );
				 }
				 catch(Exception ^ ex) {
				 ;
				 } */
				 //delete graph;
			 }
	private: System::Void pictureBox_MM1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
				 int i = 0;
				 int iStart = 1;

				 if( absReadOpcIndex > GRAPH_X_NUM ) {
					 GRAPH_GRID_SECOND = GRAPH_GRID_SECOND + 5;
					 GRAPH_X_NUM = (GRAPH_GRID_SECOND * GRAPH_GRID_NUM );
				 }
				 //Invalidate(new Rectangle(0, 0, 1, 1));

				 Graphics^ graph ;
				 float prefMm,fMm;

				 Pen^ Pen_black= gcnew Pen( System::Drawing::Color::Black ,1);
				 Pen^ Pen_gray= gcnew Pen( System::Drawing::Color::LightGray ,1);
				 Pen^ Pen_dash= gcnew Pen( System::Drawing::Color::Gray ,1);
				 Pen^ RedPen= gcnew Pen( System::Drawing::Color::Red ,2);
				 Pen^ BluePen= gcnew Pen( System::Drawing::Color::Blue ,2);
				 Pen_dash->DashStyle = System::Drawing::Drawing2D::DashStyle::DashDotDot;
				 System::Drawing::Font^ drawFont = gcnew System::Drawing::Font( "Arial",11 );
				 SolidBrush^ drawBrush = gcnew SolidBrush( Color::Black );
				 SolidBrush^ drawBrushWhite = gcnew SolidBrush( Color::White );
				 SolidBrush^ drawBrushRed = gcnew SolidBrush( Color::Red );
				 System::Drawing::StringFormat^ drawVertical = gcnew System::Drawing::StringFormat(StringFormatFlags::DirectionVertical);

				 Pen^ forColorPen= gcnew Pen( System::Drawing::Color::Red );
				 graph = e->Graphics; //this->panel_MM->CreateGraphics();

				 graph->DrawLine(Pen_black,graph1_x,graph1_y,graph1_x + GRAPH_WID,graph1_y);
				 graph->DrawLine(Pen_black,graph1_x,graph1_y,graph1_x ,graph1_y - GRAPH_HEIT);
				 graph->DrawString(System::Convert::ToString( 0 ),drawFont,drawBrush ,PointF( (float)(graph1_x - 10) ,(float)( graph1_y - 1)) );
				 //graph->DrawString("时间( S )",drawFont,drawBrushRed ,PointF( (float)(graph1_x + 4 * GRAPH_WID/GRAPH_GRID_NUM + 10) , (float)graph1_y ) );
				 //graph->DrawString("位移( mm )",drawFont,drawBrushRed ,PointF( (float)(graph1_x - 20),(float)(graph1_y -  GRAPH_HEIT )) ,drawVertical);

				 for(i = 1; i < GRAPH_GRID_NUM + 1; i++) {
					 graph->DrawString(System::Convert::ToString( i * GRAPH_GRID_SECOND ),drawFont,drawBrush ,PointF( (float)(graph1_x  - 11 + i * GRAPH_WID/GRAPH_GRID_NUM),(float) (graph1_y - 1)) );
					 graph->DrawString(System::Convert::ToString( i * GRAPH_GRID_MM),drawFont,drawBrush ,PointF( (float)(graph1_x - 20),(float)(graph1_y	- i * GRAPH_HEIT/GRAPH_GRID_NUM - 14)) );
					 if( i < GRAPH_GRID_NUM ){
						 graph->DrawLine(Pen_gray,graph1_x + i * GRAPH_WID/GRAPH_GRID_NUM, graph1_y, graph1_x + i * GRAPH_WID/GRAPH_GRID_NUM, graph1_y - GRAPH_HEIT);
						 graph->DrawLine(Pen_gray,graph1_x,graph1_y  - i * GRAPH_HEIT/GRAPH_GRID_NUM,graph1_x + GRAPH_WID,graph1_y - i * GRAPH_HEIT/GRAPH_GRID_NUM);
					 }
					 else {
						 graph->DrawLine(Pen_dash,graph1_x + i * GRAPH_WID/GRAPH_GRID_NUM, graph1_y, graph1_x + i * GRAPH_WID/GRAPH_GRID_NUM, graph1_y - GRAPH_HEIT);
						 graph->DrawLine(Pen_dash,graph1_x,graph1_y  - i * GRAPH_HEIT/GRAPH_GRID_NUM,graph1_x + GRAPH_WID,graph1_y - i * GRAPH_HEIT/GRAPH_GRID_NUM);
					 }
				 }


				 for(i = iStart; i < absReadOpcIndex; i++) {
					 fMm = drawData[i ].Mm;
					 prefMm = drawData[i- 1].Mm;
					 graph->DrawLine(BluePen,(float)(graph1_x + (i - iStart) * GRAPH_WID/GRAPH_X_NUM ), graph1_y - prefMm * GRAPH_GRID_Y_RATIO_MM, (float)( graph1_x + (i - iStart + 1) * GRAPH_WID/(float)GRAPH_X_NUM ) + 1,graph1_y - fMm * GRAPH_GRID_Y_RATIO_MM + 1);
				 }
				 //e->Graphics->DrawImage(myBitmap,30,600,400,400 );
				 //graph->Dispose();
				 //delete graph;

			 }
	private: System::Void pictureBox_Mpa2_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
				 int i = 0;
				 int iStart = 1;

				 if( absReadOpcIndex > GRAPH_X_NUM ) {
					 GRAPH_GRID_SECOND = GRAPH_GRID_SECOND + 5;
					 GRAPH_X_NUM = (GRAPH_GRID_SECOND * GRAPH_GRID_NUM );
				 }
				 //Invalidate(new Rectangle(0, 0, 1, 1));

				 Graphics^ graph ;
				 float prefMpa,fMpa;

				 Pen^ Pen_black= gcnew Pen( System::Drawing::Color::Black ,1);
				 Pen^ Pen_gray= gcnew Pen( System::Drawing::Color::LightGray ,1);
				 Pen^ Pen_dash= gcnew Pen( System::Drawing::Color::Gray ,1);
				 Pen^ RedPen= gcnew Pen( System::Drawing::Color::Red ,2);
				 Pen^ BluePen= gcnew Pen( System::Drawing::Color::Blue ,2);
				 Pen_dash->DashStyle = System::Drawing::Drawing2D::DashStyle::DashDotDot;
				 System::Drawing::Font^ drawFont = gcnew System::Drawing::Font( "Arial",11 );
				 SolidBrush^ drawBrush = gcnew SolidBrush( Color::Black );
				 SolidBrush^ drawBrushWhite = gcnew SolidBrush( Color::White );
				 SolidBrush^ drawBrushRed = gcnew SolidBrush( Color::Red );
				 System::Drawing::StringFormat^ drawVertical = gcnew System::Drawing::StringFormat(StringFormatFlags::DirectionVertical);

				 Pen^ forColorPen= gcnew Pen( System::Drawing::Color::Red );
				 graph = e->Graphics;
				 // SmoothingMode oldMode = graph->GetSmoothingMode();
				 //e->Graphics->Clear(Color::White);
				 //graph->FillRectangle(drawBrushWhite , graph1_x,graph1_y, GRAPH_WID, GRAPH_HEIT);
				 graph->DrawLine(Pen_black,graph1_x,graph1_y,graph1_x + GRAPH_WID,graph1_y);
				 graph->DrawLine(Pen_black,graph1_x,graph1_y,graph1_x ,graph1_y - GRAPH_HEIT);
				 graph->DrawString(System::Convert::ToString( 0 ),drawFont,drawBrush ,PointF((float) (graph1_x - 10) , (float)(graph1_y - 1)) );
				 //graph->DrawString("时间( S )",drawFont,drawBrushRed ,PointF( (float)(graph1_x + 4 * GRAPH_WID/GRAPH_GRID_NUM + 10) , (float)graph1_y ));
				 //graph->DrawString("压力( M pa )",drawFont,drawBrushRed ,PointF( (float)(graph1_x - 20),(float)(graph1_y	-  GRAPH_HEIT) ) ,drawVertical);
				 for(i = 1; i < GRAPH_GRID_NUM + 1; i++) {
					 graph->DrawString(System::Convert::ToString( i * GRAPH_GRID_SECOND ),drawFont,drawBrush ,PointF( (float)(graph1_x - 5 + i * GRAPH_WID/GRAPH_GRID_NUM), (float)(graph1_y - 1)) );
					 graph->DrawString(System::Convert::ToString( i * GRAPH_GRID_MPA),drawFont,drawBrush ,PointF( (float)(graph1_x - 20),(float)(graph1_y	- i * GRAPH_HEIT/GRAPH_GRID_NUM - 14)) );
					 if( i < GRAPH_GRID_NUM ){
						 graph->DrawLine(Pen_gray,graph1_x + i * GRAPH_WID/GRAPH_GRID_NUM, graph1_y, graph1_x + i * GRAPH_WID/GRAPH_GRID_NUM, graph1_y - GRAPH_HEIT);
						 graph->DrawLine(Pen_gray,graph1_x,graph1_y	- i * GRAPH_HEIT/GRAPH_GRID_NUM,graph1_x + GRAPH_WID,graph1_y - i * GRAPH_HEIT/GRAPH_GRID_NUM);
					 }
					 else {
						 graph->DrawLine(Pen_dash,graph1_x + i * GRAPH_WID/GRAPH_GRID_NUM, graph1_y, graph1_x + i * GRAPH_WID/GRAPH_GRID_NUM, graph1_y - GRAPH_HEIT);
						 graph->DrawLine(Pen_dash,graph1_x,graph1_y  - i * GRAPH_HEIT/GRAPH_GRID_NUM,graph1_x + GRAPH_WID,graph1_y - i * GRAPH_HEIT/GRAPH_GRID_NUM);
					 }
				 }
				 /*
				 try{
				 if( this->p_comBase->opcReadData[0]->Quality == 192 ) 
				 graph->DrawLine( RedPen, (float)graph1_x,(float) (graph1_y - System::Convert::ToSingle(this->textBox_d2Mpa_des->Text) * GRAPH_GRID_Y_RATIO_MPA),(float)(graph1_x + GRAPH_WID),(float)( graph1_y  - System::Convert::ToSingle(this->textBox_d2Mpa_des->Text) * GRAPH_GRID_Y_RATIO_MPA) );
				 }
				 catch(Exception ^ ex) {
				 ;
				 } */
				 for(i = iStart; i < absReadOpcIndex; i++) {
					 fMpa = drawData[i  ].Mpa2;
					 prefMpa = drawData[i- 1].Mpa2;
					 graph->DrawLine(BluePen,(float)( graph1_x + (i - iStart) * GRAPH_WID/GRAPH_X_NUM ), graph1_y - prefMpa * GRAPH_GRID_Y_RATIO_MPA, (float)(graph1_x + (i - iStart + 1) * GRAPH_WID/(float)GRAPH_X_NUM ) + 1, graph1_y - fMpa  * GRAPH_GRID_Y_RATIO_MPA + 1);
				 }

				 //graph->Dispose();
				 //delete graph;
			 }
	private: System::Void pictureBox_MM2_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
				 int i = 0;
				 int iStart = 1;

				 if( absReadOpcIndex > GRAPH_X_NUM ) {
					 GRAPH_GRID_SECOND = GRAPH_GRID_SECOND  + 5;
					 GRAPH_X_NUM = (GRAPH_GRID_SECOND * GRAPH_GRID_NUM);
				 }
				 //Invalidate(new Rectangle(0, 0, 1, 1));

				 Graphics^ graph ;
				 float prefMm,fMm;

				 Pen^ Pen_black= gcnew Pen( System::Drawing::Color::Black ,1);
				 Pen^ Pen_gray= gcnew Pen( System::Drawing::Color::LightGray ,1);
				 Pen^ Pen_dash= gcnew Pen( System::Drawing::Color::Gray ,1);
				 Pen^ RedPen= gcnew Pen( System::Drawing::Color::Red ,2);
				 Pen^ BluePen= gcnew Pen( System::Drawing::Color::Blue ,2);
				 Pen_dash->DashStyle = System::Drawing::Drawing2D::DashStyle::DashDotDot;
				 System::Drawing::Font^ drawFont = gcnew System::Drawing::Font( "Arial",11 );
				 SolidBrush^ drawBrush = gcnew SolidBrush( Color::Black );
				 SolidBrush^ drawBrushWhite = gcnew SolidBrush( Color::White );
				 SolidBrush^ drawBrushRed = gcnew SolidBrush( Color::Red );
				 System::Drawing::StringFormat^ drawVertical = gcnew System::Drawing::StringFormat(StringFormatFlags::DirectionVertical);

				 Pen^ forColorPen= gcnew Pen( System::Drawing::Color::Red );

				 graph =  e->Graphics;//this->panel2_MM->CreateGraphics();

				 graph->DrawLine(Pen_black,graph1_x,graph1_y,graph1_x + GRAPH_WID,graph1_y);
				 graph->DrawLine(Pen_black,graph1_x,graph1_y,graph1_x ,graph1_y - GRAPH_HEIT);
				 graph->DrawString(System::Convert::ToString( 0 ),drawFont,drawBrush ,PointF( (float)(graph1_x - 10) ,(float)( graph1_y - 1)) );
				 //graph->DrawString("时间( S )",drawFont,drawBrushRed ,PointF( (float)(graph1_x + 4 * GRAPH_WID/GRAPH_GRID_NUM + 10) , (float)graph1_y ) );
				 //graph->DrawString("位移( mm )",drawFont,drawBrushRed ,PointF( (float)(graph1_x - 20),(float)(graph1_y -  GRAPH_HEIT )) ,drawVertical);

				 for(i = 1; i < GRAPH_GRID_NUM + 1; i++) {
					 graph->DrawString(System::Convert::ToString( i * GRAPH_GRID_SECOND ),drawFont,drawBrush ,PointF( (float)(graph1_x-11 + i * GRAPH_WID/GRAPH_GRID_NUM),(float) (graph1_y - 1)) );
					 graph->DrawString(System::Convert::ToString( i * GRAPH_GRID_MM),drawFont,drawBrush ,PointF( (float)(graph1_x - 20),(float)(graph1_y	- i * GRAPH_HEIT/GRAPH_GRID_NUM - 7)) );
					 if( i < GRAPH_GRID_NUM ){
						 graph->DrawLine(Pen_gray,graph1_x + i * GRAPH_WID/GRAPH_GRID_NUM, graph1_y, graph1_x + i * GRAPH_WID/GRAPH_GRID_NUM, graph1_y - GRAPH_HEIT);
						 graph->DrawLine(Pen_gray,graph1_x,graph1_y  - i * GRAPH_HEIT/GRAPH_GRID_NUM,graph1_x + GRAPH_WID,graph1_y - i * GRAPH_HEIT/GRAPH_GRID_NUM);
					 }
					 else {
						 graph->DrawLine(Pen_dash,graph1_x + i * GRAPH_WID/GRAPH_GRID_NUM, graph1_y, graph1_x + i * GRAPH_WID/GRAPH_GRID_NUM, graph1_y - GRAPH_HEIT);
						 graph->DrawLine(Pen_dash,graph1_x,graph1_y  - i * GRAPH_HEIT/GRAPH_GRID_NUM,graph1_x + GRAPH_WID,graph1_y - i * GRAPH_HEIT/GRAPH_GRID_NUM);
					 }
				 }

				 for(i = iStart; i < absReadOpcIndex; i++) {
					 fMm = drawData[i  ].Mm2;
					 prefMm = drawData[i- 1].Mm2;
					 graph->DrawLine(BluePen,(float)(graph1_x + (i - iStart) * GRAPH_WID/GRAPH_X_NUM ), graph1_y - prefMm * GRAPH_GRID_Y_RATIO_MM, (float)( graph1_x + (i - iStart + 1) * GRAPH_WID/(float)GRAPH_X_NUM ) + 1,graph1_y - fMm * GRAPH_GRID_Y_RATIO_MM + 1);
				 }

				 //graph->Dispose();
				 //delete graph;
			 }
	private: System::Void controlMachine_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
				 if(CurzhangLaSeq + 1 == zhangLaCount){
				 filePath = m_systemSet.textBox1->Text + "\\" + this->textBox_liangHao->Text + "\\" 
					 + System::Convert::ToString( 1) + "-" + m_ZhangLaParameterView.str_dataGrid[1] + ".jcd";
				 konghao_over=-1;
				 }
				 else{
				 filePath = m_systemSet.textBox1->Text + "\\" + this->textBox_liangHao->Text + "\\" 
					 + System::Convert::ToString( CurzhangLaSeq + 2) + "-" + m_ZhangLaParameterView.str_dataGrid[(CurzhangLaSeq+1) * 9 + 1] + ".jcd";
				 }
				 if (( e->KeyValue == 0x28 ) && (e->Control == true) ){
					 if( connectStatus == true ) {
						 System::Windows::Forms::DialogResult  r1;
						 r1 = MessageBox::Show("跳过当前张拉:  " + this->listBox1->Items[CurzhangLaSeq ]->ToString() + "  " ,"张拉顺序控制", MessageBoxButtons::YesNoCancel, MessageBoxIcon::Question,MessageBoxDefaultButton::Button2);
						 if( r1 == System::Windows::Forms::DialogResult::Yes){
							 if(File::Exists( filePath)){
							 System::Windows::Forms::DialogResult  r2;
							 if(CurzhangLaSeq + 1 == zhangLaCount)
								r2=MessageBox::Show("下一次张拉文件已存在,是否覆盖文件  :" + System::Convert::ToString( 1) + "-" + m_ZhangLaParameterView.str_dataGrid[1] + ".jcd" + "  " ,"张拉顺序控制", MessageBoxButtons::YesNoCancel, MessageBoxIcon::Question,MessageBoxDefaultButton::Button2);
							 else
								r2 = MessageBox::Show("下一次张拉文件已存在,是否覆盖文件  :" + System::Convert::ToString( CurzhangLaSeq + 2) + "-" + m_ZhangLaParameterView.str_dataGrid[(CurzhangLaSeq+1) * 9 + 1] + ".jcd" + "  " ,"张拉顺序控制", MessageBoxButtons::YesNoCancel, MessageBoxIcon::Question,MessageBoxDefaultButton::Button2);
								if(r2 == System::Windows::Forms::DialogResult::Yes)
									File::Delete(filePath);
								else if(r2 == System::Windows::Forms::DialogResult::Cancel)
									return;
							 }
							 //saveDrawData(absReadOpcIndex,true);
							 e->Handled = true;
							 if( CurzhangLaSeq + 1 < zhangLaCount ) 
								 CurzhangLaSeq = CurzhangLaSeq + 1;
							 else
								 CurzhangLaSeq = 0;
							 this->listBox1->SelectedIndex = CurzhangLaSeq;
							 konghao_over++;
						 }
					 }
				 }
			 }
	private: System::Void btn_single_Click(System::Object^  sender, System::EventArgs^  e) {
						  static System::Windows::Forms::DialogResult result;
						  if(!Single_Zhangla)
						  {
							result=MessageBox::Show("是否使用单端张拉?","张拉信息",MessageBoxButtons::YesNo);
							if(result==System::Windows::Forms::DialogResult::Yes)
							{
							  //MessageBox::Show("已进入单端张拉模式!");
							  Single_Zhangla=true;
							  this->btn_single->Text="取消单端张拉";
							  this->btn_single->BackColor = System::Drawing::Color::Red;
							}
						  }
						  else
						  {
							  result=MessageBox::Show("是否取消单端张拉?","张拉信息",MessageBoxButtons::YesNo);
							  if(result==System::Windows::Forms::DialogResult::Yes){
							  Single_Zhangla=false;
							  this->btn_single->Text="开启单端张拉";
							  this->btn_single->BackColor=System::Drawing::SystemColors::Control;
							  }
						  }
					  }
			 System::Boolean WriteLastSet(){
				 StreamWriter pfile("..//Debug//1.dat");//=gcnew StreamWriter("..//Debug//1.txt");
				 pfile.WriteLine(startZhangLaMm1);
				 pfile.WriteLine(startZhangLaMm2);
				 pfile.WriteLine(ZhangLaStatus);
				 pfile.WriteLine(CurzhangLaSeq);
				 pfile.WriteLine(curXingCheng);
				 pfile.WriteLine(p_comBase->opcReadData[6]->DataValue);//第一行程结束
				 pfile.WriteLine(p_comBase->opcReadData[7]->DataValue);//第一行程进油
				 pfile.WriteLine(p_comBase->opcReadData[8]->DataValue);//2完
				 pfile.WriteLine(p_comBase->opcReadData[9]->DataValue);//2进
				 pfile.WriteLine(p_comBase->opcReadData[10]->DataValue);//3完
				 pfile.WriteLine(p_comBase->opcReadData[11]->DataValue);//3进
					 pfile.WriteLine("False");
				 pfile.Close();
				 return true;
			 }
			 System::Boolean ReadSet(){
				 StreamReader pfile("..//Debug//1.dat");
				 startZhangLaMm1=float::Parse(pfile.ReadLine());
				 startZhangLaMm2=float::Parse(pfile.ReadLine());
				 ZhangLaStatus=Int32::Parse(pfile.ReadLine());
				 CurzhangLaSeq=Int32::Parse(pfile.ReadLine());
				 listBox1->SelectedIndex=CurzhangLaSeq;
				 curXingCheng=float::Parse(pfile.ReadLine());
				 p_comBase->opcWriteData[6]=pfile.ReadLine();
				 p_comBase->opcWriteData[7]=pfile.ReadLine();
				 p_comBase->opcWriteData[8]=pfile.ReadLine();
				 p_comBase->opcWriteData[9]=pfile.ReadLine();
				 p_comBase->opcWriteData[10]=pfile.ReadLine();
				 p_comBase->opcWriteData[11]=pfile.ReadLine();
				 if (ZhangLaStatus==1||ZhangLaStatus==2)
				 {
					 ZhangLaStatus=2;
					 p_comBase->opcWriteDataParameter[0]=pfile.ReadLine();
					 MessageBox::Show(p_comBase->opcWriteDataParameter[0]->ToString());
				 }
				 pfile.Close();
				 this->p_comBase->gRInit = 0;
				 this->p_comBase->gOpcOperation = WRITE_OPC;
				 this->p_comBase->gOpcDataId   = IDW_OTHER;
				 this->p_comBase->gOpcDataId   |= IDW_START1;
				 if(!Single_Zhangla)
					 this->p_comBase->gOpcDataId   |= IDW_START2;
				 ReleaseSemaphore( this->p_comBase->semaphore,1,NULL);
				 return true;
			 }
			/* private: Boolean readMorecheck(String^ sqlString)  //读取梁号
					  {
						  Boolean retVal = false;
						  try {
							  System::String^ dataCon = L"Provider=Microsoft.Jet.OLEDB.4.0;Data Source=" + System::AppDomain::CurrentDomain->BaseDirectory->ToString() + L"\\jcData.mdb;Jet OLEDB:Database Password=jc123;Persist Security Info=False;";
							  OleDbConnection ^connection = gcnew OleDbConnection( dataCon );

							  OleDbCommand^ command = gcnew OleDbCommand();

							  command->Connection = connection;
							  try
							  {
								  connection->Open();
								  command->Connection = connection;
								  // Execute the commands.
								  command->CommandText = sqlString;//"select * from table2";
								  OleDbDataReader^ reader   =   command->ExecuteReader();
								  array<System::Object^>^  meta = gcnew array<System::Object^>(52); 
								  retVal = reader->Read();
								  int a=reader->GetValues(meta);
								  //MessageBox::Show(meta[30]->ToString());
								  More_check=float::Parse(meta[30]->ToString());
								  reader->Close();
							  }
							  catch (Exception^ ex)
							  {
								  MessageBox::Show(ex->Message,"读数据库失败", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
							  }

							  connection->Close(); 
						  }
						  catch (Exception^ ex)
						  {
						  }
						  return retVal;
					  }*/
};
}
