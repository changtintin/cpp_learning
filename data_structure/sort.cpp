#include <iostream>
#include <vector>
using namespace std;
void InsertSort(int *ary, int size){
    for(int i = 0;i < size; i++){
        int num = ary[i];
        int j = i - 1;
        while(j >= 0 && ary[j] > num){
            ary[j + 1] = ary[j];
            j--;
        }
        ary[j + 1] = num;
    }
}
void show(vector<int> &a){
    for(int i = 0; i < a.size(); i++){
        cout << a[i];
        if(i != a.size() - 1)
            cout << ", ";
    }
    cout << endl;
}
void insertion_sort(vector<int> &ary){
    int s = ary.size();

    for(int i = 1; i < s; i++){
        cout << "i = " << i << endl;
        for(int j = i - 1; j >= 0; j--){
            cout << "\tj = " << j << endl;
            if(ary[i] > ary[j]) {
                ary.insert(ary.begin() + j + 1, ary[i]);
                ary.erase(ary.begin() + i + 1);
                break;
            }
            else if(j == 0 && ary[i] != ary[0]){
                ary.insert(ary.begin(), ary[i]);
                ary.erase(ary.begin() + i + 1);
            }
        }
        show(ary);
        cout << "______________________" << endl;
    }
}
/*
Insertion Sort:
    · if the element is less than num, insert to the right of the element
    · if that element isn't exist, num will be the first element of the array

19 31 5 11 9 4 6 44 35
*
19 31 5 11 9 4 6 44 35
   *
5 19 31 11 9 4 6 44 35
     *
5 4 6 9 11 19 31 44 35
              *
5 4 6 9 11 19 31 44 35
                 *

*/
void bubble_sort(vector<int> &a){
    for(int i = 0; i < a.size(); i++){        
        int t = i;
        for(int j = i - 1; j >= 0; j--){            
            if(a[j] > a[t]){
                int tmp = a[j];
                a[j] = a[t];
                a[t] = tmp;
                t = j;                
            }
        }
    }
}

/*
★ Selection Sort:
    Traverse the every element(key) in the array
        Each round:
            · Traverse the rest of the elements in the array
            · if the value less than key, then swap the index with key
            · Until find the least value and swap it with key
            · So the traversed array would be sorted in ascending order
*/
void selection_sort(vector<int> &a){
    int p;
    for(int i = 0; i < a.size(); i++){
        p = i;
        for(int j = a.size() - 1; j > i; j--){
            if(a[j]< a[p]){
                p = j;
            }
        }
        int tmp = a[p];
        a[p] = a[i];
        a[i] = tmp;
    }
}

void merge(vector<int> &ary, int l, int r) {
    int m = (l + r) / 2;
    
    int index1 = l;
    int index2 = m + 1;

    vector<int> tmp(r - l + 1);
    for(int i = 0; i < tmp.size(); i++) {
        if(index1 == m + 1) {
            tmp[i] = ary[index2];
            index2++;
            continue;
        }

        if(index2 == r + 1) {
            tmp[i] = ary[index1];
            index1++;
            continue;
        }

        if(ary[index1] < ary[index2]) {
            tmp[i] = ary[index1];
            index1 ++;
        }
        else {
            tmp[i] = ary[index2];
            index2 ++;
        }
    }

    for(int i = 0; i < tmp.size(); i++) {
        ary[l + i] = tmp[i];
    }
}

void merge_sort(vector<int> &ary, int l, int r) {
    if(l == r) {
        return;
    }

    int m = (l + r)/2;

    cout << l << " " << m << " " << r << endl;
    // 排左邊
    merge_sort(ary, l, m);
    // 排右邊
    merge_sort(ary, m+1, r);

    merge(ary, l, r);
}

int main(){
    // vector<int> ary;
    // ary = {22, 3, 15, 82, 41, 6, 14};

    // cout << "Insertion Sort:" << endl;
    // show(ary);
    // insertion_sort(ary);
    // show(ary);
    // cout << "_____________________" << endl;

    // vector<int> arr;
    // arr = {25, 42, 85, 31, 19, 77, 10};
    // cout << "Bubble Sort:" << endl;

    // show(arr);
    // bubble_sort(arr);
    // show(arr);
    // cout << "_____________________" << endl;


    // vector<int> a;
    // a = {11, 42, 160, 2, 19, 92, 74};
    // cout << "Selection Sort:" << endl;
    // show(a);
    // selection_sort(a);
    // show(a);

    // vector<int> m;
    // m = {1, 4, 16, 22, -7, 9, 12, 25, 0, 87, 44, 92, 19, 13, 7, 3};
    // merge_sort(m, 0, m.size() - 1);

    // for(int i = 0; i < m.size(); i++) {
    //     cout << m[i] << " ";
    // }
    // cout << endl;


    vector<int> v;
    v = {41, 34, 16, 22, -7, 1, 19, 63, 23};
    insertion_sort(v);
   
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}