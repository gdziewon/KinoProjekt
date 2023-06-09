#include "TicketTypeFrame.h"

TicketTypeFrame::TicketTypeFrame(const wxString& title, const wxString& movie, const wxString& date, const wxString& time, const wxString& type, const wxString& language)
    : wxFrame(nullptr, wxID_ANY, title), movie(movie), date(date), time(time), type(type), language(language)
{
    mainPanel = new wxPanel(this, wxID_ANY);
    panel0 = new wxPanel(mainPanel, wxID_ANY, wxDefaultPosition, wxSize(1280, 100));
    panel0->SetBackgroundColour(wxColor(0, 0, 0));
    panel1 = new wxPanel(mainPanel, wxID_ANY, wxDefaultPosition, wxSize(1280, 520));
    panel1->SetBackgroundColour(wxColor(65, 65, 65));
    panel2 = new wxPanel(mainPanel, wxID_ANY, wxDefaultPosition, wxSize(1280, 100));
    panel2->SetBackgroundColour(wxColor(0, 0, 0));

    staticText0 = new wxStaticText(panel0, wxID_ANY, L"Rodzaj Biletów", wxPoint(80,5), wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);
    staticText0->SetFont(wxFont(60, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    staticText0->SetForegroundColour(wxColor(40, 126, 75));

    label1 = new wxStaticText(panel1, wxID_ANY, "Rodzaj Biletu", wxPoint(300,130), wxDefaultSize, wxALIGN_CENTER);
    label1->SetFont(wxFont(25, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    label1->SetForegroundColour(wxColor(255, 255, 255));
 
    label2 = new wxStaticText(panel1, wxID_ANY, L"Ilość", wxPoint(630, 130), wxDefaultSize, wxALIGN_CENTER);
    label2->SetFont(wxFont(25, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    label2->SetForegroundColour(wxColor(255, 255, 255));

    label3 = new wxStaticText(panel1, wxID_ANY, "Cena(szt)", wxPoint(860, 130), wxDefaultSize, wxALIGN_CENTER);
    label3->SetFont(wxFont(25, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    label3->SetForegroundColour(wxColor(255, 255, 255));

    staticText4 = new wxStaticText(panel1, wxID_ANY, "Normalny", wxPoint(340, 200), wxDefaultSize, wxALIGN_CENTER);
    staticText4->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    staticText4->SetForegroundColour(wxColor(255, 255, 255));

    spinCtrlSizer0 = new wxBoxSizer(wxHORIZONTAL);
    spinCtrl0 = new wxSpinCtrl(panel1, wxID_ANY, "", wxPoint(635, 200), wxSize(65, 35));
    spinCtrl0->SetMax(5);
    spinCtrl0->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    spinCtrl0->Bind(wxEVT_SPINCTRL, &TicketTypeFrame::OnSpin, this);

    staticText6 = new wxStaticText(panel1, wxID_ANY, L"21 zł", wxPoint(900, 200), wxDefaultSize, wxALIGN_CENTER);
    staticText6->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    staticText6->SetForegroundColour(wxColor(255, 255, 255));

    staticText5 = new wxStaticText(panel1, wxID_ANY, "Ulgowy", wxPoint(350, 270), wxDefaultSize, wxALIGN_CENTER);
    staticText5->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    staticText5->SetForegroundColour(wxColor(255, 255, 255));

    spinCtrl1 = new wxSpinCtrl(panel1, wxID_ANY, "", wxPoint(635, 270), wxSize(65, 35));
    spinCtrl1->SetMax(5);
    spinCtrl1->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    spinCtrl1->Bind(wxEVT_SPINCTRL, &TicketTypeFrame::OnSpin, this);

    staticText7 = new wxStaticText(panel1, wxID_ANY, L"16 zł", wxPoint(900, 270), wxDefaultSize, wxALIGN_CENTER);
    staticText7->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    staticText7->SetForegroundColour(wxColor(255, 255, 255));

    button0 = new wxButton(panel2, wxID_ANY, L"Wybierz Miejsca", wxPoint(1000,20), wxSize(200, 60));
    button0->Bind(wxEVT_BUTTON, &TicketTypeFrame::OnButton0Clicked, this, wxID_ANY);
    button0->SetFont(wxFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));

    backbutton = new wxButton(panel2, wxID_ANY, "Powrót", wxPoint(80, 20), wxSize(200, 60));
    backbutton->Bind(wxEVT_BUTTON, &TicketTypeFrame::OnBackButtonClicked, this, wxID_ANY);
    backbutton->SetFont(wxFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));

    mainSizer = new wxBoxSizer(wxVERTICAL);
    mainSizer->Add(panel0, 0, wxEXPAND);
    mainSizer->Add(panel1, 1, wxEXPAND);
    mainSizer->Add(panel2, 0, wxEXPAND);
    mainPanel->SetSizer(mainSizer);

    /*
    spinText = new wxStaticText(panel1, wxID_ANY, L"Do zapłaty: ", wxPoint(500, 30), wxDefaultSize, wxALIGN_CENTER);
    spinText->SetFont(wxFont(30, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    spinText->SetForegroundColour(wxColor(255, 255, 255));
    */
    
    message = "0";
    spinText = new wxStaticText(panel2, wxID_ANY, L"Do zapłaty: " + message + " zł", wxPoint(500, 30), wxDefaultSize, wxALIGN_CENTER);
    spinText->SetFont(wxFont(30, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    spinText->SetForegroundColour(wxColor(255, 255, 255));
}

void TicketTypeFrame::OnButton0Clicked(wxCommandEvent& evt)
{
    int value0 = spinCtrl0->GetValue();
    int value1 = spinCtrl1->GetValue();

    if (value0 > 0 || value1 > 0) {
        SeatFrame* seatFrame = new SeatFrame("Wybierz Miejsca", movie, date, time, type, language, message);
        seatFrame->Show();
        seatFrame->SetClientSize(1280, 720);
        seatFrame->SetMaxClientSize(wxSize(1280, 720));
        seatFrame->Center();
        Close();
    }
    else {
        wxMessageBox("Wybierz przynajmniej jeden bilet.", "Błąd", wxOK | wxICON_ERROR);
    }
}

/*
void TicketTypeFrame::OnSpin(wxSpinEvent& event)
{
    int value0 = spinCtrl0->GetValue();
    int value1 = spinCtrl1->GetValue();
    message = wxString::Format(wxT("Do zapłaty: %d zł "), value0 * 21 + value1 * 16);
    spinText->SetLabel(message);
}
*/

void TicketTypeFrame::OnSpin(wxSpinEvent& event)
{
    int value0 = spinCtrl0->GetValue();
    int value1 = spinCtrl1->GetValue();
    message = wxString::Format("%d", value0 * 21 + value1 * 16);
    spinText->SetLabel("Do zapłaty: " + message + "zł");
}

void TicketTypeFrame::OnBackButtonClicked(wxCommandEvent& evt)
{
    TicketFrame* ticketFrame = new TicketFrame("Kup Bilet");
    ticketFrame->Show();
    ticketFrame->SetClientSize(1280, 720);
    ticketFrame->SetMaxClientSize(wxSize(1280, 720));
    ticketFrame->Center();
    Close();
}