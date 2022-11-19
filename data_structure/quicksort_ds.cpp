#include <iostream>
using namespace std;
void swap(int *d , int *b){
    int tmp = *d;
    *d = *b;
    *b = tmp;
}

int PivotIndex(int ary[], int left, int right){
    int p = ary[right];
    int idx = left;
    
    for(int i = left; i <= right; i++){
        if(ary[i] < p){
            swap(&ary[i], &ary[idx]);
            idx ++;
        }
    }
    swap(&ary[idx], &ary[right]);
    return idx;
}

void QuickSort(int ary[], int left, int right){
    if(left < right){
        int pivot = PivotIndex(ary, left, right);
        cout << pivot << endl;
        for(int i = left; i <= right; i++)
            cout << ary[i] << " ";
        cout << endl;
        cout << "###########################" << endl;

        QuickSort(ary, left, pivot - 1);
        QuickSort(ary, pivot + 1, right);
    }
}

int main(){
    int ary[] = {27, 2, 5, 28, 1, 13, 3, 66, 8};
    int right =  sizeof(ary) / sizeof(int);
    for(int i = 0; i < right; i++)
        cout << ary[i] << " ";
    cout << endl;

    QuickSort(ary, 0, right - 1);

    for(int i = 0; i < right; i++)
        cout << ary[i] << " ";
    cout << endl;
}

/*
Find the pivot:
    Pick one of the number(ary[right]), and loop through array.

    Move the number less than the number to its left:
        Use a pointer point to the most left position of the smaller numbers.
        Swap the position of smaller number and the most left one.
    
    Swap the  position of picked number and the most left number

Partition the array to left and right sub-array by the pivot.
*/