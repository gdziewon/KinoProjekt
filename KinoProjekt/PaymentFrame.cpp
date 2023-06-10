#include "PaymentFrame.h"

PaymentFrame::PaymentFrame(const wxString& title, const wxString& movie, const wxString& date, const wxString& time, const wxString& type, const wxString& language, const wxString& message)
     : wxFrame(nullptr, wxID_ANY, title), movie(movie), date(date), time(time), type(type), language(language), message(message)
{
    mainPanel = new wxPanel(this, wxID_ANY);

    topPanel = new wxPanel(mainPanel, wxID_ANY, wxDefaultPosition, wxSize(1280, 100));
    topPanel->SetBackgroundColour(wxColour(0, 0, 0));

    staticText0 = new wxStaticText(topPanel, wxID_ANY, L"Płatność", wxPoint(80,5), wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);
    staticText0->SetFont(wxFont(60, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    staticText0->SetForegroundColour(wxColor(40, 126, 75));

    leftPanel = new wxPanel(mainPanel, wxID_ANY, wxDefaultPosition, wxSize(640, 520));
    leftPanel->SetBackgroundColour(wxColour(65, 65, 65));

    staticText1 = new wxStaticText(leftPanel, wxID_ANY, "Podsumowanie", wxPoint(220, 10), wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);
    staticText1->SetFont(wxFont(25, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    staticText1->SetForegroundColour(wxColor(255, 255, 255));

    movieText = new wxStaticText(leftPanel, wxID_ANY, "Film:  "+ movie+"  "+type, wxPoint(100, 80), wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);
    movieText->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    movieText->SetForegroundColour(wxColor(255, 255, 255));

    dateText = new wxStaticText(leftPanel, wxID_ANY, "Data: "+ date, wxPoint(100, 130), wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);
    dateText->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    dateText->SetForegroundColour(wxColor(255, 255, 255));

    hourText = new wxStaticText(leftPanel, wxID_ANY, "Godzina: " + time, wxPoint(100, 180), wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);
    hourText->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    hourText->SetForegroundColour(wxColor(255, 255, 255));

    languageText = new wxStaticText(leftPanel, wxID_ANY, L"Język: " + language, wxPoint(100, 230), wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);
    languageText->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    languageText->SetForegroundColour(wxColor(255, 255, 255));

    roomText = new wxStaticText(leftPanel, wxID_ANY, "Sala: ", wxPoint(100, 280), wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);
    roomText->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    roomText->SetForegroundColour(wxColor(255, 255, 255));

    seatText = new wxStaticText(leftPanel, wxID_ANY, "Miejsca: ", wxPoint(100, 330), wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);
    seatText->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    seatText->SetForegroundColour(wxColor(255, 255, 255));

    priceText = new wxStaticText(leftPanel, wxID_ANY, wxT("Do zapłaty: ") + message + wxT(" zł"), wxPoint(100, 380), wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);
    priceText->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    priceText->SetForegroundColour(wxColor(255, 255, 255));

    rightPanel = new wxPanel(mainPanel, wxID_ANY, wxDefaultPosition, wxSize(640, 520));
    rightPanel->SetBackgroundColour(wxColour(65, 65, 65));

    staticText2 = new wxStaticText(rightPanel, wxID_ANY, "Twoje Dane", wxPoint(220, 10), wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);
    staticText2->SetFont(wxFont(25, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    staticText2->SetForegroundColour(wxColor(255, 255, 255));

    nameText = new wxStaticText(rightPanel, wxID_ANY, L"Imię:", wxPoint(100,80), wxDefaultSize);
    nameText->SetFont(wxFont(18, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    nameText->SetForegroundColour(wxColor(255, 255, 255));
    nameCtrl = new wxTextCtrl(rightPanel, wxID_ANY, "", wxPoint(100, 110), wxSize(200,30));
    nameCtrl->SetFont(wxFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    nameCtrl->SetForegroundColour(wxColor(0, 0, 0));
    nameCtrl->SetMaxLength(20);

    surnameText = new wxStaticText(rightPanel, wxID_ANY, "Nazwisko:", wxPoint(360, 80), wxDefaultSize);
    surnameText->SetFont(wxFont(18, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    surnameText->SetForegroundColour(wxColor(255, 255, 255));
    surnameCtrl = new wxTextCtrl(rightPanel, wxID_ANY, "", wxPoint(360, 110), wxSize(200, 30));
    surnameCtrl->SetFont(wxFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    surnameCtrl->SetForegroundColour(wxColor(0, 0, 0));
    surnameCtrl->SetMaxLength(20);

    emailText = new wxStaticText(rightPanel, wxID_ANY, "Adres e-mail:", wxPoint(100, 150), wxDefaultSize);
    emailText->SetFont(wxFont(18, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    emailText->SetForegroundColour(wxColor(255, 255, 255));
    emailCtrl = new wxTextCtrl(rightPanel, wxID_ANY, "", wxPoint(100, 180), wxSize(200, 30));
    emailCtrl->SetFont(wxFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    emailCtrl->SetForegroundColour(wxColor(0, 0, 0));

    phoneText = new wxStaticText(rightPanel, wxID_ANY, "Numer telefonu:", wxPoint(360, 150), wxDefaultSize);
    phoneText->SetFont(wxFont(18, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    phoneText->SetForegroundColour(wxColor(255, 255, 255));
    phoneCtrl = new wxTextCtrl(rightPanel, wxID_ANY, "+48 ", wxPoint(360, 180), wxSize(200, 30));
    phoneCtrl->SetFont(wxFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    phoneCtrl->SetForegroundColour(wxColor(0, 0, 0));
    //phoneCtrl->SetValidator(wxTextValidator(wxFILTER_NUMERIC));
    phoneCtrl->SetMaxLength(15);

    cardText = new wxStaticText(rightPanel, wxID_ANY, "Numer karty:", wxPoint(100, 260), wxDefaultSize);
    cardText->SetFont(wxFont(18, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    cardText->SetForegroundColour(wxColor(255, 255, 255));
    cardNumberCtrl = new wxTextCtrl(rightPanel, wxID_ANY, "", wxPoint(100, 290), wxSize(210, 30));
    cardNumberCtrl->SetFont(wxFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    cardNumberCtrl->SetForegroundColour(wxColor(0, 0, 0));
    cardNumberCtrl->SetMaxLength(19);

    datecardText = new wxStaticText(rightPanel, wxID_ANY, "Data:", wxPoint(100, 330), wxDefaultSize);
    datecardText->SetFont(wxFont(18, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    datecardText->SetForegroundColour(wxColor(255, 255, 255));
    expiryDateCtrl = new wxTextCtrl(rightPanel, wxID_ANY, "", wxPoint(100, 360), wxSize(65, 30));
    expiryDateCtrl->SetFont(wxFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    expiryDateCtrl->SetForegroundColour(wxColor(0, 0, 0));
    expiryDateCtrl->SetMaxLength(5);

    cvcText = new wxStaticText(rightPanel, wxID_ANY, "CVC:", wxPoint(255, 330), wxDefaultSize);
    cvcText->SetFont(wxFont(18, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    cvcText->SetForegroundColour(wxColor(255, 255, 255));
    cvcCtrl = new wxTextCtrl(rightPanel, wxID_ANY, "", wxPoint(260, 360), wxSize(50, 30));
    cvcCtrl->SetValidator(wxTextValidator(wxFILTER_NUMERIC));
    cvcCtrl->SetFont(wxFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    cvcCtrl->SetForegroundColour(wxColor(0, 0, 0));
    cvcCtrl->SetMaxLength(3);

    bottomPanel = new wxPanel(mainPanel, wxID_ANY, wxDefaultPosition, wxSize(1280, 100));
    bottomPanel->SetBackgroundColour(wxColour(0, 0, 0));

    backbutton = new wxButton(bottomPanel, wxID_ANY, "Anuluj", wxPoint(80, 20), wxSize(200, 60));
    backbutton->Bind(wxEVT_BUTTON, &PaymentFrame::OnBackButtonClicked, this, wxID_ANY);
    backbutton->SetFont(wxFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));

    button0 = new wxButton(bottomPanel, wxID_ANY, L"Zamawiam i płacę", wxPoint(1060, 20), wxSize(200, 60));
    button0->Bind(wxEVT_BUTTON, &PaymentFrame::OnButton0Clicked, this, wxID_ANY);
    button0->SetFont(wxFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));

    mainSizer = new wxBoxSizer(wxVERTICAL);

    horizontalSizer = new wxBoxSizer(wxHORIZONTAL);
    horizontalSizer->Add(leftPanel, 1, wxEXPAND);
    horizontalSizer->Add(rightPanel, 1, wxEXPAND);

    mainSizer->Add(topPanel, 1, wxEXPAND);
    mainSizer->Add(horizontalSizer, 1, wxEXPAND);
    mainSizer->Add(bottomPanel, 0, wxEXPAND);

    mainPanel->SetSizer(mainSizer);

    mainSizer->Layout();
}

void PaymentFrame::OnBackButtonClicked(wxCommandEvent& evt)
{
    MainFrame* mainFrame = new MainFrame("Kino");
    mainFrame->Show();
    mainFrame->SetClientSize(1280, 720);
    mainFrame->SetMinClientSize(wxSize(1280, 720));
    mainFrame->SetMaxClientSize(wxSize(1280, 720));
    mainFrame->Center();
    Close();
}

void PaymentFrame::OnButton0Clicked(wxCommandEvent& evt)
{
    
}