#include<iostream>
using namespace std;
void swap(int *v, int k){
    int tmp;
    tmp = v[k];
    v[k] = v[k+1];
    v[k+1] = tmp;
}
void sort(int *v, int n){
    int com = 0;
    for(int i = 0; i < n; i++){
        for(int j = i - 1; j >=0 && v[j] > v[j + 1]; j--){ //限制條件比較多
            swap(v, j);
            com ++;
        }
    }
    cout << "complexity: " << com << endl;
}
int main(){
    int ary[] = {1, 3, 6, 4, 42, 0, 30};
    int size = sizeof(ary)/sizeof(ary[0]);
    sort(ary, size);

    for(int i = 0; i < size; i++){
        cout << ary[i];
        if(i != size - 1)
            cout << ", ";
    }
    cout << endl;

    int arr[] = {1, 3, 6, 4, 42, 0, 30};
    int bcom = 0;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < i; j++){
            if(arr[i] < arr[j]){
                int t = arr[j];
                arr[j] = arr[i];
                arr[i] = t;
            }
            bcom ++;
        }
    }
    
    cout << "bubble sort: " << endl;
    for(int i = 0; i < size; i++){
        cout << arr[i];
        if(i != size - 1 )
            cout << ", ";
    }
    cout << endl;
    cout << "bubble complexity: " << bcom << endl;
}