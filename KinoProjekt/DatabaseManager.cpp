#include "DatabaseManager.h"
<<<<<<< Updated upstream
#include "json.hpp"
#include <fstream>
=======
#include <vector>
#include <memory>
>>>>>>> Stashed changes

using json = nlohmann::json;

DatabaseManager::DatabaseManager() {
<<<<<<< Updated upstream
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
    //hiii
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
=======
	// Initialize database connection
	// TODO: Implement the code to establish a database connection
	this->loadMovies();
	this->loadRooms();
	this->loadScreenings();
	this->loadTickets();
}

void DatabaseManager::loadMovies() {
	std::ifstream file("movies.json");

	if (!file.is_open()) {
		std::cout << "Couldn't open file." << std::endl;
		return;// Return an empty vector
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
		std::string releaseDate = movieElement["release_Date"];
		int runningTime = movieElement["runningTime"];

		// Create a new Movie object and add it to the vector
		std::shared_ptr<Movie> movie = std::make_shared<Movie>(id, name, description, actors, director, genre, releaseDate, runningTime);
		movies_.push_back(movie);

		// Increment id for the next movie
		++id;
	}
}

std::shared_ptr<Movie> DatabaseManager::getMovie(int movieId)
{
	auto it = std::find_if(movies_.begin(), movies_.end(),
		[movieId](const std::shared_ptr<Movie>& ptr)
		{
			return ptr->getId() == movieId;
		});

	if (it != movies_.end())
	{
		return *it;
	}
	else
	{
		return nullptr;
	}
}

std::shared_ptr<Movie> DatabaseManager::getMovie(std::string movieTitle)
{
	return nullptr;
}


void DatabaseManager::loadRooms() {
	std::ifstream file("rooms.json");

	if (!file.is_open()) {
		std::cout << "Couldn't open file." << std::endl;
		return;  // Return an empty vector
	}

	json j;
	file >> j;

	for (auto& roomElement : j) {
		int roomId = std::stoi(roomElement["id"].get<std::string>());
		std::string roomName = "Room" + roomId;
		int seatsQuantity = roomElement["seatsQuantity"];
		std::string roomDescription = roomName + ": a comfortable cinematic experience accustomed for seating " + std::to_string(seatsQuantity) + " people.";
		int rows = roomElement["rows"];
		int columns = roomElement["columns"];

		// Create a new Room object and add it to the vector
		std::shared_ptr<Room> room = std::make_shared<Room>(roomId, roomName, roomDescription, rows, columns);
		rooms_.push_back(room);
	}
}

std::shared_ptr<Room> DatabaseManager::getRoom(int roomId)
{
	auto it = std::find_if(rooms_.begin(), rooms_.end(),
		[roomId](const std::shared_ptr<Room>& ptr)
		{
			return ptr->getId() == roomId;
		});

	if (it != rooms_.end())
	{
		return *it;
	}
	else
	{
		return nullptr;
	}
}


void DatabaseManager::loadScreenings() {
	std::ifstream file("screenings.json");

	if (!file.is_open()) {
		std::cout << "Couldn't open file." << std::endl;
		return;  // Return an empty vector
	}

	json j;
	file >> j;
	int id = 1;

	for (auto& screeningElement : j) {
		int movieId = screeningElement["movie_id"];
		int roomId = screeningElement["_room_id"];
		std::string screeningTime = screeningElement["screening_time"];

		// Retrieve the movie and room objects from their respective data sources
		std::shared_ptr<Movie> movie = getMovie(movieId);
		std::shared_ptr<Room> room = getRoom(roomId);

		// Create a new Screening object and add it to the vector
		std::shared_ptr<Screening> screening = std::make_shared<Screening>(id, "", "", movie, room, screeningTime, 0.0);
		screenings_.push_back(screening);

		// Increment id for the next screening
		++id;
	}

}

std::shared_ptr<Screening> DatabaseManager::getScreening(int screeningId)
{
	auto it = std::find_if(screenings_.begin(), screenings_.end(),
		[screeningId](const std::shared_ptr<Screening>& ptr)
		{
			return ptr->getId() == screeningId;
		});

	if (it != screenings_.end())
	{
		return *it;
	}
	else
	{
		return nullptr;
	}
}

