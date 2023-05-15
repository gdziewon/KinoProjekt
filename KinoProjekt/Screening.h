// Screening.h
#include <string>
#include <memory>
#include "CinemaItem.h"
#include "Movie.h"
#include "Room.h"

class Screening : public CinemaItem {
public:
    Screening(int id, const std::string& name, const std::string& description, std::shared_ptr<Movie> movie, std::shared_ptr<Room> room, const std::string& dateTime, double price)
        : CinemaItem(id, name, description), movie(movie), room(room), dateTime(dateTime), price(price) {}

    std::shared_ptr<Movie> getMovie() const { return movie; }
    std::shared_ptr<Room> getRoom() const { return room; }
    std::string getDateTime() const { return dateTime; }
    double getPrice() const { return price; }

    void setMovie(const std::shared_ptr<Movie>& movie) { this->movie = movie; }
    void setRoom(const std::shared_ptr<Room>& room) { this->room = room; }
    void setDateTime(const std::string& dateTime) { this->dateTime = dateTime; }
    void setPrice(double price) { this->price = price; }

    void display() const override {
        std::cout << "ID: " << getId()
            << ", Name: " << getName()
            << ", Description: " << getDescription()
            << ", Movie: " << movie->getName()
            << ", Room: " << room->getName()
            << ", Date and time: " << dateTime
            << ", Price: " << price << std::endl;
    }

private:
    std::shared_ptr<Movie> movie;
    std::shared_ptr<Room> room;
    std::string dateTime;
    double price;
};
