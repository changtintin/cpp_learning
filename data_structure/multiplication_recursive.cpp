#include <iostream>
using namespace std;
int multi(int a, int b){
    if (b == 0){
        return 0;
    }
    return (multi(a, (b-1))+a);
}
int main() {
    int a, b;
    cin >> a >> b;
    cout << multi(a, b) << endl;
}