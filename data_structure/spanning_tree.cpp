#include <iostream>
#include <vector>
#include <algorithm>    // std::sort
#include <map>
using namespace std;
class E{
    public:
        int target;
        int dis;
    public:
        E(int t, int v);
};

E::E(int t, int v){
    target = t;
    dis = v;
}

class V {
    public: 
        int num;
        E *edge;
    public:
        V(int b, int d, int w);
};

V::V(int b, int d, int w) {
    num = b;
    E *tmp = new E(d, w);
    edge = tmp;
};

class Graph{
    public:
        vector<V> adj; // adjacent list
        vector<int> n; // tmp vector to store the numbers
        vector<V> t; // tmp vecctor to store the edges
        map<int, bool> vis; //visited list

    public:
        void Sort();
        void PrintBool();
        void PrintSpan();
        void NewEdge(int b, int d, int w);
        void KruskalSpan(int vn);
};
void Graph::Sort(){
    sort (n.begin(), n.end()); 
    
    for(int i = 0;  i  < n.size(); i ++){
        int num = n[i] ;
        if(n[i] != n[i - 1] || i == 0)
            vis.insert({num, false});

        for(int j = 0; j < t.size(); j++){
            if(t[j].num == n[i]){
                adj.push_back(t[j]);
                t.erase(t.begin() + j);
            }
        }
    }

    for(auto i = adj.cbegin(); i != adj.cend(); i++){
        cout << "[" << i -> num << "] -> ";
        cout << "[" << i -> edge -> target << "] = " << i -> edge -> dis ;
        cout << endl;
    }
    cout << endl;

    t.clear();
    n.clear();
    PrintBool();
} 

void Graph::PrintBool(){
    cout << "Bool Vector:" << endl;
    for(auto i = vis.cbegin(); i != vis.cend(); i++){
        cout << i -> first << " -> ";
        cout << i -> second << endl;
    }
    cout << endl;
}

void Graph::NewEdge(int b, int d, int w){
    V tmp = V(b, d, w);
    n.push_back(tmp.num);
    t.push_back(tmp);
}

void Graph::KruskalSpan(int vn){
    int tmp;
    int min = -1; // default minimum distance, dis != negative
    vis.find(vn) -> second = 1;
    // cout << "______________________________________________" << endl;
    
    n.push_back(vn);

    for(int i = 0; i < adj.size(); i++){
        if(vn == adj[i].num) {
            bool a = (adj[i].edge -> dis < min);
            bool b = (vis.find(adj[i].edge -> target) -> second == 0);
            bool c = (adj[i].edge -> dis != 0);

            if(min == -1){
                tmp = i;
                min = adj[i].edge -> dis;
            }
            else if(a && b && c) {
                tmp = i; // if the vertex has no edge, dis = -1, target = 0
                min = adj[i].edge -> dis;
            }
            // cout << "tmp = " << tmp << endl;
            // cout << "adj[i].edge -> dis = " << min << endl;
        }
    }

    for(int i = 0; i < adj.size(); i++){
        if(adj[i].num == adj[tmp].edge -> target && vis.find(adj[i].num) -> second == 0){
            KruskalSpan(adj[i].num);
        }
    }
}

void Graph::PrintSpan(){
    cout << "Spannning route: ";
    for(int i = 0; i < n.size(); i++){
        cout << n[i];
        if(i != n.size() - 1)
            cout << " -> ";
    }
    cout << endl;
}

int main(){
    // Graph G;
    // G.NewEdge(0, 1, 28);    
    // G.NewEdge(4, 6, 24);
    // G.NewEdge(3, 6, 18);
    // G.NewEdge(0, 5, 10);
    // G.NewEdge(4, 3, 22);
    // G.NewEdge(3, 2, 12);
    // G.NewEdge(1, 6, 14);
    // G.NewEdge(2, 1, 16);
    // G.NewEdge(5, 4, 25);
    // G.NewEdge(6, -1, 0);

    // G.Sort();
    // G.KruskalSpan(G.adj[0]);

    Graph R;
    R.NewEdge(0, 3, 16);    
    R.NewEdge(1, 0, 8);    
    R.NewEdge(1, 2, 20);    
    R.NewEdge(1, 4, 10);    
    R.NewEdge(2, 5, 12);    
    R.NewEdge(3, 2, 4);    
    R.NewEdge(3, 5, 30);    
    R.NewEdge(4, -1, 0);    
    R.NewEdge(4, 4, 7);    
    R.NewEdge(5, 4, 12);        

    R.Sort();
    
    R.KruskalSpan(1);
    R.PrintSpan();
}