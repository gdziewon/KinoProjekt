#pragma once
#include <wx/wx.h>

#include "MovieFrame.h"

class RepFrame : public wxFrame
{
public:
	RepFrame(const wxString& title);
private:
	void OnMovieButtonClick(wxCommandEvent& event);
	void OnMovieTitleClick(wxMouseEvent& event);

	wxPanel* mainPanel;
	wxPanel* panel0;
	wxScrolledWindow* panel1;
	wxPanel* panel2;

	wxStaticText* staticText0;
	wxStaticText* movieTitleText;

	wxBitmapButton* movieButton;

	wxBoxSizer* mainSizer;

	MovieFrame* movieFrame;
};