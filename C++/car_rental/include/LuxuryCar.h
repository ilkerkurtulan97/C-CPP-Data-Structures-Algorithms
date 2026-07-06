#ifndef LUXURYCAR_H
#define LUXURYCAR_H

#include "Car.h"

class LuxuryCar : public Car {
public:
    LuxuryCar(const std::string& model, const std::string& plate, double rate);
    double calculateRentalCost(int days) const override;
};

#endif