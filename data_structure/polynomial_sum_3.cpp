#include<iostream>
#include<string>
using namespace std;
class term{
    public:
        int coef, exp;
};
class Polynomial{
    public:
        static term term_ary[100];
        static int free;
    public:
        int start, finish;
    public:
        void newitem(int c , int e);
        Polynomial add(Polynomial b);
        char compare(int a_exp, int b_exp);
        void show(Polynomial c);
};
int Polynomial::free = 0;
term Polynomial::term_ary[100]; //???

void Polynomial::newitem(int c, int e){
    term_ary[free].coef = c;
    term_ary[free].exp = e;
    free ++;
}
char Polynomial::compare(int a_exp, int b_exp){
    if(a_exp > b_exp){
        return '>';
    }
    else if(a_exp < b_exp){
        return '<';
    }
    else{
        return '=';
    }
            
}
Polynomial Polynomial::add(Polynomial b){
    int a_start = start;
    int b_start = b.start;
    int a_finish = finish;
    int b_finish = b.finish;
    int c_coef;
    Polynomial c;
    c.start = free;
    while(start <= finish && b_start <= b_finish){
        switch (compare(term_ary[a_start].exp, term_ary[b_start].exp)){
            case '>':
                c.newitem(term_ary[a_start].coef, term_ary[a_start].exp);
                a_start ++;
                break;
            case '=':
                c_coef = term_ary[a_start].coef + term_ary[b_start].coef;
                c.newitem(c_coef, term_ary[a_start].exp);
                a_start ++;
                b_start ++;
                break;
            case '<':
                c.newitem(term_ary[b_start].coef, term_ary[b_start].exp);
                b_start ++;
                break;
        }
    }
    c.finish = free - 1;
    return c;
}
void Polynomial::show(Polynomial c){
    for(int i = start; i <= finish; i++){
        cout << term_ary[i].coef << " (X ^ " << term_ary[i].exp << ") ";
        if (i != finish){
            cout << " + ";
        }
    }
    cout << endl;
}
int main(){
    Polynomial a;
    a.newitem(3,20);
    a.newitem(2,7);
    a.newitem(12,3);
    a.newitem(8,1);
    a.newitem(422,0);
    a.start =  0;
    a.finish = 4;
    cout << "Polynomial a: ";
    a.show(a); 

    Polynomial b;
    b.newitem(1,99);
    b.newitem(50,3);
    b.newitem(6,0);
    b.start = 5;
    b.finish = 7;
    cout << "Polynomial b: ";
    b.show(b); 

    Polynomial c = a.add(b);
    cout << "result: ";
    c.show(c);
}
