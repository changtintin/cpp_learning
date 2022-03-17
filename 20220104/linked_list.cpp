#include<iostream>
#include<string>
using namespace std;

class node{
    public:
    int num;
    node *next;
};
void Show_list(node * eg){
    while(eg != NULL) {
        cout << eg ->num << " ";
        eg = eg -> next;
    }
    cout << endl;
}
void Push_front(int x , node * head){
    node *input = NULL;
    input = new node();
    input -> num = x;
    input -> next = head;
    head = input;
    Show_list(input);
}

int main(){
    node *head = NULL;
    node *second = NULL;
    node *third = NULL;

    head = new node();
    second = new node();
    third = new node();

    head -> num = 3;
    head -> next = second; 

    second -> num = 53;
    second -> next = third;

    third -> num = 19;
    third -> next = NULL;

    int x ;
    cout << "This is default linked list: " ;
    Show_list(head);
    cout << "Give a number to insert: " ;
    cin >> x ;
    Push_front(x,head);
    return 0 ;
}


