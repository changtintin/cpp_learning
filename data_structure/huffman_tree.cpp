#include <iostream>
#include <iterator>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
class Node{
    public:
        Node *left;
        Node *right;
        Node *next;
        Node *last;
        int val;
        char itm;
    public:
        Node(char c, int v);
};

Node::Node(char c, int v){
    itm = c;
    val = v;
    left = nullptr;
    right = nullptr;
}

class ConstructList{
    public:
        Node *root;
        map<char, int> m;

    public: 
       ConstructList();

    public:
        void HuffNode();
};

ConstructList::ConstructList(){
    root  = nullptr;
}

void ConstructList::HuffNode(){
    for(auto i = m.begin();i != m.end(); i++){
        Node *nd = new Node(i -> first, i -> second);
        if(i == m.begin()){
            root = nd;
        }
        else{
            if(nd -> val <= root -> val){
                nd -> next = root;
                root -> last = nd;
                root  = nd;
            }
            else{
                Node *tmp = root;
                while(tmp -> next != nullptr){
                    if(nd -> val > tmp -> next -> val)
                        tmp = tmp -> next;
                    else
                        break;
                }
                nd -> last = tmp;
                if(tmp->next!=nullptr)
                    tmp -> next -> last = nd;
                nd -> next = tmp -> next;
                tmp -> next = nd;
            }
        }
    }
}

class HuffmanTree{
    public:
        Node *root;
        ConstructList cons;

        //char -> code 
        //e.g. e -> 10
        map<char, string> table;

    public: 
       HuffmanTree(ConstructList c);

    public:
       void ShowTree(Node *r);
       void Encode(Node *r, string str);
       void ShowHuffCode(char *arr, int size);
};

HuffmanTree::HuffmanTree(ConstructList c){
    cons = c;
    while(cons.root -> next != nullptr){
        // # = tree node
        Node *nd = new Node('#',(cons.root -> val + cons.root -> next -> val)); 
        //value of right node is greater than  the one at the left
        if(cons.root -> val > cons.root -> next -> val){
            nd ->left = cons.root -> next;
            nd -> right = cons.root;
        }
        else{
            nd -> left = cons.root;
            nd -> right = cons.root -> next;
        }
        
        if(cons.root -> next ->next == nullptr){
            root  = nd;
            break;
        }
        else{
            cons.root = cons.root -> next -> next;
        }

        Node *tp = cons.root;
        while(tp != nullptr){
            // insert to the right position in order (ascending)
            if(tp -> val > nd -> val){ 
                nd -> next = tp;
                tp -> last -> next = nd;
                nd -> last = tp -> last;
                tp -> last = nd;
                break;
            }
            else if(tp -> next == nullptr){
                tp -> next = nd;
                nd -> last = tp;
                break;
            }
            tp = tp ->next;
        }
    }
}

void HuffmanTree::ShowTree(Node *r){
    if(r != nullptr){
        ShowTree(r -> left);
        cout << r -> itm << ", " << r -> val;
        cout << endl;
        ShowTree(r -> right);
    }
}

void HuffmanTree::Encode(Node *r, string str){
    if (!r)
        return;
 
    if (r -> itm != '#'){
        cout << r -> itm << ": " << str << "\n";
        table.insert({r -> itm, str});
    }
 
    Encode(r -> left, str + "0");
    Encode(r -> right, str + "1");
}

void HuffmanTree::ShowHuffCode(char *arr, int size){
    int bit = 0;
    for(int i = 0; i < size; i++){
        auto j = table.find(arr[i]);
        bit += (j -> second).length();
        cout << j -> second ;
    }
    cout << endl;
    cout << "Huffman code use " << bit << " bits." << endl;
}

int main(){
    ifstream fin("huftext.txt",ios::in);
    string str;
    getline(fin, str);
    cout << str << endl;
    char* chary = new char[str.length()];
    chary = (char *)str.data();

    map<char, int> input_tb;
    for(int i = 0; i < str.length(); i++)
        input_tb[chary[i]]++;
    
    for(auto i = input_tb.begin(); i != input_tb.end(); i++)
        cout << i->first << " -> " << i -> second << endl;
    cout << endl;
    ConstructList ct;
    ct.m = input_tb;
    ct.HuffNode();
    Node *t = ct.root;

    HuffmanTree h(ct);
    cout << "*******************" << endl;
    // h.ShowTree(h.root);
    h.Encode(h.root,"");
    cout << "*******************" << endl;
    
    for(auto i = h.table.begin(); i != h.table.end(); i++){
        cout << i -> first << " -> " << i -> second << endl;
    }
    
    h.ShowHuffCode(chary, str.length());
    cout << "ASCII use " << str.length() * 8 << " bits."<< endl;
}