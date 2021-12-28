/* Exercises: Pointers*/
#include <iostream>
using namespace std;
int main(){
    int a,b;
    cout << "Enter value of A:";
    cin >> a ;
    cout << "Enter value of B:";
    cin >> b ;
    int* ptrA = &a ;
    int* ptrB = &b ;
    cout <<"The value of ptrA is"<< *ptrA  << endl;
    cout <<"The value of ptrB is"<< *ptrB  << endl;
}