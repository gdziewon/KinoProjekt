#include "Room.h"

Room::Room(int id, const std::string& name, const std::string& description, int numRows, int numSeatsPerRow)
    : CinemaItem(id, name, description), numRows(numRows), numSeatsPerRow(numSeatsPerRow) {

    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numSeatsPerRow; ++j) {
            seats.push_back(std::make_shared<Seat>(i * numSeatsPerRow + j, i, j));
        }
    }
}

int Room::getNumRows() const { return numRows; }
int Room::getNumSeatsPerRow() const { return numSeatsPerRow; }
std::vector<std::shared_ptr<Seat>> Room::getSeats() const { return seats; }

void Room::setNumRows(int numRows) { this->numRows = numRows; }
void Room::setNumSeatsPerRow(int numSeatsPerRow) { this->numSeatsPerRow = numSeatsPerRow; }
void Room::setSeats(const std::vector<std::shared_ptr<Seat>>& seats) { this->seats = seats; }