#include<iostream>
#include<ctime>
#include<chrono>
using namespace std;
using namespace chrono;

void insertion_sort(int *ary, int s){
    for(int i = 1; i < s; i++){
        int key = ary[i];
        int j = i - 1;
        while(key < ary[j] && j >=0 ){
            ary[j+1]=ary[j];
            j--;
        }
        ary[j+1] = key;
    }
}
void show(int *a, int s){
    for(int i = 0; i < s; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}
int main(){
    clock_t s = clock();
    auto st = steady_clock::now();
    cout << "s = " << (double)s / CLOCKS_PER_SEC << endl;

    int ary[]={2, 5, 3, 44, 25, 64, 23, 14, 67, 36};
    insertion_sort(ary, sizeof(ary) / sizeof(int));

    auto ed = steady_clock::now();
    clock_t end = clock();
    cout << "end = " << (double)end / CLOCKS_PER_SEC << endl;
    cout << "sorting time: " << (double)(end - s) / CLOCKS_PER_SEC << endl;
    
    
    duration<double> diff = ed - st;
    cout << "diff:  " << diff.count() << endl;

    show(ary, sizeof(ary) / sizeof(int));
}