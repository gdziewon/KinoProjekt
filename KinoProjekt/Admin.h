#include <string>
#include <vector>
#include <memory>
#include "User.h"
#include "Movie.h"
#include "Room.h"
#include "Screening.h"
#include "Promotion.h"
#include "ReportGenerator.h"

class Admin : public User {
public:
    Admin(const std::string& username, const std::string& hashedPassword)
        : User(username, hashedPassword) {}

    
    void addMovie(const std::shared_ptr<Movie>& movie) { movies.push_back(movie); }
    bool removeMovie(int movieId) {
        auto it = std::find_if(movies.begin(), movies.end(),
            [movieId](const std::shared_ptr<Movie>& movie) {
                return movie->getId() == movieId;
            });
        if (it != movies.end()) {
            movies.erase(it);
            return true;
        }
        return false;
    }

    
    void addRoom(const std::shared_ptr<Room>& room) { rooms.push_back(room); }
    bool removeRoom(int roomId) {
        auto it = std::find_if(rooms.begin(), rooms.end(),
            [roomId](const std::shared_ptr<Room>& room) {
                return room->getId() == roomId;
            });
        if (it != rooms.end()) {
            rooms.erase(it);
            return true;
        }
        return false;
    }

    
    void addScreening(const std::shared_ptr<Screening>& screening) { screenings.push_back(screening); }
    bool removeScreening(int screeningId) {
        auto it = std::find_if(screenings.begin(), screenings.end(),
            [screeningId](const std::shared_ptr<Screening>& screening) {
                return screening->getId() == screeningId;
            });
        if (it != screenings.end()) {
            screenings.erase(it);
            return true;
        }
        return false;
    }

    
    void addPromotion(const std::shared_ptr<Promotion>& promotion) { promotions.push_back(promotion); }
    bool removePromotion(int promotionId) {
        auto it = std::find_if(promotions.begin(), promotions.end(),
            [promotionId](const std::shared_ptr<Promotion>& promotion) {
                return promotion->getId() == promotionId;
            });
        if (it != promotions.end()) {
            promotions.erase(it);
            return true;
        }
        return false;
    }

    
    void generateReport() const {
        ReportGenerator reportGenerator;
        reportGenerator.generateReport(movies, rooms, screenings, promotions);
    }

private:
    std::vector<std::shared_ptr<Movie>> movies;
    std::vector<std::shared_ptr<Room>> rooms;
    std::vector<std::shared_ptr<Screening>> screenings;
    std::vector<std::shared_ptr<Promotion>> promotions;
};

