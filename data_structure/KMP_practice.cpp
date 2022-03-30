#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
using namespace std;
void kmp(char *txt, char *ptn, int end, int *lps){
    int i = 0, j = 0;
    int ptn_len = strlen(ptn) - 1;
    cout << "index: ";
    while(i < end){ 
        if(txt[i] == ptn[j]){
            if(j == 3){ 
                cout << i - 3 << ", ";
                j = lps[j-1];
                i ++;
            }
            else{
                i++ ;
                j++ ;
            }
        }
        else{
            if(j == 0){
                i++;
            }
            else{
                j = lps[j-1];
            }
        }
    }
    cout << endl;
}
int *lps_fun(char *txt, char *ptn, int *lps){
    int len = 0, i = 1;
    int end = strlen(ptn);
    int *lps = new int[strlen(ptn)];
    lps[0] = 0;
    while(i < end){
        if(ptn[i] == ptn[len]){
            lps[i] = len + 1;
            len ++;
            i ++;
        }
        else{
            if(len == 0){
                lps[i]=0;
                i++;
            }
            else{
                len = lps[len-1];
            }
        }    
    }
    return lps;
}
int main(){
    char txt[] = "abddbadbddbdada";
    char ptn[] = "bddb";
    int lps[strlen(ptn)];
    int *lps = lps_fun(txt, ptn, lps);
    kmp(txt, ptn, strlen(txt), lps);
}