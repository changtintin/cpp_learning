#include <iostream>
#include <string>
using namespace std;

#define currect true

typedef struct{
    int age;
    string name;
    int sex;
} person;

int main(void) {
    if(currect) {
        cout << "ok~" << endl;
    }
    person ming;
    ming.age = 15;
    ming.name =  "ming";
    ming.sex = 1;

    // cout << ming;
    cout << ming.age << " " << ming.name << " " << ming.sex << endl;
}