#pragma once
#include <tchar.h>
#include "Cal.h"
namespace VisualStudy {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Form1 摘要
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^  Pg7816;
	private: System::Windows::Forms::TabPage^  Port;

	protected:

	private: System::Windows::Forms::TabPage^  Pg14443;
	private: System::Windows::Forms::Button^  P14443_Btn1;
	private: System::Windows::Forms::SplitContainer^  splitContainer1;
	private: System::Windows::Forms::RichTextBox^  P14443_Text1;
	private: Microsoft::VisualBasic::PowerPacks::ShapeContainer^  shapeContainer2;
	private: Microsoft::VisualBasic::PowerPacks::LineShape^  lineShape2;
	private: System::Windows::Forms::ComboBox^  P14443_Cbox1;
	private: System::Windows::Forms::Label^  P14443_Lab1;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->P14443_Text1 = (gcnew System::Windows::Forms::RichTextBox());
			this->shapeContainer2 = (gcnew Microsoft::VisualBasic::PowerPacks::ShapeContainer());
			this->lineShape2 = (gcnew Microsoft::VisualBasic::PowerPacks::LineShape());
			this->P14443_Cbox1 = (gcnew System::Windows::Forms::ComboBox());
			this->P14443_Lab1 = (gcnew System::Windows::Forms::Label());
			this->Pg7816 = (gcnew System::Windows::Forms::TabControl());
			this->Pg14443 = (gcnew System::Windows::Forms::TabPage());
			this->P14443_Btn1 = (gcnew System::Windows::Forms::Button());
			this->Port = (gcnew System::Windows::Forms::TabPage());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			this->Pg7816->SuspendLayout();
			this->Pg14443->SuspendLayout();
			this->SuspendLayout();
			// 
			// splitContainer1
			// 
			resources->ApplyResources(this->splitContainer1, L"splitContainer1");
			this->splitContainer1->Name = L"splitContainer1";
			// 
			// splitContainer1.Panel1
			// 
			resources->ApplyResources(this->splitContainer1->Panel1, L"splitContainer1.Panel1");
			this->splitContainer1->Panel1->Controls->Add(this->P14443_Text1);
			this->splitContainer1->Panel1->Controls->Add(this->shapeContainer2);
			this->splitContainer1->Panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::splitContainer1_Panel1_Paint);
			// 
			// splitContainer1.Panel2
			// 
			resources->ApplyResources(this->splitContainer1->Panel2, L"splitContainer1.Panel2");
			this->splitContainer1->Panel2->Controls->Add(this->P14443_Cbox1);
			this->splitContainer1->Panel2->Controls->Add(this->P14443_Lab1);
			// 
			// P14443_Text1
			// 
			resources->ApplyResources(this->P14443_Text1, L"P14443_Text1");
			this->P14443_Text1->Name = L"P14443_Text1";
			this->P14443_Text1->TextChanged += gcnew System::EventHandler(this, &Form1::P14443_Text1_TextChanged);
			// 
			// shapeContainer2
			// 
			resources->ApplyResources(this->shapeContainer2, L"shapeContainer2");
			this->shapeContainer2->Name = L"shapeContainer2";
			this->shapeContainer2->Shapes->AddRange(gcnew cli::array< Microsoft::VisualBasic::PowerPacks::Shape^  >(1) {this->lineShape2});
			this->shapeContainer2->TabStop = false;
			// 
			// lineShape2
			// 
			resources->ApplyResources(this->lineShape2, L"lineShape2");
			this->lineShape2->Name = L"lineShape2";
			// 
			// P14443_Cbox1
			// 
			resources->ApplyResources(this->P14443_Cbox1, L"P14443_Cbox1");
			this->P14443_Cbox1->FormattingEnabled = true;
			this->P14443_Cbox1->Items->AddRange(gcnew cli::array< System::Object^  >(6) {resources->GetString(L"P14443_Cbox1.Items"), 
				resources->GetString(L"P14443_Cbox1.Items1"), resources->GetString(L"P14443_Cbox1.Items2"), resources->GetString(L"P14443_Cbox1.Items3"), 
				resources->GetString(L"P14443_Cbox1.Items4"), resources->GetString(L"P14443_Cbox1.Items5")});
			this->P14443_Cbox1->Name = L"P14443_Cbox1";
			this->P14443_Cbox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::P14443_Cbox1_SelectedIndexChanged);
			// 
			// P14443_Lab1
			// 
			resources->ApplyResources(this->P14443_Lab1, L"P14443_Lab1");
			this->P14443_Lab1->Name = L"P14443_Lab1";
			// 
			// Pg7816
			// 
			resources->ApplyResources(this->Pg7816, L"Pg7816");
			this->Pg7816->Controls->Add(this->Pg14443);
			this->Pg7816->Controls->Add(this->Port);
			this->Pg7816->Name = L"Pg7816";
			this->Pg7816->SelectedIndex = 0;
			// 
			// Pg14443
			// 
			resources->ApplyResources(this->Pg14443, L"Pg14443");
			this->Pg14443->Controls->Add(this->splitContainer1);
			this->Pg14443->Controls->Add(this->P14443_Btn1);
			this->Pg14443->Name = L"Pg14443";
			this->Pg14443->UseVisualStyleBackColor = true;
			this->Pg14443->Click += gcnew System::EventHandler(this, &Form1::Pg14443_Click);
			// 
			// P14443_Btn1
			// 
			resources->ApplyResources(this->P14443_Btn1, L"P14443_Btn1");
			this->P14443_Btn1->Name = L"P14443_Btn1";
			this->P14443_Btn1->UseVisualStyleBackColor = true;
			this->P14443_Btn1->Click += gcnew System::EventHandler(this, &Form1::P14443_Btn1_Click);
			// 
			// Port
			// 
			resources->ApplyResources(this->Port, L"Port");
			this->Port->Name = L"Port";
			this->Port->UseVisualStyleBackColor = true;
			// 
			// Form1
			// 
			resources->ApplyResources(this, L"$this");
			this->AllowDrop = true;
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->AutoValidate = System::Windows::Forms::AutoValidate::EnableAllowFocusChange;
			this->Controls->Add(this->Pg7816);
			this->HelpButton = true;
			this->Name = L"Form1";
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			this->Pg7816->ResumeLayout(false);
			this->Pg14443->ResumeLayout(false);
			this->Pg14443->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
