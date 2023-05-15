#include <string>
#include <memory>
#include "Screening.h"
#include "Seat.h"

class Ticket : public CinemaItem {
public:
    Ticket(int id, const std::string& name, const std::string& description, std::shared_ptr<Screening> screening, std::shared_ptr<Seat> seat, const std::string& customerName)
        : CinemaItem(id, name, description), screening(screening), seat(seat), customerName(customerName) {
        
        seat->setIsBooked(true);
    }

    std::shared_ptr<Screening> getScreening() const { return screening; }
    std::shared_ptr<Seat> getSeat() const { return seat; }
    std::string getCustomerName() const { return customerName; }

    void setScreening(const std::shared_ptr<Screening>& screening) { this->screening = screening; }
    void setSeat(const std::shared_ptr<Seat>& seat) { this->seat = seat; }
    void setCustomerName(const std::string& customerName) { this->customerName = customerName; }

    
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
