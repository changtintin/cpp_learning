#include <iostream>
#include <stdio.h>      
#include <math.h> 
#include <iomanip>
using namespace std;

void show_rgt(char *tree, int i, int k){
    while(i > pow(2, k- 1)){
        cout << "No child, try again: " << endl; ;
        cin >> i;
    }
    int g = tree[i] - 64; // order of the alphabet
    cout << tree[i + g + 1] << endl;
}

void show_lft(char *tree, int i, int k){
    while(i > pow(2, k- 1)){
        cout << "This node has no child, try again: " << endl; ;
        cin >> i;
    }
    int g = tree[i] - 64; // order of the alphabet
    cout << tree[i + g] << endl;
}

void prt_tree(char *tree, int item, int k){
    // //triangle
    // int j = 1;
    // for(int i = 0; i < item; i++){
    //     cout << setw(3) << tree[i] << " ";
    //     if(i + 1 == pow(2, j) - 1){
    //         cout << endl;
    //         j++;
    //     }
    // }

    int l = pow(2, k) / 2; // space of starting every line
    int sp = k; // space from first one in the line
    int idx = 0; //idx of tree[item]

    for(int i = 0; i < k; i++){ // next line
        for(int j = 0; j < pow(2, i); j++){
            if(i >= 1 && j > 0){
                cout << setw(pow(2, sp) ) << tree[idx];
                idx ++;
            }
            else if(j == 0){
                cout << setw(l) << tree[idx];
                l = l / 2;
                idx ++;
            }
        }
        sp --;
        cout << endl;
    }
}
int main(){
    int k = 5; // depth (height)
    int item = pow(2, k) - 1; // num of nodes in tree
    char tree[item];
    for(int i = 0; i < item; i++){
        tree[i] = 65 + i  ;
    }
    int j; // index of ary
    show_rgt(tree, 0, k);
    cout << endl;
    prt_tree(tree, item, k);
}