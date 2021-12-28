#include <iostream>
using namespace std;

template <class T>
class Stack {
    public:
        T index;
        T arr[5];
    
    public:
        Stack();

    public:
        void push(T v);
        void push(T ary[], int len);
        void pop();
        void clear();
        void show();
};

template <class T>
Stack<T>::Stack() {
    index = 0;

    for(int i = 0; i < 5; i++) {
        arr[i] = 0;
    }
}

template <class T>
void Stack<T>::push(T v) {
    if(index == 5) {
        cout << "Unable to push value " << v << ", stack is full." << endl;
        return;
    }

    arr[index] = v;
    index += 1;
}

template <class T>
void Stack<T>::push(T ary[], int len) {
    for(int i = 0; i < len; i++) {
        if(index == 5) {
            cout << "Unable to push value " << ary[i] << ", stack is full." << endl;
            continue;
        }

        arr[index] = ary[i];
        index += 1;
    }
}

template <class T>
void Stack<T>::pop() {
    if(index == 0) {
        cout << "The stack is now empty." << endl;
        return;
    }

    index -= 1;
}

template <class T>
void Stack<T>::clear() {
    index = 0;
}

template <class T>
void Stack<T>::show() {
    if(index == 0) {
        cout << "The stack is now empty." << endl;
        return;
    }
    
    for(int i = 0; i < index; i++) {
        string space = ((i == index - 1)? "": " ");
        cout << arr[i] << space;
    }
    cout << endl;
}

int main(void) {
    Stack<int> s;

    cout << "Case: 1" << endl;
    int a[] = {1, 2, 3, 9, 15};
    s.push(a, 5);
    s.show();

    cout << "Case: 2" << endl;
    s.pop();
    s.show();

    cout << "Case: 3" << endl;
    s.pop();
    // s.clear();
    s.show();

    cout << "Case: 4" << endl;
    s.push(9);
    int b[] = {3, 4, 2, 1, 5, 6, 7};
    s.push(b, 7);
    s.show();
}