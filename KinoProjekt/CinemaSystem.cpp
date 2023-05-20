#include "CinemaSystem.h"

void CinemaSystem::addMovie(const std::shared_ptr<Movie>& movie) {
    movies_.push_back(movie);
}

void CinemaSystem::addRoom(const std::shared_ptr<Room>& room) {
    rooms_.push_back(room);
}

void CinemaSystem::addScreening(const std::shared_ptr<Screening>& screening) {
    screenings_.push_back(screening);
}

std::shared_ptr<Ticket> CinemaSystem::bookTicket(const std::shared_ptr<Screening>& screening, const std::shared_ptr<Seat>& seat, const std::string& customerName) {
    if (!seat->getIsBooked()) {
        auto ticket = std::make_shared<Ticket>(tickets_.size(),
            "Ticket " + std::to_string(tickets_.size()),
            "Ticket for " + screening->getName(), screening, seat, customerName);
        tickets_.push_back(ticket);
        seat->setIsBooked(true);
        return ticket;
    }
    else {
        std::cout << "Seat is already booked." << std::endl;
        return nullptr;
    }
}

void CinemaSystem::cancelTicket(const std::shared_ptr<Ticket>& ticket) {
    auto it = std::find(tickets_.begin(), tickets_.end(), ticket);
    if (it != tickets_.end()) {
        ticket->getSeat()->setIsBooked(false);
        tickets_.erase(it);
    }
}

void CinemaSystem::displayMovies() const {
    std::cout << "Movies:\n";
    for (const auto& movie : movies_) {
        movie->display();
    }
}

void CinemaSystem::displayScreenings() const {
    std::cout << "Screenings:\n";
    for (const auto& screening : screenings_) {
        screening->display();
    }
}

void CinemaSystem::displayBookings() const {
    std::cout << "Bookings:\n";
    for (const auto& booking : bookings_) {
        booking->display();
    }
}
