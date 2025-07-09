#include <iostream>
using namespace std;

class Car {
private:
    string brand;
public:
    Car(string b) { brand = b; cout << "Constructor called\n"; }
    void drive() { cout << brand << " is driving\n"; }
    ~Car() { cout << "Destructor called for " << brand << endl; }
};

int main() {
    Car myCar("BMW");
    myCar.drive();
    return 0;
}
