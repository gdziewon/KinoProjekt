#include <wx/wx.h>
#include <wx/statbmp.h>
#include <map>
#include<iomanip>

#include "MainFrame.h"
#include "TicketFrame.h"
#include "RepFrame.h"
#include "ContactFrame.h"
#include "LoginFrame.h"

enum IDs
{
	BUY_TICKET_ID = 2,
	REP_ID = 3,
	CONTACT_ID=4,
	LOGIN_ID=5,
	REGISTER_ID=6
};


MainFrame::MainFrame(const wxString& title): wxFrame(nullptr,wxID_ANY,title)
{
	wxPanel* mainPanel = new wxPanel(this, wxID_ANY);

	wxPanel* panel0 = new wxPanel(mainPanel,wxID_ANY,wxPoint(0,0), wxSize(1280, 100));
	panel0->SetBackgroundColour(wxColor(0, 0, 0));
	wxPanel* panel1 = new wxPanel(mainPanel,wxID_ANY, wxPoint(0, 200), wxSize(1280, 420));
	panel1->SetBackgroundColour(wxColor(255, 255, 255));
	wxPanel* panel2 = new wxPanel(mainPanel, wxID_ANY, wxPoint(0, 600), wxSize(1280, 200));
	panel2->SetBackgroundColour(wxColor(0, 0, 0));

	//panel 0
	wxStaticText* staticText0 = new wxStaticText(panel0, wxID_ANY, "Kino", wxDefaultPosition, wxSize(400, -1), wxALIGN_CENTER_HORIZONTAL);
	staticText0->SetFont(wxFont(60, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
	staticText0->SetForegroundColour(wxColor(57, 255, 20));

	/*
	wxStaticText* staticText1 = new wxStaticText(panel0, 4, "Logowanie", wxPoint(1050,10), wxSize(100, -1), wxALIGN_CENTER_HORIZONTAL);
	staticText1->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
	staticText1->SetForegroundColour(wxColor(255, 255, 255));
	//staticText1->Bind(wxEVT_LEFT_DOWN, &MainFrame::OnLoginClicked, this, LOGIN_ID);

	wxStaticText* staticText2 = new wxStaticText(panel0, 5, "Rejestracja", wxPoint(1050,50), wxSize(100, -1), wxALIGN_CENTER_HORIZONTAL);
	staticText2->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
	staticText2->SetForegroundColour(wxColor(255, 255, 255));
	*/

	//panel 1
	wxInitAllImageHandlers();
	wxImage image("C:/Users/huber/source/repos/KinoProjekt/KinoProjekt/image/kino.png");
	if (image.IsOk())
	{
		wxSize panel_size = panel1->GetSize();
		wxImage scaled_image = image.Scale(panel_size.GetWidth(), panel_size.GetHeight(), wxIMAGE_QUALITY_HIGH);
		wxBitmap bitmap(scaled_image);
		wxStaticBitmap*  bitmap_image = new wxStaticBitmap(panel1, wxID_ANY, bitmap, wxDefaultPosition);
	}

	//panel 2
	wxBoxSizer* panel2Sizer = new wxBoxSizer(wxHORIZONTAL);
	panel2->SetSizer(panel2Sizer);

	wxButton* button0 = new wxButton(panel2, 3, "REPERTUAR", wxPoint(50, 50), wxSize(180, 100));
	button0->Bind(wxEVT_BUTTON, &MainFrame::OnButton0Clicked, this, REP_ID);
	button0->SetFont(wxFont(30, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
	wxButton* button1 = new wxButton(panel2, 2, "KUP BILET", wxPoint(400, 600), wxSize(180, 100));
	button1->Bind(wxEVT_BUTTON, &MainFrame::OnButton1Clicked, this, BUY_TICKET_ID);
	button1->SetFont(wxFont(30, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
	wxButton* button2= new wxButton(panel2, 4, "KONTAKT", wxPoint(850, 600), wxSize(180,100));
	button2->Bind(wxEVT_BUTTON, &MainFrame::OnButton2Clicked, this, CONTACT_ID);
	button2->SetFont(wxFont(30, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));

	panel2Sizer->Add(button0, 20, wxALL, 50);
	panel2Sizer->Add(button1, 20, wxALL, 50);
	panel2Sizer->Add(button2, 20, wxALL, 50);

	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
	mainSizer->Add(panel0, 0, wxEXPAND);
	mainSizer->Add(panel1, 0, wxEXPAND);
	mainSizer->Add(panel2, 0, wxEXPAND);
	mainPanel->SetSizer(mainSizer);

	mainPanel->Fit();

	// Set the window size
	SetSize(wxSize(1280, 720));
	
}

void MainFrame::OnButton0Clicked(wxCommandEvent& evt)
{
	RepFrame* repFrame = new RepFrame("Repertuar");
	repFrame->Show();
	repFrame->SetClientSize(1280, 720);
	repFrame->SetMinClientSize(wxSize(1280, 720));
	repFrame->SetMaxClientSize(wxSize(1280, 720));
	repFrame->Center();
}

void MainFrame::OnButton1Clicked(wxCommandEvent& evt)
{
	TicketFrame* ticketFrame = new TicketFrame("Kup Bilet");
	ticketFrame->Show();
	ticketFrame->SetClientSize(1280, 720);
	ticketFrame->SetMinClientSize(wxSize(1280, 720));
	ticketFrame->SetMaxClientSize(wxSize(1280, 720));
	ticketFrame->Center();
	//Hide();
}

void MainFrame::OnButton2Clicked(wxCommandEvent& evt)
{
	ContactFrame* contactFrame = new ContactFrame("Kontakt");
	contactFrame->Show();
	contactFrame->SetClientSize(640, 310);
	contactFrame->SetMinClientSize(wxSize(640, 310));
	contactFrame->SetMaxClientSize(wxSize(640, 310));
	contactFrame->Center();
}

void MainFrame::OnLoginClicked(wxCommandEvent& evt)
{
	LoginFrame* loginFrame = new LoginFrame("Logowanie");
	loginFrame->Show();
	loginFrame->Center();
}