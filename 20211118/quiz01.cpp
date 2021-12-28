#include <iostream>
#include <string>
using namespace std;

int bigger(int x, int y){
    if (x>y){
        return(x);
    }
    else{
        return(y);
    }
} 
bool prime(int z){
    for(int i=2; i<=z-1; i++){
        if(z%i==0){
            return false;
        }
    }
    return true;
}

int main(){
    int x, y, z;
    cin >> x >> y;
    if( bigger(x,y)>1 ){
        z=bigger(x,y);
        if (prime(z)==true){
            cout << bigger(x,y) << " is prime." << endl;
        }
        else{
            cout << bigger(x,y) <<" isn't prime." << endl;
        }    
    }
    else{
        cout << "<1" << endl;
    }
}  