#include <wx/wx.h>

#include "MovieFrame.h"

struct MovieData
{
    wxString title;
    wxString releaseDate;
    wxString duration;
    wxString director;
    wxString rating;
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
    movie.rating = "8.4";
    movie.genre = "Krymina� Dramat Thriller";
    movie.description = "Joker to film o tytu�owym bohaterze z uniwersum Batmana.\nTo historia Arthura Flecka, cz�owieka cierpi�cego na\nzaburzenia psychiczne, kt�ry wpl�tuje si� w �wiat\nprzest�pczo�ci i staje si� ikon� z�a.";
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

    callendar_zdj = new wxPanel(panel1, wxID_ANY, wxPoint(100, 25), wxSize(50, 50));
    wxImage callendar(wxT("image/Calendar.png"));
    if (callendar.IsOk())
    {
        wxSize panel_size1 = callendar_zdj->GetSize();
        wxImage scaled_image1 = callendar.Scale(panel_size1.GetWidth(), panel_size1.GetHeight(), wxIMAGE_QUALITY_HIGH);
        wxBitmap bitmap1(scaled_image1);
        imageBitmap1 = new wxStaticBitmap(callendar_zdj, wxID_ANY, bitmap1, wxDefaultPosition);
    }

    wxStaticText* staticText = new wxStaticText(panel1, wxID_ANY, movieData.releaseDate, wxPoint(155, 45), wxDefaultSize, wxALIGN_CENTER_VERTICAL);
    staticText->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    staticText->SetForegroundColour(wxColor(0, 0, 0));

    wxStaticText* dateLabel = new wxStaticText(panel1, wxID_ANY, "DATA PREMIERY:", wxPoint(155, 30), wxDefaultSize, wxALIGN_CENTER_VERTICAL);
    dateLabel->SetFont(wxFont(13, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    dateLabel->SetForegroundColour(wxColor(0, 0, 0));

    stopwatch_zdj = new wxPanel(panel1, wxID_ANY, wxPoint(450, 25), wxSize(50, 50));
    wxImage stopwatch(wxT("image/Stopwatch.png"));
    if (stopwatch.IsOk())
    {
        wxSize panel_size2 = stopwatch_zdj->GetSize();
        wxImage scaled_image2 = stopwatch.Scale(panel_size2.GetWidth(), panel_size2.GetHeight(), wxIMAGE_QUALITY_HIGH);
        wxBitmap bitmap2(scaled_image2);
        imageBitmap2 = new wxStaticBitmap(stopwatch_zdj, wxID_ANY, bitmap2, wxDefaultPosition);
    }

    wxStaticText* durationLabel = new wxStaticText(panel1, wxID_ANY, "CZAS TRWANIA:", wxPoint(505, 30), wxDefaultSize, wxALIGN_CENTER_VERTICAL);
    durationLabel->SetFont(wxFont(13, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    durationLabel->SetForegroundColour(wxColor(0, 0, 0));

    wxStaticText* staticText1 = new wxStaticText(panel1, wxID_ANY, movieData.duration, wxPoint(505, 45), wxDefaultSize, wxALIGN_CENTER_VERTICAL);
    staticText1->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    staticText1->SetForegroundColour(wxColor(0, 0, 0));

    movie_zdj = new wxPanel(panel1, wxID_ANY, wxPoint(100, 125), wxSize(50, 50));
    wxImage movie(wxT("image/Movie.png"));
    if (movie.IsOk())
    {
        wxSize panel_size3 = movie_zdj->GetSize();
        wxImage scaled_image3 = movie.Scale(panel_size3.GetWidth(), panel_size3.GetHeight(), wxIMAGE_QUALITY_HIGH);
        wxBitmap bitmap3(scaled_image3);
        imageBitmap3 = new wxStaticBitmap(movie_zdj, wxID_ANY, bitmap3, wxDefaultPosition);
    }

    wxStaticText* directorLabel = new wxStaticText(panel1, wxID_ANY, "RE�YSER:", wxPoint(155, 130), wxDefaultSize, wxALIGN_CENTER_VERTICAL);
    directorLabel->SetFont(wxFont(13, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    directorLabel->SetForegroundColour(wxColor(0, 0, 0));

    wxStaticText* staticText2 = new wxStaticText(panel1, wxID_ANY, movieData.director, wxPoint(155, 145), wxDefaultSize, wxALIGN_CENTER_VERTICAL);
    staticText2->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    staticText2->SetForegroundColour(wxColor(0, 0, 0));

    rating_zdj = new wxPanel(panel1, wxID_ANY, wxPoint(450, 125), wxSize(50, 50));
    wxImage rating(wxT("image/rating.png"));
    if (rating.IsOk())
    {
        wxSize panel_size4 = rating_zdj->GetSize();
        wxImage scaled_image4 = rating.Scale(panel_size4.GetWidth(), panel_size4.GetHeight(), wxIMAGE_QUALITY_HIGH);
        wxBitmap bitmap4(scaled_image4);
        imageBitmap4 = new wxStaticBitmap(rating_zdj, wxID_ANY, bitmap4, wxDefaultPosition);
    }

    wxStaticText* ratingLabel = new wxStaticText(panel1, wxID_ANY, "OCENA:", wxPoint(505, 130), wxDefaultSize, wxALIGN_CENTER_VERTICAL);
    ratingLabel->SetFont(wxFont(13, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    ratingLabel->SetForegroundColour(wxColor(0, 0, 0));

    wxStaticText* ratingText = new wxStaticText(panel1, wxID_ANY, movieData.rating+" / 10", wxPoint(505, 145), wxDefaultSize, wxALIGN_CENTER_VERTICAL);
    ratingText->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    ratingText->SetForegroundColour(wxColor(0, 0, 0));

    wxStaticText* staticText3 = new wxStaticText(panel1, wxID_ANY, "Gatunek:\n"+movieData.genre, wxPoint(100, 225), wxDefaultSize, wxALIGN_CENTER_VERTICAL);
    staticText3->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    staticText3->SetForegroundColour(wxColor(0, 0, 0));

    wxStaticText* staticText4 = new wxStaticText(panel1, wxID_ANY, "Opis Filmu:\n"+movieData.description, wxPoint(100, 325), wxDefaultSize, wxALIGN_CENTER_VERTICAL);
    staticText4->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    staticText4->SetForegroundColour(wxColor(0, 0, 0));

    wxInitAllImageHandlers();
    panel_zdj = new wxPanel(panel1, wxID_ANY, wxPoint(870, 25), wxSize(345, 512));
    wxImage image(movieData.imagePath);
    if (image.IsOk())
    {
        wxSize panel_size = panel_zdj->GetSize();
        wxImage scaled_image = image.Scale(panel_size.GetWidth(), panel_size.GetHeight(), wxIMAGE_QUALITY_HIGH);
        wxBitmap bitmap(scaled_image);
        imageBitmap = new wxStaticBitmap(panel_zdj, wxID_ANY, bitmap, wxDefaultPosition);
    }

    wxPanel* panel2 = new wxPanel(mainPanel, wxID_ANY, wxDefaultPosition, wxSize(1280, 80));
    panel2->SetBackgroundColour(wxColor(0, 0, 0));

    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    mainSizer->Add(panel0, 0, wxEXPAND);
    mainSizer->Add(panel1, 1, wxEXPAND);
    mainSizer->Add(panel2, 0, wxEXPAND);
    mainPanel->SetSizer(mainSizer);
}