#include<iostream>
#include<fstream>
#include<string>

/*
without namespace -> std::
*/

int main(){
    std::string str;
    std::ifstream input;
    input.open("test_file.txt");
    getline(input,str);
    std::cout << str << std::endl;
}