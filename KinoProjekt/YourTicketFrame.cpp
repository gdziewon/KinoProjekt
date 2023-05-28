#include "YourTicketFrame.h"
#include <wx/wx.h>

YourTicketFrame::YourTicketFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
    // Utwórz g³ówny panel
    wxPanel* mainPanel = new wxPanel(this, wxID_ANY);

    // Utwórz panel górny
    wxPanel* topPanel = new wxPanel(mainPanel, wxID_ANY, wxDefaultPosition, wxSize(1280, 100));
    topPanel->SetBackgroundColour(wxColour(0, 0, 0));

    wxStaticText* staticText0 = new wxStaticText(topPanel, wxID_ANY, "Twoje Bilety", wxDefaultPosition, wxSize(400, -1), wxALIGN_CENTER_HORIZONTAL);
    staticText0->SetFont(wxFont(60, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    staticText0->SetForegroundColour(wxColor(57, 255, 20));

    // Utwórz panel lewy
    wxPanel* midPanel = new wxPanel(mainPanel, wxID_ANY, wxDefaultPosition, wxSize(640, 520));
    midPanel->SetBackgroundColour(wxColour(255, 255, 255));

    // Utwórz stopkê
    wxPanel* bottomPanel = new wxPanel(mainPanel, wxID_ANY, wxDefaultPosition, wxSize(1280, 100));
    bottomPanel->SetBackgroundColour(wxColour(0, 0, 0));

    // Utwórz uk³ad sizer (rozmiarówka)
    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);  // Ustaw pionowy uk³ad rozmiarówki


    // Dodaj panele do g³ównej rozmiarówki
    mainSizer->Add(topPanel, 1, wxEXPAND);  // Panel górny zajmuje 1 czêœæ dostêpnego miejsca
    mainSizer->Add(midPanel, 1, wxEXPAND);  // Uk³ad poziomy zajmuje 1 czêœæ dostêpnego miejsca
    mainSizer->Add(bottomPanel, 0, wxEXPAND);  // Stopka zajmuje sta³¹ wysokoœæ (0 czêœci dostêpnego miejsca)

    // Ustaw rozmiarówkê na g³ównym panelu
    mainPanel->SetSizer(mainSizer);

    // Wyrównaj elementy w rozmiarówce
    mainSizer->Layout();
}