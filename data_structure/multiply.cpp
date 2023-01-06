#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main(){
    for(int i = 1; i <= 81; i++){
        cout << setw(3);
        if(i % 9 == 0){
            cout << 9 * ceil((double)i / 9);
            cout << endl;
        }
        else{
            cout << i % 9 * ceil((double)i / 9) ;
        }

        // cout << setw(3) << ((i%9)+1) * ((i/9)+1);
        // if(i % 9 == 8)
        //     cout << endl;
    }
}