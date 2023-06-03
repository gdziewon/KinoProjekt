#include "DatabaseManager.h"
#include "json.hpp"
#include <fstream>

using json = nlohmann::json;

DatabaseManager::DatabaseManager() {
    // Initialize database connection
    // TODO: Implement the code to establish a database connection
}

std::unordered_map<int, std::shared_ptr<Movie>> DatabaseManager::loadMovies() {
    std::unordered_map<int, std::shared_ptr<Movie>> movies;
    std::ifstream file("movies.json");

    if (!file.is_open()) {
        std::cout << "Couldn't open file." << std::endl;
        return movies;  // Return an empty map
    }

    json j;
    file >> j;
    int id = 1;

    for (auto& movieElement : j) {
        std::string name = movieElement["name"];
        std::vector<std::string> actors = movieElement["actors"].get<std::vector<std::string>>();
        std::string description = movieElement["description"];
        std::string director = movieElement["director"];
        std::string genre = movieElement["genre"];
        std::string release_Date = movieElement["release_Date"];
        int runningTime = movieElement["runningTime"];

        // create a new Movie object and insert it into the map
        std::shared_ptr<Movie> movie = std::make_shared<Movie>(id, name, actors, description, director, genre, release_Date, runningTime);
        movies.insert({ id, movie });

        // increment id for the next movie
        ++id;
    }

    return movies;  // Return the populated map
}

void DatabaseManager::saveMovies(const std::unordered_map<int, std::shared_ptr<Movie>>& movies) {
    // TODO: Implement the code to save movies to the database
}

std::unordered_map<int, std::shared_ptr<Room>> DatabaseManager::loadRooms() {
    std::unordered_map<int, std::shared_ptr<Room>> rooms;
    std::ifstream file("rooms.json");

    if (!file.is_open()) {
        std::cout << "Couldn't open file." << std::endl;
        return rooms;  // Return an empty map
    }

    json j;
    file >> j;
    int id = 1;

    for (auto& roomElement : j) {
        int roomId = std::stoi(roomElement["id"].get<std::string>());
        int seatsQuantity = roomElement["seatsQuantity"];
        int rows = roomElement["rows"];
        int columns = roomElement["columns"];

        // Create a new Room object and insert it into the map
        std::shared_ptr<Room> room = std::make_shared<Room>(roomId, seatsQuantity, rows, columns);
        rooms.insert({ roomId, room });

        // Increment id for the next room
        ++id;
    }

    return rooms;  // Return the populated map
}

void DatabaseManager::saveRooms(const std::unordered_map<int, std::shared_ptr<Room>>& rooms) {
    // TODO: Implement the code to save rooms to the database
}

std::unordered_map<int, std::shared_ptr<Screening>> DatabaseManager::loadScreenings() {
    std::unordered_map<int, std::shared_ptr<Screening>> screenings;

    // TODO: Implement the code to load screenings from the database

    return screenings; // Return the populated map
}

void DatabaseManager::saveScreenings(const std::unordered_map<int, std::shared_ptr<Screening>>& screenings) {
    // TODO: Implement the code to save screenings to the database
}

std::unordered_map<int, std::shared_ptr<Ticket>> DatabaseManager::loadTickets() {
    std::unordered_map<int, std::shared_ptr<Ticket>> tickets;

    // TODO: Implement the code to load tickets from the database

    return tickets; // Return the populated map
}

void DatabaseManager::saveTickets(const std::unordered_map<int, std::shared_ptr<Ticket>>& tickets) {
    // TODO: Implement the code to save tickets to the database
}
