#pragma once
#include <wx/wx.h>
class PaymentFrame : public wxFrame
{
public:
	PaymentFrame(const wxString& title);
private:
	void OnButton0Clicked(wxCommandEvent& evt);
};

