#include <iostream>
#include <string>
using namespace std;

template<class T>
class Node{
    public:
        T value;
        Node<T> *next;
        Node<T> *last;
    public:
        Node();
};

template<class T>
Node<T>::Node(){
    next = NULL;
    last = NULL;
}

template<class T>
class Que{
    public:
        int max;
        int curr;
        Node<T> *head;
    public:
        Que<T>(int num);
    public:
        void push_back(T num);
        void push_front(T num);
        void show();
        void pop_back();
        void pop_front();
        bool full();
        bool empty();
};

template<class T>
Que<T>::Que(int num){
    head = NULL;
    max = num;
    curr = 0;
};

template<class T>
bool Que<T>::full(){
    if(curr == max && curr != 0){
        return true;
    }
    else{
        return false;
    }
}

template<class T>
bool Que<T>::empty(){
    if(curr == 0)
        return true;
    else
        return false;
}

template<class T>
void Que<T>::push_back(T num){
    if(full() == true){
        cout << "The queue is full." << endl;
    }
    else{
        if(empty() == true){
            Node<T> *tmp = new Node<T>();
            tmp -> value = num;
            head = tmp;
            tmp -> last = NULL;
            tmp -> next = NULL;
        }
        else{
            Node<T> *tmp = head;
            while(tmp -> next != NULL){
                tmp = tmp -> next;
            }
            Node<T> *new_node = new Node<T>();
            new_node -> value = num;
            tmp -> next = new_node;
            new_node -> last = tmp;
            new_node -> next = NULL;
        }
        curr ++;
    }
}

template<class T>
void Que<T>::push_front(T num){
    Node<T> *tmp = new Node<T>();
    tmp -> value = num;
    Node<T> *tt = head;
    tmp -> next = tt;
    tt -> last = tmp;
    head = tmp;
}

template<class T>
void Que<T>::show(){
    Node<T> *tmp = head;
    for(int i = 0; i < curr; i++){
        if(i == curr - 1){
            cout << tmp -> value << endl;
        }
        else{
            cout << tmp -> value << ", " ;
        }
        tmp = tmp -> next;
    }
}

template<class T>
void Que<T>::pop_back(){
    if(empty() != true){
        Node<T> *tmp = head;
        for(int i = 0; i < curr -1 ; i++){
            tmp = tmp -> next;
        }
        Node<T> *num = tmp -> last;
        delete (tmp);
        num -> next = NULL; 
        curr = curr - 1;
    }
}

template<class T>
void Que<T>::pop_front(){
    if(empty() != true){
        Node<T> *tmp = head -> next;
        head -> next = NULL;
        tmp -> last = NULL;
        delete (head);
        head = tmp;
        curr = curr - 1;
    }
}

int main() {
    Que<int> queue(5);
    queue.push_back(2);
    queue.push_back(6);
    queue.push_back(1);
    queue.show();
    queue.push_back(8);
    queue.show();
    queue.pop_back();
    queue.show();
    queue.push_back(4);
    queue.show();
    queue.push_back(34);
    
    cout << "________________________________" << endl;

    Que<float> qq(6);
    qq.push_back(3.3);
    qq.push_back(4.2);
    qq.push_back(3.1);
    qq.push_back(1.3);
    qq.push_back(6.2);
    qq.push_back(3.1);
    qq.push_front(7.9);
    qq.show();
    qq.pop_front();
    qq.show();
    cout << "curr: " << qq.curr << endl;

}