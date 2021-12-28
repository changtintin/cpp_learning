#include <iostream>
using namespace std;

#define error false


bool check(int a, int b) {
    return (a == b);
}

int main (void){
    int account, password;
    cout << "account: ";
    cin >>  account;
    cout << "password: ";
    cin >> password;

    int count_error = 0;

    while(check(account, password) == error) {
        count_error = count_error + 1;

        if(count_error == 3) {
            cout << "try too much, break system." << endl;
            break;
        }

        cout << "please try again" << endl;
        cout << "account: ";
        cin >>  account;
        cout << "password: ";
        cin >> password;
    }

    if(count_error != 3) {
        cout << "log in" << endl;
    }
}