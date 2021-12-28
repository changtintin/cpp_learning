#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
//輸入1-3的數字，跑出1-3組隨機身分證字號，要符合身分證驗證規則
int main() {
    srand(time(NULL));

    int x, sum = 0;
    char id[10];
    while(cin >> x) {
        if(x >= 1 && x <= 3) {
            break;
        }
    }

    for(int i = 1; i <= x; i++) {
        id[0] = rand() % ('Z' - 'A' + 1) + 'A';
        id[1] = rand() % ('2' - '1' + 1) + '1'; 
        
        for(int i = 2; i < 9; i++) {
            id[i] = rand() % ('9' - '0' + 1) + '0';
        }


        int value_In_Alphabet[26] = {
            10, 11, 12, 13, 14, 15, 16, 17, 34,
            18, 19, 20, 21, 22, 35, 23, 24, 25,
            26, 27, 28, 29, 32, 30, 31, 33
        };

        for(int i = 0; i < 26; i++) {
            char alphabet = 'A' + i;
            if(alphabet == id[0]) {
                sum = value_In_Alphabet[i];
            }
        }

        sum = (sum / 10) + (sum % 10) * 9;
        for(int i = 1; i <= 8; i++) {
            sum += (id[i] - '0') * (9 - i);
        }

        if(sum % 10 == 0)
            id[9] = '0';
        else
            id[9] = '0' + (10 - (sum % 10));

        cout << id << endl;
    }
}