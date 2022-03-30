#include<iostream>
#include<string>
using namespace std;
void print(int *ary, int len){
    for(int i = 0; i < len; i++ ){
        cout << ary[i] << " ";
    }
    cout << endl;
} 
void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
    cout <<"swap a:" <<*a  <<"  b:"<< *b <<endl;
}
int partition(int *ary, int front, int end){
    int pivot = ary[end];
    int i = front - 1, j = front; // i = -1 只有第一次會對
    while(j < end){
        if(j > i && ary[j] < pivot){
            swap(&ary[i+1], &ary[j]);
            i++ ;
        }
        j++ ;
    }
    swap(&ary[i+1], &ary[end]); //swap(ary[i+1], ary[end]) 不行嗎QQ -> 真的不行：如果只有數值換
    return i+1 ;
}
void quick_sort(int *ary, int front, int end){
    if(front < end){ 
        int pivot = partition(ary, front, end); //位址
        quick_sort(ary, front, (pivot - 1));
        quick_sort(ary, (pivot + 1), end); 
    }
    
}
int main(){
    int ary[] = {82, 25, 6, 1, 17, 4, 2, 10};
    int len = sizeof(ary)/sizeof(ary[0]);
    print(ary, len);
    quick_sort(ary, 0, len-1);
    print(ary, len);
}