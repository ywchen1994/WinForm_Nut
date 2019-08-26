#pragma once
#include<opencv2\opencv.hpp>
#include <opencv2\highgui.hpp>
#include"CapFromCam.h"
typedef CapFromCam FlyCam;
 FlyCam Cam;
 static Mat frame;
namespace WinForm_Nut {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Threading;
	using namespace System::IO;
	using namespace System::IO::Ports;
	using namespace std;
	/// <summary>
	/// MyForm 的摘要
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO:  在此加入建構函式程式碼
			//
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	protected:
	private: System::Windows::Forms::GroupBox^  groupBox1;

	private: System::Windows::Forms::Button^  btn_Connect;
	private: System::IO::Ports::SerialPort^  serialPort1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Button^  btn_DisConnect;
	private: System::ComponentModel::IContainer^  components;

	private:
		Thread^ mthread;
	private: System::Windows::Forms::ComboBox^  cBox_Radar;
	private: System::Windows::Forms::CheckBox^  ckBox_CW;
	private: System::Windows::Forms::CheckBox^  ckBox_CCW;
	private: System::Windows::Forms::Button^  btn_Stop;
	private: System::Windows::Forms::Button^  btn_Start;

			 bool isCamOpen = false;
			 uint counter = 0;
	private: System::Windows::Forms::Button^  btnCapture;
			 bool isMotorStop = false;
			 /// <summary>
			 /// 設計工具所需的變數。
			 /// </summary>

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
		/// </summary>
			 void InitializeComponent(void)
			 {
				 this->components = (gcnew System::ComponentModel::Container());
				 this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
				 this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
				 this->btn_DisConnect = (gcnew System::Windows::Forms::Button());
				 this->btn_Connect = (gcnew System::Windows::Forms::Button());
				 this->serialPort1 = (gcnew System::IO::Ports::SerialPort(this->components));
				 this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
				 this->ckBox_CW = (gcnew System::Windows::Forms::CheckBox());
				 this->ckBox_CCW = (gcnew System::Windows::Forms::CheckBox());
				 this->btn_Stop = (gcnew System::Windows::Forms::Button());
				 this->btn_Start = (gcnew System::Windows::Forms::Button());
				 this->cBox_Radar = (gcnew System::Windows::Forms::ComboBox());
				 this->btnCapture = (gcnew System::Windows::Forms::Button());
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
				 this->groupBox1->SuspendLayout();
				 this->groupBox2->SuspendLayout();
				 this->SuspendLayout();
				 // 
				 // pictureBox1
				 // 
				 this->pictureBox1->Location = System::Drawing::Point(8, 1);
				 this->pictureBox1->Name = L"pictureBox1";
				 this->pictureBox1->Size = System::Drawing::Size(1024, 1024);
				 this->pictureBox1->TabIndex = 0;
				 this->pictureBox1->TabStop = false;
				 // 
				 // groupBox1
				 // 
				 this->groupBox1->Controls->Add(this->btnCapture);
				 this->groupBox1->Controls->Add(this->btn_DisConnect);
				 this->groupBox1->Controls->Add(this->btn_Connect);
				 this->groupBox1->Location = System::Drawing::Point(1063, 12);
				 this->groupBox1->Name = L"groupBox1";
				 this->groupBox1->Size = System::Drawing::Size(268, 139);
				 this->groupBox1->TabIndex = 1;
				 this->groupBox1->TabStop = false;
				 this->groupBox1->Text = L"Camera";
				 // 
				 // btn_DisConnect
				 // 
				 this->btn_DisConnect->Location = System::Drawing::Point(152, 30);
				 this->btn_DisConnect->Name = L"btn_DisConnect";
				 this->btn_DisConnect->Size = System::Drawing::Size(75, 23);
				 this->btn_DisConnect->TabIndex = 2;
				 this->btn_DisConnect->Text = L"Disconnect";
				 this->btn_DisConnect->UseVisualStyleBackColor = true;
				 this->btn_DisConnect->Click += gcnew System::EventHandler(this, &MyForm::btn_DisConnect_Click);
				 // 
				 // btn_Connect
				 // 
				 this->btn_Connect->Location = System::Drawing::Point(31, 30);
				 this->btn_Connect->Name = L"btn_Connect";
				 this->btn_Connect->Size = System::Drawing::Size(75, 23);
				 this->btn_Connect->TabIndex = 1;
				 this->btn_Connect->Text = L"Connect";
				 this->btn_Connect->UseVisualStyleBackColor = true;
				 this->btn_Connect->Click += gcnew System::EventHandler(this, &MyForm::btn_Connect_Click);
				 // 
				 // serialPort1
				 // 
				 this->serialPort1->BaudRate = 57600;
				 this->serialPort1->DataReceived += gcnew System::IO::Ports::SerialDataReceivedEventHandler(this, &MyForm::serialPort1_DataReceived);
				 // 
				 // groupBox2
				 // 
				 this->groupBox2->Controls->Add(this->ckBox_CW);
				 this->groupBox2->Controls->Add(this->ckBox_CCW);
				 this->groupBox2->Controls->Add(this->btn_Stop);
				 this->groupBox2->Controls->Add(this->btn_Start);
				 this->groupBox2->Controls->Add(this->cBox_Radar);
				 this->groupBox2->Location = System::Drawing::Point(1063, 172);
				 this->groupBox2->Name = L"groupBox2";
				 this->groupBox2->Size = System::Drawing::Size(268, 109);
				 this->groupBox2->TabIndex = 2;
				 this->groupBox2->TabStop = false;
				 this->groupBox2->Text = L"StepMotor";
				 // 
				 // ckBox_CW
				 // 
				 this->ckBox_CW->AutoSize = true;
				 this->ckBox_CW->Checked = true;
				 this->ckBox_CW->CheckState = System::Windows::Forms::CheckState::Checked;
				 this->ckBox_CW->Location = System::Drawing::Point(12, 88);
				 this->ckBox_CW->Name = L"ckBox_CW";
				 this->ckBox_CW->Size = System::Drawing::Size(43, 16);
				 this->ckBox_CW->TabIndex = 8;
				 this->ckBox_CW->Text = L"CW";
				 this->ckBox_CW->UseVisualStyleBackColor = true;
				 this->ckBox_CW->CheckedChanged += gcnew System::EventHandler(this, &MyForm::ckBox_CW_CheckedChanged);
				 // 
				 // ckBox_CCW
				 // 
				 this->ckBox_CCW->AutoSize = true;
				 this->ckBox_CCW->Location = System::Drawing::Point(12, 66);
				 this->ckBox_CCW->Name = L"ckBox_CCW";
				 this->ckBox_CCW->Size = System::Drawing::Size(51, 16);
				 this->ckBox_CCW->TabIndex = 8;
				 this->ckBox_CCW->Text = L"CCW";
				 this->ckBox_CCW->UseVisualStyleBackColor = true;
				 this->ckBox_CCW->CheckedChanged += gcnew System::EventHandler(this, &MyForm::ckBox_CCW_CheckedChanged);
				 // 
				 // btn_Stop
				 // 
				 this->btn_Stop->Location = System::Drawing::Point(179, 19);
				 this->btn_Stop->Name = L"btn_Stop";
				 this->btn_Stop->Size = System::Drawing::Size(75, 40);
				 this->btn_Stop->TabIndex = 7;
				 this->btn_Stop->Text = L"Stop";
				 this->btn_Stop->UseVisualStyleBackColor = true;
				 this->btn_Stop->Click += gcnew System::EventHandler(this, &MyForm::btn_Stop_Click);
				 // 
				 // btn_Start
				 // 
				 this->btn_Start->Location = System::Drawing::Point(95, 19);
				 this->btn_Start->Name = L"btn_Start";
				 this->btn_Start->Size = System::Drawing::Size(68, 40);
				 this->btn_Start->TabIndex = 6;
				 this->btn_Start->Text = L"Start";
				 this->btn_Start->UseVisualStyleBackColor = true;
				 this->btn_Start->Click += gcnew System::EventHandler(this, &MyForm::btn_Start_Click);
				 // 
				 // cBox_Radar
				 // 
				 this->cBox_Radar->FormattingEnabled = true;
				 this->cBox_Radar->Location = System::Drawing::Point(12, 30);
				 this->cBox_Radar->Name = L"cBox_Radar";
				 this->cBox_Radar->Size = System::Drawing::Size(77, 20);
				 this->cBox_Radar->TabIndex = 5;
				 this->cBox_Radar->DropDown += gcnew System::EventHandler(this, &MyForm::cBox_Radar_DropDown);
				 // 
				 // btnCapture
				 // 
				 this->btnCapture->Location = System::Drawing::Point(57, 70);
				 this->btnCapture->Name = L"btnCapture";
				 this->btnCapture->Size = System::Drawing::Size(156, 59);
				 this->btnCapture->TabIndex = 3;
				 this->btnCapture->Text = L"Save Image";
				 this->btnCapture->UseVisualStyleBackColor = true;
				 this->btnCapture->Click += gcnew System::EventHandler(this, &MyForm::btnCapture_Click);
				 // 
				 // MyForm
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->ClientSize = System::Drawing::Size(1378, 1031);
				 this->Controls->Add(this->groupBox2);
				 this->Controls->Add(this->groupBox1);
				 this->Controls->Add(this->pictureBox1);
				 this->Name = L"MyForm";
				 this->Text = L"MyForm";
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
				 this->groupBox1->ResumeLayout(false);
				 this->groupBox2->ResumeLayout(false);
				 this->groupBox2->PerformLayout();
				 this->ResumeLayout(false);

			 }
#pragma endregion
	private:void ThreadGetImage()
	{
		while (isCamOpen)
		{
			time_t t1 = clock();
			frame = Cam.getImage();
			time_t t2 = clock();
			float time = (float)(t2 - t1) / CLK_TCK;
			//cout << time << endl;
			ShowImage(pictureBox1, frame);
		
		}
		Cam.close();
	}
	private: System::Void btn_Connect_Click(System::Object^  sender, System::EventArgs^  e) {
		isCamOpen = Cam.open(0);
		mthread = gcnew Thread(gcnew ThreadStart(this, &MyForm::ThreadGetImage));
		mthread->Start();
	}
	private:delegate void SetImageDelegate(PictureBox^object, Bitmap^ _img);
	private:void SetThreadImage(PictureBox^obj, Bitmap^ _img)
	{
		if (obj->InvokeRequired)
		{
			SetImageDelegate ^ d = gcnew SetImageDelegate(this, &MyForm::SetThreadImage);
			Invoke(d, gcnew cli::array<Object^>{obj, _img});
		}
		else
		{
			obj->Image = _img;
		}
	}
	public:void ShowImage(System::Windows::Forms::PictureBox^ PBox, cv::Mat Image)
	{

		Mat image_Temp;
		switch (Image.type())
		{
		case CV_8UC3:
			Image.copyTo(image_Temp);
			break;
		case CV_8UC1:
			cvtColor(Image, image_Temp, CV_GRAY2RGB);
			break;
		default:
			break;
		}
		if (image_Temp.empty())return;
		if (image_Temp.cols > PBox->Width || image_Temp.rows > PBox->Height)
		{
			resize(image_Temp, image_Temp, cv::Size(PBox->Width, PBox->Height));
		}

		Bitmap ^ bmpimg = gcnew Bitmap(image_Temp.cols, image_Temp.rows, System::Drawing::Imaging::PixelFormat::Format24bppRgb);
		System::Drawing::Imaging::BitmapData^ data = bmpimg->LockBits(System::Drawing::Rectangle(0, 0, image_Temp.cols, image_Temp.rows), System::Drawing::Imaging::ImageLockMode::WriteOnly, System::Drawing::Imaging::PixelFormat::Format24bppRgb);
		Byte* dstData = reinterpret_cast<Byte*>(data->Scan0.ToPointer());

		unsigned char* srcData = image_Temp.data;


		for (int row = 0; row < data->Height; ++row)
		{
			memcpy(reinterpret_cast<void*>(&dstData[row*data->Stride]), reinterpret_cast<void*>(&srcData[row*image_Temp.step]), image_Temp.cols*image_Temp.channels());
		}

		bmpimg->UnlockBits(data);
		SetThreadImage(PBox, bmpimg);

		GC::Collect();
	}
	private: System::Void btn_DisConnect_Click(System::Object^  sender, System::EventArgs^  e) {
		isCamOpen = false;
	}
	private: System::Void cBox_Radar_DropDown(System::Object^  sender, System::EventArgs^  e) {
		cBox_Radar->Items->Clear();
		cli::array<System::String^>^ Port = SerialPort::GetPortNames();
		cBox_Radar->Items->AddRange(Port);
	}
	private: System::Void serialPort1_DataReceived(System::Object^  sender, System::IO::Ports::SerialDataReceivedEventArgs^  e) {
		System::String ^ str = serialPort1->ReadLine();
		if (str == "Done\r" && !isMotorStop)
		{
			Mat img=frame;
			cout << counter << endl;
			counter++;
			serialPort1->WriteLine("start");
		}
	}
	private: System::Void ckBox_CCW_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		if (ckBox_CCW->Checked)
			ckBox_CW->Checked = false;
		if (!ckBox_CCW->Checked && !ckBox_CW->Checked)
			ckBox_CCW->Checked = true;
		if (CheckSerialPortConnect())
			serialPort1->WriteLine("CCW");
	}
	private: System::Void ckBox_CW_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		if (ckBox_CW->Checked)
			ckBox_CCW->Checked = false;
		if (!ckBox_CCW->Checked && !ckBox_CW->Checked)
			ckBox_CW->Checked = true;
		if (CheckSerialPortConnect())
			serialPort1->WriteLine("C W");
	}
	private: System::Void btn_Start_Click(System::Object^  sender, System::EventArgs^  e) {
		if (CheckSerialPortConnect())
			serialPort1->WriteLine("start");
		isMotorStop = false;
	}
	private: System::Void btn_Stop_Click(System::Object^  sender, System::EventArgs^  e) {
		if (CheckSerialPortConnect())
			serialPort1->WriteLine("stop");
		isMotorStop = true;
	}
	private:bool CheckSerialPortConnect()
	{
		if (!serialPort1->IsOpen)
		{
			System::String ^str = cBox_Radar->Text;
			if (str != "")
			{
				serialPort1->PortName = cBox_Radar->Text;
				serialPort1->Open();
				return true;
			}
			else
			{
				MessageBox::Show("Plz Select ComPort");
				return false;
			}
		}
	}


private: System::Void btnCapture_Click(System::Object^  sender, System::EventArgs^  e) {
	
	if (!frame.empty())
	{
		Mat image = frame.clone();
		string SavePath = ".\\ImageData\\" + to_string(counter) + ".jpg";
		imwrite(SavePath, image);
		counter++;
	}
}
};
}
