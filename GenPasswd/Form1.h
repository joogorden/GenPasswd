#pragma once
#include "about.h"


namespace GenPasswd {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Сводка для Form1
	///
	/// Внимание! При изменении имени этого класса необходимо также изменить
	///          свойство имени файла ресурсов ("Resource File Name") для средства компиляции управляемого ресурса,
	///          связанного со всеми файлами с расширением .resx, от которых зависит данный класс. В противном случае,
	///          конструкторы не смогут правильно работать с локализованными
	///          ресурсами, сопоставленными данной форме.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			userstring = gcnew String("");
			checkedListBox1->Items->Insert(0, gcnew String("абвгдеёжзиклмнопрстуфхцчшщъыьэюя"));
			checkedListBox1->Items->Insert(0, gcnew String("АБВГДЕЁЖЗИКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"));
			checkedListBox1->Items->Insert(0, gcnew String("~!@#$%^&*()_+|"));
			checkedListBox1->Items->Insert(0, gcnew String("abcdefghijklmnopqrstuvwxyz"));
			checkedListBox1->Items->Insert(0, gcnew String("ABCDEFGHIJKLMNOPQRSTUVWXYZ"));
			checkedListBox1->Items->Insert(0, gcnew String("0123456789"));
			IniRead();
			m_cmax = 0;
			m_cmin = 0xFF;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Form1()
		{
			IniWrite();
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;
	protected: 
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::CheckedListBox^  checkedListBox1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;


	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->checkedListBox1 = (gcnew System::Windows::Forms::CheckedListBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->BeginInit();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 12);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(400, 20);
			this->textBox1->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(138, 48);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Новый";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(12, 51);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {65536, 0, 0, 0});
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(120, 20);
			this->numericUpDown1->TabIndex = 2;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {50, 0, 0, 0});
			this->numericUpDown1->ValueChanged += gcnew System::EventHandler(this, &Form1::numericUpDown1_ValueChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 35);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(94, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Кол-во символов";
			// 
			// checkedListBox1
			// 
			this->checkedListBox1->CheckOnClick = true;
			this->checkedListBox1->FormattingEnabled = true;
			this->checkedListBox1->Location = System::Drawing::Point(12, 77);
			this->checkedListBox1->Name = L"checkedListBox1";
			this->checkedListBox1->Size = System::Drawing::Size(400, 79);
			this->checkedListBox1->TabIndex = 4;
			this->checkedListBox1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::checkedListBox1_MouseUp);
			this->checkedListBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::checkedListBox1_SelectedIndexChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(9, 159);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(166, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Набор символов пользователя";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(12, 175);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(400, 20);
			this->textBox2->TabIndex = 6;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &Form1::textBox2_TextChanged);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(256, 48);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 7;
			this->button2->Text = L"О ...";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(337, 48);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 8;
			this->button3->Text = L"Закрыть";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(426, 208);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->checkedListBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->textBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MGN_Gen_passwd";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::Form1_KeyDown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 Random^ randObj= gcnew Random;
				 UInt32 numb = numericUpDown1->Value.ToUInt64(numericUpDown1->Value);
				 wchar_t str0[65536];
				 m_cmax = 0;
				 m_cmin = 0xFFFF;
				 bool OffAllCheck = true;
				 for(int i=0; i<checkedListBox1->Items->Count; i++)
				 {
					 if(checkedListBox1->GetItemCheckState(i)==CheckState::Checked)
					 {
						 MaxMin(checkedListBox1->Items[i]->ToString());
						 OffAllCheck = false;
					 }
				 }

				 if(userstring->Length != 0)
				 {
					 OffAllCheck = false;
					 MaxMin(userstring);
				 }

				 if(OffAllCheck == true)
				 {
					 MessageBox::Show("Нужно выбрать диаппазон символов", "",
						 MessageBoxButtons::OK, MessageBoxIcon::Asterisk);

					 return;
				 }

				 for(UInt32 i=0;i<numb;i++)
				 {
					 wchar_t ch;
					 bool diap = false;
					 int q=-1;
					 bool ok = false;
					 while(ok == false)
					 {
						 ch = randObj->Next(m_cmin, m_cmax+1);
						 for(int i=0; i<checkedListBox1->Items->Count; i++)
						 {
							 if(checkedListBox1->GetItemCheckState(i)==CheckState::Checked)
							 {
								 String ^str = checkedListBox1->Items[i]->ToString();
								 if(find(str, ch)!=-1) ok = true;
							 }
							 if(ok) break;
						 }
						 if(ok) break;
						 if(userstring->Length != 0)
						 {
							 if(find(userstring, ch)!=-1) ok = true;
						 }
					 }
					 str0[i] = ch;
				 }
				 str0[numb] = 0;
 				 String ^str2 = gcnew String(str0,0,numb);
				 textBox1->Text = str2;
				 Clipboard::SetDataObject(str2, true);
			 }
	private: System::Void numericUpDown1_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
//				 this->textBox1->Text = this->numericUpDown1->Value.ToString();
			 }
public:

	int find(String ^str, wchar_t ch)
	{
		for(int i=0; i<str->Length; i++)
		{
			wchar_t wch = (wchar_t)str[i];
			if(ch == (wchar_t)str[i])
				return i;
		}
		return -1;
	}
public:
	unsigned int m_cmax, m_cmin;
	void MaxMin(String ^str)
	{
		for(int i=0; i<str->Length; i++)
		{
			m_cmin = min(m_cmin, (unsigned int)str[i]);
			m_cmax = max(m_cmax, (unsigned int)str[i]);
		}
		return;
	}

	String ^userstring;
	int IniRead(void)
	{
		String^ fileName = "MGNGenPasswd.ini";
		try 
		{
			StreamReader^ din = File::OpenText(fileName);
			int count = 0;
			userstring = din->ReadLine();
			String ^str;

			numericUpDown1->Text = din->ReadLine();
			int Count = Convert::ToInt16(din->ReadLine());
			if(Count==3)
			for(int i=0; i<Count; i++)
			{
				int state = Convert::ToInt16(din->ReadLine());
				checkedListBox1->SetItemChecked(i, (bool)state);
			}
			textBox2->Text = userstring;
			din->Close();
		}
		catch (Exception^ e)
		{
			if (dynamic_cast<FileNotFoundException^>(e))
				Console::WriteLine("file '{0}' not found", fileName);
			else
				Console::WriteLine("problem reading file '{0}'", fileName);
		}
		return 0;
	}

	int IniWrite(void)
	{
		String^ fileName = "MGNGenPasswd.ini";
		StreamWriter^ sw = gcnew StreamWriter(fileName);
		sw->WriteLine(userstring);
		sw->WriteLine(numericUpDown1->Text);
		sw->WriteLine(checkedListBox1->Items->Count);
		for(int i=0; i<checkedListBox1->Items->Count; i++)
		{
			sw->WriteLine((int)checkedListBox1->GetItemChecked(i));
		}
		sw->Close();
		return 0;
	}
private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 userstring = textBox2->Text;
		 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 about^ f = gcnew about();   
			 this->Enabled = false;
			 //this->Hide();
			 f->ShowDialog();
			 this->Enabled = true;//
			 this->Show();
		 }
private: System::Void checkedListBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void checkedListBox1_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		 }
private: System::Void Form1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			 Close();
		 }
};
}

