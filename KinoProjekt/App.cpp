#include "App.h"
#include "MainFrame.h"
#include <wx/wx.h>

wxIMPLEMENT_APP(App);

DatabaseManager* dbManager;

bool App::OnInit()
{
	dbManager = new DatabaseManager();
	MainFrame* mainFrame = new MainFrame("Kino");
	mainFrame->Show();
	mainFrame->SetClientSize(1280,720);
	mainFrame->SetMinClientSize(wxSize(1280, 720));
	mainFrame->SetMaxClientSize(wxSize(1280, 720));
	mainFrame->Center();
	return true;
}

int App::OnExit()
{
	delete dbManager;

	return wxApp::OnExit();
}

