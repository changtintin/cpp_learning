#include<iostream>
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
        int size;
    public:
        Graph(int n); // n = number of vertex value
        Vertex *NewVertex(int n); 
        void AddEdge(int va, int vb);
        void AdjItm(Vertex *vt, Vertex *dv);
        Vertex *DFS(Vertex *vt);
};

Graph::Graph(int n){
    size = n;
    AdjList = new Vertex[size];
    rd = new bool[size];
    for(int i = 0; i < size; i++){
        AdjList[i].v = 0;
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
    AdjItm(nvb, nva);
}

Vertex *Graph::DFS(Vertex *vt){
   
    Vertex *tmp = new Vertex();
    tmp = &AdjList[vt -> v];
    while(rd[tmp -> v] == 1){
        tmp = tmp -> next;
    }
    rd[tmp -> v] = 1;
    cout << tmp -> v << " ";
    DFS(tmp -> next);
    
    return vt;
}

int main(){
    Graph g(8);
    g.AddEdge(0,1);
    g.AddEdge(0,2);
    g.AddEdge(1,3);
    g.AddEdge(1,4);
    g.AddEdge(2,5);
    g.AddEdge(2,6);
    g.AddEdge(3,7);
    g.AddEdge(4,7);
    g.AddEdge(5,7);
    g.AddEdge(6,7);

    for(int i = 0; i < g.size; i++){
        cout << i << ": ";
        Vertex *tmp = new Vertex();
        tmp = &g.AdjList[i];
        while(tmp != nullptr){
            cout << tmp -> v ;
            tmp = tmp -> next;
            if(tmp != nullptr)
                cout << " -> ";
        }
        cout << endl;
    }
    g.DFS(&g.AdjList[0]);
}
