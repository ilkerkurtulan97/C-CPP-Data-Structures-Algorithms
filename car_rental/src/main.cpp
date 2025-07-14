#include <iostream>
#include <vector>
#include "Customer.h"
#include "Car.h"
#include "EconomyCar.h"
#include "LuxuryCar.h"
#include "Rental.h"

int main() {
    std::vector<Customer*> customers;
    std::vector<Car*> cars;
    std::vector<Rental*> rentals;

    // Create some customers
    Customer* c1 = new Customer("Alice", "C001");
    Customer* c2 = new Customer("Bob", "C002");
    customers.push_back(c1);
    customers.push_back(c2);

    // Create some cars
    Car* car1 = new EconomyCar("Toyota Yaris", "ABC-123", 30);
    Car* car2 = new LuxuryCar("BMW 7 Series", "XYZ-999", 70);
    cars.push_back(car1);
    cars.push_back(car2);

    // Rentals
    rentals.push_back(new Rental(c1, car1, 3)); // 3 days economy
    rentals.push_back(new Rental(c2, car2, 2)); // 2 days luxury

    // Display all rentals
    for (const auto& r : rentals) {
        r->displayRentalDetails();
    }

    // Clean up
    for (auto& r : rentals) delete r;
    for (auto& c : customers) delete c;
    for (auto& c : cars) delete c;

    return 0;
}
