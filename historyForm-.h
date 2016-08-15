#pragma once

#include "stdlib.h"
#include "time.h"

#include <stdio.h>

#if _MSC_VER
#define snprintf _snprintf
#endif


namespace Inte_extend {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public struct DRAW_DATA {
	 UInt32 AbsReadIndex;//读取数据的顺序序号，每秒读5次 
	 float Mpa; //Mpa data
	 float Mm; //位移 mm data
	
	 float Mpa2; //Mpa data
	 float Mm2; //位移 mm data
	};
	
#define GRAPH_WID  320
#define GRAPH_HEIT 220
	
	
#define GRAPH_GRID_NUM  5  //格子数
	
#define GRAPH_GRID_MPA  10  //每格10 MPA
#define GRAPH_GRID_MM  40  //每格40 mm
	
#define GRAPH_GRID_Y_RATIO_MM  ((float) GRAPH_HEIT / GRAPH_GRID_NUM / GRAPH_GRID_MM)
#define GRAPH_GRID_Y_RATIO_MPA  ((float) GRAPH_HEIT / GRAPH_GRID_NUM / GRAPH_GRID_MPA)
	
	
	//#define GRAPH_X_NUM (GRAPH_GRID_SECOND * GRAPH_GRID_NUM * 5)	//5格，每格10秒，每秒5个采样点 
#define DRAW_DATA_BUFF (4095*10)  //张拉数据缓存大小

	static struct DRAW_DATA drawDataHis[DRAW_DATA_BUFF];

