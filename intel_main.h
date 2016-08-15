#pragma once
#include "safewNote.h"
#include "goujian.h"
#include "controlMachine.h"

#include "operationStep.h"
#include "public.h"

#define MULTI1 366
#define MULTI2 31


#using <System.Xml.dll>
namespace Inte_extend {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace System::IO;
	using namespace System::Text;
	using namespace System::Xml;

	/// <summary>
	/// intel_main 摘要
	/// </summary>
	public ref class intel_main : public System::Windows::Forms::Form
	{
		//public static System::Threading::Mutex Run;
	public:
		intel_main(void)
		{
			bInit = 0;
			
/*
			bool noRun = false;
			Run = new System.Threading.Mutex(true, "intel_extendProgram", out noRun);
			//检测是否已经运行
			if ( !noRun)
				Application.Exit();
			else
				Run.ReleaseMutex();*/

			InitializeComponent();
			//
			//TODO: 在此处添加构造函数代码
			//
		}

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~intel_main()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel_left;
	private: System::Windows::Forms::Panel^  panel_right;
	protected: 

	protected: 
	private: safewNote m_safeNote;
	private: goujian  m_goujian;
	private: controlMachine m_controlMachine;

	private: System::Windows::Forms::TextBox^  text_sheJiZhangLaQiangDu;


	private: System::Windows::Forms::TextBox^  text_sheJiYingli;

	private: System::Windows::Forms::TextBox^  text_gongChen;
	private: System::Windows::Forms::TextBox^  text_sheJiQiangDu;


	private: System::Windows::Forms::TextBox^  text_liangChang;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label25;
	private: System::Windows::Forms::Label^  label26;
	private: System::Windows::Forms::TextBox^  text_tuJian;

	private: System::Windows::Forms::TextBox^  text_jianLi;

	private: System::Windows::Forms::TextBox^  text_shiGong;
	private: System::Windows::Forms::TextBox^  text_xiangMu;
	private: System::Windows::Forms::Button^  but_SaveProject;

	private: System::Windows::Forms::Button^  but_inputGouJian;
	private: System::Windows::Forms::Button^  but_SoftwareUpdate;
	private: System::Windows::Forms::Button^  but_exit;




	private: System::Windows::Forms::Button^  but_modifyProject;
	private: System::Windows::Forms::Label^  label_dunwei;



	private: System::Windows::Forms::Panel^  panel_2;

	private: System::Windows::Forms::TextBox^  text_machine2CheckDate;

	private: System::Windows::Forms::TextBox^  text_machine2ip;

	private: System::Windows::Forms::TextBox^  text_ding2Num;
	private: System::Windows::Forms::TextBox^  text_ding2HuiGuib;


	private: System::Windows::Forms::TextBox^  text_ding2HuiGuifx;

	private: System::Windows::Forms::Label^  label28;
	private: System::Windows::Forms::Label^  label29;

	private: System::Windows::Forms::Label^  label31;
	private: System::Windows::Forms::Label^  label32;
	private: System::Windows::Forms::Label^  label33;
	private: System::Windows::Forms::Panel^  panel_1;


	private: System::Windows::Forms::TextBox^  text_machine1CheckDate;

	private: System::Windows::Forms::TextBox^  text_ding1HuiGuib;

	private: System::Windows::Forms::TextBox^  text_ding1HuiGuifx;
	private: System::Windows::Forms::TextBox^  text_machine1ip;


	private: System::Windows::Forms::TextBox^  text_ding1Num;

	private: System::Windows::Forms::Label^  label34;
	private: System::Windows::Forms::Label^  label35;
	private: System::Windows::Forms::Label^  label36;
	private: System::Windows::Forms::Label^  label37;
	private: System::Windows::Forms::Label^  label38;
	private: System::Windows::Forms::Label^  label39;
	private: System::Windows::Forms::Label^  label40;
	private: System::Windows::Forms::Label^  label41;
	private: System::Windows::Forms::Label^  label42;
	private: System::Windows::Forms::Label^  label43;
	private: System::Windows::Forms::Label^  label44;
	private: System::Windows::Forms::Label^  label45;
	private: System::Windows::Forms::Button^  but_safeNote;
	private: System::Windows::Forms::Button^  but_operationStep;



	private: System::Windows::Forms::Button^  prePressButton;
	private: System::Windows::Forms::Button^  but_kongxinban;
	private: System::Windows::Forms::Button^  but_jianZhiT;
	private: System::Windows::Forms::Button^  but_fuWanJu;

	private: System::Windows::Forms::Button^  but_ControlMachine;



	private: System::Windows::Forms::Button^  but_jianZhiXiang;
	private: System::Windows::Forms::Button^  but_gaiLiang;


	private: System::Windows::Forms::Button^  but_shuXiangDuan;

	private: System::Windows::Forms::Button^  but_lianXuZong;
	private: System::Windows::Forms::Button^  but_otherZhangLa;


	private: System::Windows::Forms::Button^  but_lianXuHeng;
private: System::Windows::Forms::ComboBox^  comboBox_DunWei;
private: System::Windows::Forms::Panel^  panel_4;

private: System::Windows::Forms::TextBox^  text_machine4CheckDate;
private: System::Windows::Forms::TextBox^  text_ding4HuiGuib;
private: System::Windows::Forms::TextBox^  text_ding4HuiGuifx;
private: System::Windows::Forms::TextBox^  text_machine4ip;
private: System::Windows::Forms::TextBox^  text_ding4Num;

private: System::Windows::Forms::Label^  label9;
private: System::Windows::Forms::Label^  label10;
private: System::Windows::Forms::Label^  label11;
private: System::Windows::Forms::Label^  label12;
private: System::Windows::Forms::Label^  label13;
private: System::Windows::Forms::Panel^  panel_3;
		 private: System::Int32 wid,hei,countExe;
		 
		 private: System::Int32 but_curSel, bInit ;

private: System::Windows::Forms::TextBox^  text_machine3CheckDate;
private: System::Windows::Forms::TextBox^  text_ding3HuiGuib;
private: System::Windows::Forms::TextBox^  text_ding3HuiGuifx;
private: System::Windows::Forms::TextBox^  text_machine3ip;
private: System::Windows::Forms::TextBox^  text_ding3Num;

private: System::Windows::Forms::Label^  label3;
private: System::Windows::Forms::Label^  label4;
private: System::Windows::Forms::Label^  label5;
private: System::Windows::Forms::Label^  label6;
private: System::Windows::Forms::Label^  label7;
private: System::Windows::Forms::Panel^  panel2;
private: System::Windows::Forms::Panel^  panel1;

private: System::Windows::Forms::Label^  label_GouJianInfo;
private: System::Windows::Forms::PictureBox^  pictureBox1;



static array<System::Windows::Forms::Label^>^ right_label = gcnew array<System::Windows::Forms::Label^>(64); 
public:	static array<System::Windows::Forms::TextBox^>^ right_TextBox = gcnew array<System::Windows::Forms::TextBox^>(64); 
public:	static array<System::Windows::Forms::ComboBox^>^ right_ComboBox = gcnew array<System::Windows::Forms::ComboBox^>(7); 

public: static array<System::String^>^ str_holeInfo = gcnew array<System::String^>(holeInfoNum); 
static array<System::Windows::Forms::Label^>^ sequence_label = gcnew array<System::Windows::Forms::Label^>(zhangLaSeqNum); 
public: static array<System::Windows::Forms::TextBox^>^ sequence_TextBox = gcnew array<System::Windows::Forms::TextBox^>(zhangLaSeqNum); 
private: System::Windows::Forms::Label^  label1;
private: System::Windows::Forms::Label^  label8;
private: System::Windows::Forms::Label^  label16;
private: System::Windows::Forms::Label^  label17;
private: System::Windows::Forms::Label^  label14;
private: System::Windows::Forms::Label^  label15;
private: System::Windows::Forms::Label^  label_project;

private: System::Windows::Forms::Timer^  timer1;
private: System::Windows::Forms::Label^  label20;
private: System::Windows::Forms::Label^  label19;
private: System::Windows::Forms::Label^  label18;
private: System::Windows::Forms::Label^  label_top;
private: System::Windows::Forms::PictureBox^  pictureBox2;
private: System::Windows::Forms::Button^  but_historySearch;
private: System::Windows::Forms::PictureBox^  pictureBox3;
private: System::Windows::Forms::Label^  label21;
private: System::Windows::Forms::Label^  label22;
private: System::Windows::Forms::TextBox^  textBox_lenSub;


private: System::Int32 otherHoleNum, otherExtendNum ;//latestCountDown:保压倒计时
private: float  otherKn;
private: System::Windows::Forms::Button^  btn_delete_data;












private: System::ComponentModel::IContainer^  components;


	protected: 



	protected: 



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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(intel_main::typeid));
			this->panel_left = (gcnew System::Windows::Forms::Panel());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->textBox_lenSub = (gcnew System::Windows::Forms::TextBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->text_sheJiZhangLaQiangDu = (gcnew System::Windows::Forms::TextBox());
			this->text_sheJiYingli = (gcnew System::Windows::Forms::TextBox());
			this->text_gongChen = (gcnew System::Windows::Forms::TextBox());
			this->text_sheJiQiangDu = (gcnew System::Windows::Forms::TextBox());
			this->text_liangChang = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->text_tuJian = (gcnew System::Windows::Forms::TextBox());
			this->label40 = (gcnew System::Windows::Forms::Label());
			this->label41 = (gcnew System::Windows::Forms::Label());
			this->label42 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->text_jianLi = (gcnew System::Windows::Forms::TextBox());
			this->text_shiGong = (gcnew System::Windows::Forms::TextBox());
			this->text_xiangMu = (gcnew System::Windows::Forms::TextBox());
			this->label43 = (gcnew System::Windows::Forms::Label());
			this->label44 = (gcnew System::Windows::Forms::Label());
			this->label45 = (gcnew System::Windows::Forms::Label());
			this->panel_4 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->text_machine4CheckDate = (gcnew System::Windows::Forms::TextBox());
			this->text_ding4HuiGuib = (gcnew System::Windows::Forms::TextBox());
			this->text_ding4HuiGuifx = (gcnew System::Windows::Forms::TextBox());
			this->text_machine4ip = (gcnew System::Windows::Forms::TextBox());
			this->text_ding4Num = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->panel_3 = (gcnew System::Windows::Forms::Panel());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->text_machine3CheckDate = (gcnew System::Windows::Forms::TextBox());
			this->text_ding3HuiGuib = (gcnew System::Windows::Forms::TextBox());
			this->text_ding3HuiGuifx = (gcnew System::Windows::Forms::TextBox());
			this->text_machine3ip = (gcnew System::Windows::Forms::TextBox());
			this->text_ding3Num = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->comboBox_DunWei = (gcnew System::Windows::Forms::ComboBox());
			this->but_SaveProject = (gcnew System::Windows::Forms::Button());
			this->but_modifyProject = (gcnew System::Windows::Forms::Button());
			this->label_dunwei = (gcnew System::Windows::Forms::Label());
			this->panel_2 = (gcnew System::Windows::Forms::Panel());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->text_machine2CheckDate = (gcnew System::Windows::Forms::TextBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->text_machine2ip = (gcnew System::Windows::Forms::TextBox());
			this->text_ding2Num = (gcnew System::Windows::Forms::TextBox());
			this->text_ding2HuiGuib = (gcnew System::Windows::Forms::TextBox());
			this->text_ding2HuiGuifx = (gcnew System::Windows::Forms::TextBox());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->label33 = (gcnew System::Windows::Forms::Label());
			this->panel_1 = (gcnew System::Windows::Forms::Panel());
			this->label36 = (gcnew System::Windows::Forms::Label());
			this->text_machine1CheckDate = (gcnew System::Windows::Forms::TextBox());
			this->text_ding1HuiGuib = (gcnew System::Windows::Forms::TextBox());
			this->text_ding1HuiGuifx = (gcnew System::Windows::Forms::TextBox());
			this->text_machine1ip = (gcnew System::Windows::Forms::TextBox());
			this->text_ding1Num = (gcnew System::Windows::Forms::TextBox());
			this->label34 = (gcnew System::Windows::Forms::Label());
			this->label35 = (gcnew System::Windows::Forms::Label());
			this->label37 = (gcnew System::Windows::Forms::Label());
			this->label38 = (gcnew System::Windows::Forms::Label());
			this->label39 = (gcnew System::Windows::Forms::Label());
			this->panel_right = (gcnew System::Windows::Forms::Panel());
			this->btn_delete_data = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->but_inputGouJian = (gcnew System::Windows::Forms::Button());
			this->but_SoftwareUpdate = (gcnew System::Windows::Forms::Button());
			this->but_exit = (gcnew System::Windows::Forms::Button());
			this->but_safeNote = (gcnew System::Windows::Forms::Button());
			this->but_operationStep = (gcnew System::Windows::Forms::Button());
			this->but_kongxinban = (gcnew System::Windows::Forms::Button());
			this->but_jianZhiT = (gcnew System::Windows::Forms::Button());
			this->but_fuWanJu = (gcnew System::Windows::Forms::Button());
			this->but_ControlMachine = (gcnew System::Windows::Forms::Button());
			this->but_jianZhiXiang = (gcnew System::Windows::Forms::Button());
			this->but_gaiLiang = (gcnew System::Windows::Forms::Button());
			this->but_shuXiangDuan = (gcnew System::Windows::Forms::Button());
			this->but_lianXuZong = (gcnew System::Windows::Forms::Button());
			this->but_otherZhangLa = (gcnew System::Windows::Forms::Button());
			this->but_lianXuHeng = (gcnew System::Windows::Forms::Button());
			this->label_GouJianInfo = (gcnew System::Windows::Forms::Label());
			this->label_project = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label_top = (gcnew System::Windows::Forms::Label());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->but_historySearch = (gcnew System::Windows::Forms::Button());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->panel_left->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel1->SuspendLayout();
			this->panel_4->SuspendLayout();
			this->panel_3->SuspendLayout();
			this->panel_2->SuspendLayout();
			this->panel_1->SuspendLayout();
			this->panel_right->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox3))->BeginInit();
			this->SuspendLayout();
			// 
			// panel_left
			// 
			this->panel_left->AutoSize = true;
			this->panel_left->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel_left->Controls->Add(this->label21);
			this->panel_left->Controls->Add(this->label22);
			this->panel_left->Controls->Add(this->textBox_lenSub);
			this->panel_left->Controls->Add(this->panel2);
			this->panel_left->Controls->Add(this->panel1);
			this->panel_left->Controls->Add(this->panel_4);
			this->panel_left->Controls->Add(this->panel_3);
			this->panel_left->Controls->Add(this->comboBox_DunWei);
			this->panel_left->Controls->Add(this->but_SaveProject);
			this->panel_left->Controls->Add(this->but_modifyProject);
			this->panel_left->Controls->Add(this->label_dunwei);
			this->panel_left->Controls->Add(this->panel_2);
			this->panel_left->Controls->Add(this->panel_1);
			this->panel_left->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->panel_left->Location = System::Drawing::Point(14, 160);
			this->panel_left->Name = L"panel_left";
			this->panel_left->Size = System::Drawing::Size(520, 560);
			this->panel_left->TabIndex = 12;
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Bold));
			this->label21->Location = System::Drawing::Point(179, 509);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(97, 14);
			this->label21->TabIndex = 30;
			this->label21->Text = L"伸长量修正值";
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Bold));
			this->label22->Location = System::Drawing::Point(319, 509);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(23, 14);
			this->label22->TabIndex = 31;
			this->label22->Text = L"mm";
			// 
			// textBox_lenSub
			// 
			this->textBox_lenSub->BackColor = System::Drawing::SystemColors::Info;
			this->textBox_lenSub->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Bold));
			this->textBox_lenSub->Location = System::Drawing::Point(278, 505);
			this->textBox_lenSub->Name = L"textBox_lenSub";
			this->textBox_lenSub->Size = System::Drawing::Size(40, 23);
			this->textBox_lenSub->TabIndex = 29;
			this->textBox_lenSub->Text = L"9";
			this->textBox_lenSub->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox_lenSub->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &intel_main::textBox_lenSub_KeyPress);
			this->textBox_lenSub->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &intel_main::textBox_lenSub_MouseDown);
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->label20);
			this->panel2->Controls->Add(this->label19);
			this->panel2->Controls->Add(this->label18);
			this->panel2->Controls->Add(this->text_sheJiZhangLaQiangDu);
			this->panel2->Controls->Add(this->text_sheJiYingli);
			this->panel2->Controls->Add(this->text_gongChen);
			this->panel2->Controls->Add(this->text_sheJiQiangDu);
			this->panel2->Controls->Add(this->text_liangChang);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Controls->Add(this->label25);
			this->panel2->Controls->Add(this->label26);
			this->panel2->Controls->Add(this->text_tuJian);
			this->panel2->Controls->Add(this->label40);
			this->panel2->Controls->Add(this->label41);
			this->panel2->Controls->Add(this->label42);
			this->panel2->Location = System::Drawing::Point(17, 117);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(480, 98);
			this->panel2->TabIndex = 28;
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(442, 75);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(31, 14);
			this->label20->TabIndex = 29;
			this->label20->Text = L"MPa";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(442, 42);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(31, 14);
			this->label19->TabIndex = 28;
			this->label19->Text = L"MPa";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(208, 75);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(31, 14);
			this->label18->TabIndex = 27;
			this->label18->Text = L"MPa";
			// 
			// text_sheJiZhangLaQiangDu
			// 
			this->text_sheJiZhangLaQiangDu->BackColor = System::Drawing::SystemColors::Info;
			this->text_sheJiZhangLaQiangDu->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->text_sheJiZhangLaQiangDu->Location = System::Drawing::Point(345, 70);
			this->text_sheJiZhangLaQiangDu->Name = L"text_sheJiZhangLaQiangDu";
			this->text_sheJiZhangLaQiangDu->Size = System::Drawing::Size(96, 23);
			this->text_sheJiZhangLaQiangDu->TabIndex = 8;
			this->text_sheJiZhangLaQiangDu->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &intel_main::text_sheJiZhangLaQiangDu_KeyPress);
			this->text_sheJiZhangLaQiangDu->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &intel_main::text_machine4CheckDate_MouseDown);
			// 
			// text_sheJiYingli
			// 
			this->text_sheJiYingli->BackColor = System::Drawing::SystemColors::Info;
			this->text_sheJiYingli->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->text_sheJiYingli->Location = System::Drawing::Point(345, 38);
			this->text_sheJiYingli->Name = L"text_sheJiYingli";
			this->text_sheJiYingli->Size = System::Drawing::Size(96, 23);
			this->text_sheJiYingli->TabIndex = 6;
			this->text_sheJiYingli->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &intel_main::text_sheJiYingli_KeyPress);
			this->text_sheJiYingli->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &intel_main::text_machine4CheckDate_MouseDown);
			// 
			// text_gongChen
			// 
			this->text_gongChen->BackColor = System::Drawing::SystemColors::Info;
			this->text_gongChen->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->text_gongChen->Location = System::Drawing::Point(345, 6);
			this->text_gongChen->Name = L"text_gongChen";
			this->text_gongChen->Size = System::Drawing::Size(120, 23);
			this->text_gongChen->TabIndex = 4;
			this->text_gongChen->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &intel_main::text_machine4CheckDate_MouseDown);
			// 
			// text_sheJiQiangDu
			// 
			this->text_sheJiQiangDu->BackColor = System::Drawing::SystemColors::Info;
			this->text_sheJiQiangDu->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->text_sheJiQiangDu->Location = System::Drawing::Point(110, 70);
			this->text_sheJiQiangDu->Name = L"text_sheJiQiangDu";
			this->text_sheJiQiangDu->Size = System::Drawing::Size(96, 23);
			this->text_sheJiQiangDu->TabIndex = 7;
			this->text_sheJiQiangDu->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &intel_main::text_sheJiQiangDu_KeyPress);
			this->text_sheJiQiangDu->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &intel_main::text_machine4CheckDate_MouseDown);
			// 
			// text_liangChang
			// 
			this->text_liangChang->BackColor = System::Drawing::SystemColors::Info;
			this->text_liangChang->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->text_liangChang->Location = System::Drawing::Point(110, 38);
			this->text_liangChang->Name = L"text_liangChang";
			this->text_liangChang->Size = System::Drawing::Size(120, 23);
			this->text_liangChang->TabIndex = 5;
			this->text_liangChang->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &intel_main::text_machine4CheckDate_MouseDown);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label2->Location = System::Drawing::Point(244, 72);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(75, 14);
			this->label2->TabIndex = 26;
			this->label2->Text = L"弹性模量:";
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label25->Location = System::Drawing::Point(239, 40);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(112, 14);
			this->label25->TabIndex = 25;
			this->label25->Text = L"设计张拉应力：";
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label26->Location = System::Drawing::Point(239, 10);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(82, 14);
			this->label26->TabIndex = 24;
			this->label26->Text = L"工程名称：";
			// 
			// text_tuJian
			// 
			this->text_tuJian->BackColor = System::Drawing::SystemColors::Info;
			this->text_tuJian->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->text_tuJian->Location = System::Drawing::Point(110, 6);
			this->text_tuJian->Name = L"text_tuJian";
			this->text_tuJian->Size = System::Drawing::Size(120, 23);
			this->text_tuJian->TabIndex = 3;
			this->text_tuJian->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &intel_main::text_machine4CheckDate_MouseDown);
			// 
			// label40
			// 
			this->label40->AutoSize = true;
			this->label40->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label40->Location = System::Drawing::Point(5, 72);
			this->label40->Name = L"label40";
			this->label40->Size = System::Drawing::Size(82, 14);
			this->label40->TabIndex = 5;
			this->label40->Text = L"设计强度：";
			// 
			// label41
			// 
			this->label41->AutoSize = true;
			this->label41->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label41->Location = System::Drawing::Point(5, 40);
			this->label41->Name = L"label41";
			this->label41->Size = System::Drawing::Size(82, 14);
			this->label41->TabIndex = 4;
			this->label41->Text = L"预制梁场：";
			// 
			// label42
			// 
			this->label42->AutoSize = true;
			this->label42->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label42->Location = System::Drawing::Point(5, 10);
			this->label42->Name = L"label42";
			this->label42->Size = System::Drawing::Size(97, 14);
			this->label42->TabIndex = 3;
			this->label42->Text = L"土建合同号：";
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->text_jianLi);
			this->panel1->Controls->Add(this->text_shiGong);
			this->panel1->Controls->Add(this->text_xiangMu);
			this->panel1->Controls->Add(this->label43);
			this->panel1->Controls->Add(this->label44);
			this->panel1->Controls->Add(this->label45);
			this->panel1->Location = System::Drawing::Point(17, 14);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(480, 98);
			this->panel1->TabIndex = 27;
			// 
			// text_jianLi
			// 
			this->text_jianLi->BackColor = System::Drawing::SystemColors::Info;
			this->text_jianLi->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->text_jianLi->Location = System::Drawing::Point(110, 64);
			this->text_jianLi->Name = L"text_jianLi";
			this->text_jianLi->Size = System::Drawing::Size(365, 26);
			this->text_jianLi->TabIndex = 2;
			this->text_jianLi->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->text_jianLi->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &intel_main::text_machine4CheckDate_MouseDown);
			// 
			// text_shiGong
			// 
			this->text_shiGong->BackColor = System::Drawing::SystemColors::Info;
			this->text_shiGong->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->text_shiGong->Location = System::Drawing::Point(110, 34);
			this->text_shiGong->Name = L"text_shiGong";
			this->text_shiGong->Size = System::Drawing::Size(365, 26);
			this->text_shiGong->TabIndex = 1;
			this->text_shiGong->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->text_shiGong->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &intel_main::text_machine4CheckDate_MouseDown);
			// 
			// text_xiangMu
			// 
			this->text_xiangMu->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->text_xiangMu->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->text_xiangMu->Location = System::Drawing::Point(110, 5);
			this->text_xiangMu->Name = L"text_xiangMu";
			this->text_xiangMu->Size = System::Drawing::Size(365, 26);
			this->text_xiangMu->TabIndex = 0;
			this->text_xiangMu->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->text_xiangMu->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &intel_main::text_machine4CheckDate_MouseDown);
			// 
			// label43
			// 
			this->label43->AutoSize = true;
			this->label43->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label43->Location = System::Drawing::Point(7, 75);
			this->label43->Name = L"label43";
			this->label43->Size = System::Drawing::Size(82, 14);
			this->label43->TabIndex = 2;
			this->label43->Text = L"监理单位：";
			// 
			// label44
			// 
			this->label44->AutoSize = true;
			this->label44->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label44->Location = System::Drawing::Point(7, 40);
			this->label44->Name = L"label44";
			this->label44->Size = System::Drawing::Size(82, 14);
			this->label44->TabIndex = 1;
			this->label44->Text = L"施工单位：";
			// 
			// label45
			// 
			this->label45->AutoSize = true;
			this->label45->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label45->Location = System::Drawing::Point(7, 10);
			this->label45->Name = L"label45";
			this->label45->Size = System::Drawing::Size(82, 14);
			this->label45->TabIndex = 0;
			this->label45->Text = L"项目名称：";
			// 
			// panel_4
			// 
			this->panel_4->Controls->Add(this->label1);
			this->panel_4->Controls->Add(this->label8);
			this->panel_4->Controls->Add(this->text_machine4CheckDate);
			this->panel_4->Controls->Add(this->text_ding4HuiGuib);
			this->panel_4->Controls->Add(this->text_ding4HuiGuifx);
			this->panel_4->Controls->Add(this->text_machine4ip);
			this->panel_4->Controls->Add(this->text_ding4Num);
			this->panel_4->Controls->Add(this->label9);
			this->panel_4->Controls->Add(this->label10);
			this->panel_4->Controls->Add(this->label11);
			this->panel_4->Controls->Add(this->label12);
			this->panel_4->Controls->Add(this->label13);
			this->panel_4->Location = System::Drawing::Point(17, 434);
			this->panel_4->Name = L"panel_4";
			this->panel_4->Size = System::Drawing::Size(480, 65);
			this->panel_4->TabIndex = 12;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label1->Location = System::Drawing::Point(273, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(48, 16);
			this->label1->TabIndex = 21;
			this->label1->Text = L"(x)=a";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label8->Location = System::Drawing::Point(386, 11);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(32, 16);
			this->label8->TabIndex = 22;
			this->label8->Text = L"x+b";
			// 
			// text_machine4CheckDate
			// 
			this->text_machine4CheckDate->BackColor = System::Drawing::SystemColors::Info;
			this->text_machine4CheckDate->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->text_machine4CheckDate->Location = System::Drawing::Point(104, 37);
			this->text_machine4CheckDate->Name = L"text_machine4CheckDate";
			this->text_machine4CheckDate->Size = System::Drawing::Size(149, 23);
			this->text_machine4CheckDate->TabIndex = 5;
			this->text_machine4CheckDate->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &intel_main::text_machine4CheckDate_KeyPress);
			this->text_machine4CheckDate->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &intel_main::text_machine4CheckDate_MouseDown);
			// 
			// text_ding4HuiGuib
			// 
			this->text_ding4HuiGuib->BackColor = System::Drawing::SystemColors::Info;
			this->text_ding4HuiGuib->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->text_ding4HuiGuib->Location = System::Drawing::Point(416, 9);
			this->text_ding4HuiGuib->Name = L"text_ding4HuiGuib";
			this->text_ding4HuiGuib->Size = System::Drawing::Size(61, 23);
			this->text_ding4HuiGuib->TabIndex = 3;
			this->text_ding4HuiGuib->Text = L"-0.27";
			this->text_ding4HuiGuib->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &intel_main::text_ding4HuiGuib_KeyPress);
			this->text_ding4HuiGuib->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &intel_main::text_machine4CheckDate_MouseDown);
			// 
			// text_ding4HuiGuifx
			// 
			this->text_ding4HuiGuifx->BackColor = System::Drawing::SystemColors::Info;
			this->text_ding4HuiGuifx->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->text_ding4HuiGuifx->Location = System::Drawing::Point(321, 9);
			this->text_ding4HuiGuifx->Name = L"text_ding4HuiGuifx";
			this->text_ding4HuiGuifx->Size = System::Drawing::Size(67, 23);
			this->text_ding4HuiGuifx->TabIndex = 2;
			this->text_ding4HuiGuifx->Text = L"0.052";
			this->text_ding4HuiGuifx->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &intel_main::text_ding4HuiGuifx_KeyPress);
			this->text_ding4HuiGuifx->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &intel_main::text_machine4CheckDate_MouseDown);
			// 
			// text_machine4ip
			// 
			this->text_machine4ip->BackColor = System::Drawing::SystemColors::Info;
			this->text_machine4ip->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->text_machine4ip->Location = System::Drawing::Point(376, 77);
			this->text_machine4ip->Name = L"text_machine4ip";
			this->text_machine4ip->Size = System::Drawing::Size(75, 23);
			this->text_machine4ip->TabIndex = 4;
			this->text_machine4ip->Text = L"192.168.0.1";
			this->text_machine4ip->Visible = false;
			this->text_machine4ip->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &intel_main::text_machine4ip_KeyPress);
			// 
			// text_ding4Num
			// 
			this->text_ding4Num->BackColor = System::Drawing::SystemColors::Info;
			this->text_ding4Num->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->text_ding4Num->Location = System::Drawing::Point(104, 7);
			this->text_ding4Num->Name = L"text_ding4Num";
			this->text_ding4Num->Size = System::Drawing::Size(75, 23);
			this->text_ding4Num->TabIndex = 0;
			this->text_ding4Num->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &intel_main::text_machine4CheckDate_MouseDown);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label9->Location = System::Drawing::Point(184, 10);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(90, 14);
			this->label9->TabIndex = 10;
			this->label9->Text = L"回归方程：f";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label10->Location = System::Drawing::Point(340, 12);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(40, 16);
			this->label10->TabIndex = 1;
			this->label10->Text = L"x)=a";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label11->Location = System::Drawing::Point(273, 77);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(146, 16);
			this->label11->TabIndex = 12;
			this->label11->Text = L"张拉仪4 IP地址：";
			this->label11->Visible = false;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label12->Location = System::Drawing::Point(9, 40);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(82, 14);
			this->label12->TabIndex = 8;
			this->label12->Text = L"检验日期：";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label13->Location = System::Drawing::Point(7, 10);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(105, 14);
			this->label13->TabIndex = 6;
			this->label13->Text = L"千斤顶4编号：";
			// 
			// panel_3
			// 
			this->panel_3->Controls->Add(this->label16);
			this->panel_3->Controls->Add(this->label17);
			this->panel_3->Controls->Add(this->text_machine3CheckDate);
			this->panel_3->Controls->Add(this->text_ding3HuiGuib);
			this->panel_3->Controls->Add(this->text_ding3HuiGuifx);
			this->panel_3->Controls->Add(this->text_machine3ip);
			this->panel_3->Controls->Add(this->text_ding3Num);
			this->panel_3->Controls->Add(this->label3);
			this->panel_3->Controls->Add(this->label4);
			this->panel_3->Controls->Add(this->label5);
			this->panel_3->Controls->Add(this->label6);
			this->panel_3->Controls->Add(this->label7);
			this->panel_3->Location = System::Drawing::Point(17, 364);
			this->panel_3->Name = L"panel_3";
			this->panel_3->Size = System::Drawing::Size(480, 65);
			this->panel_3->TabIndex = 11;
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label16->Location = System::Drawing::Point(273, 10);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(48, 16);
			this->label16->TabIndex = 19;
			this->label16->Text = L"(x)=a";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label17->Location = System::Drawing::Point(386, 11);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(32, 16);
			this->label17->TabIndex = 20;
			this->label17->Text = L"x+b";
			// 
			// text_machine3CheckDate
			// 
			this->text_machine3CheckDate->BackColor = System::Drawing::SystemColors::Info;
			this->text_machine3CheckDate->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->text_machine3CheckDate->Location = System::Drawing::Point(104, 37);
			this->text_machine3CheckDate->Name = L"text_machine3CheckDate";
			this->text_machine3CheckDate->Size = System::Drawing::Size(149, 23);
			this->text_machine3CheckDate->TabIndex = 5;
			this->text_machine3CheckDate->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &intel_main::text_machine3CheckDate_KeyPress);
			this->text_machine3CheckDate->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &intel_main::text_machine4CheckDate_MouseDown);
			// 
			// text_ding3HuiGuib
			// 
			this->text_ding3HuiGuib->BackColor = System::Drawing::SystemColors::Info;
			this->text_ding3HuiGuib->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->text_ding3HuiGuib->Location = System::Drawing::Point(416, 9);
			this->text_ding3HuiGuib->Name = L"text_ding3HuiGuib";
			this->text_ding3HuiGuib->Size = System::Drawing::Size(61, 23);
			this->text_ding3HuiGuib->TabIndex = 3;
			this->text_ding3HuiGuib->Text = L"-0.27";
			this->text_ding3HuiGuib->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &intel_main::text_ding3HuiGuib_KeyPress);
			this->text_ding3HuiGuib->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &intel_main::text_machine4CheckDate_MouseDown);
			// 
			// text_ding3HuiGuifx
			// 
			this->text_ding3HuiGuifx->BackColor = System::Drawing::SystemColors::Info;
			this->text_ding3HuiGuifx->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->text_ding3HuiGuifx->Location = System::Drawing::Point(321, 9);
			this->text_ding3HuiGuifx->Name = L"text_ding3HuiGuifx";
			this->text_ding3HuiGuifx->Size = System::Drawing::Size(67, 23);
			this->text_ding3HuiGuifx->TabIndex = 2;
			this->text_ding3HuiGuifx->Text = L"0.052";
			this->text_ding3HuiGuifx->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &intel_main::text_ding3HuiGuifx_KeyPress);
			this->text_ding3HuiGuifx->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &intel_main::text_machine4CheckDate_MouseDown);
			// 
			// text_machine3ip
			// 
			this->text_machine3ip->BackColor = System::Drawing::SystemColors::Info;
			this->text_machine3ip->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->text_machine3ip->Location = System::Drawing::Point(110, 158);
			this->text_machine3ip->Name = L"text_machine3ip";
			this->text_machine3ip->Size = System::Drawing::Size(75, 23);
			this->text_machine3ip->TabIndex = 4;
			this->text_machine3ip->Text = L"192.168.0.1";
			this->text_machine3ip->Visible = false;
			this->text_machine3ip->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &intel_main::text_machine3ip_KeyPress);
			// 
			// text_ding3Num
			// 
			this->text_ding3Num->BackColor = System::Drawing::SystemColors::Info;
			this->text_ding3Num->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->text_ding3Num->Location = System::Drawing::Point(104, 7);
			this->text_ding3Num->Name = L"text_ding3Num";
			this->text_ding3Num->Size = System::Drawing::Size(75, 23);
			this->text_ding3Num->TabIndex = 0;
			this->text_ding3Num->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &intel_main::text_machine4CheckDate_MouseDown);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label3->Location = System::Drawing::Point(184, 11);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(90, 14);
			this->label3->TabIndex = 10;
			this->label3->Text = L"回归方程：f";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label4->Location = System::Drawing::Point(340, 10);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(40, 16);
			this->label4->TabIndex = 1;
			this->label4->Text = L"x)=a";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label5->Location = System::Drawing::Point(7, 158);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(146, 16);
			this->label5->TabIndex = 12;
			this->label5->Text = L"张拉仪3 IP地址：";
			this->label5->Visible = false;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label6->Location = System::Drawing::Point(9, 40);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(82, 14);
			this->label6->TabIndex = 8;
			this->label6->Text = L"检验日期：";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label7->Location = System::Drawing::Point(7, 10);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(105, 14);
			this->label7->TabIndex = 6;
			this->label7->Text = L"千斤顶3编号：";
			// 
			// comboBox_DunWei
			// 
			this->comboBox_DunWei->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->comboBox_DunWei->FormattingEnabled = true;
			this->comboBox_DunWei->Items->AddRange(gcnew cli::array< System::Object^  >(12) {L"26  T", L"60  T", L"100 T", L"150 T", L"200 T", 
				L"250 T", L"300 T", L"350 T", L"400 T", L"450 T", L"500 T", L"600 T"});
			this->comboBox_DunWei->Location = System::Drawing::Point(106, 505);
			this->comboBox_DunWei->Name = L"comboBox_DunWei";
			this->comboBox_DunWei->Size = System::Drawing::Size(70, 22);
			this->comboBox_DunWei->TabIndex = 13;
			// 
			// but_SaveProject
			// 
			this->but_SaveProject->Enabled = false;
			this->but_SaveProject->Font = (gcnew System::Drawing::Font(L"黑体", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->but_SaveProject->ForeColor = System::Drawing::Color::Black;
			this->but_SaveProject->Location = System::Drawing::Point(423, 497);
			this->but_SaveProject->Name = L"but_SaveProject";
			this->but_SaveProject->Size = System::Drawing::Size(79, 33);
			this->but_SaveProject->TabIndex = 15;
			this->but_SaveProject->Text = L"保 存";
			this->but_SaveProject->UseVisualStyleBackColor = true;
			this->but_SaveProject->Click += gcnew System::EventHandler(this, &intel_main::but_SaveProject_Click);
			// 
			// but_modifyProject
			// 
			this->but_modifyProject->Font = (gcnew System::Drawing::Font(L"黑体", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->but_modifyProject->ForeColor = System::Drawing::Color::Black;
			this->but_modifyProject->Location = System::Drawing::Point(343, 497);
			this->but_modifyProject->Name = L"but_modifyProject";
			this->but_modifyProject->Size = System::Drawing::Size(79, 33);
			this->but_modifyProject->TabIndex = 14;
			this->but_modifyProject->Text = L"修 改";
			this->but_modifyProject->UseVisualStyleBackColor = true;
			this->but_modifyProject->Click += gcnew System::EventHandler(this, &intel_main::but_modifyProject_Click);
			// 
			// label_dunwei
			// 
			this->label_dunwei->AutoSize = true;
			this->label_dunwei->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label_dunwei->Location = System::Drawing::Point(11, 509);
			this->label_dunwei->Name = L"label_dunwei";
			this->label_dunwei->Size = System::Drawing::Size(105, 14);
			this->label_dunwei->TabIndex = 17;
			this->label_dunwei->Text = L"千斤顶 吨位：";
			// 
			// panel_2
			// 
			this->panel_2->Controls->Add(this->label14);
			this->panel_2->Controls->Add(this->text_machine2CheckDate);
			this->panel_2->Controls->Add(this->label15);
			this->panel_2->Controls->Add(this->text_machine2ip);
			this->panel_2->Controls->Add(this->text_ding2Num);
			this->panel_2->Controls->Add(this->text_ding2HuiGuib);
			this->panel_2->Controls->Add(this->text_ding2HuiGuifx);
			this->panel_2->Controls->Add(this->label28);
			this->panel_2->Controls->Add(this->label29);
			this->panel_2->Controls->Add(this->label31);
			this->panel_2->Controls->Add(this->label32);
			this->panel_2->Controls->Add(this->label33);
			this->panel_2->Location = System::Drawing::Point(17, 294);
			this->panel_2->Name = L"panel_2";
			this->panel_2->Size = System::Drawing::Size(480, 65);
			this->panel_2->TabIndex = 10;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label14->Location = System::Drawing::Point(273, 10);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(48, 16);
			this->label14->TabIndex = 16;
			this->label14->Text = L"(x)=a";
			// 
			// text_machine2CheckDate
			// 
			this->text_machine2CheckDate->BackColor = System::Drawing::SystemColors::Info;
			this->text_machine2CheckDate->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->text_machine2CheckDate->Location = System::Drawing::Point(104, 37);
			this->text_machine2CheckDate->Name = L"text_machine2CheckDate";
			this->text_machine2CheckDate->Size = System::Drawing::Size(149, 23);
			this->text_machine2CheckDate->TabIndex = 5;
			this->text_machine2CheckDate->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &intel_main::text_machine2CheckDate_KeyPress);
			this->text_machine2CheckDate->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &intel_main::text_machine4CheckDate_MouseDown);
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label15->Location = System::Drawing::Point(386, 10);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(32, 16);
			this->label15->TabIndex = 17;
			this->label15->Text = L"x+b";
			// 
			// text_machine2ip
			// 
			this->text_machine2ip->BackColor = System::Drawing::SystemColors::Info;
			this->text_machine2ip->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->text_machine2ip->Location = System::Drawing::Point(110, 250);
			this->text_machine2ip->Name = L"text_machine2ip";
			this->text_machine2ip->Size = System::Drawing::Size(75, 23);
			this->text_machine2ip->TabIndex = 4;
			this->text_machine2ip->Text = L"192.168.0.1";
			this->text_machine2ip->Visible = false;
			this->text_machine2ip->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &intel_main::text_machine2ip_KeyPress);
			// 
			// text_ding2Num
			// 
			this->text_ding2Num->BackColor = System::Drawing::SystemColors::Info;
			this->text_ding2Num->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->text_ding2Num->Location = System::Drawing::Point(104, 7);
			this->text_ding2Num->Name = L"text_ding2Num";
			this->text_ding2Num->Size = System::Drawing::Size(75, 23);
			this->text_ding2Num->TabIndex = 0;
			this->text_ding2Num->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &intel_main::text_machine4CheckDate_MouseDown);
			// 
			// text_ding2HuiGuib
			// 
			this->text_ding2HuiGuib->BackColor = System::Drawing::SystemColors::Info;
			this->text_ding2HuiGuib->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->text_ding2HuiGuib->Location = System::Drawing::Point(416, 8);
			this->text_ding2HuiGuib->Name = L"text_ding2HuiGuib";
			this->text_ding2HuiGuib->Size = System::Drawing::Size(61, 23);
			this->text_ding2HuiGuib->TabIndex = 3;
			this->text_ding2HuiGuib->Text = L"-0.27";
			this->text_ding2HuiGuib->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &intel_main::text_ding2HuiGuib_KeyPress);
			this->text_ding2HuiGuib->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &intel_main::text_machine4CheckDate_MouseDown);
			// 
			// text_ding2HuiGuifx
			// 
			this->text_ding2HuiGuifx->BackColor = System::Drawing::SystemColors::Info;
			this->text_ding2HuiGuifx->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->text_ding2HuiGuifx->Location = System::Drawing::Point(321, 9);
			this->text_ding2HuiGuifx->Name = L"text_ding2HuiGuifx";
			this->text_ding2HuiGuifx->Size = System::Drawing::Size(67, 23);
			this->text_ding2HuiGuifx->TabIndex = 2;
			this->text_ding2HuiGuifx->Text = L"0.052";
			this->text_ding2HuiGuifx->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &intel_main::text_ding2HuiGuifx_KeyPress);
			this->text_ding2HuiGuifx->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &intel_main::text_machine4CheckDate_MouseDown);
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label28->Location = System::Drawing::Point(512, 19);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(32, 16);
			this->label28->TabIndex = 18;
			this->label28->Text = L"x+b";
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label29->Location = System::Drawing::Point(184, 11);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(90, 14);
			this->label29->TabIndex = 16;
			this->label29->Text = L"回归方程：f";
			// 
			// label31
			// 
			this->label31->AutoSize = true;
			this->label31->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label31->Location = System::Drawing::Point(7, 250);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(146, 16);
			this->label31->TabIndex = 13;
			this->label31->Text = L"张拉仪2 IP地址：";
			this->label31->Visible = false;
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label32->Location = System::Drawing::Point(9, 40);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(82, 14);
			this->label32->TabIndex = 9;
			this->label32->Text = L"检验日期：";
			// 
			// label33
			// 
			this->label33->AutoSize = true;
			this->label33->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label33->Location = System::Drawing::Point(7, 10);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(105, 14);
			this->label33->TabIndex = 7;
			this->label33->Text = L"千斤顶2编号：";
			// 
			// panel_1
			// 
			this->panel_1->Controls->Add(this->label36);
			this->panel_1->Controls->Add(this->text_machine1CheckDate);
			this->panel_1->Controls->Add(this->text_ding1HuiGuib);
			this->panel_1->Controls->Add(this->text_ding1HuiGuifx);
			this->panel_1->Controls->Add(this->text_machine1ip);
			this->panel_1->Controls->Add(this->text_ding1Num);
			this->panel_1->Controls->Add(this->label34);
			this->panel_1->Controls->Add(this->label35);
			this->panel_1->Controls->Add(this->label37);
			this->panel_1->Controls->Add(this->label38);
			this->panel_1->Controls->Add(this->label39);
			this->panel_1->Location = System::Drawing::Point(17, 224);
			this->panel_1->Name = L"panel_1";
			this->panel_1->Size = System::Drawing::Size(480, 65);
			this->panel_1->TabIndex = 9;
			// 
			// label36
			// 
			this->label36->AutoSize = true;
			this->label36->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label36->Location = System::Drawing::Point(273, 9);
			this->label36->Name = L"label36";
			this->label36->Size = System::Drawing::Size(48, 16);
			this->label36->TabIndex = 1;
			this->label36->Text = L"(x)=a";
			// 
			// text_machine1CheckDate
			// 
			this->text_machine1CheckDate->BackColor = System::Drawing::SystemColors::Info;
			this->text_machine1CheckDate->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->text_machine1CheckDate->Location = System::Drawing::Point(104, 36);
			this->text_machine1CheckDate->Name = L"text_machine1CheckDate";
			this->text_machine1CheckDate->Size = System::Drawing::Size(149, 23);
			this->text_machine1CheckDate->TabIndex = 5;
			this->text_machine1CheckDate->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &intel_main::text_machine1CheckDate_KeyPress);
			this->text_machine1CheckDate->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &intel_main::text_machine4CheckDate_MouseDown);
			// 
			// text_ding1HuiGuib
			// 
			this->text_ding1HuiGuib->BackColor = System::Drawing::SystemColors::Info;
			this->text_ding1HuiGuib->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->text_ding1HuiGuib->Location = System::Drawing::Point(416, 9);
			this->text_ding1HuiGuib->Name = L"text_ding1HuiGuib";
			this->text_ding1HuiGuib->Size = System::Drawing::Size(61, 23);
			this->text_ding1HuiGuib->TabIndex = 3;
			this->text_ding1HuiGuib->Text = L"-0.27";
			this->text_ding1HuiGuib->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &intel_main::text_ding1HuiGuib_KeyPress);
			this->text_ding1HuiGuib->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &intel_main::text_machine4CheckDate_MouseDown);
			// 
			// text_ding1HuiGuifx
			// 
			this->text_ding1HuiGuifx->BackColor = System::Drawing::SystemColors::Info;
			this->text_ding1HuiGuifx->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->text_ding1HuiGuifx->Location = System::Drawing::Point(321, 9);
			this->text_ding1HuiGuifx->Name = L"text_ding1HuiGuifx";
			this->text_ding1HuiGuifx->Size = System::Drawing::Size(67, 23);
			this->text_ding1HuiGuifx->TabIndex = 2;
			this->text_ding1HuiGuifx->Text = L"0.052";
			this->text_ding1HuiGuifx->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &intel_main::text_ding1HuiGuifx_KeyPress);
			this->text_ding1HuiGuifx->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &intel_main::text_machine4CheckDate_MouseDown);
			// 
			// text_machine1ip
			// 
			this->text_machine1ip->BackColor = System::Drawing::SystemColors::Info;
			this->text_machine1ip->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->text_machine1ip->Location = System::Drawing::Point(110, 353);
			this->text_machine1ip->Name = L"text_machine1ip";
			this->text_machine1ip->Size = System::Drawing::Size(75, 23);
			this->text_machine1ip->TabIndex = 4;
			this->text_machine1ip->Text = L"192.168.0.1";
			this->text_machine1ip->Visible = false;
			this->text_machine1ip->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &intel_main::text_machine1ip_KeyPress);
			// 
			// text_ding1Num
			// 
			this->text_ding1Num->BackColor = System::Drawing::SystemColors::Info;
			this->text_ding1Num->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->text_ding1Num->Location = System::Drawing::Point(104, 7);
			this->text_ding1Num->Name = L"text_ding1Num";
			this->text_ding1Num->Size = System::Drawing::Size(75, 23);
			this->text_ding1Num->TabIndex = 0;
			this->text_ding1Num->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &intel_main::text_machine4CheckDate_MouseDown);
			// 
			// label34
			// 
			this->label34->AutoSize = true;
			this->label34->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label34->Location = System::Drawing::Point(386, 12);
			this->label34->Name = L"label34";
			this->label34->Size = System::Drawing::Size(32, 16);
			this->label34->TabIndex = 15;
			this->label34->Text = L"x+b";
			// 
			// label35
			// 
			this->label35->AutoSize = true;
			this->label35->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label35->Location = System::Drawing::Point(184, 10);
			this->label35->Name = L"label35";
			this->label35->Size = System::Drawing::Size(90, 14);
			this->label35->TabIndex = 10;
			this->label35->Text = L"回归方程：f";
			// 
			// label37
			// 
			this->label37->AutoSize = true;
			this->label37->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label37->Location = System::Drawing::Point(7, 353);
			this->label37->Name = L"label37";
			this->label37->Size = System::Drawing::Size(146, 16);
			this->label37->TabIndex = 12;
			this->label37->Text = L"张拉仪1 IP地址：";
			this->label37->Visible = false;
			// 
			// label38
			// 
			this->label38->AutoSize = true;
			this->label38->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label38->Location = System::Drawing::Point(9, 39);
			this->label38->Name = L"label38";
			this->label38->Size = System::Drawing::Size(82, 14);
			this->label38->TabIndex = 8;
			this->label38->Text = L"检验日期：";
			// 
			// label39
			// 
			this->label39->AutoSize = true;
			this->label39->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label39->Location = System::Drawing::Point(7, 10);
			this->label39->Name = L"label39";
			this->label39->Size = System::Drawing::Size(105, 14);
			this->label39->TabIndex = 6;
			this->label39->Text = L"千斤顶1编号：";
			// 
			// panel_right
			// 
			this->panel_right->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel_right->Controls->Add(this->btn_delete_data);
			this->panel_right->Controls->Add(this->pictureBox1);
			this->panel_right->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->panel_right->Location = System::Drawing::Point(540, 160);
			this->panel_right->Name = L"panel_right";
			this->panel_right->Size = System::Drawing::Size(464, 510);
			this->panel_right->TabIndex = 16;
			// 
			// btn_delete_data
			// 
			this->btn_delete_data->Font = (gcnew System::Drawing::Font(L"宋体", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->btn_delete_data->Location = System::Drawing::Point(379, 20);
			this->btn_delete_data->Name = L"btn_delete_data";
			this->btn_delete_data->Size = System::Drawing::Size(70, 26);
			this->btn_delete_data->TabIndex = 5;
			this->btn_delete_data->Text = L"删除条目";
			this->btn_delete_data->UseVisualStyleBackColor = true;
			this->btn_delete_data->Click += gcnew System::EventHandler(this, &intel_main::btn_delete_data_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(230, 160);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 4;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Visible = false;
			// 
			// but_inputGouJian
			// 
			this->but_inputGouJian->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->but_inputGouJian->ForeColor = System::Drawing::Color::Black;
			this->but_inputGouJian->Location = System::Drawing::Point(737, 75);
			this->but_inputGouJian->Name = L"but_inputGouJian";
			this->but_inputGouJian->Size = System::Drawing::Size(92, 35);
			this->but_inputGouJian->TabIndex = 15;
			this->but_inputGouJian->Text = L"构件输入";
			this->but_inputGouJian->UseVisualStyleBackColor = true;
			this->but_inputGouJian->Click += gcnew System::EventHandler(this, &intel_main::but_inputGouJian_Click);
			// 
			// but_SoftwareUpdate
			// 
			this->but_SoftwareUpdate->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->but_SoftwareUpdate->ForeColor = System::Drawing::Color::Black;
			this->but_SoftwareUpdate->Location = System::Drawing::Point(830, 75);
			this->but_SoftwareUpdate->Name = L"but_SoftwareUpdate";
			this->but_SoftwareUpdate->Size = System::Drawing::Size(92, 35);
			this->but_SoftwareUpdate->TabIndex = 15;
			this->but_SoftwareUpdate->Text = L"软件升级";
			this->but_SoftwareUpdate->UseVisualStyleBackColor = true;
			this->but_SoftwareUpdate->Click += gcnew System::EventHandler(this, &intel_main::but_SoftwareUpdate_Click);
			// 
			// but_exit
			// 
			this->but_exit->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->but_exit->ForeColor = System::Drawing::Color::Black;
			this->but_exit->Location = System::Drawing::Point(923, 75);
			this->but_exit->Name = L"but_exit";
			this->but_exit->Size = System::Drawing::Size(92, 35);
			this->but_exit->TabIndex = 15;
			this->but_exit->Text = L"系统退出";
			this->but_exit->UseVisualStyleBackColor = true;
			this->but_exit->Click += gcnew System::EventHandler(this, &intel_main::but_exit_Click);
			// 
			// but_safeNote
			// 
			this->but_safeNote->AutoSize = true;
			this->but_safeNote->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->but_safeNote->ForeColor = System::Drawing::Color::Maroon;
			this->but_safeNote->Location = System::Drawing::Point(2, 74);
			this->but_safeNote->Name = L"but_safeNote";
			this->but_safeNote->Size = System::Drawing::Size(89, 35);
			this->but_safeNote->TabIndex = 0;
			this->but_safeNote->Text = L"安全需知";
			this->but_safeNote->UseVisualStyleBackColor = true;
			this->but_safeNote->Click += gcnew System::EventHandler(this, &intel_main::button1_Click);
			// 
			// but_operationStep
			// 
			this->but_operationStep->AutoSize = true;
			this->but_operationStep->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->but_operationStep->ForeColor = System::Drawing::Color::Maroon;
			this->but_operationStep->Location = System::Drawing::Point(92, 74);
			this->but_operationStep->Name = L"but_operationStep";
			this->but_operationStep->Size = System::Drawing::Size(89, 35);
			this->but_operationStep->TabIndex = 1;
			this->but_operationStep->Text = L"操作流程";
			this->but_operationStep->UseVisualStyleBackColor = true;
			this->but_operationStep->Click += gcnew System::EventHandler(this, &intel_main::button4_Click);
			// 
			// but_kongxinban
			// 
			this->but_kongxinban->AutoSize = true;
			this->but_kongxinban->BackColor = System::Drawing::SystemColors::Info;
			this->but_kongxinban->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->but_kongxinban->ForeColor = System::Drawing::Color::Black;
			this->but_kongxinban->Location = System::Drawing::Point(2, 112);
			this->but_kongxinban->Name = L"but_kongxinban";
			this->but_kongxinban->Size = System::Drawing::Size(89, 35);
			this->but_kongxinban->TabIndex = 3;
			this->but_kongxinban->Text = L"空心板梁";
			this->but_kongxinban->UseVisualStyleBackColor = true;
			this->but_kongxinban->Click += gcnew System::EventHandler(this, &intel_main::but_kongxinban_Click);
			// 
			// but_jianZhiT
			// 
			this->but_jianZhiT->AutoSize = true;
			this->but_jianZhiT->BackColor = System::Drawing::SystemColors::Info;
			this->but_jianZhiT->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->but_jianZhiT->ForeColor = System::Drawing::Color::Black;
			this->but_jianZhiT->Location = System::Drawing::Point(93, 112);
			this->but_jianZhiT->Name = L"but_jianZhiT";
			this->but_jianZhiT->Size = System::Drawing::Size(89, 35);
			this->but_jianZhiT->TabIndex = 4;
			this->but_jianZhiT->Text = L"简支T梁";
			this->but_jianZhiT->UseVisualStyleBackColor = true;
			this->but_jianZhiT->Click += gcnew System::EventHandler(this, &intel_main::but_jianZhiT_Click);
			// 
			// but_fuWanJu
			// 
			this->but_fuWanJu->AutoSize = true;
			this->but_fuWanJu->BackColor = System::Drawing::SystemColors::Info;
			this->but_fuWanJu->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->but_fuWanJu->ForeColor = System::Drawing::Color::Black;
			this->but_fuWanJu->Location = System::Drawing::Point(274, 112);
			this->but_fuWanJu->Name = L"but_fuWanJu";
			this->but_fuWanJu->Size = System::Drawing::Size(89, 35);
			this->but_fuWanJu->TabIndex = 6;
			this->but_fuWanJu->Text = L"负弯矩束";
			this->but_fuWanJu->UseVisualStyleBackColor = true;
			this->but_fuWanJu->Click += gcnew System::EventHandler(this, &intel_main::but_fuWanJu_Click);
			// 
			// but_ControlMachine
			// 
			this->but_ControlMachine->AutoSize = true;
			this->but_ControlMachine->Font = (gcnew System::Drawing::Font(L"黑体", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->but_ControlMachine->ForeColor = System::Drawing::SystemColors::Desktop;
			this->but_ControlMachine->Location = System::Drawing::Point(582, 674);
			this->but_ControlMachine->Name = L"but_ControlMachine";
			this->but_ControlMachine->Size = System::Drawing::Size(179, 40);
			this->but_ControlMachine->TabIndex = 6;
			this->but_ControlMachine->Text = L"开 始 张 拉";
			this->but_ControlMachine->UseVisualStyleBackColor = true;
			this->but_ControlMachine->Click += gcnew System::EventHandler(this, &intel_main::but_ControlMachine_Click);
			// 
			// but_jianZhiXiang
			// 
			this->but_jianZhiXiang->AutoSize = true;
			this->but_jianZhiXiang->BackColor = System::Drawing::SystemColors::Info;
			this->but_jianZhiXiang->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->but_jianZhiXiang->ForeColor = System::Drawing::Color::Black;
			this->but_jianZhiXiang->Location = System::Drawing::Point(184, 112);
			this->but_jianZhiXiang->Name = L"but_jianZhiXiang";
			this->but_jianZhiXiang->Size = System::Drawing::Size(89, 35);
			this->but_jianZhiXiang->TabIndex = 5;
			this->but_jianZhiXiang->Text = L"简支箱梁";
			this->but_jianZhiXiang->UseVisualStyleBackColor = true;
			this->but_jianZhiXiang->Click += gcnew System::EventHandler(this, &intel_main::but_jianZhiXiang_Click);
			// 
			// but_gaiLiang
			// 
			this->but_gaiLiang->AutoSize = true;
			this->but_gaiLiang->BackColor = System::Drawing::SystemColors::Info;
			this->but_gaiLiang->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->but_gaiLiang->ForeColor = System::Drawing::Color::Black;
			this->but_gaiLiang->Location = System::Drawing::Point(661, 112);
			this->but_gaiLiang->Name = L"but_gaiLiang";
			this->but_gaiLiang->Size = System::Drawing::Size(89, 35);
			this->but_gaiLiang->TabIndex = 10;
			this->but_gaiLiang->Text = L"盖  梁";
			this->but_gaiLiang->UseVisualStyleBackColor = true;
			this->but_gaiLiang->Click += gcnew System::EventHandler(this, &intel_main::but_gaiLiang_Click);
			// 
			// but_shuXiangDuan
			// 
			this->but_shuXiangDuan->AutoSize = true;
			this->but_shuXiangDuan->BackColor = System::Drawing::SystemColors::Info;
			this->but_shuXiangDuan->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->but_shuXiangDuan->ForeColor = System::Drawing::Color::Black;
			this->but_shuXiangDuan->Location = System::Drawing::Point(571, 112);
			this->but_shuXiangDuan->Name = L"but_shuXiangDuan";
			this->but_shuXiangDuan->Size = System::Drawing::Size(89, 35);
			this->but_shuXiangDuan->TabIndex = 9;
			this->but_shuXiangDuan->Text = L"竖向短束";
			this->but_shuXiangDuan->UseVisualStyleBackColor = true;
			this->but_shuXiangDuan->Click += gcnew System::EventHandler(this, &intel_main::but_shuXiangDuan_Click);
			// 
			// but_lianXuZong
			// 
			this->but_lianXuZong->BackColor = System::Drawing::SystemColors::Info;
			this->but_lianXuZong->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->but_lianXuZong->ForeColor = System::Drawing::Color::Black;
			this->but_lianXuZong->Location = System::Drawing::Point(364, 112);
			this->but_lianXuZong->Name = L"but_lianXuZong";
			this->but_lianXuZong->Size = System::Drawing::Size(101, 35);
			this->but_lianXuZong->TabIndex = 7;
			this->but_lianXuZong->Text = L"连续梁纵向";
			this->but_lianXuZong->UseVisualStyleBackColor = true;
			this->but_lianXuZong->Click += gcnew System::EventHandler(this, &intel_main::but_lianXuZong_Click);
			// 
			// but_otherZhangLa
			// 
			this->but_otherZhangLa->AutoSize = true;
			this->but_otherZhangLa->BackColor = System::Drawing::SystemColors::Info;
			this->but_otherZhangLa->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->but_otherZhangLa->ForeColor = System::Drawing::Color::Black;
			this->but_otherZhangLa->Location = System::Drawing::Point(751, 112);
			this->but_otherZhangLa->Name = L"but_otherZhangLa";
			this->but_otherZhangLa->Size = System::Drawing::Size(89, 35);
			this->but_otherZhangLa->TabIndex = 11;
			this->but_otherZhangLa->Text = L"其它张拉";
			this->but_otherZhangLa->UseVisualStyleBackColor = true;
			this->but_otherZhangLa->Click += gcnew System::EventHandler(this, &intel_main::but_otherZhangLa_Click);
			// 
			// but_lianXuHeng
			// 
			this->but_lianXuHeng->AutoSize = true;
			this->but_lianXuHeng->BackColor = System::Drawing::SystemColors::Info;
			this->but_lianXuHeng->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->but_lianXuHeng->ForeColor = System::Drawing::Color::Black;
			this->but_lianXuHeng->Location = System::Drawing::Point(467, 112);
			this->but_lianXuHeng->Name = L"but_lianXuHeng";
			this->but_lianXuHeng->Size = System::Drawing::Size(103, 35);
			this->but_lianXuHeng->TabIndex = 8;
			this->but_lianXuHeng->Text = L"连续梁横向";
			this->but_lianXuHeng->UseVisualStyleBackColor = true;
			this->but_lianXuHeng->Click += gcnew System::EventHandler(this, &intel_main::but_lianXuHeng_Click);
			// 
			// label_GouJianInfo
			// 
			this->label_GouJianInfo->AutoSize = true;
			this->label_GouJianInfo->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label_GouJianInfo->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->label_GouJianInfo->Location = System::Drawing::Point(560, 152);
			this->label_GouJianInfo->Name = L"label_GouJianInfo";
			this->label_GouJianInfo->Size = System::Drawing::Size(72, 16);
			this->label_GouJianInfo->TabIndex = 13;
			this->label_GouJianInfo->Text = L"构件信息";
			// 
			// label_project
			// 
			this->label_project->AutoSize = true;
			this->label_project->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label_project->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->label_project->Location = System::Drawing::Point(22, 151);
			this->label_project->Name = L"label_project";
			this->label_project->Size = System::Drawing::Size(72, 16);
			this->label_project->TabIndex = 17;
			this->label_project->Text = L"项目信息";
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &intel_main::timer1_Tick);
			// 
			// label_top
			// 
			this->label_top->BackColor = System::Drawing::Color::Silver;
			this->label_top->Location = System::Drawing::Point(0, 0);
			this->label_top->Name = L"label_top";
			this->label_top->Size = System::Drawing::Size(1018, 109);
			this->label_top->TabIndex = 18;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(290, 10);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(418, 62);
			this->pictureBox2->TabIndex = 19;
			this->pictureBox2->TabStop = false;
			// 
			// but_historySearch
			// 
			this->but_historySearch->AutoSize = true;
			this->but_historySearch->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->but_historySearch->ForeColor = System::Drawing::Color::Black;
			this->but_historySearch->Location = System::Drawing::Point(182, 74);
			this->but_historySearch->Name = L"but_historySearch";
			this->but_historySearch->Size = System::Drawing::Size(89, 35);
			this->but_historySearch->TabIndex = 2;
			this->but_historySearch->Text = L"历史查询";
			this->but_historySearch->UseVisualStyleBackColor = true;
			// 
			// pictureBox3
			// 
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(3, 3);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(181, 71);
			this->pictureBox3->TabIndex = 20;
			this->pictureBox3->TabStop = false;
			// 
			// intel_main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1016, 730);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->label_project);
			this->Controls->Add(this->but_ControlMachine);
			this->Controls->Add(this->label_GouJianInfo);
			this->Controls->Add(this->but_lianXuHeng);
			this->Controls->Add(this->but_otherZhangLa);
			this->Controls->Add(this->but_gaiLiang);
			this->Controls->Add(this->but_shuXiangDuan);
			this->Controls->Add(this->but_lianXuZong);
			this->Controls->Add(this->but_fuWanJu);
			this->Controls->Add(this->but_jianZhiXiang);
			this->Controls->Add(this->but_jianZhiT);
			this->Controls->Add(this->but_kongxinban);
			this->Controls->Add(this->but_historySearch);
			this->Controls->Add(this->but_operationStep);
			this->Controls->Add(this->but_safeNote);
			this->Controls->Add(this->but_SoftwareUpdate);
			this->Controls->Add(this->but_exit);
			this->Controls->Add(this->but_inputGouJian);
			this->Controls->Add(this->panel_left);
			this->Controls->Add(this->panel_right);
			this->Controls->Add(this->label_top);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"intel_main";
			this->Text = L"湖南聚创  智能张拉系统";
			this->MinimumSizeChanged += gcnew System::EventHandler(this, &intel_main::intel_main_MinimumSizeChanged);
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &intel_main::intel_main_FormClosing);
			this->Load += gcnew System::EventHandler(this, &intel_main::intel_main_Load);
			this->Shown += gcnew System::EventHandler(this, &intel_main::intel_main_Shown);
			this->panel_left->ResumeLayout(false);
			this->panel_left->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel_4->ResumeLayout(false);
			this->panel_4->PerformLayout();
			this->panel_3->ResumeLayout(false);
			this->panel_3->PerformLayout();
			this->panel_2->ResumeLayout(false);
			this->panel_2->PerformLayout();
			this->panel_1->ResumeLayout(false);
			this->panel_1->PerformLayout();
			this->panel_right->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox3))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label13_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void label15_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		//safewNote().ShowDialog();
		m_safeNote.ShowDialog();
		 }
