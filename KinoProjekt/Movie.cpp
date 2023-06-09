#include "Movie.h"

Movie::Movie
(int id,
	const std::string& name,
	const std::string& description,
	const std::vector<std::string>& actors,
	const std::string& director,
	const std::string& genre,
	const std::string& releaseDate,
	int runningTime)
	: CinemaItem(id, name, description), actors(actors), director(director), genre(genre), releaseDate(releaseDate), runningTime(runningTime) {}

std::vector<std::string> Movie::getActors() const { return actors; }
std::string Movie::getDirector() const { return director; }
std::string Movie::getGenre() const { return genre; }
std::string Movie::getReleaseDate() const { return releaseDate; }
int Movie::getRunningTime() const { return runningTime; }

void Movie::setActors(const std::vector<std::string>& actors) { this->actors = actors; }
void Movie::setDirector(const std::string& director) { this->director = director; }
void Movie::setGenre(const std::string& genre) { this->genre = genre; }
void Movie::setRunningTime(int runningTime) { this->runningTime = runningTime; }
void Movie::setReleaseDate(const std::string& releaseDate) { this->releaseDate = releaseDate; }