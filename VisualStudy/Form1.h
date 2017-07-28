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
	using namespace System::IO::Ports;
	//using namespace System.IO.Ports

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
	private: System::Windows::Forms::TabControl^  tabcontrol;
	protected: 

	protected: 

	private: System::Windows::Forms::TabPage^  Calculate;


	protected:


	private: System::Windows::Forms::Button^  P14443_Btn1;
	private: System::Windows::Forms::SplitContainer^  splitContainer1;
	private: System::Windows::Forms::RichTextBox^  P14443_Text1;
	private: Microsoft::VisualBasic::PowerPacks::ShapeContainer^  shapeContainer2;
	private: Microsoft::VisualBasic::PowerPacks::LineShape^  lineShape2;
	private: System::Windows::Forms::ComboBox^  P14443_Cbox1;
	private: System::Windows::Forms::Label^  P14443_Lab1;
	private: System::Windows::Forms::TabPage^  Endurance;

	private: System::IO::Ports::SerialPort^  serialport;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::SplitContainer^  splitContainer2;
	private: System::Windows::Forms::Label^  Endurance_label2;
	private: System::Windows::Forms::Label^  Endurance_label1;
	private: System::Windows::Forms::Label^  Endurance_label5;
	private: System::Windows::Forms::Label^  Endurance_label4;
	private: System::Windows::Forms::Label^  Endurance_label3;
	private: System::Windows::Forms::ComboBox^  Endurance_comboBox3;
	private: System::Windows::Forms::ComboBox^  Endurance_comboBox2;
	private: System::Windows::Forms::ComboBox^  Endurance_comboBox1;
	private: System::Windows::Forms::ComboBox^  Endurance_comboBox5;


	private: System::Windows::Forms::ComboBox^  Endurance_comboBox4;
	private: System::Windows::Forms::Button^  endurance_openport;
	private: System::Windows::Forms::Label^  endurance_label6;

	private: System::Windows::Forms::RichTextBox^  TestText;







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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->P14443_Text1 = (gcnew System::Windows::Forms::RichTextBox());
			this->shapeContainer2 = (gcnew Microsoft::VisualBasic::PowerPacks::ShapeContainer());
			this->lineShape2 = (gcnew Microsoft::VisualBasic::PowerPacks::LineShape());
			this->P14443_Cbox1 = (gcnew System::Windows::Forms::ComboBox());
			this->P14443_Lab1 = (gcnew System::Windows::Forms::Label());
			this->tabcontrol = (gcnew System::Windows::Forms::TabControl());
			this->Calculate = (gcnew System::Windows::Forms::TabPage());
			this->P14443_Btn1 = (gcnew System::Windows::Forms::Button());
			this->Endurance = (gcnew System::Windows::Forms::TabPage());
			this->TestText = (gcnew System::Windows::Forms::RichTextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->splitContainer2 = (gcnew System::Windows::Forms::SplitContainer());
			this->endurance_label6 = (gcnew System::Windows::Forms::Label());
			this->Endurance_label5 = (gcnew System::Windows::Forms::Label());
			this->Endurance_label4 = (gcnew System::Windows::Forms::Label());
			this->Endurance_label3 = (gcnew System::Windows::Forms::Label());
			this->Endurance_label2 = (gcnew System::Windows::Forms::Label());
			this->Endurance_label1 = (gcnew System::Windows::Forms::Label());
			this->endurance_openport = (gcnew System::Windows::Forms::Button());
			this->Endurance_comboBox5 = (gcnew System::Windows::Forms::ComboBox());
			this->Endurance_comboBox4 = (gcnew System::Windows::Forms::ComboBox());
			this->Endurance_comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->Endurance_comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->Endurance_comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->serialport = (gcnew System::IO::Ports::SerialPort(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			this->tabcontrol->SuspendLayout();
			this->Calculate->SuspendLayout();
			this->Endurance->SuspendLayout();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer2))->BeginInit();
			this->splitContainer2->Panel1->SuspendLayout();
			this->splitContainer2->Panel2->SuspendLayout();
			this->splitContainer2->SuspendLayout();
			this->SuspendLayout();
			// 
			// splitContainer1
			// 
			resources->ApplyResources(this->splitContainer1, L"splitContainer1");
			this->splitContainer1->Name = L"splitContainer1";
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->Controls->Add(this->P14443_Text1);
			this->splitContainer1->Panel1->Controls->Add(this->shapeContainer2);
			this->splitContainer1->Panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::splitContainer1_Panel1_Paint);
			// 
			// splitContainer1.Panel2
			// 
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
			this->lineShape2->Name = L"lineShape2";
			resources->ApplyResources(this->lineShape2, L"lineShape2");
			// 
			// P14443_Cbox1
			// 
			resources->ApplyResources(this->P14443_Cbox1, L"P14443_Cbox1");
			this->P14443_Cbox1->FormattingEnabled = true;
			this->P14443_Cbox1->Items->AddRange(gcnew cli::array< System::Object^  >(7) {resources->GetString(L"P14443_Cbox1.Items"), 
				resources->GetString(L"P14443_Cbox1.Items1"), resources->GetString(L"P14443_Cbox1.Items2"), resources->GetString(L"P14443_Cbox1.Items3"), 
				resources->GetString(L"P14443_Cbox1.Items4"), resources->GetString(L"P14443_Cbox1.Items5"), resources->GetString(L"P14443_Cbox1.Items6")});
			this->P14443_Cbox1->Name = L"P14443_Cbox1";
			this->P14443_Cbox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::P14443_Cbox1_SelectedIndexChanged);
			// 
			// P14443_Lab1
			// 
			resources->ApplyResources(this->P14443_Lab1, L"P14443_Lab1");
			this->P14443_Lab1->Name = L"P14443_Lab1";
			// 
			// tabcontrol
			// 
			this->tabcontrol->Controls->Add(this->Calculate);
			this->tabcontrol->Controls->Add(this->Endurance);
			resources->ApplyResources(this->tabcontrol, L"tabcontrol");
			this->tabcontrol->Name = L"tabcontrol";
			this->tabcontrol->SelectedIndex = 0;
			// 
			// Calculate
			// 
			this->Calculate->Controls->Add(this->splitContainer1);
			this->Calculate->Controls->Add(this->P14443_Btn1);
			resources->ApplyResources(this->Calculate, L"Calculate");
			this->Calculate->Name = L"Calculate";
			this->Calculate->UseVisualStyleBackColor = true;
			this->Calculate->Click += gcnew System::EventHandler(this, &Form1::Pg14443_Click);
			// 
			// P14443_Btn1
			// 
			resources->ApplyResources(this->P14443_Btn1, L"P14443_Btn1");
			this->P14443_Btn1->Name = L"P14443_Btn1";
			this->P14443_Btn1->UseVisualStyleBackColor = true;
			this->P14443_Btn1->Click += gcnew System::EventHandler(this, &Form1::P14443_Btn1_Click);
			// 
			// Endurance
			// 
			this->Endurance->Controls->Add(this->TestText);
			this->Endurance->Controls->Add(this->groupBox1);
			resources->ApplyResources(this->Endurance, L"Endurance");
			this->Endurance->Name = L"Endurance";
			this->Endurance->UseVisualStyleBackColor = true;
			this->Endurance->Click += gcnew System::EventHandler(this, &Form1::Endurance_Click);
			// 
			// TestText
			// 
			resources->ApplyResources(this->TestText, L"TestText");
			this->TestText->Name = L"TestText";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->splitContainer2);
			resources->ApplyResources(this->groupBox1, L"groupBox1");
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->TabStop = false;
			// 
			// splitContainer2
			// 
			resources->ApplyResources(this->splitContainer2, L"splitContainer2");
			this->splitContainer2->Name = L"splitContainer2";
			// 
			// splitContainer2.Panel1
			// 
			this->splitContainer2->Panel1->Controls->Add(this->endurance_label6);
			this->splitContainer2->Panel1->Controls->Add(this->Endurance_label5);
			this->splitContainer2->Panel1->Controls->Add(this->Endurance_label4);
			this->splitContainer2->Panel1->Controls->Add(this->Endurance_label3);
			this->splitContainer2->Panel1->Controls->Add(this->Endurance_label2);
			this->splitContainer2->Panel1->Controls->Add(this->Endurance_label1);
			this->splitContainer2->Panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::splitContainer2_Panel1_Paint);
			// 
			// splitContainer2.Panel2
			// 
			this->splitContainer2->Panel2->Controls->Add(this->endurance_openport);
			this->splitContainer2->Panel2->Controls->Add(this->Endurance_comboBox5);
			this->splitContainer2->Panel2->Controls->Add(this->Endurance_comboBox4);
			this->splitContainer2->Panel2->Controls->Add(this->Endurance_comboBox3);
			this->splitContainer2->Panel2->Controls->Add(this->Endurance_comboBox2);
			this->splitContainer2->Panel2->Controls->Add(this->Endurance_comboBox1);
			// 
			// endurance_label6
			// 
			resources->ApplyResources(this->endurance_label6, L"endurance_label6");
			this->endurance_label6->Name = L"endurance_label6";
			// 
			// Endurance_label5
			// 
			resources->ApplyResources(this->Endurance_label5, L"Endurance_label5");
			this->Endurance_label5->Name = L"Endurance_label5";
			// 
			// Endurance_label4
			// 
			resources->ApplyResources(this->Endurance_label4, L"Endurance_label4");
			this->Endurance_label4->Name = L"Endurance_label4";
			// 
			// Endurance_label3
			// 
			resources->ApplyResources(this->Endurance_label3, L"Endurance_label3");
			this->Endurance_label3->Name = L"Endurance_label3";
			// 
			// Endurance_label2
			// 
			resources->ApplyResources(this->Endurance_label2, L"Endurance_label2");
			this->Endurance_label2->Name = L"Endurance_label2";
			// 
			// Endurance_label1
			// 
			resources->ApplyResources(this->Endurance_label1, L"Endurance_label1");
			this->Endurance_label1->Name = L"Endurance_label1";
			// 
			// endurance_openport
			// 
			resources->ApplyResources(this->endurance_openport, L"endurance_openport");
			this->endurance_openport->Name = L"endurance_openport";
			this->endurance_openport->UseVisualStyleBackColor = true;
			this->endurance_openport->Click += gcnew System::EventHandler(this, &Form1::endurance_openport_Click);
			// 
			// Endurance_comboBox5
			// 
			resources->ApplyResources(this->Endurance_comboBox5, L"Endurance_comboBox5");
			this->Endurance_comboBox5->FormattingEnabled = true;
			this->Endurance_comboBox5->Items->AddRange(gcnew cli::array< System::Object^  >(3) {resources->GetString(L"Endurance_comboBox5.Items"), 
				resources->GetString(L"Endurance_comboBox5.Items1"), resources->GetString(L"Endurance_comboBox5.Items2")});
			this->Endurance_comboBox5->Name = L"Endurance_comboBox5";
			// 
			// Endurance_comboBox4
			// 
			resources->ApplyResources(this->Endurance_comboBox4, L"Endurance_comboBox4");
			this->Endurance_comboBox4->FormattingEnabled = true;
			this->Endurance_comboBox4->Items->AddRange(gcnew cli::array< System::Object^  >(3) {resources->GetString(L"Endurance_comboBox4.Items"), 
				resources->GetString(L"Endurance_comboBox4.Items1"), resources->GetString(L"Endurance_comboBox4.Items2")});
			this->Endurance_comboBox4->Name = L"Endurance_comboBox4";
			// 
			// Endurance_comboBox3
			// 
			resources->ApplyResources(this->Endurance_comboBox3, L"Endurance_comboBox3");
			this->Endurance_comboBox3->FormattingEnabled = true;
			this->Endurance_comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(4) {resources->GetString(L"Endurance_comboBox3.Items"), 
				resources->GetString(L"Endurance_comboBox3.Items1"), resources->GetString(L"Endurance_comboBox3.Items2"), resources->GetString(L"Endurance_comboBox3.Items3")});
			this->Endurance_comboBox3->Name = L"Endurance_comboBox3";
			// 
			// Endurance_comboBox2
			// 
			resources->ApplyResources(this->Endurance_comboBox2, L"Endurance_comboBox2");
			this->Endurance_comboBox2->FormattingEnabled = true;
			this->Endurance_comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(5) {resources->GetString(L"Endurance_comboBox2.Items"), 
				resources->GetString(L"Endurance_comboBox2.Items1"), resources->GetString(L"Endurance_comboBox2.Items2"), resources->GetString(L"Endurance_comboBox2.Items3"), 
				resources->GetString(L"Endurance_comboBox2.Items4")});
			this->Endurance_comboBox2->Name = L"Endurance_comboBox2";
			// 
			// Endurance_comboBox1
			// 
			resources->ApplyResources(this->Endurance_comboBox1, L"Endurance_comboBox1");
			this->Endurance_comboBox1->FormattingEnabled = true;
			this->Endurance_comboBox1->Name = L"Endurance_comboBox1";
			// 
			// serialport
			// 
			this->serialport->Parity = System::IO::Ports::Parity::Odd;
			// 
			// Form1
			// 
			this->AllowDrop = true;
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			resources->ApplyResources(this, L"$this");
			this->AutoValidate = System::Windows::Forms::AutoValidate::EnableAllowFocusChange;
			this->Controls->Add(this->tabcontrol);
			this->HelpButton = true;
			this->Name = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			this->tabcontrol->ResumeLayout(false);
			this->Calculate->ResumeLayout(false);
			this->Calculate->PerformLayout();
			this->Endurance->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			this->splitContainer2->Panel1->ResumeLayout(false);
			this->splitContainer2->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer2))->EndInit();
			this->splitContainer2->ResumeLayout(false);
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
private: System::Void Endurance_Click(System::Object^  sender, System::EventArgs^  e) {
			
		 }
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 array<String^>^ serialPorts = nullptr;
			 String^ port;
			 serialPorts=serialport->GetPortNames();
			 for each(port in serialPorts)
			 {
				 Endurance_comboBox1->Items->Add(port);
			 }
		 }