	/// <summary>
	/// historyForm 摘要
	/// </summary>
	public ref class historyForm : public System::Windows::Forms::Form
	{
	public:
		historyForm(void)
		{
			InitializeComponent();
			//
			//TODO: 在此处添加构造函数代码
			//
		}

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~historyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label27;
	protected: 
	private: System::Windows::Forms::Label^  label40;

	private: System::Windows::Forms::Label^  label_d2mm;
	private: System::Windows::Forms::Label^  label31;
	private: System::Windows::Forms::Label^  label32;
	private: System::Windows::Forms::Label^  label_d2Mpa;
	private: System::Windows::Forms::Label^  label37;

	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Panel^  panel2_MM;
	private: System::Windows::Forms::Panel^  panel2_MPA;
	private: System::Windows::Forms::Panel^  panel8;

	public: char * pFilePath ;
	private: Boolean  bPlay;

	private: System::Int32 length;
	private: System::Int32 intervalTime;
	private: System::Int32 graph1_x,graph1_y;

	private: System::Int32 absReadOpcIndex; //时间计数序号
	private: System::Int32 absReadOpcIndex_pre;
	private: System::Int32	GRAPH_GRID_SECOND ,  GRAPH_X_NUM ;	//5格，每格10秒，每秒5个采样点 ;



	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel1;
	private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel2;
	private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel3;
	private: System::Windows::Forms::ToolStripProgressBar^  toolStripProgressBar1;
	private: System::Windows::Forms::ToolStripStatusLabel^  toolStripConnectStatus;
	private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel5;
	private: System::Windows::Forms::Panel^  panel_MM;


	private: System::Windows::Forms::Panel^  panel_MPA;
	private: System::Windows::Forms::Label^  label43;
	private: System::Windows::Forms::Label^  label42;
	private: System::Windows::Forms::LinkLabel^  linkLabel1;




	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label_d1mm;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label_d1Mpa;

	private: System::Windows::Forms::Button^  but_play;

	private: System::Windows::Forms::VScrollBar^  vScrollBar1;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Timer^  timer1;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(historyForm::typeid));
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->label40 = (gcnew System::Windows::Forms::Label());
			this->label_d2mm = (gcnew System::Windows::Forms::Label());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->label_d2Mpa = (gcnew System::Windows::Forms::Label());
			this->label37 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->panel2_MM = (gcnew System::Windows::Forms::Panel());
			this->panel2_MPA = (gcnew System::Windows::Forms::Panel());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->toolStripStatusLabel1 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->toolStripStatusLabel2 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->toolStripStatusLabel3 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->toolStripProgressBar1 = (gcnew System::Windows::Forms::ToolStripProgressBar());
			this->toolStripConnectStatus = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->toolStripStatusLabel5 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->panel_MM = (gcnew System::Windows::Forms::Panel());
			this->panel_MPA = (gcnew System::Windows::Forms::Panel());
			this->label43 = (gcnew System::Windows::Forms::Label());
			this->label42 = (gcnew System::Windows::Forms::Label());
			this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label_d1mm = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label_d1Mpa = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->but_play = (gcnew System::Windows::Forms::Button());
			this->vScrollBar1 = (gcnew System::Windows::Forms::VScrollBar());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel8->SuspendLayout();
			this->statusStrip1->SuspendLayout();
			this->panel1->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->label27->Location = System::Drawing::Point(471, 3);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(47, 12);
			this->label27->TabIndex = 21;
			this->label27->Text = L"千斤顶2";
			// 
			// label40
			// 
			this->label40->AutoSize = true;
			this->label40->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->label40->Location = System::Drawing::Point(27, 4);
			this->label40->Name = L"label40";
			this->label40->Size = System::Drawing::Size(47, 12);
			this->label40->TabIndex = 19;
			this->label40->Text = L"千斤顶1";
			// 
			// label_d2mm
			// 
			this->label_d2mm->BackColor = System::Drawing::SystemColors::ControlText;
			this->label_d2mm->Font = (gcnew System::Drawing::Font(L"宋体", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label_d2mm->ForeColor = System::Drawing::Color::Yellow;
			this->label_d2mm->Location = System::Drawing::Point(261, 9);
			this->label_d2mm->Name = L"label_d2mm";
			this->label_d2mm->Size = System::Drawing::Size(85, 40);
			this->label_d2mm->TabIndex = 12;
			this->label_d2mm->Text = L"000.0";
			this->label_d2mm->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label31
			// 
			this->label31->AutoSize = true;
			this->label31->Location = System::Drawing::Point(216, 23);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(41, 12);
			this->label31->TabIndex = 11;
			this->label31->Text = L"( mm )";
			this->label31->Click += gcnew System::EventHandler(this, &historyForm::label31_Click);
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label32->Location = System::Drawing::Point(187, 22);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(37, 14);
			this->label32->TabIndex = 10;
			this->label32->Text = L"位移";
			// 
			// label_d2Mpa
			// 
			this->label_d2Mpa->BackColor = System::Drawing::SystemColors::ControlText;
			this->label_d2Mpa->Font = (gcnew System::Drawing::Font(L"宋体", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label_d2Mpa->ForeColor = System::Drawing::Color::Yellow;
			this->label_d2Mpa->Location = System::Drawing::Point(86, 9);
			this->label_d2Mpa->Name = L"label_d2Mpa";
			this->label_d2Mpa->Size = System::Drawing::Size(90, 45);
			this->label_d2Mpa->TabIndex = 4;
			this->label_d2Mpa->Text = L"000.00";
			this->label_d2Mpa->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label37
			// 
			this->label37->AutoSize = true;
			this->label37->Location = System::Drawing::Point(35, 22);
			this->label37->Name = L"label37";
			this->label37->Size = System::Drawing::Size(41, 12);
			this->label37->TabIndex = 5;
			this->label37->Text = L"(M Pa)";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label5->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label5->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label5->Location = System::Drawing::Point(75, 379);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(268, 16);
			this->label5->TabIndex = 18;
			this->label5->Text = L"张拉仪2 位移曲线:( 毫米 - 秒 )";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label4->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label4->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label4->Location = System::Drawing::Point(75, 90);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(261, 16);
			this->label4->TabIndex = 18;
			this->label4->Text = L"张拉仪2 压力曲线:( Mpa - 秒 )";
			// 
			// panel2_MM
			// 
			this->panel2_MM->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->panel2_MM->Location = System::Drawing::Point(21, 369);
			this->panel2_MM->Name = L"panel2_MM";
			this->panel2_MM->Size = System::Drawing::Size(367, 283);
			this->panel2_MM->TabIndex = 19;
			this->panel2_MM->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &historyForm::panel2_MM_Paint);
			// 
			// panel2_MPA
			// 
			this->panel2_MPA->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->panel2_MPA->Location = System::Drawing::Point(18, 83);
			this->panel2_MPA->Name = L"panel2_MPA";
			this->panel2_MPA->Size = System::Drawing::Size(367, 280);
			this->panel2_MPA->TabIndex = 18;
			this->panel2_MPA->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &historyForm::panel2_MPA_Paint);
			// 
			// panel8
			// 
			this->panel8->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel8->Controls->Add(this->label7);
			this->panel8->Controls->Add(this->label_d2mm);
			this->panel8->Controls->Add(this->label31);
			this->panel8->Controls->Add(this->label32);
			this->panel8->Controls->Add(this->label37);
			this->panel8->Controls->Add(this->label_d2Mpa);
			this->panel8->Location = System::Drawing::Point(16, 14);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(362, 63);
			this->panel8->TabIndex = 0;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label7->Location = System::Drawing::Point(3, 20);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(37, 14);
			this->label7->TabIndex = 13;
			this->label7->Text = L"压力";
			// 
			// statusStrip1
			// 
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {this->toolStripStatusLabel1, 
				this->toolStripStatusLabel2, this->toolStripStatusLabel3, this->toolStripProgressBar1, this->toolStripConnectStatus, this->toolStripStatusLabel5});
			this->statusStrip1->Location = System::Drawing::Point(0, 680);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(981, 22);
			this->statusStrip1->TabIndex = 14;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// toolStripStatusLabel1
			// 
			this->toolStripStatusLabel1->Name = L"toolStripStatusLabel1";
			this->toolStripStatusLabel1->Size = System::Drawing::Size(111, 17);
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
			this->toolStripStatusLabel3->Size = System::Drawing::Size(72, 17);
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
			this->toolStripStatusLabel5->Size = System::Drawing::Size(170, 17);
			this->toolStripStatusLabel5->Text = L"湖南聚创建筑科技有限公司:";
			// 
			// panel_MM
			// 
			this->panel_MM->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->panel_MM->Location = System::Drawing::Point(21, 369);
			this->panel_MM->Name = L"panel_MM";
			this->panel_MM->Size = System::Drawing::Size(367, 283);
			this->panel_MM->TabIndex = 17;
			this->panel_MM->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &historyForm::panel_MM_Paint);
			// 
			// panel_MPA
			// 
			this->panel_MPA->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->panel_MPA->Location = System::Drawing::Point(18, 84);
			this->panel_MPA->Name = L"panel_MPA";
			this->panel_MPA->Size = System::Drawing::Size(367, 279);
			this->panel_MPA->TabIndex = 16;
			this->panel_MPA->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &historyForm::panel_MPA_Paint);
			// 
			// label43
			// 
			this->label43->AutoSize = true;
			this->label43->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label43->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label43->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label43->Location = System::Drawing::Point(75, 379);
			this->label43->Name = L"label43";
			this->label43->Size = System::Drawing::Size(268, 16);
			this->label43->TabIndex = 14;
			this->label43->Text = L"张拉仪1 位移曲线:( 毫米 - 秒 )";
			// 
			// label42
			// 
			this->label42->AutoSize = true;
			this->label42->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label42->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label42->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label42->Location = System::Drawing::Point(75, 91);
			this->label42->Name = L"label42";
			this->label42->Size = System::Drawing::Size(261, 16);
			this->label42->TabIndex = 13;
			this->label42->Text = L"张拉仪1 压力曲线:( Mpa - 秒 )";
			// 
			// linkLabel1
			// 
			this->linkLabel1->AutoSize = true;
			this->linkLabel1->Location = System::Drawing::Point(802, 707);
			this->linkLabel1->Name = L"linkLabel1";
			this->linkLabel1->Size = System::Drawing::Size(113, 12);
			this->linkLabel1->TabIndex = 15;
			this->linkLabel1->TabStop = true;
			this->linkLabel1->Text = L"http://jochon.com/";
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->panel3);
			this->panel1->Controls->Add(this->label43);
			this->panel1->Controls->Add(this->label42);
			this->panel1->Controls->Add(this->panel_MM);
			this->panel1->Controls->Add(this->panel_MPA);
			this->panel1->Location = System::Drawing::Point(23, 13);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(400, 660);
			this->panel1->TabIndex = 12;
			// 
			// panel3
			// 
			this->panel3->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel3->Controls->Add(this->label1);
			this->panel3->Controls->Add(this->label_d1mm);
			this->panel3->Controls->Add(this->label3);
			this->panel3->Controls->Add(this->label6);
			this->panel3->Controls->Add(this->label8);
			this->panel3->Controls->Add(this->label_d1Mpa);
			this->panel3->Location = System::Drawing::Point(15, 14);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(362, 63);
			this->panel3->TabIndex = 18;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label1->Location = System::Drawing::Point(6, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(37, 14);
			this->label1->TabIndex = 13;
			this->label1->Text = L"压力";
			// 
			// label_d1mm
			// 
			this->label_d1mm->BackColor = System::Drawing::SystemColors::ControlText;
			this->label_d1mm->Font = (gcnew System::Drawing::Font(L"宋体", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label_d1mm->ForeColor = System::Drawing::Color::Yellow;
			this->label_d1mm->Location = System::Drawing::Point(261, 9);
			this->label_d1mm->Name = L"label_d1mm";
			this->label_d1mm->Size = System::Drawing::Size(85, 40);
			this->label_d1mm->TabIndex = 12;
			this->label_d1mm->Text = L"000.0";
			this->label_d1mm->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(219, 23);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(41, 12);
			this->label3->TabIndex = 11;
			this->label3->Text = L"( mm )";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label6->Location = System::Drawing::Point(187, 22);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(37, 14);
			this->label6->TabIndex = 10;
			this->label6->Text = L"位移";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(37, 22);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(41, 12);
			this->label8->TabIndex = 5;
			this->label8->Text = L"(M Pa)";
			// 
			// label_d1Mpa
			// 
			this->label_d1Mpa->BackColor = System::Drawing::SystemColors::ControlText;
			this->label_d1Mpa->Font = (gcnew System::Drawing::Font(L"宋体", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label_d1Mpa->ForeColor = System::Drawing::Color::Yellow;
			this->label_d1Mpa->Location = System::Drawing::Point(86, 9);
			this->label_d1Mpa->Name = L"label_d1Mpa";
			this->label_d1Mpa->Size = System::Drawing::Size(90, 40);
			this->label_d1Mpa->TabIndex = 4;
			this->label_d1Mpa->Text = L"000.00";
			this->label_d1Mpa->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel2
			// 
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel2->Controls->Add(this->label5);
			this->panel2->Controls->Add(this->label4);
			this->panel2->Controls->Add(this->panel2_MM);
			this->panel2->Controls->Add(this->panel8);
			this->panel2->Controls->Add(this->panel2_MPA);
			this->panel2->Location = System::Drawing::Point(467, 13);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(400, 660);
			this->panel2->TabIndex = 20;
			// 
			// but_play
			// 
			this->but_play->Font = (gcnew System::Drawing::Font(L"宋体", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->but_play->ForeColor = System::Drawing::SystemColors::Desktop;
			this->but_play->Location = System::Drawing::Point(875, 388);
			this->but_play->Name = L"but_play";
			this->but_play->Size = System::Drawing::Size(94, 44);
			this->but_play->TabIndex = 22;
			this->but_play->Text = L"播 放";
			this->but_play->UseVisualStyleBackColor = true;
			this->but_play->Click += gcnew System::EventHandler(this, &historyForm::but_play_Click);
			// 
			// vScrollBar1
			// 
			this->vScrollBar1->Location = System::Drawing::Point(919, 109);
			this->vScrollBar1->Maximum = 200;
			this->vScrollBar1->Minimum = 1;
			this->vScrollBar1->Name = L"vScrollBar1";
			this->vScrollBar1->Size = System::Drawing::Size(25, 245);
			this->vScrollBar1->TabIndex = 23;
			this->vScrollBar1->Value = 50;
			this->vScrollBar1->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &historyForm::vScrollBar1_Scroll);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"宋体", 18, System::Drawing::FontStyle::Bold));
			this->label10->Location = System::Drawing::Point(880, 163);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(35, 24);
			this->label10->TabIndex = 24;
			this->label10->Text = L"回";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"宋体", 18, System::Drawing::FontStyle::Bold));
			this->label11->Location = System::Drawing::Point(880, 203);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(35, 24);
			this->label11->TabIndex = 25;
			this->label11->Text = L"放";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"宋体", 18, System::Drawing::FontStyle::Bold));
			this->label12->Location = System::Drawing::Point(880, 243);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(35, 24);
			this->label12->TabIndex = 26;
			this->label12->Text = L"速";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"宋体", 18, System::Drawing::FontStyle::Bold));
			this->label13->Location = System::Drawing::Point(880, 283);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(35, 24);
			this->label13->TabIndex = 27;
			this->label13->Text = L"度";
			// 
			// timer1
			// 
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &historyForm::timer1_Tick);
			// 
			// historyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(981, 702);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->vScrollBar1);
			this->Controls->Add(this->but_play);
			this->Controls->Add(this->label27);
			this->Controls->Add(this->label40);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->linkLabel1);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->panel2);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"historyForm";
			this->Text = L"历史记录回放";
			this->Shown += gcnew System::EventHandler(this, &historyForm::historyForm_Shown);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &historyForm::historyForm_Paint);
			this->panel8->ResumeLayout(false);
			this->panel8->PerformLayout();
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label31_Click(System::Object^  sender, System::EventArgs^  e) {
			 }

