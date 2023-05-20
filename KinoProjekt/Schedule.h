#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <vector>
#include <memory>
#include "Screening.h"

class Schedule {
public:
    Schedule() = default;

    void addScreening(const std::shared_ptr<Screening>& screening);

    void removeScreening(const std::shared_ptr<Screening>& screening);

    std::vector<std::shared_ptr<Screening>> getScreenings() const;

    std::vector<std::shared_ptr<Screening>> getScreeningsByMovie(const std::shared_ptr<Movie>& movie) const;

    std::vector<std::shared_ptr<Screening>> getScreeningsByRoom(const std::shared_ptr<Room>& room) const;

private:
    std::vector<std::shared_ptr<Screening>> screenings;
};

#endif

