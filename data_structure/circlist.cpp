#include<iostream>
using namespace std;

template<class T>
class Node{
    public:
        T val;
        Node<T> *next;
        Node<T> *last;
        Node<T> *t_hd; // point to head
    public:
        Node(T v);
};

template<class T>
Node<T>::Node(T v){
    val = v;
    next = NULL;
    last = NULL;
}

template<class T>
class Cir_list{
    public: 
        Node<T> *head;
        Node<T> *tail;
        int idx;
    public:
        Cir_list();
        void add(T v);
        void prt();
        bool emp();
};

template<class T>
Cir_list<T>::Cir_list(){
    idx = 0;
    head = NULL;
    tail = NULL;
}

template<class T>
bool Cir_list<T>::emp(){
    if(idx == 0)
        return true;
    else
        return false;
}

template<class T>
void Cir_list<T>::add(T v){
    Node<T> *n_nd = new Node<T>(v);
    if(emp() == false){
        tail -> next = n_nd;
        n_nd -> last = tail;
    }
    else{
        head = n_nd;
    }
    tail = n_nd;
    tail -> t_hd = head;
    n_nd -> next = tail -> t_hd;
    idx ++;
}

template<class T>
void Cir_list<T>::prt(){
    Node<T> *tmp = head; 
    for(int i = 0; i < idx; i++){
        cout << tmp -> val;
        tmp = tmp -> next;
        if(i == idx - 1){
            cout << ", " << tail -> next -> val;
        }
        else{
            cout << ", ";
        }
    }
    cout << endl;
}

int main(){
    Cir_list<int> lt;

    lt.add(233);
    lt.add(12);
    lt.add(71);
    lt.add(43);
    lt.add(488);
    lt.add(13);
    lt.add(92);
    lt.add(38);

    lt.prt();
    // cout << lt.tail -> next -> val << endl; 
}