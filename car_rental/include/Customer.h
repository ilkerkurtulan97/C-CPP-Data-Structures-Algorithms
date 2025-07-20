#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer {
private:
    std::string name;
    std::string id;

public:
    Customer(const std::string& name, const std::string& id);
    void displayInfo() const;
    std::string getId() const;
};

#endif
