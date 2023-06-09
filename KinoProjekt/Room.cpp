#include "Room.h"

Room::Room(int id, const std::string& name, const std::string& description, int numRows, int numColumns)
    : CinemaItem(id, name, description), numRows(numRows), numColumns(numColumns) {

    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numColumns; ++j) {
            seats_.push_back(std::make_shared<Seat>(i * numColumns + j, i, j));
        }
    }
}

int Room::getNumRows() const { return numRows; }
int Room::getNumColumns () const { return numColumns; }
std::vector<std::shared_ptr<Seat>> Room::getSeats() const { return seats_; }

void Room::setNumRows(int numRows) { this->numRows = numRows; }
void Room::setNumColumns(int numColumns) { this->numColumns = numColumns; }
void Room::setSeats(const std::vector<std::shared_ptr<Seat>>& seats) { this->seats_ = seats; }