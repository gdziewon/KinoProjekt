#pragma once
#include "App.h"
#include <wx/wx.h>
#include "MainFrame.h";
#include <unordered_map>
class PaymentFrame : public wxFrame
{
public:
	PaymentFrame(const wxString& title, const wxString& movie, const wxString& date, const wxString& time, const wxString& type, const wxString& language, const wxString& message, int ticketLimit);
private:
	void OnButton0Clicked(wxCommandEvent& evt);
	void OnBackButtonClicked(wxCommandEvent& evt);

	wxString movie, date, time, type, language, message;
	
	wxPanel* mainPanel;
	wxPanel* topPanel;
	wxPanel* leftPanel;
	wxPanel* rightPanel;
	wxPanel* bottomPanel;

	wxStaticText* staticText0;
	wxStaticText* staticText1;
	wxStaticText* staticText2;

	wxStaticText* movieText;
	wxStaticText* dateText;
	wxStaticText* hourText;
	wxStaticText* languageText;
	wxStaticText* roomText;
	wxStaticText* seatText;
	wxStaticText* priceText;
	wxStaticText* nameText;
	wxStaticText* surnameText;
	wxStaticText* emailText;
	wxStaticText* phoneText;
	wxStaticText* cardText;
	wxStaticText* datecardText;
	wxStaticText* cvcText;

	wxTextCtrl* nameCtrl;
	wxTextCtrl* surnameCtrl;
	wxTextCtrl* emailCtrl;
	wxTextCtrl* phoneCtrl;
	wxTextCtrl* cardNumberCtrl;
	wxTextCtrl* expiryDateCtrl;
	wxTextCtrl* cvcCtrl;

	wxButton* button0;
	wxButton* backbutton;

	wxBoxSizer* mainSizer;
	wxBoxSizer* horizontalSizer;

	std::string customer_name;
	std::string seance_id;
	int row;
	int column;

	int ticketLimit;
};

