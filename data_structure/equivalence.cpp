#include<iostream>
#include<sstream>
#include<fstream>
using namespace std;
bool out[12];

class Node{
    public:
        int num;
        Node *next;
    public:
        Node();
};

Node::Node(){
    next = NULL;
}

Node seq[12];

class Stack{
    public:
        Node *head;
        int idx;
    public:
        Stack();
    public:
        void push(Node *n);
        void pop_all();
        void prt_stk();
        void inspect(Node *seq);
        void out_ary();
        int limit(Node *sq);
};

Stack::Stack(){
   head = NULL;
   idx = 0;
}

void Stack::push(Node *n){
    bool a;
    for(int i = 0; i < 12; i++){
        if(n == (seq + n -> num)){
            a = true;
        }
        else{
            a = false;
        }
    }
    if(head == NULL && a == false){ // don't push the index i of seq[i]
        Node *tmp = new Node();
        tmp -> num = n ->num ;
        tmp -> next = NULL;
        head = tmp;
    }
    else if(head != NULL && a == false){
        Node *tmp = head;
        while(tmp -> next != NULL){
            tmp = tmp -> next;
        }
        Node *nd = new Node();
        tmp -> next = nd;
        nd -> num = n -> num ;
        nd -> next = NULL;
    }
    idx ++;
}

void Stack::pop_all(){
    Node *tmp = head;
    while(tmp != NULL){
        Node *z = tmp ->next;
        delete tmp;
        tmp = z;
    }
    idx = 0;
}

void Stack::prt_stk(){
    Node *tmp = head;
    cout << "{ ";
    while(tmp != NULL){
        cout << tmp -> num;
        tmp = tmp -> next;
        if(tmp != NULL)
            cout << ", ";
    }
    cout << " } "<< endl;
}

int Stack::limit(Node *sq){
    for(int i = 0; i< 12; i++){
        if(sq == (seq + i) &&  out[i] == true){
            return true;
        }
        else if(out[sq -> num] == true){
            return true;
        }
    }
    return false;
}

void Stack::inspect(Node *sq){ 
    while(sq != NULL){
        if(limit(sq) == false){
            push(sq); 
        }
        sq = sq -> next;
    }
    out_ary();
}

void Stack::out_ary(){
    Node *tmp = head;
    while(tmp != NULL){
        out[tmp -> num] = true;
        tmp = tmp -> next; 
    }
}
/*
0,11
4,1
5,9
6,7
1,2
7,10
2,3
8,0
3,5
*/

int *read_record(int row){
    ifstream ifs;
    /*
    To solve the "address of stack memory associated with local variable {} returned"
    ***********************************
    method 1: global variable: always in the same memory location 
    (better used for the global variable)
    */
    static int ary[18]; 

    /* 
    method 2:
    Dynamic storage duration (Heap) :
    ************************************
    int *ary = NULL; 
    ary = new int[18]; 
    ************************************
    1. Usage:
        _ you want to have objects live on another isle, 
          put pointers around that reference them
        
        _ if your objects are big, and if you want to create arrays 
          of size only known at runtime. 

    2. Points:
        _ Because of this flexibility, 
          objects having dynamic storage duration are 
          complicated and slow to manage. 

        _ Every time when we made an object it always creates 
          in Heap-space and the referencing information to these objects 
          are always stored in Stack-memory. 

        _ Its lifetime ends only when you call delete for them. 
          If you forget that, those objects never end lifetime.    
    */
    string line, word;
    ifs.open("read_incsv.txt", ios::in);
    if(!ifs.is_open()){
        cout << "Failed" << endl;
    }
    else{
        int j =0;
        for(int i = 0; i < row; i++){
            /*
            Extracts characters from is and stores them into str 
            until the delimitation character delim is found 
            (or the newline character, '\n' is default)
            */
            getline(ifs,line); 
            /* 
            A stringstream associates a string object with a stream 
            allowing you to read from the string 
            as if it were a stream (like cin). 
            To use stringstream, we need to include sstream header file. 
            */
            stringstream s(line);  //Converting to stringstream object
            while(getline(s, word, ',')){
                // convert string to integer
                ary[j] = stoi(word); 
                j++;
            }
        }
    }
    return ary;
}

bool empty(Node *seq){
    if(seq -> next == NULL)
        return true;
    else
        return false;
}

int main(){
    int *rd;
    rd = read_record(9); // row = 9
    int rd_ary[18];
    for(int i = 0; i < 18; i++){
        rd_ary[i] = *(rd + i);
    }
  
    for(int i = 0; i < 12; i++){ //initialize array seq[], out[]
        out[i] = false;
        seq[i].num = 0;
        seq[i].next = NULL;
    }

    for(int i = 0; i < 18; i++){  //traverse rd_ary[0]-[17]
        for(int j = 0; j < 12; j++){ // index j of seq[j]
            if(rd_ary[i] == j){  
                Node *x = new Node();
                x -> num = rd_ary[i+1];
                x -> next = NULL;
                if(empty(seq+j)){ // if the list is empty
                    seq[j].next = x;
                } 
                else{
                    Node *tmp = seq[j].next; // seq[j] = value (not address)
                    seq[j].next = x;
                    x-> next = tmp;
                }
                int tp = rd_ary[i+1];
                Node *y = new Node();
                y -> num = rd_ary[i];
                y -> next = NULL;
                if(empty(seq+j)){ 
                    seq[tp].next = y;
                } 
                else{
                    Node *tmp = seq[tp].next; 
                    seq[tp].next = y;
                    y -> next = tmp;
                }
            }
        }
        i++; 
    }
    int s = 0;
    for(int i = 0; i < 12; i++){
        Stack stk;
        stk.inspect(seq + i);
        Node *tp = stk.head;
        while(tp != NULL){
            stk.inspect(seq + (tp->num));
            tp = tp -> next;
        }
        if(stk.idx > 0){
            s++;
            cout << "S" << s << " = ";
            stk.prt_stk();
            stk.pop_all();
        }
    }
}