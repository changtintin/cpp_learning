// solution by pei shih

#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;

    cout << "user name: ";
    cin >> name;

    cout << name << "'s name has ";
    cout << name.length() << " chatacters.";
    cout << endl;

    string cs = "computer science";
    
    cout << "t is in location:" << cs.find("t") << endl;
    cout << "index[3] in cs is: " << cs.at(3) << endl;

    string a = "apple";
    string b = "apple";    
    cout << ((a == b)? "the same": "different") << endl;

    cout << string("apple") + string("Banana") << endl;
}