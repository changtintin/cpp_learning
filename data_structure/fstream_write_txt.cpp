#include <iostream>
#include <fstream>
using namespace std;
int main(){
    ofstream fout("test_file.txt", ios::app);
    fout <<  "It's okay." << endl;
    
    fout.close();

    ifstream in("test_file.txt");
    string s;
    while(in){
        getline(in,s);
        cout << s ;
    }
    cout << endl;
    ofstream ot("test_file.txt", ios::out|ios::trunc);
    ot.close();

    string st;
    cout << "After trunc:" << endl;
    while(in){
        getline(in,st);
        cout << st ;
    }
}