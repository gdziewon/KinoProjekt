#pragma once
#include <wx/wx.h>

class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& title);
private:
	wxPanel* mainPanel;
	wxPanel* panel0;
	wxPanel* panel1;
	wxPanel* panel2;
	wxStaticText* staticText0;
	wxStaticBitmap* bitmap_image;
	wxBoxSizer* panel2Sizer;
	wxButton* button0;
	wxButton* button1;
	wxButton* button2;
	wxButton* button3;
	wxBoxSizer* mainSizer;

	void OnButton0Clicked(wxCommandEvent& evt);
	void OnButton1Clicked(wxCommandEvent& evt);
	void OnButton2Clicked(wxCommandEvent& evt);
	void OnButton3Clicked(wxCommandEvent& evt);
	void OnLoginClicked(wxCommandEvent& evt);
};