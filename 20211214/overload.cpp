#include <iostream>
#include <string>
using namespace std;

// overload
// function overload = 可以接受複數個同名稱的函數
// operator overload

class num {
    public:
        int a;
    
    public:
        num();
        num(int n);

    public:
        // function overload
        void add();
        void add(int n);

    public:
        void operator+(int n);
        void operator+(double n);
};

num::num() {
    a = 5;
}

num::num(int n) {
    a = n;
}

void num::add(int n) {
    a += n;
}

void num::add() {
    a += a;
}

void num::operator+(int n) {
    a *= n;
};

void num::operator+(double n) {
    a = n + n;
};


int main(void) {
    num x;         // x.a = 5
    num y(46);     // y.a = 46

    x.add();       // x.a = 10
    x.add(3);      // x.a = 13

    // (num) + (int)
         x   +  3.2;  // x.a = 6

    x + 4;

    cout << x.a << " " << y.a << endl;
}