private: System::Void but_play_Click(System::Object^  sender, System::EventArgs^  e) {
			 if( bPlay == false) {
			 this->but_play->Text = "暂 停";
			 bPlay = true;
			 intervalTime = 0;
			 this->timer1->Interval = 4000 / this->vScrollBar1->Value;
			  this->timer1->Enabled = true;
			 }
			 else {
				 this->but_play->Text = "播 放";
				 this->timer1->Enabled = false;
				 bPlay = false;
			 }
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
	System::String ^  s = System::Runtime::InteropServices::Marshal::PtrToStringAnsi((IntPtr)a);
	
	 return  s;  

 }

private: System::Void panel_MPA_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
	int i = 0;
	 int iStart = 1;
	 if( absReadOpcIndex > GRAPH_X_NUM ) {
		 GRAPH_GRID_SECOND = GRAPH_GRID_SECOND + 5;
	    GRAPH_X_NUM = (GRAPH_GRID_SECOND * GRAPH_GRID_NUM * 5);
	 }
	//Invalidate(new Rectangle(0, 0, 1, 1));

	Graphics^ graph = e->Graphics;
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

	graph->DrawLine(Pen_black,graph1_x,graph1_y,graph1_x + GRAPH_WID,graph1_y);
	graph->DrawLine(Pen_black,graph1_x,graph1_y,graph1_x ,graph1_y - GRAPH_HEIT);
	graph->DrawString(System::Convert::ToString( 0 ),drawFont,drawBrush ,PointF((float) (graph1_x - 10) , (float)(graph1_y - 1)) );
	//graph->DrawString("时间( S )",drawFont,drawBrushRed ,PointF( (float)(graph1_x + 4 * GRAPH_WID/GRAPH_GRID_NUM + 10) , (float)graph1_y ));
	//graph->DrawString("压力( M pa )",drawFont,drawBrushRed ,PointF( (float)(graph1_x - 20),(float)(graph1_y	-  GRAPH_HEIT) ) ,drawVertical);
	for(i = 1; i < GRAPH_GRID_NUM + 1; i++) {
		graph->DrawString(System::Convert::ToString( i * GRAPH_GRID_SECOND ),drawFont,drawBrush ,PointF( (float)(graph1_x -5 + i * GRAPH_WID/GRAPH_GRID_NUM), (float)(graph1_y - 1)) );
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
	fMpa = (int )(drawDataHis[absReadOpcIndex > 0 ? absReadOpcIndex - 1:absReadOpcIndex].Mpa * 100 ) / 100.0;

	this->label_d1Mpa->Text = Round_float( fMpa ,2);
	fMpa = GRAPH_GRID_Y_RATIO_MPA;
	for(i = iStart; i < absReadOpcIndex; i++) {
		fMpa = drawDataHis[i].Mpa;
		prefMpa = drawDataHis[i -1].Mpa;
		graph->DrawLine(BluePen,(float)( graph1_x + (i - iStart) * GRAPH_WID/(float)GRAPH_X_NUM ) , graph1_y - prefMpa * GRAPH_GRID_Y_RATIO_MPA , (float)(graph1_x + (i - iStart + 1) * GRAPH_WID/(float)GRAPH_X_NUM ) + 1, graph1_y - fMpa  * GRAPH_GRID_Y_RATIO_MPA + 1);
	}
	/*try{
		if( this->p_comBase->opcReadData[0]->Quality == 192 ) 
			graph->DrawLine( RedPen, (float)graph1_x,(float) (graph1_y - System::Convert::ToSingle(this->textBox_d1Mpa_des->Text) * GRAPH_GRID_Y_RATIO_MPA),(float)(graph1_x + GRAPH_WID),(float)( graph1_y  - System::Convert::ToSingle(this->textBox_d1Mpa_des->Text) * GRAPH_GRID_Y_RATIO_MPA) );
	}
	catch(Exception ^ ex) {
		;
	}*/
	delete graph;
	
}

