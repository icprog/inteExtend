#pragma once

namespace Inte_extend {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// operationStep ժҪ
	/// </summary>
	public ref class operationStep : public System::Windows::Forms::Form
	{
	public:
		operationStep(void)
		{
			InitializeComponent();
			//
			//TODO: �ڴ˴���ӹ��캯������
			//
		}

	protected:
		/// <summary>
		/// ������������ʹ�õ���Դ��
		/// </summary>
		~operationStep()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button6;
	protected: 
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Label^  label1;
 private: Int32 wid,hei;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(operationStep::typeid));
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// button6
			// 
			System::Drawing::Rectangle workingRectangle = Screen::PrimaryScreen->WorkingArea;
			this->wid = workingRectangle.Width - 10;
			this->hei =  workingRectangle.Height - 10;

			this->button6->Font = (gcnew System::Drawing::Font(L"����", 14.25F, System::Drawing::FontStyle::Bold));
			this->button6->ForeColor = System::Drawing::Color::Black;
			this->button6->Location = System::Drawing::Point(this->wid-150,this->hei - 110);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(120,30 );
			this->button6->TabIndex = 12;
			this->button6->Text = L"ȷ  ��";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &operationStep::button6_Click);
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"����", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->textBox1->HideSelection = false;
			this->textBox1->Location = System::Drawing::Point(53, 80);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(this->wid-100,this->hei - 250);
			this->textBox1->TabIndex = 10;
			this->textBox1->Text = resources->GetString(L"textBox1.Text");
			this->textBox1->SelectionStart = 0;
			this->textBox1->SelectionLength = 0;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(53, this->hei - 120);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(202, 71);
			this->pictureBox1->TabIndex = 11;
			this->pictureBox1->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"���뺲īë��", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label1->ForeColor = System::Drawing::Color::Red;
			this->label1->Location = System::Drawing::Point(this->wid / 3 - 20, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(356, 48);
			this->label1->TabIndex = 9;
			this->label1->Text = L"�����ǲ�������";
			// 
			// operationStep
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(this->wid, this->hei);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"operationStep";
			this->Text = L"��������";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->Hide();
				 this->Close();
			 }
};
}
