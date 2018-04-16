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
		int x1, y1, x2, y2;
		Graphics^ gr;
		bool flag=false;
		TChart *pFirst;
		TRoot *pCurr;
		int i;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::Button^  button1;
	public:
		TFind *find;
		Drawing_program(void)
		{
			i = 0;
			InitializeComponent();
			gr = CreateGraphics();
			pFirst = nullptr;
			find = new TFind();
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
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(586, 2);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(81, 17);
			this->checkBox1->TabIndex = 0;
			this->checkBox1->Text = L"GOD_MOD";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &Drawing_program::checkBox1_CheckedChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(586, 25);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(80, 22);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Delete";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Visible = false;
			this->button1->Click += gcnew System::EventHandler(this, &Drawing_program::button1_Click);
			// 
			// Drawing_program
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(678, 458);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->checkBox1);
			this->Name = L"Drawing_program";
			this->Text = L"Drawing_program";
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Drawing_program::Drawing_program_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Drawing_program::Drawing_program_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Drawing_program::Drawing_program_MouseUp);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	private: System::Void Drawing_program_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		if (!checkBox1->Checked){
			x1 = x2 = e->X;
			y1 = y2 = e->Y;
			gr->FillEllipse(Brushes::Black, x1 - 2, y1 - 2, 5, 5);
			flag = true;
		}
		else {
			pCurr=pFirst->Excretion(gr,e->X,e->Y);
			
		}
	}
	private: System::Void Drawing_program_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		flag = false;
		if (!checkBox1->Checked) {
			if (pFirst == nullptr) {
				gr->FillEllipse(Brushes::Black, x2 - 2, y2 - 2, 5, 5);
				TPoint *p1 = new TPoint(x1, y1), *p2 = new TPoint(x2, y2);
				pFirst = new TChart(p1, p2);
			}

			else {
				*find = pFirst->Find(x1, x2, y1, y2);
				if (find->pS != nullptr && find->pS->visible == false && find->pE != nullptr && find->pE->visible == false)  find->pE->visible == true;
				else {
					if (find->pS != nullptr && find->pS->visible == false) find->pS = nullptr;
					if (find->pE != nullptr && find->pE->visible == false) find->pE = nullptr;
				}
				if (find->pS == nullptr && find->pE == nullptr) {
					gr->Clear(Color::White);
					pFirst->Draw(gr, Color::Black);
				}

				if (find->pS != nullptr && find->pE != nullptr) {
					TPoint  *p1, *p2;
					if (find->Start == 1) p1 = dynamic_cast<TPoint*>(dynamic_cast<TChart*>(find->pS)->getBegin());
					if (find->Start == 2) p1 = dynamic_cast<TPoint*>(dynamic_cast<TChart*>(find->pS)->getEnd());
					if (find->End == 1) p2 = dynamic_cast<TPoint*>(dynamic_cast<TChart*>(find->pE)->getBegin());
					if (find->End == 2) p2 = dynamic_cast<TPoint*>(dynamic_cast<TChart*>(find->pE)->getEnd());
					if (pFirst->CopyrightedTest(p1->getX(), p1->getY(), p2->getX(), p2->getY())) {
						TChart *tmp = new TChart(p1, p2);
						if (find->End == 1) dynamic_cast<TChart*>(find->pE)->setStart(tmp);
						if (find->End == 2) dynamic_cast<TChart*>(find->pE)->setEnd(tmp);

					}
					gr->Clear(Color::White);
					pFirst->Draw(gr, Color::Black);
					return;
				}
				if (find->pS != nullptr) {
					TPoint  *p1, *p2 = new TPoint(x2, y2);
					if (find->Start == 1) p1 = dynamic_cast<TPoint*>(dynamic_cast<TChart*>(find->pS)->getBegin());
					if (find->Start == 2) p1 = dynamic_cast<TPoint*>(dynamic_cast<TChart*>(find->pS)->getEnd());
					TChart *tmp = new TChart(p2, p1);
					if (find->Start == 1) dynamic_cast<TChart*>(find->pS)->setStart(tmp);
					if (find->Start == 2) dynamic_cast<TChart*>(find->pS)->setEnd(tmp);
					gr->Clear(Color::White);
					pFirst->Draw(gr, Color::Black);
				}
				if (find->pE != nullptr) {
					TPoint  *p1 = new TPoint(x1, y1), *p2;
					if (find->End == 1) p2 = dynamic_cast<TPoint*>(dynamic_cast<TChart*>(find->pE)->getBegin());
					if (find->End == 2) p2 = dynamic_cast<TPoint*>(dynamic_cast<TChart*>(find->pE)->getEnd());
					TChart *tmp = new TChart(p1, p2);
					if (find->End == 1) dynamic_cast<TChart*>(find->pE)->setStart(tmp);
					if (find->End == 2) dynamic_cast<TChart*>(find->pE)->setEnd(tmp);
					gr->Clear(Color::White);
					pFirst->Draw(gr, Color::Black);
				}

			}
		}
	}
	private: System::Void Drawing_program_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		if (flag) {
			gr->DrawLine(Pens::White, x1, y1, x2, y2);
			x2 = e->X;
			y2 = e->Y;
			gr->DrawLine(Pens::Black, x1, y1, x2, y2);
			gr->FillEllipse(Brushes::Black, x1 - 2, y1 - 2, 5, 5);
			if (pFirst!=nullptr)
			pFirst->Draw(gr, Color::Black);
		}
	}
	private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		
		
		if (checkBox1->Checked) { if (pFirst != nullptr) pFirst->Draw(gr, Color::AntiqueWhite); button1->Visible = true; }
			
		else if (pFirst != nullptr) {
			pFirst->Draw(gr, Color::Black);
			button1->Visible = false;
		}
		
	}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	if (pCurr != nullptr) {
		pCurr->visible = false;
		gr->Clear(Color::White);
		pFirst->Draw(gr, Color::AntiqueWhite);
		pCurr = nullptr;
	}
}
};
}
