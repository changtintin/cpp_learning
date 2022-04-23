#include<iostream>
#include<string>
using namespace std;

template<class T>
class Node{
    public:
        T value;
        Node<T> *next;
        Node<T> *last;
    public:
        Node<T>();
};

template<class T>
Node<T>::Node(){
    next = NULL; //初始化很重要！！！！
    last = NULL;
}

template<class T>
class Stack{
    public: 
        int max_size;
        int present_size;
        Node<T> *head;
        Node<T> *tail;
    public:
        void add(T num);
        void del();
        void show();
        bool is_full();
        bool is_empty();
    public:
        Stack<T>(int item);
};

template<class T>
Stack<T>::Stack(int item){
    head = NULL; //初始化很重要！！！！
    max_size = item;
    present_size = 0;
}

template<class T>
void Stack<T>::add(T num){
    if(is_full() != true){
        Node<T> *add = new Node<T>();
        add -> value = num; 
        if(is_empty() == true){
            head = add;
            add -> last = NULL;
            add -> next = NULL;
        }
        else{
            Node<T> *tmp = head;
            while(tmp -> next != NULL){
                tmp = tmp -> next;
            }
            tmp -> next = add;
            add -> last = tmp;
        }
        tail = add;
        present_size ++;
    }
};

template<class T>
bool Stack<T>::is_full(){
    if(present_size == max_size && present_size != 0){
        cout << "The stack is full." << endl; 
        return true;
    }   
    else{
        return false;
    }
}

template<class T>
void Stack<T>::show(){
    Node<T> *n = head; 
    while(n != NULL) {
        cout << n -> value << endl;
        n = n -> next;
    }   
}
    
template<class T>
bool Stack<T>::is_empty(){
    if(present_size == 0){
        cout << "The stack is empty." << endl;
        return true;
    }     
    else{
        return false;
    }
}

template<class T>
void Stack<T>::del(){
    if(is_empty() != true){
        Node<T> *tmp = tail -> last;
        tmp -> next = NULL;
        delete(tail);
        tail = tmp;
    }
}


int main(){
    Stack<float> stk(7);
    stk.add(4.5);
    stk.add(2.3);
    stk.add(24.7);
    stk.add(9.1);
    stk.show();

    stk.add(29.5);
    stk.add(242.5);
    stk.add(9.5);
    stk.add(6.5);
    cout << "current size: " << stk.present_size << endl;
    cout << "tail: " << stk.tail -> value << endl;
    stk.del();
    stk.show();
}