#include "ContactFrame.h"

ContactFrame::ContactFrame(const wxString& title) : wxDialog(nullptr, wxID_ANY, title)
{
	titleFont = wxFont(30, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
	textFont = wxFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
	buttonFont = wxFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);

	wxColour panel0Color(0, 0, 0); 
	wxColour panel1Color(32, 32, 32); 
	wxColour staticText0Color(40, 126, 75); 
	wxColour textColors(255, 255, 255);

	mainPanel = new wxPanel(this, wxID_ANY);

	panel0 = new wxPanel(mainPanel, wxID_ANY, wxPoint(0, 0), wxSize(640, 70));
	panel0->SetBackgroundColour(panel0Color);

	panel1 = new wxPanel(mainPanel, wxID_ANY, wxPoint(0, 0), wxSize(640, 240));
	panel1->SetBackgroundColour(panel1Color);

	staticText0 = new wxStaticText(panel0, wxID_ANY, "Kontakt", wxPoint(0, 14), wxSize(200, -1), wxALIGN_CENTER_HORIZONTAL);
	staticText0->SetFont(titleFont);
	staticText0->SetForegroundColour(staticText0Color);

	emailText = new wxStaticText(panel1, wxID_ANY, "Email: projekt@projekt.com", wxPoint(30,15), wxDefaultSize);
	emailText->SetFont(textFont);
	emailText->SetForegroundColour(textColors);

	staticText2 = new wxStaticText(panel1, wxID_ANY, "Telefon: 123 123 123", wxPoint(30, 60), wxDefaultSize);
	staticText2->SetFont(textFont);
	staticText2->SetForegroundColour(textColors);

	staticText3 = new wxStaticText(panel1, wxID_ANY, "Autorzy: Hubert Kordula", wxPoint(30, 105), wxDefaultSize);
	staticText3->SetFont(textFont);
	staticText3->SetForegroundColour(textColors);

	staticText4 = new wxStaticText(panel1, wxID_ANY, "Eryk Dziewoñski", wxPoint(280, 105), wxDefaultSize);
	staticText4->SetFont(textFont);
	staticText4->SetForegroundColour(textColors);

	staticText5 = new wxStaticText(panel1, wxID_ANY, "Jakub Sado", wxPoint(108, 140), wxDefaultSize);
	staticText5->SetFont(textFont);
	staticText5->SetForegroundColour(textColors);

	staticText6 = new wxStaticText(panel1, wxID_ANY, "Micha³ Radziukiewicz", wxPoint(280, 140), wxDefaultSize);
	staticText6->SetFont(textFont);
	staticText6->SetForegroundColour(textColors);

	closeButton = new wxButton(panel1, wxID_ANY, "Zamknij", wxPoint(500,180), wxSize(100, 40));
	closeButton->Bind(wxEVT_BUTTON, &ContactFrame::OnCloseButtonClicked, this);
	closeButton->SetFont(buttonFont);

	mainSizer = new wxBoxSizer(wxVERTICAL);
	mainSizer->Add(panel0, 0, wxEXPAND);
	mainSizer->Add(panel1, 1, wxEXPAND);
	mainPanel->SetSizer(mainSizer);

	mainSizer->Fit(this);
}

void ContactFrame::OnCloseButtonClicked(wxCommandEvent& event)
{
	Close();
}
