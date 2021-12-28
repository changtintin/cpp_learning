#include <iostream>
#include <string>
using namespace std;

int main() {
    if(!true) {
        float a = -0.01;
        if(a) {
            cout << a << " in here!" << endl;
        }
        cout << "end." << endl;
    }

    if(2 > 3) {
        cout << "2 & 3 = " << (2 & 3) << endl;
        cout << "2 & 4 = " << (2 & 4) << endl;
        cout << "2 | 3 = " << (2 | 3) << endl;
        cout << "2 | 4 = " << (2 | 4) << endl;
        cout << "2 ^ 3 = " << (2 ^ 3) << endl;
        cout << "6 ^ 2 = " << (6 ^ 2) << endl;
    }

    if(2 & 5) {
        cout << "3 | 4 & 5 ^ 6: " << endl;
        cout << (4 & 5) << endl;
        cout << (4 & 5 ^ 6) << endl;
        cout << (3 | 4 & 5 ^ 6) << endl;
    }

    if(!(4 ^ 7)) {
        int a = 1;
        cout << "a:" << endl;
        cout << a++ << endl;
        cout << a << endl;

        int b = 2;
        cout << "b:" << endl;
        cout << ++b << endl;
        cout << b << endl;
    }

    const int a = 1;
    cout << a << endl;
}