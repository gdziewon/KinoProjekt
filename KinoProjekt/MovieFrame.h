#pragma once
#include <wx/wx.h>
class MovieFrame : public wxFrame
{
public:
	MovieFrame(const wxString& title);
private:
	wxStaticBitmap* imageBitmap;
	wxStaticBitmap* imageBitmap1;
	wxStaticBitmap* imageBitmap2;
	wxStaticBitmap* imageBitmap3;
	wxStaticBitmap* imageBitmap4;
	wxPanel* panel_zdj;
	wxPanel* callendar_zdj;
	wxPanel* stopwatch_zdj;
	wxPanel* movie_zdj;
	wxPanel* rating_zdj;
};