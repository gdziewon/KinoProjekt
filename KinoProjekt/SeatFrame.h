#pragma once
#include <wx/wx.h>
#include "PaymentFrame.h"

class SeatFrame : public wxFrame
{
public:
	SeatFrame(const wxString& title, const wxString& movie, const wxString& date, const wxString& time, const wxString& type, const wxString& language, const wxString& message);
private:
	void OnButton0Clicked(wxCommandEvent& evt);
	wxString movie, date, time, type, language, message;

    wxPanel* mainPanel;
    wxBoxSizer* mainSizer;

    wxPanel* panel0;

    wxStaticText* staticText0;

    wxPanel* panel1;

    wxPanel* panel2;

    wxBoxSizer* panel2Sizer;

    wxStaticText* staticText1;

    wxButton* button0;
};