private: System::Void splitContainer2_Panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		 }
private: System::Void endurance_openport_Click(System::Object^  sender, System::EventArgs^  e) {				
			 try
			 {
				if(endurance_openport->Text=="打开串口")
				{
					//Endurance_comboBox1->Items.Count
					serialport->PortName=Endurance_comboBox1->Text;
					serialport->BaudRate=Convert::ToInt32(Endurance_comboBox2->Text,10);
					serialport->DataBits=Convert::ToInt32(Endurance_comboBox3->Text,10);
					
					if(Endurance_comboBox5->Text=="Odd")
						serialport->Parity=Parity::Odd;
					else if(Endurance_comboBox5->Text=="Even")
						serialport->Parity=Parity::Even;
					else
						serialport->Parity=Parity::None;
					
					if(Endurance_comboBox4->Text=="1")
						serialport->StopBits=StopBits::One;
					else if(Endurance_comboBox4->Text=="1.5")
						serialport->StopBits=StopBits::OnePointFive;
					else
						serialport->StopBits=StopBits::Two;
					serialport->Open();
					//serialport->Write("Test");
					endurance_openport->Text="关闭串口";
				}
				else
				{
					serialport->Close();
					//serialport->Write("Test");
					endurance_openport->Text="打开串口";
				}
				
			 }
			 catch(...)
			 {
				endurance_openport->Text="打开串口";
			 }
			 



		 }
};
}


