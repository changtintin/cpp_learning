#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

void read_record(int row){
    ifstream ifs, cpy;
    static int ary[18];
    string line, word;
    ifs.open("read_incsv.txt", ios::in);
    if(!ifs.is_open()){
        cout << "Failed";
    }
    else{
        int j = 0;

        for(int i = 0; i < row; i++){
            /*Extracts characters from is and stores them into str 
            until the delimitation character delim is found 
            (or the newline character, '\n'
            */
            getline(ifs,line); 

            /* 
            A stringstream associates a string object with a stream 
            allowing you to read from the string 
            as if it were a stream (like cin). 
            To use stringstream, we need to include sstream header file. 
            */
            stringstream s(line);  //Converting to stringstream object
            while(getline(s, word, ',')){
                // convert string to integer
                ary[j] = stoi(word); 
                j++;
            }
        }
        for(int p = 0; p < j; p++){
            cout << ary[p] << " ";
        }
        cout << endl;
    }
}

int main(){
    read_record(9); 

    stringstream aa;
    stringstream num;
    string eg;
    int n;
    num << 4838;
    num >> n;
    aa << "hello,there " << "tintin";
    cout << "n+36 "<< n+36 << endl;
    cout << "aa: " << aa.str();

}