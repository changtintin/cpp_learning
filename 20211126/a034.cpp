// solution by pei shih

#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int input;
    
    while(cin >> input) {
        char record[35];

        int index = 0;
        while(input != 0) {
            switch (input % 2) {
            case 0:
                record[index]='0';
                break;
            case 1:
                record[index]='1';
                break;
            }
            
            index = index + 1;
            input = input / 2;
        }

        for(int i = index-1; i >= 0; i--) {
            cout << record[i];
        }
        cout << endl;
    }
}