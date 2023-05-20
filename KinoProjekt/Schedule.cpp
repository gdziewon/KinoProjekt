#include "Schedule.h"

    void Schedule::addScreening(const std::shared_ptr<Screening>& screening) {
        screenings.push_back(screening);
    }

    void Schedule::removeScreening(const std::shared_ptr<Screening>& screening) {
        auto it = std::find(screenings.begin(), screenings.end(), screening);
        if (it != screenings.end()) {
            screenings.erase(it);
        }
    }

    std::vector<std::shared_ptr<Screening>> Schedule::getScreenings() const {
        return screenings;
    }

    std::vector<std::shared_ptr<Screening>> Schedule::getScreeningsByMovie(const std::shared_ptr<Movie>& movie) const {
        std::vector<std::shared_ptr<Screening>> filteredScreenings;
        for (const auto& screening : screenings) {
            if (screening->getMovie() == movie) {
                filteredScreenings.push_back(screening);
            }
        }
        return filteredScreenings;
    }

    std::vector<std::shared_ptr<Screening>> Schedule::getScreeningsByRoom(const std::shared_ptr<Room>& room) const {
        std::vector<std::shared_ptr<Screening>> filteredScreenings;
        for (const auto& screening : screenings) {
            if (screening->getRoom() == room) {
                filteredScreenings.push_back(screening);
            }
        }
        return filteredScreenings;
    }

