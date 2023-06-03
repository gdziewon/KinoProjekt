#pragma once
#include "Screening.h"
#include <wx/wx.h>
class SeatFrame : public wxFrame
{
public:
	SeatFrame(const wxString& title, int totalSeats, Screening& screening);
private:
	void OnButton0Clicked(wxCommandEvent& evt);
	void GenerateSeats(Room& room);
	void OnSeatSelected(wxCommandEvent& event);
	int totalSeats;
	Screening& screening;
};

