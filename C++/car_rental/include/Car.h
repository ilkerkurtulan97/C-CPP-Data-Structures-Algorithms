#ifndef CAR_H
#define CAR_H

#include <string>

class Car {
protected:
    std::string model;
    std::string licensePlate;
    double baseRate;

public:
    Car(const std::string& model, const std::string& plate, double rate);
    virtual ~Car();

    virtual double calculateRentalCost(int days) const = 0;
    virtual void displayInfo() const;

    std::string getLicensePlate() const;
};

#endif