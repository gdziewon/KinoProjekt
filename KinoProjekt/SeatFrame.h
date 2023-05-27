#pragma once
#include <wx/wx.h>
class SeatFrame : public wxFrame
{
public:
	SeatFrame(const wxString& title);
private:
	void OnButton0Clicked(wxCommandEvent& evt);
};