private: System::Void panel_MM_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {

	 int i = 0;
	 int iStart = 1;
	 if( absReadOpcIndex > GRAPH_X_NUM ) {
		 GRAPH_GRID_SECOND = GRAPH_GRID_SECOND  + 5;
	    GRAPH_X_NUM = (GRAPH_GRID_SECOND * GRAPH_GRID_NUM * 5);
	 }
	//Invalidate(new Rectangle(0, 0, 1, 1));

	Graphics^ graph = e->Graphics;
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

	graph->DrawLine(Pen_black,graph1_x,graph1_y,graph1_x + GRAPH_WID,graph1_y);
	graph->DrawLine(Pen_black,graph1_x,graph1_y,graph1_x ,graph1_y - GRAPH_HEIT);
	graph->DrawString(System::Convert::ToString( 0 ),drawFont,drawBrush ,PointF( (float)(graph1_x - 10) ,(float)( graph1_y - 1)) );
	//graph->DrawString("时间( S )",drawFont,drawBrushRed ,PointF( (float)(graph1_x + 4 * GRAPH_WID/GRAPH_GRID_NUM + 10) , (float)graph1_y ) );
	//graph->DrawString("位移( mm )",drawFont,drawBrushRed ,PointF( (float)(graph1_x - 20),(float)(graph1_y -  GRAPH_HEIT )) ,drawVertical);

	for(i = 1; i < GRAPH_GRID_NUM + 1; i++) {
		graph->DrawString(System::Convert::ToString( i * GRAPH_GRID_SECOND ),drawFont,drawBrush ,PointF( (float)(graph1_x -11 + i * GRAPH_WID/GRAPH_GRID_NUM),(float) (graph1_y - 1)) );
		graph->DrawString(System::Convert::ToString( i * GRAPH_GRID_MM),drawFont,drawBrush ,PointF( (float)(graph1_x - 26),(float)(graph1_y	- i * GRAPH_HEIT/GRAPH_GRID_NUM - 14)) );
		if( i < GRAPH_GRID_NUM ){
			graph->DrawLine(Pen_gray,graph1_x + i * GRAPH_WID/GRAPH_GRID_NUM, graph1_y, graph1_x + i * GRAPH_WID/GRAPH_GRID_NUM, graph1_y - GRAPH_HEIT);
			graph->DrawLine(Pen_gray,graph1_x,graph1_y  - i * GRAPH_HEIT/GRAPH_GRID_NUM,graph1_x + GRAPH_WID,graph1_y - i * GRAPH_HEIT/GRAPH_GRID_NUM);
		}
		else {
			graph->DrawLine(Pen_dash,graph1_x + i * GRAPH_WID/GRAPH_GRID_NUM, graph1_y, graph1_x + i * GRAPH_WID/GRAPH_GRID_NUM, graph1_y - GRAPH_HEIT);
			graph->DrawLine(Pen_dash,graph1_x,graph1_y  - i * GRAPH_HEIT/GRAPH_GRID_NUM,graph1_x + GRAPH_WID,graph1_y - i * GRAPH_HEIT/GRAPH_GRID_NUM);
		}
	}
	fMm = (int )(drawDataHis[absReadOpcIndex > 0 ? absReadOpcIndex - 1:absReadOpcIndex].Mm * 100 ) / 100.0;
	this->label_d1mm->Text = Round_float( fMm ,1);
	for(i = iStart; i < absReadOpcIndex; i++) {
		fMm = drawDataHis[i ].Mm;
		prefMm = drawDataHis[i- 1].Mm;
		graph->DrawLine(BluePen,(float)(graph1_x + (i - iStart) * GRAPH_WID/GRAPH_X_NUM ), graph1_y - prefMm * GRAPH_GRID_Y_RATIO_MM, (float)( graph1_x + (i - iStart + 1) * GRAPH_WID/(float)GRAPH_X_NUM ) + 1,graph1_y - fMm * GRAPH_GRID_Y_RATIO_MM + 1);
	}
	//e->Graphics->DrawImage(myBitmap,30,600,400,400 );
	//graph->Dispose();
	delete graph;
}