private: System::Void intel_main_Shown(System::Object^  sender, System::EventArgs^  e) {
			 if( !bInit) {
				 bInit = 1;
				 for(int j=0;j< 64;j++) 
				 { 
					 this->right_label[j] = (gcnew System::Windows::Forms::Label()); 
					 //this->right_label[j]->ContextMenuStrip = this->右键选项;
					 this->right_label[j]->Font = (gcnew System::Drawing::Font(L"宋体", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
						 static_cast<System::Byte>(134)));
					 this->right_label[j]->Location = System::Drawing::Point(512 + j*50, 200 + j*25); 
					 this->right_label[j]->Name = L"rightLabel"; 
					 this->right_label[j]->Size = System::Drawing::Size(40, 20); 
					 this->right_label[j]->Text = L""; 
					 this->right_label[j]->Visible = false;
					 this->panel_right->Controls->Add(this->right_label[j]); 
				 } 
				 for(int j=0;j<7;j++) 
				 { 
					 this->right_ComboBox[j] = (gcnew System::Windows::Forms::ComboBox()); 
					 this->right_ComboBox[j]->Location = System::Drawing::Point(512 + j*50, 230 + j*25); 
					 this->right_ComboBox[j]->Font = (gcnew System::Drawing::Font(L"宋体", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
						 static_cast<System::Byte>(134)));
					 this->right_ComboBox[j]->Name = L"ComboBox"; 
					 this->right_ComboBox[j]->Size = System::Drawing::Size(40, 20); 
					 this->right_ComboBox[j]->Text = L""; 
					 this->right_ComboBox[j]->Visible = false;
					 this->right_ComboBox[j]->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
					 this->panel_right->Controls->Add(this->right_ComboBox[j]); 
				 } 
				 this->right_ComboBox[0]->SelectedIndexChanged += gcnew System::EventHandler(this, &intel_main::right_ComboBox0_SelectedIndexChanged);
				 this->right_ComboBox[0]->SelectionChangeCommitted += gcnew System::EventHandler(this, &intel_main::comboBox0_SelectionChangeCommitted);
				 this->right_ComboBox[1]->SelectedIndexChanged += gcnew System::EventHandler(this, &intel_main::right_ComboBox1_SelectedIndexChanged);
				 this->right_ComboBox[2]->SelectedIndexChanged += gcnew System::EventHandler(this, &intel_main::right_ComboBox2_SelectedIndexChanged);
				 for(int j=0;j< 64;j++) 
				 { 
					 this->right_TextBox[j] = (gcnew System::Windows::Forms::TextBox()); 
					 this->right_TextBox[j]->Location = System::Drawing::Point(512 + j*50, 280 +  j*25); 
					 this->right_TextBox[j]->Font = (gcnew System::Drawing::Font(L"宋体", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
						 static_cast<System::Byte>(134)));
					 this->right_TextBox[j]->Name = L"ComboBox"; 
					 this->right_TextBox[j]->Size = System::Drawing::Size(40, 20); 
					 this->right_TextBox[j]->Text = L""; 
					 this->right_TextBox[j]->Visible = false;
					 this->panel_right->Controls->Add(this->right_TextBox[j]); 
				 }
				 for(int j=0;j< holeInfoNum;j++) 
					 this->str_holeInfo[j] = (gcnew System::String("")); 
				 
				 for(int j=0;j<zhangLaSeqNum;j++) 
				 { 
					 this->sequence_label[j] = (gcnew System::Windows::Forms::Label()); 
					 this->sequence_label[j]->Font = (gcnew System::Drawing::Font(L"宋体", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
						 static_cast<System::Byte>(134)));
					 if( j < 6 )
						 this->sequence_label[j]->Location = System::Drawing::Point(70 + j * 80, 453  ); 
					 else
						 this->sequence_label[j]->Location = System::Drawing::Point(70 + (j - 6) * 80, 483  ); 
					 this->sequence_label[j]->Name = L"rightLabel"; 
					 this->sequence_label[j]->Size = System::Drawing::Size(20, 21); 
					 this->sequence_label[j]->Text = L"->"; 
					 this->sequence_label[j]->Visible = false;
					 this->panel_right->Controls->Add(this->sequence_label[j]); 
				 }
				 for(int j=0;j<zhangLaSeqNum;j++) 
				 { 
					 this->sequence_TextBox[j] = (gcnew System::Windows::Forms::TextBox()); 
					 this->sequence_TextBox[j]->Font = (gcnew System::Drawing::Font(L"宋体", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
						 static_cast<System::Byte>(134)));
					 this->sequence_TextBox[j]->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
						 static_cast<System::Int32>(static_cast<System::Byte>(192)));
					 if( j < 6 )
						 this->sequence_TextBox[j]->Location = System::Drawing::Point(10 + j * 80, 450  ); 
					 else
						 this->sequence_TextBox[j]->Location = System::Drawing::Point(10 + (j - 6) * 80, 480  ); 
					 this->sequence_TextBox[j]->Name = L"rightLabel"; 
					 this->sequence_TextBox[j]->Size = System::Drawing::Size(60, 21); 
					 this->sequence_TextBox[j]->Text = L""; 
					 this->sequence_TextBox[j]->Visible = false;
					 this->sequence_TextBox[j]->Enabled = false;
					 this->panel_right->Controls->Add(this->sequence_TextBox[j]); 
				 }
				 read_parameter( );

			 }
		//m_safeNote.ShowDialog();
		project_text_changeState(0);
		machine3_4_hide();
		

		but_curSel = 1;
		rightAera_Show() ;
		this->but_kongxinban->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)), 
			static_cast<System::Int32>(static_cast<System::Byte>(128)));
		this->prePressButton = this->but_kongxinban;
		//project_text_disable();
		 }
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			 operationStep().ShowDialog();
		 }
