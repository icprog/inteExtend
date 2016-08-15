#pragma once
#include "comBase.h"
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

	using namespace System::Runtime::InteropServices;
	using namespace System::Threading;

	using namespace OPC::Common;
	using namespace OPC::Data::Interface;
	using namespace OPC::Data;

	/// <summary>
	/// systemSet 摘要
	/// </summary>
	public ref class systemSet : public System::Windows::Forms::Form
	{
	public:
		systemSet(void)
		{
			connectStatus = false;
			dataChanged = false;
			timeTickCount = 0;
			InitializeComponent();
			//
			//TODO: 在此处添加构造函数代码
			//
		}

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~systemSet()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Boolean  dataChanged,connectStatus;
	
	private: System::Int32 timeTickCount,sendTest ;
public: combase^  p_comBase;
	protected: 
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label2;
	
	public: System::Windows::Forms::TextBox^  textBox1;
	public: System::Windows::Forms::TextBox^  textBox2;
	public: System::Windows::Forms::TextBox^  textBox3;
	public: System::Windows::Forms::TextBox^  textBox4;
	public: System::Windows::Forms::TextBox^  textBox5;
	public: System::Windows::Forms::TextBox^  textBox6;
	public: System::Windows::Forms::TextBox^  textBox7;
	public: System::Windows::Forms::TextBox^  textBox8;
	public: System::Windows::Forms::TextBox^  textBox9;

	private: System::Windows::Forms::Label^  label7;

	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label41;
	private: System::Windows::Forms::Button^  button_commuTest;

	private: System::Windows::Forms::Button^  button_exit;

	private: System::Windows::Forms::Button^  button_save;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Label^  label16;
	public: System::Windows::Forms::TextBox^  textBox10;
	private: 
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::Label^  label18;
	public: 
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(systemSet::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->button_commuTest = (gcnew System::Windows::Forms::Button());
			this->button_exit = (gcnew System::Windows::Forms::Button());
			this->button_save = (gcnew System::Windows::Forms::Button());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label41 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label1->Location = System::Drawing::Point(15, 75);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(133, 19);
			this->label1->TabIndex = 0;
			this->label1->Text = L"张拉仪1地址：";
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel1->Controls->Add(this->label18);
			this->panel1->Controls->Add(this->label16);
			this->panel1->Controls->Add(this->textBox10);
			this->panel1->Controls->Add(this->label17);
			this->panel1->Controls->Add(this->button_commuTest);
			this->panel1->Controls->Add(this->button_exit);
			this->panel1->Controls->Add(this->button_save);
			this->panel1->Controls->Add(this->label13);
			this->panel1->Controls->Add(this->textBox7);
			this->panel1->Controls->Add(this->label14);
			this->panel1->Controls->Add(this->textBox8);
			this->panel1->Controls->Add(this->label15);
			this->panel1->Controls->Add(this->textBox9);
			this->panel1->Controls->Add(this->label12);
			this->panel1->Controls->Add(this->textBox6);
			this->panel1->Controls->Add(this->label11);
			this->panel1->Controls->Add(this->textBox5);
			this->panel1->Controls->Add(this->label10);
			this->panel1->Controls->Add(this->textBox4);
			this->panel1->Controls->Add(this->label9);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->textBox1);
			this->panel1->Controls->Add(this->textBox3);
			this->panel1->Controls->Add(this->label7);
			this->panel1->Controls->Add(this->textBox2);
			this->panel1->Controls->Add(this->label8);
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(12, 22);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(628, 365);
			this->panel1->TabIndex = 1;
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label18->Location = System::Drawing::Point(244, 162);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(29, 19);
			this->label18->TabIndex = 30;
			this->label18->Text = L"Hz";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label16->Location = System::Drawing::Point(565, 169);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(29, 19);
			this->label16->TabIndex = 29;
			this->label16->Text = L"Hz";
			// 
			// textBox10
			// 
			this->textBox10->Font = (gcnew System::Drawing::Font(L"宋体", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->textBox10->Location = System::Drawing::Point(471, 163);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(90, 30);
			this->textBox10->TabIndex = 28;
			this->textBox10->Text = L"15";
			this->textBox10->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox10->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &systemSet::textBox7_MouseDown);
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label17->Location = System::Drawing::Point(317, 165);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(133, 19);
			this->label17->TabIndex = 27;
			this->label17->Text = L"顶1补压频率：";
			// 
			// button_commuTest
			// 
			this->button_commuTest->Font = (gcnew System::Drawing::Font(L"宋体", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->button_commuTest->Location = System::Drawing::Point(416, 62);
			this->button_commuTest->Name = L"button_commuTest";
			this->button_commuTest->Size = System::Drawing::Size(145, 41);
			this->button_commuTest->TabIndex = 26;
			this->button_commuTest->Text = L"通信测试";
			this->button_commuTest->UseVisualStyleBackColor = true;
			this->button_commuTest->Click += gcnew System::EventHandler(this, &systemSet::button_commuTest_Click);
			// 
			// button_exit
			// 
			this->button_exit->Font = (gcnew System::Drawing::Font(L"宋体", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->button_exit->Location = System::Drawing::Point(321, 302);
			this->button_exit->Name = L"button_exit";
			this->button_exit->Size = System::Drawing::Size(98, 41);
			this->button_exit->TabIndex = 25;
			this->button_exit->Text = L"退 出";
			this->button_exit->UseVisualStyleBackColor = true;
			this->button_exit->Click += gcnew System::EventHandler(this, &systemSet::button_exit_Click);
			// 
			// button_save
			// 
			this->button_save->Font = (gcnew System::Drawing::Font(L"宋体", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->button_save->Location = System::Drawing::Point(148, 302);
			this->button_save->Name = L"button_save";
			this->button_save->Size = System::Drawing::Size(98, 41);
			this->button_save->TabIndex = 12;
			this->button_save->Text = L"保 存";
			this->button_save->UseVisualStyleBackColor = true;
			this->button_save->Click += gcnew System::EventHandler(this, &systemSet::button_save_Click);
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label13->Location = System::Drawing::Point(564, 262);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(49, 19);
			this->label13->TabIndex = 24;
			this->label13->Text = L"M pa";
			// 
			// textBox7
			// 
			this->textBox7->Font = (gcnew System::Drawing::Font(L"宋体", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->textBox7->Location = System::Drawing::Point(471, 122);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(90, 30);
			this->textBox7->TabIndex = 23;
			this->textBox7->Text = L"20";
			this->textBox7->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox7->Click += gcnew System::EventHandler(this, &systemSet::textBox1_Click);
			this->textBox7->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &systemSet::textBox8_KeyPress);
			this->textBox7->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &systemSet::textBox7_MouseDown);
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label14->Location = System::Drawing::Point(565, 214);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(29, 19);
			this->label14->TabIndex = 22;
			this->label14->Text = L"Hz";
			// 
			// textBox8
			// 
			this->textBox8->Font = (gcnew System::Drawing::Font(L"宋体", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->textBox8->Location = System::Drawing::Point(471, 208);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(90, 30);
			this->textBox8->TabIndex = 21;
			this->textBox8->Text = L"15";
			this->textBox8->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox8->Click += gcnew System::EventHandler(this, &systemSet::textBox1_Click);
			this->textBox8->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &systemSet::textBox8_KeyPress);
			this->textBox8->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &systemSet::textBox7_MouseDown);
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label15->Location = System::Drawing::Point(565, 127);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(29, 19);
			this->label15->TabIndex = 20;
			this->label15->Text = L"Hz";
			// 
			// textBox9
			// 
			this->textBox9->Font = (gcnew System::Drawing::Font(L"宋体", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->textBox9->Location = System::Drawing::Point(471, 255);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(90, 30);
			this->textBox9->TabIndex = 19;
			this->textBox9->Text = L"0.5";
			this->textBox9->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox9->Click += gcnew System::EventHandler(this, &systemSet::textBox1_Click);
			this->textBox9->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &systemSet::textBox8_KeyPress);
			this->textBox9->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &systemSet::textBox7_MouseDown);
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label12->Location = System::Drawing::Point(244, 262);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(29, 19);
			this->label12->TabIndex = 18;
			this->label12->Text = L"Hz";
			// 
			// textBox6
			// 
			this->textBox6->Font = (gcnew System::Drawing::Font(L"宋体", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->textBox6->Location = System::Drawing::Point(148, 255);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(90, 30);
			this->textBox6->TabIndex = 17;
			this->textBox6->Text = L"30";
			this->textBox6->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox6->Click += gcnew System::EventHandler(this, &systemSet::textBox1_Click);
			this->textBox6->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &systemSet::textBox8_KeyPress);
			this->textBox6->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &systemSet::textBox7_MouseDown);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label11->Location = System::Drawing::Point(244, 215);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(29, 19);
			this->label11->TabIndex = 16;
			this->label11->Text = L"Hz";
			// 
			// textBox5
			// 
			this->textBox5->Font = (gcnew System::Drawing::Font(L"宋体", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->textBox5->Location = System::Drawing::Point(148, 208);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(90, 30);
			this->textBox5->TabIndex = 15;
			this->textBox5->Text = L"50";
			this->textBox5->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox5->Click += gcnew System::EventHandler(this, &systemSet::textBox1_Click);
			this->textBox5->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &systemSet::textBox8_KeyPress);
			this->textBox5->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &systemSet::textBox7_MouseDown);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label10->Location = System::Drawing::Point(244, 118);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(29, 19);
			this->label10->TabIndex = 14;
			this->label10->Text = L"Hz";
			// 
			// textBox4
			// 
			this->textBox4->Font = (gcnew System::Drawing::Font(L"宋体", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->textBox4->Location = System::Drawing::Point(148, 122);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(90, 30);
			this->textBox4->TabIndex = 13;
			this->textBox4->Text = L"25";
			this->textBox4->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox4->Click += gcnew System::EventHandler(this, &systemSet::textBox1_Click);
			this->textBox4->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &systemSet::textBox8_KeyPress);
			this->textBox4->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &systemSet::textBox7_MouseDown);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label9->Location = System::Drawing::Point(317, 255);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(142, 19);
			this->label9->TabIndex = 12;
			this->label9->Text = L"变频调压精度：";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label2->Location = System::Drawing::Point(15, 255);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(142, 19);
			this->label2->TabIndex = 11;
			this->label2->Text = L"手动操作频率：";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"宋体", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->textBox1->Location = System::Drawing::Point(148, 25);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(413, 30);
			this->textBox1->TabIndex = 10;
			this->textBox1->Text = L"D:\\张拉数据\\";
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &systemSet::textBox7_MouseDown);
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"宋体", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->textBox3->Location = System::Drawing::Point(148, 163);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(90, 30);
			this->textBox3->TabIndex = 9;
			this->textBox3->Text = L"25";
			this->textBox3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox3->Click += gcnew System::EventHandler(this, &systemSet::textBox1_Click);
			this->textBox3->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &systemSet::textBox8_KeyPress);
			this->textBox3->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &systemSet::textBox7_MouseDown);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label7->Location = System::Drawing::Point(15, 165);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(133, 19);
			this->label7->TabIndex = 8;
			this->label7->Text = L"顶2初始频率：";
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"宋体", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->textBox2->Location = System::Drawing::Point(148, 70);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(165, 30);
			this->textBox2->TabIndex = 7;
			this->textBox2->Text = L"192.168.2.10";
			this->textBox2->Click += gcnew System::EventHandler(this, &systemSet::textBox1_Click);
			this->textBox2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &systemSet::textBox8_KeyPress);
			this->textBox2->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &systemSet::textBox7_MouseDown);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label8->Location = System::Drawing::Point(317, 210);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(133, 19);
			this->label8->TabIndex = 6;
			this->label8->Text = L"顶2补压频率：";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label5->Location = System::Drawing::Point(15, 210);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(142, 19);
			this->label5->TabIndex = 5;
			this->label5->Text = L"张拉退顶频率：";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label6->Location = System::Drawing::Point(317, 127);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(142, 19);
			this->label6->TabIndex = 4;
			this->label6->Text = L"接近目标频率：";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label3->Location = System::Drawing::Point(15, 127);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(133, 19);
			this->label3->TabIndex = 3;
			this->label3->Text = L"顶1初始频率：";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label4->Location = System::Drawing::Point(15, 30);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(142, 19);
			this->label4->TabIndex = 2;
			this->label4->Text = L"数据保存路径：";
			// 
			// label41
			// 
			this->label41->AutoSize = true;
			this->label41->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label41->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->label41->Location = System::Drawing::Point(20, 12);
			this->label41->Name = L"label41";
			this->label41->Size = System::Drawing::Size(104, 16);
			this->label41->TabIndex = 11;
			this->label41->Text = L"系统参数设置";
			// 
			// timer1
			// 
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &systemSet::timer1_Tick);
			// 
			// systemSet
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(655, 399);
			this->Controls->Add(this->label41);
			this->Controls->Add(this->panel1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"systemSet";
			this->Text = L"系统设置";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &systemSet::systemSet_FormClosing);
			this->Load += gcnew System::EventHandler(this, &systemSet::systemSet_Load);
			this->Shown += gcnew System::EventHandler(this, &systemSet::systemSet_Shown);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void  onlynumber(System::Object^ sender,  System::Windows::Forms::KeyPressEventArgs^ e)
		 {
			 TextBox^ txt = (TextBox^ )sender;
			 if (((int)e->KeyChar < 48 || (int)e->KeyChar > 57) && (int)e->KeyChar != 8 && (int)e->KeyChar != 46 && (int)e->KeyChar != 45){
				 e->Handled = true;
				 MessageBox::Show("请输入合法数据：此处必须是数字","输入错误", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
			 }
			 if ((int)e->KeyChar == 46)                         
			 {
				 if (txt->ToString()->Length <= 0)
					 e->Handled = true;
			 }
		 }

private: System::Void button_exit_Click(System::Object^  sender, System::EventArgs^  e) {
			 if( dataChanged ) {
				System::Windows::Forms::DialogResult ^ r1;
				r1  =  MessageBox::Show("有未保存的数据，是否退出！","数据未保存", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
				 if( r1 == System::Windows::Forms::DialogResult::OK)
				 this->Hide();
			 }
			 else
				 this->Hide();
			// if( MessageBox::Show()
		 }

private: System::Void textBox1_Click(System::Object^  sender, System::EventArgs^  e) {

		 }

public: System::Void read_parameter( ) {
			 XmlTextReader^ reader = nullptr;
		 try
		 {
			 FileStream^ fs = gcnew FileStream( System::AppDomain::CurrentDomain->BaseDirectory->ToString() + "\\JC_SYSTEM", FileMode::Open, FileAccess::Read, FileShare::Read);
			reader = gcnew XmlTextReader( fs  );
			 StringBuilder^ builder = gcnew StringBuilder();
			 reader->WhitespaceHandling = WhitespaceHandling::None;
			reader->MoveToContent();
			//reader->ReadElementString( "project");
			 this->textBox1->Text =  reader->ReadElementString();
			 this->textBox2->Text =  reader->ReadElementString( "ip1");
			 this->textBox3->Text = reader->ReadElementString( "ip2");
			 this->textBox4->Text =  reader->ReadElementString( "startfreq");
			 this->textBox5->Text = reader->ReadElementString( "exitfreq");
			 this->textBox6->Text =  reader->ReadElementString( "handfreq");
			 this->textBox7->Text = reader->ReadElementString( "targetfreq");
			 this->textBox8->Text =  reader->ReadElementString( "supplyfreq");
			 this->textBox9->Text = reader->ReadElementString( "varMpa");
			 this->textBox10->Text =  reader->ReadElementString( "supplyfreq2");
			 this->p_comBase->ipAdd = this->textBox2->Text;
			 this->p_comBase->ipAdd2 = this->textBox3->Text;
			 this->p_comBase->opcWriteData[14] = System::Convert::ToSingle(this->textBox4->Text); //m_systemSet.textBox2->Text;//ip1
			 this->p_comBase->opcWriteData[15] = System::Convert::ToSingle(this->textBox5->Text);
			 this->p_comBase->opcWriteData[16] = System::Convert::ToSingle(this->textBox6->Text);
			 this->p_comBase->opcWriteData[17] = System::Convert::ToSingle(this->textBox7->Text);
			 this->p_comBase->opcWriteData[18] = System::Convert::ToSingle(this->textBox8->Text);
			 this->p_comBase->opcWriteData[19] = System::Convert::ToSingle(this->textBox9->Text);

			 if( itemNum > SINGLE_OPC_NUM ) {
				
				this->p_comBase->opcWriteData[SINGLE_OPC_NUM + 15] = this->p_comBase->opcWriteData[15] ;  
				this->p_comBase->opcWriteData[SINGLE_OPC_NUM + 16] = this->p_comBase->opcWriteData[16] ;  
				this->p_comBase->opcWriteData[SINGLE_OPC_NUM + 17] = this->p_comBase->opcWriteData[17] ; 
				this->p_comBase->opcWriteData[SINGLE_OPC_NUM + 18] =  System::Convert::ToSingle(this->textBox10->Text);   
				this->p_comBase->opcWriteData[SINGLE_OPC_NUM + 19] = this->p_comBase->opcWriteData[19] ; 
				
				this->p_comBase->opcWriteData[SINGLE_OPC_NUM + 14] = this->textBox3->Text ;  
			}

			 reader->Close();
			 reader = nullptr;
		 }
		 catch(XmlException^ er3)
		 {
			 MessageBox::Show(er3->Message,"read parameter error");
			 if ( reader != nullptr )
				 reader->Close();
		 }
		}
private: System::Void button_save_Click(System::Object^  sender, System::EventArgs^  e) {
		
			 if(this->textBox1->TextLength < 1 ) {                                                                              
				 MessageBox::Show("请填写张拉数据保存位置 ", "信息缺失", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);        
				 return;                                                                                                        
			 }                                                                                                                
			 if(this->textBox2->TextLength < 1 ) {                                                                       
				 MessageBox::Show("请填写张拉仪1地址 ", "信息缺失", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);        
				 return;                                                                                                        
			 }                                                                                                                
			 if(this->textBox3->TextLength < 1 ) {                                                                        
				 MessageBox::Show("请填写张拉初始频率 ", "信息缺失", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);        
				 return;                                                                                                        
			 }                                                                                                                
			 if(this->textBox4->TextLength < 1 ) {                                                                        
				 MessageBox::Show("请填写张拉初始频率 ", "信息缺失", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);    
				 return;                                                                                                        
			 }                                                                                                                
			 if(this->textBox5->TextLength < 1 ) {                                                                       
				 MessageBox::Show("请填写张拉退顶频率 ", "信息缺失", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);        
				 return;                                                                                                        
			 }                                                                                                                
			 if(this->textBox6->TextLength < 1 ) {                                                                    
				 MessageBox::Show("请填写手动操作频率 ", "信息缺失", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);        
				 return;                                                                                                        
			 }                                                                                                                
			 if(this->textBox7->TextLength < 1 ) {                                                                   
				 MessageBox::Show("请填写接近目标时频率 ", "信息缺失", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
				 return;                                                                                                        
			 }                                                                                                                
			 if(this->textBox8->TextLength < 1 ) {                                                                  
				 MessageBox::Show("请填写保压时补压频率 ", "信息缺失", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);        
				 return;                                                                                                        
			 }                                                                                                                
			 if(this->textBox9->TextLength < 1 ) {                                                           
				 MessageBox::Show("请填写压力变化值 ", "信息缺失", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
				 return;                                                                                                        
			 }	                                                                                                              
			 if(this->textBox10->TextLength < 1 ) {                                                                  
				 MessageBox::Show("请填写保压时补压频率 ", "信息缺失", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);        
				 return;                                                                                                        
			 } 

			 XmlTextWriter^ writer = nullptr;
			 XmlException^ er = gcnew XmlException();
			 try{
				 String^ filename = System::AppDomain::CurrentDomain->BaseDirectory->ToString() +  "JC_SYSTEM";
				 UnicodeEncoding^ uniCode_encode = gcnew UnicodeEncoding;
				 writer = gcnew XmlTextWriter( filename, uniCode_encode  );
				 writer->Formatting = Formatting::Indented;
				// writer->WriteComment( "parameter XML" );
				 writer->WriteStartElement( "project" );
				 writer->WriteElementString( "filePath",	this->textBox1->Text->Trim()	 ); // this->text_xiangMu
				 writer->WriteElementString( "ip1", 	this->textBox2->Text->Trim() );                      
				 writer->WriteElementString( "ip2", this->textBox3->Text->Trim() );                          
				 writer->WriteElementString( "startfreq", this->textBox4->Text->Trim() );                          
				 writer->WriteElementString( "exitfreq", this->textBox5->Text->Trim() );                      
				 writer->WriteElementString( "handfreq", this->textBox6->Text->Trim() );                  
				 writer->WriteElementString( "targetfreq", this->textBox7->Text->Trim() );                
				 writer->WriteElementString( "supplyfreq", this->textBox8->Text->Trim() );              
				 writer->WriteElementString( "varMpa", this->textBox9->Text->Trim() );
				 writer->WriteElementString( "supplyfreq2", this->textBox10->Text->Trim() );  
	 
				 //Write the close tag for the root element.
				 writer->WriteEndElement();
					 //Write the XML to file and close the writer.
				 writer->Flush();
				 writer->Close();
				 writer = nullptr;
				 dataChanged = false;
			  }
			 catch(XmlException^ er3)
			 {
				 MessageBox::Show(er3->Message,"write parameter error  !");
				 if ( writer != nullptr )
					 writer->Close();
			 }
			 try {
			 this->p_comBase->ipAdd = this->textBox2->Text;
			 this->p_comBase->ipAdd2 = this->textBox3->Text;
			 this->p_comBase->opcWriteData[14] = System::Convert::ToSingle(this->textBox4->Text); //m_systemSet.textBox2->Text;//ip1
			 this->p_comBase->opcWriteData[15] = System::Convert::ToSingle(this->textBox5->Text);
			 this->p_comBase->opcWriteData[16] = System::Convert::ToSingle(this->textBox6->Text);
			 this->p_comBase->opcWriteData[17] = System::Convert::ToSingle(this->textBox7->Text);
			 this->p_comBase->opcWriteData[18] = System::Convert::ToSingle(this->textBox8->Text);
			 this->p_comBase->opcWriteData[19] = System::Convert::ToSingle(this->textBox9->Text);
			 if( itemNum > SINGLE_OPC_NUM ) {
				this->p_comBase->opcWriteData[SINGLE_OPC_NUM + 15] = this->p_comBase->opcWriteData[15] ;  
				this->p_comBase->opcWriteData[SINGLE_OPC_NUM + 16] = this->p_comBase->opcWriteData[16] ;  
				this->p_comBase->opcWriteData[SINGLE_OPC_NUM + 17] = this->p_comBase->opcWriteData[17] ; 
				this->p_comBase->opcWriteData[SINGLE_OPC_NUM + 18] =  System::Convert::ToSingle(this->textBox10->Text); 
				this->p_comBase->opcWriteData[SINGLE_OPC_NUM + 19] = this->p_comBase->opcWriteData[19] ; 
				
				this->p_comBase->opcWriteData[SINGLE_OPC_NUM + 14] = this->textBox3->Text ;  
			}
			 	 }
	catch(Exception ^ ex) {
	}

		 }
private: System::Void systemSet_Load(System::Object^  sender, System::EventArgs^  e) {
			 read_parameter( );
		 }
private: System::Void textBox8_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 onlynumber(sender,e);
			 dataChanged = true;
		 }
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		timeTickCount++;
		try {
		System::String^ strNotice ; 
		if( sendTest ) {
			WaitForSingleObject(  this->p_comBase->semaphoreComp,10000);
			
			sendTest = 0;
			if((this->p_comBase->opcReadData[0]->Quality  == 192) && (this->p_comBase->opcReadData[0]->DataValue->ToString()->ToLower() == "true"))
				strNotice = "IP 1通信测试OK！";
			else
				strNotice = "IP 1通信测试失败！";
			
/*			if((this->p_comBase->opcReadData[SINGLE_OPC_NUM + 0]->Quality  == 192) && (this->p_comBase->opcReadData[SINGLE_OPC_NUM + 0]->DataValue->ToString()->ToLower() == "true"))
				strNotice += "IP 2通信测试OK！";
			else
				strNotice += "IP 2通信测试失败！"; */
			
			MessageBox::Show(strNotice,"通信测试", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
		}
			 }
	catch(Exception ^ ex) {
	}

}
private: System::Void systemSet_Shown(System::Object^  sender, System::EventArgs^  e) {
	this->timer1->Enabled = true;
		 }
private: System::Void systemSet_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
	this->timer1->Enabled = false;
		 }
private: System::Void button_commuTest_Click(System::Object^  sender, System::EventArgs^  e) {
	this->p_comBase->ipAdd = this->textBox2->Text;
	this->p_comBase->ipAdd2 = this->textBox3->Text;
	this->p_comBase->opcWriteData[25] = true; 
	this->p_comBase->opcWriteData[26] = rand(); 
	this->p_comBase->opcWriteData[SINGLE_OPC_NUM + 25] = true;  
	this->p_comBase->opcWriteData[SINGLE_OPC_NUM + 26] = rand(); 
	
	 this->p_comBase->gRInit = 1;
	 this->p_comBase->gOpcOperation = READ_WRITE_OPC;
	 this->p_comBase->gOpcDataId   = IDR_OTHER;
	 this->p_comBase->gOpcDataId   |= IDW_OTHER;
	sendTest = 1;
	
	ReleaseSemaphore( this->p_comBase->semaphore,1,NULL);
	

}
public: BOOL FindProcess()
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
		if(stricmp( "osk.exe" ,exeFileName)==0)
		{
			return true;
		}
		bMore = ::Process32Next(hProcessSnap, &pe32);
	}
	return false;
}
public: void showKeyBoard() {
	if( FindProcess () )
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

private: System::Void textBox7_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		showKeyBoard();
		 }
};
}
