#include <iostream>
#include <algorithm>
using namespace std;

int main(){
 int numb[7];
 int i, j;

 for(i=0;i<=6;i++){
  cout << "Please enter number: ";
  cin >> numb[i];
 }
sort(numb,numb+7,greater<int>());

 for(i=0;i<=6;i++){
  cout << endl <<  numb[i] << endl;
 }

 cin.ignore();
 cin.get();

 //system("pause");
}