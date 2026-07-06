#include "LuxuryCar.h"

//Overriding the methods here !!
LuxuryCar::LuxuryCar(const std::string& model, const std::string& plate, double rate)
    : Car(model, plate, rate) {}

double LuxuryCar::calculateRentalCost(int days) const {
    return (baseRate * days) + 100; // luxury fee
}
