#include<iostream>
#include<string>
using namespace std;
// int change(int size_a, int size_b){
//     if(size_a > size_b){
//         return 1;
//     }
//     else if(size_a < size_b){
//         return -1;
//     }
//     else if(size_a == size_b){
//         return 0;
//     }
// }
int main(){
    int poly_a[]={2,13,0,36,1};
    int poly_b[]={5,0,0,2,6,8,9,23};
    int size_a = sizeof(poly_a)/sizeof(poly_a[0]);
    int size_b = sizeof(poly_b)/sizeof(poly_b[0]);
    
    // switch (change(size_a, size_b)){
    //     case -1:{
    //         int * a = poly_a; // correct
    //         int * b = poly_b;
    //     }
    //         break;
    //     case 0:{
    //         int * a = poly_a; 
    //         int * b = poly_b;
    //     }
    //         break;
    //     case 1:{
    //         int * a = poly_b; 
    //         int * b = poly_a;
    //     } 
    //         break;
    // }
    
    int *poly_new = new int[size_b];
    for(int i = 0; i < size_a; i++){
        poly_new[i] =  poly_b[i]+ poly_a[i];
    }
    for(int i = size_a; i < size_b; i++){
        poly_new[i] = poly_b[i];
    }
    for(int i=0; i< size_b; i++){
        cout << poly_new[i] << " ";
    }
}