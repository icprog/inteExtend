#pragma once

#include "public.h"
//#include "ZhangLaParameterView.h"

#using <mscorlib.dll>
namespace Inte_extend {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace System::Data::OleDb;
	using namespace System::Configuration;
	using namespace System::IO;

	
	/// <summary>
	/// goujian 摘要
	/// </summary>
	public ref class goujian : public System::Windows::Forms::Form
	{
	public:
		goujian(void)
		{
			bInit = 0;
			liangHaoChanged = 0;
			preHoleNum = 0;
			preLiangType = -1;
			zhanglaNum = 0;
			InitializeComponent();
			//
			//TODO: 在此处添加构造函数代码
			//
		}


	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~goujian()
		{
			if (components)
			{
				delete components;
			}
			//delete m_ZhangLaParameterView;
			//More_check=0;
		}
	private: System::Windows::Forms::Panel^  panel1;
	protected: 
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	public: System::Windows::Forms::TextBox^  textBox4;
	public : System::String ^ defaultExtendStr;
	public: System::String^ Line_num;
	public: System::String^	Line_kn;
	public: System::Windows::Forms::TextBox^  textBox3;
	public: System::Windows::Forms::TextBox^  textBox2;
	public: System::Windows::Forms::ComboBox^  comboBox6;
	private: System::Windows::Forms::Label^  label16;
	public: System::Windows::Forms::CheckBox^  checkBox1;
	public : System::String ^ defaultKnStr;
	public: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::ComboBox^  comboBox5;
	private: System::Windows::Forms::ComboBox^  comboBox4;
	private: System::Windows::Forms::ComboBox^  comboBox3;
	private: System::Windows::Forms::ComboBox^  comboBox2;
	public: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label7;
	private: System::Int32 curLiangType,NumChanged,liangHaoChanged,preHoleNum , preLiangType,zhanglaNum; //zhanglaNum:张拉次数
	private: System::Int32 bInit;
	//public: System::Boolean More_check;
	//private: ZhangLaParameterView m_Param;
static array<System::String^>^ str_holeInfo = gcnew array<System::String^>(holeInfoNum); 
static array<System::Windows::Forms::Label^>^ sequence_label = gcnew array<System::Windows::Forms::Label^>(zhangLaSeqNum); 
static array<System::Windows::Forms::TextBox^>^ sequence_TextBox = gcnew array<System::Windows::Forms::TextBox^>(zhangLaSeqNum); 
private: System::Windows::Forms::Button^  button_sav;

private: System::Windows::Forms::Button^  button_mod;
	private: System::Windows::Forms::Panel^  panel2;


	private:
		/// <summary>
		/// 必需的设计器变量。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要
		/// 使用代码编辑器修改此方法的内容。
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(goujian::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button_sav = (gcnew System::Windows::Forms::Button());
			this->button_mod = (gcnew System::Windows::Forms::Button());
			this->comboBox6 = (gcnew System::Windows::Forms::ComboBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox5 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox4 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Controls->Add(this->button_sav);
			this->panel1->Controls->Add(this->button_mod);
			this->panel1->Controls->Add(this->comboBox6);
			this->panel1->Controls->Add(this->label16);
			this->panel1->Controls->Add(this->checkBox1);
			this->panel1->Controls->Add(this->textBox1);
			this->panel1->Controls->Add(this->comboBox5);
			this->panel1->Controls->Add(this->comboBox4);
			this->panel1->Controls->Add(this->comboBox2);
			this->panel1->Controls->Add(this->comboBox1);
			this->panel1->Controls->Add(this->label9);
			this->panel1->Controls->Add(this->label8);
			this->panel1->Controls->Add(this->label7);
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Location = System::Drawing::Point(31, 32);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(679, 533);
			this->panel1->TabIndex = 0;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->textBox4);
			this->panel2->Controls->Add(this->textBox3);
			this->panel2->Controls->Add(this->textBox2);
			this->panel2->Controls->Add(this->comboBox3);
			this->panel2->Controls->Add(this->label14);
			this->panel2->Controls->Add(this->label15);
			this->panel2->Controls->Add(this->label12);
			this->panel2->Controls->Add(this->label13);
			this->panel2->Controls->Add(this->label11);
			this->panel2->Controls->Add(this->label10);
			this->panel2->Controls->Add(this->label5);
			this->panel2->Location = System::Drawing::Point(16, 120);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(631, 81);
			this->panel2->TabIndex = 29;
			// 
			// textBox4
			// 
			this->textBox4->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->textBox4->Location = System::Drawing::Point(474, 45);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(81, 26);
			this->textBox4->TabIndex = 26;
			this->textBox4->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &goujian::textBox4_KeyPress);
			this->textBox4->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &goujian::textBox4_MouseDown);
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->textBox3->Location = System::Drawing::Point(276, 45);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(55, 26);
			this->textBox3->TabIndex = 25;
			this->textBox3->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &goujian::textBox3_KeyPress);
			this->textBox3->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &goujian::textBox4_MouseDown);
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->textBox2->Location = System::Drawing::Point(103, 44);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(40, 26);
			this->textBox2->TabIndex = 24;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &goujian::textBox2_TextChanged);
			this->textBox2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &goujian::textBox2_KeyPress);
			this->textBox2->Leave += gcnew System::EventHandler(this, &goujian::textBox2_Leave);
			this->textBox2->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &goujian::textBox4_MouseDown);
			// 
			// comboBox3
			// 
			this->comboBox3->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox3->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Location = System::Drawing::Point(73, 7);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(124, 24);
			this->comboBox3->TabIndex = 17;
			this->comboBox3->SelectedIndexChanged += gcnew System::EventHandler(this, &goujian::comboBox3_SelectedIndexChanged);
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label14->Location = System::Drawing::Point(559, 48);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(26, 16);
			this->label14->TabIndex = 14;
			this->label14->Text = L"mm";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label15->Location = System::Drawing::Point(378, 48);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(93, 16);
			this->label15->TabIndex = 13;
			this->label15->Text = L"理论伸长量";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label12->Location = System::Drawing::Point(335, 49);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(26, 16);
			this->label12->TabIndex = 12;
			this->label12->Text = L"KN";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label13->Location = System::Drawing::Point(186, 47);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(93, 16);
			this->label13->TabIndex = 11;
			this->label13->Text = L"张拉控制力";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label11->Location = System::Drawing::Point(144, 48);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(25, 16);
			this->label11->TabIndex = 10;
			this->label11->Text = L"根";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label10->Location = System::Drawing::Point(9, 46);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(93, 16);
			this->label10->TabIndex = 9;
			this->label10->Text = L"钢绞线数量";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label5->Location = System::Drawing::Point(13, 10);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(69, 19);
			this->label5->TabIndex = 3;
			this->label5->Text = L"孔号：";
			// 
			// button_sav
			// 
			this->button_sav->Font = (gcnew System::Drawing::Font(L"宋体", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->button_sav->Location = System::Drawing::Point(514, 375);
			this->button_sav->Name = L"button_sav";
			this->button_sav->Size = System::Drawing::Size(104, 31);
			this->button_sav->TabIndex = 28;
			this->button_sav->Text = L"保 存";
			this->button_sav->UseVisualStyleBackColor = true;
			this->button_sav->Click += gcnew System::EventHandler(this, &goujian::button_sav_Click);
			// 
			// button_mod
			// 
			this->button_mod->Font = (gcnew System::Drawing::Font(L"宋体", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->button_mod->Location = System::Drawing::Point(514, 307);
			this->button_mod->Name = L"button_mod";
			this->button_mod->Size = System::Drawing::Size(104, 31);
			this->button_mod->TabIndex = 27;
			this->button_mod->Text = L"修 改";
			this->button_mod->UseVisualStyleBackColor = true;
			this->button_mod->Click += gcnew System::EventHandler(this, &goujian::button_mod_Click);
			// 
			// comboBox6
			// 
			this->comboBox6->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox6->Enabled = false;
			this->comboBox6->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->comboBox6->FormattingEnabled = true;
			this->comboBox6->Items->AddRange(gcnew cli::array< System::Object^  >(5) {L"101%", L"102%", L"103%", L"104%", L"105%"});
			this->comboBox6->Location = System::Drawing::Point(543, 97);
			this->comboBox6->Name = L"comboBox6";
			this->comboBox6->Size = System::Drawing::Size(76, 24);
			this->comboBox6->TabIndex = 23;
			this->comboBox6->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &goujian::textBox4_MouseDown);
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label16->Location = System::Drawing::Point(407, 98);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(26, 16);
			this->label16->TabIndex = 22;
			this->label16->Text = L"KN";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->checkBox1->Location = System::Drawing::Point(454, 99);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(91, 20);
			this->checkBox1->TabIndex = 21;
			this->checkBox1->Text = L"超拉系数";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &goujian::checkBox1_CheckedChanged);
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->textBox1->Location = System::Drawing::Point(277, 95);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(123, 26);
			this->textBox1->TabIndex = 20;
			this->textBox1->Text = L"195.3";
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &goujian::textBox1_TextChanged);
			this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &goujian::textBox1_KeyPress);
			this->textBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &goujian::textBox4_MouseDown);
			// 
			// comboBox5
			// 
			this->comboBox5->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox5->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->comboBox5->FormattingEnabled = true;
			this->comboBox5->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"10%", L"15%", L"20%", L"25%"});
			this->comboBox5->Location = System::Drawing::Point(477, 204);
			this->comboBox5->Name = L"comboBox5";
			this->comboBox5->Size = System::Drawing::Size(64, 24);
			this->comboBox5->TabIndex = 19;
			// 
			// comboBox4
			// 
			this->comboBox4->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox4->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->comboBox4->FormattingEnabled = true;
			this->comboBox4->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"25%", L"20%", L"15%", L"10%"});
			this->comboBox4->Location = System::Drawing::Point(172, 206);
			this->comboBox4->Name = L"comboBox4";
			this->comboBox4->Size = System::Drawing::Size(64, 24);
			this->comboBox4->TabIndex = 18;
			// 
			// comboBox2
			// 
			this->comboBox2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox2->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"2孔3次", L"4孔4次"});
			this->comboBox2->Location = System::Drawing::Point(199, 58);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(251, 24);
			this->comboBox2->TabIndex = 16;
			this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &goujian::comboBox2_SelectedIndexChanged);
			// 
			// comboBox1
			// 
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(199, 24);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(251, 24);
			this->comboBox1->TabIndex = 15;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &goujian::comboBox1_SelectedIndexChanged);
			this->comboBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &goujian::comboBox1_KeyPress);
			this->comboBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &goujian::textBox4_MouseDown);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label9->Location = System::Drawing::Point(362, 206);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(129, 19);
			this->label9->TabIndex = 8;
			this->label9->Text = L"初应力选择：";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label8->Location = System::Drawing::Point(547, 206);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(89, 16);
			this->label8->TabIndex = 7;
			this->label8->Text = L"Ó con/min";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label7->Location = System::Drawing::Point(240, 210);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(89, 16);
			this->label7->TabIndex = 6;
			this->label7->Text = L"Ó con/min";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(12, 255);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(262, 193);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 5;
			this->pictureBox1->TabStop = false;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label6->Location = System::Drawing::Point(27, 206);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(149, 19);
			this->label6->TabIndex = 4;
			this->label6->Text = L"张拉加载速度：";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label4->Location = System::Drawing::Point(28, 95);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(229, 19);
			this->label4->TabIndex = 2;
			this->label4->Text = L"单根钢绞线张拉控制力：";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label3->Location = System::Drawing::Point(28, 60);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(142, 19);
			this->label3->TabIndex = 1;
			this->label3->Text = L"张 拉 工 艺：";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label2->Location = System::Drawing::Point(28, 25);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(142, 19);
			this->label2->TabIndex = 0;
			this->label2->Text = L"张 拉 梁 号：";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label1->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->label1->Location = System::Drawing::Point(43, 21);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(110, 16);
			this->label1->TabIndex = 1;
			this->label1->Text = L"构件信息输入";
			// 
			// goujian
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(740, 588);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->panel1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"goujian";
			this->Text = L"构件信息输入";
			this->Shown += gcnew System::EventHandler(this, &goujian::goujian_Shown);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
				 this->comboBox6->Enabled = this->checkBox1->Checked;
				 //m_ZhangLaParameterView->More_check=1;
				 //More_check=1;
			 }
