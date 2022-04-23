#include<iostream>
using namespace std;
class Info{
    friend class Apply;
    public:
        string name;
        int seri_n;
    private:
        int salary;
    public:
        Info(string name, int num, int seri);
    public:
        void promote(int sal);
        
};

Info::Info(string nm, int num, int seri){
    name = nm;
    salary = num;
    seri_n = seri;
}

void Info::promote(int sal){
    cout << "now: "<< salary << endl;
    salary = sal;
    cout << "after promotion: " <<  salary << endl;
}


class Apply{
    public:
        int apy_seri;       
    public:
        void apy_seri_num(int num);
        void show_result(Info a);
};

void Apply::apy_seri_num(int num){
    apy_seri = num;
}

void Apply::show_result(Info a){
    cout << "name: "<< a.name << endl;
    cout << "salary: "<< a.salary << endl;
    cout << "Info serial number: " << a.seri_n << endl;
    cout << "Apply serial number: "<< apy_seri << endl;
}

int main(){
    Info jack("Jack", 300000,45);
    cout << jack.name << " ";
    cout << jack.seri_n << endl;

    Apply apl_a;
    apl_a.show_result(jack);

    apl_a.apy_seri_num(43);
    apl_a.show_result(jack);
}