private: System::Void pictureBox_Mpa2_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
	int i = 0;
	 int iStart = 1;
	 if( absReadOpcIndex > GRAPH_X_NUM ) {
		 GRAPH_GRID_SECOND = GRAPH_GRID_SECOND + 5;
	    GRAPH_X_NUM = (GRAPH_GRID_SECOND * GRAPH_GRID_NUM * 5);
	 }
	//Invalidate(new Rectangle(0, 0, 1, 1));

	Graphics^ graph = e->Graphics;
	float prefMpa,fMpa;

	Pen^ Pen_black= gcnew Pen( System::Drawing::Color::Black ,1);
	 Pen^ Pen_gray= gcnew Pen( System::Drawing::Color::LightGray ,1);
	 Pen^ Pen_dash= gcnew Pen( System::Drawing::Color::Gray ,1);
	 Pen^ RedPen= gcnew Pen( System::Drawing::Color::Red ,2);
	 Pen^ BluePen= gcnew Pen( System::Drawing::Color::Blue ,2);
	 Pen_dash->DashStyle = System::Drawing::Drawing2D::DashStyle::DashDotDot;
	 System::Drawing::Font^ drawFont = gcnew System::Drawing::Font( "Arial", 11 );
	 SolidBrush^ drawBrush = gcnew SolidBrush( Color::Black );
	 SolidBrush^ drawBrushWhite = gcnew SolidBrush( Color::White );
	 SolidBrush^ drawBrushRed = gcnew SolidBrush( Color::Red );
	 System::Drawing::StringFormat^ drawVertical = gcnew System::Drawing::StringFormat(StringFormatFlags::DirectionVertical);

	 Pen^ forColorPen= gcnew Pen( System::Drawing::Color::Red ); 

	//e->Graphics->Clear(Color::White);
	//graph->FillRectangle(drawBrushWhite , graph1_x,graph1_y, GRAPH_WID, GRAPH_HEIT);
	graph->DrawLine(Pen_black,graph1_x,graph1_y,graph1_x + GRAPH_WID,graph1_y);
	graph->DrawLine(Pen_black,graph1_x,graph1_y,graph1_x ,graph1_y - GRAPH_HEIT);
	graph->DrawString(System::Convert::ToString( 0 ),drawFont,drawBrush ,PointF((float) (graph1_x - 10) , (float)(graph1_y - 1)) );
	//graph->DrawString("时间( S )",drawFont,drawBrushRed ,PointF( (float)(graph1_x + 4 * GRAPH_WID/GRAPH_GRID_NUM + 10) , (float)graph1_y ));
	//graph->DrawString("压力( M pa )",drawFont,drawBrushRed ,PointF( (float)(graph1_x - 20),(float)(graph1_y	-  GRAPH_HEIT) ) ,drawVertical);
	for(i = 1; i < GRAPH_GRID_NUM + 1; i++) {
		graph->DrawString(System::Convert::ToString( i * GRAPH_GRID_SECOND ),drawFont,drawBrush ,PointF( (float)(graph1_x -5 + i * GRAPH_WID/GRAPH_GRID_NUM), (float)(graph1_y - 1)) );
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
	}*/
	fMpa = (int )(drawDataHis[absReadOpcIndex > 0 ? absReadOpcIndex - 1:absReadOpcIndex].Mpa2 * 100 ) / 100.0;
	this->label_d2Mpa->Text = Round_float( fMpa ,2);
	for(i = iStart; i < absReadOpcIndex; i++) {
		fMpa = drawDataHis[i  ].Mpa2;
		prefMpa = drawDataHis[i- 1].Mpa2;
		graph->DrawLine(BluePen,(float)( graph1_x + (i - iStart) * GRAPH_WID/GRAPH_X_NUM ), graph1_y - prefMpa * GRAPH_GRID_Y_RATIO_MPA, (float)(graph1_x + (i - iStart + 1) * GRAPH_WID/(float)GRAPH_X_NUM ) + 1, graph1_y - fMpa  * GRAPH_GRID_Y_RATIO_MPA + 1);
	}

	//graph->Dispose();
	//delete graph;
	
}


