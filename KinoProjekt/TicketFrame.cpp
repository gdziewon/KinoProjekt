#include "TicketFrame.h"
#include "TicketTypeFrame.h"

#include <wx/wx.h>
#include <wx/datectrl.h>
#include <wx/dateevt.h>
#include <wx/datetime.h>
#include <wx/bitmap.h>
#include <wx/image.h>

TicketFrame::TicketFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
    // Czcionki
    fontTitle = wxFont(60, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
    fontLabel = wxFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
    fontChoice = wxFont(18, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
    // Panel górny
    upper_panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(1280, 100));
    upper_panel->SetBackgroundColour(wxColour(0, 0, 0));

    staticText0 = new wxStaticText(upper_panel, wxID_ANY, "Kup Bilet", wxDefaultPosition, wxSize(400, -1), wxALIGN_CENTER_HORIZONTAL);
    staticText0->SetFont(fontTitle);
    staticText0->SetForegroundColour(wxColour(57, 255, 20));

    // Panel lewy
    left_panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(756, 520));
    left_panel->SetBackgroundColour(wxColour(255, 255, 255));

    // Wybierz Film
    movieLabelText = new wxStaticText(left_panel, wxID_ANY, "Wybierz Film:", wxPoint(80,100), wxDefaultSize);
    movieLabelText->SetFont(fontLabel);
    movieLabelText->SetForegroundColour(wxColour(0, 0, 0));

    wxArrayString choices;
    choices.Add("Movie 1");
    choices.Add("Movie 2");
    choices.Add("Movie 3");
    choices.Add("Movie 4");
    choices.Add("Movie 5");
    choices.Add("Movie 6");
    choices.Add("Movie 7");
    choices.Add("Movie 8");

    choice = new wxChoice(left_panel, wxID_ANY, wxPoint(40, 130), wxSize(200, -1), choices);
    choice->Connect(wxEVT_CHOICE, wxCommandEventHandler(TicketFrame::Image), nullptr, this);
    choice->SetFont(fontChoice);
   
    // Wybierz Datê 
    dateTimeText = new wxStaticText(left_panel, wxID_ANY, "Wybierz Datê:", wxPoint(325, 100), wxDefaultSize);
    dateTimeText->SetFont(fontLabel);
    dateTimeText->SetForegroundColour(wxColour(0, 0, 0));
   
    wxDatePickerCtrl* datePicker = new wxDatePickerCtrl(left_panel, wxID_ANY, wxDefaultDateTime, wxPoint(285, 130), wxSize(200, 35), wxDP_DROPDOWN);
    datePicker->SetFont(fontLabel);
    wxDateTime maxDate = wxDateTime::Today();
    maxDate.Add(wxDateSpan::Months(1));
    datePicker->SetRange(wxDateTime::Today(), maxDate);
    
    // Wybierz Godzinê
    timeText = new wxStaticText(left_panel, wxID_ANY, "Wybierz Godzinê:", wxPoint(550, 100), wxDefaultSize);
    timeText->SetFont(fontLabel);
    timeText->SetForegroundColour(wxColour(0, 0, 0));

    wxArrayString hours;
    hours.Add("10:00");
    hours.Add("13:00");
    hours.Add("16:00");
    hours.Add("19:00");
    hours.Add("22:00");
    hourChoice = new wxChoice(left_panel, wxID_ANY, wxPoint(530, 130), wxSize(200, -1), hours);
    hourChoice->SetFont(fontChoice);
    
    // Wybierz Typ
    typeLabelText = new wxStaticText(left_panel, wxID_ANY, "Wybierz Typ:", wxPoint(450, 230), wxDefaultSize);
    typeLabelText->SetFont(fontLabel);
    typeLabelText->SetForegroundColour(wxColour(0, 0, 0));
    
    wxArrayString type;
    type.Add("2D");
    type.Add("3D");
    type.Add("4DX");

    listbox0 = new wxListBox(left_panel, wxID_ANY, wxPoint(405, 270), wxSize(200, 75), type);
    listbox0->SetFont(fontLabel);
    
    // Wybierz Jêzyk
    languageLabelText = new wxStaticText(left_panel, wxID_ANY, "Wybierz Jêzyk:", wxPoint(200, 230), wxDefaultSize);
    languageLabelText->SetFont(fontLabel);
    languageLabelText->SetForegroundColour(wxColour(0, 0, 0));
    
    wxArrayString language;
    language.Add("Dubbing PL");
    language.Add("Lektor PL");
    language.Add("Angielski Napisy PL");
    listBox = new wxListBox(left_panel, wxID_ANY, wxPoint(165, 270), wxSize(200, 75), language);
    listBox->SetFont(fontLabel);
   
    // Panel prawy
    right_panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(504, 520));
    right_panel->SetBackgroundColour(wxColour(255, 255, 0));

    // Panel dolny (stopka)
    lower_panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(1260, 100));
    lower_panel->SetBackgroundColour(wxColour(0, 0, 0));

    // Przycisk "Wybór Biletów"
    button0 = new wxButton(lower_panel, wxID_ANY, "WYBÓR BILETÓW", wxPoint(560, 20), wxSize(200, 60));
    button0->Bind(wxEVT_BUTTON, &TicketFrame::OnButton0Clicked, this, wxID_ANY);
    button0->SetFont(fontLabel);

    // Sizer g³ówny
    main_sizer = new wxBoxSizer(wxVERTICAL);
    main_sizer->Add(upper_panel, 0, wxEXPAND);

    // Sizer lewy i prawy
    sub_sizer = new wxBoxSizer(wxHORIZONTAL);
    sub_sizer->Add(left_panel, 1, wxEXPAND);
    sub_sizer->Add(right_panel, 0, wxEXPAND);
    main_sizer->Add(sub_sizer, 1, wxEXPAND);
    main_sizer->Add(lower_panel, 0, wxEXPAND);

    SetSizerAndFit(main_sizer);
}

