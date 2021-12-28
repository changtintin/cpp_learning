#include <iostream>
#include <math.h>
using namespace std;
int main(){
    float a, b, c ;
    int root1, root2;
    cin >> a >> b >> c ;
    int judge = ( (b*b) - (4*a*c) );
    if(judge < 0){
        cout << "No real root"  << endl;
    }
    else{
        if(judge == 0){
            if(b==0 && c==0){
                cout << "Two same roots x=" << 0 << endl ;
            }
            else{
                cout << "Two same roots x=" << -b / (2*a) << endl ;
            }
        }
        else{ 
            root1 = ( -b + sqrt( judge ) ) / (2 * a) ;
            root2 = ( -b - sqrt( judge ) ) / (2 * a) ; 
            cout << "Two different roots x1=" << root1 << " , x2=" << root2 << endl ;        
        }
    }   
}