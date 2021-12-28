#include <iostream>
#include <string>
using namespace std;

// 結構變數
typedef struct {
    int id;
    string name;
    int age;
} student;

int main(void) {
    student ming;
    ming.age = 14;
    ming.name = "ming";
    ming.id = 1101201;

    cout << ming.name << endl;
    return 0;
}