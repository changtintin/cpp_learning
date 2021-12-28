#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    for(int x=2; x<10; x=x+1 ){
        for(int y=1; y<10; y=y+1){
            cout << x << "*" << y << "=" << setw(4) << (x*y) << endl;
        }
        cout << endl;
    }
} 