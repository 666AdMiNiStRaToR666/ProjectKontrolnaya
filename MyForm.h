#pragma once

#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <msclr/marshal_cppstd.h>

namespace ProjectKontrolnaya {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Summary for MyForm
    /// </summary>
    public ref class MyForm : public System::Windows::Forms::Form
    {
    public:
        MyForm(void)
        {
            InitializeComponent();
        }

    protected:
        ~MyForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private: System::Windows::Forms::Button^ btnConvert;
    private: System::Windows::Forms::TextBox^ txtInput;
    private: System::Windows::Forms::Label^ lblOutput;

           /// <summary>
           /// Required designer variable.
           /// </summary>
           System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
           /// <summary>
           /// Required method for Designer support - do not modify
           /// the contents of this method with the code editor.
           /// </summary>
           void InitializeComponent(void)
           {
               this->btnConvert = (gcnew System::Windows::Forms::Button());
               this->txtInput = (gcnew System::Windows::Forms::TextBox());
               this->lblOutput = (gcnew System::Windows::Forms::Label());
               this->SuspendLayout();
               // 
               // btnConvert
               // 
               this->btnConvert->Location = System::Drawing::Point(16, 47);
               this->btnConvert->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
               this->btnConvert->Name = L"btnConvert";
               this->btnConvert->Size = System::Drawing::Size(133, 28);
               this->btnConvert->TabIndex = 0;
               this->btnConvert->Text = L"Convert";
               this->btnConvert->UseVisualStyleBackColor = true;
               this->btnConvert->Click += gcnew System::EventHandler(this, &MyForm::btnConvert_Click);
               // 
               // txtInput
               // 
               this->txtInput->Location = System::Drawing::Point(16, 15);
               this->txtInput->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
               this->txtInput->Name = L"txtInput";
               this->txtInput->Size = System::Drawing::Size(532, 22);
               this->txtInput->TabIndex = 1;
               // 
               // lblOutput
               // 
               this->lblOutput->AutoSize = true;
               this->lblOutput->Location = System::Drawing::Point(16, 86);
               this->lblOutput->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
               this->lblOutput->Name = L"lblOutput";
               this->lblOutput->Size = System::Drawing::Size(0, 16);
               this->lblOutput->TabIndex = 2;
               // 
               // MyForm
               // 
               this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
               this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
               this->ClientSize = System::Drawing::Size(565, 124);
               this->Controls->Add(this->lblOutput);
               this->Controls->Add(this->txtInput);
               this->Controls->Add(this->btnConvert);
               this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
               this->MaximizeBox = false;
               this->Name = L"MyForm";
               this->Text = L"Number to Hex String Converter";
               this->ResumeLayout(false);
               this->PerformLayout();

           }
#pragma endregion

    private:
        System::Void btnConvert_Click(System::Object^ sender, System::EventArgs^ e) {
            std::vector<unsigned char> numbers;
            std::string inputString = msclr::interop::marshal_as<std::string>(txtInput->Text);

            std::istringstream iss(inputString);
            std::string token;
            while (std::getline(iss, token, ' ')) {
                unsigned int number;
                std::stringstream ss(token);
                ss >> std::hex >> number;
                numbers.push_back(static_cast<unsigned char>(number));
            }

            std::stringstream ss;
            for (const auto& number : numbers) {
                ss << std::setw(2) << std::setfill('0') << std::hex << std::uppercase << static_cast<int>(number);
            }

            std::string hexString = ss.str();

            lblOutput->Text = gcnew String(hexString.c_str());
        }

    };
}
//10.	Преобразование чисел в строки. Напишите функцию, которая преобразует коллекцию 
//8-битных целых чисел (массив или вектор) в строку с шестнадцатеричными их представлениями. 
//Функция должна поддерживать вывод символов в верхнем и в нижнем регистрах.