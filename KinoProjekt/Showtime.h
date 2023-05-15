#include <string>
#include <iostream>
#include <vector>
#include "Screening.h"

class Showtime {
public:
    Showtime(const std::string& date, const std::vector<std::shared_ptr<Screening>>& screenings)
        : date(date), screenings(screenings) {}

    std::string getDate() const { return date; }
    std::vector<std::shared_ptr<Screening>> getScreenings() const { return screenings; }

    void addScreening(const std::shared_ptr<Screening>& screening) {
        screenings.push_back(screening);
    }

    void removeScreening(const std::shared_ptr<Screening>& screening) {
        auto it = std::find(screenings.begin(), screenings.end(), screening);
        if (it != screenings.end()) {
            screenings.erase(it);
        }
    }

    void display() const {
        std::cout << "Showtime Date: " << date << std::endl;

        std::cout << "Screenings:" << std::endl;
        for (const auto& screening : screenings) {
            screening->display();
            std::cout << std::endl;
        }
    }

private:
    std::string date;
    std::vector<std::shared_ptr<Screening>> screenings;
};

