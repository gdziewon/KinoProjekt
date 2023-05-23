#include "ContactFrame.h"
#include <wx/wx.h>
#include <wx/hyperlink.h>

ContactFrame::ContactFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
    wxPanel* mainPanel = new wxPanel(this, wxID_ANY);

    wxPanel* panel0 = new wxPanel(mainPanel, wxID_ANY, wxPoint(0, 0), wxSize(640, 70));
    panel0->SetBackgroundColour(wxColor(0, 0, 0));
    wxPanel* panel1 = new wxPanel(mainPanel, wxID_ANY, wxPoint(0, 0), wxSize(640, 240));
    panel1->SetBackgroundColour(wxColor(255, 255, 255));

    // panel0
    wxStaticText* staticText0 = new wxStaticText(panel0, wxID_ANY, "Kontakt", wxPoint(0,14), wxSize(200, -1), wxALIGN_CENTER_HORIZONTAL);
    staticText0->SetFont(wxFont(30, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    staticText0->SetForegroundColour(wxColor(57, 255, 20));

    // panel1
    wxBoxSizer* panel2Sizer = new wxBoxSizer(wxVERTICAL);
    panel1->SetSizer(panel2Sizer);

    panel2Sizer->AddSpacer(20);

    wxStaticText* emailText = new wxStaticText(panel1, wxID_ANY, "Email: projekt@projekt.com", wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT);
    emailText->SetFont(wxFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    emailText->SetForegroundColour(wxColor(57, 255, 20));
    panel2Sizer->Add(emailText, 0, wxALL | wxEXPAND, 10);

    wxStaticText* staticText2 = new wxStaticText(panel1, wxID_ANY, "Telefon: 123 123 123", wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT);
    staticText2->SetFont(wxFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    staticText2->SetForegroundColour(wxColor(57, 255, 20));
    panel2Sizer->Add(staticText2, 0, wxALL | wxEXPAND, 10);

    wxStaticText* staticText3 = new wxStaticText(panel1, wxID_ANY, "Autorzy: Hubert Kordula \t\tEryk Dziewoñski\n\t Jakub Sado\t\tMicha³ Radziukiewicz", wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT);
    staticText3->SetFont(wxFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    staticText3->SetForegroundColour(wxColor(57, 255, 20));
    panel2Sizer->Add(staticText3, 1, wxALL | wxEXPAND, 10);

    wxButton* closeButton = new wxButton(mainPanel, wxID_ANY, "Zamknij", wxDefaultPosition, wxSize(100,40));
    closeButton->Bind(wxEVT_BUTTON, &ContactFrame::OnCloseButtonClicked, this); 
    closeButton->SetFont(wxFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));

    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    mainSizer->Add(panel0, 0, wxEXPAND);
    mainSizer->Add(panel1, 1, wxEXPAND);
    mainSizer->Add(closeButton, 0, wxALIGN_RIGHT | wxBOTTOM | wxRIGHT, 20);
    mainPanel->SetSizer(mainSizer);

    mainSizer->Fit(this);
    SetClientSize(mainSizer->GetMinSize());
}

void ContactFrame::OnCloseButtonClicked(wxCommandEvent& event)
{
    Close();
}
