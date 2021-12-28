#include <iostream>
using namespace std;
int main(){
    char id[10];
    char alphabet[26];
    int sum=0;
   
    int value_of_alphabet[26]= {
        10, 11, 12, 13, 14, 
        15, 16, 17, 34, 18, 
        19, 20, 21, 22, 35, 
        23, 24, 25, 26, 27, 
        28, 29, 32, 30, 31, 
        33
    };
    while (cin >> id){
        for (int i=0; i<26; i++) {
        alphabet[i] = 'A' + i; 
        }
        for(int i=0; i<26; i++){
            if(alphabet[i] == id[0]){
                sum = sum + (value_of_alphabet[i] / 10) + (value_of_alphabet[i] % 10) * 9;
            }
        }
        
        for(int i=1; i<9; i++){
            id[i] = (id[i]-48) * (9-i);
            sum = sum + id[i];
        }
        sum = sum + (id[9]-48);
        cout << ((sum%10==0)?"real":"fake")<< endl;
    }
}