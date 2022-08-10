#include<iostream>
using namespace std;
int main(){
    unsigned max = UINT32_MAX;
    int min = INT32_MIN;
    cout << "max: " << max << endl;
    cout << "max + max: " << max + max << endl;
    cout << "max + max +8: " << max + max +8 << endl;

    cout << "min: " << min << endl;  
    cout << "min - 3: " << min - 3 << endl;  

}