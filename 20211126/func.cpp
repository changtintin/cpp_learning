#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

bool in_the_range(int a) {
    int min = 1;
    int max = 5;

    if(a < min)
        return false;
    else if(a > max)
        return false;
    else
       return true;
}

string generate_character(char a, char b) {
    int min = a;
    int max = b;

    char rnd = rand() % (max - min + 1) + min;

    // convert char to string in cpp
    return string(1, rnd);
}

string final_id_generate(string input) {
    int sum = 0;
    
    int value_In_Alphabet[26] = {
        10, 11, 12, 13, 14, 15, 16, 17, 34,
        18, 19, 20, 21, 22, 35, 23, 24, 25,
        26, 27, 28, 29, 32, 30, 31, 33
    };
    int index = string("ABCDEFGHIJKLMNOPQRSTUVWXYZ").find(input.at(0));
    sum += ((value_In_Alphabet[index] / 10) * 1);
    sum += ((value_In_Alphabet[index] % 10) * 9);
    
    for(int i = 1; i < input.length(); i++) {
        sum += (input.at(i) - '0') * (9 - i);
    }

    return string(1, ('0' + ((sum % 10 == 0)? 0: (10 - sum % 10))));
}


int main(void) {
    int input_number = '?';
    while(cin >> input_number) {
        if(in_the_range(input_number)) {
            break;
        }
    }

    for(int round = 1; round <= input_number; round++) {
        string id = "";
        id = id + generate_character('A', 'Z');
        id = id + generate_character('1', '2');
        for(int i = 1; i <= 7; i++) {
            id = id + generate_character('0', '9');
        }
        id = id + final_id_generate(id);

        cout << id << endl;
    }
}

/*

function argument parameter
函數      引數     參數


int function(parameter1, parameter2) {
    return 0;
}

int main() {
    function(argument, argument);
}

*/