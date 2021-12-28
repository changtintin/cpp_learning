#include <iostream>
using namespace std;

int main (void){
    float apple = -6;

    if(apple > 3) {
        cout << "more than 3" << endl;
    }
    else {
        if (apple ==3) {
            cout << "equal 3" << endl;
        }
        else {
            cout << "less than 3" << endl;
        }
    }

    if(apple != 3) {
        cout << "apple not equal to 3" << endl;
    }

    cout << "end." << endl;
}