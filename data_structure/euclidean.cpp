#include <iostream>
using namespace std;
int Eu(int a,int b){
    int remainder = a % b;
    if(remainder == 0){
        return b;
    }
    return Eu(b, remainder);
}
int main(){
    int a ,b, x, y;               
    cin >> x >> y;

    if(x > y){
        a = x;
        b = y;
    }
    else if(x < y){
        a = y;
        b = x;
    }
    cout << Eu(a,b);
}