#include <string>
#include <vector>
#include <algorithm>
#include "Movie.h"
#include "Screening.h"

class Search {
public:
    static std::vector<std::shared_ptr<Movie>> searchMoviesByTitle(const std::vector<std::shared_ptr<Movie>>& movies, const std::string& title) {
        std::vector<std::shared_ptr<Movie>> searchResults;

        std::string lowercaseTitle = toLowercase(title);
        for (const auto& movie : movies) {
            std::string lowercaseMovieTitle = toLowercase(movie->getTitle());
            if (contains(lowercaseMovieTitle, lowercaseTitle)) {
                searchResults.push_back(movie);
            }
        }

        return searchResults;
    }

    static std::vector<std::shared_ptr<Screening>> searchScreeningsByMovie(const std::vector<std::shared_ptr<Screening>>& screenings, const std::shared_ptr<Movie>& movie) {
        std::vector<std::shared_ptr<Screening>> searchResults;

        for (const auto& screening : screenings) {
            if (screening->getMovie() == movie) {
                searchResults.push_back(screening);
            }
        }

        return searchResults;
    }

private:
    static std::string toLowercase(const std::string& str) {
        std::string lowercaseStr;
        lowercaseStr.reserve(str.length());
        std::transform(str.begin(), str.end(), std::back_inserter(lowercaseStr), [](unsigned char c) { return std::tolower(c); });
        return lowercaseStr;
    }

    static bool contains(const std::string& str, const std::string& substr) {
        return str.find(substr) != std::string::npos;
    }
};

