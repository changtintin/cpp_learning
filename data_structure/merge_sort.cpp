#include<iostream>
#include<vector>
using namespace std;
void merge_sort(int l, int r, int m, vector<int> &ary, vector<int> &result){
    if (l != r){
        int ptrl = l;
        int ptrr = m + 1;
    
        while(ptrl <= m || ptrr <= r){
            if(ary[ptrl] < ary[ptrr] && ptrl <= m){
                result.push_back(ary[ptrl]);
                ptrl++ ;
            }
            else if(ptrr <= r){
                result.push_back(ary[ptrr]);
                ptrr++;
            }
            else if(ptrl <= m){
                result.push_back(ary[ptrl]);
                ptrl++;
            }
        }
        int c = 0;
        for(int j = l; j <= r; j++){
            if(c < r-l+1){  
                ary[j] = result[c];
                c++;
            }
        }
        result.clear();
    }
}

void merge(int l, int r, vector<int> &ary, vector<int> &result){
    int m = (l + r) / 2;    
    if(l < r){
        merge(l, m, ary, result);
        merge(m + 1, r, ary, result);
        merge_sort(l, r, m, ary, result);
    }    
}

void show(vector<int> &ary){
    for(int f = 0; f < ary.size(); f++){
        cout << ary[f] << " ";
    }
    cout << endl;
}
int main(){
    vector<int> ary;
    vector<int> result;
    ary = {1, 144, 442, -304, 6, 99, 431, 6, 24, 88, 35};
    cout << "input:\t";
    show(ary);
    merge(0, ary.size() - 1, ary, result);
    
    cout << "result:\t";
    show(ary);
}