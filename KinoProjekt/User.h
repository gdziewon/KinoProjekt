#include <string>
#include <vector>
#include <memory>
#include "Ticket.h"
#include "Review.h"
#include "Booking.h"
#include "Feedback.h"

class User {
public:
    User(const std::string& username, const std::string& hashedPassword)
        : username(username), hashedPassword(hashedPassword) {}

    
    std::string getUsername() const { return username; }
    std::string getHashedPassword() const { return hashedPassword; }

    
    void setUsername(const std::string& username) { this->username = username; }
    void setHashedPassword(const std::string& hashedPassword) { this->hashedPassword = hashedPassword; }

    
    void addTicket(const std::shared_ptr<Ticket>& ticket) { tickets.push_back(ticket); }
    bool removeTicket(int ticketId) {
        auto it = std::find_if(tickets.begin(), tickets.end(),
            [ticketId](const std::shared_ptr<Ticket>& ticket) {
                return ticket->getId() == ticketId;
            });
        if (it != tickets.end()) {
            tickets.erase(it);
            return true;
        }
        return false;
    }

    void writeReview(const std::string& content, int movieId) {
        auto review = std::make_shared<Review>(username, content, movieId);
        reviews.push_back(review);
    }

    void makeBooking(const std::shared_ptr<Booking>& booking) { bookings.push_back(booking); }

    void provideFeedback(const std::string& content) {
        auto feedback = std::make_shared<Feedback>(username, content);
        feedbacks.push_back(feedback);
    }

    void viewHistory() const {
        for (const auto& ticket : tickets) {
            std::cout << "Movie: " << ticket->getScreening()->getMovie()->getTitle()
                << ", Time: " << ticket->getScreening()->getTime()
                << ", Seat: " << ticket->getSeat()->getSeatNumber() << std::endl;
        }
    }

private:
    std::string username;
    std::string hashedPassword;
    std::vector<std::shared_ptr<Ticket>> tickets;
    std::vector<std::shared_ptr<Review>> reviews;
    std::vector<std::shared_ptr<Booking>> bookings;
    std::vector<std::shared_ptr<Feedback>> feedbacks;
};
