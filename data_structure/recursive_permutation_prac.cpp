#include <iostream>
using namespace std;
void swap (char *a, char *b){
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void permutation(char *str, int index, int len){
    if(index == (len-1))
        cout << str << endl;
    else
        for(int i = index; i < len; i++ ){
            swap((str + index), (str + i));
            permutation(str, index + 1, len);
            swap((str + index), (str + i));
        }
}
int main(){
    char str[]= "ABC";
    int index = 0;
    int len = strlen(str);    
    permutation(str, index, len);
}