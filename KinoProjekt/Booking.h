#include <string>
#include <vector>
#include <iostream>
#include "Screening.h"
#include "Ticket.h"
#include "User.h"

class Booking {
public:
    Booking(const std::shared_ptr<Screening>& screening, const std::shared_ptr<User>& user)
        : screening(screening), user(user) {}

    std::shared_ptr<Screening> getScreening() const { return screening; }
    std::shared_ptr<User> getUser() const { return user; }
    std::vector<std::shared_ptr<Ticket>> getTickets() const { return tickets; }

    void addTicket(const std::shared_ptr<Ticket>& ticket) {
        tickets.push_back(ticket);
        user->addTicket(ticket);
    }

    void removeTicket(const std::shared_ptr<Ticket>& ticket) {
        auto it = std::find(tickets.begin(), tickets.end(), ticket);
        if (it != tickets.end()) {
            tickets.erase(it);
            user->removeTicket(ticket);
        }
    }

    void display() const {
        std::cout << "Booking Details:" << std::endl;
        std::cout << "Screening: " << screening->getName() << std::endl;
        std::cout << "User: " << user->getName() << std::endl;

        std::cout << "Tickets:" << std::endl;
        for (const auto& ticket : tickets) {
            ticket->display();
            std::cout << std::endl;
        }
    }

private:
    std::shared_ptr<Screening> screening;
    std::shared_ptr<User> user;
    std::vector<std::shared_ptr<Ticket>> tickets;
};

