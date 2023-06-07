#pragma once
#include <wx/wx.h>

#include "TicketFrame.h"
#include "RepFrame.h"
#include "ContactFrame.h"
#include "YourTicketFrame.h"

class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& title);
private:
	wxPanel* mainPanel;
	wxPanel* panel0;
	wxPanel* panel1;
	wxPanel* panel2;

	wxBoxSizer* panel2Sizer;
	wxBoxSizer* mainSizer;

	wxStaticText* staticText0;
	wxStaticBitmap* bitmap_image;
	
	wxButton* button0;
	wxButton* button1;
	wxButton* button2;
	wxButton* button3;
	
	RepFrame* repFrame;
	ContactFrame* contactFrame;

	void OnButton0Clicked(wxCommandEvent& evt);
	void OnButton1Clicked(wxCommandEvent& evt);
	void OnButton2Clicked(wxCommandEvent& evt);
	void OnButton3Clicked(wxCommandEvent& evt);
};