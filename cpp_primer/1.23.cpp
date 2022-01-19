#include<iostream>
#include<string>
#include "Sales_item.h"
using namespace std;
int main(){
    Sales_item item_1 , item_2;
    int count=0;
    cin >> item_1;
    while(cin >> item_2){
        if(item_2.isbn() == item_1.isbn()){
            count ++;
        }
        else{
            
            cout << item_1.isbn() << " : count = " << count << endl; 
            item_1 = item_2;
            count = 0;
        }
    }
    
}
