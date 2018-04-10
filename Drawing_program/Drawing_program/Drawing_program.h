#pragma once
#include "Figures.h"
namespace Drawing_program {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ Drawing_program
	/// </summary>
	public ref class Drawing_program : public System::Windows::Forms::Form
	{
	public:
		Drawing_program(void)
		{
			TChart p;
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~Drawing_program()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(165, 100);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"label1";
			// 
			// Drawing_program
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(678, 458);
			this->Controls->Add(this->label1);
			this->Name = L"Drawing_program";
			this->Text = L"Drawing_program";
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Drawing_program::Drawing_program_MouseDown);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Drawing_program::Drawing_program_MouseUp);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	private: System::Void Drawing_program_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		label1->Text = "aaaa";
	}
	private: System::Void Drawing_program_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		label1->Text = "dddd";
	}
	};
}
