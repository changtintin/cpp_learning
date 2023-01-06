#include <iostream>
#include <string>
#include<ctime>
using namespace std;
int main(){
    time_t s = clock();

    int x,y;
    cout << "x =" ; 
    cin >> x ;
    cout << "y =" ; 
    cin >> y ;

    int t = x;
    x = y;
    y = t;


    cout << "x =" << x << endl;
    cout << "y =" << y << endl;
    cout << "swap time: " << (double)(clock()-s)/CLOCKS_PER_SEC << "s ";

    time_t tmp = clock();
    int a,b;
    cout << "a =" ; 
    cin >> a ;
    cout << "b =" ; 
    cin >> b ;

    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    
    cout << "a =" << a << endl;
    cout << "b =" << b << endl;
    cout << "swap time: " << (double)(clock()-tmp)/CLOCKS_PER_SEC << "s ";
}