private: System::Void  onlynumber(System::Object^ sender,  System::Windows::Forms::KeyPressEventArgs^ e)
		 {
			 TextBox^ txt = (TextBox^ )sender;
			 if (((int)e->KeyChar < 48 || (int)e->KeyChar > 57) && (int)e->KeyChar != 8 && (int)e->KeyChar != 46   &&  (int)e->KeyChar != 45){
				 e->Handled = true;
				 MessageBox::Show("请输入合法数据：此处必须是数字","输入错误", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
			 }
			 if ((int)e->KeyChar == 46)                         
			 {
				 if (txt->ToString()->Length <= 0)
					 e->Handled = true;
			 }
		 }
private: System::Void project_enable_changeState( int setValue){
			 if( setValue == 0){
				 for(int j=0;j<zhangLaSeqNum;j++) 
					 this->sequence_TextBox[j]->Enabled = false;

				 this->comboBox2->Enabled = false;
				 this->comboBox3->Enabled = false;
				 this->comboBox4->Enabled = false;
				 this->comboBox5->Enabled = false;
				 this->comboBox6->Enabled = false;

				 this->checkBox1->Enabled = false;
				 this->textBox1->Enabled = false;
				 this->textBox2->Enabled = false;
				 this->textBox3->Enabled = false;
				 this->textBox4->Enabled = false;
			 }
			 else
			 {
				 for(int j=0;j<zhangLaSeqNum;j++) 
					 this->sequence_TextBox[j]->Enabled = true;

				 this->comboBox2->Enabled = true;
				 this->comboBox3->Enabled = true;
				 this->comboBox4->Enabled = true;
				 this->comboBox5->Enabled = true;
				// this->comboBox6->Enabled = true;

				 this->checkBox1->Enabled = true;
				 this->textBox1->Enabled = true;
				 this->textBox2->Enabled = true;
				 this->textBox3->Enabled = true;
				 this->textBox4->Enabled = true;
				 this->comboBox6->Enabled = this->checkBox1->Checked;
			 }	 
 }


private: System::Void button_mod_Click(System::Object^  sender, System::EventArgs^  e) {
			 project_enable_changeState(1);
		 }
private: System::Boolean checkAllDataReady()
		 {
			 this->str_holeInfo[preHoleNum * 3] = this->textBox2->Text;
			 this->str_holeInfo[preHoleNum * 3 + 1] = this->textBox3->Text;
			 this->str_holeInfo[preHoleNum * 3 + 2] = this->textBox4->Text;

			 if(this->textBox1->Text->Length <= 0 ) {
				 MessageBox::Show("请输入：单根钢绞线张拉控制力","信息输入错误", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
				 return false;
			 }
			 
			 for(int i = 0; i < this->comboBox3->Items->Count; i++) {
				 if(this->str_holeInfo[i * 3]->Length <= 0 ) {
					 MessageBox::Show(L"请输入孔" + System::Convert::ToString(i + 1) + "钢绞线数量","信息输入错误", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
					 return false;
				 }
				 if(this->str_holeInfo[i * 3 + 1]->Length <= 0 ) {
					 MessageBox::Show(L"请输入孔" + System::Convert::ToString(i+ 1) + "张拉控制力","信息输入错误", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
					 return false;
				 }
				 if(this->str_holeInfo[i * 3 + 2]->Length <= 0 ) {
					 MessageBox::Show(L"请输入孔" + System::Convert::ToString(i+ 1) + "理论伸长量","信息输入错误", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
					 return false;
				 }
			 }
			 return true;
		 }
private: System::Void button_sav_Click(System::Object^  sender, System::EventArgs^  e) {
			/* if (More_check==1)
			 {
				 StreamWriter pfile("..//Debug//1.dat");
				 pfile.WriteLine(comboBox6->Text);
				 pfile.Close();
			 }*/
			 //readLiangInfo(L"select chaozhangla from table" + System::Convert::ToString(curLiangType) + L" where lianghao ='" + this->comboBox1->Text + L"'");
			 
			 
			  System::String^ sqlStr = "";
			  if( liangHaoChanged && checkAllDataReady() ) {  //liangHaoChanged = 1, insert,  == 2, update
				  //Insert into table1 (lianghao, gongyi) VALUES ('100', 'Description')";
				 this->defaultKnStr = this->textBox1->Text ;
				  this->defaultExtendStr = this->textBox4->Text ;
				  
				  if(liangHaoChanged == 1) {
					  sqlStr = sqlStr + L"Insert into table" +  System::Convert::ToString(curLiangType)
						  + L" (lianghao, gongyi, sudu, chuyinli ";
					  for(int i = 0; i < this->comboBox3->Items->Count; i++) {
						  sqlStr = sqlStr + L", kong" + System::Convert::ToString(i+1) +
							  L", kongshu" + System::Convert::ToString(i+1) +
							  L", konglali" + System::Convert::ToString(i+1) +
							  L", kongshenchang" + System::Convert::ToString(i+1) ;
					  }
					  for ( int i = 0; i < zhanglaNum; i++)
						  sqlStr = sqlStr + L" , shun" + System::Convert::ToString(i+1);
					  sqlStr = sqlStr + L", chaozhangla,dangenlali) VALUES ( '" + this->comboBox1->Text->Trim() + L"' , '"
						   + this->comboBox2->Text->Trim() + L"' , '"
						   + this->comboBox4->Text->Trim() + L"' , '"
						   + this->comboBox5->Text->Trim() + L"' , '";

					  for(int i = 0; i < this->comboBox3->Items->Count; i++) {
						  sqlStr = sqlStr + this->comboBox3->Items[i]->ToString() + L"' , '"
							  + this->str_holeInfo[i * 3] + L"' , '"
							  + this->str_holeInfo[i * 3 + 1] + L"' , '"
							  + this->str_holeInfo[i * 3 + 2] + L"' , '";
					  }
					  for ( int i = 0; i < zhanglaNum; i++)
							sqlStr = sqlStr + this->sequence_TextBox[i]->Text  + L"' , '";
					  if( this->checkBox1->Checked)
						sqlStr = sqlStr + this->comboBox6->Text  + L"' , '";
					  else
						  sqlStr = sqlStr +  L"' , '";
					  sqlStr = sqlStr + this->textBox1->Text->Trim() + L"' )";

				  }
				  else if(liangHaoChanged == 2) {
					  
					  sqlStr = sqlStr + L"Update table" +  System::Convert::ToString(curLiangType)
						  + L" SET gongyi = '"  + this->comboBox2->Text->Trim() 
						  + L"' ,  sudu = '"  + this->comboBox4->Text->Trim() 
						   + L"' ,  chuyinli = '"  + this->comboBox5->Text->Trim()
						  + L"' ,  dangenlali = '"  + this->textBox1->Text->Trim();
					  if ( this->checkBox1->Checked )
						 sqlStr = sqlStr +  L"' ,  chaozhangla = '"  + this->comboBox6->Text->Trim()  ;
					  else
						  sqlStr = sqlStr +  L"' ,  chaozhangla = '"  ;

						  for(int i = 0; i < this->comboBox3->Items->Count; i++) {
							  sqlStr = sqlStr + L"', kong" + System::Convert::ToString(i+1) + L" = '" + this->comboBox3->Items[i]->ToString() 
								 + L"', kongshu" + System::Convert::ToString(i+1)  + L" = '" + this->str_holeInfo[i * 3] 
								 + L"', konglali" + System::Convert::ToString(i+1) + L" = '" + this->str_holeInfo[i * 3 + 1] 
								 + L"', kongshenchang" + System::Convert::ToString(i+1) + L" = '" + this->str_holeInfo[i * 3 + 2]  ;
						  }
						   
						  for ( int i = 0; i < zhanglaNum; i++)
							  sqlStr = sqlStr + L"' , shun" + System::Convert::ToString(i+1) + L" = '" + this->sequence_TextBox[i]->Text;
						  sqlStr = sqlStr + L"' WHERE lianghao ='" + this->comboBox1->Text->Trim() + L"'";  
				  }
				  if( writeSql(sqlStr) == true ){
					  if(liangHaoChanged == 1)
						 this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(1) {this->comboBox1->Text});
					//  clearTextContent();
					  //liangHaoChanged = 0;
					  this->comboBox3->SelectedIndex = 0;
					  this->comboBox4->SelectedIndex = 0;
					  this->comboBox5->SelectedIndex = 0;
					  this->comboBox6->SelectedIndex = 0;
					  project_enable_changeState(0);
				  }
			  }
			  //Line_num=this->textBox2->Text;
			  //Line_kn=this->textBox3->Text;
			  //System::Convert::ToInt32(Line_num,1);
			  /*for (int i=0;i<20;i++)
			  {
				  MessageBox::Show(str_holeInfo[i]);
			  }*/
		 }
		
//张拉梁号
private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		project_enable_changeState(0);
		liangHaoChanged = 2;
		clearTextContent();
		readLiangInfo(L"select * from table" + System::Convert::ToString(curLiangType) + L" where lianghao ='" + this->comboBox1->Text + L"'");
		//select * from table1 where 张拉梁号== combobox1.text   //并在textbox上显示
		 }
//孔号
private: System::Void comboBox3_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 this->str_holeInfo[preHoleNum * 3] = this->textBox2->Text;
			 this->str_holeInfo[preHoleNum * 3 + 1] = this->textBox3->Text;
			 this->str_holeInfo[preHoleNum * 3 + 2] = this->textBox4->Text;
			 preHoleNum = this->comboBox3->SelectedIndex;
			 this->textBox2->Text = this->str_holeInfo[preHoleNum * 3];
			 this->textBox3->Text = this->str_holeInfo[preHoleNum * 3 + 1];
			 this->textBox4->Text = this->str_holeInfo[preHoleNum * 3 + 2];
		}
private: System::Void comboBox1_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
		project_enable_changeState(1);
		liangHaoChanged = 1;
		//clearTextContent();
		this->textBox1->Text =  this->defaultKnStr;
		this->textBox4->Text =  this->defaultExtendStr ;
		 }
		 //单根张拉控制力
private: System::Void textBox1_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
		 onlynumber(sender,e);
		 }
		 //钢筋数
