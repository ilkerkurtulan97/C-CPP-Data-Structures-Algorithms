#include "EconomyCar.h"

//Overriding the methods here !!
EconomyCar::EconomyCar(const std::string& model, const std::string& plate, double rate)
    : Car(model, plate, rate) {}

double EconomyCar::calculateRentalCost(int days) const {
    return baseRate * days;
}