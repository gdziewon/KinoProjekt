// CinemaItem.h
#include <string>

class CinemaItem {
public:
    CinemaItem(int id, const std::string& name) : id(id), name(name) {}
    virtual ~CinemaItem() = default;

    // Getter methods
    int getId() const { return id; }
    const std::string& getName() const { return name; }

    // Abstract method to be implemented by derived classes
    virtual std::string getInfo() const = 0;

protected:
    int id;
    std::string name;
};
