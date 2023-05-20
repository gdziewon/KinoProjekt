#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <unordered_map>
#include "Movie.h"
#include "Room.h"
#include "Screening.h"
#include "Ticket.h"

class DatabaseManager {
public:
    DatabaseManager();

    // Movie-related methods
    std::unordered_map<int, std::shared_ptr<Movie>> loadMovies();

    void saveMovies(const std::unordered_map<int, std::shared_ptr<Movie>>& movies);

    // Room-related methods
    std::unordered_map<int, std::shared_ptr<Room>> loadRooms();

    void saveRooms(const std::unordered_map<int, std::shared_ptr<Room>>& rooms);

    // Screening-related methods
    std::unordered_map<int, std::shared_ptr<Screening>> loadScreenings();

    void saveScreenings(const std::unordered_map<int, std::shared_ptr<Screening>>& screenings);

    // Ticket-related methods
    std::unordered_map<int, std::shared_ptr<Ticket>> loadTickets();

    void saveTickets(const std::unordered_map<int, std::shared_ptr<Ticket>>& tickets);

private:
    // TODO: Database connection information
};
#endif