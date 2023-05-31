#include <wx/wx.h>

#include "MovieFrame.h"

struct MovieData
{
    wxString title;
    wxString releaseDate;
    wxString duration;
    wxString director;
    wxString genre;
    wxString description;
    wxString imagePath;
};


MovieData GetMovieDataFromDatabase()
{
    MovieData movie;
    movie.title = "Joker";
    movie.releaseDate = "04.10.2019";
    movie.duration = "122 minuty";
    movie.director = "Todd Phillips";
    movie.genre = "Krymina³ Dramat Thriller";
    movie.description = "Opis filmu Joker...";
    movie.imagePath = wxT("image/movie1.jpg");

    return movie;
}

MovieFrame::MovieFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
    MovieData movieData = GetMovieDataFromDatabase();

    wxPanel* mainPanel = new wxPanel(this, wxID_ANY);

    wxPanel* panel0 = new wxPanel(mainPanel, wxID_ANY, wxDefaultPosition, wxSize(1280, 80));
    panel0->SetBackgroundColour(wxColor(0, 0, 0));

    wxStaticText* staticText0 = new wxStaticText(panel0, wxID_ANY, movieData.title, wxPoint(50,5), wxDefaultSize, wxALIGN_CENTER_VERTICAL);
    staticText0->SetFont(wxFont(50, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    staticText0->SetForegroundColour(wxColor(57, 255, 20));

    wxPanel* panel1 = new wxPanel(mainPanel, wxID_ANY, wxDefaultPosition, wxSize(1280, 80));
    panel1->SetBackgroundColour(wxColor(255, 255, 255));

    wxStaticText* staticText = new wxStaticText(panel1, wxID_ANY, movieData.releaseDate, wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_VERTICAL);
    staticText->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    staticText->SetForegroundColour(wxColor(0, 0, 0));

    wxStaticText* staticText1 = new wxStaticText(panel1, wxID_ANY, movieData.duration, wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_VERTICAL);
    staticText1->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    staticText1->SetForegroundColour(wxColor(0, 0, 0));

    wxStaticText* staticText2 = new wxStaticText(panel1, wxID_ANY, movieData.director, wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_VERTICAL);
    staticText2->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    staticText2->SetForegroundColour(wxColor(0, 0, 0));

    wxStaticText* staticText3 = new wxStaticText(panel1, wxID_ANY, movieData.genre, wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_VERTICAL);
    staticText3->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    staticText3->SetForegroundColour(wxColor(0, 0, 0));

    wxStaticText* staticText4 = new wxStaticText(panel1, wxID_ANY, movieData.description, wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_VERTICAL);
    staticText4->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    staticText4->SetForegroundColour(wxColor(0, 0, 0));

    wxPanel* panel2 = new wxPanel(mainPanel, wxID_ANY, wxDefaultPosition, wxSize(1280, 80));
    panel2->SetBackgroundColour(wxColor(0, 0, 0));

    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    mainSizer->Add(panel0, 0, wxEXPAND);
    mainSizer->Add(panel1, 1, wxEXPAND);
    mainSizer->Add(panel2, 0, wxEXPAND);
    mainPanel->SetSizer(mainSizer);
}