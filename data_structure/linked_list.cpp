#include<iostream>
#include<string>
using namespace std;
class Node{
    public:
        int value;
        Node *next;
};
class Linked_list{
    public:
        Node *head;
    public:
        Linked_list();
    public:
        void new_node(int num);
        void insert_front(int num);
        void show();
};
Linked_list::Linked_list(){
    head = NULL;
}
void Linked_list::new_node(int num){
    Node *new_node = new Node();
    new_node -> value = num;
    if(head == NULL){
        head = new_node;
        new_node -> next = NULL;
    }
    else{
        Node *index;
        index = head;
        while(index -> next != NULL){
            index = index -> next;
        }
        index ->next = new_node;
        new_node ->next = NULL;
    }
}
void Linked_list::insert_front(int num){
    if(head == NULL){
        new_node(num);
    }
    else{
        Node *insert_node = new Node();
        insert_node -> value = num;
        Node *index;
        index = head;
        insert_node -> next = index;
        head = insert_node;
    }
}
void Linked_list::show(){
    if(head!=NULL){
        Node *index;
        index = head;
        while(index!= NULL){
            cout << index ->value << ", " ;
            index = index -> next;
        }
    }
    else{
        cout << "WTF Here is nothing to show!";
    }
    cout << endl;
}
int main(){
    Linked_list list_a;
    list_a.show();
    list_a.new_node(9);
    list_a.new_node(23);
    list_a.new_node(88);
    list_a.new_node(45);
    list_a.new_node(99);
    list_a.insert_front(33);
    list_a.show();
}
