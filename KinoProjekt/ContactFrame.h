#pragma once
#include <wx/wx.h>
class ContactFrame : public wxDialog
{
public:
	ContactFrame(const wxString& title);
private:
	void OnCloseButtonClicked(wxCommandEvent& evt);
};