private: System::Void panel2_MM_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
	int i = 0;
	 int iStart = 1;
	 if( absReadOpcIndex > GRAPH_X_NUM ) {
		 GRAPH_GRID_SECOND = GRAPH_GRID_SECOND  + 5;
	    GRAPH_X_NUM = (GRAPH_GRID_SECOND * GRAPH_GRID_NUM * 5);
	 }
	//Invalidate(new Rectangle(0, 0, 1, 1));

	Graphics^ graph = e->Graphics;

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

	graph->DrawLine(Pen_black,graph1_x,graph1_y,graph1_x + GRAPH_WID,graph1_y);
	graph->DrawLine(Pen_black,graph1_x,graph1_y,graph1_x ,graph1_y - GRAPH_HEIT);
	graph->DrawString(System::Convert::ToString( 0 ),drawFont,drawBrush ,PointF( (float)(graph1_x - 10) ,(float)( graph1_y - 1)) );
	//graph->DrawString("时间( S )",drawFont,drawBrushRed ,PointF( (float)(graph1_x + 4 * GRAPH_WID/GRAPH_GRID_NUM + 10) , (float)graph1_y ) );
	//graph->DrawString("位移( mm )",drawFont,drawBrushRed ,PointF( (float)(graph1_x - 20),(float)(graph1_y -  GRAPH_HEIT )) ,drawVertical);

	for(i = 1; i < GRAPH_GRID_NUM + 1; i++) {
		graph->DrawString(System::Convert::ToString( i * GRAPH_GRID_SECOND ),drawFont,drawBrush ,PointF( (float)(graph1_x -11 + i * GRAPH_WID/GRAPH_GRID_NUM),(float) (graph1_y - 1)) );
		graph->DrawString(System::Convert::ToString( i * GRAPH_GRID_MM),drawFont,drawBrush ,PointF( (float)(graph1_x - 26),(float)(graph1_y	- i * GRAPH_HEIT/GRAPH_GRID_NUM - 14)) );
		if( i < GRAPH_GRID_NUM ){
			graph->DrawLine(Pen_gray,graph1_x + i * GRAPH_WID/GRAPH_GRID_NUM, graph1_y, graph1_x + i * GRAPH_WID/GRAPH_GRID_NUM, graph1_y - GRAPH_HEIT);
			graph->DrawLine(Pen_gray,graph1_x,graph1_y  - i * GRAPH_HEIT/GRAPH_GRID_NUM,graph1_x + GRAPH_WID,graph1_y - i * GRAPH_HEIT/GRAPH_GRID_NUM);
		}
		else {
			graph->DrawLine(Pen_dash,graph1_x + i * GRAPH_WID/GRAPH_GRID_NUM, graph1_y, graph1_x + i * GRAPH_WID/GRAPH_GRID_NUM, graph1_y - GRAPH_HEIT);
			graph->DrawLine(Pen_dash,graph1_x,graph1_y  - i * GRAPH_HEIT/GRAPH_GRID_NUM,graph1_x + GRAPH_WID,graph1_y - i * GRAPH_HEIT/GRAPH_GRID_NUM);
		}
	}
	fMm = (int )(drawDataHis[absReadOpcIndex > 0 ? absReadOpcIndex - 1:absReadOpcIndex].Mm2 * 100 ) / 100.0;
	this->label_d2mm->Text = Round_float ( fMm ,1);

	for(i = iStart; i < absReadOpcIndex; i++) {
		fMm = drawDataHis[i  ].Mm2;
		prefMm = drawDataHis[i- 1].Mm2;
		graph->DrawLine(BluePen,(float)(graph1_x + (i - iStart) * GRAPH_WID/GRAPH_X_NUM ), graph1_y - prefMm * GRAPH_GRID_Y_RATIO_MM, (float)( graph1_x + (i - iStart + 1) * GRAPH_WID/(float)GRAPH_X_NUM ) + 1,graph1_y - fMm * GRAPH_GRID_Y_RATIO_MM + 1);
	}

}

