#ifndef CINEMA_SYSTEM_H
#define CINEMA_SYSTEM_H

#include <vector>
#include <memory>
#include "Movie.h"
#include "Room.h"
#include "Screening.h"
#include "Ticket.h"
#include "Seat.h"
#include "Booking.h"

class CinemaSystem {
public:
    CinemaSystem() = default;

    void addMovie(const std::shared_ptr<Movie>& movie);

    void addRoom(const std::shared_ptr<Room>& room);

    void addScreening(const std::shared_ptr<Screening>& screening);

    std::shared_ptr<Ticket> bookTicket(const std::shared_ptr<Screening>& screening, const std::shared_ptr<Seat>& seat, const std::string& customerName);

    void cancelTicket(const std::shared_ptr<Ticket>& ticket);

    void displayMovies() const;

    void displayScreenings() const;

    void displayBookings() const;

    static std::shared_ptr<Screening> getScreening(std::shared_ptr<Movie> movie, const std::string& dateTime);

    std::shared_ptr<Movie> getMovieFromTitle(const std::string& name);

private:
    std::vector<std::shared_ptr<Movie>> movies_;
    std::vector<std::shared_ptr<Room>> rooms_;
    std::vector<std::shared_ptr<Screening>> screenings_;
    std::vector<std::shared_ptr<Ticket>> tickets_;
    std::vector<std::shared_ptr<Booking>> bookings_;
};

#endif
