#include<iostream>
using namespace std;
int Compare(int *arr, int l, int r){
    if(arr[l] > arr[r]){
        return l;
    }
    else{
        return r;
    }
}

void Swap(int *arr, int a, int b){
    arr[a] = arr[a] ^ arr[b];
    arr[b] = arr[a] ^ arr[b];
    arr[a] = arr[a] ^ arr[b];
}

void Heapify(int *ary, int idx, int non_leaf, int last){
    if (idx >= 0){
        int l = (idx * 2) + 1;
        int r = (idx * 2) + 2;
        int tmp; // index of greater node

        if(l > last && r <= last){
            tmp = r;
        }
        else if(r > last && l <= last){
            tmp = l;
        }
        else{
            tmp = Compare(ary, l, r);
        }

        if(ary[tmp] >  ary[idx] && idx <= non_leaf){
            Swap(ary, tmp, idx);
            Heapify(ary, tmp, non_leaf, last);
        }
        else{
            idx--;
            Heapify(ary, idx, non_leaf, last);
        }
    }
}

void HeapSort(int *ary, int last, int *heap){ //index of last node 
    while(last >= 0){
        heap[last] = ary[0];
        Swap(ary, last, 0);
    
        int non_leaf = last / 2 - 1;
        last --;
        Heapify(ary, non_leaf, non_leaf, last);
    }
}

void ShowHeap(int *ary, int size){
    cout << "Heap:" << endl; 
    for(int i = 0; i < size; i++){
        cout << ary[i];
        if(i != size - 1){
            cout << ", ";
        }
    }       
    cout << endl;
}

int main(){
    int ary[]={14, 226, 10, 4, 89, 100, 37, 3, 442, 24, 34, 99, 244};

    int size = sizeof(ary)/sizeof(ary[0]);
    int non_leaf = (size / 2) - 1; // non_leaf node index 
    int idx = non_leaf;

    Heapify(ary, idx, non_leaf, size - 1);
    ShowHeap(ary, size);
   
    int *heap = new int[size]; 
    HeapSort(ary, size - 1, heap);
    ShowHeap(heap, size);
}

