#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

template <class T1>
class Node{
    public:
        T1 value;
        bool result;
        Node<T1> *left;
        Node<T1> *right;
        Node<T1> *parent;
        Node<T1> *next;

    public:
        Node(T1 v);
};

template <class T1>
Node<T1>::Node(T1 v){
    value = v;
    next = NULL; // down to next element in stack
    left = NULL;
    right = NULL;
}

template <class T1>
class ExpressionTree{
    friend class Node<T1>;
    public:
        Node<T1> *root;
        int num;
    public:
        ExpressionTree(Node<T1> *r, int n);
        void In(Node<T1> *r); // Inorder: L V R
};

template <class T1>
ExpressionTree<T1>::ExpressionTree(Node<T1> *r, int n){
    num = n;
    root = r;
    In(r);
    cout << endl;
}

template <class T1>
void ExpressionTree<T1>::In(Node<T1> *r){
    if (r == NULL)
            return;
    else{
        In(r -> left);
        cout << r -> value;
        In(r -> right);
    }
}

template <class T1>
class Stack{
    friend class Node<T1>;
    public:
        Node<T1> *head; // top of the stack
        
    public:
        Stack();
    public:
        void push(Node<T1> *n);
        void pop();
        void eva(Node<T1> *nd);
};

template <class T1>
Stack<T1>::Stack(){
    head = NULL;
}

template <class T1>
void Stack<T1>::push(Node<T1> *n){
    if(head == NULL){
        head = n;
    }
    else if(n -> value == '-'){
        n -> next = head -> next;
        n -> right = head;
        head = n;
    }
    else{
        n -> next = head;
        head = n;
    }
}

template <class T1>
void Stack<T1>::pop(){
    head = head -> next;
}

template <class T1>
void Stack<T1>::eva(Node<T1> *nd){
    switch (nd -> value){
        case '^':
            nd -> result = nd -> left-> result && nd -> right -> result;
            break;

        case 'v':
            nd -> result = nd -> left-> result || nd -> right -> result;
            break;

        case '-':
            nd -> result = ! nd -> right -> result;
            break;

        default:
            break;
    }
}

template<class T1>
class Tree{
    public: 
        Node<T1> *root;
        bool arr[30];
        int y;
    public:
        Tree(int lay, T1 rt){
            Node<T1> *r = new Node<T1>(rt);
            y =0;
            root = r;
            lay --;
            binary(root, lay);
        };

        void binary(Node<T1> *n, int lay){
            if(lay > 0){
                Node<T1> *l = new Node<T1>(false);
                n -> left = l;
                l -> parent = n;

                Node<T1> *r = new Node<T1>(true);
                n -> right = r;
                r -> parent = n;
            
                binary(l, lay - 1);
                binary(r, lay - 1);
            }
        };

        void combo(Node<T1> *r, int lay){
            if(lay > 0){
                combo(r -> left, lay - 1);
                combo(r -> right, lay - 1);

                if(lay == 1){
                    cout << "L = " << r -> left -> value << r -> value;
                    cout << r -> parent -> value << endl;

                    arr[y] = r -> left -> value;
                    y++;
                    arr[y] = r -> value;
                    y++;
                    arr[y] = r -> parent -> value;
                    y++;
                    
                    
                    cout << "R = " << r -> right -> value << r -> value;
                    cout << r -> parent -> value << endl;  

                    arr[y] = r -> right -> value;
                    y++;
                    arr[y] = r -> value;
                    y++;
                    arr[y] = r -> parent -> value;
                    y++;
                }
            }
        };
};

int main(){
    Stack<char> stk;
    string ss = "xy-^x-z^vz-v";
    int len = ss.length();
    char ary[len];
    strcpy(ary, ss.c_str()); 
    
    Tree<bool> f(3,0); // root = 0
    Tree<bool> t(3,1); // root = 1

    cout << endl;
    cout << "All combination of x,y,z:" << endl << endl;

    int layer = 2;
    bool bl[30];
    int count = 0;
    
    Node<bool> *r = f.root;
    if(layer > 0){
        f.combo(r -> left, layer - 1);
        f.combo(r -> right, layer - 1);
    }

    for(int i = 0; i < f.y; i++){
        bl[count] = f.arr[i];
        count ++;
    }

    Node<bool> *z = t.root;
    if(layer > 0){
        t.combo(z -> left, layer - 1);
        t.combo(z -> right, layer - 1);
    }
    for(int i = 0; i < t.y; i++){ //bl = all possible combination of x, y, z in an array
        bl[count] = t.arr[i];
        count ++;
    }
    
    bool bool_a, bool_b, bool_c;
    for(int j = 0; j < count; j++){
        bool_a = bl[j];
        j++;
        bool_b = bl[j];
        j++;
        bool_c = bl[j];
        
        for(int i = 0; i < len; i++){
            Node<char> *n = new Node<char>(ary[i]);
            if(ary[i] == 'v' || ary[i] == '^'){
                Node<char> *r = stk.head;
                Node<char> *l = stk.head ->next;

                n -> right = r;
                stk.pop();
                n -> left =  l;
                stk.pop();

                stk.eva(n);
                stk.push(n);
            }
            else{
                stk.push(n);
                switch (n -> value){
                case 'x':
                    n -> result = bool_a;
                    break;
                case 'y':
                    n -> result = bool_b;
                    break;
                case 'z':
                    n -> result = bool_c;
                    break;
                case '-':
                    n -> result = !n -> right -> result;
                    break;
                
                default:
                    break;
                }
            }

            if(i == len - 1){
                if(n -> result == 1){
                    cout << "Right combination: " << endl;
                    cout << bool_a << bool_b << bool_c << endl;

                    if(bool_c == bl[count+2]){
                        cout << "Inorder: " << endl;
                        ExpressionTree<char> eg(n,len);
                        cout << endl;
                    }
                }
            }
        }
    }
}