private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	intervalTime = this->timer1->Interval * (absReadOpcIndex - absReadOpcIndex_pre);

	if( intervalTime > 1000  || abs(absReadOpcIndex - absReadOpcIndex_pre) > 5){
		intervalTime = 0;
		absReadOpcIndex_pre = absReadOpcIndex;
	//	this->Invalidate();
		this->panel_MM->Invalidate();
		this->panel_MPA->Invalidate();
		this->panel2_MM->Invalidate();
		this->pictureBox_Mpa2->Invalidate(); 
	}
	absReadOpcIndex++;
	if( absReadOpcIndex > length ) {
		this->but_play->Text = "播 放";
		this->timer1->Enabled = false;
		bPlay = false;
		absReadOpcIndex = 0;
	}
    }
private: System::Void historyForm_Shown(System::Object^  sender, System::EventArgs^  e) {
			 FILE * fp =	 fopen( pFilePath ,"rb");
			 absReadOpcIndex = 0;
			 absReadOpcIndex_pre = 0;
			 GRAPH_GRID_SECOND = 10;
			 graph1_x = 30;
			graph1_y = GRAPH_HEIT + 30; 
			 this->timer1->Enabled = false;
			 this->but_play->Text = "播 放";
			 bPlay = false;
    		GRAPH_X_NUM = (GRAPH_GRID_SECOND * GRAPH_GRID_NUM * 5);  //5格，每格10秒，每秒5个采样点 
			 if( fp ) {
				 fseek(fp, 0L, SEEK_END);
				 length = ftell( fp )/ sizeof(struct DRAW_DATA);
				 fseek(fp, 0L, SEEK_SET);
				 int readlen = fread( drawDataHis , sizeof(struct DRAW_DATA) , length , fp);
				 	 while( length > GRAPH_X_NUM ) {
						GRAPH_GRID_SECOND = GRAPH_GRID_SECOND  + 5;
				    	GRAPH_X_NUM = (GRAPH_GRID_SECOND * GRAPH_GRID_NUM * 5);
				 	}
				 fclose(fp);
				 return ;
			 }
		 }
private: System::Void vScrollBar1_Scroll(System::Object^  sender, System::Windows::Forms::ScrollEventArgs^  e) {
	 this->timer1->Interval = 4000 / this->vScrollBar1->Value;
		 }
private: System::Void historyForm_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
	
	
		 }
};
}
