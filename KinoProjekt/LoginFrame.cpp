#include "LoginFrame.h"
#include <wx/wx.h>

LoginFrame::LoginFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
	wxPanel* panel = new wxPanel(this);
	wxButton* button0 = new wxButton(panel, wxID_ANY, "WYBÓR BILETÓW", wxPoint(10, 100), wxSize(100, 35));
}
