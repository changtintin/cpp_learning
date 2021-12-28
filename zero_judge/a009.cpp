#include <iostream>
#include <string>
#include <bits/stdc++.h> 
using namespace std;
int main(){
    string input;
    getline(cin,input);
    int x = input.length();
    char password[ input.length() ], original[ input.length() ]; 
    strcpy( original, input.c_str() ); 
    for (int i = 0; i < x; i++) {
        password[i] = original[i] - 7;
        cout << password[i] ;
    }
    
}