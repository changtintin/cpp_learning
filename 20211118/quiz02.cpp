#include <iostream>
using namespace std;
bool prime(int x){
    for(int i=2; i<x; i++ ){
        if(x%i==0){
            return false;
        }
    } 
    return true;
}


int main(){
    int x, time=0;
    cin >> x;

    while(prime(x)==false){
        time=time+1;
        if(time>=5){
            cout << "DAMN! wait a while" <<endl;
            break;
        }
        cout << "it's not prime number." <<endl;
        cin >> x;
    }
}