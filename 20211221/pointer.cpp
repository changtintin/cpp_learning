#include <iostream>
#include <string>
using namespace std;

typedef struct node {
    int value;
    node* next_address;
} node;

int main(void) {
    node a, b;
    a.value = 1;
    a.next_address = &b;

    b.value = 3;
    cout << a.value << " " << a.next_address -> value << endl;
}