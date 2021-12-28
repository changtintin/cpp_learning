#include <iostream>
#include <string>
using namespace std;

int main(void) {
    char id[10];

    // (1), (2)
    char alphabet[26];
    for(int i = 0; i <= 25; i++) {
        alphabet[i] = 'A' + i;
    }

    int value_In_Alphabet[26] = {
        10, 11, 12, 13, 14, 15, 16, 17, 34,
        18, 19, 20, 21, 22, 35, 23, 24, 25,
        26, 27, 28, 29, 32, 30, 31, 33
    };

    while(cin >> id) {
        int sum = 0;
        
        for(int i = 0; i < 26; i++) {
            if(alphabet[i] == id[0]) {
                sum = sum + (value_In_Alphabet[i] / 10);
                sum = sum + (value_In_Alphabet[i] % 10) * 9;
            }
        }

        // (3)
        for(int i = 1; i <= 8; i++) {
            sum = sum + ((id[i] - 48) * (9-i));
        }
        // (4)
        sum = sum + (id[9]-'0');

        if(sum % 10 == 0) {
            cout << "real" << endl;
        }
        else {
            cout << "fake" << endl;
        }
    }
}