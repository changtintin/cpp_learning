#include <iostream>
#include <string>
#include <bits/stdc++.h> 
using namespace std;
int main(){
    string input="";
    char alphabet [7] ={'I','V','X','L','C','D','M'};
    int value[7] = {1, 5, 10, 50, 100, 500, 1000};
    int i;
    while (cin >> input) {
		if (input == "#") {
			break;
		}
	}
   char roman[input.length()+1];
    
    
    
    for(int i = 0; i < 7; i++) {
        for(int a=0; a< input.length()+1; a++){
            if(alphabet[i] == roman[a]) {
                alphabet[i] = value[a];
                cout << value[a];
            }
        }
    }


}

    