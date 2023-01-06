#include<iostream>
#include<stack>

using namespace std;
class Node{
    public:
        int value;
        Node* next;
    public:
        Node(int v);
};

Node::Node(int v){
    value = v;
    next = nullptr;
}

class List{
    public:
        Node *h;
    public:
        List();
    public:
        void AddNode(int v);
        void ShowList();
};

List::List(){
    h = nullptr;
}

void List::AddNode(int v){
    Node *n = new Node(v);
    Node *tmp = h;
    if(h == nullptr){
        h = n;
    }
    else{
        while(tmp -> next != nullptr){
            tmp = tmp -> next;
        }
        tmp -> next = n;
    }
}

void List::ShowList(){
    Node *tmp = h;
    while(tmp -> next != nullptr){
        cout << tmp->value << " ";
        tmp = tmp -> next;
    }
    cout << tmp->value;
    cout << endl;
}

class Graph{
    public:
        stack<int> route;
        Node **head;
        bool *visited;
        int idx;
        int size;

    public:
        Graph(int s);
    public:
        void AddHeadNode(List l); 
        void ShowHead();
        void DFS(int n);
};

Graph::Graph(int s){
    idx = 1;
    size = s + 1;
    head = new Node* [size];
    visited = new bool[size];
    for(int i = 0; i < size; i++){
        visited[i] = false;
    }
}
void Graph::AddHeadNode(List l){
    if(idx < size){
        head[idx] = l.h;
        idx++;
    }
}

void Graph::ShowHead(){
    for(int i = 1; i < idx; i++){
        cout << head[i] -> value << " ";
    }
    cout << endl;
}

void Graph::DFS(int n){ 
    Node *tmp = head[n];
    if(!visited[n]){
        visited[n] = 1;
        cout << n << " ";
    }

    while(tmp != nullptr){
        if(!visited[tmp -> value]){
            route.push(n);
            cout << tmp -> value << " ";
            visited[tmp -> value] = 1;
            break;
        }
        tmp = tmp -> next;
    }
    if(tmp == nullptr){
        if(!route.empty()){
            int num = route.top();
            route.pop();
            DFS(num);
        }
    }
    else{
       DFS(tmp -> value);
    }
}

int main(){
    Graph g(9);
    
    List l1;
    l1.AddNode(2);
    l1.AddNode(3);
    l1.ShowList();

    List l2;
    l2.AddNode(1);
    l2.AddNode(4);
    l2.AddNode(5);
    l2.ShowList();

    List l3;        
    l3.AddNode(1);
    l3.AddNode(6);
    l3.AddNode(7);
    l3.ShowList();
    
    List l4;        
    l4.AddNode(2);
    l4.AddNode(8);
    l4.ShowList();
    
    List l5;        
    l5.AddNode(2);
    l5.AddNode(8);
    l5.ShowList();
    
    List l6;        
    l6.AddNode(3);
    l6.AddNode(8);
    l6.ShowList();
    
    List l7;        
    l7.AddNode(3);
    l7.AddNode(8);
    l7.ShowList();
    
    List l8;        
    l8.AddNode(4);
    l8.AddNode(5);
    l8.AddNode(6);
    l8.AddNode(7);
    l8.ShowList();
    
    g.AddHeadNode(l1);
    g.AddHeadNode(l2);
    g.AddHeadNode(l3);
    g.AddHeadNode(l4);
    g.AddHeadNode(l5);
    g.AddHeadNode(l6);
    g.AddHeadNode(l7);
    g.AddHeadNode(l8);
    g.ShowHead();    

    g.DFS(1);
}