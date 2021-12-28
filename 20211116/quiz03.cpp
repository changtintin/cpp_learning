#include <iostream>
using namespace std;

int main(void) {
    int x;
    cin >> x;

    if(x < 1) {
        cout << "out of range" << endl;
    }
    else {
        // for(int i = 1; i <= x; i++) {
        //     cout << i << endl;
        // }

        int i = 1;
        while (i <= x) {
            cout << i << endl;
            i++;
        }
    } 
    
}