#include <iostream>
using namespace std;
int main(){
    int r = 12;
    int d = 8;
    int q[4];
    int i = 0;
    while(i < 7){
        if(r > 0){
            q[i] = 1;
            r = (2 * r) - d;
        }
        else{
            q[i] = -1;
            r = (2 * r) + d;
        }
    }
    for(int i = 0; i < 14 ; i++){
        cout << q[i] << " ";
    }
}    
    