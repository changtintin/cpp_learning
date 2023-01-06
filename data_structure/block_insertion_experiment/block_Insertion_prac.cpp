#include<iostream>
#include<cmath>
#include<chrono>
#include "Sorting.hpp"
using namespace chrono;
using namespace std;

void BlockInsertion(int *S, int n, int k){
    int BNum = n / k;
    int BSize = k;
    int ep, sp, ini, end, j, Ofs, key;
    int r = k - 1, l = 0;
    
    // insertion sort of block length k
    while(r < n){
        for(int tmp = l; tmp <= r; tmp++){
            int key = S[tmp];
            int j = tmp - 1;
            while(j >= l && key < S[j]){
                S[j + 1] = S[j];
                j--;
            }
            S[j + 1] = key;
        }
        l = r + 1;
        r = l + k - 1;
    }
    
    int Level = 1;
    while(BSize < n){
        sp = 0;
        cout << "Level: " << Level << endl;
        while(sp < n){
            ep = sp + k * BSize - 1;
            ini = sp + 2 * BSize;
            end = ini + BSize - 1;
            j = sp + BSize;
            cout << "BSize: " <<  BSize << endl;
            cout << "sp / ep: " << sp << ", " << ep << endl;
            cout << "ini / end: " << ini << ", " << end << endl;
            cout << "j: " <<  j << endl;
            
            // Store B_2 to another array
            int *E = new int(BSize);
            int e = 0;
            for(int i = sp + BSize; i < sp + 2 * BSize; i++){
                E[e] = S[i];
                e++;
            }
            cout << "Arrary E[]=";
            for(int i = 0; i < BSize;i++)
                cout << E[i] << " ";
            cout << endl << endl;

            while(ini <= ep){
                Ofs = BSize;
                for(int i = end; i <= ini; i++){
                    key = S[i];
                    while(j >= sp && key < S[j]){
                        S[j + Ofs] = S[j];
                        j--;
                    }
                    S[j + Ofs] = key;
                    Ofs --;
                }
                j = ini - 1;
                ini = end;
                end = end + BSize;
            }
            Ofs = BSize;
            j = ep - BSize;
            for(int i  = BSize - 1; i >= 0; i--){
                key = E[i];
                while(j >= sp && key < S[j]){
                    S[j + Ofs] = S[j];
                    j--;
                }
                S[j + Ofs] = key;
                Ofs --;
            }
            sp = ep + 1;
        }
        cout << "Array S[]=";
        for(int i = 0; i < n; i++){
            cout << S[i] << " ";
        }
        cout << endl;
        cout << "___________________________________________________" << endl;
        Level ++;
        BSize = BSize * k;
    }
}
int main(){
    int n = 27;
    int S[n];
    cout << "S[" << n << "]= ";
    for(int i = 0; i < n; i++){
        S[i] = rand() % 100;
        cout << S[i] << " ";
    }
    cout << endl;
    int k = 3;
    
    cout << "Block-Insertion Sort:" << endl;
    cout << "k = " << k << endl;
    cout << "n = " << n << endl;
    auto st = steady_clock::now();
    BlockInsertion(S, n, k);
    // srt::blockInsertionSort(S, 0, n);
    auto ed = steady_clock::now();

    duration<double,nano> diff = ed - st;
    cout << "time:"<< diff.count() << "   nanoseconds"<< endl;

    cout << "After Sorting: \nS[" << n << "]= ";
    for(int i = 0; i < n; i++){
        cout << S[i] << " ";
    }
    cout << endl;

    int A[n];
    for(int i = 0; i < n; i++){
        A[i] = rand() % 100;
    }

    size_t l = 0;
    size_t r = 64;

    auto st2 = steady_clock::now();
    srt::mergeSort(A, l, r);
    auto ed2 = steady_clock::now();
    duration<double,nano> diff2 = ed2 - st2;
    cout << "time:"<< diff2.count() << "  nanoseconds"<< endl;
}