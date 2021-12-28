#include <iostream>
#include <string>
using namespace std;

int add(int a, int b) {
    return (a+b) ;
}

void oh_ya(void) {
    cout << "oh ya" << endl;
}

string member_check(int id) {
    switch (id) {
        case 1:
            return "boss";
        case 2:
            return "manager";
        default:
            return "employee";
    }
}

int main() {
    cout << "who am I? ";
    int x;
    cin >> x;

    oh_ya();
    
    cout << "you are " + member_check(x) << endl;

    return 0;
}
