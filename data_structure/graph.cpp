#include<iostream>
#include<stack>
#include<queue>          
using namespace std;
class Vertex{
    public:
        int v;
        Vertex *next;
    public:
        Vertex();
};

Vertex::Vertex(){
    next = nullptr;
}

class Graph{
    public:
        Vertex *AdjList;
        bool *rd;
        stack<int> stk;
        queue<int> que;
        int size;
    public:
        Graph(int n); // n = number of vertex value
        Vertex *NewVertex(int n); 
        void AddEdge(int va, int vb);
        void AdjItm(Vertex *vt, Vertex *dv);
        void DFS(Vertex *vt);
        void BFS(Vertex *vt);
};

Graph::Graph(int n){
    size = n;
    AdjList = new Vertex[size];
    rd = new bool[size];
    for(int i = 0; i < size; i++){
        AdjList[i].v = i;
        rd[i] = 0;
    }
}

Vertex *Graph::NewVertex(int n){
    Vertex *va = new Vertex();
    va -> v = n;
    va -> next = nullptr;
    return va;
}

void Graph::AdjItm(Vertex *vt, Vertex *dv){
    int n = vt -> v;
    Vertex *tmp = new Vertex();
    tmp = &AdjList[n];
    while(tmp -> next != nullptr){
        tmp = tmp -> next;
    }
    tmp -> next = dv;
}

void Graph::AddEdge(int a, int b){
    Vertex *nva = new Vertex();
    nva = NewVertex(a);

    Vertex *nvb = new Vertex();
    nvb = NewVertex(b);
    AdjItm(nva, nvb);
}

void Graph::DFS(Vertex *vt){
    Vertex *tmp = new Vertex();
    tmp = vt;
    while(rd[tmp -> v] == 1){
        tmp = tmp -> next;
        if(tmp==nullptr)
            break;
    }
   
    if(tmp != nullptr){ //push into stack
        stk.push(tmp -> v);
        rd[tmp -> v] = 1;

        cout << tmp -> v << " ";
        DFS(&AdjList[tmp -> v]);
    }
    else{ //pop from stack        
        stk.pop();      

        if(stk.empty() == 0){
            int n = stk.top();
            DFS(&AdjList[n]);
        }
        else{
            cout << endl;
            for(int i = 0; i < size; i++){ // Initialize rd[] to 0
                rd[i] = 0;
            }
        }            
    }    
}

void Graph::BFS(Vertex *vt){
    Vertex *tmp = new Vertex();
    tmp = vt;
    while(rd[tmp -> v] == 1){
        tmp = tmp -> next;
        if(tmp == nullptr)
            break;
    }
    
    if(tmp != nullptr){
        rd[tmp -> v] = 1;
        que.push(tmp -> v);
        cout << tmp -> v << " ";
        BFS(&AdjList[vt -> v]);
    }
    else if(que.empty() == 0){
        que.pop();
        if(que.empty() == 0){
            int n = que.front();
            BFS(&AdjList[n]);
        }
        else{
            cout << endl;
        }
    }
}

int main(){

    Graph gg(11);
    gg.AddEdge(0,3);
    gg.AddEdge(0,4);
    gg.AddEdge(0,8);

    gg.AddEdge(2,10);
    gg.AddEdge(3,1);
    gg.AddEdge(3,5);
    gg.AddEdge(3,7);
    gg.AddEdge(4,2);
    gg.AddEdge(7,6);
    gg.AddEdge(8,9);    

    for(int i = 0; i < gg.size; i++){
        Vertex *tmp = new Vertex();
        tmp = &gg.AdjList[i];
        while(tmp != nullptr){
            cout << tmp -> v ;
            tmp = tmp -> next;
            if(tmp != nullptr)
                cout << " -> ";
        }
        cout << endl;
    }

    cout << "DFS: ";
    gg.DFS(&gg.AdjList[3]);

    cout << "BFS: ";
    gg.BFS(&gg.AdjList[3]);

    Graph G(8);
    G.AddEdge(0,1);
    G.AddEdge(0,4);
    G.AddEdge(1,6);
    G.AddEdge(3,7);
    G.AddEdge(4,3);
    G.AddEdge(4,7);
    G.AddEdge(5,1);
    G.AddEdge(5,0);
    G.AddEdge(7,2);
      
    for(int i = 0; i < G.size; i++){
        Vertex *tmp = new Vertex();
        tmp = &G.AdjList[i];
        while(tmp != nullptr){
            cout << tmp -> v ;
            tmp = tmp -> next;
            if(tmp != nullptr)
                cout << " -> ";
        }
        cout << endl;
    }

    cout << "DFS: ";
    G.DFS(&G.AdjList[0]);

    cout << "BFS: ";
    G.BFS(&G.AdjList[0]);
}
