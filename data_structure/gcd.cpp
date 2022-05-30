#include <iostream>
using namespace std;
int gcd(int a, int b){
    if(a % b == 0){
        return b;
    }
    else{
        return gcd(b, a % b);
    }
}
int main(){
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    if(a < b){
        int tmp;
        tmp  = a;
        a = b;
        b = tmp;
    }
    cout << "GCD is " << gcd(a,b) << endl;
}