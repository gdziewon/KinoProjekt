#ifndef SEAT_H
#define SEAT_H

#include "CinemaItem.h"

class Seat : public CinemaItem {
public:

    Seat(int id, int rowNum, int columnNum, bool isBooked = false);
    bool isBooked;
    int getRowNum() const;
    int getColumnNum() const;
    bool getIsBooked() const;

    void setRowNum(int rowNum);
    void setColumnNum(int columnNum);
    void setIsBooked(bool isBooked);

    void display() const override {
        std::cout << "ID: " << getId()
            << ", Name: " << getName()
            << ", Description: " << getDescription()
            << ", Row number: " << rowNum
            << ", Seat number: " << columnNum
            << ", Is booked: " << (isBooked ? "Yes" : "No") << std::endl;
    }

private:
    int rowNum;
    int columnNum;
};

#endif
