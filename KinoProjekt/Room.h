#include <vector>
#include "CinemaItem.h"
#include "Seat.h"

class Room : public CinemaItem {
public:
    Room(int id, const std::string& name, const std::string& description, int numRows, int numSeatsPerRow)
        : CinemaItem(id, name, description), numRows(numRows), numSeatsPerRow(numSeatsPerRow) {
        
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numSeatsPerRow; ++j) {
                seats.push_back(std::make_shared<Seat>(i * numSeatsPerRow + j, i, j));
            }
        }
    }

    int getNumRows() const { return numRows; }
    int getNumSeatsPerRow() const { return numSeatsPerRow; }
    std::vector<std::shared_ptr<Seat>> getSeats() const { return seats; }

    void setNumRows(int numRows) { this->numRows = numRows; }
    void setNumSeatsPerRow(int numSeatsPerRow) { this->numSeatsPerRow = numSeatsPerRow; }
    void setSeats(const std::vector<std::shared_ptr<Seat>>& seats) { this->seats = seats; }

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
