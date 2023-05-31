#pragma once
#include <wx/wx.h>
class TicketTypeFrame : public wxFrame
{
public:
	TicketTypeFrame(const wxString& title, const wxString& movie, const wxString& date, const wxString& time, const wxString& type, const wxString& language);
private:
	void OnButton0Clicked(wxCommandEvent& evt);
	void OnSpin(wxSpinEvent& event);
	wxSpinCtrl* spinCtrl0;
	wxSpinCtrl* spinCtrl1;
	wxStaticText* spinText;

	wxString movie, date, time, type, language;

	wxString message;
};