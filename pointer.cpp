#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int* ptr = &a;
    int** doublePtr = &ptr;

    cout << "Value: " << a << endl;
    cout << "Value using *ptr: " << *ptr << endl;
    cout << "Value using **doublePtr: " << **doublePtr << endl;

    return 0;
}
