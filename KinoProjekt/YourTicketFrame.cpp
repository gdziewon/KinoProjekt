#include "YourTicketFrame.h"
#include <wx/wx.h>

YourTicketFrame::YourTicketFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
    // Utw�rz g��wny panel
    wxPanel* mainPanel = new wxPanel(this, wxID_ANY);

    // Utw�rz panel g�rny
    wxPanel* topPanel = new wxPanel(mainPanel, wxID_ANY, wxDefaultPosition, wxSize(1280, 100));
    topPanel->SetBackgroundColour(wxColour(0, 0, 0));

    wxStaticText* staticText0 = new wxStaticText(topPanel, wxID_ANY, "Twoje Bilety", wxDefaultPosition, wxSize(400, -1), wxALIGN_CENTER_HORIZONTAL);
    staticText0->SetFont(wxFont(60, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    staticText0->SetForegroundColour(wxColor(57, 255, 20));

    // Utw�rz panel lewy
    wxPanel* midPanel = new wxPanel(mainPanel, wxID_ANY, wxDefaultPosition, wxSize(640, 520));
    midPanel->SetBackgroundColour(wxColour(255, 255, 255));

    // Utw�rz stopk�
    wxPanel* bottomPanel = new wxPanel(mainPanel, wxID_ANY, wxDefaultPosition, wxSize(1280, 100));
    bottomPanel->SetBackgroundColour(wxColour(0, 0, 0));

    // Utw�rz uk�ad sizer (rozmiar�wka)
    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);  // Ustaw pionowy uk�ad rozmiar�wki


    // Dodaj panele do g��wnej rozmiar�wki
    mainSizer->Add(topPanel, 1, wxEXPAND);  // Panel g�rny zajmuje 1 cz�� dost�pnego miejsca
    mainSizer->Add(midPanel, 1, wxEXPAND);  // Uk�ad poziomy zajmuje 1 cz�� dost�pnego miejsca
    mainSizer->Add(bottomPanel, 0, wxEXPAND);  // Stopka zajmuje sta�� wysoko�� (0 cz�ci dost�pnego miejsca)

    // Ustaw rozmiar�wk� na g��wnym panelu
    mainPanel->SetSizer(mainSizer);

    // Wyr�wnaj elementy w rozmiar�wce
    mainSizer->Layout();
}