//--------na razie nie wiem czy potrzebujemy pobierac bilety z bazy
void DatabaseManager::loadTickets() {
	std::ifstream file("tickets.json");

	if (!file.is_open()) {
		std::cout << "Couldn't open file." << std::endl;
		return;  // Return an empty vector
	}

	json j;
	file >> j;

	for (auto& customerElement : j["customers"]) {
		std::string customerName = customerElement["customer_name"];
		int screeningId = customerElement["seance_id"];
		int row = customerElement["row"];
		int column = customerElement["column"];

		std::shared_ptr<Screening> screening = getScreening(screeningId);
		std::shared_ptr<Room> room = screening->getRoom();
		std::vector<std::shared_ptr<Seat>> seats_ = room->getSeats();

		std::shared_ptr<Seat> seat = getSeat(row, column, seats_); //nie ma takich funkcji :(

		std::shared_ptr<Ticket> ticket = std::make_shared<Ticket>(0, "", "", screening, seat, customerName);
		tickets_.push_back(ticket);
	}
}

bool DatabaseManager::isSeatReserved(int movieId, int roomId, int row, int column) {
	std::ifstream file("tickets.json");
	if (!file.is_open()) {
		std::cout << "Couldn't open tickets file." << std::endl;
		return false;
	}

	json j;
	file >> j;
	file.close();

	for (const auto& customer : j["customers"]) {
		int customerRoomId = customer["room_id"];
		int customerMovieId = customer["movie_id"];
		int customerRow = customer["row"];
		int customerColumn = customer["column"];

		if (customerMovieId == movieId && customerRoomId == roomId && customerRow == row && customerColumn == column) {
			std::cout << "Seat is already reserved." << std::endl;
			return true;
		}
	}

	std::cout << "Seat is not reserved." << std::endl;
	return false;
}

std::shared_ptr<Seat> DatabaseManager::getSeat(int row, int column, const std::vector<std::shared_ptr<Seat>>& seats_)
{
	auto it = std::find_if(seats_.begin(), seats_.end(),
		[row, column](const std::shared_ptr<Seat>& ptr)
		{
			return ptr->getRowNum() == row && ptr->getColumnNum() == column;
		});

	if (it != seats_.end())
	{
		return *it;
	}
	else
	{
		return nullptr;
	}
}


/*void DatabaseManager::saveTicket(int movieId, int roomId, int row, int column) {
	std::ifstream file("tickets.json");
	json j;

	if (file.is_open()) {
		file >> j;
		file.close();
	}

	json ticketJson;
	ticketJson["movie_id"] = movieId;
	ticketJson["room_id"] = roomId;
	ticketJson["row"] = row;
	ticketJson["column"] = column;
	ticketJson["name"] = customer_name;

	j["customers"].push_back(ticketJson);

	std::ofstream outFile("tickets.json");
	if (outFile.is_open()) {
		outFile << j.dump(4);
		outFile.close();
		std::cout << "Ticket saved successfully." << std::endl;
	}
	else {
		std::cout << "Couldn't open file for saving ticket." << std::endl;
	}
}*/

void DatabaseManager::saveTickets(const std::unordered_map<int, std::shared_ptr<Ticket>>& tickets) {
	json j;

	for (const auto& pair : tickets) {
		const std::shared_ptr<Ticket>& ticket = pair.second;
		json ticketJson;
		ticketJson["customer_name"] = "blank";
		ticketJson["seance_id"] = "blank";
		ticketJson["row"] = 0;
		ticketJson["column"] = 0;

		j.push_back(ticketJson);
	}

	std::ofstream file("tickets.json");
	if (file.is_open()) {
		file << j.dump(4);
		file.close();
		std::cout << "Tickets saved successfully." << std::endl;
	}
	else {
		std::cout << "Couldn't open file for saving tickets." << std::endl;
	}
>>>>>>> Stashed changes
}
