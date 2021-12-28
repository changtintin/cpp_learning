#include <iostream>
using namespace std;

int main (void) {
    int apple;
    cout << "apple = ";
    cin >> apple;
    
    if(apple>=5) {
         cout << "more than 4" << endl;
    }

    if(apple<0) {
         cout << "impossible" << endl;
    }

    int banana;
    cout << "banana = ";
    cin >> banana;

    if(banana%2 == 0) {
        cout << "even number" << endl;
    }
    else {
        cout << "odd number" << endl;
    }

    cout << "total:" << (banana+apple) << endl;
    
}