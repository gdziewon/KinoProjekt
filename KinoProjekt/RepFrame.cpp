#include "RepFrame.h"
#include <wx/wx.h>

RepFrame::RepFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
    wxPanel* mainPanel = new wxPanel(this, wxID_ANY);
    wxPanel* panel0 = new wxPanel(mainPanel, wxID_ANY, wxDefaultPosition, wxSize(1280, 100));
    panel0->SetBackgroundColour(wxColor(0, 0, 0));
    wxPanel* panel1 = new wxPanel(mainPanel, wxID_ANY, wxDefaultPosition, wxSize(1280, 620));
    panel1->SetBackgroundColour(wxColor(255, 255, 255));

    wxStaticText* staticText0 = new wxStaticText(panel0, wxID_ANY, "Repertuar", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_VERTICAL);
    staticText0->SetFont(wxFont(60, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    staticText0->SetForegroundColour(wxColor(57, 255, 20));

    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    mainSizer->Add(panel0, 0, wxEXPAND);

    // Przyk³adowe dane plakatów filmów
    wxString movieTitles[8] = {
        "Film 1", "Film 2", "Film 3", "Film 4", "Film 5",
        "Film 6", "Film 7", "Film 8"
    };

    for (int i = 0; i < 8; i++)
    {
        wxString imagePath = wxString::Format(wxT("image/movie%d.jpg"), i + 1);
        wxBitmap moviePoster(imagePath, wxBITMAP_TYPE_JPEG);

        wxBitmapButton* movieButton = new wxBitmapButton(panel1, wxID_ANY, moviePoster);
        movieButton->Bind(wxEVT_BUTTON, &RepFrame::OnMovieButtonClick, this);
        movieButton->SetId(i + 1);
        movieButton->SetToolTip(wxString::Format("Poster %d", i + 1));
        movieButton->SetSize(wxSize(150, 200));

        int row = i / 4;
        int column = i % 4;
        int x = 120 + column * 300;
        int y = 30 + row * 300;
        movieButton->SetPosition(wxPoint(x, y));

        wxStaticText* movieTitleText = new wxStaticText(panel1, wxID_ANY, movieTitles[i], wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER);
        movieTitleText->SetFont(wxFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
        movieTitleText->SetForegroundColour(wxColor(0, 0, 0));
        movieTitleText->Bind(wxEVT_LEFT_DOWN, &RepFrame::OnMovieTitleClick, this);
        movieTitleText->SetId(i + 1);

        int row1 = i / 4;
        int column1 = i % 4; 
        int z = 150 + column1 * 300;
        int c = 260 + row1 * 300;
        movieTitleText->SetPosition(wxPoint(z, c));
    }

    mainSizer->Add(panel1, 1, wxEXPAND);
    mainPanel->SetSizer(mainSizer);
}

void RepFrame::OnMovieButtonClick(wxCommandEvent& event)
{
    
}

void RepFrame::OnMovieTitleClick(wxMouseEvent& event)
{

}