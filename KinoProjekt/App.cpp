#include "App.h"
#include "MainFrame.h"
#include <wx/wx.h>

wxIMPLEMENT_APP(App);

bool App::OnInit()
{
	MainFrame* mainFrame = new MainFrame("Kino");
	mainFrame->Show();
	mainFrame->SetClientSize(1280,720);
	mainFrame->SetMinClientSize(wxSize(1280, 720));
	mainFrame->SetMaxClientSize(wxSize(1280, 720));
	mainFrame->Center();
	return true;
}