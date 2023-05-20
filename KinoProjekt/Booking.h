#ifndef BOOKING_H
#define BOOKING_H

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include "Screening.h"
#include "Ticket.h"

class Booking {
public:
    Booking(const std::shared_ptr<Screening>& screening, const std::string& customerName);

    std::shared_ptr<Screening> getScreening() const;
    std::string getCustomerName() const;
    std::vector<std::shared_ptr<Ticket>> getTickets() const;

    void addTicket(const std::shared_ptr<Ticket>& ticket);

    void removeTicket(const std::shared_ptr<Ticket>& ticket);

    void display() const;

private:
    std::shared_ptr<Screening> screening;
    std::string customerName;
    std::vector<std::shared_ptr<Ticket>> tickets;
};

#endif
