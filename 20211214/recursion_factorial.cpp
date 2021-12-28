#include <iostream>
using namespace std;
int factorial(int n){
    int a ;
    if(n < 1){
         return 1;
    }
    else{
        a = n * factorial(n-1);
        return a;
    }
    

}
int main(){
    int n;
    cin >> n;
    cout << factorial(n);
    
}