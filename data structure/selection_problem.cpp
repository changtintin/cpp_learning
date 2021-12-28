#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main(){
    cout << "How many numbers? " << endl;
    int n, k, time = 0;
    cin >> n;
    cout << "Please enter the numbers: " << endl;
    int arr[n];
    for(int i = 0; i < n; i++ ){
       cin >> arr[i];
    }
    cin >> k;
    sort( arr, arr+n,less<int>() );
    for(int i=0; i<k; i++){
        time +=1;
        if(time == k)
            cout << arr[i];
    }
    
    return 0;

}