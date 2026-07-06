#include "Car.h"
#include <iostream>

class Car {
protected:
    std::string model;
    std::string licensePlate;
    double baseRate;

public:
    Car(const std::string&, const std::string&, double);
    virtual ~Car(); //Virtual here is used to enable runtime polymorphism. It allows base functions to be overwritten
    virtual double calculateRentalCost(int days) const = 0;
    virtual void displayInfo() const;
};
