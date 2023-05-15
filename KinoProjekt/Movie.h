#include <string>

class Movie : public CinemaItem {
public:
    Movie(int id, const std::string& name, int duration, const std::string& genre, int pegi)
        : CinemaItem(id, name), duration(duration), genre(genre), pegi(pegi) {}

    // Getter method for duration
    int getDuration() const { return duration; }

    // Implement the getInfo() method from the CinemaItem abstract class
    std::string getInfo() const override {
        return "Movie ID: " + std::to_string(id) + "\n"
            "Title: " + name + "\n"
            "Duration: " + std::to_string(duration) + " minutes\n";
            "Genre: " + genre + "\n";
            "Minimal age: " + std::to_string(pegi) + " years old";
    }

private:
    int duration; // Duration of the movie in minutes
    std::string genre;
    int pegi;
};
