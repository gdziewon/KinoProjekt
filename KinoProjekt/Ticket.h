#ifndef TICKET_H
#define TICKET_H

#include <string>
#include <memory>
#include "CinemaItem.h"
#include "Screening.h"
#include "Seat.h"

class Ticket : public CinemaItem {
public:
    Ticket(int id, const std::string& name, const std::string& description, std::shared_ptr<Screening> screening, std::shared_ptr<Seat> seat, const std::string& customerName);

    std::shared_ptr<Screening> getScreening() const;
    std::shared_ptr<Seat> getSeat() const;
    std::string getCustomerName() const;

    void setScreening(const std::shared_ptr<Screening>& screening);
    void setSeat(const std::shared_ptr<Seat>& seat);
    void setCustomerName(const std::string& customerName);

    
    void display() const override {
        std::cout << "ID: " << getId()
            << ", Name: " << getName()
            << ", Description: " << getDescription()
            << ", Screening: " << screening->getName()
            << ", Seat: " << seat->getName()
            << ", Customer name: " << customerName << std::endl;
    }

private:
    std::shared_ptr<Screening> screening;
    std::shared_ptr<Seat> seat;
    std::string customerName;
};

#endif