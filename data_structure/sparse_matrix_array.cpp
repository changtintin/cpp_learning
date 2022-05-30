#include<iostream>
#include<string>
#include <algorithm>

using namespace std;
class Term{
    public:
        int row, column, value;
    public:
        Term();
};
Term::Term() {
    row = 0;
    column = 0;
    value = 0;
};
class Matrix{
    public: 
        int Row, Column, index;
        Term matrix[128];
    public:
        Matrix(int r, int c);
    public:
        void new_term(int r, int c, int v);
        void show();
        void row_asscending();
        void column_asscending(); 
        void setMatrix();
        void add(Matrix b);
        char compare(Matrix b, int i, int j);
        int search(int r, int c);
        void transpose();
        void transpose_new();
};
Matrix::Matrix(int r, int c) {
    Row = r;
    Column = c;
    index = 0;
}
void Matrix::row_asscending() {
    for(int i = 0; i < index; i++){
        for(int j = 0; j < index; j++){
            if(matrix[i].row < matrix[j].row){
                Term t = matrix[i];
                matrix[i] = matrix[j];
                matrix[j] = t; 
            }
        }
    }
}
void Matrix::column_asscending() {
    Term t;
    for(int i = 0; i < index; i++){
        for(int j = 0; j < index; j++){
            if(matrix[i].row == matrix[j].row && matrix[i].column < matrix[j].column){
                t = matrix[i];
                matrix[i] = matrix[j];
                matrix[j] = t; 
            }
        }
    }
}
void Matrix::new_term(int r, int c, int v) {
    if(r < Row && c < Column ) {
        matrix[index].row = r;
        matrix[index].column = c;
        matrix[index].value = v;
        index++;
    }
    else {
        cout << "Try other row/column!" << endl;
    }
    row_asscending();
    column_asscending();
}
void Matrix::show() {
    for(int i = 0; i < index; i++) {
        cout << "row: " << matrix[i].row;
        cout << ", column: " << matrix[i].column;
        cout << ", value: " << matrix[i].value << endl;
    }
}
char Matrix::compare(Matrix b, int i, int j){
    if(matrix[i].row > b.matrix[i].row)
        return '>';
    else if(matrix[i].row < b.matrix[i].row)
        return '<';
    else if(matrix[i].row == b.matrix[j].row && matrix[i].column == b.matrix[j].column)
        return '=';
    else 
        return '+';
}
int Matrix::search(int r, int c){
    for(int i = 0; i <= Row; i++){
        if(matrix[i].row == r && matrix[i].column == c){
            return matrix[i].value;
        }
    }
    return 0; // doesn't exist
}
void Matrix::add(Matrix b){
    Matrix c (Row, Column);
    for(int i = 0; i <= Row; i++){
        for(int j = 0; j <= Column; j++){
            int v_a = search(i, j);
            int v_b = b.search(i, j);
            if(v_a != 0 && v_b != 0 ){
                if(v_a != 0){
                    c.new_term(i, j, (v_a + v_b));
                }
            }
            else{
                if(v_b != 0){
                    c.new_term(i, j, v_b);
                }
                else if(v_a != 0){
                    c.new_term(i, j, v_a);
                }
            }
        }
    }
    c.show();
} 
void Matrix::transpose(){
    Matrix b(Column, Row);
    int num[Column];
    
    for(int i = 0; i <= Row; i++){
        for(int j = 0; j <= Column; j++){
            int v_a = search(i, j);
            if(v_a != 0){
                b.new_term(j, i, v_a);
            }
        }
    }

    b.show();
} 
void Matrix::transpose_new(){
    int *row_size = new int[Column]; //沒有名字的int陣列  匿名函數
    int *row_start = new int[Column];
    Matrix c(Column, Row);
    c.index = index;
    if(index > 0){
        for(int i = 0; i < Column; i++ ){
            row_size[i] = 0; 
        }
        for(int i = 0; i < index; i++){
            row_size[matrix[i].column]++ ;
        }
        row_start[0] = 0;
        for(int i = 1; i < Column; i++){
            row_start[i] = row_start[i-1] + row_size[i-1];
        }
        for(int i = 0; i < index; i++){
            int tmp = row_start[matrix[i].column];
            c.matrix[tmp].row = matrix[i].column;
            c.matrix[tmp].column = matrix[i].row;
            c.matrix[tmp].value = matrix[i].value;
            row_start[matrix[i].column]++ ;
        }
        delete [] row_size;
        delete [] row_start;
    }
}
int main(void) {
    Matrix a(6, 6);
    a.new_term(1,1,1);
    a.new_term(4,1,4);
    a.new_term(3,3,2);
    a.new_term(1,4,3);
    a.new_term(4,5,11);
    
    a.show();
    cout << "________" << endl;
    Matrix b(6, 6);
    b.new_term(1,1,5);
    b.new_term(5,0,6);
    b.new_term(3,2,7);
    b.new_term(5,3,8);
    b.new_term(1,4,9);
    b.new_term(0,5,10);
    b.show();
    cout << "________" << endl;
    cout << "Result: " << endl; 
    a.add(b);
    cout << "________" << endl;

    Matrix d(5,3);
    d.new_term(0,2,51);
    d.new_term(3,1,6);
    d.new_term(2,2,17);    
    d.new_term(2,0,2);
    d.new_term(4,1,51);
    d.new_term(1,2,5);
    d.show();
    cout << "________" << endl;
    d.transpose();
    cout << "________" << endl;
    d.transpose_new();
    d.show();
}