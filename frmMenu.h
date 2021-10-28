#pragma once
#include "frmRankings.h"
#include "frmCredits.h"
#include "MyForm.h"

namespace FormsTemplate {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for frmMenu
	/// </summary>
	public ref class frmMenu : public System::Windows::Forms::Form
	{
	public:
		frmMenu(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmMenu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btnStart;
	private: System::Windows::Forms::Button^ btnRankings;
	private: System::Windows::Forms::Button^ btnExit;



	private: System::Windows::Forms::Button^ btnCredits;

	protected:

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnStart = (gcnew System::Windows::Forms::Button());
			this->btnRankings = (gcnew System::Windows::Forms::Button());
			this->btnExit = (gcnew System::Windows::Forms::Button());
			this->btnCredits = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(79, 27);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(435, 73);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Reclickadores";
			// 
			// btnStart
			// 
			this->btnStart->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnStart->Location = System::Drawing::Point(225, 146);
			this->btnStart->Name = L"btnStart";
			this->btnStart->Size = System::Drawing::Size(135, 53);
			this->btnStart->TabIndex = 1;
			this->btnStart->Text = L"Iniciar";
			this->btnStart->UseVisualStyleBackColor = true;
			this->btnStart->Click += gcnew System::EventHandler(this, &frmMenu::btnStart_Click);
			// 
			// btnRankings
			// 
			this->btnRankings->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnRankings->Location = System::Drawing::Point(225, 227);
			this->btnRankings->Name = L"btnRankings";
			this->btnRankings->Size = System::Drawing::Size(135, 53);
			this->btnRankings->TabIndex = 2;
			this->btnRankings->Text = L"Rankings";
			this->btnRankings->UseVisualStyleBackColor = true;
			this->btnRankings->Click += gcnew System::EventHandler(this, &frmMenu::btnRankings_Click);
			// 
			// btnExit
			// 
			this->btnExit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnExit->Location = System::Drawing::Point(225, 385);
			this->btnExit->Name = L"btnExit";
			this->btnExit->Size = System::Drawing::Size(135, 53);
			this->btnExit->TabIndex = 4;
			this->btnExit->Text = L"Salir";
			this->btnExit->UseVisualStyleBackColor = true;
			this->btnExit->Click += gcnew System::EventHandler(this, &frmMenu::btnExit_Click);
			// 
			// btnCredits
			// 
			this->btnCredits->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCredits->Location = System::Drawing::Point(225, 308);
			this->btnCredits->Name = L"btnCredits";
			this->btnCredits->Size = System::Drawing::Size(135, 53);
			this->btnCredits->TabIndex = 3;
			this->btnCredits->Text = L"Créditos";
			this->btnCredits->UseVisualStyleBackColor = true;
			this->btnCredits->Click += gcnew System::EventHandler(this, &frmMenu::btnCredits_Click);
			// 
			// frmMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(589, 477);
			this->Controls->Add(this->btnCredits);
			this->Controls->Add(this->btnExit);
			this->Controls->Add(this->btnRankings);
			this->Controls->Add(this->btnStart);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"frmMenu";
			this->Text = L"frmMenu";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	private: System::Void btnExit_Click(System::Object^ sender, System::EventArgs^ e) {
		Close();
	}
	private: System::Void btnRankings_Click(System::Object^ sender, System::EventArgs^ e) {
		frmRankings^ frm = gcnew frmRankings();
		this->Visible = false;
		frm->ShowDialog();
		this->Visible = true;
		delete frm;
	}
	private: System::Void btnCredits_Click(System::Object^ sender, System::EventArgs^ e) {
		frmCredits^ frm = gcnew frmCredits();
		this->Visible = false;
		frm->ShowDialog();
		this->Visible = true;
		delete frm;
	}
	private: System::Void btnStart_Click(System::Object^ sender, System::EventArgs^ e) {
		MyForm^ frm = gcnew MyForm();
		this->Visible = false;
		frm->ShowDialog();
		this->Visible = true;
		delete frm;
	}
};
}
