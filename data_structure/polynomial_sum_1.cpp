#include<iostream>
#include<string>
using namespace std;

int main(){
    int poly_a[5];
    int poly_b[5];
    cout << "Enter the degree of polynomial a : " << endl;
    for(int i = 0; i < 5; i++){
        cin >> poly_a[i];
    }
    cout << "Enter the degree of polynomial b : " << endl;
    for(int j = 0; j < 5; j++){
        cin >> poly_b[j];
    }
    int poly_sum[5];
    
    for(int i = 0; i < 5; i++){
        poly_sum[i] = poly_a[i]+poly_b[i];
        cout << poly_sum[i] << " ";
    }
}