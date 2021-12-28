#include <iostream>
using namespace std;
int main(){
    int x;
    while(cin >> x){
        if(x%4==0 && x%100!=0){
        cout << "閏年" << endl;
        }
        else{
            if(x%400==0){
                cout << "閏年" << endl;
            }
            else{
                cout << "平年" << endl;
            }
        }
    }
    
}