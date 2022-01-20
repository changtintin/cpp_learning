#include <iostream>
using namespace std;

int add(int v) {
    if(v == 1)
        return 1;
    else
        return v + add(v - 1);
}

int main(void) {
    int sum = add(5);
    cout << sum << endl;
}