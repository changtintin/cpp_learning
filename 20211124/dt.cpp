// dt = data type

#include <iostream>
#include <iomanip>
using namespace std;

int main(void) {
    int i = 65;
    cout << "i = " << i << endl;

    // ascii
    char c = 100;
    cout << "c = " << c << endl;

    // 強轉型
    cout << (int)c << endl;

    int d = 4;
    d = 3.7;
    cout << "d = " << d << endl;  // d = 3
}