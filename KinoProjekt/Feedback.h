#include <string>
#include <iostream>

class Feedback {
public:
    Feedback(const std::string& customerName, const std::string& message, int rating)
        : customerName(customerName), message(message), rating(rating) {}

    std::string getCustomerName() const { return customerName; }
    std::string getMessage() const { return message; }
    int getRating() const { return rating; }

    
    void setCustomerName(const std::string& customerName) { this->customerName = customerName; }
    void setMessage(const std::string& message) { this->message = message; }
    void setRating(int rating) { this->rating = rating; }

    void display() const {
        std::cout << "Customer Name: " << customerName << std::endl;
        std::cout << "Rating: " << rating << std::endl;
        std::cout << "Message: " << message << std::endl;
    }

private:
    std::string customerName;
    std::string message;
    int rating;
};

