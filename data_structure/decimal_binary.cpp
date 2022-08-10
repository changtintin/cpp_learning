#include<iostream>
#include<cmath>
#include<string>
using namespace std;
int main(){
    int dec;
    while(cin >> dec){
        int tmp = dec;
        int com = -1;
        string result;
        while(tmp != 0){
            int exp = log2(tmp);
            tmp = tmp - pow(2, exp);
            for(int i = 0; i < com - exp - 1; i++){
                result += "0";
            }
            result += "1";
            if(tmp == 0){
                for(int i = 0; i < exp; i++){
                    result += "0";
                }
            }
            com = exp;
        }
        cout << result << endl;
    }
}