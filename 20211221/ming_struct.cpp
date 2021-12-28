#include <iostream>
#include <string>
using namespace std;

struct person{
    int age;
    string name;
    int sex;
};

int main(void) {
    struct person ming;
    ming.age = 13;
    ming.name =  "ming";
    ming.sex = 1;

    // cout << ming;
    cout << ming.age << " " << ming.name << " " << ming.sex << endl;
}