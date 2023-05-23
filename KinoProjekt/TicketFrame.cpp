#include "TicketFrame.h"
#include "TicketTypeFrame.h"
#include <wx/wx.h>
#include <wx/datectrl.h>
#include <wx/dateevt.h>

enum IDs
{
	BUY_TICKET_ID = 2,
};

TicketFrame::TicketFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
	wxPanel* mainPanel = new wxPanel(this, wxID_ANY);
	wxPanel* panel0 = new wxPanel(mainPanel, wxID_ANY, wxDefaultPosition, wxSize(1280, 100));
	panel0->SetBackgroundColour(wxColor(0, 0, 0));
	wxPanel* panel1 = new wxPanel(mainPanel, wxID_ANY, wxDefaultPosition, wxSize(1280, 620));
	panel1->SetBackgroundColour(wxColor(255, 255, 255));

	wxBoxSizer* sizer1 = new wxBoxSizer(wxVERTICAL);

	wxStaticText* staticText0 = new wxStaticText(panel0, wxID_ANY, "Kup Bilet", wxPoint(0, 14), wxSize(200, -1), wxALIGN_CENTER_HORIZONTAL);
	staticText0->SetFont(wxFont(30, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
	staticText0->SetForegroundColour(wxColor(57, 255, 20));

	//date
	wxDatePickerCtrl* datePicker = new wxDatePickerCtrl(panel1, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize);
	sizer1->Add(datePicker, 0, wxCENTER | wxALL, 10);
	//movie
	wxArrayString choices;
	choices.Add("Movie 1");
	choices.Add("Movie 2");
	choices.Add("Movie 3");
	choices.Add("Movie 4");
	choices.Add("Movie 5");	
	wxChoice* choice = new wxChoice(panel1, wxID_ANY, wxPoint(10, 50), wxDefaultSize, choices);
	choice->Select(0);
	sizer1->Add(choice, 0, wxCENTER | wxALL, 10);

	//type
	wxArrayString type;
	type.Add("2D");
	type.Add("3D");
	type.Add("4DX");
	wxRadioBox* radiobox = new wxRadioBox(panel1, wxID_ANY, "Typ Seansu", wxDefaultPosition, wxDefaultSize, type);
	sizer1->Add(radiobox, 0, wxCENTER | wxALL, 10);
	//language
	wxArrayString language;
	language.Add("Dubbing PL");
	language.Add("Lektor PL");
	language.Add("Angielski Napisy PL");
	wxListBox* listBox = new wxListBox(panel1, wxID_ANY, wxDefaultPosition, wxDefaultSize, language);
	sizer1->Add(listBox, 0, wxCENTER | wxALL, 10);
	//hours

	wxButton* button0 = new wxButton(panel1, 2, "WYBÓR BILETÓW", wxDefaultPosition, wxDefaultSize);
	button0->Bind(wxEVT_BUTTON, &TicketFrame::OnButton0Clicked, this, BUY_TICKET_ID);
	sizer1->Add(button0, 0, wxCENTER | wxALL, 10);

	panel1->SetSizer(sizer1);

	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
	mainSizer->Add(panel0, 0, wxEXPAND);
	mainSizer->Add(panel1, 1, wxEXPAND);
	mainPanel->SetSizer(mainSizer);

}

void TicketFrame::OnButton0Clicked(wxCommandEvent& evt)
{
	TicketTypeFrame* tickettypeFrame = new TicketTypeFrame("Wybierz Bilet");
	tickettypeFrame->Show();
	tickettypeFrame->SetClientSize(1280, 720);
	tickettypeFrame->SetMinClientSize(wxSize(1280, 720));
	tickettypeFrame->SetMaxClientSize(wxSize(1280, 720));
	tickettypeFrame->Center();
}