#ifndef MOVIE_H
#define MOVIE_H


#include <string>
#include <vector>
#include "CinemaItem.h"

class Movie : public CinemaItem {
public:
    Movie(int id, const std::string& name, const std::string& description, const std::vector<std::string>& actors, const std::string& director, const std::string& genre, const std::string& releaseDate, int runningTime);

    std::vector<std::string> getActors() const;
    std::string getDirector() const;
    std::string getGenre() const;
    int getRunningTime() const;
    std::string getReleaseDate() const;

    void setActors(const std::vector<std::string>& actors);
    void setDirector(const std::string& director);
    void setGenre(const std::string& genre);
    void setRunningTime(int runningTime);
    void setReleaseDate(const std::string& releaseDate);

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
            << ", Release date: " << releaseDate << std::endl;
    }

private:
    std::vector<std::string> actors;
    std::string director;
    std::string genre;
    std::string releaseDate;
    int runningTime;
};

#endif
