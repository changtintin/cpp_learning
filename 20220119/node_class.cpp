#include <iostream>

class Node{
    public:
        int data;
        Node* next; //存放node物件的位址（等號的另一邊也是node*
    public:
        Node(int value);
};

Node::Node(int value){ //當物件被建立時要做的事情（初始化
    data = value;
    next = NULL;
};