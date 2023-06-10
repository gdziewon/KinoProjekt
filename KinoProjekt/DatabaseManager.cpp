#include "DatabaseManager.h"
#include "json.hpp"
#include <fstream>

#include "App.h"

using json = nlohmann::json;



DatabaseManager::DatabaseManager() {
	// Initialize database connection
	// TODO: Implement the code to establish a database connection

	Initialize();
}
DatabaseManager& DatabaseManager::getInstance() {
	static DatabaseManager instance; 
	return instance;
}

void DatabaseManager::Initialize()
{
	loadMovies(Configuration::moviesFilePath);
	loadRooms(Configuration::roomsFilePath);
	loadScreenings(Configuration::screeningsFilePath);
	loadTickets(Configuration::ticketsFilePath);
}

void DatabaseManager::loadMovies(const std::string& moviesFilePath) {
	std::ifstream file(moviesFilePath);

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


void DatabaseManager::loadRooms(const std::string& filePath = Configuration::roomsFilePath) {
	std::ifstream file(filePath);

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


void DatabaseManager::loadScreenings(const std::string& filePath = Configuration::screeningsFilePath) {
	std::ifstream file(filePath);

	if (!file.is_open()) {
		std::cout << "Couldn't open file." << std::endl;
		return;  // Return an empty vector
	}

	json j;
	file >> j;
	int id = 3;

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
	// if not found return nullptr
	return nullptr;
}

std::shared_ptr<Screening> DatabaseManager::getScreening(const wxString& movie, const wxString& time)
{
	auto it = std::find_if(screenings_.begin(), screenings_.end(),
		[movie, time](const std::shared_ptr<Screening>& ptr)
		{
			return ptr->getMovie()->getName() == movie && ptr->getScreeningTime() == time;
		});

	if (it != screenings_.end())
	{
		return *it;
	}
	// if not found return nullptr
	return nullptr;
}

//--------na razie nie wiem czy potrzebujemy pobierac bilety z bazy
void DatabaseManager::loadTickets(const std::string& filePath = Configuration::ticketsFilePath) {
	std::ifstream file(filePath);

	if (!file.is_open()) {
		std::cout << "Couldn't open file." << std::endl;
		return;  // Return an empty vector
	}

	json j;
	file >> j;

	for (auto& customerElement : j["customers"]) {
		std::string customerName = customerElement["customer_name"];

		// for some reason our json files have screeningId as a String data type
		// therefore we shall convert
		std::string screeningIdString = customerElement["seance_id"];
		int screeningId = std::atoi(screeningIdString.c_str());

		int row = customerElement["row"];
		int column = customerElement["column"];
		
		std::shared_ptr<Screening> screening = getScreening(screeningId);
		std::shared_ptr<Room> room = screening->getRoom();
		int id = row * room->getNumColumns() + column;


		std::shared_ptr<Seat> seat = getSeat(row, column, room); //nie ma takich funkcji :(

		std::shared_ptr<Ticket> ticket = std::make_shared<Ticket>(id, "", "", screening, seat, customerName);
		tickets_.push_back(ticket);
		++id;
	}
}

bool DatabaseManager::isSeatReserved(int movieId, int roomId, int row, int column) {
	std::ifstream file(Configuration::ticketsFilePath);
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

std::shared_ptr<Seat> DatabaseManager::getSeat(int row, int column, std::shared_ptr<Room> room) const
{
	std::vector<std::shared_ptr<Seat>> seats_ = room->getSeats();

	auto it = std::find_if(seats_.begin(), seats_.end(),
		[row, column](const std::shared_ptr<Seat>& ptr)
		{
			return (ptr->getRowNum() == row && ptr->getColumnNum() == column);
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

std::shared_ptr<Seat> DatabaseManager::getSeat(int seatId, std::shared_ptr<Room> room) const
{
	std::vector<std::shared_ptr<Seat>> seats_ = room->getSeats();

	auto it = std::find_if(seats_.begin(), seats_.end(),
		[seatId](const std::shared_ptr<Seat>& ptr)
		{
			return (ptr->getId() == seatId);
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

void DatabaseManager::saveTickets(const std::vector<std::shared_ptr<Ticket>>& tickets) {
	json j;

	for (const auto& ticket : tickets) {
		json ticketJson;
		ticketJson["customer_name"] = ticket -> getCustomerName();  // You might want to replace "blank" with actual data
		ticketJson["seance_id"] = "hii"; // Same here
		ticketJson["row"] = 1;  // And here
		ticketJson["column"] = 3;  // And here too

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
}

std::string* DatabaseManager::getTitles() {
	std::string* titles = new std::string[9];
	int j = 0;
	for (auto& movies : movies_) {
		titles[j] = movies->getName();
		j++;
	}
	return titles;
}