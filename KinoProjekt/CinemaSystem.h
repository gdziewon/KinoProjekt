// CinemaSystem.h
#include <string>
#include <vector>
#include <memory>
#include "User.h"
#include "Screening.h"
#include "DatabaseManager.h"
#include "Movie.h"

class CinemaSystem {
public:
    CinemaSystem() : dbManager(std::make_shared<DatabaseManager>()) {
        // Load data from the database
        users = dbManager->loadUsers();
        movies = dbManager->loadMovies();
        screenings = dbManager->loadScreenings();
    }

    // User-related methods
    bool registerUser(const std::string& username, const std::string& password) {
        if (findUser(username)) {
            return false;  // Username is already taken
        }

        auto user = std::make_shared<User>(username, HashFunction(password));
        users.push_back(user);
        dbManager->saveUsers(users);
        return true;
    }

    std::shared_ptr<User> loginUser(const std::string& username, const std::string& password) {
        auto user = findUser(username);
        if (user && user->validatePassword(password)) {
            return user;
        }
        return nullptr;  // Login failed
    }

    // Movie-related methods
    void addMovie(const std::string& title, double price) {
        auto movie = std::make_shared<Movie>(nextMovieId++, title, price);
        movies.push_back(movie);
        dbManager->saveMovies(movies);
    }

    void removeMovie(int movieId) {
        movies.erase(std::remove_if(movies.begin(), movies.end(),
            [movieId](const std::shared_ptr<Movie>& movie) {
                return movie->getId() == movieId;
            }), movies.end());
        dbManager->saveMovies(movies);
    }

    // Screening-related methods
    void addScreening(int movieId, int roomId, const std::string& time) {
        auto movie = findMovie(movieId);
        auto room = findRoom(roomId);
        if (!movie || !room) {
            return;  // Movie or room not found
        }

        auto screening = std::make_shared<Screening>(nextScreeningId++, movie, room, time);
        screenings.push_back(screening);
        dbManager->saveScreenings(screenings);
    }

    void removeScreening(int screeningId) {
        screenings.erase(std::remove_if(screenings.begin(), screenings.end(),
            [screeningId](const std::shared_ptr<Screening>& screening) {
                return screening->getId() == screeningId;
            }), screenings.end());
        dbManager->saveScreenings(screenings);
    }

    // Booking-related methods
    bool bookSeat(const std::string& username, int screeningId, int row, int col) {
        // Find the user
        auto user = findUser(username);
        if (!user) {
            return false;  // User not found
        }

        // Find the screening
        auto screening = findScreening(screeningId);
        if (!screening) {
            return false;  // Screening not found
        }

        // Book the seat and get the ticket
        auto ticket = screening->bookSeat(user->getUsername(), row, col);
        if (!ticket) {
            return false;  // Seat couldn't be booked
        }

        // Add the ticket to the user's collection
        user->addTicket(ticket);

        // Save the updated data to the database
        dbManager->saveUsers(users);
        dbManager->saveScreenings(screenings);

        return true;
    }

    bool cancelBooking(const std::string& username, int ticketId) {
        auto user = findUser(username);
        if (!user) {
            return false;  // User not found
        }

        auto ticket = user->findTicket(ticketId);
        if (!ticket) {
            return false;  // Ticket not found
        }

        auto screening = ticket->getScreening();
        if (!screening) {
            return false;  // Screening not found
        }

        // Cancel the booking and remove the ticket
        if (!screening->cancelBooking(ticketId)) {
            return false;  // Booking couldn't be cancelled
        }
        user->removeTicket(ticketId);

        // Save the updated data to the database
        dbManager->saveUsers(users);
        dbManager->saveScreenings(screenings);

        return true;
    }

private:
    std::shared_ptr<DatabaseManager> dbManager;  // The database manager
    std::vector<std::shared_ptr<User>> users;  // All users in the system
    std::vector<std::shared_ptr<Movie>> movies;  // All movies in the system
    std::vector<std::shared_ptr<Screening>> screenings;  // All screenings in the system
    int nextMovieId = 1;
    int nextScreeningId = 1;

    // Helper methods to find entities by id or username
    std::shared_ptr<User> findUser(const std::string& username) const {
        for (auto& user : users) {
            if (user->getUsername() == username) {
                return user;
            }
        }
        return nullptr;  // User not found
    }

    std::shared_ptr<Movie> findMovie(int id) const {
        for (auto& movie : movies) {
            if (movie->getId() == id) {
                return movie;
            }
        }
        return nullptr;  // Movie not found
    }

    std::shared_ptr<Screening> findScreening(int id) const {
        for (auto& screening : screenings) {
            if (screening->getId() == id) {
                return screening;
            }
        }
        return nullptr;  // Screening not found
    }
};