private: System::Void textBox2_Leave(System::Object^  sender, System::EventArgs^  e) {
			
		}
private: System::Void textBox2_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
		 onlynumber(sender,e);
		 NumChanged = 1;
		 }
		 //张拉控制力
private: System::Void textBox3_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
		 onlynumber(sender,e);
		 }
		 //理论伸长量
private: System::Void textBox4_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
		 onlynumber(sender,e);
		 }
		 //张拉工艺
private: System::Void comboBox2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 try{
				 this->pictureBox1->Image = Image::FromFile(System::AppDomain::CurrentDomain->BaseDirectory->ToString() + L"\\Resources\\"+this->comboBox2->Text + L".jpg");
			 }
			 catch( Exception ^ ex){
				 //MessageBox::Show(ex->Message,"文件缺失", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
				 this->pictureBox1->Image = nullptr;
			 };
			 clearTextContent();
			 int j = 0;
			 try{
				 if( this->comboBox2->Text == L"2孔3次") {
					 this->panel2->Visible = true;
					 this->comboBox3->Items->Clear();
					 this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(1) {L"N1左-N1右"});
					 this->comboBox3->SelectedIndex = 0;
					 j=0;
					 this->sequence_TextBox[j]->Text = "50%N1左";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N1右";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N1左";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = false;
					 j++;
				 }else if(this->comboBox2->Text == L"4孔4次") {
					 this->panel2->Visible = true;
					 this->comboBox3->Items->Clear();
					 this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"N1左-N1右",L"N2左-N2右"});
					 this->comboBox3->SelectedIndex = 0;
					 j=0;
					 this->sequence_TextBox[j]->Text = "100%N1左";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N2右";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N1右";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N2左";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = false;
					 j++;
				 }else if(this->comboBox2->Text == L"3孔4次") {
					 this->panel2->Visible = true;
					 this->comboBox3->Items->Clear();
					 this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"N1",L"N2",L"N3"});
					 this->comboBox3->SelectedIndex = 0;
					 j=0;
					 this->sequence_TextBox[j]->Text = "50%N2";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N3";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N2";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N1";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = false;
					 j++;
				 }else if(this->comboBox2->Text == L"T梁4孔4次") {
					 this->panel2->Visible = true;
					 this->comboBox3->Items->Clear();
					 this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"N1",L"N2",L"N3",L"N4"});
					 this->comboBox3->SelectedIndex = 0;
					 j=0;
					 this->sequence_TextBox[j]->Text = "100%N1";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N2";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N3";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N4";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = false;
					 j++;
				 }else if(this->comboBox2->Text == L"4孔5次") {
					 this->panel2->Visible = true;
					 this->comboBox3->Items->Clear();
					 this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"N1",L"N2",L"N3",L"N4"});
					 this->comboBox3->SelectedIndex = 0;
					 j=0;
					 this->sequence_TextBox[j]->Text = "50%N2";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N3";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N4";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N1";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N2";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = false;
					 j++;
				 }else if(this->comboBox2->Text == L"4孔6次") {
					 this->panel2->Visible = true;
					 this->comboBox3->Items->Clear();
					 this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"N1",L"N2",L"N3",L"N4"});
					 this->comboBox3->SelectedIndex = 0;
					 j=0;
					 this->sequence_TextBox[j]->Text = "50%N2";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "50%N3";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N4";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N3";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N2";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N1";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = false;
					 j++;
				 }else if(this->comboBox2->Text == L"4孔8次") {
					 this->panel2->Visible = true;
					 this->comboBox3->Items->Clear();
					 this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"N1",L"N2",L"N3",L"N4"});
					 this->comboBox3->SelectedIndex = 0;
					 j=0;
					 this->sequence_TextBox[j]->Text = "50%N1";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N1";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "50%N2";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N2";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "50%N3";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N3";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "50%N4";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N4";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = false;
					 j++;
				 }else if(this->comboBox2->Text == L"5孔6次") {
					 this->panel2->Visible = true;
					 this->comboBox3->Items->Clear();
					 this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(5) {L"N1",L"N2",L"N3",L"N4左",L"N4右"});
					 this->comboBox3->SelectedIndex = 0;
					 j=0;
					 this->sequence_TextBox[j]->Text = "100%N1";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N2";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N3";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "50%N4左";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N4右";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N4左";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = false;
					 j++;
				 }else if(this->comboBox2->Text == L"5孔7次") {
					 this->panel2->Visible = true;
					 this->comboBox3->Items->Clear();
					 this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(5) {L"N1左",L"N1右",L"N2",L"N3",L"N4"});
					 this->comboBox3->SelectedIndex = 0;
					 j=0;
					 this->sequence_TextBox[j]->Text = "50%N2";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "50%N3";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N1左";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N1右";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N2";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N3";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N4";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = false;
					 j++;
				 }else if(this->comboBox2->Text == L"5孔8次") {
					 this->panel2->Visible = true;
					 this->comboBox3->Items->Clear();
					 this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(5) {L"N1左",L"N1右",L"N2",L"N3",L"N4"});
					 this->comboBox3->SelectedIndex = 0;
					 j=0;
					 this->sequence_TextBox[j]->Text = "50%N2";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "50%N3";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "50%N1左";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N1右";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N1左";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N2";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N3";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N4";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = false;
					 j++;
				 }else if(this->comboBox2->Text == L"5孔10次") {
					 this->panel2->Visible = true;
					 this->comboBox3->Items->Clear();
					 this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(5) {L"N1",L"N2",L"N3",L"N4",L"N5"});
					 this->comboBox3->SelectedIndex = 0;
					 j=0;
					 this->sequence_TextBox[j]->Text = "50%N1";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N1";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "50%N2";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N2";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "50%N3";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N3";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "50%N4";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N4";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "50%N5";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N5";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = false;
					 j++;
				 }else if(this->comboBox2->Text == L"5孔11次") {
					 this->panel2->Visible = true;
					 this->comboBox3->Items->Clear();
					 this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(5) {L"N1左",L"N1右",L"N2",L"N3",L"N4"});
					 this->comboBox3->SelectedIndex = 0;
					 j=0;
					 this->sequence_TextBox[j]->Text = "50%N2";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "50%N3";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "50%N1左";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "50%N1右";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "75%N1左";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "75%N1右";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N1左";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N1右";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N2";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N3";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N4";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = false;
					 j++;
				 }else if(this->comboBox2->Text == L"5孔13次") {
					 this->panel2->Visible = true;
					 this->comboBox3->Items->Clear();
					 this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(5) {L"N1左",L"N1右",L"N2",L"N3",L"N4"});
					 this->comboBox3->SelectedIndex = 0;
					 j=0;
					 this->sequence_TextBox[j]->Text = "50%N2";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "50%N3";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "25%N1左";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "25%N1右";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "50%N1左";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "50%N1右";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "75%N1左";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "75%N1右";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N1左";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N1右";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N2";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N3";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N4";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = false;
					 j++;
				 }else if(this->comboBox2->Text == L"6孔8次") {
					 this->panel2->Visible = true;
					 this->comboBox3->Items->Clear();
					 this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(6) {L"N1左",L"N1右",L"N2左",L"N2右",L"N3",L"N4"});
					 this->comboBox3->SelectedIndex = 0;
					 j=0;
					 this->sequence_TextBox[j]->Text = "100%N3";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "50%N2左";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N2右";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N2左";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N4";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "50%N1左";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N1右";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N1左";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = false;
					 j++;
				 }else if(this->comboBox2->Text == L"6孔6次对称张拉") {
					 this->panel2->Visible = true;
					 this->comboBox3->Items->Clear();
					 this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"N1左 N1右",L"N2左 N2右",L"N3左 N3右"});
					 this->comboBox3->SelectedIndex = 0;
					 j=0;
					 this->sequence_TextBox[j]->Text = "50%N1左 N1右";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N1左 N1右";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "50%N2左 N2右";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N2左 N2右";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "50%N3左 N3右";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N3左 N3右";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = false;
					 j++;
				 }else if(this->comboBox2->Text == L"6孔12次对称张拉") {
					 this->panel2->Visible = true;
					 this->comboBox3->Items->Clear();
					 this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"N1左-N1右",L"N2左-N2右",L"N3左-N3右"});
					 this->comboBox3->SelectedIndex = 0;
					 j=0;
					 this->sequence_TextBox[j]->Text = "50%N1左";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N1左";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "50%N1右";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N1右";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "50%N2左";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N2左";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "50%N2右";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N2右";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "50%N3左";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N3左";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "50%N3右";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N3右";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = false;
					 j++;
				 }else if(this->comboBox2->Text == L"6孔6次") {
					 this->panel2->Visible = true;
					 this->comboBox3->Items->Clear();
					 this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"N1左-N1右",L"N2左-N2右",L"N3左-N3右"});
					 this->comboBox3->SelectedIndex = 0;
					 j=0;
					 this->sequence_TextBox[j]->Text = "100%N1左";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N1右";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N2右";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N2左";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N3左";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N3右";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = false;
					 j++;
				 }else if(this->comboBox2->Text == L"7孔7次") {
					 this->panel2->Visible = true;
					 this->comboBox3->Items->Clear();
					 this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"N1左-N1右",L"N2左-N2右",L"N3左-N3右",L"N1a"});
					 this->comboBox3->SelectedIndex = 0;
					 j=0;
					 this->sequence_TextBox[j]->Text = "100%N2左";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N2右";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N3左";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N3右";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N1左";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N1右";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N1a";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = false;
					 j++;
				 }else if(this->comboBox2->Text == L"8孔8次") {
					 this->panel2->Visible = true;
					 this->comboBox3->Items->Clear();
					 this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"N1左-N1右",L"N2左-N2右",L"N3左-N3右",L"N4左-N4右"});
					 this->comboBox3->SelectedIndex = 0;
					 j=0;
					 this->sequence_TextBox[j]->Text = "100%N1左";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N1右";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N3右";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N3左";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N2左";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N2右";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N4右";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N4左";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = false;
					 j++;
				 }else if(this->comboBox2->Text == L"6孔3次两端张拉") {
					 this->panel2->Visible = true;
					 this->comboBox3->Items->Clear();
					 this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"N1左 N1右",L"N2左 N2右",L"N3左 N3右"});
					 this->comboBox3->SelectedIndex = 0;
					 j=0;
					 this->sequence_TextBox[j]->Text = "100%N1左 N1右";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N2左 N2右";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N3左 N3右";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = false;
					 j++;
				 }else if(this->comboBox2->Text == L"8孔4次两端张拉") {
					 this->panel2->Visible = true;
					 this->comboBox3->Items->Clear();
					 this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"N1左 N1右",L"N2左 N2右",L"N3左 N3右",L"N4左 N4右"});
					 this->comboBox3->SelectedIndex = 0;
					 j=0;
					 this->sequence_TextBox[j]->Text = "100%N1左 N1右";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N2左 N2右";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N3左 N3右";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N4左 N4右";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = false;
					 j++;
				 } else if(this->comboBox2->Text == L"9孔9次一") {
					 this->comboBox3->Items->Clear();
					 this->panel2->Visible = false;
					 j=0;
				 }else if(this->comboBox2->Text == L"9孔9次二") {
					 this->comboBox3->Items->Clear();
					 this->panel2->Visible = false;
					 j=0;
				 }else if(this->comboBox2->Text == L"10孔5次两端张拉") {
					 this->panel2->Visible = true;
					 this->comboBox3->Items->Clear();
					 this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(5) {L"N1左 N1右",L"N2左 N2右",L"N3左 N3右",L"N4左 N4右",L"N5左 N5右"});
					 this->comboBox3->SelectedIndex = 0;
					 j=0;
					 this->sequence_TextBox[j]->Text = "100%N1左 N1右";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N2左 N2右";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N3左 N3右";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N4左 N4右";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N5左 N5右";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = false;
					 j++;
				 }else if(this->comboBox2->Text == L"12孔6次两端张拉") {
					 this->panel2->Visible = true;
					 this->comboBox3->Items->Clear();
					 this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(6) {L"N1左 N1右",L"N2左 N2右",L"N3左 N3右",L"N4左 N4右",L"N5左 N5右",L"N6左 N6右"});
					 this->comboBox3->SelectedIndex = 0;
					 j=0;
					 this->sequence_TextBox[j]->Text = "100%N1左 N1右";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N2左 N2右";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N3左 N3右";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N4左 N4右";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N5左 N5右";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = true;
					 j++;
					 this->sequence_TextBox[j]->Text = "100%N6左 N6右";
					 this->sequence_TextBox[j]->Visible = true;
					 this->sequence_label[j]->Visible = false;
					 j++;
				 }
			 }
			 catch(Exception ^exce)
			 {
				 MessageBox::Show(exce->Message,"智能张拉系统", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
			 }
			 zhanglaNum = j;
			 for( ;j < zhangLaSeqNum ; j++) {
				 this->sequence_TextBox[j]->Visible = false;
				 this->sequence_label[j]->Visible = false;
			 }
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
			this->comboBox1->Items->Clear();
			while (reader->Read())
			{
				this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(1) {reader->GetString(0)});
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
							  this->comboBox2->Text = meta[1]->ToString(); //reader->GetString(1);
							  this->comboBox4->Text =  meta[4]->ToString();
							  this->comboBox5->Text =  meta[5]->ToString();
							  this->textBox1->Text = meta[31]->ToString(); //32 : shun1     7:钢绞线数目
							  for ( int i = 0; i < zhanglaNum; i++)
								  this->sequence_TextBox[i]->Text = meta[32 + i]->ToString(); 

							  for(int i = 0; i < this->comboBox3->Items->Count; i++) {
								  this->str_holeInfo[i * 3] = meta[7 + i * 4]->ToString();
								  this->str_holeInfo[i * 3 + 1] = meta[8 + i * 4]->ToString();
								  this->str_holeInfo[i * 3 + 2] = meta[9 + i * 4]->ToString();
							  }
							  this->comboBox3->SelectedIndex = 0;
							  preHoleNum = 0;
							  this->textBox2->Text = this->str_holeInfo[0];
							  this->textBox3->Text = this->str_holeInfo[1];
							  this->textBox4->Text = this->str_holeInfo[2];
							  if(meta[30]->ToString()->Length <= 0 )
								  this->checkBox1->Checked = false;
							  else{
								  this->checkBox1->Checked = true;
								 // MessageBox::Show(meta[30]->ToString());
							  }
							  this->comboBox6->Text = meta[30]->ToString(); 
							 // for (int i = 0; i < NumberOfColums; i++)
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
private:		 static Boolean writeSql(String^ sqlString)
		 {
			 //	static int num = 0;
			 Boolean retVal = false;
			 System::String^ dataCon = L"Provider=Microsoft.Jet.OLEDB.4.0;Data Source=" + System::AppDomain::CurrentDomain->BaseDirectory->ToString() + L"\\jcData.mdb;Jet OLEDB:Database Password=jc123;Persist Security Info=False;";
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
			 return retVal;
		 }
public:		 System::Void 	setCaptionText(int index)
		 {
			 if(!bInit){
				 bInit = 1;
				 for(int j=0;j< holeInfoNum;j++) 
					 this->str_holeInfo[j] = (gcnew System::String("")); 
				 
				 for(int j=0;j< zhangLaSeqNum;j++) 
				 { 
					 this->sequence_label[j] = (gcnew System::Windows::Forms::Label()); 
					 this->sequence_label[j]->Font = (gcnew System::Drawing::Font(L"宋体", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
						 static_cast<System::Byte>(134)));
					 if( j < 7 )
						 this->sequence_label[j]->Location = System::Drawing::Point(80 + j*95, 473  ); 
					 else
						 this->sequence_label[j]->Location = System::Drawing::Point(80 + (j - 7)*95, 503  ); 
					 this->sequence_label[j]->Name = L"rightLabel"; 
					 this->sequence_label[j]->Size = System::Drawing::Size(25, 21); 
					 this->sequence_label[j]->Text = L"->"; 
					 this->sequence_label[j]->Visible = false;
					 this->panel1->Controls->Add(this->sequence_label[j]); 
				 }
				 for(int j=0;j<zhangLaSeqNum;j++) 
				 { 
					 this->sequence_TextBox[j] = (gcnew System::Windows::Forms::TextBox()); 
					 this->sequence_TextBox[j]->Font = (gcnew System::Drawing::Font(L"宋体", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
						 static_cast<System::Byte>(134)));
					 if( j < 7 )
						 this->sequence_TextBox[j]->Location = System::Drawing::Point(10 + j*95, 470  ); 
					 else
						 this->sequence_TextBox[j]->Location = System::Drawing::Point(10 + (j - 7)*95, 500  ); 
					 this->sequence_TextBox[j]->Name = L"rightLabel"; 
					 this->sequence_TextBox[j]->Size = System::Drawing::Size(70, 21); 
					 this->sequence_TextBox[j]->Text = L""; 
					 this->sequence_TextBox[j]->Visible = false;
					 this->panel1->Controls->Add(this->sequence_TextBox[j]); 
				 }
			 }
			 curLiangType = index;
			 if( preLiangType != curLiangType)
				 clearTextContent();
			 preLiangType = curLiangType;
			 this->comboBox4->SelectedIndex = 0;
			 this->comboBox5->SelectedIndex = 0;
			 this->comboBox6->SelectedIndex = 0;
			 readLiangHao(L"select lianghao from table" + System::Convert::ToString(curLiangType));
			 //	OpenConnection();
			 if(index == 1) {
				 this->Text = "空心板梁 - 构件信息输入";
				 this->comboBox2->Items->Clear();
				 this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"2孔3次", L"4孔4次"});
				 this->comboBox2->SelectedIndex = 0;
			 }
			 else if(index == 2){
				 this->Text = "简支T梁 - 构件信息输入";
				 this->comboBox2->Items->Clear();
				 this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(14) {L"3孔4次", L"T梁4孔4次", L"4孔5次", L"4孔6次", L"4孔8次",
					 L"5孔6次", L"5孔7次", L"5孔8次", L"5孔10次", L"5孔11次", 
					 L"5孔13次", L"6孔8次", L"6孔6次对称张拉", L"6孔12次对称张拉"});
				 this->comboBox2->SelectedIndex = 0;
			 }
			 else if(index == 3){
				 this->Text = "简支箱梁 - 构件信息输入";
				 this->comboBox2->Items->Clear();
				 this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(9) {L"6孔6次", L"7孔7次", L"8孔8次"
					 , L"6孔3次两端张拉", L"8孔4次两端张拉", L"9孔9次一", L"9孔9次二", L"10孔5次两端张拉", L"12孔6次两端张拉"});
				 this->comboBox2->SelectedIndex = 0;
			 }
			 else if(index == 4){
				 this->Text = "负弯矩束 - 构件信息输入";
				 this->comboBox2->Items->Clear();
				 this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"单根单端张拉", L"单根两端张拉"});
				 this->comboBox2->SelectedIndex = 0;
			 }
			 else if(index == 5){
				 this->Text = "连续梁纵向 - 构件信息输入";
				 this->comboBox2->Items->Clear();
				 this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"单束两端张拉", L"两束横桥向对称张拉"});
				 this->comboBox2->SelectedIndex = 0;
			 }
			 else if(index == 6){
				 this->Text = "连续梁横向 - 构件信息输入";
				 this->comboBox2->Items->Clear();
				 this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(1) {L"单根单端张拉"});
				 this->comboBox2->SelectedIndex = 0;
			 }
			 else if(index == 7){
				 this->Text = "竖向短束 - 构件信息输入";
				 this->comboBox2->Items->Clear();
				 this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(1) {L"分二次张拉"});
				 this->comboBox2->SelectedIndex = 0;
			 }
			 else if(index == 8){
				 this->Text = "盖梁构件 - 信息输入";
				 this->comboBox2->Items->Clear();
				 this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(1) {L"单根两端张拉"});
				 this->comboBox2->SelectedIndex = 0;
			 }
			 else if(index == 9)
				 this->Text = "其它张拉 - 构件信息输入";
		 }

