#include <iostream>
#include <string>
using namespace std;

int main(void) {
    int a[3][2];

    int n = 1;
    for(int i = 0; i < 3; i++) {      // 中括號的位置
        for(int j = 0; j < 2; j++) {  // 大括號的位置
            a[i][j] = n;
            n += 1;
        }
    }

    for(int j = 0; j < 2; j++) {
        for(int i = 0; i < 3; i++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    /*
        00 10 20
        01 11 21

        a [ {1.2} | {3.4} | {5.6} ];

        1 2
        3 4
        5 6

        1 3 5
        2 4 6
    */
}