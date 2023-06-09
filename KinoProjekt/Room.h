#ifndef ROOM_H
#define ROOM_H

#include <vector>
#include "CinemaItem.h"
#include "Seat.h"
#include "DatabaseManager.h"
#include "json.hpp"
#include <fstream>

using json = nlohmann::json;


class Room {
public:
    Room(int id, int seatsQuantity, int rows, int columns)
        : id_(id), seatsQuantity_(seatsQuantity), rows_(rows), columns_(columns) {}

    // Getters for the variables (optional)
    int getId() const { return id_; }
    int getSeatsQuantity() const { return seatsQuantity_; }
    int getRows() const { return rows_; }
    int getColumns() const { return columns_; }

private:
    int id_;
    int seatsQuantity_;
    int rows_;
    int columns_;
};
#endif ROOM_H

/*class Room : public CinemaItem {
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
*/