#include <iostream>
using namespace std;

void reverseArray(int* arr, int size) {
    int* start = arr;
    int* end = arr + size - 1;

    while (start < end) {
        swap(*start, *end);
        start++;
        end--;
    }
}

int main() {
    int nums[] = {1, 2, 3, 4, 5};
    int size = sizeof(nums) / sizeof(nums[0]);

    reverseArray(nums, size);

    cout << "Reversed array: ";
    for (int i = 0; i < size; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
