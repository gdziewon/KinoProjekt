#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include "json.hpp"
#include <memory>
#include <fstream>
#include <wx/wx.h>

#include "Movie.h"
#include "Room.h"
#include "Screening.h"
#include "Ticket.h"

namespace Configuration
{
	const std::string defaultJsonDirName = "json/";
	const std::string moviesFilePath = defaultJsonDirName + "movies.json";
	const std::string roomsFilePath = defaultJsonDirName + "rooms.json";
	const std::string screeningsFilePath = defaultJsonDirName + "screening.json";
	const std::string ticketsFilePath = defaultJsonDirName + "tickets.json";
}

class DatabaseManager {
public:
	
	DatabaseManager();

	static DatabaseManager& getInstance();

	void Initialize();
	// Movie-related methods
	void loadMovies(const std::string& filePath);
	std::shared_ptr<Movie> getMovie(int movieId);
	std::shared_ptr<Movie> getMovie(std::string movieTitle);

	//void saveMovies(const std::unordered_map<int, std::shared_ptr<Movie>>& movies);

	 // Room-related methods
	void loadRooms(const std::string& filePath);
	std::shared_ptr<Room> getRoom(int roomId);

	//void saveRooms(const std::unordered_map<int, std::shared_ptr<Room>>& rooms);

	// Screening-related methods
	void loadScreenings(const std::string& filePath);
	std::shared_ptr<Screening> getScreening(int screeningId);
	std::shared_ptr<Screening> getScreening(const wxString& movie, const wxString& time);

	// Ticket-related methods
	void loadTickets(const std::string& filePath);


	//void saveScreenings(const std::unordered_map<int, std::shared_ptr<Screening>>& screenings);
	bool isSeatReserved(int movieId, int roomId, int row, int column);
	std::string* getTitles();

	std::shared_ptr<Seat> getSeat(int row, int column, std::shared_ptr<Room> room) const;
	std::shared_ptr<Seat> getSeat(int seatId, std::shared_ptr<Room> room) const;


	//void DatabaseManager::saveTicket(int movieId, int roomId, int row, int column);

	void saveTickets(const std::vector<std::shared_ptr<Ticket>>& tickets);

private:
	std::vector<std::shared_ptr<Movie>> movies_;
	std::vector<std::shared_ptr<Screening>> screenings_;
	std::vector<std::shared_ptr<Room>> rooms_;
	std::vector<std::shared_ptr<Ticket>> tickets_;
};
#endif