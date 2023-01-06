#include"iostream"
#include"square.hpp"
#define TEN 10
#define SUM(a, b) (a + b)
#define TIME 12
using namespace std;
int main(){
    int num = 11;
    cout << sq(num) << endl;
    cout << sq(TEN) << endl;
    cout << SUM(TEN, num) << endl;
    cout << TIME << endl;
}