#pragma once
#include <wx/wx.h>

#include "MainFrame.h";

class YourTicketFrame : public wxFrame
{
public:
	YourTicketFrame(const wxString& title);
	
private:
	wxPanel* mainPanel;
	wxPanel* topPanel;
	wxPanel* midPanel;
	wxPanel* bottomPanel;

	wxBoxSizer* mainSizer;

	wxStaticText* staticText0;

	wxButton* backbutton;

	void OnBackButtonClicked(wxCommandEvent& evt);
};
