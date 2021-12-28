#include <iostream>
using namespace std;
int main(void){
  int x, y;
  cin >> x >> y;

  while(x!=0 || y!=0){

    if(x<0 || y<0){
      cout << "please try again" << endl;
      cin >> x >> y;
      continue;
    }

      if(x==0){
        cout << (1+y)*y/2 << endl;
        
      }
      else {
        if(y==0) {
          cout << (1+x)*x/2 << endl;
          
          }
        else {
          cout << (x*y) << endl;
          
        }
          
      }
    cin >> x >> y;
  }

}