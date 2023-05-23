#pragma once
#include <wx/wx.h>
class ContactFrame : public wxFrame
{
public:
	ContactFrame(const wxString& title);
private:
	void OnCloseButtonClicked(wxCommandEvent& evt);
};
