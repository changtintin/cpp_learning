#include <iostream>
#include <cstdlib>
using namespace std;
 
int main()
{
    int i;
    bool a=true,b=true;
    cin >> i;
    if(i%3==0&&i%5==0)
        a=1;
    else
        a=0;
    if(i%5==0&&i%7==0)
        b=1;
    else
        b=0;
 
    if(a)
        cout<<i<<" =3*5*n"<<endl;
    else
        cout<<i<<" !=3*5*n"<<endl;
    if(b)
        cout<<i<<" =5*7*n"<<endl;
    else
        cout<<i<<" !=5*7*n"<<endl;
}