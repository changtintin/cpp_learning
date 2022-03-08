#include <iostream>
#include <string>
using namespace std;

class term {
    public:
        int coeffiicient;
        int exponential;
};

class Polynomial {
    public:
        static term termArray[128];
        static int free;
    public:
        int start, finish;
    public:
        void newTerm(int c, int e);
        char compare(int a_exp, int b_exp);
        Polynomial add(Polynomial B);
        void show(string s);
};
term Polynomial::termArray[128];
int Polynomial::free = 0;

void Polynomial::newTerm(int c, int e) {
    if(free >= 128) {
        cout << "Too many." << endl;
        exit(0);
    }
    
    termArray[free].coeffiicient = c;
    termArray[free].exponential = e;
    free++;
}

char Polynomial::compare(int a_exp, int b_exp) {
    if(a_exp == b_exp)
        return '=';
    else if(a_exp < b_exp)
        return '<';
    else
        return '>';
}

Polynomial Polynomial::add(Polynomial B) {
    Polynomial C;
    int a_pointer = start;          // a_pointer = 0
    int b_pointer = B.start;        // b_pointer = 2
    C.start = free;               // c_start = 6

    int c;
    while(a_pointer <= finish && b_pointer <= B.finish) {
        switch(compare(termArray[a_pointer].exponential, termArray[b_pointer].exponential)) {
            case '=':
                c = termArray[a_pointer].coeffiicient + termArray[b_pointer].coeffiicient;
                if(c != 0) {
                    newTerm(c, termArray[a_pointer].exponential);
                    a_pointer++;
                    b_pointer++;
                }
                break;
            case '<':
                newTerm(termArray[b_pointer].coeffiicient, termArray[b_pointer].exponential);
                b_pointer++;
                break;
            case '>':
                newTerm(termArray[a_pointer].coeffiicient, termArray[a_pointer].exponential);
                a_pointer++;
                break;
        }
    }

    C.finish = free - 1;
    return C;
}

void Polynomial::show(string s) {
    cout << s;

    for(int i = start; i <= finish; i++) {
        int c = termArray[i].coeffiicient;
        int e = termArray[i].exponential;
        if(i != start)
            cout << " + ";
        if(e != 0)
            cout <<  c << "x^(" << e << ")";
        else if(e == 1)
            cout <<  c << "x";
        else
            cout << c;
    }
    cout << endl;
}

int main(void) {
    (new Polynomial) -> newTerm(2, 1000);
    (new Polynomial) -> newTerm(1,    0);
    (new Polynomial) -> newTerm( 1, 4);
    (new Polynomial) -> newTerm(10, 3);
    (new Polynomial) -> newTerm( 3, 2);
    (new Polynomial) -> newTerm( 1, 0);

    Polynomial a, b;
    a.start  = 0;
    a.finish = 1;
    b.start  = 2;
    b.finish = 5;

    Polynomial c = a.add(b);

    a.show("a: ");
    b.show("b: ");
    c.show("c: ");
}