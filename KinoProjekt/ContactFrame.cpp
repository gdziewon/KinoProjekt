#include "ContactFrame.h"

ContactFrame::ContactFrame(const wxString& title) : wxDialog(nullptr, wxID_ANY, title)
{
	titleFont = wxFont(30, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
	textFont = wxFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
	buttonFont = wxFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);

	mainPanel = new wxPanel(this, wxID_ANY);

	panel0 = new wxPanel(mainPanel, wxID_ANY, wxPoint(0, 0), wxSize(640, 70));
	panel0->SetBackgroundColour(wxColor(0, 0, 0));

	panel1 = new wxPanel(mainPanel, wxID_ANY, wxPoint(0, 0), wxSize(640, 240));
	panel1->SetBackgroundColour(wxColor(128, 128, 128));

	staticText0 = new wxStaticText(panel0, wxID_ANY, "Kontakt", wxPoint(0, 14), wxSize(200, -1), wxALIGN_CENTER_HORIZONTAL);
	staticText0->SetFont(titleFont);
	staticText0->SetForegroundColour(wxColor(40, 126, 75));

	emailText = new wxStaticText(panel1, wxID_ANY, "Email: projekt@projekt.com", wxPoint(30,15), wxDefaultSize);
	emailText->SetFont(textFont);
	emailText->SetForegroundColour(wxColor(0, 0, 0));

	staticText2 = new wxStaticText(panel1, wxID_ANY, "Telefon: 123 123 123", wxPoint(30, 50), wxDefaultSize);
	staticText2->SetFont(textFont);
	staticText2->SetForegroundColour(wxColor(0, 0, 0));

	staticText3 = new wxStaticText(panel1, wxID_ANY, "Autorzy: Hubert Kordula ErykDziewoñski JakubSado Micha³Radziukiewicz", wxPoint(30, 85), wxDefaultSize);
	staticText3->SetFont(textFont);
	staticText3->SetForegroundColour(wxColor(0, 0, 0));

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
