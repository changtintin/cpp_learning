#include <iostream>
using namespace std;
int main() {
    int x, y, z, sum=0 ;
    cin >> x >> y >> z;

    while(x!=0) {
        if(x>6 || x<0) {
            cout << "try again!" << endl;
            cin >> x >> y >> z;
            continue;
        }
        else {
            switch (x) {
                case 1:
                    cout << (y+z) << endl;
                    cin >> x >> y >> z;
                    break;
                case 2:
                    cout << (y-z) << endl;
                    cin >> x >> y >> z;
                    break;
                case 3:
                    cout << (y*z) << endl;
                    cin >> x >> y >> z;
                    break;
                case 4:
                    cout << ( (float)y / z ) << endl;
                    cin >> x >> y >> z;
                    break;
                case 5:
                    sum=0;
                     for (int i = y; i <= z; i++){
                        sum=sum+i;
                    }
                        cout << sum << endl; 
                        break;
                case 6:
                    cout << "undone" << endl;
                    cin >> x >> y >> z;
                    break;
            }
        }
    }
}