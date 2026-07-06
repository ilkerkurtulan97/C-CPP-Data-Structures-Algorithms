#include <stdio.h>

int main() {
    
    int arr[] = {10, 20, 30, 40, 50};
    int* p = arr;
    p++;

    int x = *(p + 2);

    int add(int a, int b) { return a + b; }
    int mul(int a, int b) { return a * b; }

    int (*op)(int, int);

    op = add; op (3,4);
    op = add; op (3,4);

    typedef int (*BinOp)()

    return 0;
}