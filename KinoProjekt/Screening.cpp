#include "Screening.h"

Screening::Screening(int id, const std::string& name, const std::string& description, std::shared_ptr<Movie> movie, std::shared_ptr<Room> room, const std::string& screeningTime, double price)
    : CinemaItem(id, name, description), movie(movie), room(room), screeningTime(screeningTime), price(price) {}

//Getters
std::shared_ptr<Movie> Screening::getMovie() const { return movie; }
std::shared_ptr<Room> Screening::getRoom() const { return room; }
std::string Screening::getScreeningTime() const { return screeningTime; }
double Screening::getPrice() const { return price; }

//Setters
void Screening::setMovie(const std::shared_ptr<Movie>& movie) { this->movie = movie; }
void Screening::setRoom(const std::shared_ptr<Room>& room) { this->room = room; }
void Screening::setScreeningTime(const std::string& screeningTime) { this->screeningTime = screeningTime; }
void Screening::setPrice(double price) { this->price = price; }