private: void P14443_Print(String ^ tmpstr)
		 {
			 P14443_Lab1->Text=tmpstr;
		 }


private: System::Void Pg14443_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void maskedTextBox1_MaskInputRejected(System::Object^  sender, System::Windows::Forms::MaskInputRejectedEventArgs^  e) {
		 }
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void label1_Click_1(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void label1_Click_2(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void splitContainer1_Panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		 }
private: System::Void P14443_Btn1_Click(System::Object^  sender, System::EventArgs^  e) {
			 String ^tmpstr;
			 Cal caltemp;
			 tmpstr=P14443_Text1->Text;
			 switch(P14443_Cbox1->SelectedIndex)
			 {
			 case 0://ATQA
				 P14443_Lab1->Text=caltemp.Pras_ATQA(tmpstr);
				 break;
			 case 1://ATS
				 P14443_Lab1->Text=caltemp.Pras_ATS(tmpstr);
				 break;
			 case 2://SAK
				 P14443_Lab1->Text=caltemp.Pras_SAK(tmpstr);
				 break;
			 case 3://CRC_14443A
				  P14443_Lab1->Text=caltemp.Pras_CRC14443A(tmpstr);
				  //P14443_Lab1->Text=(tmpstr);
				break;
			 case 4://CRC_14443B
				  P14443_Lab1->Text=caltemp.Pras_CRC14443B(tmpstr);
				 break;
			 case 5:
				  P14443_Lab1->Text=caltemp.Pras_ATR(tmpstr);
				 break;
				
			 default:
				 P14443_Lab1->Text="Do Nothing";
				 break;

			 }

			 
		 }
private: System::Void P14443_Cbox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void P14443_Text1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 String ^tmpstr;
		 P14443_Lab1->Text=((double)(P14443_Text1->Text->Length)/2.0).ToString();
		 }
};
}


