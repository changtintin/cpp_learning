#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int input_number[5];
    for(int i=0; i<5; i++){
        cin >> input_number[i];
    }
    
    cout << "The largest number is " << *max_element(input_number,input_number+5);
}