private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if( NumChanged ) {
				 float num,kn;
				 NumChanged = 0;
				 try
				 {
					 num = System::Convert::ToSingle(this->textBox2->Text);
					 kn = System::Convert::ToSingle (this->textBox1->Text);
					 this->textBox3->Text = System::Convert::ToString( kn * num);
				 }
				 catch (Exception^ e)
				 {
				 	
				 }
			 }
		 }
private : System::Void  clearTextContent(){
			  for(int j=0;j< holeInfoNum;j++) 
			  	if( (j + 1) %3 != 0 )
				  this->str_holeInfo[j] = "";
				else
					this->str_holeInfo[j] = defaultExtendStr;
			  preHoleNum = 0;
			  this->checkBox1->Checked = false;
			  this->textBox2->Text = "";
			  this->textBox3->Text = "";
			  this->textBox4->Text = "";
			  //this->comboBox1->
			  this->textBox1->Text =  this->defaultKnStr;

			  this->textBox4->Text =  this->defaultExtendStr ;
		  }

public: BOOL FindProcess( char * pName)
{
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
			return true;
		}
		bMore = ::Process32Next(hProcessSnap, &pe32);
	}
	return false;
}
public: void showKeyBoard() {
	if( FindProcess ( "osk.exe") )
		return;

	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory( &si, sizeof(si) );
	si.cb = sizeof(si);
	ZeroMemory( &pi, sizeof(pi) );
	TCHAR lpszCmd[500]= TEXT("osk"); //cmd.exe /c
	// Start the child process. 
	if( !CreateProcess( NULL,   // No module name (use command line)
		lpszCmd,        // Command line
		NULL,           // Process handle not inheritable
		NULL,           // Thread handle not inheritable
		FALSE,          // Set handle inheritance to FALSE
		0,              // No creation flags
		NULL,           // Use parent's environment block
		NULL,           // Use parent's starting directory 
		&si,            // Pointer to STARTUPINFO structure
		&pi )           // Pointer to PROCESS_INFORMATION structure
		) 
	{
		printf( "CreateProcess failed (%d).\n", GetLastError() );
		return;
	}
}

private: System::Void goujian_Shown(System::Object^  sender, System::EventArgs^  e) {
			showKeyBoard();
		 }
private: System::Void textBox4_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 showKeyBoard();
		 }
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	float num,kn;
		 NumChanged = 0;
		 try
		 {
			 kn = System::Convert::ToSingle (this->textBox1->Text);

			 	for(int i = 0; i < this->comboBox3->Items->Count; i++) {
					 if(this->str_holeInfo[i * 3 ]->Length > 0 ) {
						num = System::Convert::ToSingle(this->str_holeInfo[i * 3 ]);
					    this->str_holeInfo[i * 3 +1] = System::Convert::ToString( kn * num);
					 	}
			 	}
			num = System::Convert::ToSingle(this->textBox2->Text);
			this->textBox3->Text = System::Convert::ToString( kn * num);
		 }
		 catch (Exception^ e)
		 {
		 	
		 }
 }


};


}
