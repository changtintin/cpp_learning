#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int x;
    cin >> x ;
    cout << setw(2); 
    while(x>0){
        if(x%2!=0){
             for(int c=1; c<=(x*2)-1; c++){
                 if(c==x){
                     cout << "*" << setw(2);
                 }
                 else{
                     cout << "" << setw(2);
                 }
            }
            cout << endl;
            for(int b=2; b<=x; b++){
                for(int a=1; a<=(x*2)-1; a++){
                    if( a>=1 && a<=(x-b) ){
                        cout << "" << setw(2); 
                    }
                    else{
                        if( a>(x+(b-1)) ){
                            cout << "" << setw(2);
                        }
                        else{
                            cout << "*" << setw(2); 
                        }cd
                        
                    }       
                }
            cout << endl;
            }
        }
        cin >> x;
    }
   
}