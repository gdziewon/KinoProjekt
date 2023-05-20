#include "Seat.h"

Seat::Seat(int id, int rowNum, int seatNum)
    : CinemaItem(id, "Seat " + std::to_string(id), "Row " + std::to_string(rowNum) + ", Seat " + std::to_string(seatNum)),
    rowNum(rowNum), seatNum(seatNum), isBooked(false) {}

int Seat::getRowNum() const { return rowNum; }
int Seat::getSeatNum() const { return seatNum; }
bool Seat::getIsBooked() const { return isBooked; }

void Seat::setRowNum(int rowNum) { this->rowNum = rowNum; }
void Seat::setSeatNum(int seatNum) { this->seatNum = seatNum; }
void Seat::setIsBooked(bool isBooked) { this->isBooked = isBooked; }