private: System::Void project_text_changeState( int setValue){
	if( setValue == 0){
		this->text_xiangMu->Enabled = false;
		this->text_shiGong->Enabled = false;
		this->text_jianLi->Enabled = false;
		this->text_tuJian->Enabled = false;
		this->text_gongChen->Enabled = false;
		this->text_liangChang->Enabled = false;
		this->text_sheJiYingli->Enabled = false;
		this->text_sheJiQiangDu->Enabled = false;
		this->text_sheJiZhangLaQiangDu->Enabled = false;
		this->text_ding1Num->Enabled = false;
		this->text_ding1HuiGuifx->Enabled = false;
		this->text_ding1HuiGuib->Enabled = false;
		this->text_machine1ip->Enabled = false;
		this->text_machine1CheckDate->Enabled = false;
		this->text_ding2Num->Enabled = false;
		this->text_ding2HuiGuifx->Enabled = false;
		this->text_ding2HuiGuib->Enabled = false;
		this->text_machine2ip->Enabled = false;
		this->text_machine2CheckDate->Enabled = false;
		this->text_ding3Num->Enabled = false;
		this->text_ding3HuiGuifx->Enabled = false;
		this->text_ding3HuiGuib->Enabled = false;
		this->text_machine3ip->Enabled = false;
		this->text_machine3CheckDate->Enabled = false;
		this->text_ding4Num->Enabled = false;
		this->text_ding4HuiGuifx->Enabled = false;
		this->text_ding4HuiGuib->Enabled = false;
		this->text_machine4ip->Enabled = false;
		this->text_machine4CheckDate->Enabled = false;
		this->comboBox_DunWei->Enabled = false; 
		this->textBox_lenSub->Enabled = false;
		
		this->text_xiangMu->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),static_cast<System::Int32>(static_cast<System::Byte>(224)));
		this->text_shiGong->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
		this->text_jianLi->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
		this->text_tuJian->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
		this->text_gongChen->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
		this->text_liangChang->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
		this->text_sheJiYingli->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
		this->text_sheJiQiangDu->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
		this->text_sheJiZhangLaQiangDu->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
		this->text_ding1Num->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
		this->text_ding1HuiGuifx->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
		this->text_ding1HuiGuib->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
		this->text_machine1ip->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
		this->text_machine1CheckDate->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
		this->text_ding2Num->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
		this->text_ding2HuiGuifx->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
		this->text_ding2HuiGuib->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
		this->text_machine2ip->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
		this->text_machine2CheckDate->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
		this->text_ding3Num->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
		this->text_ding3HuiGuifx->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
		this->text_ding3HuiGuib->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
		this->text_machine3ip->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
		this->text_machine3CheckDate->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
		this->text_ding4Num->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
		this->text_ding4HuiGuifx->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
		this->text_ding4HuiGuib->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
		this->text_machine4ip->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
		this->text_machine4CheckDate->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));

		this->comboBox_DunWei->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
	}
	else {
		this->text_xiangMu->Enabled = true;
		this->text_shiGong->Enabled = true;
		this->text_jianLi->Enabled = true;
		this->text_tuJian->Enabled = true;
		this->text_gongChen->Enabled = true;
		this->text_liangChang->Enabled = true;
		this->text_sheJiYingli->Enabled = true;
		this->text_sheJiQiangDu->Enabled = true;
		this->text_sheJiZhangLaQiangDu->Enabled = true;
		this->text_ding1Num->Enabled = true;
		this->text_ding1HuiGuifx->Enabled = true;
		this->text_ding1HuiGuib->Enabled = true;
		this->text_machine1ip->Enabled = true;
		this->text_machine1CheckDate->Enabled = true;
		this->text_ding2Num->Enabled = true;
		this->text_ding2HuiGuifx->Enabled = true;
		this->text_ding2HuiGuib->Enabled = true;
		this->text_machine2ip->Enabled = true;
		this->text_machine2CheckDate->Enabled = true;
		this->text_ding3Num->Enabled = true;
		this->text_ding3HuiGuifx->Enabled = true;
		this->text_ding3HuiGuib->Enabled = true;
		this->text_machine3ip->Enabled = true;
		this->text_machine3CheckDate->Enabled = true;
		this->text_ding4Num->Enabled = true;
		this->text_ding4HuiGuifx->Enabled = true;
		this->text_ding4HuiGuib->Enabled = true;
		this->text_machine4ip->Enabled = true;
		this->text_machine4CheckDate->Enabled = true;
		this->comboBox_DunWei->Enabled = true;
		this->textBox_lenSub->Enabled = true;
		this->text_xiangMu->BackColor = System::Drawing::SystemColors::Window;
		this->text_shiGong->BackColor = System::Drawing::SystemColors::Window;
		this->text_jianLi->BackColor = System::Drawing::SystemColors::Window;
		this->text_tuJian->BackColor = System::Drawing::SystemColors::Window;
		this->text_gongChen->BackColor = System::Drawing::SystemColors::Window;
		this->text_liangChang->BackColor = System::Drawing::SystemColors::Window;
		this->text_sheJiYingli->BackColor = System::Drawing::SystemColors::Window;
		this->text_sheJiQiangDu->BackColor = System::Drawing::SystemColors::Window;
		this->text_sheJiZhangLaQiangDu->BackColor = System::Drawing::SystemColors::Window;
		this->text_ding1Num->BackColor = System::Drawing::SystemColors::Window;
		this->text_ding1HuiGuifx->BackColor = System::Drawing::SystemColors::Window;
		this->text_ding1HuiGuib->BackColor = System::Drawing::SystemColors::Window;
		this->text_machine1ip->BackColor = System::Drawing::SystemColors::Window;
		this->text_machine1CheckDate->BackColor = System::Drawing::SystemColors::Window;
		this->text_ding2Num->BackColor = System::Drawing::SystemColors::Window;
		this->text_ding2HuiGuifx->BackColor = System::Drawing::SystemColors::Window;
		this->text_ding2HuiGuib->BackColor = System::Drawing::SystemColors::Window;
		this->text_machine2ip->BackColor = System::Drawing::SystemColors::Window;
		this->text_machine2CheckDate->BackColor = System::Drawing::SystemColors::Window;
		this->text_ding3Num->BackColor = System::Drawing::SystemColors::Window;
		this->text_ding3HuiGuifx->BackColor = System::Drawing::SystemColors::Window;
		this->text_ding3HuiGuib->BackColor = System::Drawing::SystemColors::Window;
		this->text_machine3ip->BackColor = System::Drawing::SystemColors::Window;
		this->text_machine3CheckDate->BackColor = System::Drawing::SystemColors::Window;

		this->text_ding4Num->BackColor = System::Drawing::SystemColors::Window;
		this->text_ding4HuiGuifx->BackColor = System::Drawing::SystemColors::Window;
		this->text_ding4HuiGuib->BackColor = System::Drawing::SystemColors::Window;
		this->text_machine4ip->BackColor = System::Drawing::SystemColors::Window;
		this->text_machine4CheckDate->BackColor = System::Drawing::SystemColors::Window;
		this->comboBox_DunWei->BackColor = System::Drawing::SystemColors::Window;
	}
}
private: System::Void but_modifyProject_Click(System::Object^  sender, System::EventArgs^  e) {
			 project_text_changeState(1);
			 this->text_xiangMu->Focus();
			 but_modifyProject->Enabled = false;
			 but_SaveProject->Enabled = true;
		 }

