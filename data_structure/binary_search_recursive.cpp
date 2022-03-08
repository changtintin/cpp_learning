#include<iostream>
using namespace std;
bool check(int arr[], int input, int x){
    for (int i = 0; i < x; i++ ){
        if(input == arr[i]){
           return true;
        }
    }
    return false;
}
int compare(int middle, int input){
    if(middle == input){
        return 0;
    }
    else{
        if(middle > input){
            return 1;
        }
        else{
             return -1;
        }

    }
}
int binary(int arr[], int input, int left, int right){
    while(true){
        int middle= (left + right)/2;
        switch (compare(arr[middle],input)){
            case 0:
                return middle;
                break;
            case 1:
                return binary(arr, input, left, right = middle - 1);
                break;
            case -1:
                return binary(arr, input, left = middle + 1, right);
                break;
        }
    }   
}
int main(){
    int length, input;
    cout << "Array length: ";
    cin >> length;
    int arr[length-1];
    for(int i = 0; i < length; i++){
        cin >> arr[i];
    }
    
    cout << "Enter a number to search: ";
    cin >> input;
    if(check(arr, input, length)==true){
        int left = 0, right = length-1;
        cout << input << " is at number " << binary(arr, input, left, right) <<endl;
    }
    else{
        cout << "This number isn't exist in this array." ;
    }
}