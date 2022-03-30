#include<iostream>
#include<string>
using namespace std;

class User{
    public: 
        char password[12];
        char name[10];
    public:
        User(char name[10], char password[12]);
        void revise(char name[10]);
};
User::User(char name[10], char password[12]){}
class Table{
    public:
        User user;
    public:
        bool login();
        void revise();
};
bool Table::login(){
    char name[10];
    int count = 0;
    cout << "enter user name: ";
    cin >> name;
    while(true){
        if(name == user.name){
            char pwd[12];
            cout << "enter passwords: ";
            cin >> pwd;
            if(pwd == user.password){
                cout << "Login Successful! " << endl;
                return true;
            }
        }
        else{
            cout << "Please try again" << endl;
            count ++;
            if(count > 5){
                return false;
            }
        }
    }
}
void Table::revise(){
    if(login() == true){
        char n[10];
        char p[12];
        cout << "name: ";
        cin >> n[10];
        user.name = n[10];
        cout << "password: ";
        cin >> p[12];
        user.password = p[12];
        cout << "OK! "<< endl;
    }

}
int main(){
    User A("Jack","123asd");
    User B("Ting","4567890");
    Table Jack;
    Table Ting;
    Ting.login();
    Ting.revise();
    cout << A.name << " " << endl;
    cout << A.name << " " << endl;
}