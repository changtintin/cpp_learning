#include <iostream>
using namespace std;

class Node {
    public:
        int value;
        Node *l;
        Node *r;
    public:
        Node(int v);
};

Node::Node(int v) {
    value = v;
    l = NULL;
    r = NULL;
}

class Tree {
    public:
        Node *head;
        int value;
    public:
        Tree(int level);
    public:
        void show();
    private:
        void recursive_create(Node* parent, int level);
        void recursive_show(Node *n);
};

Tree::Tree(int level) {
    value = 1;

    head = new Node(value);
    value ++;

    recursive_create(head, level - 1);
}

void Tree::recursive_create(Node* parent, int level) {
    if(level == 0) return;

    Node *n1 = new Node(value);
    value ++;
    Node *n2 = new Node(value);
    value ++;

    parent -> l = n1;
    parent -> r = n2;

    recursive_create(n1, level - 1);
    recursive_create(n2, level - 1);
}

void Tree::show() {
    recursive_show(head);
}

void :: Tree::recursive_show(Node *n) {
    cout << "now: " << (n -> value) << endl;
    if(n -> l != NULL)
        cout << (n -> value) << " -> l: " << (n -> l -> value) << endl;
    else
        cout << (n -> value) << " -> r: " << "x" << endl;

    if(n -> r != NULL)
        cout << (n -> value) << " -> r: " << (n -> r -> value) << endl;
    else
        cout << (n -> value) << " -> l: " << "x" << endl;


    if(n -> l != NULL)
        recursive_show(n -> l);
    if(n -> r != NULL)
        recursive_show(n -> r);
}

int main(void) {
    cout << "--------------------" << endl;
    Tree t1(1);
    t1.show();
    cout << "--------------------" << endl;
    Tree t2(2);
    t2.show();
    cout << "--------------------" << endl;
    Tree t3(3);
    t3.show();
    cout << "--------------------" << endl;
    Tree t4(4);
    t4.show();
    cout << "--------------------" << endl;
    Tree t5(5);
    t5.show();
    cout << "--------------------" << endl;
}