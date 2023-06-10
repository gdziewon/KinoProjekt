#include "SeatFrame.h"
#include "DatabaseManager.h"
#include "App.h"

wxBEGIN_EVENT_TABLE(SeatFrame, wxFrame)
	EVT_CHECKBOX(wxID_ANY, SeatFrame::OnSeatSelected)
	EVT_BUTTON(wxID_ANY, SeatFrame::OnAcceptClicked)
wxEND_EVENT_TABLE()

SeatFrame::SeatFrame(const wxString& title, const wxString& movie, const wxString& date, const wxString& time, const wxString& type, const wxString& language, const wxString& message, int ticketLimit)
	: wxFrame(nullptr, wxID_ANY, title), movie(movie), date(date), time(time), type(type), language(language), message(message), ticketLimit(ticketLimit)
{
	mainPanel = new wxPanel(this, wxID_ANY);
	mainSizer = new wxBoxSizer(wxVERTICAL);
	mainPanel->SetSizer(mainSizer);

	panel0 = new wxPanel(mainPanel, wxID_ANY, wxDefaultPosition, wxSize(1280, 100));
	panel0->SetBackgroundColour(wxColor(0, 0, 0));
	mainSizer->Add(panel0, 0, wxEXPAND);

	staticText0 = new wxStaticText(panel0, wxID_ANY, "Wybierz Miejsca", wxPoint(80, 5), wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);
	staticText0->SetFont(wxFont(60, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
	staticText0->SetForegroundColour(wxColor(40, 126, 75));

	panel1 = new wxPanel(mainPanel, wxID_ANY, wxDefaultPosition, wxSize(1280, 520));
	panel1->SetBackgroundColour(wxColor(65, 65, 65));
	mainSizer->Add(panel1, 1, wxEXPAND);

	panel2 = new wxPanel(mainPanel, wxID_ANY, wxDefaultPosition, wxSize(1280, 100));
	panel2->SetBackgroundColour(wxColor(0, 0, 0));
	mainSizer->Add(panel2, 0, wxEXPAND);

	staticText1 = new wxStaticText(panel2, wxID_ANY, "Twoje miejsca:", wxPoint(500, 0), wxDefaultSize, wxALIGN_CENTER);
	staticText1->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
	staticText1->SetForegroundColour(wxColor(255, 255, 255));

	button0 = new wxButton(panel2, wxID_ANY, L"Płatność", wxPoint(1000, 20), wxSize(200, 60));
	button0->Bind(wxEVT_BUTTON, &SeatFrame::OnAcceptClicked, this, wxID_ANY);
	button0->SetFont(wxFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));


	backbutton = new wxButton(panel2, wxID_ANY, "Anuluj", wxPoint(80, 20), wxSize(200, 60));
	backbutton->Bind(wxEVT_BUTTON, &SeatFrame::OnBackButtonClicked, this, wxID_ANY);
	backbutton->SetFont(wxFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));


	std::shared_ptr<Screening> screening = dbManager->getScreening(movie, time);
	std::shared_ptr<Room> room = screening->getRoom();

	seatGridSizer = new wxGridSizer(room->getNumRows(), room->getNumColumns(), 5, 5);
	buttonPanel = new wxPanel(this, wxID_ANY);

	GenerateSeats(room);
	CreateButtons();
	SetLayout();
}

void SeatFrame::OnAcceptClicked(wxCommandEvent& evt)
{
	PaymentFrame* paymentFrame = new PaymentFrame(wxT("Płatność"), movie, date, time, type, language, message);
	paymentFrame->Show();
	paymentFrame->SetClientSize(1280, 720);
	paymentFrame->SetMinClientSize(wxSize(1280, 720));
	paymentFrame->SetMaxClientSize(wxSize(1280, 720));
	paymentFrame->Center();
	Close();
}

void SeatFrame::OnSeatSelected(wxCommandEvent& evt) {
	wxCheckBox* checkBox = dynamic_cast<wxCheckBox*>(evt.GetEventObject());
	if (checkBox) {
		if (checkBox->IsChecked()) {
			if (selectedSeatsCount < ticketLimit) {
				checkBox->SetBackgroundColour(wxColour(0, 0, 255));
				selectedSeatsCount++;
			}
			else {
				checkBox->SetValue(false);
			}
		}
		else {
			checkBox->SetBackgroundColour(wxColour(0, 255, 0));
			selectedSeatsCount--;
		}
		checkBox->Refresh();
	}
}

