#include <iostream>
#include <string>
using namespace std;

class term {
    private:
        int coefiicient;
        int exp;
};

class Polynomial {
    public:
        static term termArray[128];
        static int free;
    public:
        int start, finish;
    public:
        void newTerm(int c, int e);
};
term Polynomial::termArray[128];
int Polynomial::free = 0;

void Polynomial::newTerm(int c, int e) {
    if(free >= 128) {
        cout << "Too many." << endl;
        exit(1);
    }
}

void asd(int i) {
    if(i == 7)
        return;
        
    cout << i << endl;
}

int main(void) {
    for(int i = 0; i < 10; i++) {
        asd(i);
    }
    cout << "yaya" << endl;
}