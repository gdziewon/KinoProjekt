#include <string>
#include <iostream>

class Promotion {
public:
    Promotion(const std::string& name, const std::string& description, double discountPercentage)
        : name(name), description(description), discountPercentage(discountPercentage) {}

    
    std::string getName() const { return name; }
    std::string getDescription() const { return description; }
    double getDiscountPercentage() const { return discountPercentage; }

    void setName(const std::string& name) { this->name = name; }
    void setDescription(const std::string& description) { this->description = description; }
    void setDiscountPercentage(double discountPercentage) { this->discountPercentage = discountPercentage; }

    void display() const {
        std::cout << "Promotion: " << name << std::endl;
        std::cout << "Description: " << description << std::endl;
        std::cout << "Discount Percentage: " << discountPercentage << "%" << std::endl;
    }

private:
    std::string name;
    std::string description;
    double discountPercentage;
};

