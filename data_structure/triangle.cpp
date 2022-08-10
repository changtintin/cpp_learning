#include<iostream>
#include <cmath>
using namespace std;
int main(){
    float n;
    cout << "Enter a number" << endl;
    cin >> n;

    int idx = round(n / 2);
    cout << idx << endl;
    for(int x = 0; x < idx; x++){
        for(int y = 1; y <= n; y++){
            if(y >= idx - x && y <= idx + x){
                cout << "*";
            }
            else{
                cout << " ";
            }
        }
        cout << endl;
    }
}