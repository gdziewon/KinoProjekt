#include "RepFrame.h"
#include "MovieFrame.h"

#include <wx/wx.h>

RepFrame::RepFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
    wxPanel* mainPanel = new wxPanel(this, wxID_ANY);

    wxPanel* panel0 = new wxPanel(mainPanel, wxID_ANY, wxDefaultPosition, wxSize(1280, 80));
    panel0->SetBackgroundColour(wxColor(0, 0, 0));

    wxScrolledWindow* panel1 = new wxScrolledWindow(mainPanel, wxID_ANY);
    panel1->SetSize(1280, 700);
    panel1->SetScrollbars(0, 20, 0, 84); // Set the scrollbar parameters
    panel1->SetBackgroundColour(wxColor(255, 255, 255));

    wxPanel* panel2 = new wxPanel(mainPanel, wxID_ANY, wxDefaultPosition, wxSize(1280, 80));
    panel2->SetBackgroundColour(wxColor(0, 0, 0));

    wxStaticText* staticText0 = new wxStaticText(panel0, wxID_ANY, "Repertuar", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_VERTICAL);
    staticText0->SetFont(wxFont(50, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    staticText0->SetForegroundColour(wxColor(57, 255, 20));

    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    mainSizer->Add(panel0, 0, wxEXPAND);
    mainSizer->Add(panel1, 1, wxEXPAND);
    mainSizer->Add(panel2, 0, wxEXPAND);

    // Przyk³adowe dane plakatów filmów
    wxString movieTitles[8] = {
        "Joker", "Beau Is Afraid", "Film 3", "Film 4", "Film 5",
        "Film 6", "Film 7", "Film 8"
    };

    for (int i = 0; i < 8; i++)
    {
        wxString imagePath = wxString::Format(wxT("image/movie%d.jpg"), i + 1);
        wxImage image(imagePath, wxBITMAP_TYPE_JPEG);

        wxSize buttonSize = wxSize(310, 460);  // define the size of the button

        wxImage scaled_image = image.Scale(buttonSize.GetWidth(), buttonSize.GetHeight(), wxIMAGE_QUALITY_HIGH);
        wxBitmap moviePoster(scaled_image);

        wxBitmapButton* movieButton = new wxBitmapButton(panel1, wxID_ANY, moviePoster);
        movieButton->Bind(wxEVT_BUTTON, &RepFrame::OnMovieButtonClick, this);
        movieButton->SetId(i + 1);
        movieButton->SetToolTip(wxString::Format("Plakat %d", i + 1));
        movieButton->SetSize(buttonSize);

        int row = i / 3;
        int column = i % 3;
        int x = 80 + column * 400;
        int y = 30 + row * 560;
        movieButton->SetPosition(wxPoint(x, y));

        wxStaticText* movieTitleText = new wxStaticText(panel1, wxID_ANY, movieTitles[i], wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER);
        movieTitleText->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
        movieTitleText->SetForegroundColour(wxColor(0, 0, 0));
        movieTitleText->Bind(wxEVT_LEFT_DOWN, &RepFrame::OnMovieTitleClick, this);
        movieTitleText->SetId(i + 1);

        int row1 = i / 4;
        int column1 = i % 4;
        int z = 150 + column1 * 300;
        int c = 260 + row1 * 300;
        int titleX = x + buttonSize.GetWidth() / 2 - movieTitleText->GetSize().GetWidth() / 2;
        int titleY = y + buttonSize.GetHeight() + 20;
        movieTitleText->SetPosition(wxPoint(titleX, titleY));
    }
    
    mainPanel->SetSizer(mainSizer);
}

void RepFrame::OnMovieButtonClick(wxCommandEvent& evt)
{
    MovieFrame* movieFrame = new MovieFrame("Film");
    movieFrame->Show();
    movieFrame->SetClientSize(1280, 720);
    movieFrame->SetMinClientSize(wxSize(1280, 720));
    movieFrame->SetMaxClientSize(wxSize(1280, 720));
    movieFrame->Center();
}

void RepFrame::OnMovieTitleClick(wxMouseEvent& evt)
{
    MovieFrame* movieFrame = new MovieFrame("Film");
    movieFrame->Show();
    movieFrame->SetClientSize(1280, 720);
    movieFrame->SetMinClientSize(wxSize(1280, 720));
    movieFrame->SetMaxClientSize(wxSize(1280, 720));
    movieFrame->Center();
}