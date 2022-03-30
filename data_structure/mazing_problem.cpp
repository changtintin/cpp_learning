#include <iostream>
using namespace std;
class Offset{
    public:
        int horz;
        int vert;
    public:
        void h_v(int h, int v);
};

void Offset::h_v(int h, int v){
    horz = h;
    vert = v;
}

class Stack{ //path history
    public:
        int row;
        int col;
    public:
        void push(int r, int c);
};

void Stack::push(int r, int c){
    row = r;
    col = c;
}

void process(int nr, int nc, int fr, int fc, int index, int maze[][17], Offset *move, Stack *stk){
    if(nr == fr && nc == fc){
        index ++;
        stk[index].push(nr, nc);
        maze[nr][nc] = 1;
        for(int i = 0; i < index; i++){
            cout << "("<<stk[i].row << ", " << stk[i].col ;
            if(i == index -1)
                cout << ")";
            else
                cout << ") -> ";
        }
        cout << endl;
        return;
    }
    else{
        int tmpr, tmpc, dir = 0; 
        while(dir < 8){
            tmpc = nc + move[dir].horz;
            tmpr = nr + move[dir].vert;
            if(maze[tmpr][tmpc] == 0){
                nr = tmpr;
                nc = tmpc;
                index ++;
                stk[index].push(nr, nc);
                maze[nr][nc] = 1;
                process(nr, nc, fr, fc, index, maze, move, stk);
            }
            else{
                dir ++;
                tmpr = 0;
                tmpc = 0;
            }
        }
        return;
    }
}

int main(){
    int maze[13][17] = {
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,0,1,0,0,0,1,1,0,0,0,1,1,1,1,1,1},
        {1,1,0,0,0,1,1,0,1,1,1,0,0,1,1,1,1},
        {1,0,1,1,0,0,0,0,1,1,1,1,0,0,1,1,1},
        {1,1,1,0,1,1,1,1,0,1,1,0,1,1,0,0,1},
        {1,1,1,0,1,0,0,1,0,1,1,1,1,1,1,1,1},
        {1,0,0,1,1,0,1,1,1,0,1,0,0,1,0,1,1},
        {1,0,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1},
        {1,0,0,1,1,0,1,1,0,1,1,1,1,1,0,1,1},
        {1,1,1,0,0,0,1,1,0,1,1,0,0,0,0,0,1},
        {1,0,0,1,1,1,1,1,0,0,0,1,1,1,1,0,1},
        {1,0,1,0,0,1,1,1,1,1,0,1,1,1,1,0,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    };

    Offset move[8];
    move[0].h_v(-1, 0); // N
    move[1].h_v(-1, 1); // NE
    move[2].h_v(0, 1); // E
    move[3].h_v(1, 1); // ES
    move[4].h_v(1, 0); // S
    move[5].h_v(1, -1); // WS
    move[6].h_v(0, -1); // W
    move[7].h_v(-1, -1); // NW

    int nr = 1; //start
    int nc = 1;

    int fr = 11; // finish
    int fc = 15;

    Stack stk[221];
    int index = 0;
    stk[index].push(1, 1);
    maze[1][1] = 1;
    
    process(nr, nc, fr, fc, index, maze, move, stk);
}