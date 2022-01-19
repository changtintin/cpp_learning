#include<iostream>
#include<string>
using namespace std;


bool compare(int y , int z){
    if (y>z){
        return true ;
    }
    else{
        return false;
    }
}
int main(){
    /*Exercise 1.10: 
    Use the decrement operator to write a while that 
    prints the numbers from ten down to zero.
    */
    int x = 10 ;
    while(x >= 0){
        cout << x << endl;
        x--;
    }

    int y,z,output;
    cout << "Enter two integer: ";
    cin >> y >> z;
    
    /*Exercise 1.11: 
    Write a program that prompts the user for two integers. 
    Print each number in the range specified by those two integers.
    */
    if(compare(y,z)==true){
        output = z;
        while(output >= z && output <= y){
            cout << output << endl;
            output ++;
        }
    }
    else{
        output = y;
        while(output >= y && output <= z){
            cout << output << endl;
            output ++;
        }
    }
   
}