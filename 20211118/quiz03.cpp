#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

bool judge(int a, int b){
    if(a==b)
        return false;
    else
        return true;
}

void big() {
    cout << "too big!" << endl;
}

void too(string str) {
    cout << "too " + str << endl;
}


int main() {
    int x = rand() % 99+ 1;
    int y;
    cin >> y;

    while(judge(x, y) ) {
        if(y >= 1 && y <= 99) {
            if(y > x)
                big();
            else
                too("small!");
        }
        else{
            cout << "enter 1-99" << endl;
        }

        cin >> y;
    }

    if(x == y) {
        cout <<"correct!"<<endl;
    }
}