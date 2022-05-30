#include<iostream>
#include<iomanip>
using namespace std;

/*
bool for C language: 
************************
enum Boolean {    
    FALSE, TRUE  
};
*/

template <class T>
struct Entry{
    T val;
    int row;
    int col;
};

template <class T>
class Matrix;

template <class T>
class Matrix_node{
    public:
        friend class Matrix<T>;
    private:
        Matrix_node<T> *left;
        Matrix_node<T> *up;
        Matrix_node<T> *down;
        Matrix_node<T> *right;

        /*
        This is most useful when the type of data 
        being passed through functions is unknown, 
        using a union which contains all possible data types 
        can remedy this problem.
        */
        union{
            Matrix_node<T> *next; // H node
            Entry<T> *entry;  // entry node
        };
    public:
        Matrix_node(bool b, Entry<T> *t = NULL); //entry node & H node share this class
};

template <class T>
Matrix_node<T>::Matrix_node(bool b, Entry<T> *t) {
    // head
    if(b){
        left = NULL;
        up = NULL;
        right = this;
        next = this;
        down = this;
    } 
    else{ // entry
        entry = t;
    }
}

template <class T>
class Matrix{
    friend class Matrix_node<T>;
    private:
        Matrix_node<T> *head_nd;
        int row;
        int col;
    public: 
        Matrix(int r, int c);
    public: 
        void enter_rc();
        void add_node(bool bol);
        Entry<T>* entry(T v, int r, int c);
        void show();
        void drop(Matrix_node<T> *e);
        void find(int r, int c);
};

template<class T>
void Matrix<T>::drop(Matrix_node<T> *e){
    e -> left -> right = e -> right;
    e -> right -> left = e -> left;
    // e -> right = NULL;
    // e -> left = NULL;

    e -> up -> down = e -> down;
    e -> down -> up = e -> up;
    // e -> down = NULL;
    // e -> up = NULL;

    delete e;
}

template<class T>
void Matrix<T>::find(int r, int c){
    if( r > row || c > col){
        cout << "Out of range! " << endl;
    }
    else{
        Matrix_node<T> *tmp = head_nd;
        int max = 0;
        if(row > col)
            max = r;
        else
            max = c;

        for(int i = 0; i < max; i++){ 
            tmp = tmp -> next;
            cout << "i:   " << i << endl;
            if(i + 1 == r ){
                Matrix_node<T> *h = tmp;
                int tp = 1;
                
                while(h -> right != tmp){
                    cout << "tp: " << tp << endl;
                    h = h -> right;
                    if(h -> entry -> col == c){
                        cout << "drop at" <<endl;
                        drop(h);
                        break;
                    }
                    tp ++;
                }
               
            }
            else if(i + 1 == c){
                Matrix_node<T> *h = tmp;
                int tp = 1;
                
                while(tmp -> down != tmp){
                    cout << "tp: " << tp << endl;

                    h = h -> down;
                    if(h -> entry -> row == r){
                        cout << "drop at" << tp << endl;

                        drop(h);
                        break;
                    }
                }
                
            }
        }
    }
}

template <class T>
Matrix<T>::Matrix(int r, int c) {
    row = r;
    col = c;
    cout << row << ", " << col << endl;
    head_nd = new Matrix_node<T>(true);
    int max;
    if(row > col)
        max = row;
    else
        max = col;
    for(int i = 0; i < max; i++){
        add_node(true);
    }
}

template <class T>
void Matrix<T>::add_node(bool bol) {
    if(bol){ // add head
        Matrix_node<T> *n = new Matrix_node<T>(bol);
        Matrix_node<T> *tmp = head_nd;
        while(tmp -> next != head_nd){
            tmp = tmp -> next;
        }
        tmp -> next  = n;
        n -> next = head_nd;
    }
    else{ // add entry
        int v = 0, r = 0, c = 0;
        while(true){
            cout << "enter val, row, col of entry: " << endl;
            cin >> v >> r >> c;
            if(r > row || c > col){
                cout << "Out of range!" << endl;
                continue;
            }
            else
                break;
        }
        Entry<T> *en = entry(v, r, c);
        Matrix_node<T> *n = new Matrix_node<T>(bol, en);

        int i = 1; // row
        int j = 1; // col

        Matrix_node<T> *tmp = head_nd -> next;
        while(tmp != head_nd){
            if(i == en ->row){
                Matrix_node<T> *h = tmp;
                while(h -> right  != tmp){
                    h = h -> right;
                }
                h -> right = n;
                n -> left = h;
                n -> right = tmp;
            }
            else if(j == en -> col){
                Matrix_node<T> *h = tmp;
                while(h -> down != tmp){
                    h = h -> down;
                }
                h -> down = n;
                n -> up = h;
                n -> down = tmp;
            }
            else if(i > row && j > col){
                break;
            }
            tmp = tmp -> next;
            i++;
            j++;
        }
    }
}

template <class T>
Entry<T>* Matrix<T>::entry(T v, int r, int c) {
    Entry<T> *e = new Entry<T>();
    e -> val = v;
    e -> row = r;
    e -> col = c;
    return e;
}

template <class T>
void Matrix<T>::show(){
    cout << "(" << setw(4) << row << "*"<< col << setw(4)<< ")";
    cout << "----->" ;
    bool t;
    int j, s;
    for(int i = 0; i < col; i++){
        cout << "(" << setw(4) << "H " <<i+1 << setw(5)<< ")";
        if(i != col - 1){
            cout <<  "----->" ;
        }
    }
    cout << endl;
    cout << setw(5) << "|" << endl;
    
    Matrix_node<T> *tmp = head_nd;
    for(int i = 1; i <= row; i++){
        cout << "(" << setw(4) << "H " <<i << setw(5)<< ")";
        tmp = tmp -> next;
        Matrix_node<T> *tt = tmp -> right;
        for(int f = 1; f <= col; f++){
            if(tt-> entry -> col == f){
                cout << "----->" ;
                cout << "(" << tt -> entry -> row << "," << tt -> entry -> col << ",";
                cout << setw(5) << tt -> entry -> val << ")";
                tt = tt -> right;
            }
            else{
                if(tt != tmp)
                    cout << "-----------------";
                else if(tt == tmp)
                    cout << setw(17) << " "; 
            }
        }
        if(i != row){
            cout << endl;
            cout << setw(5) << "|" << endl;
        }
    }
    cout << endl;
}
int main() {
    Matrix<int> matx(3,4);
    for(int i = 0; i < 4; i++){
        matx.add_node(false);
    }
    matx.show();
    matx.find(2,1);
    cout << endl;
    
    // cout << endl;
    // cout << "*************************"  << endl;
    // cout << endl;

    // matx.find(3,3);
    // cout << endl;
    matx.show();

    
}