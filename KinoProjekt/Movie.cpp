#include "Movie.h"

Movie::Movie(int id, const std::string& name, const std::string& description, const std::vector<std::string>& actors, const std::string& director, const std::string& genre, int runningTime, int releaseYear)
        : CinemaItem(id, name, description), actors(actors), director(director), genre(genre), runningTime(runningTime), releaseYear(releaseYear) {}

    std::vector<std::string> Movie::getActors() const { return actors; }
    std::string Movie::getDirector() const { return director; }
    std::string Movie::getGenre() const { return genre; }
    int Movie::getRunningTime() const { return runningTime; }
    int Movie::getReleaseYear() const { return releaseYear; }

    void Movie::setActors(const std::vector<std::string>& actors) { this->actors = actors; }
    void Movie::setDirector(const std::string& director) { this->director = director; }
    void Movie::setGenre(const std::string& genre) { this->genre = genre; }
    void Movie::setRunningTime(int runningTime) { this->runningTime = runningTime; }
    void Movie::setReleaseYear(int releaseYear) { this->releaseYear = releaseYear; }