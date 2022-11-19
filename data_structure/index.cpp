#include<iostream>
using namespace std;
int main(){
    // int yy = 1994;
    // int v;
    
    // for(int i = 0; i < 20; i++){
    //     if(i%2==0){
    //         v = i*3+5;
    //     }
    //     else{
    //         v  = i * i;
    //     }
    //     cout << yy << "," << v << endl;
    //     yy++;
    // }
    char c = 97;
    
    for(int i = 1; i < 26 ; i++){
        cout << c ;
        if(i != 25)
            cout << ",";
    
        c++;
    }

}