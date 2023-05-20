#include "Ticket.h"

Ticket::Ticket(int id, const std::string& name, const std::string& description, std::shared_ptr<Screening> screening, std::shared_ptr<Seat> seat, const std::string& customerName)
    : CinemaItem(id, name, description), screening(screening), seat(seat), customerName(customerName) {

    seat->setIsBooked(true);
}

std::shared_ptr<Screening> Ticket::getScreening() const { return screening; }
std::shared_ptr<Seat> Ticket::getSeat() const { return seat; }
std::string Ticket::getCustomerName() const { return customerName; }

void Ticket::setScreening(const std::shared_ptr<Screening>& screening) { this->screening = screening; }
void Ticket::setSeat(const std::shared_ptr<Seat>& seat) { this->seat = seat; }
void Ticket::setCustomerName(const std::string& customerName) { this->customerName = customerName; }