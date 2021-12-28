#include <iostream>
using namespace std;

int main(void) {
    int x;
    cin >> x;

    if(x > 9 || x < 0) {
        cout << "out of range" << endl;
    }
    else {
       switch(x) {
            case 2:
            case 3:
            case 5:
            case 7:
                cout << "prime number" << endl;
                break;
            default:
                cout << "not prime number" << endl;
       }
   }
}