private: System::Void read_parameter( ) {

		XmlTextReader^ reader = nullptr;
		 try
		 {
		 		 FileStream^ fs = gcnew FileStream( System::AppDomain::CurrentDomain->BaseDirectory->ToString() + "\\JC_PARAMETER", FileMode::Open, FileAccess::Read, FileShare::Read);
		 reader = gcnew XmlTextReader( fs  );
		 StringBuilder^ builder = gcnew StringBuilder();
		  reader->WhitespaceHandling = WhitespaceHandling::None;
			reader->MoveToContent();
			//reader->ReadElementString( "project");
			 this->text_xiangMu->Text =  reader->ReadElementString();
			 this->text_shiGong->Text =  reader->ReadElementString( "shiGong");
			 this->text_jianLi->Text = reader->ReadElementString( "jianLi");
			 this->text_tuJian->Text =  reader->ReadElementString( "tuJian");
			 this->text_gongChen->Text = reader->ReadElementString( "gongChen");
			 this->text_liangChang->Text =  reader->ReadElementString( "liangChang");
			 this->text_sheJiYingli->Text = reader->ReadElementString( "sheJiYingli");
			 this->text_sheJiQiangDu->Text =  reader->ReadElementString( "sheJiQiangDu");
			 this->text_sheJiZhangLaQiangDu->Text = reader->ReadElementString( "tanxingmoliang");

                 
			 this->text_ding1Num->Text = reader->ReadElementString( "ding1Num"  );                      
			 this->text_ding1HuiGuifx->Text  = reader->ReadElementString( "ding1HuiGuifx" );            
			 this->text_ding1HuiGuib->Text = reader->ReadElementString( "ding1HuiGuib"  );              
			 this->text_machine1ip->Text = reader->ReadElementString( "machine1ip" );                  
			 this->text_machine1CheckDate->Text = reader->ReadElementString( "machine1CheckDate"  );    
			 this->text_ding2Num->Text  = reader->ReadElementString( "ding2Num" );                      
			 this->text_ding2HuiGuifx->Text  = reader->ReadElementString( "ding2HuiGuifx" );            
			 this->text_ding2HuiGuib->Text = reader->ReadElementString( "ding2HuiGuib"  );              
			 this->text_machine2ip->Text  = reader->ReadElementString( "machine2ip" );                  
			 this->text_machine2CheckDate->Text = reader->ReadElementString( "machine2CheckDate"  );  

			 this->text_ding3Num->Text  = reader->ReadElementString( "ding3Num" );                      
			 this->text_ding3HuiGuifx->Text  = reader->ReadElementString( "ding3HuiGuifx" );            
			 this->text_ding3HuiGuib->Text = reader->ReadElementString( "ding3HuiGuib"  );              
			 this->text_machine3ip->Text  = reader->ReadElementString( "machine3ip" );                  
			 this->text_machine3CheckDate->Text = reader->ReadElementString( "machine3CheckDate"  );

			 this->text_ding4Num->Text  = reader->ReadElementString( "ding4Num" );                      
			 this->text_ding4HuiGuifx->Text  = reader->ReadElementString( "ding4HuiGuifx" );            
			 this->text_ding4HuiGuib->Text = reader->ReadElementString( "ding4HuiGuib"  );              
			 this->text_machine4ip->Text  = reader->ReadElementString( "machine4ip" );                  
			 this->text_machine4CheckDate->Text = reader->ReadElementString( "machine4CheckDate"  );

			 this->comboBox_DunWei->Text = reader->ReadElementString( "DunWei"  );
			 this->countExe = System::Convert::ToInt32( reader->ReadElementString(  "machineS" ) );
			 	
			this->textBox_lenSub->Text = reader->ReadElementString( "lenSub"  );
			otherHoleNum = System::Convert::ToInt32( reader->ReadElementString(  "otherHoleNum" ) );
			otherExtendNum = System::Convert::ToInt32( reader->ReadElementString(  "otherExtendNum" ) );
			otherKn = System::Convert::ToSingle( reader->ReadElementString(  "otherKn" ) );

			 m_goujian.textBox2->Text = reader->ReadElementString( "defaultKn");
			 //this->right_TextBox[0]->Text= reader->ReadElementString("zhanglaqiangdu");
			 //this->right_TextBox[1]->Text= reader->ReadElementString("tanxingmoliang");
			 m_goujian.defaultKnStr = m_goujian.textBox2->Text;

			 m_goujian.textBox4->Text = reader->ReadElementString( "defaultExtendStr");
			 m_goujian.defaultExtendStr = m_goujian.textBox4->Text;

		
			 reader->Close();
			 reader = nullptr;
		 }
		 catch(XmlException^ er3)
		 {
			// MessageBox::Show(er3->Message);
			 if ( reader != nullptr )
				 reader->Close();
		 }
		 
}

