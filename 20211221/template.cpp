#include <iostream>
#include <string>
using namespace std;

template <typename T1, typename T2>
T1 sum(T1 n1, T2 n2) {
    return n2 + n1;
}

int main(void) {
    int a = 10, b = 4;
    float x = 12.4, y = 4.5;

    int n = sum(a, x);
    cout << n << endl;
}