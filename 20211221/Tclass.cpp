#include <iostream>
#include <string>
using namespace std;

template <class T>
class stack {
    public:
        int index;
        T container[5];

    public:
        stack();
    
    public:
        void push(T value);
        void pop();
        void show();
};

template <class T>
stack<T>::stack() {
    // init
    for(int i = 0; i < 5; i++) {
        container[i] = 0;
        index = 0;
    }
    cout << "stack container is now created." << endl;
};

template <class T>
void stack<T>::push(T value) {
    if(index == 5) {
        cout << "Stack is full" << endl;
        return;
    }

    container[index] = value;
    cout << "value " << value << " is pushed in conatiner[" << index << "]\n";
    index ++;
};

template <class T>
void stack<T>::pop() {
    if(index == 0) {
        cout << "Stack is empty." << endl;
    }

    index -= 1;
    container[index] = 0;
    cout << "container[" << index << "] now is empty." << endl;   
};

template <class T>
void stack<T>::show() {
    if(index == 0) {
        cout << "Stack is empty." << endl;
    }
    for(int i = 0; i < index; i++) {
        cout << "container[" << i << "]: " << container[i] << endl;
    }
};

int main(void) {
    stack<int>   si;
    stack<float> sf;

    si.push(3);
    si.show();

    sf.push(7.5);
    sf.show();
}