private: System::Boolean write_parameter( ) {
	Boolean  returnValue = false;
	XmlTextWriter^ writer = nullptr;
	 XmlException^ er = gcnew XmlException();
	 try{
		 String^ filename =  System::AppDomain::CurrentDomain->BaseDirectory->ToString() + "\\JC_PARAMETER";
		 UnicodeEncoding^ uniCode_encode = gcnew UnicodeEncoding;
		 writer = gcnew XmlTextWriter( filename, uniCode_encode  );
		 writer->Formatting = Formatting::Indented;
		// writer->WriteComment( "parameter XML" );
		 writer->WriteStartElement( "project" );
		 writer->WriteElementString( "xiangMu", this->text_xiangMu->Text->Trim()	 ); // this->text_xiangMu
		 writer->WriteElementString( "shiGong", 	this->text_shiGong->Text->Trim() ); 					 
		 writer->WriteElementString( "jianLi", this->text_jianLi->Text->Trim() );						   
		 writer->WriteElementString( "tuJian", this->text_tuJian->Text->Trim() );						   
		 writer->WriteElementString( "gongChen", this->text_gongChen->Text->Trim() );					   
		 writer->WriteElementString( "liangChang", this->text_liangChang->Text->Trim() );				   
		 writer->WriteElementString( "sheJiYingli", this->text_sheJiYingli->Text->Trim() ); 			   
		 writer->WriteElementString( "sheJiQiangDu", this->text_sheJiQiangDu->Text->Trim() );			   
		 writer->WriteElementString( "tanxingmoliang", this->text_sheJiZhangLaQiangDu->Text->Trim() );
		 writer->WriteElementString( "ding1Num", this->text_ding1Num->Text->Trim() );					   
		 writer->WriteElementString( "ding1HuiGuifx", this->text_ding1HuiGuifx->Text->Trim() ); 		   
		 writer->WriteElementString( "ding1HuiGuib", this->text_ding1HuiGuib->Text->Trim() );			   
		 writer->WriteElementString( "machine1ip", this->text_machine1ip->Text->Trim() );				   
		 writer->WriteElementString( "machine1CheckDate", this->text_machine1CheckDate->Text->Trim() );    
		 writer->WriteElementString( "ding2Num", this->text_ding2Num->Text->Trim() );					   
		 writer->WriteElementString( "ding2HuiGuifx", this->text_ding2HuiGuifx->Text->Trim() ); 		   
		 writer->WriteElementString( "ding2HuiGuib", this->text_ding2HuiGuib->Text->Trim() );			   
		 writer->WriteElementString( "machine2ip", this->text_machine2ip->Text->Trim() );				   
		 writer->WriteElementString( "machine2CheckDate", this->text_machine2CheckDate->Text->Trim() );  

		 writer->WriteElementString( "ding3Num", this->text_ding3Num->Text->Trim() );					   
		 writer->WriteElementString( "ding3HuiGuifx", this->text_ding3HuiGuifx->Text->Trim() ); 		   
		 writer->WriteElementString( "ding3HuiGuib", this->text_ding3HuiGuib->Text->Trim() );			   
		 writer->WriteElementString( "machine3ip", this->text_machine3ip->Text->Trim() );				   
		 writer->WriteElementString( "machine3CheckDate", this->text_machine3CheckDate->Text->Trim() ); 

		 writer->WriteElementString( "ding4Num", this->text_ding4Num->Text->Trim() );					   
		 writer->WriteElementString( "ding4HuiGuifx", this->text_ding4HuiGuifx->Text->Trim() ); 		   
		 writer->WriteElementString( "ding4HuiGuib", this->text_ding4HuiGuib->Text->Trim() );			   
		 writer->WriteElementString( "machine4ip", this->text_machine4ip->Text->Trim() );				   
		 writer->WriteElementString( "machine4CheckDate", this->text_machine4CheckDate->Text->Trim() );
		 
		 writer->WriteElementString( "DunWei", this->comboBox_DunWei->Text->Trim() );
		  writer->WriteElementString( "machineS", System::Convert::ToString( this->countExe)  );

		writer->WriteElementString( "lenSub", this->textBox_lenSub->Text->Trim() );
		   
		writer->WriteElementString("otherHoleNum",  System::Convert::ToString( otherHoleNum ) );
		writer->WriteElementString("otherExtendNum",  System::Convert::ToString(  otherExtendNum ) );
		writer->WriteElementString( "otherKn",  System::Convert::ToString(  otherKn ) );
		//writer->WriteElementString("zhanglaqiangdu", this->right_TextBox[0]->Text->Trim());
		//writer->WriteElementString("tanxingmoliang", this->right_TextBox[1]->Text->Trim());
		writer->WriteElementString( "defaultKn",  m_goujian.defaultKnStr );
		
		writer->WriteElementString( "defaultExtendStr",  m_goujian.defaultExtendStr );

	
		 //Write the close tag for the root element.
		 writer->WriteEndElement();
			 //Write the XML to file and close the writer.
		 writer->Flush();
		 writer->Close();
		 writer = nullptr;
		 returnValue = true;
	  }
	 catch(XmlException^ er3)
	 {
		 MessageBox::Show(er3->Message);
		 if ( writer != nullptr )
			 writer->Close();
	 }
	 return returnValue ;

}

private: System::Void but_SaveProject_Click(System::Object^  sender, System::EventArgs^  e) {
		
			 if(this->text_xiangMu->TextLength < 1 ) {                                                                              
				 MessageBox::Show("请填写项目名称 ", "项目名称", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);        
				 return;                                                                                                        
			 }                                                                                                                
			 if(this->text_shiGong->TextLength < 1 ) {                                                                       
				 MessageBox::Show("请填写施工单位 ", "施工单位", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);        
				 return;                                                                                                        
			 }                                                                                                                
			 if(this->text_jianLi->TextLength < 1 ) {                                                                        
				 MessageBox::Show("请填写监理单位 ", "监理单位", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);        
				 return;                                                                                                        
			 }                                                                                                                
			 if(this->text_tuJian->TextLength < 1 ) {                                                                        
				 MessageBox::Show("请填写土建合同号 ", "土建合同号", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);    
				 return;                                                                                                        
			 }                                                                                                                
			 if(this->text_xiangMu->TextLength < 1 ) {                                                                       
				 MessageBox::Show("请填写工程名称 ", "工程名称", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);        
				 return;                                                                                                        
			 }                                                                                                                
			 if(this->text_liangChang->TextLength < 1 ) {                                                                    
				 MessageBox::Show("请填写预制梁场 ", "预制梁场", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);        
				 return;                                                                                                        
			 }                                                                                                                
			 if(this->text_sheJiYingli->TextLength < 1 ) {                                                                   
				 MessageBox::Show("请填写设计张拉应力 ", "设计张拉应力", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
				 return;                                                                                                        
			 }                                                                                                                
			 if(this->text_sheJiQiangDu->TextLength < 1 ) {                                                                  
				 MessageBox::Show("请填写设计强度 ", "设计强度", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);        
				 return;                                                                                                        
			 }                                                                                                                
			 if(this->text_sheJiZhangLaQiangDu->TextLength < 1 ) {                                                           
				 MessageBox::Show("请填写设计张拉强度 ", "设计张拉强度", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
				 return;                                                                                                        
			 }	                                                                                                              

			 if(this->text_ding1Num->TextLength < 1 ) {                                                                      
				 MessageBox::Show("请填写千斤顶1 编号", "编号", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);         
				 return;                                                                                                        
			 }                                                                                                                
			 if(this->text_ding1HuiGuib->TextLength < 1 ||  this->text_ding1HuiGuifx->TextLength < 1) {                     
				 MessageBox::Show("请填写张拉仪1 回归方程 ", "回归方程", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
				 return;                                                                                                        
			 }                                                                                                                
			 if(this->text_machine1ip->TextLength < 1 ) {                                                                    
				 MessageBox::Show("请填写张拉仪1 IP地址 ", "IP地址", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);    
				 return;                                                                                                        
			 }                                                                                                                
			 if(this->text_machine1CheckDate->TextLength < 1 ) {                                                             
				 MessageBox::Show("请填写张拉仪1检验日期 ", "检验日期", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk); 
				 return;                                                                                                        
			 }                                                                                                                
			 if(this->text_ding2Num->TextLength < 1 ) {                                                                      
				 MessageBox::Show("请填写千斤顶2 编号", "编号", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);         
				 return;                                                                                                        
			 }                                                                                                                
			 if(this->text_ding2HuiGuib->TextLength < 1 ||  this->text_ding2HuiGuifx->TextLength < 1) {                     
				 MessageBox::Show("请填写张拉仪2 回归方程 ", "回归方程", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
				 return;                                                                                                        
			 }                                                                                                                
			 if(this->text_machine2ip->TextLength < 1 ) {                                                                    
				 MessageBox::Show("请填写张拉仪2 IP地址 ", "IP地址", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);    
				 return;                                                                                                        
			 }                                                                                                                
			 if(this->text_machine2CheckDate->TextLength < 1 ) {                                                             
				 MessageBox::Show("请填写张拉仪2检验日期 ", "检验日期", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk); 
				 return;                                                                                                        
			 }
			 if(this->text_ding3Num->TextLength < 1 ) {                                                                      
				 MessageBox::Show("请填写千斤顶3 编号", "编号", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);         
				 return;                                                                                                        
			 }                                                                                                                
			 if(this->text_ding3HuiGuib->TextLength < 1 ||  this->text_ding3HuiGuifx->TextLength < 1) {                     
				 MessageBox::Show("请填写张拉仪3 回归方程 ", "回归方程", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
				 return;                                                                                                        
			 }                                                                                                                
			 if(this->text_machine3ip->TextLength < 1 ) {                                                                    
				 MessageBox::Show("请填写张拉仪3 IP地址 ", "IP地址", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);    
				 return;                                                                                                        
			 }                                                                                                                
			 if(this->text_machine3CheckDate->TextLength < 1 ) {                                                             
				 MessageBox::Show("请填写张拉仪3检验日期 ", "检验日期", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk); 
				 return;                                                                                                        
			 }
			 if(this->text_ding4Num->TextLength < 1 ) {                                                                      
				 MessageBox::Show("请填写千斤顶4 编号", "编号", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);         
				 return;                                                                                                        
			 }                                                                                                                
			 if(this->text_ding4HuiGuib->TextLength < 1 ||  this->text_ding4HuiGuifx->TextLength < 1) {                     
				 MessageBox::Show("请填写张拉仪4 回归方程 ", "回归方程", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
				 return;                                                                                                        
			 }                                                                                                                
			 if(this->text_machine4ip->TextLength < 1 ) {                                                                    
				 MessageBox::Show("请填写张拉仪4 IP地址 ", "IP地址", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);    
				 return;                                                                                                        
			 }                                                                                                                
			 if(this->text_machine4CheckDate->TextLength < 1 ) {                                                             
				 MessageBox::Show("请填写张拉仪4检验日期 ", "检验日期", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk); 
				 return;                                                                                                        
			 }
			  if(this->comboBox_DunWei->Text->Length < 1 ) {                                                             
				 MessageBox::Show("请填写吨位信息 ", "吨位信息", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk); 
				 return;                                                                                                        
			 }
			   if(this->textBox_lenSub->Text->Length < 1 ) {                                                             
				 MessageBox::Show("请填写回缩量信息 ", "回缩量信息", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk); 
				 return;                                                                                                        
			 }	
			 if( write_parameter() ) {
				 but_modifyProject->Enabled = true ;
				 but_SaveProject->Enabled = false;
				 project_text_changeState( 0 );
			 }
		 }
private: System::Void  onlynumber(System::Object^ sender,  System::Windows::Forms::KeyPressEventArgs^ e)
		 {
			 System::Windows::Forms::TextBox^ txt = (System::Windows::Forms::TextBox^ )sender;
			 if (( e->KeyChar < 48 ||  e->KeyChar > 57) &&  e->KeyChar != 8 &&  e->KeyChar != 46 &&  e->KeyChar != 45){
				 e->Handled = true;
				 MessageBox::Show("请输入合法数据：此处必须是数字","输入错误", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
			 }
			 if ( e->KeyChar == 46)                         
			 {
				 if (txt->ToString()->Length <= 0)
					 e->Handled = true;
			 }
		 }
private: System::Void text_sheJiYingli_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			onlynumber(sender,e);
		 }
private: System::Void text_sheJiQiangDu_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
		 onlynumber(sender,e);
		 }
private: System::Void text_sheJiZhangLaQiangDu_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
		  onlynumber(sender,e);}
private: System::Void text_ding1HuiGuifx_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 onlynumber(sender,e);}
private: System::Void text_ding1HuiGuib_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 onlynumber(sender,e);}
private: System::Void text_machine1CheckDate_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 onlynumber(sender,e);}
private: System::Void text_machine1ip_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 onlynumber(sender,e);}

private: System::Void text_ding2HuiGuifx_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			onlynumber(sender,e);}
private: System::Void text_ding2HuiGuib_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			onlynumber(sender,e);}
private: System::Void text_machine2CheckDate_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			onlynumber(sender,e);}
private: System::Void text_machine2ip_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			onlynumber(sender,e);}

private: System::Void text_ding3HuiGuifx_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 onlynumber(sender,e);}
private: System::Void text_ding3HuiGuib_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 onlynumber(sender,e);}
private: System::Void text_machine3CheckDate_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 onlynumber(sender,e);}
private: System::Void text_machine3ip_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 onlynumber(sender,e);}

private: System::Void textBox_lenSub_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 onlynumber(sender,e);}			 

private: System::Void text_ding4HuiGuifx_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 onlynumber(sender,e);}
private: System::Void text_ding4HuiGuib_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 onlynumber(sender,e);}
private: System::Void text_machine4CheckDate_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 onlynumber(sender,e);}
private: System::Void text_machine4ip_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 onlynumber(sender,e);}

private: System::Void machine3_4_hide(){

			this->panel1->Location = System::Drawing::Point(17, 24);
			this->panel2->Location = System::Drawing::Point(17, 140);

			this->panel_1->Location = System::Drawing::Point(17, 260);
			this->panel_2->Location = System::Drawing::Point(17,380);
			this->panel_1->Size = System::Drawing::Size( 480, 105);
			this->panel_2->Size = System::Drawing::Size( 480, 105);

			this->panel1->Size = System::Drawing::Size( 480, 105);
			this->panel2->Size = System::Drawing::Size( 480, 105);
			

			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel_1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel_2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;

			/*this->label_dunwei->Location = System::Drawing::Point(11, 505);
			this->comboBox_DunWei->Location = System::Drawing::Point( 106, 505);
			this->but_modifyProject->Location = System::Drawing::Point( 314, 500);
			this->but_SaveProject->Location = System::Drawing::Point( 409, 500);

			this->label21->Location = System::Drawing::Point( 183, 505);
			this->textBox_lenSub->Location = System::Drawing::Point( 237, 502);
			this->label22->Location = System::Drawing::Point( 280, 505);*/
			
			this->panel_1->Visible = true;
			this->panel_2->Visible = true;
			this->panel_3->Visible = false;
			this->panel_4->Visible = false;
		}
