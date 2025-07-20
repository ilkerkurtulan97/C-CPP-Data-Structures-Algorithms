#ifndef RENTAL_H
#define RENTAL_H

#include "Customer.h"
#include "Car.h"

class Rental {
private:
    Customer* customer;
    Car* car;
    int days;

public:
    Rental(Customer* customer, Car* car, int days);
    void displayRentalDetails() const;
};

#endif
