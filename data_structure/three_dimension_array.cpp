#include <iostream>
using namespace std;
int main(){
    int ary[2][4][3] = {
        { {1,23,34}, {11,5,7}, {32,2,11}, {17,99,47} },
        { {2,53,38}, {91,95,97}, {22,54,61}, {27,93,36} },
    };

    // for(int i = 0; i < 2; i++){
    //     for(int j = 0; j < 4; j++){
    //         for(int h = 0; h < 3; h++){
    //             cout << ary[i][j][h] << endl;
    //         }
    //     }
    // }
    // int e[2][2] = {{1,0},{0,1}};
    // for(int i = 0; i < 2; i++){
    //     for(int j = 0; j < 2; j++){
    //         if(e[i][j])
    //             cout << i << ", " << j << endl;
    //     }
    // }
    int c[2][2][4];
    c[0][0][1] = 8;
    cout << c[1][1][2] << endl;
}