private: System::Void machine3_4_show(){

			/*this->label_dunwei->Location = System::Drawing::Point(11, 516);
			this->comboBox_DunWei->Location = System::Drawing::Point( 106, 516);
			this->but_modifyProject->Location = System::Drawing::Point( 314, 512);
			this->but_SaveProject->Location = System::Drawing::Point( 409, 512);

			this->label21->Location = System::Drawing::Point( 183, 516);
			this->textBox_lenSub->Location = System::Drawing::Point( 237, 513);
			this->label22->Location = System::Drawing::Point( 280, 516);
			*/
			 this->panel1->Location = System::Drawing::Point(17, 14);
			 this->panel2->Location = System::Drawing::Point(17, 117);

			 this->panel1->Size = System::Drawing::Size( 480, 98);
			 this->panel2->Size = System::Drawing::Size( 480, 98);

			 this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			 this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			 this->panel_1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			 this->panel_2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			 this->panel_3->BorderStyle = System::Windows::Forms::BorderStyle::None;
			 this->panel_4->BorderStyle = System::Windows::Forms::BorderStyle::None;

			 this->panel_1->Size = System::Drawing::Size( 480, 65);
			 this->panel_2->Size = System::Drawing::Size( 480, 65);
			 this->panel_3->Size = System::Drawing::Size( 480, 65);
			 this->panel_4->Size = System::Drawing::Size( 480, 65);
			 this->panel_1->Location = System::Drawing::Point(17, 224);
			 this->panel_2->Location = System::Drawing::Point(17, 294);
			 this->panel_3->Location = System::Drawing::Point(17, 364);
			 this->panel_4->Location = System::Drawing::Point(17, 434);

			 this->panel_1->Visible = true;
			 this->panel_2->Visible = true;
			 this->panel_3->Visible = true;
			 this->panel_4->Visible = true;
		 }
void comboBoxValueSet( ){
	if(but_curSel == 1) {
				this->right_ComboBox[1]->Items->Clear();
				this->right_ComboBox[1]->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"2孔3次", L"4孔4次"});
				this->right_ComboBox[1]->SelectedIndex = 0;
			}
			else if(but_curSel == 2){
				this->right_ComboBox[1]->Items->Clear();
				this->right_ComboBox[1]->Items->AddRange(gcnew cli::array< System::Object^  >(14) {L"3孔4次", L"T梁4孔4次", L"4孔5次", L"4孔6次", L"4孔8次",
					L"5孔6次", L"5孔7次", L"5孔8次", L"5孔10次", L"5孔11次", 
					L"5孔13次", L"6孔8次", L"6孔6次对称张拉", L"6孔12次对称张拉"});
				this->right_ComboBox[1]->SelectedIndex = 0;
			}
			else if(but_curSel == 3){
				this->right_ComboBox[1]->Items->Clear();
			this->right_ComboBox[1]->Items->AddRange(gcnew cli::array< System::Object^  >(9) {L"6孔6次", L"7孔7次", L"8孔8次"
				, L"6孔3次两端张拉", L"8孔4次两端张拉", L"9孔9次一", L"9孔9次二", L"10孔5次两端张拉", L"12孔6次两端张拉"});
			this->right_ComboBox[1]->SelectedIndex = 0;
		}
			else if(but_curSel == 4){
				this->right_ComboBox[1]->Items->Clear();
			this->right_ComboBox[1]->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"单根单端张拉", L"单根两端张拉"});
			this->right_ComboBox[1]->SelectedIndex = 0;
	}
			else if(but_curSel == 5){
				this->right_ComboBox[1]->Items->Clear();
				this->right_ComboBox[1]->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"单束两端张拉", L"两束横桥向对称张拉"});
				this->right_ComboBox[1]->SelectedIndex = 0;
			}
			else if(but_curSel == 6){
				this->right_ComboBox[1]->Items->Clear();
			this->right_ComboBox[1]->Items->AddRange(gcnew cli::array< System::Object^  >(1) {L"单根单端张拉"});
			this->right_ComboBox[1]->SelectedIndex = 0;
		}
			else if(but_curSel == 7){
				this->right_ComboBox[1]->Items->Clear();
				this->right_ComboBox[1]->Items->AddRange(gcnew cli::array< System::Object^  >(1) {L"分二次张拉"});
			this->right_ComboBox[1]->SelectedIndex = 0;
	}
			else if(but_curSel == 8){
				this->right_ComboBox[1]->Items->Clear();
				this->right_ComboBox[1]->Items->AddRange(gcnew cli::array< System::Object^  >(1) {L"单根两端张拉"});
				this->right_ComboBox[1]->SelectedIndex = 0;
			}
			else if(but_curSel == 9)
				this->right_ComboBox[1]->Items->Clear();
}
private:		  Boolean readLiangHao(String^ sqlString)
	{
		//	static int num = 0;
		Boolean retVal = false;
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
			this->right_ComboBox[0]->Items->Clear();
			while (reader->Read())
			{
				this->right_ComboBox[0]->Items->AddRange(gcnew cli::array< System::Object^  >(1) {reader->GetString(0)});
			}
			
			// Always call Close when done reading.
			reader->Close();
			retVal = true;
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message,"读数据库失败", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
		}
		connection->Close(); 
		//this->right_ComboBox[0]->SelectedIndex = 0;
		return retVal;
	}
private:		  Boolean readLiangInfo(String^ sqlString)  //读取梁号的其它信息
				  {
					  //	static int num = 0;
					  Boolean retVal = false;
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
						  if (reader->Read() == true)
						  {
							  
							  int NumberOfColums = reader->GetValues(meta);
							  if (meta[30]->ToString()->Length==4)
								  m_controlMachine.More_check=meta[30]->ToString();
							  else
								  m_controlMachine.More_check="100%";
							  this->right_ComboBox[1]->Text = meta[1]->ToString(); //reader->GetString(1);
							  this->right_ComboBox[3]->Text =  meta[4]->ToString();
							  this->right_ComboBox[4]->Text =  meta[5]->ToString();
							  for ( int i = 0; i < 12; i++) {
							  	if(meta[32 + i]->ToString()->Length > 0 ) {
								  	this->sequence_TextBox[i]->Text = meta[32 + i]->ToString(); 
								  	this->sequence_TextBox[i]->Visible = true;
					 				this->sequence_label[i]->Visible = true;
							  		}
								else
									{
									this->sequence_TextBox[i]->Text = "";
									this->sequence_TextBox[i]->Visible = false;
					 				this->sequence_label[i]->Visible = false;
									if( i > 0 )
										this->sequence_label[i - 1]->Visible = false;
									}
							  }
								this->right_ComboBox[2]->Items->Clear();
							  for(int i = 0; i < 6; i++) {
							  	if(meta[6 + i]->ToString()->Length > 0 ) //lhg
									this->right_ComboBox[2]->Items->AddRange(gcnew cli::array< System::Object^  >(1) { meta[6 + i*4]->ToString() });
								  this->str_holeInfo[i * 3] = meta[7 + i * 4]->ToString();
								  this->str_holeInfo[i * 3 + 1] = meta[8 + i * 4]->ToString();
								  this->str_holeInfo[i * 3 + 2] = meta[9 + i * 4]->ToString();
							  }
							  this->right_ComboBox[2]->SelectedIndex = 0;

						  }

						  // Always call Close when done reading.
						  reader->Close();
						  retVal = true;
					  }
					  catch (Exception^ ex)
					  {
						  MessageBox::Show(ex->Message,"读数据库失败", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
					  }
					  //objDB->ChangeDatabase("INSERT INTO table1('张拉梁号','张拉工艺') VALUES ('6号梁','sechs')");
					  connection->Close(); 
					  return retVal;
				  }	
