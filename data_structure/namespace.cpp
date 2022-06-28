#include <iostream>
using namespace std;

namespace basket_ball{
    string ball = "red";
}
namespace baseball{
    string ball =  "white";
}
int main(){
    cout << baseball::ball << endl;
    cout << basket_ball::ball << endl;
}