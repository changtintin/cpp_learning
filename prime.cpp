#include <iostream>
#include <string>
using namespace std;
int main()
{
    int input, cnt = 0;
    cout << "Enter a num." << endl;
    cin >> input;
    if (input < 2)
    {
        cout << "try again mother fucker ~ " << endl;
        cin >> input;
    }
    else if (input == 2)
    {
        cout << "2^1 ";
    }
    int num = input;
    for (int div = 2; div < input; div++)
    {
        while (num % div == 0)
        {
            num = num / div;
            cnt++;
        }
        if (cnt > 1)
        {
            cout << div << " ^ " << cnt << "*";
        }
        else if (cnt == 1)
        {
            cout << div << "*";
        }
        cnt = 0;
    }
    cout << "\b";
}