void TicketFrame::OnButton0Clicked(wxCommandEvent& evt)
{
    TicketTypeFrame* tickettypeFrame = new TicketTypeFrame("Wybierz Bilet");
    tickettypeFrame->Show();
    tickettypeFrame->SetClientSize(1280, 720);
    tickettypeFrame->SetMaxClientSize(wxSize(1280, 720));
    tickettypeFrame->Center();
}

void TicketFrame::Image(wxCommandEvent& evt)
{
    if (imageBitmap)
    {
        imageBitmap->Destroy();
        imageBitmap = nullptr;
    }
    wxString numer_zdj = choice->GetStringSelection();
    panel_zdj = new wxPanel(right_panel, wxID_ANY, wxPoint(80, 40), wxSize(350, 430));

    wxString imagePath;
    if (numer_zdj == "Movie 1")
        imagePath = wxT("image/movie1.jpg");
    else if (numer_zdj == "Movie 2")
        imagePath = wxT("image/movie2.jpg");
    else if (numer_zdj == "Movie 3")
        imagePath = wxT("image/movie3.jpg");
    else if (numer_zdj == "Movie 4")
        imagePath = wxT("image/movie4.jpg");
    else if (numer_zdj == "Movie 5")
        imagePath = wxT("image/movie5.jpg");
    else if (numer_zdj == "Movie 6")
        imagePath = wxT("image/movie6.jpg");
    else if (numer_zdj == "Movie 7")
        imagePath = wxT("image/movie7.jpg");
    else if (numer_zdj == "Movie 8")
        imagePath = wxT("image/movie8.jpg");

    if (!imagePath.IsEmpty())
    {
        wxImage image(imagePath);
        if (image.IsOk())
        {
            wxSize panel_size = panel_zdj->GetSize();
            wxImage scaled_image = image.Scale(panel_size.GetWidth(), panel_size.GetHeight(), wxIMAGE_QUALITY_HIGH);
            wxBitmap bitmap(scaled_image);
            imageBitmap = new wxStaticBitmap(panel_zdj, wxID_ANY, bitmap, wxDefaultPosition);
        }
    }
}