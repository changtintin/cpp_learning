#include <iostream>
#include <map>
#include <list>
#include <stack>
#include <queue>
using namespace std;

class Graph{
    public:        
        map<int, list<int>> G;
        queue<int> bfs_route;
        stack<int> dfs_route;
        map<int, bool> visited;
    
    public:
        void AddEdge(int st, int ed);
        void ShowGraph();
        void DFS(int num);
        void BFS(int num);
        void VisReset();
};

void Graph::AddEdge(int st, int ed){
    list<int> l;
    G.emplace(st, l); // if the key doesn't exist, it'll insert one
    visited.emplace(st, false);
    G[st].push_back(ed);
    G[st].sort();    
}

void Graph::ShowGraph(){
    cout << "Graph : \n";
    for(map<int, list<int>>::iterator i = G.begin(); i != G.end(); i++){
        cout << "\t[ " << i->first << " ] = ";
        for(list<int>::iterator j = i -> second.begin(); j != i -> second.end(); j++){
            cout << *j << " ";
        } 
        cout << endl;
    }
    cout << endl;
}

void Graph::DFS(int num){
    if(visited[num] == false){
        cout << num << " ";
        dfs_route.push(num);
        visited[num] = true;
    }

    list<int>::iterator i;
    for(i = G[num].begin(); i != G[num].end(); i++){
        if(visited[*i] == false){
            DFS(*i);
            break;
        } 
    }

    if(i == G[num].end() && dfs_route.empty() == false){
        int des = dfs_route.top();
        dfs_route.pop();
        DFS(des);
    }
}

void Graph::BFS(int num){ 
    if(visited[num] == false){
        cout << num << " ";
        visited[num] = true;
    }

    list<int>::iterator i;
    for(i = G[num].begin(); i != G[num].end(); i++){
        if(visited[*i] == false){
            cout << *i << " ";
            visited[*i] = true;
            bfs_route.push(*i);
        } 
    }

    if(!bfs_route.empty()){
        int des = bfs_route.front();
        bfs_route.pop();
        BFS(des);
    }
}

void Graph::VisReset(){
    int s = G.size();
    for(int i = 0; i < s; i++){
        visited[i+1]=false;
    }
}
int main(){
    Graph gr;
    gr.AddEdge(1,2);
    gr.AddEdge(1,3);
    gr.AddEdge(2,1);
    gr.AddEdge(2,4);
    gr.AddEdge(2,5);
    gr.AddEdge(3,1);
    gr.AddEdge(3,6);
    gr.AddEdge(3,7);
    gr.AddEdge(4,2);
    gr.AddEdge(4,8);
    gr.AddEdge(5,2);
    gr.AddEdge(5,8);
    gr.AddEdge(6,8);
    gr.AddEdge(7,8);
    gr.AddEdge(6,3);
    gr.AddEdge(7,3);
    gr.AddEdge(8,4);
    gr.AddEdge(8,5);
    gr.AddEdge(8,6);
    gr.AddEdge(8,7);
    
    gr.ShowGraph();
    gr.DFS(1);
    gr.VisReset();
    cout << endl;
    gr.BFS(1);
}
