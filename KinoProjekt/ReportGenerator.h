// ReportGenerator.h
#include <iostream>
#include <vector>
#include <iomanip>
#include "Movie.h"
#include "Screening.h"
#include "Booking.h"

class ReportGenerator {
public:
    static void generateMovieReport(const std::vector<std::shared_ptr<Movie>>& movies) {
        std::cout << "Movie Report" << std::endl;
        std::cout << "-------------------------" << std::endl;

        for (const auto& movie : movies) {
            std::cout << "Title: " << movie->getTitle() << std::endl;
            std::cout << "Genre: " << movie->getGenre() << std::endl;
            std::cout << "Director: " << movie->getDirector() << std::endl;
            std::cout << "Running Time: " << movie->getRunningTime() << " minutes" << std::endl;

            std::cout << "Screenings:" << std::endl;
            for (const auto& screening : movie->getScreenings()) {
                std::cout << "Date: " << screening->getDate() << std::endl;
                std::cout << "Time: " << screening->getTime() << std::endl;
                std::cout << "Room: " << screening->getRoom() << std::endl;
                std::cout << "Tickets Sold: " << screening->getTicketsSold() << std::endl;
                std::cout << std::endl;
            }

            std::cout << "-------------------------" << std::endl;
        }
    }

    static void generateBookingReport(const std::vector<std::shared_ptr<Booking>>& bookings) {
        std::cout << "Booking Report" << std::endl;
        std::cout << "-------------------------" << std::endl;

        for (const auto& booking : bookings) {
            std::cout << "User: " << booking->getUser()->getName() << std::endl;

            std::cout << "Screening: " << booking->getScreening()->getMovie()->getTitle() << std::endl;
            std::cout << "Date: " << booking->getScreening()->getDate() << std::endl;
            std::cout << "Time: " << booking->getScreening()->getTime() << std::endl;
            std::cout << "Room: " << booking->getScreening()->getRoom() << std::endl;

            std::cout << "Tickets:" << std::endl;
            for (const auto& ticket : booking->getTickets()) {
                std::cout << "Ticket ID: " << ticket->getTicketId() << std::endl;
                std::cout << "Seat: " << ticket->getSeat() << std::endl;
                std::cout << std::endl;
            }

            std::cout << "-------------------------" << std::endl;
        }
    }
};

