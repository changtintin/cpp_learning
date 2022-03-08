#include<iostream>
using namespace std;
int Sum(int num){
    if(num == 0){
        return 0;
    }
    return num + Sum(num-1);
}
int main(){
    int num;
    cin >> num;
    cout << Sum(num);
}
