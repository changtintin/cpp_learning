#include <iostream>
using namespace std;
int F(int n){
    if(n == 1){
        return 1;
    }
    if(n == 0){
        return 0;
    }
    int result = F(n-1) + F(n-2); 
    return result;
}
int main(){
    int n;
    cin >> n;
    cout << F(n);
}