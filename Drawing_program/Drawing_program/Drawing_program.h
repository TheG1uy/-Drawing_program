#pragma once
#include "Figures.h"
#include  <string>
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
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  actionToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  openToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  deleteLineToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  refreshToolStripMenuItem;

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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->actionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->deleteLineToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->refreshToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(586, 2);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(88, 17);
			this->checkBox1->TabIndex = 0;
			this->checkBox1->Text = L"GOD_MODE";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &Drawing_program::checkBox1_CheckedChanged);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->actionToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(678, 24);
			this->menuStrip1->TabIndex = 2;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// actionToolStripMenuItem
			// 
			this->actionToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->saveToolStripMenuItem,
					this->openToolStripMenuItem, this->deleteLineToolStripMenuItem, this->refreshToolStripMenuItem
			});
			this->actionToolStripMenuItem->Name = L"actionToolStripMenuItem";
			this->actionToolStripMenuItem->Size = System::Drawing::Size(54, 20);
			this->actionToolStripMenuItem->Text = L"Action";
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->saveToolStripMenuItem->Text = L"Save";
			this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &Drawing_program::saveToolStripMenuItem_Click);
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->openToolStripMenuItem->Text = L"Open";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &Drawing_program::openToolStripMenuItem_Click);
			// 
			// deleteLineToolStripMenuItem
			// 
			this->deleteLineToolStripMenuItem->Name = L"deleteLineToolStripMenuItem";
			this->deleteLineToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->deleteLineToolStripMenuItem->Text = L"Delete_Line";
			this->deleteLineToolStripMenuItem->Click += gcnew System::EventHandler(this, &Drawing_program::deleteLineToolStripMenuItem_Click);
			// 
			// refreshToolStripMenuItem
			// 
			this->refreshToolStripMenuItem->Name = L"refreshToolStripMenuItem";
			this->refreshToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->refreshToolStripMenuItem->Text = L"Refresh";
			this->refreshToolStripMenuItem->Click += gcnew System::EventHandler(this, &Drawing_program::refreshToolStripMenuItem_Click);
			// 
			// Drawing_program
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(678, 458);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Drawing_program";
			this->Text = L"Drawing_program";
			this->Load += gcnew System::EventHandler(this, &Drawing_program::Drawing_program_Load);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Drawing_program::Drawing_program_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Drawing_program::Drawing_program_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Drawing_program::Drawing_program_MouseUp);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		string MarshalString(String ^ s) {
			string os;
			using namespace Runtime::InteropServices;
			const char* chars =
				(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
			os = chars;
			Marshal::FreeHGlobal(IntPtr((void*)chars));
			return os;
		}
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
				if (find->pS != nullptr && find->pS->visible == false && find->pE != nullptr && find->pE->visible == false && !(pFirst->Distance(x2, y2) || pFirst->Distance(x1, y1))) {
					find->pS = nullptr;
					find->pE = nullptr;
				}
				else {
					if (find->pS != nullptr && find->pS->visible == false && find->pE == nullptr && !(pFirst->Distance(x2,y2) || pFirst->Distance(x1, y1))) find->pS = nullptr;
					if (find->pE != nullptr && find->pE->visible == false && find->pS == nullptr && !(pFirst->Distance(x2, y2) || pFirst->Distance(x1, y1))) find->pE = nullptr;
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
		
		
		if (checkBox1->Checked) { if (pFirst != nullptr) { pFirst->Draw(gr, Color::Bisque); deleteLineToolStripMenuItem->Enabled = true; } }
			
		else {
			if (pFirst != nullptr) {
				pFirst->Draw(gr, Color::Black);
			}
			deleteLineToolStripMenuItem->Enabled = false;
		}
		
		
	}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	
}
private: System::Void deleteLineToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	if (pCurr != nullptr) {
		pCurr->visible = false;
		gr->Clear(Color::White);
		pFirst->Draw(gr, Color::AntiqueWhite);
		pCurr = nullptr;
	}
}

private: System::Void Drawing_program_Load(System::Object^  sender, System::EventArgs^  e) {
	deleteLineToolStripMenuItem->Enabled = false;
}
private: System::Void saveToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	FILE *f;
	f = fopen("text.txt", "r");
	pFirst->Get_Points("text.txt");

}
private: System::Void openToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	FILE *f;
	//f = fopen("text.txt", "r");
	OpenFileDialog^ dialog = gcnew OpenFileDialog();
	dialog->Filter = "Text files | *.txt; | All Files (*.*) | *.*";
	if (dialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
	  f=fopen(MarshalString(dialog->FileName).c_str(),"r");
	  pFirst = pFirst->CreateFigure(f);
	  gr->Clear(Color::White);
	  pFirst->Draw(gr,Color::Black);
	}
}
private: System::Void refreshToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	if (pFirst != nullptr) {
		pFirst->ClearChart();
		pFirst = nullptr;
	}
	gr->Clear(Color::White);
}
};
}
