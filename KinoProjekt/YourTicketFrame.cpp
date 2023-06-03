#include "YourTicketFrame.h"

YourTicketFrame::YourTicketFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
    mainPanel = new wxPanel(this, wxID_ANY);

    topPanel = new wxPanel(mainPanel, wxID_ANY, wxDefaultPosition, wxSize(1280, 100));
    topPanel->SetBackgroundColour(wxColour(0, 0, 0));

    staticText0 = new wxStaticText(topPanel, wxID_ANY, "Twoje Bilety", wxDefaultPosition, wxSize(400, -1), wxALIGN_CENTER_HORIZONTAL);
    staticText0->SetFont(wxFont(60, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    staticText0->SetForegroundColour(wxColor(57, 255, 20));

    midPanel = new wxPanel(mainPanel, wxID_ANY, wxDefaultPosition, wxSize(640, 520));
    midPanel->SetBackgroundColour(wxColour(255, 255, 255));

    bottomPanel = new wxPanel(mainPanel, wxID_ANY, wxDefaultPosition, wxSize(1280, 100));
    bottomPanel->SetBackgroundColour(wxColour(0, 0, 0));

    mainSizer = new wxBoxSizer(wxVERTICAL);
    mainSizer->Add(topPanel, 1, wxEXPAND);
    mainSizer->Add(midPanel, 1, wxEXPAND);
    mainSizer->Add(bottomPanel, 0, wxEXPAND); 
    mainPanel->SetSizer(mainSizer);
    mainSizer->Layout();
}