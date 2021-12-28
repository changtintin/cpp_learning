#include <iostream>
using namespace std;

void swap(int *x, int *y) {
    int z = *x;
    *x = *y;
    *y = z;
}

int main() {
    int a = 3;
    int b = 5;
    
    swap(&a, &b);

    cout << "in main: " << a << "  " << b << endl;
}