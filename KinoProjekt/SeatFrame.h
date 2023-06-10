#pragma once
#include <wx/wx.h>
#include "PaymentFrame.h"
#include "MainFrame.h"
#include "Room.h"

#include <wx/grid.h>
#include <wx/checkbox.h>
#include <vector>

class SeatFrame : public wxFrame
{
public:
	SeatFrame(const wxString& title, const wxString& movie, const wxString& date, const wxString& time, const wxString& type, const wxString& language, const wxString& message, int ticketLimit);
private:
    void OnSeatSelected(wxCommandEvent& evt);
    void OnAcceptClicked(wxCommandEvent& evt);
    void GenerateSeats(std::shared_ptr<Room> room);
    void CreateButtons();
    void SetLayout();

    void OnBackButtonClicked(wxCommandEvent& evt);

	wxString movie, date, time, type, language, message;
    wxPanel* mainPanel;
    wxBoxSizer* mainSizer;
    wxPanel* panel0;
    wxStaticText* staticText0;
    wxPanel* panel1;
    wxPanel* panel2;
    wxStaticText* staticText1;
    wxButton* button0;
    wxButton* backbutton;
    wxGridSizer* seatGridSizer;
    wxPanel* buttonPanel;
    wxButton* acceptButton;
    std::vector<wxCheckBox*> checkBoxes;
    std::vector<wxBitmap> bitmaps;

    std::vector<int> selectedSeats;

    // Ticket selection GUI
    int ticketLimit;
    int selectedSeatsCount = 0;

    wxBitmap unselectedBitmap;
    wxBitmap selectedBitmap;

    wxDECLARE_EVENT_TABLE();
};

