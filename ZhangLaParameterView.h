#pragma once
#include "public.h"
//#include "goujian.h"
namespace Inte_extend {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// ZhangLaParameterView ժҪ
	/// </summary>
	public ref class ZhangLaParameterView : public System::Windows::Forms::Form
	{
	public:
		ZhangLaParameterView(void)
		{
			InitializeComponent();
			//
			//TODO: �ڴ˴���ӹ��캯������
			//
			More_check=0;
		}

	protected:
		/// <summary>
		/// ������������ʹ�õ���Դ��
		/// </summary>
		~ZhangLaParameterView()
		{
			if (components)
			{
				delete components;
			}
			//delete m_goujian;
		}
    public:  static array<String^>^ str_dataGrid = gcnew array<String^>(zhangLaSeqNum * 9); 

	protected: 
	//private: static goujian^ m_goujian=gcnew goujian;
	public:  System::Boolean More_check;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column7;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column8;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column9;


















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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(ZhangLaParameterView::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column9 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"����", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->button1->Location = System::Drawing::Point(593, 321);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(104, 46);
			this->button1->TabIndex = 1;
			this->button1->Text = L"ȷ  ��";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ZhangLaParameterView::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"����", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label1->ForeColor = System::Drawing::Color::Red;
			this->label1->Location = System::Drawing::Point(27, 334);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(376, 16);
			this->label1->TabIndex = 2;
			this->label1->Text = L"��ܰ��ʾ��������ʼǰ���뼼����Ա��ϸȷ�ϲ�����";
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(9) {this->Column1, 
				this->Column2, this->Column3, this->Column4, this->Column5, this->Column6, this->Column7, this->Column8, this->Column9});
			this->dataGridView1->Location = System::Drawing::Point(30, 24);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersWidth = 4;
			this->dataGridView1->RowTemplate->Height = 23;
			this->dataGridView1->Size = System::Drawing::Size(706, 291);
			this->dataGridView1->TabIndex = 3;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"����";
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			this->Column1->Width = 60;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"�׺�";
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			this->Column2->Width = 60;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"��ʼ�г�(1)";
			this->Column3->Name = L"Column3";
			this->Column3->ReadOnly = true;
			this->Column3->Width = 80;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"��ʼ�г�(2)";
			this->Column4->Name = L"Column4";
			this->Column4->ReadOnly = true;
			this->Column4->Width = 80;
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"�ڶ��г�(1)";
			this->Column5->Name = L"Column5";
			this->Column5->ReadOnly = true;
			this->Column5->Width = 80;
			// 
			// Column6
			// 
			this->Column6->HeaderText = L"�ڶ��г�(2)";
			this->Column6->Name = L"Column6";
			this->Column6->ReadOnly = true;
			this->Column6->Width = 80;
			// 
			// Column7
			// 
			this->Column7->HeaderText = L"�����г�(1)";
			this->Column7->Name = L"Column7";
			this->Column7->ReadOnly = true;
			this->Column7->Width = 80;
			// 
			// Column8
			// 
			this->Column8->HeaderText = L"�����г�(2)";
			this->Column8->Name = L"Column8";
			this->Column8->ReadOnly = true;
			this->Column8->Width = 90;
			// 
			// Column9
			// 
			this->Column9->HeaderText = L"�����쳤��";
			this->Column9->Name = L"Column9";
			this->Column9->ReadOnly = true;
			this->Column9->Width = 90;
			// 
			// ZhangLaParameterView
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(761, 386);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"ZhangLaParameterView";
			this->Text = L"��������ȷ��";
			this->Shown += gcnew System::EventHandler(this, &ZhangLaParameterView::ZhangLaParameterView_Shown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Hide();
		}
	private: System::Void ZhangLaParameterView_Shown(System::Object^  sender, System::EventArgs^  e) {
				 dataGridView1->Rows->Clear();
				/* StreamReader pfile("..//Debug//1.dat");
				 System::String^ temp;
				 temp=pfile.ReadLine();
				 pfile.Close();
				 //array<System::Char^>^ strList;
					 temp=temp->Split((wchar_t)"%");
				 MessageBox::Show(temp);
				 float::Parse(temp);*/
				 for(int i= 0; i < zhangLaSeqNum; i++){
					 if(  str_dataGrid[i *9 + 0] == nullptr || (str_dataGrid[i *9 + 0] &&  str_dataGrid[i *9 + 0]->ToString()->Length <= 0 ))
						 break;
					 DataGridViewRow^ dgr = gcnew DataGridViewRow();
					 dgr->CreateCells(dataGridView1);
					 for(int j = 0 ; j < 9; j++){
						dgr->Cells[j]->Value = (this->str_dataGrid[i *9 + j]);
					 }
					dataGridView1->Rows->Add( dgr );

				 }
			 }
};
}
