#include "Seat.h"

Seat::Seat(int id, int rowNum, int columnNum, bool isBooked)
    : CinemaItem(id, "Seat " + std::to_string(id), "Row " + std::to_string(rowNum) + ", Column " + std::to_string(columnNum)),
    rowNum(rowNum), columnNum(columnNum), isBooked(isBooked) {}

int Seat::getRowNum() const { return rowNum; }
int Seat::getColumnNum() const { return columnNum; }
bool Seat::getIsBooked() const { return isBooked; }

void Seat::setRowNum(int rowNum) { this->rowNum = rowNum; }
void Seat::setColumnNum(int columnNum) { this->columnNum = columnNum; }
void Seat::setIsBooked(bool isBooked) { this->isBooked = isBooked; }