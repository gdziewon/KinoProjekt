#include "TicketFrame.h"
#include "TicketTypeFrame.h"
#include "SeatFrame.h"

#include <wx/wx.h>
#include <wx/datectrl.h>
#include <wx/dateevt.h>
#include <wx/spinctrl.h>

TicketTypeFrame::TicketTypeFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
    wxPanel* mainPanel = new wxPanel(this, wxID_ANY);
    wxPanel* panel0 = new wxPanel(mainPanel, wxID_ANY, wxDefaultPosition, wxSize(1280, 100));
    panel0->SetBackgroundColour(wxColor(0, 0, 0));
    wxPanel* panel1 = new wxPanel(mainPanel, wxID_ANY, wxDefaultPosition, wxSize(1280, 520));
    panel1->SetBackgroundColour(wxColor(255, 255, 255));
    wxPanel* panel2 = new wxPanel(mainPanel, wxID_ANY, wxDefaultPosition, wxSize(1280, 100));
    panel2->SetBackgroundColour(wxColor(0, 0, 0));

    wxStaticText* staticText0 = new wxStaticText(panel0, wxID_ANY, "Rodzaj Biletów", wxDefaultPosition, wxSize(400, -1), wxALIGN_CENTER_HORIZONTAL);
    staticText0->SetFont(wxFont(60, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    staticText0->SetForegroundColour(wxColor(57, 255, 20));

    wxBoxSizer* sizer1 = new wxBoxSizer(wxVERTICAL);

    wxStaticText* label1 = new wxStaticText(panel1, wxID_ANY, "Rodzaj Biletu", wxPoint(300,100), wxDefaultSize, wxALIGN_CENTER);
    label1->SetFont(wxFont(18, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    label1->SetForegroundColour(wxColor(0, 0, 0));
 

    wxStaticText* label2 = new wxStaticText(panel1, wxID_ANY, "Iloœæ", wxPoint(630, 100), wxDefaultSize, wxALIGN_CENTER);
    label2->SetFont(wxFont(18, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    label2->SetForegroundColour(wxColor(0, 0, 0));


    wxStaticText* label3 = new wxStaticText(panel1, wxID_ANY, "Cena(szt)", wxPoint(860, 100), wxDefaultSize, wxALIGN_CENTER);
    label3->SetFont(wxFont(18, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    label3->SetForegroundColour(wxColor(0, 0, 0));
  

    // Dodanie pierwszego rzêdu
    wxBoxSizer* row1ContainerSizer = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* row1Sizer = new wxBoxSizer(wxHORIZONTAL);

    wxStaticText* staticText4 = new wxStaticText(panel1, wxID_ANY, "Normalny", wxPoint(330, 150), wxDefaultSize, wxALIGN_CENTER);
    staticText4->SetFont(wxFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    staticText4->SetForegroundColour(wxColor(0, 0, 0));

    wxBoxSizer* spinCtrlSizer0 = new wxBoxSizer(wxHORIZONTAL);
    wxSpinCtrl* spinCtrl0 = new wxSpinCtrl(panel1, wxID_ANY, "", wxPoint(630, 150), wxSize(60, 25));
    spinCtrl0->SetMax(10);
    spinCtrl0->SetFont(wxFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));

    wxStaticText* staticText6 = new wxStaticText(panel1, wxID_ANY, "21 z³", wxPoint(890, 150), wxDefaultSize, wxALIGN_CENTER);
    staticText6->SetFont(wxFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    staticText6->SetForegroundColour(wxColor(0, 0, 0));


    wxStaticText* staticText5 = new wxStaticText(panel1, wxID_ANY, "Ulgowy", wxPoint(340, 200), wxDefaultSize, wxALIGN_CENTER);
    staticText5->SetFont(wxFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    staticText5->SetForegroundColour(wxColor(0, 0, 0));

    wxSpinCtrl* spinCtrl1 = new wxSpinCtrl(panel1, wxID_ANY, "", wxPoint(630, 200), wxSize(60, 25));
    spinCtrl1->SetMax(10);
    spinCtrl1->SetFont(wxFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));

    wxStaticText* staticText7 = new wxStaticText(panel1, wxID_ANY, "16 z³", wxPoint(890, 200), wxDefaultSize, wxALIGN_CENTER);
    staticText7->SetFont(wxFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    staticText7->SetForegroundColour(wxColor(0, 0, 0));

    wxButton* button0 = new wxButton(panel1, wxID_ANY, "WYBÓR MIEJSC", wxPoint(560,250), wxSize(200, 60));
    button0->Bind(wxEVT_BUTTON, &TicketTypeFrame::OnButton0Clicked, this, wxID_ANY);
    button0->SetFont(wxFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));

    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    mainSizer->Add(panel0, 0, wxEXPAND);
    mainSizer->Add(panel1, 1, wxEXPAND);
    mainSizer->Add(panel2, 0, wxEXPAND);
    mainPanel->SetSizer(mainSizer);
}

void TicketTypeFrame::OnButton0Clicked(wxCommandEvent& evt)
{
    SeatFrame* seatFrame = new SeatFrame("Siedzenie");
    seatFrame->Show();
    seatFrame->SetClientSize(1280, 720);
    seatFrame->SetMinClientSize(wxSize(1280, 720));
    seatFrame->SetMaxClientSize(wxSize(1280, 720));
    seatFrame->Center();
}
