#include <iostream>
#include <string>
using namespace std;

template <class T>
class Node {
    public:
        T value;
        Node<T> *next;
    public:
        Node(T v);
};

template <class T>
Node<T>::Node(T v) {
    value = v;
    next = NULL;
};

template <class T>
class Stack {
    public:
        int max_size;
        int now_size;
        Node<T> *head;
    public:
        Stack();
        Stack(int s);
    public:
        bool is_full();
        bool is_empty();
        void add(T item);
        void remove(T item);
        void show();
};

template <class T>
Stack<T>::Stack() {
    max_size = 5;
    now_size = 0;
    head = NULL;
};

template <class T>
bool Stack<T>::is_full() {
    if(now_size == max_size)
        return true;
    else
        return false;
};

template <class T>
bool Stack<T>::is_empty() {
    if(now_size == 0)
        return true;
    else
        return false;
};

template <class T>
Stack<T>::Stack(int s) {
    max_size = s;
    now_size = 0;
    head = NULL;
};

template <class T>
void Stack<T>::add(T item) {
    if(is_full()) {
        cout << "This stack is full." << endl;
        return;
    }

    Node<T> *n = new Node<T>(item);
    if(head == NULL)
        head = n;
    else {
        Node<T> *tmp = head;
        while((tmp -> next) != NULL) {
            tmp = tmp -> next;
        }
        tmp -> next = n;
    }
    now_size += 1;
};

template <class T>
void Stack<T>::remove(T item) {
    if(is_empty()) {
        cout << "Stack is now empty." << endl;
        return;
    }

    if(head -> value == item) {
        if(head -> next == NULL) {
            free(head);
            head = NULL;
        }
        else {
            Node<T> *new_head = head -> next;
            free(head);
            head = new_head;
        }
    }
    else {
        Node<T> *n = head;
        while(n -> next -> value != item) {
            n = n -> next;
        }

        if(n -> next -> next == NULL) {
            free(n -> next);
            n -> next = NULL;
        }
        else {
            Node<T> *tmp = n -> next -> next;
            free(n -> next);
            n -> next = tmp;
        }
    }

    now_size -= 1;
};

template <class T>
void Stack<T>::show() {
    if(is_empty()) {
        cout << "Stack is now empty." << endl;
        return;
    }

    Node<T> *n = head;
    while(n != NULL) {
        cout << (n -> value) << " ";
        n = n -> next;
    }
    cout << endl;
}

int main(void) {
    Stack<int> stack;
    stack.add(3);
    stack.add(4);
    stack.add(5);
    stack.show();

    stack.add(6);
    stack.add(7);
    stack.add(8);

    stack.remove(4);
    stack.show();

    stack.add(9);
    stack.show();
}