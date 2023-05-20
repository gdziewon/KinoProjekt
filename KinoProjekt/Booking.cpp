#include "Booking.h"

Booking::Booking(const std::shared_ptr<Screening>& screening, const std::string& customerName)
        : screening(screening), customerName(customerName) {}

    std::shared_ptr<Screening> Booking::getScreening() const { return screening; }
    std::string Booking::getCustomerName() const { return customerName; }
    std::vector<std::shared_ptr<Ticket>> Booking::getTickets() const { return tickets; }

    void Booking::addTicket(const std::shared_ptr<Ticket>& ticket) {
        tickets.push_back(ticket);
    }

    void Booking::removeTicket(const std::shared_ptr<Ticket>& ticket) {
        auto it = std::find(tickets.begin(), tickets.end(), ticket);
        if (it != tickets.end()) {
            tickets.erase(it);
        }
    }

    void Booking::display() const {
        std::cout << "Booking Details:" << std::endl;
        std::cout << "Screening: " << screening->getName() << std::endl;
        std::cout << "Customer: " << customerName << std::endl;

        std::cout << "Tickets:" << std::endl;
        for (const auto& ticket : tickets) {
            ticket->display();
            std::cout << std::endl;
        }
    }
