#include "Screening.h"

Screening::Screening(int id, const std::string& name, const std::string& description, std::shared_ptr<Movie> movie, std::shared_ptr<Room> room, const std::string& dateTime, double price)
    : CinemaItem(id, name, description), movie(movie), room(room), dateTime(dateTime), price(price) {}

//Getters
std::shared_ptr<Movie> Screening::getMovie() const { return movie; }
std::shared_ptr<Room> Screening::getRoom() const { return room; }
std::string Screening::getDateTime() const { return dateTime; }
double Screening::getPrice() const { return price; }

//Setters
void Screening::setMovie(const std::shared_ptr<Movie>& movie) { this->movie = movie; }
void Screening::setRoom(const std::shared_ptr<Room>& room) { this->room = room; }
void Screening::setDateTime(const std::string& dateTime) { this->dateTime = dateTime; }
void Screening::setPrice(double price) { this->price = price; }