
#pragma once
#include <wx/wx.h>
class TicketTypeFrame : public wxFrame
{
public:
	TicketTypeFrame(const wxString& title);
private:
	void OnButton0Clicked(wxCommandEvent& evt);
};