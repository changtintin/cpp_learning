#include <iostream>
using namespace std;
// 0, 1, 1, 2, 3, 5, 8, 13, 21
int F(int n){
    if(n == 0 || n == 1)
        return n;
    cout << F(n - 1) + F(n - 2) << endl;
    return F(n - 1) + F(n - 2);
}
int main(){
    int num;
    // cin >> num;
    // for(int i = 0; i < num; i++){
    //     cout << F(i);
    //     if(i != num - 1)
    //         cout << ", ";
    // }
    cout << F(3);
}