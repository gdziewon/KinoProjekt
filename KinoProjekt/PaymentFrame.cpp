#include "PaymentFrame.h"
#include <wx/wx.h>

PaymentFrame::PaymentFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
    // Utwórz g³ówny panel
    wxPanel* mainPanel = new wxPanel(this, wxID_ANY);

    // Utwórz panel górny
    wxPanel* topPanel = new wxPanel(mainPanel, wxID_ANY, wxDefaultPosition, wxSize(1280, 100));
    topPanel->SetBackgroundColour(wxColour(0, 0, 0));

    wxStaticText* staticText0 = new wxStaticText(topPanel, wxID_ANY, "P³atnoœæ", wxDefaultPosition, wxSize(400, -1), wxALIGN_CENTER_HORIZONTAL);
    staticText0->SetFont(wxFont(60, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    staticText0->SetForegroundColour(wxColor(57, 255, 20));

    // Utwórz panel lewy
    wxPanel* leftPanel = new wxPanel(mainPanel, wxID_ANY, wxDefaultPosition, wxSize(640, 520));
    leftPanel->SetBackgroundColour(wxColour(225, 225, 225));

    wxStaticText* staticText1 = new wxStaticText(leftPanel, wxID_ANY, "Podsumowanie:", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);
    staticText1->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    staticText1->SetForegroundColour(wxColor(0, 0, 0));

    // Utwórz panel prawy
    wxPanel* rightPanel = new wxPanel(mainPanel, wxID_ANY, wxDefaultPosition, wxSize(640, 520));
    rightPanel->SetBackgroundColour(wxColour(255, 255, 255));

    wxStaticText* staticText2 = new wxStaticText(rightPanel, wxID_ANY, "Twoje Dane", wxPoint(250, 10), wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);
    staticText2->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    staticText2->SetForegroundColour(wxColor(0, 0, 0));

    // Utwórz pola tekstowe
    wxStaticText* nameText = new wxStaticText(rightPanel, wxID_ANY, "Imiê:", wxPoint(100,80), wxDefaultSize);
    nameText->SetFont(wxFont(18, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    nameText->SetForegroundColour(wxColor(0, 0, 0));
    wxTextCtrl* nameCtrl = new wxTextCtrl(rightPanel, wxID_ANY, "", wxPoint(100, 110), wxSize(200,30));
    nameCtrl->SetFont(wxFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    nameCtrl->SetForegroundColour(wxColor(0, 0, 0));
    nameCtrl->SetMaxLength(20);

    wxStaticText* surnameText = new wxStaticText(rightPanel, wxID_ANY, "Nazwisko:", wxPoint(360, 80), wxDefaultSize);
    surnameText->SetFont(wxFont(18, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    surnameText->SetForegroundColour(wxColor(0, 0, 0));
    wxTextCtrl* surnameCtrl = new wxTextCtrl(rightPanel, wxID_ANY, "", wxPoint(360, 110), wxSize(200, 30));
    surnameCtrl->SetFont(wxFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    surnameCtrl->SetForegroundColour(wxColor(0, 0, 0));
    surnameCtrl->SetMaxLength(20);

    wxStaticText* emailText = new wxStaticText(rightPanel, wxID_ANY, "Adres email:", wxPoint(100, 150), wxDefaultSize);
    emailText->SetFont(wxFont(18, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    emailText->SetForegroundColour(wxColor(0, 0, 0));
    wxTextCtrl* emailCtrl = new wxTextCtrl(rightPanel, wxID_ANY, "", wxPoint(100, 180), wxSize(200, 30));
    emailCtrl->SetFont(wxFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    emailCtrl->SetForegroundColour(wxColor(0, 0, 0));

    wxStaticText* phoneText = new wxStaticText(rightPanel, wxID_ANY, "Numer telefonu:", wxPoint(360, 150), wxDefaultSize);
    phoneText->SetFont(wxFont(18, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    phoneText->SetForegroundColour(wxColor(0, 0, 0));
    wxTextCtrl* phoneCtrl = new wxTextCtrl(rightPanel, wxID_ANY, "+48 ", wxPoint(360, 180), wxSize(200, 30));
    phoneCtrl->SetFont(wxFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    phoneCtrl->SetForegroundColour(wxColor(0, 0, 0));
    //phoneCtrl->SetValidator(wxTextValidator(wxFILTER_NUMERIC));
    phoneCtrl->SetMaxLength(15);

    wxStaticText* cardText = new wxStaticText(rightPanel, wxID_ANY, "Numer karty:", wxPoint(100, 260), wxDefaultSize);
    cardText->SetFont(wxFont(18, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    cardText->SetForegroundColour(wxColor(0, 0, 0));
    wxTextCtrl* cardNumberCtrl = new wxTextCtrl(rightPanel, wxID_ANY, "", wxPoint(100, 290), wxSize(210, 30));
    cardNumberCtrl->SetFont(wxFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    cardNumberCtrl->SetForegroundColour(wxColor(0, 0, 0));
    cardNumberCtrl->SetMaxLength(19);

    wxStaticText* dateText = new wxStaticText(rightPanel, wxID_ANY, "Data:", wxPoint(100, 330), wxDefaultSize);
    dateText->SetFont(wxFont(18, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    dateText->SetForegroundColour(wxColor(0, 0, 0));
    wxTextCtrl* expiryDateCtrl = new wxTextCtrl(rightPanel, wxID_ANY, "", wxPoint(100, 360), wxSize(65, 30));
    expiryDateCtrl->SetFont(wxFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    expiryDateCtrl->SetForegroundColour(wxColor(0, 0, 0));
    expiryDateCtrl->SetMaxLength(5);

    wxStaticText* cvcText = new wxStaticText(rightPanel, wxID_ANY, "CVC:", wxPoint(255, 330), wxDefaultSize);
    cvcText->SetFont(wxFont(18, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    cvcText->SetForegroundColour(wxColor(0, 0, 0));
    wxTextCtrl* cvcCtrl = new wxTextCtrl(rightPanel, wxID_ANY, "", wxPoint(260, 360), wxSize(50, 30));
    cvcCtrl->SetValidator(wxTextValidator(wxFILTER_NUMERIC));
    cvcCtrl->SetFont(wxFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    cvcCtrl->SetForegroundColour(wxColor(0, 0, 0));
    cvcCtrl->SetMaxLength(3);

    // Utwórz stopkê
    wxPanel* bottomPanel = new wxPanel(mainPanel, wxID_ANY, wxDefaultPosition, wxSize(1280, 100));
    bottomPanel->SetBackgroundColour(wxColour(0, 0, 0));

    wxButton* button0 = new wxButton(bottomPanel, wxID_ANY, "Zamawiam i p³acê", wxPoint(1060, 20), wxSize(200, 60));
    button0->Bind(wxEVT_BUTTON, &PaymentFrame::OnButton0Clicked, this, wxID_ANY);
    button0->SetFont(wxFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));

    // Utwórz uk³ad sizer (rozmiarówka)
    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);  // Ustaw pionowy uk³ad rozmiarówki

    // Utwórz uk³ad sizer (rozmiarówka) dla paneli lewego i prawego
    wxBoxSizer* horizontalSizer = new wxBoxSizer(wxHORIZONTAL);  // Ustaw poziomy uk³ad rozmiarówki

    // Dodaj panele lewy i prawy do uk³adu poziomego
    horizontalSizer->Add(leftPanel, 1, wxEXPAND);  // Panel lewy zajmuje 1 czêœæ dostêpnego miejsca
    horizontalSizer->Add(rightPanel, 1, wxEXPAND);  // Panel prawy zajmuje 1 czêœæ dostêpnego miejsca

    // Dodaj panele do g³ównej rozmiarówki
    mainSizer->Add(topPanel, 1, wxEXPAND);  // Panel górny zajmuje 1 czêœæ dostêpnego miejsca
    mainSizer->Add(horizontalSizer, 1, wxEXPAND);  // Uk³ad poziomy zajmuje 1 czêœæ dostêpnego miejsca
    mainSizer->Add(bottomPanel, 0, wxEXPAND);  // Stopka zajmuje sta³¹ wysokoœæ (0 czêœci dostêpnego miejsca)

    // Ustaw rozmiarówkê na g³ównym panelu
    mainPanel->SetSizer(mainSizer);

    // Wyrównaj elementy w rozmiarówce
    mainSizer->Layout();
}

void PaymentFrame::OnButton0Clicked(wxCommandEvent& evt)
{
    
}