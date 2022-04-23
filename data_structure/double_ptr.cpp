#include<iostream>
using namespace std;
int main(){
    int num = 23;
    int *ptr = &num; 
    int ** d_ptr = &ptr;

    cout << "&num: " << &num << endl;
    cout << "num: " << num << endl;

    cout << "ptr: " << ptr << endl;
    cout << "&ptr: " << &ptr << endl;
    cout << "*ptr: " << *ptr << endl;

    cout << "d_ptr: " << d_ptr << endl;
    cout << "&d_ptr: " << &d_ptr << endl;
    cout << "*d_ptr: " << *d_ptr << endl;
    cout << "**d_ptr: " << **d_ptr << endl;
}