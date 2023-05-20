#ifndef PAYMENTPROCESSOR_H
#define PAYMENTPROCESSOR_H

#include <iostream>
#include <string>
#include <chrono>
#include <thread>

class PaymentProcessor {
public:
    bool processPayment(const std::string& cardNumber, const std::string& cardHolder, const std::string& expiryDate, const std::string& cvv, double amount);

private:
    bool connectToPaymentGateway();

    bool authorizePayment(const std::string& cardNumber, const std::string& cardHolder, const std::string& expiryDate, const std::string& cvv);

    bool processPaymentAmount(double amount);

    void disconnectFromPaymentGateway();
};
#endif
