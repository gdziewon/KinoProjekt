#ifndef CINEMAITEM_H
#define CINEMAITEM_H

#include <string>
#include <iostream>

class CinemaItem {
public:
    CinemaItem(int id, const std::string& name, const std::string& description);

    virtual ~CinemaItem() = default;

    int getId() const;
    std::string getName() const;
    std::string getDescription() const;

    void setId(int id);
    void setName(const std::string& name);
    void setDescription(const std::string& description);

    virtual void display() const = 0;

private:
    int id;
    std::string name;
    std::string description;
};

#endif //CINEMAITEM_H
