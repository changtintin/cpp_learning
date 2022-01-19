#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main(){
    int x,y;
    cout << "x =" ; 
    cin >> x ;
    cout << "y =" ; 
    cin >> y ;

    swap(x,y);
    cout << "x =" << x << endl;
    cout << "y =" << y << endl;
}
