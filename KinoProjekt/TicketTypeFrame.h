#pragma once
#include <wx/wx.h>
#include "SeatFrame.h"
#include "TicketFrame.h"

#include <wx/spinctrl.h>

class TicketTypeFrame : public wxFrame
{
public:
	TicketTypeFrame(const wxString& title, const wxString& movie, const wxString& date, const wxString& time, const wxString& type, const wxString& language);
private:
	void OnButton0Clicked(wxCommandEvent& evt);
	void OnSpin(wxSpinEvent& event);
	void OnBackButtonClicked(wxCommandEvent& evt);

	wxPanel* mainPanel;
	wxPanel* panel0;
	wxPanel* panel1;
	wxPanel* panel2;

	wxSpinCtrl* spinCtrl0;
	wxSpinCtrl* spinCtrl1;
	wxStaticText* spinText;

	wxStaticText* staticText0;
	wxStaticText* staticText4;
	wxStaticText* staticText6;
	wxStaticText* staticText5;
	wxStaticText* staticText7;

	wxStaticText* label1;
	wxStaticText* label2;
	wxStaticText* label3;

	wxButton* button0;
	wxButton* backbutton;

	wxBoxSizer* sizer1;
	wxBoxSizer* mainSizer;
	wxBoxSizer* spinCtrlSizer0;

	wxString movie, date, time, type, language;

	wxString message;
};