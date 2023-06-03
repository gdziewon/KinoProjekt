#pragma once
#include <wx/wx.h>

class ContactFrame : public wxDialog
{
public:
	ContactFrame(const wxString& title);

private:
	void OnCloseButtonClicked(wxCommandEvent& event);

	wxPanel* mainPanel;
	wxPanel* panel0;
	wxPanel* panel1;

	wxBoxSizer* mainSizer;
	wxBoxSizer* panel2Sizer;
	
	wxStaticText* staticText0;
	wxStaticText* emailText;
	wxStaticText* staticText2;
	wxStaticText* staticText3;

	wxFont titleFont;
	wxFont textFont;
	wxFont buttonFont;

	wxButton* closeButton;
};