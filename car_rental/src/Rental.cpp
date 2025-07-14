#include "Rental.h"
#include <iostream>

Rental::Rental(Customer* customer, Car* car, int days)
    : customer(customer), car(car), days(days) {}

void Rental::displayRentalDetails() const {
    customer->displayInfo();
    car->displayInfo();
    std::cout << "Days: " << days << ", Total Cost: " << car->calculateRentalCost(days) << "\n\n";
}
