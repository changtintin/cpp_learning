#include <iostream>
#include <string>
using namespace std;

class person {
    public:
        int age;
        string name;
        bool sex;
        
    public:
        person();
        person(string n);
    
    public:
        void show();
};

person::person() {
    age = 8;
    name = "ming";
    sex = boy;
}

person::person(string n) {
    age = 8;
    name = n;
    sex = boy;
}

void person::show() {
    cout << "name: " << name << ", age: " << age << ", sex: " << sex << endl; 
}

int main(void) {
    person a;
    person hua("hua");
    hua.show();
}