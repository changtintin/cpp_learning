#include<iostream>
using namespace std;
class Term{
    public:
    int coef, exp;
    Term *next;
};
class Polynomial{
    public:
        Term *start;
        Term *finish;
    public:
        Polynomial();
        void new_term(int c, int e);
        void show();
        void add(Polynomial b);
};
Polynomial::Polynomial(){
    start = NULL;
    finish = NULL;
}
void Polynomial::new_term(int c, int e){
    Term *new_term  = new Term();
    new_term -> coef = c;
    new_term -> exp = e;
    if(start == NULL){
        start = new_term;
        finish = start;
        new_term -> next = NULL;
    }
    else{
        Term *tmp;
        tmp = start;
        while(tmp -> next != NULL){
            tmp = tmp ->next;
        }
        tmp -> next = new_term;
        finish = new_term;
        new_term -> next = NULL;
    }
}
void Polynomial::show(){
    if(start == NULL){
        cout << "Literally nothing! " << endl;
    }
    else{
        Term *tmp;
        tmp = start;
    cout << "(start) ";
        while(tmp != NULL){
            if(tmp ->next==NULL)
                cout << "(finish) "<< tmp -> coef << "x^" << tmp -> exp;
            else
                cout << tmp -> coef << "x^" << tmp -> exp << " + ";
            tmp = tmp -> next;
        }
        cout << endl;
    }
}
char compare(Term *a, Term *b){
    if(a->exp > b->exp)
        return '>';
    else if(a->exp < b->exp)
        return '<';
    else 
        return '=';
    
}
void Polynomial::add(Polynomial b){
    Polynomial c;
    Term *tmp_a;
    Term *tmp_b;
    tmp_a = start;
    tmp_b = b.start;
    while(tmp_a != NULL && tmp_b != NULL){
        switch (compare(tmp_a, tmp_b)){
            case '>':
                c.new_term(tmp_a -> coef, tmp_a -> exp);
                tmp_a = tmp_a -> next;
            break;

            case '<':
                c.new_term(tmp_b -> coef, tmp_b -> exp);
                tmp_b = tmp_b -> next;
            break;

            case '=':
                c.new_term(tmp_b -> coef + tmp_a -> coef, tmp_a -> exp);
                tmp_a = tmp_a -> next;
                tmp_b = tmp_b -> next;
            break;
        }
    }
    
    while(tmp_b != NULL){
        if(tmp_b -> exp >= b.finish -> exp && tmp_b -> exp < c.finish -> exp){
            c.new_term(tmp_b->coef, tmp_b ->exp);
        }
        tmp_b = tmp_b -> next;
    }
    while(tmp_a != NULL){
        if(tmp_a -> exp >= finish -> exp && tmp_a -> exp < c.finish -> exp){
            c.new_term(tmp_a->coef, tmp_a ->exp);
        }
        tmp_a = tmp_a -> next;
    }
    c.show();
}
int main(){
    Polynomial a;
    a.new_term(22,30);
    a.new_term(2,23);
    a.new_term(2,22);
    a.new_term(88,17);
    a.new_term(66,5);
    a.new_term(3,2);
    a.new_term(99,0);

   
    a.show();

    Polynomial b;
    b.new_term(7,30);
    b.new_term(7,28);
    b.new_term(7,22);
    b.new_term(3,7);
    b.new_term(5,5);
    b.new_term(2,3);

    b.show();

    a.add(b);

}