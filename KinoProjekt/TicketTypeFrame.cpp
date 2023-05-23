#include "TicketFrame.h"
#include "TicketTypeFrame.h"

#include <wx/wx.h>
#include <wx/datectrl.h>
#include <wx/dateevt.h>
#include <wx/spinctrl.h>


TicketTypeFrame::TicketTypeFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
	wxPanel* mainPanel = new wxPanel(this, wxID_ANY);
	wxPanel* panel0 = new wxPanel(mainPanel, wxID_ANY, wxDefaultPosition, wxSize(1280, 100));
	panel0->SetBackgroundColour(wxColor(0, 0, 0));
	wxPanel* panel1 = new wxPanel(mainPanel, wxID_ANY, wxDefaultPosition, wxSize(1280, 620));
	panel1->SetBackgroundColour(wxColor(255, 255, 255));

	wxBoxSizer* sizer1 = new wxBoxSizer(wxVERTICAL);

	wxStaticText* staticText0 = new wxStaticText(panel0, wxID_ANY, "Wybierz Rodzaj Biletu", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);
	staticText0->SetFont(wxFont(30, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
	staticText0->SetForegroundColour(wxColor(57, 255, 20));

	wxStaticText* staticText1 = new wxStaticText(panel1, wxID_ANY, "Rodzaj", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_VERTICAL);
	staticText1->SetFont(wxFont(30, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
	staticText1->SetForegroundColour(wxColor(57, 255, 20));
	sizer1->Add(staticText1, 0, wxVERTICAL | wxALL, 10);

	wxStaticText* staticText2 = new wxStaticText(panel1, wxID_ANY, "Iloœæ", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_VERTICAL);
	staticText2->SetFont(wxFont(30, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
	staticText2->SetForegroundColour(wxColor(57, 255, 20));
	sizer1->Add(staticText2, 0, wxVERTICAL | wxALL, 10);

	wxStaticText* staticText3 = new wxStaticText(panel1, wxID_ANY, "Cena(szt)", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_VERTICAL);
	staticText3->SetFont(wxFont(30, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
	staticText3->SetForegroundColour(wxColor(57, 255, 20));
	sizer1->Add(staticText3, 0, wxVERTICAL | wxALL, 10);

	wxStaticText* staticText4 = new wxStaticText(panel1, wxID_ANY, "Normalny", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_VERTICAL);
	staticText4->SetFont(wxFont(30, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
	staticText4->SetForegroundColour(wxColor(57, 255, 20));
	sizer1->Add(staticText4, 0, wxVERTICAL | wxALL, 10);

	wxStaticText* staticText5 = new wxStaticText(panel1, wxID_ANY, "Ulgowy", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_VERTICAL);
	staticText5->SetFont(wxFont(30, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
	staticText5->SetForegroundColour(wxColor(57, 255, 20));
	sizer1->Add(staticText5, 0, wxVERTICAL | wxALL, 10);

	wxSpinCtrl* spinCtrl0 = new wxSpinCtrl(panel1, wxID_ANY, "", wxDefaultPosition, wxDefaultSize);
	spinCtrl0->SetMax(10);
	wxSpinCtrl* spinCtrl1 = new wxSpinCtrl(panel1, wxID_ANY, "", wxDefaultPosition, wxDefaultSize);
	spinCtrl1->SetMax(10);
	sizer1->Add(spinCtrl0, 0, wxCENTER | wxALL, 10);
	sizer1->Add(spinCtrl1, 0, wxCENTER | wxALL, 10);

	

	wxButton* button0 = new wxButton(panel1, wxID_ANY, "WYBÓR MIEJSC", wxDefaultPosition, wxDefaultSize);
	button0->Bind(wxEVT_BUTTON, &TicketTypeFrame::OnButton0Clicked, this, wxID_ANY);
	sizer1->Add(button0, 0, wxCENTER | wxALL, 10);

	panel1->SetSizer(sizer1);

	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
	mainSizer->Add(panel0, 0, wxEXPAND);
	mainSizer->Add(panel1, 1, wxEXPAND);
	mainPanel->SetSizer(mainSizer);

}

void TicketTypeFrame::OnButton0Clicked(wxCommandEvent& evt)
{
	//TicketTypeFrame* tickettypeFrame = new TicketTypeFrame("Wybierz Bilet");
	//tickettypeFrame->Show();
	//tickettypeFrame->Center();
}
