#pragma once
#include <wx/wx.h>
#include "RepFrame.h"

class MovieFrame : public wxFrame
{
public:
	MovieFrame(const wxString& title);
private:
	void OnBackButtonClicked(wxCommandEvent& evt);

	wxPanel* mainPanel;
	wxPanel* panel0;
	wxPanel* panel1;
	wxPanel* panel2;

	wxBoxSizer* mainSizer;

	wxStaticText* staticText;
	wxStaticText* staticText0;
	wxStaticText* staticText1;
	wxStaticText* staticText2;
	wxStaticText* ratingText;
	wxStaticText* staticText3;
	wxStaticText* staticText4;

	wxStaticText* dateLabel;
	wxStaticText* durationLabel;
	wxStaticText* directorLabel;
	wxStaticText* ratingLabel;

	wxStaticBitmap* imageBitmap;
	wxStaticBitmap* imageBitmap1;
	wxStaticBitmap* imageBitmap2;
	wxStaticBitmap* imageBitmap3;
	wxStaticBitmap* imageBitmap4;

	wxPanel* panel_zdj;
	wxPanel* callendar_zdj;
	wxPanel* stopwatch_zdj;
	wxPanel* movie_zdj;
	wxPanel* rating_zdj;

	wxButton* backbutton;
};