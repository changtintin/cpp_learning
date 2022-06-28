#include <iostream>
using namespace std;

class Node {
    public:
        int value;
        Node *left;
        Node *right;
    public:
        Node(int v);
};

Node::Node(int v) {
    value = v;
    left = nullptr;
    right = nullptr;
}

class Tree {
    public:
        Node *root;
    public:
        Tree();
    public:
        void insert(int v);
        void search(int v);
};

Tree::Tree() {
    root = nullptr;
}

void Tree::insert(int v) {
    Node *n = new Node(v);

    if(root == nullptr) {
        root = n;
        return;
    }

    Node *tmp = root;
    while(true) {
        if(v < tmp -> value) {
            if(tmp -> left == nullptr) {
                tmp -> left = n;
                return;
            }
            else {
                tmp = tmp -> left;
            }
        }
        else {
            if(tmp -> right == nullptr) {
                tmp -> right = n;
                return;
            }
            else {
                tmp = tmp -> right;
            }
        }
    }
}

void Tree::search(int v) {
    Node *n = root;
    while(n != nullptr) {
        cout << (n->value) << endl;
        if(n -> value == v) {
            return;
        }

        if(v  < n -> value)
            n = n -> left;
        else
            n = n -> right;
    }
}

int main(void) {
    Tree t;
    t.insert(3);
    t.insert(31);
    t.insert(13);
    t.insert(7);
    t.insert(12);
    t.insert(5);
    t.insert(9);
    t.insert(16);
    t.insert(15);
    t.insert(8);
    t.insert(37);

    t.search(16);
}