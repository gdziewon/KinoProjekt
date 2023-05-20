#ifndef ROOM_H
#define ROOM_H

#include <vector>
#include "CinemaItem.h"
#include "Seat.h"

class Room : public CinemaItem {
public:
    Room(int id, const std::string& name, const std::string& description, int numRows, int numSeatsPerRow);

    int getNumRows() const;
    int getNumSeatsPerRow() const;
    std::vector<std::shared_ptr<Seat>> getSeats() const;

    void setNumRows(int numRows);
    void setNumSeatsPerRow(int numSeatsPerRow);
    void setSeats(const std::vector<std::shared_ptr<Seat>>& seats);

    void display() const override {
        std::cout << "ID: " << getId()
            << ", Name: " << getName()
            << ", Description: " << getDescription()
            << ", Number of rows: " << numRows
            << ", Number of seats per row: " << numSeatsPerRow << std::endl;
    }

private:
    int numRows;
    int numSeatsPerRow;
    std::vector<std::shared_ptr<Seat>> seats;
};

#endif
