#pragma once
#include <wx/wx.h>
class RepFrame : public wxFrame
{
public:
	RepFrame(const wxString& title);
private:
	void OnMovieButtonClick(wxCommandEvent& event);
	void OnMovieTitleClick(wxMouseEvent& event);
};