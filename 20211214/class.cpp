#include <iostream>
using namespace std;

class dog {
    
    public:
        int age;
        string name;
        string color;
    
    public:
       dog();
       void set(string input_name);
       void set(int input_age);
       void set_color(string input_color);
       void show();
};
dog ::dog(){
    color = "black";
    name = "Happy";
    age = 3;
}

void dog::set(string input_name){
    name = input_name;
}
void dog ::set(int input_age){
    age = input_age;
}
void dog::set_color(string input_color){
    color = input_color;
}
void dog ::show(){
    cout << name << color << age << endl;
}

int main(){
    /*
    cout << "Enter the dog's name: ";
    string input_name;
    cin >> input_name;

    cout << "Enter the dog's age: ";
    int input_age;
    cin >> input_age;

    cout << "Enter the dog's color: ";
    string input_color;
    cin >> input_color;
    */

    


    
}
