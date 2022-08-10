#include <iostream>
#include <vector>
using namespace std;
int Count[6][6][10];
vector<int> FindVertex(int W[][6], int p, int j, int e, vector<int> r){
    int tmpc;
    int tmpi;

    while(e >= 0){
        tmpc = 0;
        tmpi = 0;
        e--;
        if(e == 0){
            break;
        }
        else{
            for(int i = 0; i < 6; i++){
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
                if(i == 5 && tmpc != 0){
                    r.push_back(tmpi);
                    p = tmpi;
                }
            }
        }
    }
    return r;
}

vector<vector<int>> Traverse(int W[][6], int u, int v, int k){
    
    vector<vector<int>> route;

    for(int e = 0; e <= k; e++){
        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 6; j++){

                Count[i][j][e] = 0;

                if(e == 0 && i == j)
                    Count[i][j][e] = 0;
                
                if(e == 1 && W[i][j] > 0){                
                    Count[i][j][e] = W[i][j];
                }

                if(e > 1){
                    for(int p = 0; p < 6; p++){
                        if(W[i][p] > 0 && Count[p][j][e - 1] > 0){
                            // if(i == u && j == v){
                            //     cout << "i = " << i << endl;
                            //     cout << "p = " << p << endl;
                            //     cout << "j = " << j << endl;
                            //     cout << "e = " << e << endl;
                            //     cout << "Weight = " << Count[i][j][e] << endl;
                            //     cout << "***********************" << endl << endl;
                            // }
                            //if the new weight of route is less than the original one
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

                                // for(int a = 0; a < route.size(); a++){
                                //     cout << "{  ";
                                //     for(int b = 0; b < route[a].size(); b++ ){
                                //         cout << route[a][b];
                                //         if(b != route[a].size()-1)
                                //             cout << ", ";                                           
                                //     }
                                //     cout << "  }" << endl;
                                // }
                                tmp.clear();
                            }
                        }
                    }
                }
            }
        }
    }
    cout << "Count = {" << endl;;
    for(int d= 0; d < 6; d++){
        cout << "\t" <<  d << "-> " << endl; 
        for(int a = 0; a < 6; a++){
            cout << "\t\t"<< a << " -> ";
            cout << "\t{ ";
            for(int c = 0; c < 10; c++){
                
                cout << Count[d][a][c];

                if(c != 9)
                    cout << ", ";
            }
            cout << " }," << endl;
        }
    }
    cout << "}" << endl;

    return route;
}
int main(){
    
    int W[6][6] = { 
        { 0, 0, 0, 0, 0, 10},
        { 0, 0, 0, 12, 20, 0},
        { 0, 0, 0, 0, 11, 9},
        { 0, 0, 5, 0, 4, 0},
        { 1, 0, 0, 0, 0, 7},
        { 0, 0, 0, 0, 0, 0},
    };

    // k = number of edges in the graph
    // if vertex u go through all of the edge, it'd path k edges
    int k = 0;
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            if(W[i][j] != 0){
                k ++;
            }
        }
    }

    int u = 1, v = 5; 
    
    // Find all routes which is start from vertex u pass k edges to vertex v
    vector<vector<int>> Routelist = Traverse(W, u , v, 9);

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
}
