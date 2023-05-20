#ifndef SEAT_H
#define SEAT_H

#include "CinemaItem.h"

class Seat : public CinemaItem {
public:
    Seat(int id, int rowNum, int seatNum);

    int getRowNum() const;
    int getSeatNum() const;
    bool getIsBooked() const;

    void setRowNum(int rowNum);
    void setSeatNum(int seatNum);
    void setIsBooked(bool isBooked);

    void display() const override {
        std::cout << "ID: " << getId()
            << ", Name: " << getName()
            << ", Description: " << getDescription()
            << ", Row number: " << rowNum
            << ", Seat number: " << seatNum
            << ", Is booked: " << (isBooked ? "Yes" : "No") << std::endl;
    }

private:
    int rowNum;
    int seatNum;
    bool isBooked;
};

#endif
