#include "CinemaItem.h"


    CinemaItem::CinemaItem(int id, const std::string& name, const std::string& description)
        : id(id), name(name), description(description) {}


    int CinemaItem::getId() const { return id; }
    std::string CinemaItem::getName() const { return name; }
    std::string CinemaItem::getDescription() const { return description; }

    void CinemaItem::setId(int id) { this->id = id; }
    void CinemaItem::setName(const std::string& name) { this->name = name; }
    void CinemaItem::setDescription(const std::string& description) { this->description = description; }
