#include <iostream>
#include<string>
using namespace std;
void print_ary(int *ary, int term){
    for(int i = 0; i < term; i++ ){
        cout << ary[i]  << "   " ;
    }
    cout << endl;
}
void swap(int *i, int *j){
    int tmp = *i;
    *i = *j;
    *j = tmp;
}
int partition(int *ary, int front, int end){
    int pivot = ary[end];
    int i = front - 1; 
    for(int j = front; j < end; j++){
        if(ary[j] < pivot){
            i++;
            swap(&ary[i], &ary[j]);
        }
    }
    i++ ;
    swap(&ary[i], &ary[end]);
    return i;
}
void quick_sort(int *ary, int front, int end){
    if(front < end){
        int pivot = partition(ary, front, end);
        quick_sort(ary, front, pivot-1);
        quick_sort(ary, pivot+1, end);
    }
    
}
int main(){
    int term = 10;
    int ary[] = {2, 6, 3, 10, 1, 4, 5, 7, 9, 8};
    print_ary(ary, term); //ary沒[]  = 位址
    quick_sort(ary, 0, term - 1);
    print_ary(ary, term);
}