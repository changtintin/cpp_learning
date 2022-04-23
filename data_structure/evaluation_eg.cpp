#include <iostream>
#include <string>
#include <map>
using namespace std;

template <class T>
class Node {
    public:
        T value;
        Node<T> *next;
        Node<T> *last;
    public:
        Node<T>(T value);
};

template <class T>
Node<T>::Node(T v) {
    value = v;
    next = NULL;
    last = NULL;
}

template <class T>
class Stack {
    public:
        Node<T> *head;
        Node<T> *tail;
    public:
        Stack<T>();
    public:
        void push(T v);
        void pop();
        void show();
};

template <class T>
Stack<T>::Stack() {
    head = NULL;
    tail = NULL;
}

template <class T>
void Stack<T>::push(T v)  {
    Node<T> *n = new Node<T>(v);
    if(head == NULL) {
        head = n;
        tail = n;
    }
    else {
        Node<T> *tmp = head;
        while(tmp -> next != NULL) {
            tmp = tmp -> next;
        }

        tmp -> next = n;
        n -> last = tmp;
        tail = tmp -> next;
    }
}

template <class T>
void Stack<T>::pop() {
    if(head == NULL) {
        return;
    }

    if(head -> next == NULL) {
        free(head);
        head = NULL;
        tail = NULL;
        return;
    }
    
    // todo list
    Node<T> *n = head;
    while(n -> next != tail) {
        n = n -> next;
    }

    free(n -> next);
    n -> next = NULL;
    tail = n;
}

template <class T>
void Stack<T>::show() {
    Node<T> *n = head;
    while(n != NULL) {
        cout << (n -> value) << " ";
        n = n -> next;
    }
    cout << endl;
}

int main(void) {
    string input = "";
    // input = "((1-2)*3+4*(5-6))/7-8+9";
    // input = "(1+2)*(3+4)-8";
    // input = "(4+5)*(6-2)/2+(4/2)-9";
    cin >> input;
    
    cout << "input: " << input << endl;

    Stack<char> sign;
    Stack<char> postfix;

    for(int i = 0; i < input.length(); i++) {
        char c = input.at(i);

        if('0' <= c && c <= '9') {
            postfix.push(c);
            continue;
        }

        if(c == '(') {
            sign.push(c);
            continue;
        }

        if(c == ')') {
            while(sign.tail != NULL && sign.tail -> value != '(') {
                postfix.push(sign.tail -> value);
                sign.pop();
            }
            sign.pop();

            continue;
        }

        map<char, int> priority = {
            {'(', 0},
            {'+', 1},
            {'-', 1},
            {'*', 2},
            {'/', 2},
            {'%', 2},
        };

        int last_priority = 0;
        if(sign.tail != NULL) {
            last_priority = priority.find(sign.tail -> value) -> second;
        }

        int now_priority = priority.find(c) -> second;

        if(now_priority > last_priority)
            sign.push(c);
        else {
            if(sign.tail != NULL) {
                postfix.push(sign.tail -> value);
            }
            sign.pop();
            sign.push(c);
        }
    }

    while(sign.head !=  NULL) {
        postfix.push(sign.tail -> value);
        sign.pop();
    }

    cout << "postfix: ";
    postfix.show();

    Stack<int> ans;
    Node<char> *postfix_pointer = postfix.head;

    while(postfix_pointer != NULL) {
        char v = postfix_pointer -> value;

        if('0' <= v && v <= '9') {
            ans.push(v - '0');
        }
        else {
            int front = ans.tail -> last -> value;
            int back = ans.tail -> value;
            int tmp_ans = 0;
            switch(v) {
                case '+':
                    tmp_ans = front + back;
                    break;
                case '-':
                    tmp_ans = front - back;
                    break;
                case '*':
                    tmp_ans = front * back;
                    break;
                case '/':
                    tmp_ans = front / back;
                    break;
            }

            ans.pop();
            ans.pop();
            ans.push(tmp_ans);
        }

        postfix_pointer = postfix_pointer -> next;
    }

    cout << "final answer:" << (ans.head -> value) << endl;
}