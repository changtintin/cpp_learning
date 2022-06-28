#include <iostream>
#include <string>
using namespace std;
class Node{
    public:
        int val;
        int left_size;
        Node *l;
        Node *r;
        Node *parent;

    public:
        Node(int v);
};

Node::Node(int v){
    val = v;
    l = nullptr;
    r = nullptr;
    parent = nullptr;
}

class BinaryTree{
    public:
        Node *root;

    public:
        BinaryTree();

    public:
        void Inorder(Node *c); // LVR
        void Search(int num, Node *c);
        void Insert(int v);
        void Delete(int v, Node *c);

};

BinaryTree::BinaryTree(){
    root = nullptr;
}

void BinaryTree::Insert(int v){
    Node *n = new Node(v);
    if(root == nullptr){
        root = n;
    }
    else{
        Node *tmp = root;
        while (1){
            if(n -> val > tmp -> val){
                if(tmp -> r == nullptr){
                    tmp -> r = n;
                    n -> parent = tmp;
                    break;
                }
                else{
                    tmp = tmp -> r;
                }
            }
            else{
                if(tmp -> l == nullptr){
                    tmp -> l = n;
                    n -> parent = tmp;
                    break;
                }
                else{
                    tmp = tmp -> l;
                }
            }
        }
    }
    
}

void BinaryTree::Inorder(Node *c){
    if(c != nullptr){
        Inorder(c -> l);
        cout << c -> val << " " ;
        Inorder(c -> r);
    }
}

void BinaryTree::Search(int num, Node *c){
    if(c != nullptr){
        if(num == c -> val)
            cout << "Exist" << endl;
        else if (num < c -> val)
            Search(num, c -> l); 
        else
            Search(num, c -> r);
    }
    else{
        cout << "Number doesn't exist." << endl;
    }
}


/*
1. Find the selected value.
2. If 

*/

void BinaryTree::Delete(int v, Node *c){
    if (c != nullptr){
        if(v == c -> val){
            if(c -> r == nullptr || c -> l == nullptr){
                Node *n ;
                if(c -> l == nullptr){
                    cout << "r  or no child." << endl;
                    n = c -> r;
                } 
                else{
                    cout << "l" << endl;
                    n = c -> l ;
                }

                if(c == root)
                    root = n;
                else{
                    if(c == c -> parent -> r)
                        c -> parent -> r = n;
                    else
                        c -> parent -> l = n;
                }
                
                if(n != nullptr)
                    n -> parent = c -> parent;

                delete c;
                cout << "Deleted the selected value node." << endl;
            }
            else { 
                Node *tmp = c -> r;
                while(tmp -> l != nullptr){
                    tmp = tmp -> l;
                }
                Node *par = tmp -> parent;

                if(par != c)    
                    par -> l =  tmp -> r;
                else
                    c -> r = tmp -> r;
                
                c -> val = tmp -> val;
                delete tmp;
            }
        }
        else if(v < c -> val){
            Delete(v,c -> l); 
        }    
        else if(v > c -> val){
            Delete(v,c -> r); 
        }
    }
    else {
        cout << "The number doesn't exist." << endl;
    }
}

int main(){
    BinaryTree b;
    b.Insert(2);
    b.Insert(8);
    b.Insert(11);
    b.Insert(30);
    b.Insert(24);
    b.Insert(7);
    b.Insert(0);
    b.Insert(15);
    b.Insert(4);

    cout << "Inorder: " << endl;
    b.Inorder(b.root);
    cout << endl;
    b.Search(7, b.root);
    b.Search(100, b.root);

    b.Delete(24, b.root); 
    b.Delete(8, b.root); 
    b.Delete(7, b.root); 
    
    cout << "Inorder: " << endl;
    b.Inorder(b.root);

    // BinaryTree bb;
        
    // bb.Insert(6); 
    // bb.Insert(78); 
    // bb.Insert(21);
    // bb.Insert(26);
    // bb.Insert(92);
    // bb.Insert(5);  
    // bb.Insert(10); 

    // cout << "Inorder: " << endl;
    // bb.Inorder(bb.root);
    // cout <<  endl;

    // bb.Delete(10,bb.root);
    // bb.Delete(6,bb.root);

    // cout << "Inorder: " << endl;
    // bb.Inorder(bb.root);
    // cout <<  endl;
}