#include <iostream>
#include <string>
using namespace std;
int main(){
    float x;
    cin >> x;
    while(x>0){
        if(x>=1){
            cout << x << ">=1" << endl;
        }
        else{
            cout << x << "=float" << endl;
        }
        cin >> x;
    }
}