#include <iostream>
#include <string>
using namespace std;

#include "student.h"

student::student() {};

student::student(int i, string n) {
    id = i;
    age = 8;
    name = n;
};

student::student(int i, int a, string n) {
    id = i;
    age = a;
    name = n;
};

void student::showData() {
    cout << "id: " << id << ", age: " << age << ",name: " << name << endl;
}

void student::changeAge(int a) {
    age = a;
}