/*void SeatFrame::GenerateSeats(std::shared_ptr<Room> room) {
	for (int i = 0; i < room->getNumRows(); i++) {
		for (int j = 0; j < room->getNumColumns(); j++) {
			std::shared_ptr<Seat> seat = room->getSeats()[i * room->getNumColumns() + j];
			if (seat->getIsBooked()) {
				wxPanel* panel = new wxPanel(this, wxID_ANY);
				panel->SetBackgroundColour(wxColour(255, 0, 0));
				seatGridSizer->Add(panel, 1, wxEXPAND);
			}
			else {
				wxCheckBox* checkBox = new wxCheckBox(this, wxID_ANY, "");
				checkBox->Bind(wxEVT_CHECKBOX, &SeatFrame::OnSeatSelected, this);
				checkBox->SetBackgroundColour(wxColour(0, 255, 0));
				checkBox->SetFont(wxFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
				checkBox->SetForegroundColour(wxColour(255, 255, 255));
				seatGridSizer->Add(checkBox, 1, wxEXPAND);
			}
		}
	}
}*/
void SeatFrame::GenerateSeats(std::shared_ptr<Room> room) {
	for (int i = 0; i < room->getNumRows(); i++) {
		wxBoxSizer* rowSizer = new wxBoxSizer(wxHORIZONTAL);  // Create a sizer for each row

		// Create a panel to represent the row label
		wxPanel* rowLabelPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(30, 30));
		rowLabelPanel->SetBackgroundColour(wxColour(0, 0, 0));  // Black background for row label
		wxStaticText* rowLabel = new wxStaticText(rowLabelPanel, wxID_ANY, wxString::Format("%d", i + 1));
		rowLabel->SetForegroundColour(wxColour(255, 255, 255));  // White text for row label
		wxBoxSizer* rowLabelSizer = new wxBoxSizer(wxHORIZONTAL);
		rowLabelSizer->Add(rowLabel, 1, wxALIGN_CENTER);
		rowLabelPanel->SetSizer(rowLabelSizer);

		// Add the row label panel to the row sizer
		rowSizer->Add(rowLabelPanel, 0, wxALIGN_CENTER | wxRIGHT, 5);

		for (int j = 0; j < room->getNumColumns(); j++) {
			std::shared_ptr<Seat> seat = room->getSeats()[i * room->getNumColumns() + j];
			if (seat->getIsBooked()) {
				wxPanel* panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(30, 30));
				panel->SetBackgroundColour(wxColour(255, 0, 0));  // Red color for booked seats
				rowSizer->Add(panel, 0, wxALL, 2);
			}
			else {
				wxCheckBox* checkBox = new wxCheckBox(this, wxID_ANY, "");
				checkBox->Bind(wxEVT_CHECKBOX, &SeatFrame::OnSeatSelected, this);
				checkBox->SetBackgroundColour(wxColour(0, 255, 0));  // Green color for available seats
				checkBox->SetForegroundColour(wxColour(255, 255, 255));
				rowSizer->Add(checkBox, 0, wxALL, 2);
			}
		}

		// Add the row sizer to the main seat grid sizer
		seatGridSizer->Add(rowSizer, 0, wxEXPAND);
	}
}

void SeatFrame::SetLayout()
{
	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);

	// Create a horizontal sizer for the seat grid and the back button
	wxBoxSizer* seatAndButtonSizer = new wxBoxSizer(wxHORIZONTAL);
	seatAndButtonSizer->Add(seatGridSizer, 1, wxEXPAND | wxALL, 10);

	// Add the seat grid and the back button sizer to the main sizer
	mainSizer->Add(seatAndButtonSizer, 1, wxEXPAND);
	mainSizer->Add(buttonPanel, 0, wxALIGN_CENTER_HORIZONTAL | wxBOTTOM | wxTOP, 10);

	SetSizerAndFit(mainSizer);
}

void SeatFrame::CreateButtons()
{
	wxBoxSizer* buttonSizer = new wxBoxSizer(wxHORIZONTAL);

	// Create the "Back" button
	wxButton* backButton = new wxButton(buttonPanel, wxID_ANY, wxT("Powrót"));
	backButton->SetSize(wxSize(100, 40)); // Set the button size
	backButton->Bind(wxEVT_BUTTON, &SeatFrame::OnBackButtonClicked, this);

	// Create the "Accept" button
	wxButton* acceptButton = new wxButton(buttonPanel, wxID_ANY, "Akceptuj");
	acceptButton->SetSize(wxSize(100, 40)); // Set the button size
	acceptButton->Bind(wxEVT_BUTTON, &SeatFrame::OnAcceptClicked, this);

	// Add the buttons to the button sizer
	buttonSizer->Add(backButton, 0, wxALL, 10);
	buttonSizer->Add(acceptButton, 0, wxALL, 10);

	// Set the button panel's sizer
	buttonPanel->SetSizer(buttonSizer);
}

void SeatFrame::OnBackButtonClicked(wxCommandEvent & evt)
{
	MainFrame* mainFrame = new MainFrame("Kino");
	mainFrame->Show();
	mainFrame->SetClientSize(1280, 720);
	mainFrame->SetMinClientSize(wxSize(1280, 720));
	mainFrame->SetMaxClientSize(wxSize(1280, 720));
	mainFrame->Center();
	Close();
}
