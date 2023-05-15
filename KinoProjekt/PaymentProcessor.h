#include <iostream>
#include <string>
#include <chrono>
#include <thread>

class PaymentProcessor {
public:
    bool processPayment(const std::string& cardNumber, const std::string& cardHolder, const std::string& expiryDate, const std::string& cvv, double amount) {
        
        bool isConnected = connectToPaymentGateway();
        if (!isConnected) {
            std::cout << "Failed to connect to the payment gateway. Payment processing failed." << std::endl;
            return false;
        }

       
        bool isAuthorized = authorizePayment(cardNumber, cardHolder, expiryDate, cvv);
        if (!isAuthorized) {
            std::cout << "Payment authorization failed. Payment processing failed." << std::endl;
            return false;
        }

        
        bool isPaymentProcessed = processPaymentAmount(amount);
        if (!isPaymentProcessed) {
            std::cout << "Payment processing failed. Please try again later." << std::endl;
            return false;
        }

        
        disconnectFromPaymentGateway();

        std::cout << "Payment of $" << amount << " processed successfully." << std::endl;
        return true;
    }

private:
    bool connectToPaymentGateway() {
        
        std::cout << "Connecting to the payment gateway..." << std::endl;

        
        std::this_thread::sleep_for(std::chrono::seconds(2));

        
        std::cout << "Connected to the payment gateway." << std::endl;
        return true;
    }

    bool authorizePayment(const std::string& cardNumber, const std::string& cardHolder, const std::string& expiryDate, const std::string& cvv) {
        
        std::cout << "Authorizing payment with card ending in " << cardNumber.substr(cardNumber.length() - 4) << "..." << std::endl;

        
        std::this_thread::sleep_for(std::chrono::seconds(2));

        
        bool isAuthorized = true;

        if (isAuthorized) {
            std::cout << "Payment authorized." << std::endl;
        }
        else {
            std::cout << "Payment authorization failed." << std::endl;
        }

        return isAuthorized;
    }

    bool processPaymentAmount(double amount) {
        
        std::cout << "Processing payment of $" << amount << "..." << std::endl;

        
        std::this_thread::sleep_for(std::chrono::seconds(3));

        
        bool isPaymentProcessed = true;

        if (isPaymentProcessed) {
            std::cout << "Payment processed successfully." << std::endl;
        }
        else {
            std::cout << "Payment processing failed." << std::endl;
        }

        return isPaymentProcessed;
    }

    void disconnectFromPaymentGateway() {
        
        std::cout << "Disconnecting from the payment gateway..." << std::endl;

        std::this_thread::sleep_for(std::chrono::seconds(2));

        std::cout << "Disconnected from the payment gateway." << std::endl;
    }
};
