#ifndef ROOM_H
#define ROOM_H

#include <vector>
#include <fstream>

#include "CinemaItem.h"
#include "Seat.h"
#include "json.hpp"

using json = nlohmann::json;


class Room : public CinemaItem {
public:
    Room(int id, const std::string& name, const std::string& description, int numRows, int numColumns);

    int getNumRows() const;
    int getNumColumns() const;
    std::vector<std::shared_ptr<Seat>> getSeats() const;

    void setNumRows(int numRows);
    void setNumColumns(int numColumns);
    void setSeats(const std::vector<std::shared_ptr<Seat>>& seats);

    void display() const override {
        std::cout << "ID: " << getId()
            << ", Name: " << getName()
            << ", Description: " << getDescription()
            << ", Number of rows: " << numRows
            << ", Number of seats per row: " << numColumns << std::endl;
    }

private:
    int numRows;
    int numColumns;
    std::vector<std::shared_ptr<Seat>> seats_;
};

#endif