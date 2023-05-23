#pragma once
#include <wx/wx.h>

class TicketFrame : public wxFrame
{
public:
	TicketFrame(const wxString& title);
private:
	void OnButton0Clicked(wxCommandEvent& evt);
};