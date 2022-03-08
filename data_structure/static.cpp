#include <iostream>
#include <string>
using namespace std;

class Student {
    public:
        string name;
        static string skintone;
};
string Student::skintone = "black";

int main(void) {
    Student ming;
    ming.name = "ming";
    ming.skintone = "white";
    cout << "name: " << ming.name << ", skintone: " << ming.skintone << endl;
    Student hua;
    hua.name = "hua";
    hua.skintone = "black";
    cout << "name: " << hua.name << ", skintone: " << hua.skintone << endl;
    cout << ming.skintone << endl;
}