void rightAera_Show() 
        { 
        	static int bInitMouseDownEvent = 0;
        	int j = 0;
			int comboIndex = 0;
			int textIndex = 0;
			int row,column;
			row = 0; column = 0;
			int leftStart = 10, heightStart = 30;
			if( but_curSel != 9 ) {  //not  other 
				this->btn_delete_data->Visible = true;
				for( j=0;j< 64;j++) {
					this->right_label[j]->Visible = false;
					this->right_TextBox[j]->Visible = false;
					this->right_label[j]->Font = (gcnew System::Drawing::Font(L"宋体", 9.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
						static_cast<System::Byte>(134)));
					this->right_TextBox[j]->Font = (gcnew System::Drawing::Font(L"宋体", 9.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
						static_cast<System::Byte>(134)));
					if( bInitMouseDownEvent == 0 )
						this->right_TextBox[j]->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &intel_main::text_machine4CheckDate_MouseDown);
				}
				
				bInitMouseDownEvent = 1 ;
				j=0;
	            this->right_label[j]->Location = System::Drawing::Point(leftStart + this->panel_right->Size.Width/10 * column, heightStart + this->panel_right->Size.Height/13*row) ; 
	            this->right_label[j]->Size = System::Drawing::Size(110, 25); 
	            this->right_label[j]->Text = L"张 拉 梁 号"; 
	            this->right_label[j]->Visible = true;

				column = 3;
				readLiangHao(L"select lianghao from table" + System::Convert::ToString(but_curSel));
				this->right_ComboBox[comboIndex]->Location = System::Drawing::Point(leftStart + this->panel_right->Size.Width/10 * column, heightStart + this->panel_right->Size.Height/13*row - 8) ; 
	            this->right_ComboBox[comboIndex]->Size = System::Drawing::Size(210, 25); 
	            this->right_ComboBox[comboIndex]->Text = L""; 
	            this->right_ComboBox[comboIndex]->Visible = true;
				this->right_ComboBox[comboIndex]->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
				comboIndex ++;
				
				
				j++; row = 1; column = 0;
				this->right_label[j]->Location = System::Drawing::Point(leftStart + this->panel_right->Size.Width/10*column,heightStart + this->panel_right->Size.Height/13*row) ; 
				this->right_label[j]->Size = System::Drawing::Size(110, 25); 
				this->right_label[j]->Text = L"张 拉 工 艺"; 
				this->right_label[j]->Visible = true;
				column = 3;
				this->right_ComboBox[comboIndex]->Location = System::Drawing::Point(leftStart + this->panel_right->Size.Width/10 * column, heightStart + this->panel_right->Size.Height/13*row - 8) ; 
	            this->right_ComboBox[comboIndex]->Size = System::Drawing::Size(210, 25); 
				comboBoxValueSet(  );
	            this->right_ComboBox[comboIndex]->Visible = true;
				this->right_ComboBox[comboIndex]->Enabled = false;
				comboIndex ++;
				
				j++; row = 2; column = 0;
				this->right_label[j]->Location = System::Drawing::Point(leftStart + this->panel_right->Size.Width/10*column-2,heightStart + this->panel_right->Size.Height/13*row) ; 
				this->right_label[j]->Size = System::Drawing::Size(130, 25); 
				this->right_label[j]->Text = L"砼试块强度"; 
				this->right_label[j]->Visible = true;
				column = 3;
				this->right_TextBox[textIndex]->Location = System::Drawing::Point(leftStart + this->panel_right->Size.Width/10 * column -10, heightStart + this->panel_right->Size.Height/13*row - 8) ; 
	            this->right_TextBox[textIndex]->Size = System::Drawing::Size(50, 25); 
	            this->right_TextBox[textIndex]->Text = L""; 
	            this->right_TextBox[textIndex]->Visible = true;
		
				textIndex ++;
				
				j++; row = 2; column = 4;
				this->right_label[j]->Location = System::Drawing::Point(leftStart + this->panel_right->Size.Width/10*column -5,heightStart + this->panel_right->Size.Height/13*row) ; 
				this->right_label[j]->Size = System::Drawing::Size(35, 25); 
				this->right_label[j]->Text = L"MPa"; 
				this->right_label[j]->Visible = true;
				j++; row = 2; column = 5;
				/*this->right_label[j]->Location = System::Drawing::Point(leftStart + this->panel_right->Size.Width/10*column - 20,heightStart + this->panel_right->Size.Height/13*row) ; 
				this->right_label[j]->Size = System::Drawing::Size(156, 25); 
				this->right_label[j]->Text = L"实测钢绞线弹性模量"; 
				this->right_label[j]->Visible = true;*/
				column = 7;
				/*this->right_TextBox[textIndex]->Location = System::Drawing::Point(leftStart + this->panel_right->Size.Width/10 * column + 45, heightStart + this->panel_right->Size.Height/13*row - 8) ; 
	            this->right_TextBox[textIndex]->Size = System::Drawing::Size(50, 25); 
	            this->right_TextBox[textIndex]->Text = L""; 
	            this->right_TextBox[textIndex]->Visible = true;*/
				
				textIndex ++;
				j++; row = 2; column = 8;
				/*this->right_label[j]->Location = System::Drawing::Point(leftStart + this->panel_right->Size.Width/10*column + 48,heightStart + this->panel_right->Size.Height/13*row) ; 
				this->right_label[j]->Size = System::Drawing::Size(45, 25); 
				this->right_label[j]->Text = L"MPa"; 
				this->right_label[j]->Visible = true;*/

				j++; row = 3; column = 0;
				this->right_label[j]->Location = System::Drawing::Point(leftStart + this->panel_right->Size.Width/13*column,heightStart + this->panel_right->Size.Height/13*row) ; 
				this->right_label[j]->Size = System::Drawing::Size(52, 25); 
				this->right_label[j]->Text = L"孔号:"; 
				this->right_label[j]->Visible = true;
				column = 2;
				this->right_ComboBox[comboIndex]->Location = System::Drawing::Point(leftStart + this->panel_right->Size.Width/13 * column , heightStart + this->panel_right->Size.Height/13*row - 5) ; 
	            this->right_ComboBox[comboIndex]->Size = System::Drawing::Size(110, 25); 
	            this->right_ComboBox[comboIndex]->Text = L"N1左"; 
	            this->right_ComboBox[comboIndex]->Visible = true;
				
				comboIndex ++;
				j++; row = 4; column = 0;
				this->right_label[j]->Location = System::Drawing::Point(leftStart + this->panel_right->Size.Width/13*column ,heightStart + this->panel_right->Size.Height/13*row) ; 
				this->right_label[j]->Size = System::Drawing::Size(50, 25); 
				this->right_label[j]->Text = L"钢绞线"; 
				this->right_label[j]->Visible = true;
				column = 2;
				this->right_TextBox[textIndex]->Location = System::Drawing::Point(leftStart + this->panel_right->Size.Width/13 * column - 20 , heightStart + this->panel_right->Size.Height/13*row - 5) ; 
	            this->right_TextBox[textIndex]->Size = System::Drawing::Size(30, 25); 
	            this->right_TextBox[textIndex]->Text = L" "; 
				this->right_TextBox[textIndex]->Enabled = false;
	            this->right_TextBox[textIndex]->Visible = true;
				textIndex ++;
				j++;  column = 3;
				this->right_label[j]->Location = System::Drawing::Point(leftStart + this->panel_right->Size.Width/13*column-22,heightStart + this->panel_right->Size.Height/13*row) ; 
				this->right_label[j]->Size = System::Drawing::Size(30, 25); 

				this->right_label[j]->Text = L"根"; 
				this->right_label[j]->Visible = true;
				j++;  column = 4;
				this->right_label[j]->Location = System::Drawing::Point(leftStart + this->panel_right->Size.Width/13*column -28,heightStart + this->panel_right->Size.Height/13*row) ; 
				this->right_label[j]->Size = System::Drawing::Size(78, 25); 

				this->right_label[j]->Text = L"张拉控制力"; 
				this->right_label[j]->Visible = true;
				column = 6;
				this->right_TextBox[textIndex]->Location = System::Drawing::Point(leftStart + this->panel_right->Size.Width/13 * column-20 , heightStart + this->panel_right->Size.Height/13*row - 5) ; 
	            this->right_TextBox[textIndex]->Size = System::Drawing::Size(50, 25); 
	            this->right_TextBox[textIndex]->Text = L" "; 
				this->right_TextBox[textIndex]->Enabled = false;
	            this->right_TextBox[textIndex]->Visible = true;
				textIndex ++;
				j++;  column = 7;
				this->right_label[j]->Location = System::Drawing::Point(leftStart + this->panel_right->Size.Width/13*column,heightStart + this->panel_right->Size.Height/13*row) ; 
				this->right_label[j]->Size = System::Drawing::Size(30, 25); 

				this->right_label[j]->Text = L"KN"; 
				this->right_label[j]->Visible = true;
				j++;  column = 8;
				this->right_label[j]->Location = System::Drawing::Point(leftStart + this->panel_right->Size.Width/13*column - 5,heightStart + this->panel_right->Size.Height/13*row) ; 
				this->right_label[j]->Size = System::Drawing::Size(85, 25); 

				this->right_label[j]->Text = L"理论伸长量"; 
				this->right_label[j]->Visible = true;
				column = 10;
				this->right_TextBox[textIndex]->Location = System::Drawing::Point(leftStart + this->panel_right->Size.Width/13 * column + 10, heightStart + this->panel_right->Size.Height/13*row - 5) ; 
	            this->right_TextBox[textIndex]->Size = System::Drawing::Size(65, 25); 
	            this->right_TextBox[textIndex]->Text = L""; 
	            this->right_TextBox[textIndex]->Visible = true;
				this->right_TextBox[textIndex]->Enabled = false;
				textIndex ++;
				j++;  column = 11;
				this->right_label[j]->Location = System::Drawing::Point(leftStart + this->panel_right->Size.Width/13*column + 40,heightStart + this->panel_right->Size.Height/13*row) ; 
				this->right_label[j]->Size = System::Drawing::Size(30, 25); 

				this->right_label[j]->Text = L"mm"; 
				this->right_label[j]->Visible = true;

				j++; row = 5; column = 0;
				this->right_label[j]->Location = System::Drawing::Point(leftStart + this->panel_right->Size.Width/13*column,heightStart + this->panel_right->Size.Height/13*row) ; 
				this->right_label[j]->Size = System::Drawing::Size(105, 25); 
				this->right_label[j]->Text = L"张拉加载速度"; 
				this->right_label[j]->Visible = true;
				column = 3;
				this->right_ComboBox[comboIndex]->Location = System::Drawing::Point(leftStart + this->panel_right->Size.Width/13 * column + 4, heightStart + this->panel_right->Size.Height/13*row - 5) ; 
	            this->right_ComboBox[comboIndex]->Size = System::Drawing::Size(60, 25); 
				this->right_ComboBox[comboIndex]->Items->Clear();
				this->right_ComboBox[comboIndex]->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"25%", L"20%", L"15%", L"10%"});
				this->right_ComboBox[comboIndex]->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
	            this->right_ComboBox[comboIndex]->Text = L"20%"; 
				this->right_ComboBox[comboIndex]->Enabled = false;
	            this->right_ComboBox[comboIndex]->Visible = true;
				comboIndex ++;
				j++;  column = 5;
				this->right_label[j]->Location = System::Drawing::Point(leftStart + this->panel_right->Size.Width/13*column-5,heightStart + this->panel_right->Size.Height/13*row) ; 
				this->right_label[j]->Size = System::Drawing::Size(70, 25); 

				this->right_label[j]->Text = L"ócon/min"; 
				this->right_label[j]->Visible = true;
				j++;  column = 7;
				this->right_label[j]->Location = System::Drawing::Point(leftStart + this->panel_right->Size.Width/13*column +3,heightStart + this->panel_right->Size.Height/13*row) ; 
				this->right_label[j]->Size = System::Drawing::Size(90, 25); 
				this->right_label[j]->Text = L"初应力选择"; 
				this->right_label[j]->Visible = true;
				column = 9;
				this->right_ComboBox[comboIndex]->Location = System::Drawing::Point(leftStart + this->panel_right->Size.Width/13 * column+30, heightStart + this->panel_right->Size.Height/13*row - 5) ; 
	            this->right_ComboBox[comboIndex]->Size = System::Drawing::Size(60, 25); 
				this->right_ComboBox[comboIndex]->Items->Clear();
				this->right_ComboBox[comboIndex]->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"10%", L"15%", L"20%", L"25%"});
				this->right_ComboBox[comboIndex]->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
	            this->right_ComboBox[comboIndex]->Text = L"10%"; 
				this->right_ComboBox[comboIndex]->Enabled = false;
	            this->right_ComboBox[comboIndex]->Visible = true;
				comboIndex ++;
				j++;  column = 11;
				this->right_label[j]->Location = System::Drawing::Point(leftStart + this->panel_right->Size.Width/13*column + 25,heightStart + this->panel_right->Size.Height/13*row) ; 
				this->right_label[j]->Size = System::Drawing::Size(70, 25); 

				this->right_label[j]->Text = L"ócon"; 
				this->right_label[j]->Visible = true;

				 row = 6; column = 0;
				 try{
				 this->pictureBox1->Image = Image::FromFile( System::AppDomain::CurrentDomain->BaseDirectory->ToString() + L"\\Resources\\" +this->right_ComboBox[1]->Text + L".jpg");
				 }
				 catch( Exception ^ ex){
					 this->pictureBox1->Image = nullptr;
				 };
				this->pictureBox1->Location = System::Drawing::Point(leftStart + this->panel_right->Size.Width/13*column,heightStart + this->panel_right->Size.Height/13*row + 10) ; 
				this->pictureBox1->Visible = true;
				//m_controlMachine.curLiangType=but_curSel;
			}else {  //other 
				this->btn_delete_data->Visible = false;
				this->pictureBox1->Visible = false;
				for( j=0;j< 64;j++) {
					this->right_label[j]->Visible = false;
					this->right_TextBox[j]->Visible = false;
				}
				for( j=0;j< 7;j++) {
					this->right_ComboBox[j]->Visible = false;
					this->sequence_label[j]->Visible = false;
					this->sequence_TextBox[j]->Visible = false;
				}
				 j=0;
				this->right_label[j]->Location = System::Drawing::Point(leftStart + this->panel_right->Size.Width/10 * column, heightStart + this->panel_right->Size.Height/13*row - 5) ; 
	            this->right_label[j]->Size = System::Drawing::Size(110, 25); 
	            this->right_label[j]->Text = L"张 拉 孔 数"; 
	            this->right_label[j]->Visible = true;

				column = 3;
				this->right_ComboBox[comboIndex]->Items->Clear();
				this->right_ComboBox[comboIndex]->Items->AddRange(gcnew cli::array< System::Object^  >(5) {L"1", L"2",L"3", L"4",L"5"});
				
				this->right_ComboBox[comboIndex]->Location = System::Drawing::Point(leftStart + this->panel_right->Size.Width/10 * column, heightStart + this->panel_right->Size.Height/13*row - 8) ; 
	            this->right_ComboBox[comboIndex]->Size = System::Drawing::Size(60, 25); 
	            this->right_ComboBox[comboIndex]->Text = L""; 
	            this->right_ComboBox[comboIndex]->Visible = true;
				this->right_ComboBox[comboIndex]->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
				this->right_ComboBox[comboIndex]->Enabled = true;
				comboIndex ++;
				
				
				j++; column = 5;
				this->right_label[j]->Location = System::Drawing::Point(leftStart + this->panel_right->Size.Width/10*column,heightStart + this->panel_right->Size.Height/13*row - 5) ; 
				this->right_label[j]->Size = System::Drawing::Size(100, 25); 
				this->right_label[j]->Text = L"张 拉 次 数"; 
				this->right_label[j]->Visible = true;
				column = 8;
				this->right_ComboBox[comboIndex]->Items->Clear();
				this->right_ComboBox[comboIndex]->Items->AddRange(gcnew cli::array< System::Object^  >(6) {L"1", L"2",L"3", L"4",L"5",L"6"});
				
				this->right_ComboBox[comboIndex]->Location = System::Drawing::Point(leftStart + this->panel_right->Size.Width/10 * column, heightStart + this->panel_right->Size.Height/13*row - 8) ; 
	            this->right_ComboBox[comboIndex]->Size = System::Drawing::Size(60, 25); 
	            this->right_ComboBox[comboIndex]->Text = L""; 
	            this->right_ComboBox[comboIndex]->Visible = true;
				this->right_ComboBox[comboIndex]->Enabled = true;
				this->right_ComboBox[comboIndex]->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
				comboIndex ++;
				
				j++; row ++; column = 0;
				this->right_label[j]->Location = System::Drawing::Point(leftStart + this->panel_right->Size.Width/10*column-2,heightStart + this->panel_right->Size.Height/13*row) ; 
				this->right_label[j]->Size = System::Drawing::Size(140, 25); 
				this->right_label[j]->Text = L"单根钢绞线控制力"; 
				this->right_label[j]->Visible = true;
				column = 3;
				this->right_TextBox[textIndex]->Location = System::Drawing::Point(leftStart + this->panel_right->Size.Width/10 * column , heightStart + this->panel_right->Size.Height/13*row - 8) ; 
	            this->right_TextBox[textIndex]->Size = System::Drawing::Size(60, 25); 
	            this->right_TextBox[textIndex]->Text = System::Convert::ToString(  otherKn ); 
	            this->right_TextBox[textIndex]->Visible = true;

				textIndex ++;
				j++; column = 4;
				this->right_label[j]->Location = System::Drawing::Point(leftStart + this->panel_right->Size.Width/10*column + 15,heightStart + this->panel_right->Size.Height/13*row) ; 
				this->right_label[j]->Size = System::Drawing::Size(30, 25); 
				this->right_label[j]->Text = L"KN"; 
				this->right_label[j]->Visible = true;
				
				for( int kongNum = 0; kongNum < 5; kongNum ++ ){
					j++; row ++; column = 0;
					this->right_label[j]->Location = System::Drawing::Point(leftStart + this->panel_right->Size.Width/13*column,heightStart + this->panel_right->Size.Height/13*row) ; 
					this->right_label[j]->Size = System::Drawing::Size(44, 25); 
					this->right_label[j]->Text = L"孔号"+ System::Convert::ToString(kongNum+1); 
					this->right_label[j]->Visible = true;
					column = 1;
					this->right_TextBox[textIndex]->Location = System::Drawing::Point(leftStart + this->panel_right->Size.Width/13 * column + 9 , heightStart + this->panel_right->Size.Height/13*row - 5) ; 
		            this->right_TextBox[textIndex]->Size = System::Drawing::Size(45, 25); 
		            this->right_TextBox[textIndex]->Text = L""; 
					this->right_TextBox[textIndex]->Enabled = true;
		            this->right_TextBox[textIndex]->Visible = true;
					textIndex ++;
					
					j++; column = 2;
					this->right_label[j]->Location = System::Drawing::Point(leftStart + this->panel_right->Size.Width/13*column + 19,heightStart + this->panel_right->Size.Height/13*row) ; 
					this->right_label[j]->Size = System::Drawing::Size(50, 25); 

					this->right_label[j]->Text = L"钢绞线"; 
					this->right_label[j]->Visible = true;
					column = 4;
					this->right_TextBox[textIndex]->Location = System::Drawing::Point(leftStart + this->panel_right->Size.Width/13 * column  , heightStart + this->panel_right->Size.Height/13*row - 5) ; 
		            this->right_TextBox[textIndex]->Size = System::Drawing::Size(30, 25); 
		            this->right_TextBox[textIndex]->Text = L""; 
					this->right_TextBox[textIndex]->Enabled = true;
		            this->right_TextBox[textIndex]->Visible = true;
					if( kongNum==0 )
						this->right_TextBox[textIndex]->TextChanged += gcnew System::EventHandler(this, &intel_main::right_TextBox0_TextChanged);
					else if( kongNum==1 )
						this->right_TextBox[textIndex]->TextChanged += gcnew System::EventHandler(this, &intel_main::right_TextBox1_TextChanged);
					else if( kongNum==2 )
						this->right_TextBox[textIndex]->TextChanged += gcnew System::EventHandler(this, &intel_main::right_TextBox2_TextChanged);
					else if( kongNum==3 )
						this->right_TextBox[textIndex]->TextChanged += gcnew System::EventHandler(this, &intel_main::right_TextBox3_TextChanged);
					else if( kongNum==4 )
						this->right_TextBox[textIndex]->TextChanged += gcnew System::EventHandler(this, &intel_main::right_TextBox4_TextChanged);
					
					
					textIndex ++;
					j++;  column = 5;
					this->right_label[j]->Location = System::Drawing::Point(leftStart + this->panel_right->Size.Width/13*column,heightStart + this->panel_right->Size.Height/13*row) ; 
					this->right_label[j]->Size = System::Drawing::Size(15, 25); 

					this->right_label[j]->Text = L"根"; 
					this->right_label[j]->Visible = true;
					j++;  column = 6;
					this->right_label[j]->Location = System::Drawing::Point(leftStart + this->panel_right->Size.Width/13*column -20,heightStart + this->panel_right->Size.Height/13*row) ; 
					this->right_label[j]->Size = System::Drawing::Size(50, 25); 

					this->right_label[j]->Text = L"控制力"; 
					this->right_label[j]->Visible = true;
					column = 7;
					this->right_TextBox[textIndex]->Location = System::Drawing::Point(leftStart + this->panel_right->Size.Width/13 * column -5, heightStart + this->panel_right->Size.Height/13*row - 5) ; 
		            this->right_TextBox[textIndex]->Size = System::Drawing::Size(60, 25); 
		            this->right_TextBox[textIndex]->Text = L""; 
					this->right_TextBox[textIndex]->Enabled = true;
		            this->right_TextBox[textIndex]->Visible = true;
					textIndex ++;
					j++;  column = 8;
					this->right_label[j]->Location = System::Drawing::Point(leftStart + this->panel_right->Size.Width/13*column + 20,heightStart + this->panel_right->Size.Height/13*row) ; 
					this->right_label[j]->Size = System::Drawing::Size(25, 25); 

					this->right_label[j]->Text = L"KN"; 
					this->right_label[j]->Visible = true;
					j++;  column = 9;
					this->right_label[j]->Location = System::Drawing::Point(leftStart + this->panel_right->Size.Width/13*column + 7,heightStart + this->panel_right->Size.Height/13*row) ; 
					this->right_label[j]->Size = System::Drawing::Size(78, 25); 
					this->right_label[j]->Text = L"理论伸长量"; 
					this->right_label[j]->Visible = true;
					column = 11;
					this->right_TextBox[textIndex]->Location = System::Drawing::Point(leftStart + this->panel_right->Size.Width/13 * column +15, heightStart + this->panel_right->Size.Height/13*row - 5) ; 
		            this->right_TextBox[textIndex]->Size = System::Drawing::Size(30, 25); 
		            this->right_TextBox[textIndex]->Text = L""; 
		            this->right_TextBox[textIndex]->Visible = true;
					this->right_TextBox[textIndex]->Enabled = true;
					textIndex ++;
					j++;  column = 12;
					this->right_label[j]->Location = System::Drawing::Point(leftStart + this->panel_right->Size.Width/13*column +11,heightStart + this->panel_right->Size.Height/13*row) ; 
					this->right_label[j]->Size = System::Drawing::Size(30, 25); 
					this->right_label[j]->Text = L"mm"; 
					this->right_label[j]->Visible = true;
				}
				j++; row = 8; column = 0;
				this->right_label[j]->Location = System::Drawing::Point(leftStart + this->panel_right->Size.Width/13*column,heightStart + this->panel_right->Size.Height/13*row) ; 
				this->right_label[j]->Size = System::Drawing::Size(105, 25); 
				this->right_label[j]->Text = L"张 拉 顺 序"; 
				this->right_label[j]->Visible = true;

				row = 9; column = 0;
				for( int kongNum = 0; kongNum < 6; kongNum ++ ){
					this->right_TextBox[textIndex]->Location = System::Drawing::Point(leftStart + this->panel_right->Size.Width/13 * column  , heightStart + this->panel_right->Size.Height/13*row - 5) ; 
		            this->right_TextBox[textIndex]->Size = System::Drawing::Size(80, 25); 
		            this->right_TextBox[textIndex]->Text = L""; 
					this->right_TextBox[textIndex]->Enabled = true;
		            this->right_TextBox[textIndex]->Visible = true;
					textIndex ++;
					column += 3;
					j++;
					this->right_label[j]->Location = System::Drawing::Point(leftStart + this->panel_right->Size.Width/13*column - 25,heightStart + this->panel_right->Size.Height/13*row) ; 
					this->right_label[j]->Size = System::Drawing::Size(23, 25); 
					this->right_label[j]->Text = L"->"; 
					this->right_label[j]->Visible = true;
					if( kongNum == 2){
						row ++;
						column = 0;
					}
				}
				this->right_label[j]->Visible = false;

				j++; row = 11; column = 0;
				this->right_label[j]->Location = System::Drawing::Point(leftStart + this->panel_right->Size.Width/13*column,heightStart + this->panel_right->Size.Height/13*row) ; 
				this->right_label[j]->Size = System::Drawing::Size(105, 25); 
				this->right_label[j]->Text = L"张拉加载速度"; 
				this->right_label[j]->Visible = true;
				column = 3;
				this->right_ComboBox[comboIndex]->Location = System::Drawing::Point(leftStart + this->panel_right->Size.Width/13 * column + 4, heightStart + this->panel_right->Size.Height/13*row - 5) ; 
	            this->right_ComboBox[comboIndex]->Size = System::Drawing::Size(60, 25); 
				this->right_ComboBox[comboIndex]->Items->Clear();
				this->right_ComboBox[comboIndex]->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"25%", L"20%", L"15%", L"10%"});
				this->right_ComboBox[comboIndex]->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
	            this->right_ComboBox[comboIndex]->Text = L"20%"; 
				this->right_ComboBox[comboIndex]->Enabled = true;
	            this->right_ComboBox[comboIndex]->Visible = true;
				comboIndex ++;
				j++;  column = 5;
				this->right_label[j]->Location = System::Drawing::Point(leftStart + this->panel_right->Size.Width/13*column-5,heightStart + this->panel_right->Size.Height/13*row) ; 
				this->right_label[j]->Size = System::Drawing::Size(70, 25); 
				this->right_label[j]->Text = L"ócon/min"; 
				this->right_label[j]->Visible = true;
				j++;  column = 7;
				this->right_label[j]->Location = System::Drawing::Point(leftStart + this->panel_right->Size.Width/13*column +3,heightStart + this->panel_right->Size.Height/13*row) ; 
				this->right_label[j]->Size = System::Drawing::Size(90, 25); 
				this->right_label[j]->Text = L"初应力选择"; 
				this->right_label[j]->Visible = true;
				column = 9;
				this->right_ComboBox[comboIndex]->Location = System::Drawing::Point(leftStart + this->panel_right->Size.Width/13 * column+30, heightStart + this->panel_right->Size.Height/13*row - 5) ; 
	            this->right_ComboBox[comboIndex]->Size = System::Drawing::Size(60, 25); 
				this->right_ComboBox[comboIndex]->Items->Clear();
				this->right_ComboBox[comboIndex]->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"10%", L"15%", L"20%", L"25%"});
				this->right_ComboBox[comboIndex]->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
	            this->right_ComboBox[comboIndex]->Text = L"10%"; 
				this->right_ComboBox[comboIndex]->Enabled = true;
	            this->right_ComboBox[comboIndex]->Visible = true;
				comboIndex ++;
				j++;  column = 11;
				this->right_label[j]->Location = System::Drawing::Point(leftStart + this->panel_right->Size.Width/13*column + 25,heightStart + this->panel_right->Size.Height/13*row) ; 
				this->right_label[j]->Size = System::Drawing::Size(70, 25); 
				this->right_label[j]->Text = L"ócon"; 
				this->right_label[j]->Visible = true;

				row = 1;
				j++;  column = 5;
				this->right_label[j]->Location = System::Drawing::Point(leftStart + this->panel_right->Size.Width/10*column,heightStart + this->panel_right->Size.Height/13*row) ; 
				this->right_label[j]->Size = System::Drawing::Size(100, 25); 
				this->right_label[j]->Text = L"张 拉 梁 号"; 
				this->right_label[j]->Visible = true;

				column = 8;
				this->right_TextBox[textIndex]->Location = System::Drawing::Point(leftStart + this->panel_right->Size.Width/10 * column , heightStart + this->panel_right->Size.Height/13*row - 8) ; 
				this->right_TextBox[textIndex]->Size = System::Drawing::Size(60, 25); 
				this->right_TextBox[textIndex]->Text = L""; 
				this->right_TextBox[textIndex]->Visible = true;

				if( otherHoleNum < 5 )
						this->right_ComboBox[0]->SelectedIndex = otherHoleNum;

				if( otherExtendNum < 6 )
					this->right_ComboBox[1]->SelectedIndex = otherExtendNum ;
				
			}
			
        } 

private: System::Void right_TextBox0_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if( but_curSel == 9 ) {
				 float num;
				 try{
					 num = System::Convert::ToSingle(this->right_TextBox[2]->Text);
					 otherKn = System::Convert::ToSingle (this->right_TextBox[0]->Text);
					 this->right_TextBox[3]->Text = System::Convert::ToString( otherKn * num);
				 }
				catch(Exception ^ ex) {
				 }
			 }
		 }
private: System::Void right_TextBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if( but_curSel == 9 ) {
				 float num,kn;
				 num = System::Convert::ToSingle(this->right_TextBox[6]->Text);
				 kn = System::Convert::ToSingle (this->right_TextBox[0]->Text);
				 this->right_TextBox[7]->Text = System::Convert::ToString( kn * num);
			 }
		 }
private: System::Void right_TextBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if( but_curSel == 9 ) {
				 float num,kn;
				 num = System::Convert::ToSingle(this->right_TextBox[10]->Text);
				 kn = System::Convert::ToSingle (this->right_TextBox[0]->Text);
				 this->right_TextBox[11]->Text = System::Convert::ToString( kn * num);
			 }
		 }
private: System::Void right_TextBox3_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if( but_curSel == 9 ) {
				 float num,kn;
				 num = System::Convert::ToSingle(this->right_TextBox[14]->Text);
				 kn = System::Convert::ToSingle (this->right_TextBox[0]->Text);
				 this->right_TextBox[15]->Text = System::Convert::ToString( kn * num);
			 }
		 }
private: System::Void right_TextBox4_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if( but_curSel == 9 ) {
				 float num,kn;
				 num = System::Convert::ToSingle(this->right_TextBox[18]->Text);
				 kn = System::Convert::ToSingle (this->right_TextBox[0]->Text);
				 this->right_TextBox[19]->Text = System::Convert::ToString( kn * num);
			 }
		 }





private: System::Void but_kongxinban_Click(System::Object^  sender, System::EventArgs^  e) {
			machine3_4_hide();
			but_curSel = 1;
			but_inputGouJian->Enabled = true;
			rightAera_Show() ;
			this->prePressButton->BackColor =  System::Drawing::SystemColors::Info;
			this->but_kongxinban->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->prePressButton = this->but_kongxinban;
		 }

private: System::Void but_jianZhiT_Click(System::Object^  sender, System::EventArgs^  e) {
			 machine3_4_hide();
			 but_curSel = 2;
			 but_inputGouJian->Enabled = true;
			 rightAera_Show() ;
			 this->prePressButton->BackColor =  System::Drawing::SystemColors::Info;
			 this->but_jianZhiT->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				 static_cast<System::Int32>(static_cast<System::Byte>(128)));
			 this->prePressButton = this->but_jianZhiT;
		 }

private: System::Void but_jianZhiXiang_Click(System::Object^  sender, System::EventArgs^  e) {
			 machine3_4_hide();
			 but_curSel = 3;
			 but_inputGouJian->Enabled = true;
			 rightAera_Show() ;
			 this->prePressButton->BackColor =  System::Drawing::SystemColors::Info;
			 this->but_jianZhiXiang->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				 static_cast<System::Int32>(static_cast<System::Byte>(128)));
			 this->prePressButton = this->but_jianZhiXiang;
		 }
