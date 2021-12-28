#include <iostream>
using namespace std;
int main(){
    int sequences;
    int a, b, c, d, e;
    
    while(cin >> sequences ) {
        if(sequences>=0 && sequences<=20) {
          for(int i=1; i<=sequences; i++){
                cin >> a >> b >> c >> d; 
                if(d==c+c-b){
                  e=(2*d)-c;
                }
                if (d==c*(c/b)){
                    e=d*(d/c);
                }
                cout << a << " " << b << " "<< c<< " " << d <<" "<< e;
                cout << endl;
            }
          
        }
    }
    
}