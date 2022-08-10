#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
class Set{
    public:
        int *s;  //pointer to the set array
        int *ptr; // pointer point to each set
        int pr; // number of elements in ptr array
        int num; // number of elements in s array
    public: 
        Set(int n);
        void BuildSet();
        void Union(int sa, int sb);
        void Show();
};

Set::Set(int n){
    num = n;
    ptr = 0;
    s = new int[n];
    ptr = new int[n];
}

void Set::BuildSet(){
    int ary[num];
    fstream f;
    string str, st;
    
    f.open("set.txt", ios::in);
    int idx = 0, rt = 0, p = 0;
    
    // Build the set[]
    while(getline(f, str)){ 
        stringstream ss(str);
        while(getline(ss, st, ',')){
            ary[idx] = stoi(st);
            for(int i = 0; i <= num; i++){

                // idx = 0 means it's the root of this set
                // rt =  root value   
                if(i == ary[idx] && idx == 0){ 
                    s[i] = -1;
                    rt = i;
                    ptr[p] = rt;
                    p++;
                }
                else if(i == ary[idx] && idx != 0){
                    s[i] = rt;
                }
            }
            idx++;
        }
        idx = 0;
    } 
    pr = p;
}

void Set::Show(){
    // Show the sets in the set[]
    int p = 0;
    while(p < pr){
        cout << "Set" << p + 1 << ": " << ptr[p] << " ";
        for(int j = 0; j < 10; j++){
            if(s[j] == ptr[p] && s[j]!= -1){
                cout << j << " ";
            }
        }
        cout << endl;
        p++;
    }
    cout << endl;
}

void Set::Union(int sa, int sb){
    int rt = 0;
    int mrt = 0;
    if(sa > pr || sb > pr){
        cout << "The set doesn't exist.";
        exit(0);
    }

    for(int i = 0; i < pr; i++){
        if(i == sa-1 || i == sb-1){
            rt = ptr[i];
            if(i == sa - 1)
                mrt = ptr[sb - 1];
            else if(i == sb -1)
                mrt = ptr[sa -1];

            s[mrt] = rt;
            break;
        }
    }
    for(int i = 0 ; i < pr; i++){
        if(ptr[i] == mrt){
            for(int j = i; j < pr; j++){
                ptr[j] = ptr[j+1];
            }
            pr --;
            break;
        }
    }
    for(int i = 0; i <= num; i++){
        if(s[i] == mrt && s[i] != rt){ 
            s[i] = rt;
        }
    }
}

int main(){
    Set s(9);
    s.BuildSet();
    s.Show();
    s.Union(1, 3);
    s.Show();
}