private: System::Void but_fuWanJu_Click(System::Object^  sender, System::EventArgs^  e) {//one machine
			machine3_4_hide();
			this->panel_2->Visible = false;
			but_curSel = 4;
			but_inputGouJian->Enabled = true;
			rightAera_Show() ;
			this->prePressButton->BackColor =  System::Drawing::SystemColors::Info;
			this->but_fuWanJu->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->prePressButton = this->but_fuWanJu;
		 }
private: System::Void ExcelInfo(){
	m_controlMachine.str_ExcelInfo[0] = this->text_xiangMu->Text; 
	m_controlMachine.str_ExcelInfo[1] = this->text_shiGong->Text;
	m_controlMachine.str_ExcelInfo[2] = this->text_jianLi->Text; 
	m_controlMachine.str_ExcelInfo[3] = this->text_tuJian->Text;  
	m_controlMachine.str_ExcelInfo[4] = this->text_gongChen->Text; 
	
	m_controlMachine.str_ExcelInfo[5] = this->text_liangChang->Text; 
	m_controlMachine.str_ExcelInfo[6] = this->text_sheJiYingli->Text;  
	m_controlMachine.str_ExcelInfo[7] = this->text_sheJiQiangDu->Text; 
	m_controlMachine.str_ExcelInfo[8] = this->text_ding1Num->Text;  
	m_controlMachine.str_ExcelInfo[9] = this->text_machine1CheckDate->Text; 

	m_controlMachine.str_ExcelInfo[10] = this->text_ding2Num->Text; 
	m_controlMachine.str_ExcelInfo[11] = this->text_machine2CheckDate->Text;

	m_controlMachine.str_ExcelInfo[12] = this->text_ding3Num->Text; 
	m_controlMachine.str_ExcelInfo[13] = this->text_machine3CheckDate->Text;  

	m_controlMachine.str_ExcelInfo[14] = this->text_ding4Num->Text;
	m_controlMachine.str_ExcelInfo[15] = this->text_machine4CheckDate->Text; 

	m_controlMachine.str_ExcelInfo[16] = System::AppDomain::CurrentDomain->BaseDirectory->ToString() + L"\\Resources\\"+this->right_ComboBox[1]->Text + L".jpg";  //张拉顺序示意图
	m_controlMachine.str_ExcelInfo[17] = this->text_sheJiZhangLaQiangDu->Text;
	m_controlMachine.str_ExcelInfo[18] = this->right_TextBox[0]->Text;
}
private: System::Int32 initControlMachineData(){
			 int i = 0;
			 int holeNum = 0, dividIndex; 
			 int textIndex = 1;
			 
			 for(  i = 0; i < holeInfoNum; i++)
			  		m_controlMachine.str_holeInfo[i] = "";
			   for(  i = 0; i < zhangLaSeqNum; i++)
				 m_controlMachine.str_ShunXunInfo[i] = "";
			   
			if( but_curSel != 9 ) {
			  	

				 for(  i = 0; i < holeInfoNum/4; i++){
					 if( i < this->right_ComboBox[2]->Items->Count && this->right_ComboBox[2]->Items[i]->ToString()->Length > 0) {
						 dividIndex = this->right_ComboBox[2]->Items[i]->ToString()->IndexOf("-");
						 if( dividIndex >= 0){
							m_controlMachine.str_holeInfo[holeNum*4] = this->right_ComboBox[2]->Items[i]->ToString()->Substring(0,dividIndex);
							m_controlMachine.str_holeInfo[(holeNum + 1)*4] = this->right_ComboBox[2]->Items[i]->ToString()->Substring(1 + dividIndex);
						 }
						 else
							 m_controlMachine.str_holeInfo[holeNum*4] = this->right_ComboBox[2]->Items[i]->ToString();
						 
					 }
					 else
						 break;
					 m_controlMachine.str_holeInfo[holeNum*4 + 1] = this->str_holeInfo[i*3];
					 m_controlMachine.str_holeInfo[holeNum*4 + 2] = this->str_holeInfo[i*3 + 1];
					 m_controlMachine.str_holeInfo[holeNum*4 + 3] = this->str_holeInfo[i*3 + 2];
					 holeNum ++;
					 if( dividIndex >= 0){
						 m_controlMachine.str_holeInfo[holeNum*4 + 1] = this->str_holeInfo[i*3];
						 m_controlMachine.str_holeInfo[holeNum*4 + 2] = this->str_holeInfo[i*3 + 1];
						 m_controlMachine.str_holeInfo[holeNum*4 + 3] = this->str_holeInfo[i*3 + 2];
						 holeNum ++;
					 }
				 }
				 m_controlMachine.zhangLaCount = i;
				 for(  i = 0; i < zhangLaSeqNum; i++)
					 m_controlMachine.str_ShunXunInfo[i] = this->sequence_TextBox[i]->Text;
				 m_controlMachine.str_LiangInfo[0] = this->right_ComboBox[0]->Text;
				 m_controlMachine.str_LiangInfo[1] = this->right_ComboBox[3]->Text;
				 m_controlMachine.str_LiangInfo[2] = this->right_ComboBox[4]->Text;
			}
			else {
				for(  i = 0; i < (this->right_ComboBox[0]->SelectedIndex + 1)*4; i++)
					if( this->right_TextBox[i+1]->TextLength < 1 ) {
						 MessageBox::Show("请填写完整张拉孔号信息", "其它张拉", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk); 
						 return 0;                                                                                                        
					 }
				for(  i = 1 + 4*5; i <= 1 + 4*5 + this->right_ComboBox[1]->SelectedIndex; i++)
					if( this->right_TextBox[i]->TextLength < 1 ) {
						 MessageBox::Show("请填写完整张拉顺序信息", "其它张拉", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk); 
						 return 0;                                                                                                        
					 }	
				/*for(int j=0;j</*Convert::ToInt32(this->right_ComboBox[1]->SelectedIndex+1;j++)
				{
					if((("50%"+this->right_TextBox[1]->Text) != this->right_TextBox[21+j]->Text))
					{
						if((("100%"+this->right_TextBox[1]->Text) != this->right_TextBox[21+j]->Text))
						{
							MessageBox::Show("请在张拉顺序"+(j+1)+"填写正确的孔号!","其他张拉",MessageBoxButtons::OKCancel,MessageBoxIcon::Asterisk);
							return 0;
						}
					}
				}*/
				if( this->right_TextBox[27]->TextLength < 1 ) {
						 MessageBox::Show("请填写张拉梁号信息", "其它张拉", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk); 
						 return 0;                                                                                                        
					 }		
				for(  i = 0; i < this->right_ComboBox[0]->SelectedIndex + 1; i++){
					m_controlMachine.str_holeInfo[i*4]  = this->right_TextBox[textIndex++]->Text;
					m_controlMachine.str_holeInfo[i*4 + 1]  = this->right_TextBox[textIndex++]->Text;
					m_controlMachine.str_holeInfo[i*4 + 2]  = this->right_TextBox[textIndex++]->Text;
					m_controlMachine.str_holeInfo[i*4 + 3]  = this->right_TextBox[textIndex++]->Text;
				}

				 for(  i = 1 + 4*5; i <= 1 + 4*5 + this->right_ComboBox[1]->SelectedIndex; i++)
					 m_controlMachine.str_ShunXunInfo[i-21] = this->right_TextBox[i]->Text;

				 m_controlMachine.str_LiangInfo[0] =  this->right_TextBox[27]->Text; //"其它张拉";
				 m_controlMachine.str_LiangInfo[1] = this->right_ComboBox[2]->Text;
				 m_controlMachine.str_LiangInfo[2] = this->right_ComboBox[3]->Text;
			}
			
			ExcelInfo();
			try{
				m_controlMachine.LEN_SUB = System::Convert::ToSingle(this->textBox_lenSub->Text);
			 }
			 catch( Exception ^ ex){
			 	m_controlMachine.LEN_SUB = 8;
				MessageBox::Show(ex->Message,"len sub error");
			 };	
			 m_controlMachine.huiGuiXiShu[0] = System::Convert::ToSingle(this->text_ding1HuiGuifx->Text);
			 m_controlMachine.huiGuiXiShu[1] = System::Convert::ToSingle(this->text_ding1HuiGuib->Text);
			 m_controlMachine.huiGuiXiShu[2] = System::Convert::ToSingle(this->text_ding2HuiGuifx->Text);
			 m_controlMachine.huiGuiXiShu[3] = System::Convert::ToSingle(this->text_ding2HuiGuib->Text);
			 m_controlMachine.huiGuiXiShu[4] = System::Convert::ToSingle(this->text_ding3HuiGuifx->Text);
			 m_controlMachine.huiGuiXiShu[5] = System::Convert::ToSingle(this->text_ding3HuiGuib->Text);
			 m_controlMachine.huiGuiXiShu[6] = System::Convert::ToSingle(this->text_ding4HuiGuifx->Text);
			 m_controlMachine.huiGuiXiShu[7] = System::Convert::ToSingle(this->text_ding4HuiGuib->Text);
			 m_controlMachine.zhanglaSeq = this->right_ComboBox[1]->Text;

			 return 1;     
		 }
private: System::Void but_ControlMachine_Click(System::Object^  sender, System::EventArgs^  e) {
	if( this->right_ComboBox[0]->Text->Length < 1) {
		MessageBox::Show( "请选择进行张拉的梁号！","智能张拉系统", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
		return;
	}
	
	 if( m_controlMachine.ZhangLaStatus != ZHANGLA_IDLE ) {
			MessageBox::Show("正在张拉，不能更改信息!","错误", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
			if( !m_controlMachine.bShowedWindow )
				m_controlMachine.ShowDialog(this);
				m_controlMachine.ResetAll();
			return;
	 	}
	 
	try{
	 	write_parameter();
	} catch( Exception ^ ex){
		MessageBox::Show(ex->Message,"write parameter error");
	 };	
	if( initControlMachineData() > 0) {
		m_controlMachine.Main_Wnd_ButCurs=but_curSel;
		m_controlMachine.initZhangLaData ();
		//m_controlMachine.ResetAll();
	//this->Hide();
		if( !m_controlMachine.bShowedWindow )
			m_controlMachine.ShowDialog(this);
			
	//this->Show();
		}
}

private: System::Void but_lianXuZong_Click(System::Object^  sender, System::EventArgs^  e) {
			 machine3_4_show();
			 but_curSel = 5;
			 but_inputGouJian->Enabled = true;
			 rightAera_Show() ;
			 this->prePressButton->BackColor =  System::Drawing::SystemColors::Info;
			 this->but_lianXuZong->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				 static_cast<System::Int32>(static_cast<System::Byte>(128)));
			 this->prePressButton = this->but_lianXuZong;
		 }
private: System::Void but_lianXuHeng_Click(System::Object^  sender, System::EventArgs^  e) {//one machine
			machine3_4_hide();
			this->panel_2->Visible = false;
			but_curSel = 6;
			but_inputGouJian->Enabled = true;
			rightAera_Show() ;
			this->prePressButton->BackColor =  System::Drawing::SystemColors::Info;
			this->but_lianXuHeng->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->prePressButton = this->but_lianXuHeng;
		 }
private: System::Void but_shuXiangDuan_Click(System::Object^  sender, System::EventArgs^  e) {
			 machine3_4_hide();
			 but_curSel = 7;
			 but_inputGouJian->Enabled = true;
			 rightAera_Show() ;
			 this->prePressButton->BackColor =  System::Drawing::SystemColors::Info;
			 this->but_shuXiangDuan->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				 static_cast<System::Int32>(static_cast<System::Byte>(128)));
			 this->prePressButton = this->but_shuXiangDuan;
		 }

private: System::Void but_gaiLiang_Click(System::Object^  sender, System::EventArgs^  e) {
			machine3_4_hide();
			but_curSel = 8;
			but_inputGouJian->Enabled = true;
			rightAera_Show() ;
			this->prePressButton->BackColor =  System::Drawing::SystemColors::Info;
			this->but_gaiLiang->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->prePressButton = this->but_gaiLiang;
		 }

private: System::Void but_otherZhangLa_Click(System::Object^  sender, System::EventArgs^  e) {
			 machine3_4_hide();
			 but_curSel = 9;
			 but_inputGouJian->Enabled = false;
			 rightAera_Show() ;
			 this->prePressButton->BackColor =  System::Drawing::SystemColors::Info;
			 this->but_otherZhangLa->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				 static_cast<System::Int32>(static_cast<System::Byte>(128)));
			 this->prePressButton = this->but_otherZhangLa;
		 }

private: System::Void right_ComboBox0_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	 if( m_controlMachine.ZhangLaStatus != ZHANGLA_IDLE ) {
			return;
	 	}
		if( but_curSel != 9 ) {  //not  other 
			readLiangInfo(L"select * from table" + System::Convert::ToString(but_curSel) + L" where lianghao ='" + this->right_ComboBox[0]->Text + L"'");
			try{
				 this->pictureBox1->Image = Image::FromFile( System::AppDomain::CurrentDomain->BaseDirectory->ToString() + L"\\Resources\\"+this->right_ComboBox[1]->Text + L".jpg");
			 }
			 catch( Exception ^ ex){
				 this->pictureBox1->Image = nullptr;
			 };
		}
		else {
			int j, textIndex;
			j = 4 ;
			textIndex = 1 ;
			otherHoleNum = this->right_ComboBox[0]->SelectedIndex;
			
			for( int kongNum = 0 ; kongNum <= this->right_ComboBox[0]->SelectedIndex; kongNum ++ ){
					this->right_label[j++]->Visible = true;
					this->right_label[j++]->Visible = true;
					this->right_label[j++]->Visible = true;
					
					this->right_label[j++]->Visible = true;
					this->right_label[j++]->Visible = true;
					this->right_label[j++]->Visible = true;
					this->right_label[j++]->Visible = true;
					
		            this->right_TextBox[textIndex++]->Visible = true;
					this->right_TextBox[textIndex++]->Visible = true;
					this->right_TextBox[textIndex++]->Visible = true;
					this->right_TextBox[textIndex++]->Visible = true;
			}
			
			j = 4 + 7*(this->right_ComboBox[0]->SelectedIndex + 1);
			textIndex = 1 + 4*(this->right_ComboBox[0]->SelectedIndex + 1);
			for( int kongNum = this->right_ComboBox[0]->SelectedIndex + 1; kongNum < 5; kongNum ++ ){
					this->right_label[j++]->Visible = false;
					this->right_label[j++]->Visible = false;
					this->right_label[j++]->Visible = false;
					
					this->right_label[j++]->Visible = false;
					this->right_label[j++]->Visible = false;
					this->right_label[j++]->Visible = false;
					this->right_label[j++]->Visible = false;
					
		            this->right_TextBox[textIndex++]->Visible = false;
					this->right_TextBox[textIndex++]->Visible = false;
					this->right_TextBox[textIndex++]->Visible = false;
					this->right_TextBox[textIndex++]->Visible = false;
			}
		}
}

private: System::Void right_ComboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		if( but_curSel == 9 ) {
			int j, textIndex;
			j = 5 + 7*5  ;
			textIndex = 1 + 4*5;
			otherExtendNum = this->right_ComboBox[1]->SelectedIndex;
			
			for( int kongNum = 0 ; kongNum <= this->right_ComboBox[1]->SelectedIndex; kongNum ++ ){
					this->right_label[j++]->Visible = true;
					this->right_TextBox[textIndex++]->Visible = true;
			}
			
			j --;
			this->right_label[j++]->Visible = false;

			for( int kongNum = this->right_ComboBox[1]->SelectedIndex + 1; kongNum < 6; kongNum ++ ){
					this->right_label[j++]->Visible = false;
					this->right_TextBox[textIndex++]->Visible = false;
					
			}
		}
}


private: System::Void right_ComboBox2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	if( but_curSel != 9 ) {
		 this->right_TextBox[2]->Text = this->str_holeInfo[ this->right_ComboBox[2]->SelectedIndex * 3];
		 this->right_TextBox[3]->Text = this->str_holeInfo[ this->right_ComboBox[2]->SelectedIndex * 3 + 1];
		 this->right_TextBox[4]->Text = this->str_holeInfo[ this->right_ComboBox[2]->SelectedIndex * 3 + 2];
	}
}



private: System::Void intel_main_Load(System::Object^  sender, System::EventArgs^  e) {


		 }
private: System::Void but_SoftwareUpdate_Click(System::Object^  sender, System::EventArgs^  e) {
			MessageBox::Show("暂无升级版本","软件升级", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
		 }
private: System::Void but_exit_Click(System::Object^  sender, System::EventArgs^  e) {
			 if( m_controlMachine.ZhangLaStatus != ZHANGLA_IDLE ) {
				 static System::Windows::Forms::DialogResult  r1;
			 r1	=  MessageBox::Show("张拉未完成，停止张拉并退出吗?","退出张拉", MessageBoxButtons::YesNoCancel, MessageBoxIcon::Asterisk , MessageBoxDefaultButton::Button3);
			 if( r1 == System::Windows::Forms::DialogResult::Yes){
				  this->Close();
			 }

			 }
			 else
				  this->Close();
			
		 }
 private: System::Void but_inputGouJian_Click(System::Object^  sender, System::EventArgs^  e) {
			m_goujian.setCaptionText(but_curSel);
			//m_goujian.textBox2->Text=m_goujian.Line_num;
			//m_goujian.textBox3->Text=m_goujian.Line_kn;
			m_goujian.comboBox1->Text="";
			  m_goujian.ShowDialog();
			  rightAera_Show() ;
			  write_parameter( );
			  
 		}


private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
			// initControlMachineData();
			#ifdef debugVersion
				 if( this->countExe >= 400 )
					 this->Close();
				 DateTime GetDateTimeInfo = DateTime::Now;
				 if( (GetDateTimeInfo.Year * MULTI1 + GetDateTimeInfo.Month * MULTI2 > 738429) )
					 this->Close();
			#endif
			 
			 this->timer1->Enabled = false;
		 }
private: System::Void text_machine4CheckDate_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		m_goujian.showKeyBoard();
		}
private: System::Void intel_main_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		m_controlMachine.p_comBase->exitPro = 1;
		m_controlMachine.p_comBase->gOpcOperation = 0;
		ReleaseSemaphore( m_controlMachine.p_comBase->semaphore,1,NULL);	
		 }
private: System::Void comboBox0_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) {
		 if( m_controlMachine.ZhangLaStatus != ZHANGLA_IDLE ) {
			MessageBox::Show("正在张拉，不能更改梁信息","错误", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
			return;
	 	}
		 }


private: System::Void intel_main_MinimumSizeChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void textBox_lenSub_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		m_goujian.showKeyBoard(); }
private: System::Void btn_delete_data_Click(System::Object^  sender, System::EventArgs^  e) {
			 static System::Windows::Forms::DialogResult result;
			result=MessageBox::Show("删除该条目会同时删除已保存数据,是否继续?","湖南聚创",MessageBoxButtons::YesNo);
			if(result==System::Windows::Forms::DialogResult::Yes)
			{
				System::String^ del=L"delete from table"+but_curSel+L" where lianghao='"+this->right_ComboBox[0]->Text+L"';";
				this->right_ComboBox[0]->Items->Remove(right_ComboBox[0]->SelectedItem);
				String^ dataCon = L"Provider=Microsoft.Jet.OLEDB.4.0;Data Source=" + System::AppDomain::CurrentDomain->BaseDirectory->ToString() + L"\\jcData.mdb;Jet OLEDB:Database Password=jc123;Persist Security Info=False;";
				OleDbConnection^ connection=gcnew OleDbConnection(dataCon);
				OleDbCommand^ command=gcnew OleDbCommand(del,connection);
				command->Connection->Open();
				command->ExecuteNonQuery();
			}
		 }
};
}

