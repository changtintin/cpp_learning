#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int x;
    cin >> x ;
    cout << "" << setw(4);
    while ( x!=0 ){
        if(x>0 && x%2!=0){
            cout << "" << setw(4);
            for(int c=2; c<=x; c++){
                if(c==x){
                    cout << "" << setw(4);
                }
                else{
                    cout << c << setw(4);
                } 
            }
            cout << "" << setw(4);
            cout << endl;
            for(int b=2; b<=x; b++){
                if(b==x){
                    cout << "" << setw(4);
                }
                else{
                    cout << b << setw(4);
                }
                
                for(int a=2; a<=x; a++){
                    if(a==b || (a+b)==(x+1) ){
                        cout << "" << setw(4);
                    }
                    else{
                        cout << (a*b) << setw(4);
                    }
                }
                cout << endl;
            }
        }
        else{
            cout << "enter again!" << endl;
        }
        cin >> x;
    }
}