#include "CinemaItem.h"

class Seat : public CinemaItem {
public:
    Seat(int id, int rowNum, int seatNum)
        : CinemaItem(id, "Seat " + std::to_string(id), "Row " + std::to_string(rowNum) + ", Seat " + std::to_string(seatNum)),
        rowNum(rowNum), seatNum(seatNum), isBooked(false) {}

    int getRowNum() const { return rowNum; }
    int getSeatNum() const { return seatNum; }
    bool getIsBooked() const { return isBooked; }

    void setRowNum(int rowNum) { this->rowNum = rowNum; }
    void setSeatNum(int seatNum) { this->seatNum = seatNum; }
    void setIsBooked(bool isBooked) { this->isBooked = isBooked; }

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
