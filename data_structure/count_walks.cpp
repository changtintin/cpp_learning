#include <iostream>
#include <vector>
using namespace std;
int Count[8][8][11];

void ShowMinWeight(vector<vector<int>> &r){
    int tmp = 0;
    vector<int>::iterator b;
    vector<int>::iterator e;

    for(auto i = r.begin(); i != r.end(); i++){
        
        if(tmp == 0){
            tmp = *(i -> end() - 1);
            b = i -> begin();
            e = i -> end();
        }
        else if(tmp != 0 && *(i ->end() - 1) < tmp){
            tmp = *(i -> end() - 1);
            b = i -> begin();
            e = i -> end();
        }
    }
    cout << "Minimum Route: ";
    for(auto i = b; i != e; i++){
        if(i == e - 1){
            cout << endl;
            cout << " Weight: " <<  *i;
        }
        else{
            cout << *i;
            if(i != e - 2)
                cout << ", ";
        }
    }
}

vector<int> FindVertex(int W[][8], int p, int j, int e, vector<int> r){
    
    int tmpc;
    int tmpi;

    while(e > 0){
        tmpc = 0;
        tmpi = 0;
        e--;
        
        for(int i = 0; i < 8; i++){
            if(W[p][i] > 0 &&  Count[i][j][e] > 0){
                if(tmpc == 0){
                    tmpc = Count[i][j][e];
                    tmpi = i;
                }
                else if(tmpc > 0 && Count[i][j][e] < tmpc){
                    tmpc = Count[i][j][e];
                    tmpi = i;
                }
            }
            if(i == 7 && tmpc != 0){
                r.push_back(tmpi);
                p = tmpi;
            }
        }
    }
    return r;
}

vector<vector<int>> Traverse(int W[][8], int u, int v, int k){
    vector<vector<int>> route;

    for(int e = 0; e <= k; e++){
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){

                Count[i][j][e] = 0;

                if(e == 0 && i == j)
                    Count[i][j][e] = 0;
                
                if(e == 1 && W[i][j] > 0){                
                    Count[i][j][e] = W[i][j];
                }

                if(e > 1){
                    for(int p = 0; p < 8; p++){
                        if(W[i][p] > 0 && Count[p][j][e - 1] > 0){
                            
                            if(Count[i][j][e] != 0 && W[i][p] + Count[p][j][e - 1] < Count[i][j][e]){
                                Count[i][j][e] = Count[p][j][e - 1] + W[i][p];
                            }
                            else if(Count[i][j][e] == 0){
                                Count[i][j][e] = Count[p][j][e - 1] + W[i][p];
                            }

                            if(i == u && j == v){
                                // tmp is the new element of vector route 
                                vector<int> tmp; 
                                tmp.push_back(i);
                                tmp.push_back(p);

                                if(e > 0){
                                    tmp = FindVertex(W,  p, j, (e - 1), tmp);
                                }
                                tmp.push_back(j);
                                tmp.push_back(Count[p][j][e - 1] + W[i][p]);
                                route.push_back(tmp);

                                tmp.clear();
                            }
                        }
                    }
                }
            }
        }
    }
    // cout << "Count = {" << endl;;
    // for(int d= 0; d < 8; d++){
    //     cout << "\t" <<  d << "-> " << endl; 
    //     for(int a = 0; a < 8; a++){
    //         cout << "\t\t"<< a << " -> ";
    //         cout << "\t{ ";
    //         for(int c = 0; c <12 ; c++){
                
    //             cout << Count[d][a][c];

    //             if(c != 11)
    //                 cout << ", ";
    //         }
    //         cout << " }," << endl;
    //     }
    // }
    // cout << "}" << endl;
    return route;
}
int main(){
    
    int W[8][8] = { 
        { 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 300, 0, 0, 0, 0, 0, 0, 0 },
        { 1000, 800, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 1200, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 1500, 0, 250, 0, 0 },
        { 0, 0, 0, 1000, 0, 0, 900, 1400 },
        { 0, 0, 0, 0, 0, 0, 0, 1000 },
        { 1700, 0, 0, 0, 0, 0, 0, 0 },
    };

    // k = number of edges in the graph
    // if vertex u go through all of the edge, it'd path k edges
    int k = 0;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(W[i][j] != 0){
                k ++;
            }
        }
    }

    int u = 4, v = 0; 
    
    // Find all routes which is start from vertex u pass k edges to vertex v
    vector<vector<int>> Routelist = Traverse(W,u , v, 11);

    cout << "Routelist = {" << endl; 
    for(int i = 0; i < Routelist.size(); i++){
        cout << "\t" << i  << " -> {  ";
        for(int j = 0; j < Routelist[i].size(); j++){
            cout << Routelist[i][j];
            if(j != Routelist[i].size() - 1)
                cout << ", ";
        }
        cout << "  }" << endl;
    }
    cout << "}" << endl;
    
    
    ShowMinWeight(Routelist);
}
/*

int Count[8][8][5] = {
    
    {  {a,a,a,a,a}, {}, {}, {}, {}, {}, {}, {}  },
    {  {a,a,a,a,a}, {}, {}, {}, {}, {}, {}, {}  },
    {  {a,a,a,a,a}, {}, {}, {}, {}, {}, {}, {}  },
    {  {a,a,a,a,a}, {}, {}, {}, {}, {}, {}, {}  },
    {  {a,a,a,a,a}, {}, {}, {}, {}, {}, {}, {}  },
    {  {a,a,a,a,a}, {}, {}, {}, {}, {}, {}, {}  },
    {  {a,a,a,a,a}, {}, {}, {}, {}, {}, {}, {}  },
    {  {a,a,a,a,a}, {}, {}, {}, {}, {}, {}, {}  },     

};

k + 1 = 5:
    A vertex can reach another vertex by pathing k edges
    number of vertices ranged from 0 to 4

e = 0: 
    The distance from the vertex to itself is 0 

    e.g. Count[3][3][0] = 1

e = 1:
    The vertex i can reach the other node j and the distance between them is 1

    Check if the Graph[i][j] = 1
        1 means i can access j -> Count[i][j][e] = 1
        0 means i can't access j -> stay on 0 as initialization

e = 2:
    Count[i][j][2] = ?

    Graph[i][a] means Count[i][a][1] is true
    Traverse Graph to find the vertex a which vertex i can access.

    if vertex a can reach vertex j by pathing 1 edge, i can reach j by pathing 2 edge
    so add 1 at Count[i][j][2]

e = 3:
    Count[i][j][3] = ?

    Graph [i][a] means Count[i][a][1] is true
    Traverse Graph to find the vertex a which vertex i can access.

    if vertex a can reach vertex j by pathing 2 edge, i can reach j by pathing 3 edge
    so add 1 at Count[i][j][3]

e = n
*/