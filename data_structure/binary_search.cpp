#include <iostream>
using namespace std;
bool check (int arr[],int input, int n){
    int time = 0;
    for(int i=0; i < n; i++){
        if(input == arr[i]){
            time += 1;
        }          
    }
    if(time !=0){
        return 1 ;
    }
    else {
        return 0;
    }
       
}
int compare(int mid, int input ){
    if(mid > input){
        return 1;
    }
    else{
        if(mid < input){
            return -1;
        }
        else{
            return 0;
        }
    }
}
int binary(int arr[], int input, int n){
    int middle, left=0, right = n - 1;
    while(true){
        middle = (left + right) / 2;
        switch (compare(arr[middle], input)){
            case -1:
                left = middle + 1; 
            break;
            case 0:
                return middle;
            break;
            case 1:
                right = middle - 1;
            break;
        }
    }
}

int main(){ //cin 要由小到大
    int n, input;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cin >> input;
    if(check(arr,input, n)){
        cout << "Element is in index " << binary(arr,input, n) << endl;
    }
    else {
        cout << "Element doesn't exist in array." << endl;
    }
    
}