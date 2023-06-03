#pragma once
#include <wx/wx.h>
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

};
