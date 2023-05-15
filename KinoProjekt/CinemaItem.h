#include <unordered_map>
#include "User.h"
#include "Movie.h"
#include "Room.h"
#include "Screening.h"
#include "Ticket.h"
#include "DatabaseManager.h"

class CinemaSystem {
public:
    CinemaSystem() {
        dbManager = std::make_shared<DatabaseManager>();
    }

    void loadData() {
        users = dbManager->loadUsers();
        movies = dbManager->loadMovies();
        rooms = dbManager->loadRooms();
        screenings = dbManager->loadScreenings();
        tickets = dbManager->loadTickets();
    }

    void saveData() {
        dbManager->saveUsers(users);
        dbManager->saveMovies(movies);
        dbManager->saveRooms(rooms);
        dbManager->saveScreenings(screenings);
        dbManager->saveTickets(tickets);
    }

    void addUser(const std::shared_ptr<User>& user) { users[user->getId()] = user; }
    void removeUser(int userId) { users.erase(userId); }

    void addMovie(const std::shared_ptr<Movie>& movie) { movies[movie->getId()] = movie; }
    void removeMovie(int movieId) { movies.erase(movieId); }

    void addRoom(const std::shared_ptr<Room>& room) { rooms[room->getId()] = room; }
    void removeRoom(int roomId) { rooms.erase(roomId); }

    void addScreening(const std::shared_ptr<Screening>& screening) { screenings[screening->getId()] = screening; }
    void removeScreening(int screeningId) { screenings.erase(screeningId); }

    void addTicket(const std::shared_ptr<Ticket>& ticket) { tickets[ticket->getId()] = ticket; }
    void removeTicket(int ticketId) { tickets.erase(ticketId); }

private:
    std::unordered_map<int, std::shared_ptr<User>> users;
    std::unordered_map<int, std::shared_ptr<Movie>> movies;
    std::unordered_map<int, std::shared_ptr<Room>> rooms;
    std::unordered_map<int, std::shared_ptr<Screening>> screenings;
    std::unordered_map<int, std::shared_ptr<Ticket>> tickets;
    std::shared_ptr<DatabaseManager> dbManager;
};
