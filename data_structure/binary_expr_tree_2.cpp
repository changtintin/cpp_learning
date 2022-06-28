#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <stdio.h>     
#include <math.h>       
using namespace std;
template <class T1, class T2>
class Node{
    public:
        T1 itm; // for symbol
        T2 val; // for evaluation
        Node<T1,T2> *left;
        Node<T1,T2> *right;
        Node<T1,T2> *parent;
        Node<T1,T2> *next;

    public:
        Node(T1 m);
};

template <class T1, class T2>
Node<T1,T2>::Node(T1 m){
    itm = m;
    next = NULL; // point to next element in stack
    left = NULL;
    right = NULL;
}

template <class T1, class T2>
class Stack{
    public:
        Node<T1,T2> *head; // top of the stack
    public:
        Stack();
    public:
        Node<T1,T2> *tree_stk(char *post, int leng); // return the root of tree
        void push(Node<T1,T2> *n);
        void pop();
        void bool_push(Node<T1,T2> *n);
        void bool_pop();
};

template <class T1, class T2>
Node<T1,T2> * Stack<T1,T2>::tree_stk(char *post, int leng){
    for(int i = 0; i < leng; i++){
        Node<T1,T2> *n = new Node<T1, T2>(post[i]);
        if(n -> itm == '^' || n -> itm == 'v'){
            push(n);
            if(i == leng - 1)
                return head;
        }
        else{
            push(n);
        }
    }
    return 0;
}

template <class T1, class T2>
void Stack<T1,T2>::push(Node<T1,T2> *n){
    if(head == NULL){
        head = n;
    }
    else{
        switch (n -> itm){
            case 'v': case '^':
                n -> right = head;
                n -> left = head -> next;
                pop();
                pop();
                n -> right -> parent = n;
                n-> left -> parent = n;

                n -> next = head;
                head = n;
                break;

            case '-':
                n -> right = head;
                n -> right -> parent = n;
                n -> next = head -> next;
                head = n;
                break;

            default:
                n -> next = head;
                head = n;
                break;
        }
    }
}

template <class T1, class T2>
void Stack<T1,T2>::pop(){
    head  =  head -> next;
}

template <class T1, class T2>
void Stack<T1,T2>::bool_push(Node<T1,T2> *n){
    cout << "push:";
    Node<T1,T2> *tmp = new Node<T1,T2>(n -> itm);
    cout << tmp -> itm << endl;
    if(head == nullptr){
       head = tmp;
    }
    else{
        tmp -> next = head;
        head = tmp;
    }
}

template <class T1, class T2>
Stack<T1,T2>::Stack(){
    head = nullptr;
}

template <class T1, class T2>
class Tree{
    public:
        Node<T1,T2> *root;
    public:
        Tree();
    public:
        void evaluation(Node<T1,T2> *n, T2 *ary, T2 x, T2 y, T2 z); 
        void inorder(Node<T1,T2> *n);
};                                         

template <class T1, class T2>
Tree<T1,T2>::Tree(){
    root = nullptr;
}

template <class T1, class T2>
void Tree<T1,T2>::inorder(Node<T1,T2> *n){
    if(n != nullptr){
        inorder(n -> left);
        cout << n -> itm << " ";
        inorder(n -> right);
    }
}

template <class T1, class T2>
void Tree<T1,T2>::evaluation(Node<T1,T2> *n, T2 *ary, T2 a, T2 b, T2 c){
    if(n != nullptr){
        evaluation(n -> left, ary, a, b, c);
        evaluation(n -> right, ary, a, b, c);
        switch (n -> itm){
            case 'v':
                n -> val = n -> left -> val || n -> right -> val;
                break;
            case '^':
                n -> val = n -> left -> val && n -> right -> val;
                break;
            case '-':
                n -> val = !(n -> right -> val);
                break;
            case 'x':
                n -> val = a;
                break;
            case 'y':
                n -> val = b;
                break;
            case 'z':
                n -> val = c;
                break;
            default:
                break;
        }
        if(n == root && n -> val == true){
            cout << "(x, y, z) = " << a << b << c << endl;
            cout << endl;
        }
    }
}

template <class T1, class T2>
class BoolTree{
    public:
        Node<T1,T2> *root;
        T1 bool_arry[30];
        int idx;
    public:
        BoolTree();
    public:
        // num of variable and num of position for repetition permutation
        void combo(int v, int p); 
        void combo_recur(Node<T1,T2> *n, int lay);
        void traverse_leaf(Node<T1,T2> *n, int lay);
};  

template <class T1, class T2>
BoolTree<T1,T2>::BoolTree(){
    root = nullptr;
    idx = 0;
}

template <class T1, class T2>
void BoolTree<T1,T2>::combo(int v, int p){
    if(p > 0){
        Node<T1,T2> *n = new Node<T1,T2>(true);
        root = n;
        combo_recur(root, p - 1);
    }
}

template <class T1, class T2>
void BoolTree<T1,T2>::combo_recur(Node<T1,T2> *n, int lay){
    Node<T1,T2> *r = new Node<T1,T2>(true);
    Node<T1,T2> *l = new Node<T1,T2>(false);

    n -> right = r;
    n -> left = l;
    r -> parent = n;
    l -> parent = n;

    if(lay > 0){
        combo_recur(r, lay - 1);
        combo_recur(l, lay - 1);
    }
}

template <class T1, class T2>
void BoolTree<T1,T2>::traverse_leaf(Node<T1,T2> *n, int lay){
    if (lay > 0){
        traverse_leaf(n -> left, lay - 1);
        traverse_leaf(n -> right, lay - 1);
    }
    else if(lay == 0){
        while(n != root){
            bool_arry[idx] = n -> itm;
            n = n -> parent;
            idx ++;
        }
    }
}

int main(){
    string p = "xz-vy-^yxvvzy-v^";
    int leng = p.length();
    char post[leng];
    strcpy(post, p.c_str());

    Stack<char, bool> stk;
    Node<char, bool> *r = stk.tree_stk(post, leng);
    
    Tree<char, bool> tr;
    tr.root = r;
    tr.inorder(tr.root);
    cout << endl;
    
    BoolTree<bool, char> bol;
    int var = 2; // T/F
    int pos = 3;
    bol.combo(var, pos);
    bol.traverse_leaf(bol.root,pos);

    cout << "boolean array: " << endl;
    for(int i  = 0; i < bol.idx; i++){
        cout << bol.bool_arry[i];
    }
    cout << endl;

    bool a, b, c;
    for(int i = 0; i < bol.idx; i++){
        a = bol.bool_arry[i];
        b = bol.bool_arry[++i];
        c = bol.bool_arry[++i];

        tr.evaluation(tr.root, bol.bool_arry, a, b, c);
    }

    string h = " xy-^x-z^vz-v";
    int le = h.length();
    char po[le];
    strcpy(po, h.c_str());

    Stack<char, bool> sk;
    Node<char, bool> *rr = sk.tree_stk(po, le);
    
    Tree<char, bool> tre;
    tre.root = rr;
    tre.inorder(tre.root);
    cout << endl;
    
    for(int i = 0; i < bol.idx; i++){
        a = bol.bool_arry[i];
        b = bol.bool_arry[++i];
        c = bol.bool_arry[++i];

        tre.evaluation(tre.root, bol.bool_arry, a, b, c);
    }
}