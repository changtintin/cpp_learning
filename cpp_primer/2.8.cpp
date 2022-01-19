// Using escape sequences, write a program to print 2M followedby a newline.
//Modify the program to print 2, then a tab, then an M, followed by a newline.

#include <iostream>
#include <string>
using namespace std;
int main()
{
    cout << "2\115\n"
         << "#" << endl;
    cout << "2\t\115\n"
         << "#" << endl;
    ;
}