#include <iostream>
using namespace std;

int main (void){
    
    for(int i = 0; i <= 10; i++) {
        if( i == 4 || i == 6) {
            continue;
        }
        
        cout << i << endl;
        
        if(i == 8) {
            break;
        }
    }
}