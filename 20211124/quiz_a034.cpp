#include <iostream>
#include <math.h>
using namespace std;
int main(){
    int x,sum=0,result;
    cin >> x;
    int y=x/2;

    if(x%2==0){
        for(int i=0; i<=x; i=i+1){
            result=pow(2,i);
            sum=sum+i
            if(sum>=y)
                break;
            
        }

        
    }

    

    

}