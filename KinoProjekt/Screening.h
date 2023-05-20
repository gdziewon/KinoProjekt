#ifndef SCREENING_H
#define SCREENING_H

#include <string>
#include <memory>
#include "CinemaItem.h"
#include "Movie.h"
#include "Room.h"

class Screening : public CinemaItem {
public:
    Screening(int id, const std::string& name, const std::string& description, std::shared_ptr<Movie> movie, std::shared_ptr<Room> room, const std::string& dateTime, double price);

    //Getters
    std::shared_ptr<Movie> getMovie() const;
    std::shared_ptr<Room> getRoom() const;
    std::string getDateTime() const;
    double getPrice() const;

    //Setters
    void setMovie(const std::shared_ptr<Movie>& movie);
    void setRoom(const std::shared_ptr<Room>& room);
    void setDateTime(const std::string& dateTime);
    void setPrice(double price);

    void display() const override {
        std::cout << "ID: " << getId()
            << ", Name: " << getName()
            << ", Description: " << getDescription()
            << ", Movie: " << movie->getName()
            << ", Room: " << room->getName()
            << ", Date and time: " << dateTime
            << ", Price: " << price << std::endl;
    };

private:
    std::shared_ptr<Movie> movie;
    std::shared_ptr<Room> room;
    std::string dateTime;
    double price;
};
#endif
