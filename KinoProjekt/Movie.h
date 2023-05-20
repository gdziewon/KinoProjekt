#ifndef MOVIE_H
#define MOVIE_H


#include <string>
#include <vector>
#include "CinemaItem.h"

class Movie : public CinemaItem {
public:
    Movie(int id, const std::string& name, const std::string& description, const std::vector<std::string>& actors, const std::string& director, const std::string& genre, int runningTime, int releaseYear);

    std::vector<std::string> getActors() const;
    std::string getDirector() const;
    std::string getGenre() const;
    int getRunningTime() const;
    int getReleaseYear() const;

    void setActors(const std::vector<std::string>& actors);
    void setDirector(const std::string& director);
    void setGenre(const std::string& genre);
    void setRunningTime(int runningTime);
    void setReleaseYear(int releaseYear);

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

#endif
