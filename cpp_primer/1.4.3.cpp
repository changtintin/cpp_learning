#include<iostream>
using namespace std;
/*
Exercise 1.16: 
Write your own version of a program 
that prints the sum of a set of integers read from cin.
*/
bool Compare(int x, int y){
    if(x>y){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    int x, y, sum = 0;
    cin >> x >> y;
    if(Compare(x,y)==true){
        for(int i = y; i <= x; i++){
            sum += i;
        }
        cout << sum ; 
    }
    else{
        for(int i = x; i <= y; i++){
            sum += i;
        }
        cout << sum ;
    }
    
}