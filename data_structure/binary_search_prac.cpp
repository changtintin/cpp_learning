#include<iostream>
using namespace std;
bool check(int arr[], int target, int num){
    int time = 0;
    for (int i = 0; i < num; i++ ){
        if(target == arr[i]){
           return true;
        }
    }
    return false;
}
int main(){
    int num;
    cout << "Array length: ";

    while(cin >> num){
        if(num > 1){
            break;
        }
        else{
            cout << "Try again" << endl;
        }
    }
    cout << "Enter the numbers in the array: ";
    int arr[num],input;

    for (int i = 0; i < num; i++ ){
        cin >> arr[i];
    }

    cout << "Sort by assending :";
    sort(arr,arr+num,less<int>());
    for (int i = 0; i < num; i++ ){
        cout << arr[i] << " ";
    }
    cout << endl;

    int left = 0, right = (num-1), middle= (left + right)/2, target;
    cout << "Enter a number to search: ";
    cin >> target;

    if(check(arr, target, num) == true) {
        while(middle >= 0) {
            if(arr[middle] == target) {
                cout << arr[middle] << " is at number " << middle + 1 ;
                break;
            }
            else{
                if(target > arr[middle])
                    left = middle + 1;
                else
                    right = middle - 1;
                middle= (left + right)/2;

            }
            cout << "L: " << left << ", M: " << middle << ", R: " << right << endl;
        }
    }
    else{
        cout << target << "isn't in the array.";
    }
}