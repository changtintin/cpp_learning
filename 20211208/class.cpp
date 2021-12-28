#include <iostream>
#include <string>
using namespace std;

#include "student.h"

int main(void) {
    student ming(1, 17, "ming"), kid(100, "hua"), mei;
    kid.changeAge(25);

    kid.showData();

    mei.name = "mei";
}

// commend: g++ class.cpp student.cpp -o a