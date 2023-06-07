#include "MainFrame.h"

MainFrame::MainFrame(const wxString& title): wxFrame(nullptr,wxID_ANY,title)
{
	mainPanel = new wxPanel(this, wxID_ANY);

	panel0 = new wxPanel(mainPanel,wxID_ANY,wxPoint(0,0), wxSize(1280, 100));
	panel0->SetBackgroundColour(wxColor(0, 0, 0));
	panel1 = new wxPanel(mainPanel,wxID_ANY, wxPoint(0, 200), wxSize(1280, 420));
	panel1->SetBackgroundColour(wxColor(255, 255, 255));
	panel2 = new wxPanel(mainPanel, wxID_ANY, wxPoint(0, 600), wxSize(1280, 200));
	panel2->SetBackgroundColour(wxColor(0, 0, 0));

	staticText0 = new wxStaticText(panel0, wxID_ANY, "Kino", wxDefaultPosition, wxSize(400, -1), wxALIGN_CENTER_HORIZONTAL);
	staticText0->SetFont(wxFont(60, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
	staticText0->SetForegroundColour(wxColor(40, 126, 75));

	wxInitAllImageHandlers();
	wxImage image(wxT("image/kino.png"));
	if (image.IsOk())
	{
		wxSize panel_size = panel1->GetSize();
		wxImage scaled_image = image.Scale(panel_size.GetWidth(), panel_size.GetHeight(), wxIMAGE_QUALITY_HIGH);
		wxBitmap bitmap(scaled_image);
		bitmap_image = new wxStaticBitmap(panel1, wxID_ANY, bitmap, wxDefaultPosition);
	}

	panel2Sizer = new wxBoxSizer(wxHORIZONTAL);
	panel2->SetSizer(panel2Sizer);

	button0 = new wxButton(panel2, wxID_ANY, "REPERTUAR", wxPoint(50, 50), wxSize(180, 100));
	button0->Bind(wxEVT_BUTTON, &MainFrame::OnButton0Clicked, this, wxID_ANY);
	button0->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
	button1 = new wxButton(panel2, wxID_ANY, "KUP BILET", wxPoint(400, 600), wxSize(180, 100));
	button1->Bind(wxEVT_BUTTON, &MainFrame::OnButton1Clicked, this, wxID_ANY);
	button1->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
	button2= new wxButton(panel2, wxID_ANY, "TWOJE BILETY", wxPoint(850, 600), wxSize(180,100));
	button2->Bind(wxEVT_BUTTON, &MainFrame::OnButton2Clicked, this, wxID_ANY);
	button2->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
	button3 = new wxButton(panel2, wxID_ANY, "KONTAKT", wxPoint(850, 600), wxSize(180, 100));
	button3->Bind(wxEVT_BUTTON, &MainFrame::OnButton3Clicked, this, wxID_ANY);
	button3->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));

	panel2Sizer->Add(button0, 20, wxALL, 50);
	panel2Sizer->Add(button1, 20, wxALL, 50);
	panel2Sizer->Add(button2, 20, wxALL, 50);
	panel2Sizer->Add(button3, 20, wxALL, 50);

	mainSizer = new wxBoxSizer(wxVERTICAL);
	mainSizer->Add(panel0, 0, wxEXPAND);
	mainSizer->Add(panel1, 0, wxEXPAND);
	mainSizer->Add(panel2, 0, wxEXPAND);
	mainPanel->SetSizer(mainSizer);

	mainPanel->Fit();

	SetSize(wxSize(1280, 720));
}

void MainFrame::OnButton0Clicked(wxCommandEvent& evt)
{
	repFrame = new RepFrame("Repertuar");
	repFrame->Show();
	repFrame->SetClientSize(1280, 720);
	repFrame->SetMaxClientSize(wxSize(1280, 720));
	repFrame->Center();
	Close();
}

void MainFrame::OnButton1Clicked(wxCommandEvent& evt)
{
	TicketFrame* ticketFrame = new TicketFrame("Kup Bilet");
	ticketFrame->Show();
	ticketFrame->SetClientSize(1280, 720);
	ticketFrame->SetMaxClientSize(wxSize(1280, 720));
	ticketFrame->Center();
	Close();
}

void MainFrame::OnButton2Clicked(wxCommandEvent& evt)
{
	YourTicketFrame* yourticketFrame = new YourTicketFrame("Twoje Bilety");
	yourticketFrame->Show();
	yourticketFrame->SetClientSize(1280, 720);
	yourticketFrame->SetMaxClientSize(wxSize(1280, 720));
	yourticketFrame->Center();
	Close();
}

void MainFrame::OnButton3Clicked(wxCommandEvent& evt)
{
	contactFrame = new ContactFrame("Kontakt");
	contactFrame->Show();
	contactFrame->SetClientSize(640, 310);
	contactFrame->SetMaxClientSize(wxSize(640, 310));
	contactFrame->Center();
}
