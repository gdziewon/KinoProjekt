#include "YourTicketFrame.h"

YourTicketFrame::YourTicketFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
    mainPanel = new wxPanel(this, wxID_ANY);

    topPanel = new wxPanel(mainPanel, wxID_ANY, wxDefaultPosition, wxSize(1280, 100));
    topPanel->SetBackgroundColour(wxColour(0, 0, 0));

    staticText0 = new wxStaticText(topPanel, wxID_ANY, "Twoje Bilety", wxPoint(80,5), wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);
    staticText0->SetFont(wxFont(60, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    staticText0->SetForegroundColour(wxColor(40, 126, 75));

    midPanel = new wxPanel(mainPanel, wxID_ANY, wxDefaultPosition, wxSize(640, 520));
    midPanel->SetBackgroundColour(wxColour(65, 65, 65));

    bottomPanel = new wxPanel(mainPanel, wxID_ANY, wxDefaultPosition, wxSize(1280, 100));
    bottomPanel->SetBackgroundColour(wxColour(0, 0, 0));

    backbutton = new wxButton(bottomPanel, wxID_ANY, "Powrót", wxPoint(80,20), wxSize(200, 60));
    backbutton->Bind(wxEVT_BUTTON, &YourTicketFrame::OnBackButtonClicked, this, wxID_ANY);
    backbutton->SetFont(wxFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));


    mainSizer = new wxBoxSizer(wxVERTICAL);
    mainSizer->Add(topPanel, 1, wxEXPAND);
    mainSizer->Add(midPanel, 1, wxEXPAND);
    mainSizer->Add(bottomPanel, 0, wxEXPAND); 
    mainPanel->SetSizer(mainSizer);
    mainSizer->Layout();
}

void YourTicketFrame::OnBackButtonClicked(wxCommandEvent& evt)
{
    MainFrame* mainFrame = new MainFrame("Kino");
    mainFrame->Show();
    mainFrame->SetClientSize(1280, 720);
    mainFrame->SetMinClientSize(wxSize(1280, 720));
    mainFrame->SetMaxClientSize(wxSize(1280, 720));
    mainFrame->Center();
    Close();
}