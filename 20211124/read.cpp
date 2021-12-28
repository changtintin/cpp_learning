#include <iostream>
#include <iomanip>
using namespace std;

int main(void) {
    int a;
    while(cin >> a) {
        for(int i = 1; i <= a; i++) {
            for(int j = 1; j <= i; j++) {
                cout << setw(2) << "*";
            }
            cout << endl;
        }

        // cmd commend:  (read.cpp < n.txt)  power shell no no
    }
}