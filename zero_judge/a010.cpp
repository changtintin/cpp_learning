#include <iostream>
using namespace std;
int main(){
    int x;
    cin >> x;
    int time = 0;
    for(int i=2; i<=x; i++){
        while( x % i == 0){
            x = x / i;
            time = time + 1;
        } 
        if(time >1 ){
            cout << i << "^" << time ;
        }
        else if(time == 1){
            cout <<  i ;
        }
        if(x == 1){
            cout << endl;
        } 
        else if(x%i!=0 && time >=1){
            cout << " * " ;
        }
        time = 0;
    }
}