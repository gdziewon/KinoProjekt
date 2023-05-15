#include <string>
#include <vector>
#include "CinemaItem.h"

class Movie : public CinemaItem {
public:
    Movie(int id, const std::string& name, const std::string& description, const std::vector<std::string>& actors, const std::string& director, const std::string& genre, int runningTime, int releaseYear)
        : CinemaItem(id, name, description), actors(actors), director(director), genre(genre), runningTime(runningTime), releaseYear(releaseYear) {}

    std::vector<std::string> getActors() const { return actors; }
    std::string getDirector() const { return director; }
    std::string getGenre() const { return genre; }
    int getRunningTime() const { return runningTime; }
    int getReleaseYear() const { return releaseYear; }

    void setActors(const std::vector<std::string>& actors) { this->actors = actors; }
    void setDirector(const std::string& director) { this->director = director; }
    void setGenre(const std::string& genre) { this->genre = genre; }
    void setRunningTime(int runningTime) { this->runningTime = runningTime; }
    void setReleaseYear(int releaseYear) { this->releaseYear = releaseYear; }

    void display() const override {
        std::cout << "ID: " << getId()
            << ", Name: " << getName()
            << ", Description: " << getDescription()
            << ", Actors: ";
        for (const auto& actor : actors) {
            std::cout << actor << ", ";
        }
        std::cout << "Director: " << director
            << ", Genre: " << genre
            << ", Running time: " << runningTime
            << ", Release year: " << releaseYear << std::endl;
    }

private:
    std::vector<std::string> actors;
    std::string director;
    std::string genre;
    int runningTime;
    int releaseYear;
};
