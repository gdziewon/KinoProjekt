#pragma once
#include <wx/wx.h>
#include <wx/datectrl.h>
#include <wx/statbmp.h>
#include <map>
#include <iomanip>


class TicketFrame : public wxFrame
{
public:
    TicketFrame(const wxString& title);
private:
    void OnButton0Clicked(wxCommandEvent& evt);
    void Image(wxCommandEvent& evt);

    // Panels
    wxPanel* right_panel;
    wxPanel* panel_zdj;
    wxPanel* upper_panel;
    wxPanel* left_panel;
    wxPanel* lower_panel;
    wxBoxSizer* main_sizer;
    wxBoxSizer* sub_sizer;

    // Labels
    wxStaticText* staticText0;
    wxStaticText* movieLabelText;
    wxStaticText* dateTimeText;
    wxStaticText* timeText;
    wxStaticText* typeLabelText;
    wxStaticText* languageLabelText;

    // Buttons
    wxChoice* choice;
    wxChoice* hourChoice;
    wxListBox* listbox0;
    wxListBox* listBox;
    wxDatePickerCtrl* datePicked;
    wxButton* button0;

    // Fonts
    wxFont fontTitle;
    wxFont fontLabel;
    wxFont fontChoice;

    wxStaticBitmap* imageBitmap;
    wxString imagePath;

};

