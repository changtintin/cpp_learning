#include <iostream>
#include <stdio.h>      
#include <math.h> 
#include <iomanip>
#include <cstring>
#include <string>
using namespace std;

class Tree;

class TreeNode{
    friend class Tree;
    private:
        char data;
        TreeNode *left;
        TreeNode *right;
        TreeNode *parent;
    public:
        TreeNode(char v);
};

TreeNode::TreeNode(char v){
    left = NULL;
    right = NULL;
    parent = NULL;
    data = v;
}

class Tree{
    public:
        TreeNode *root;
        char idx; // index of data
        int tmp;
        int ptr;
        bool rl; // right or left
    public:
        Tree(); 

    public:
        void FullBiTree(int l); // l = num of layers
        void AddTree(TreeNode *r, int l); 

        void Inorder(TreeNode *cur); //LVR
        void Preorder(TreeNode *cur); //VLR
        void Postorder(TreeNode *cur); // LRV

        void ShowNode(TreeNode *n);
        void CopyTree(TreeNode *r); // constructer
        void CopyNode(TreeNode *r, TreeNode *n);
};

Tree::Tree(){
    idx = 65; 
}

void Tree::Inorder(TreeNode *cur){
    if(cur != NULL){
        Inorder(cur -> left);
        cout << cur -> data << " ";
        Inorder(cur -> right);
    }
}

void Tree::Preorder(TreeNode *cur){
    if(cur != NULL){
        cout << cur -> data << " ";
        Preorder(cur -> left);
        Preorder(cur -> right);
    }
}

void Tree::Postorder(TreeNode *cur){
    if(cur != NULL){
        Postorder(cur -> left);
        Postorder(cur -> right);
        cout << cur -> data << " ";
    }
}

void Tree::FullBiTree(int l){
    l--;
    TreeNode *n = new TreeNode(idx);
    root = n;
    idx++;
    AddTree(root, l-1 );
}

void Tree::AddTree(TreeNode *r, int l){
    TreeNode *n = new TreeNode(idx);
    r -> left  = n;
    n -> parent = r;
    idx ++;
    
    TreeNode *m = new TreeNode(idx);
    r -> right  = m;
    m -> parent = r;
    idx ++;

    ShowNode(r);

    if(l != 0){
        AddTree(n, (l-1));
        AddTree(m, (l-1));
    }
}

void Tree::ShowNode(TreeNode *n){
    cout << n -> data << endl;
    cout << "(L)" << " -> " << n -> left -> data << endl;
    cout << "(R)" << " -> " << n -> right -> data << endl;
    cout << endl;
};

void Tree::CopyTree(TreeNode *r){
    TreeNode *a = new TreeNode(r -> data);
    root = a;
    CopyNode(r, root);
}

void Tree::CopyNode(TreeNode *r, TreeNode *n){ 
    TreeNode *lt = new TreeNode(r -> left -> data);
    n -> left = lt;
    lt -> parent = n;
       
    TreeNode *rt = new TreeNode(r -> right -> data);
    n -> right = rt;
    rt -> parent = n;
    
    ShowNode(n);

    if(r -> left -> left != NULL){
        CopyNode(r -> left,  lt);
        CopyNode(r -> right,  rt);
    }
}


class Stack {
    public:
        char *OptStk;
        int o;
        char *PostStk;
        int p;
        char *InStk;
        int l;
        char ary[50];

    public:
        Stack(string input);

    public:
        void pop(char c);
        void type(char c);
        int optr_order(char c); // whether it's greater than last one
        void optr_push(char c);
        void symbl_push(char c);
       
};

Stack::Stack(string input){
    o = 0;
    p = 0;

    l = input.length();
    char in[l];
    char op[l];
    char ptk[l];

    OptStk = op;
    PostStk = ptk;

    strcpy(in, input.c_str());
    InStk = in;
    for(int i = 0; i < l; i++){ // traverse every element in InStk
        cout << "i= " << i << endl;
        cout << InStk[i] << endl;
        type(InStk[i]);
        cout << "__________" << endl;
        cout << endl; 

        if(i == l - 1){
            for(int i = o - 1 ; i >= 0; i--){
                PostStk[p] =  OptStk[i];
                p++;
            }
        }
    }
    int a = l - 1;
    for(int i = 0; i < p; i++){
        ary[a] = PostStk[i];
        cout << PostStk[i];
        a--;
    }
    cout << endl;
}

void Stack::type(char c){
    switch (c){
        case '(': case ')': 
        case '-': case '^': case 'v': // compare the order
            optr_push(c);
            break;

        default:
            symbl_push(c); // push to PostStk
            break;
    }
}

void Stack::optr_push(char c){
    switch (c){
        // push all of optr into PostStk
        case ')': 
            cout << ") optr: " << endl;
            for(int i = o - 1; i >= 0; i--){
                PostStk[p] =  OptStk[i];
                cout << PostStk[p] << endl;
                p++;
            }
            o = 0;
            break;

        case '^': case 'v': case '-':
            if(optr_order(c) < optr_order(OptStk[o - 1]) || o == 0){ 
                /*
                    order of input(c) optr is greater(num smaller) 
                    than the last one in OptStk (OptStk[o-1]) -> push c into OptStk
                */
                cout << "c = " << c << endl;
                cout << "old = " << OptStk[o - 1] << endl;
                OptStk[o] = c;
                o++;
            }
            else{
                /*
                    order of input(c) optr isn't greater(include equal) than the last one in OptStk,
                    push OptStk[o] into PostStk and inspect Optstk[o-1] until 
                    order of OptStk[o] is less than input(c)
                */
                cout << "o = "<< o << endl;
                while(optr_order(c) > optr_order(OptStk[o - 1])|| optr_order(c) == optr_order(OptStk[o - 1])){
                    o--;
                    cout << "o = "<< o << endl;
                    cout << "c = " << c << endl;
                    cout << "old = " << OptStk[o] << endl;
                    PostStk[p] = OptStk[o];
                    p++;
                    if(o == 0)
                        break;
                }
                OptStk[o] = c;
                cout << "o = "<< o << endl;
                cout << "save: " << OptStk[o] << endl;
                o++;
            }
            break;

        default:
            break;
    }
}

int Stack::optr_order(char c){
    switch (c){
        case '-':
            return 1;
        case '^':
            return 2;
        case 'v':
            return 3;
        default:
            return 0;
    }
}
 
void Stack::symbl_push(char c){
    cout << "symbol push" << endl;
    PostStk[p] = c;
    p++;
}

int main(){
    // Tree t;
    // t.FullBiTree(4);
    // cout << endl;
    
    // ex.Inorder(ex.root);
    // cout << endl;
    // ex.Preorder(ex.root);
    // cout << endl;
    // ex.Postorder(ex.root);
    // cout << endl;

    // Tree nn;
    // nn.CopyTree(t.root);

    // Tree f;
    // f.FullBiTree(5);
    // cout << endl;

    // string str = "(x^-y)v(-x^z)v-z";
    // Stack post(str);

    // string ss = "(x^-zvy)v-yv(-y^z)";
    // Stack pt(ss);

    string sr = "(z^-x)v-yv(xvzv-y)";
    Stack p(sr);
    
    // cout << "in main: ";
    
    // for(int i = 0; i < p.l; i++) {
        
    //     cout << p.ary[i];
    // }
    // cout << endl;
    
    char pary[]={'v','-','z','v','^','z','-','x','^','-','y','x'};
    
    char ppary[]={'v','^','z','-','y','v','-','y','v','y','^','-','z','x'};
    
}