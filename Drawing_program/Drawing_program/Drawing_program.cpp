#include "Drawing_program.h"


using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]

void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Drawing_program::Drawing_program form;
	Application::Run(%form);
}
