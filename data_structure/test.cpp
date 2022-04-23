#include<iostream>
using namespace std;
#define b 6
int main(){
    char a = '7';
    switch (a){
    case '1' ... '8':
        cout << "1-8"<< endl;
        break;
    case 9 ... 20:
        cout << "haha" << endl;
        break;
    default:
        break;
    }
    cout << b << endl;
}