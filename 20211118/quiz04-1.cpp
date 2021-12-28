#include <iostream>
#include <iomanip>
using namespace std;
int main (){
    int x,y ;
    int a,b ;
    cin >> x >> y ;

    cout << 0;
    for(int a=1; a<=x; a++){
        cout  << setw(4) << a;
        }
    cout << endl;  

    for(int b=1; b<=y; b++){
        cout << b;
        
        for(int a=1; a<=x; a++){
            cout << setw(4) << (a*b) ;
        }
        cout << endl;    
    }
}