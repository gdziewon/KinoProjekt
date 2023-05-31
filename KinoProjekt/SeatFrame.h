#pragma once
#include <wx/wx.h>
class SeatFrame : public wxFrame
{
public:
	SeatFrame(const wxString& title, const wxString& movie, const wxString& date, const wxString& time, const wxString& type, const wxString& language, const wxString& message);
private:
	void OnButton0Clicked(wxCommandEvent& evt);
	wxString movie, date, time, type, language, message;
};

