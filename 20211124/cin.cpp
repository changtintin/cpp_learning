#include <iostream>
#include <iomanip>
using namespace std;

void old_version() {
    int a;
    cin >> a;

    while(a != 0) {
        cout << "numer is: " << a << endl;
        cin >> a;
    }
}

int main(void) {
    int a;
    while(cin >> a) {
        if(a == 0)
            break;
        cout << "numer is: " << a << endl;
    }
}