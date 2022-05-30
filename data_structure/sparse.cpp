#include <iostream>
using namespace std;

class Matrix {
    friend istream& operator>>(istream& input, Matrix& m);

    public:
        int row;
        int value;

        union {
            int a;
            long b;
        };
        

    private:
        int column;
        void show();
};

istream& operator>>(istream& input, Matrix& m) {
    input >> m.column;
    m.show();

    return input;
};

void Matrix::show() {
    cout << "column value: " << column << endl;
};

int main(void) {
    Matrix mat;
    cin >> mat;
}