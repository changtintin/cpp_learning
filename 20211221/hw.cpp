#include <iostream>
#include <string>
using namespace std;

template <class T>
class Queue{
    public:
        T arr[10];
        int index;
        
    public:
        Queue(T arr2[],int num);
        Queue();
    public:
        void show(string d);
        void pop_end(int b);
        void pop_front();
        void pop_front(int n);
        void push_end(T a);
        void push_end(T arry[], int c);
        void push_front(T e);
        void clear();
        void fill(T f);
        void empty();
    public:
        //void operator+(int array[]);
};

template<class T>
Queue<T>::Queue(T arr2[],int num){
    index = 0;
    for(int i = 0; i < num; i++){
        arr[i] = arr2[i];
        index++;
    }
};

template<class T>
Queue<T>::Queue(){
    for(int i = 0; i < 10; i++){
        arr[i] = 0;
    }
    index = 0;
};

template<class T>
void Queue<T>::show(string d){
    if(index == 0) {
        cout << d << " ";
        empty();
        return;
    }

    cout << d << " ";
    for(int i = 0; i < index; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
};

template<class T>
void Queue<T>::pop_front(){
    for(int i = 1; i < index; i++) {
        arr[i-1] = arr[i];
    }
    index --;
};

template<class T>
void Queue<T>::pop_front(int n) {
    for(int i = 1; i <= n; i++) {
        pop_front();
    }
};

template<class T>
void Queue<T>::push_end(T a){
   arr[index]= a;
   index ++;
};

template<class T>
void Queue<T>::push_end(T arry[], int c){
   for(int i = 0; i < c; i++) {
       arr[index] = arry[i];
       index++;
   }
};

template<class T>
void Queue<T>::empty(){
   cout << "The queue is empty." << endl;
};

template<class T>
void Queue<T>::pop_end(int b){
   if(index == 0){
       empty();
   } 
   index -= b;
   arr[index] = 0;
};

template<class T>
void Queue<T>::clear(){
    index = 0;
};

template<class T>
void Queue<T>::push_front(T e){
    if(index == 0){
       empty();
    } 
   index += e;
   for(int i = 0; i < e; i++){
        arr[i]= 0;
    }
};

template<class T>
void Queue<T>::fill(T f){
   for(int i = index; i < 10-index; i++){
       arr[i]= f;
   }
   index = 10;
};

template<class T>
void Queue<T>:: operator+(Queue<T> q) {
   push_end(q, )
};

int main(void) {
    int default_ary[] = {2, 5, 3, 4, 6, 1};
    Queue<int> i (default_ary, 6);
    Queue<float> f;

    // Case 1: 2 5 3 4 6 1
    i.show("Case 1: ");

    // Case 2: 5 3 4 6 1
    i.pop_front(); 
    i.show("Case 2: ");

    // Case 3: 5 3 4 6 1 8 7
    i.push_end(8);
    i.push_end(7);
    i.show("Case 3: ");

    // Case 4: 2.2 5.1 3.6 1.7 4.4
    float f_ary[] = {2.2, 5.1, 3.6, 1.7, 4.4};
    f.push_end(f_ary, 5);
    f.show("Case 4: ");

    // Case 5: 2.2 5.1 3.6 1.7 4.4 7.2
    f.push_end(7.2);
    f.show("Case 5: ");

    // Case 6: 2.2 5.1 3.6
    f.pop_end(3);
    f.show("Case 6: ");

    // Case 7: Queue is now empty.
    i.clear();
    i.show("Case 7: ");

    // Case 8: 3 4 5
    for(int n = 1; n <= 5; n++) {
        i.push_end(n);
    }
    i.pop_front(2);
    i.show("Case 8: ");

    // Case 9: 3 4 5 1 6 2 7
    Queue<int> ii;
    int ii_ary[] = {1, 6, 2, 7};
    ii.push_end(ii_ary, 4);
    //i = i + ii;
    //i.show("Case 9:");

    // Case 10: 2.2 5.1 3.6 1.7 4.4 7.2 1.3 1.3 1.3 1.3
    f.fill(1.3);
    f.show("Case 10:");
}