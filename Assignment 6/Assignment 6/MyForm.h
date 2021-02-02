#include "BTree.h"
#pragma once

const int x = 5;
namespace Assignment6 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		//const int x = 5;
		
		BTree *bTree=new BTree(5);
	public:
		MyForm(void)
		{
			InitializeComponent();
			/*bTree->init(4);*/
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		//BTree tree;
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RichTextBox^  richDisplayOutput;
	private: System::Windows::Forms::TextBox^  txtInsert;
	protected:

	private: System::Windows::Forms::Button^  btnInsert;
	private: System::Windows::Forms::TextBox^  txtDelete;
	private: System::Windows::Forms::Button^  btnDelete;


	private: System::Windows::Forms::Label^  label1;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->richDisplayOutput = (gcnew System::Windows::Forms::RichTextBox());
			this->txtInsert = (gcnew System::Windows::Forms::TextBox());
			this->btnInsert = (gcnew System::Windows::Forms::Button());
			this->txtDelete = (gcnew System::Windows::Forms::TextBox());
			this->btnDelete = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// richDisplayOutput
			// 
			this->richDisplayOutput->Font = (gcnew System::Drawing::Font(L"Calisto MT", 17.856F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richDisplayOutput->Location = System::Drawing::Point(41, 246);
			this->richDisplayOutput->Name = L"richDisplayOutput";
			this->richDisplayOutput->Size = System::Drawing::Size(1376, 568);
			this->richDisplayOutput->TabIndex = 0;
			this->richDisplayOutput->TabStop = false;
			this->richDisplayOutput->Text = L"";
			// 
			// txtInsert
			// 
			this->txtInsert->Font = (gcnew System::Drawing::Font(L"Calisto MT", 17.856F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtInsert->Location = System::Drawing::Point(154, 133);
			this->txtInsert->Name = L"txtInsert";
			this->txtInsert->Size = System::Drawing::Size(172, 43);
			this->txtInsert->TabIndex = 1;
			// 
			// btnInsert
			// 
			this->btnInsert->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btnInsert->Font = (gcnew System::Drawing::Font(L"Calisto MT", 17.856F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnInsert->ForeColor = System::Drawing::Color::White;
			this->btnInsert->Location = System::Drawing::Point(404, 133);
			this->btnInsert->Name = L"btnInsert";
			this->btnInsert->Size = System::Drawing::Size(136, 44);
			this->btnInsert->TabIndex = 2;
			this->btnInsert->Text = L"Insert";
			this->btnInsert->UseVisualStyleBackColor = false;
			this->btnInsert->Click += gcnew System::EventHandler(this, &MyForm::btnInsert_Click);
			// 
			// txtDelete
			// 
			this->txtDelete->Font = (gcnew System::Drawing::Font(L"Calisto MT", 17.856F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtDelete->Location = System::Drawing::Point(629, 134);
			this->txtDelete->Name = L"txtDelete";
			this->txtDelete->Size = System::Drawing::Size(172, 43);
			this->txtDelete->TabIndex = 3;
			// 
			// btnDelete
			// 
			this->btnDelete->BackColor = System::Drawing::Color::Red;
			this->btnDelete->Font = (gcnew System::Drawing::Font(L"Calisto MT", 17.856F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnDelete->ForeColor = System::Drawing::Color::White;
			this->btnDelete->Location = System::Drawing::Point(879, 133);
			this->btnDelete->Name = L"btnDelete";
			this->btnDelete->Size = System::Drawing::Size(134, 44);
			this->btnDelete->TabIndex = 4;
			this->btnDelete->Text = L"Delete";
			this->btnDelete->UseVisualStyleBackColor = false;
			this->btnDelete->Click += gcnew System::EventHandler(this, &MyForm::btnDelete_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Calisto MT", 24.192F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(536, 27);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(142, 49);
			this->label1->TabIndex = 3;
			this->label1->Text = L"B-Tree";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->ClientSize = System::Drawing::Size(1479, 808);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btnDelete);
			this->Controls->Add(this->btnInsert);
			this->Controls->Add(this->txtDelete);
			this->Controls->Add(this->txtInsert);
			this->Controls->Add(this->richDisplayOutput);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnInsert_Click(System::Object^  sender, System::EventArgs^  e) {
		try{
			if (txtInsert->Text == "")
			{
				MessageBox::Show("No value entered");
				return;
			}
			else{
				bTree->insertKey(Convert::ToInt32(txtInsert->Text));
				richDisplayOutput->Text = "";
				bTree->displayTree(richDisplayOutput);
				txtInsert->Text = "";
				txtDelete->Text = "";
				txtInsert->Focus();
			}
		}
		catch (Exception ^ex){
			MessageBox::Show(ex->Message);
		}
	}
private: System::Void btnDelete_Click(System::Object^  sender, System::EventArgs^  e) {
	try{
		if (txtDelete->Text == "")
		{
			MessageBox::Show("No value entered");
			return;
		}
		else{
			bTree->deleteKey(Convert::ToInt32(txtDelete->Text));
			richDisplayOutput->Text = "";
			bTree->displayTree(richDisplayOutput);
			txtInsert->Text = "";
			txtDelete->Text = "";
			txtInsert->Focus();

		}
	}
	catch (Exception ^ex){
		MessageBox::Show(ex->Message);
	}
}
};
}
