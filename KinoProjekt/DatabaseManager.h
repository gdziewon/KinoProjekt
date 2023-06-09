#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include "json.hpp"
#include <fstream>
#include <wx/wx.h>
#include "Movie.h"
#include "Room.h"
#include "Screening.h"
#include "Ticket.h"

class DatabaseManager {
public:
	DatabaseManager();

	// Movie-related methods
	void loadMovies();
	std::shared_ptr<Movie> getMovie(int movieId);
	std::shared_ptr<Movie> getMovie(std::string movieTitle);

	//void saveMovies(const std::unordered_map<int, std::shared_ptr<Movie>>& movies);

	 // Room-related methods
	void loadRooms();
	std::shared_ptr<Room> getRoom(int roomId);

	//void saveRooms(const std::unordered_map<int, std::shared_ptr<Room>>& rooms);

	// Screening-related methods
	void loadScreenings();
	std::shared_ptr<Screening> getScreening(int screeningId);

	// Ticket-related methods
	void loadTickets();


	//void saveScreenings(const std::unordered_map<int, std::shared_ptr<Screening>>& screenings);
	bool isSeatReserved(int movieId, int roomId, int row, int column);

	std::shared_ptr<Seat> getSeat(int row, int column, const std::vector<std::shared_ptr<Seat>>& seats_);

	//void DatabaseManager::saveTicket(int movieId, int roomId, int row, int column);

	void saveTickets(const std::unordered_map<int, std::shared_ptr<Ticket>>& tickets);

private:
	std::vector<std::shared_ptr<Movie>> movies_;
	std::vector<std::shared_ptr<Screening>> screenings_;
	std::vector<std::shared_ptr<Room>> rooms_;
	std::vector<std::shared_ptr<Ticket>> tickets_;
};
#endif