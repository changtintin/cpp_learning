#include <iostream>
#include <sstream>
#include <string>
#include <map>
using namespace std;
int main(){
    
    string sss = "First word is APPLE.";
    stringstream ss(sss);
    cout << "Insertion with str(): ";
    cout << ss.str() << endl;

    string dup = ss.str();
    cout << "Copied object:" << dup << endl;

    ss.clear();
    ss.str("");
    string ap = "I hate apple.";
    ss << ap << dup;
    cout << "Insertion with <<: ";
    cout << ss.str() << endl;

    stringstream a;
    a << "Hello jerk! ";
    cout << a.str()<<endl;
    a << "Fuck haha ";
    cout << a.str() << endl;
    
    stringstream b;
    b << "a s d ";
    char st;
    b >> st;
    cout << st << endl;

    a.clear();
    a.str("");

    /*
    Count the frequency of each words (include space)
    */
    string itm =  "Geeks For Geeks Ide.";
    map<char, int> mp;
    char *ary = new char[itm.length()];
    ary = (char*)(itm.data()); //強轉型
    
    for(int i = 0; i < itm.length(); i++){
        if(ary[i]){
            mp[ary[i]]++;
        }
    }
    
    for(auto i = mp.begin(); i != mp.end(); i++){
        cout << i -> first << " -> ";
        cout << i -> second << endl;
    }
}
