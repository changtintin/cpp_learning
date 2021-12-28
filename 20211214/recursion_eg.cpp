// A C++ program to demonstrate working of
// recursion
#include <bits/stdc++.h>
using namespace std;
 
void printFun(int test)
{
    if (test < 1)
        return;
    else {
        cout << test << " ";
        printFun(test - 1); // statement 2
        cout << test << " ";
        return;
    }
}
 
// Driver Code
int main()
{
    int test = 3;
    printFun(test);
}

//Output : 3 2 1 1 2 3