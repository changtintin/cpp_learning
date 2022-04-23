#include<iostream>
using namespace std;

template<class T>
class Node{
    // friend class Linked_list<T>;
    public:
        T num;
        Node<T> *next;
        Node<T> *last;
    
    public:
        Node(T val);
};

template<class T>
Node<T>::Node(T val){
    num = val;
    next = NULL;
    last = NULL;
}

template<class T>
class Linked_list{
    public:
        Node<T> *head;
        Node<T> *tail;
        int idx;

    public:
        Linked_list();

    public:
        bool empty();
        bool out_of_range(int ord);

        void push_last(T n);
        void push_front(T n);
        void pop_last();
        void pop_front();
        void pop_any(int ord);
        void push_any(int ord, T n);

        void invert(Node<T> **ref);
        void connect(Linked_list<T> b);
        void show_all();
};

template<class T>
Linked_list<T>::Linked_list(){
    idx = 0;
    head = NULL;
    tail = NULL;
}

template<class T>
bool Linked_list<T>::empty(){
    if(idx > 0)
        return false;
    else
        return true;
}

template<class T>
void Linked_list<T>::push_last(T n){
    Node<T> *n_nd = new Node<T>(n);
    if(empty() == false){
        tail -> next = n_nd;
        n_nd -> last = tail;
        tail = n_nd;
    }
    else 
        head = n_nd;
    tail = n_nd;
    n_nd -> next = NULL;
    idx ++;
}

template<class T>
void Linked_list<T>::push_front(T n){
    Node<T> *nd = new Node<T>(n);
    if(empty() == false){
        head -> last = nd;
        nd -> next = head;
        head = nd;
    }
    else {
        head = nd;
        head -> next = NULL;
    }
    idx ++;
}

template<class T>
void Linked_list<T>::show_all(){
    if(empty() == true)
        cout << "Nothing to show!" << endl;
    else{
        Node<T> *tmp = head;
        while(tmp != NULL){ 
            cout << tmp -> num;
            tmp = tmp -> next;
            if(tmp != NULL)
                cout << ", ";
        }
        cout << endl;
    }
}

template<class T>
bool Linked_list<T>::out_of_range(int ord){
    if(ord > idx || ord < 0){
        cout << "Out of range." << endl;
        return true;
    }
    else
        return false;
}

template<class T>
void Linked_list<T>::pop_front(){
    if(empty() == true)
        cout << "Nothing to pop!" << endl;
    else{
        Node<T> *tmp = head;
        delete head;
        head = tmp -> next;
        head -> last = NULL;
        idx --;
    }
}

template<class T>
void Linked_list<T>::pop_last(){
    if(empty() == true)
        cout << "Nothing to pop!" << endl;
    else{
        Node<T> *tmp = tail;
        delete tail;
        tail = tmp -> last;
        tail -> next = NULL;
        idx --;
    }
}

template<class T>
void Linked_list<T>::push_any(int order, T n){
    if(out_of_range(order)== false){
        if(order == 1)
            push_front(n);
        else if(order == idx)
            push_last(n);
        else{
            Node<T> *tmp = head;
            for(int i = 1; i < order - 1 ; i++){
                tmp = tmp -> next;
            }
            Node<T> *nd = new Node<T>(n);
            nd -> next = tmp -> next;
            tmp -> next -> last = nd;
            tmp -> next = nd;
            nd -> last = tmp;
        }
        idx ++;
    }
}

template<class T>
void Linked_list<T>::pop_any(int order){
    if(out_of_range(order)== false && empty()== false){
        if(order == 1)
            pop_front();
        else if(order == idx)
            pop_last();
        else{
            Node<T> *tmp = head;
            for(int i = 1; i < order; i++){
                tmp = tmp -> next;
            }
            Node<T> *cln = tmp;
            cln -> last -> next = cln -> next;
            cln -> next -> last = cln -> last;
            delete tmp;
        }
        idx --;
    }
    else if(empty()== true)
        cout << "Go fuck your self~" << endl;
}

template<class T>
void Linked_list<T>::invert(Node<T> **ref){
    Node<T> *temp = NULL;  
    Node<T> *current = *ref; //tmp
    tail = head;
    while (current != NULL){  
        temp = current -> last;  
        current -> last = current -> next;  
        current -> next = temp;              
        current = current -> last;  
    }
    if(temp != NULL )  
        *ref = temp -> last;      

    show_all();
}

template<class T>
void Linked_list<T>::connect(Linked_list<T> b){
    Node<T> *tmp_t = tail;
    Node<T> *tmp_h = b.head;
    delete b.head;
    tmp_t -> next = tmp_h;
    tmp_h -> last = tmp_t;
    tail = b.tail;
    show_all();
}


int main(){
    Linked_list<int> ll_a;
    ll_a.pop_any(2);
    ll_a.push_last(90);   
    ll_a.push_last(2);
    ll_a.push_last(5);
    ll_a.push_last(7);
    ll_a.push_last(345);
    ll_a.push_last(74);
    ll_a.push_last(-17);
    ll_a.push_last(22);

    ll_a.push_front(188);

    ll_a.push_last(223);
    ll_a.pop_any(4);

    ll_a.push_last(82);
    ll_a.push_last(2161);
    ll_a.push_last(-3);
    ll_a.push_any(7,600);

    ll_a.push_any(33,125);
    ll_a.show_all();

    ll_a.pop_any(13);
    ll_a.show_all();

    ll_a.pop_front();

    ll_a.show_all();
    ll_a.pop_last();
    ll_a.show_all();

    cout << "After inverting:  ";
    Node<int> **r = &(ll_a.head);
    ll_a.invert(r);
    cout << "head: " << ll_a.head->num << endl;
    cout << "tail: " << ll_a.tail->num << endl;
    // cout << "r: " << r << endl;
    // cout << "*r: " << *r << endl;
    // cout << "&r: " << &r << endl;

    // cout << "ll_a.head: " << ll_a.head << endl;
    // cout << "&ll_a.head: " << &(ll_a.head) << endl;
    Linked_list<int> ll_b;
    
    ll_b.push_last(25);   
    ll_b.push_last(7);   
    ll_b.push_last(11);   
    ll_b.push_last(412);   
    ll_b.push_last(9);   
    ll_b.push_last(34);   
    ll_b.push_last(70);   
    ll_b.push_last(145);   
    ll_b.push_last(2);   
    ll_b.show_all();

    ll_a.connect(ll_b); 
} 