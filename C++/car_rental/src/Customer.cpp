#include "Customer.h"
#include <iostream>

//Overriding the methods here !!
Customer::Customer(const std::string& name, const std::string& id)
    : name(name), id(id) {}

void Customer::displayInfo() const {
    std::cout << "Customer: " << name << ", ID: " << id << "\n";
}

std::string Customer::getId() const {
    return id;
}
