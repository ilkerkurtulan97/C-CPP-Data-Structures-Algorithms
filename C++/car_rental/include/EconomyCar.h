#ifndef ECONOMYCAR_H
#define ECONOMYCAR_H

#include "Car.h"

class EconomyCar : public Car {
public:
    EconomyCar(const std::string& model, const std::string& plate, double rate);
    double calculateRentalCost(int days) const override;
};

#endif