#include <iostream>
#include <string>
using namespace std;

#include "node_class.cpp"

class Linked_list {
    public:
        Node* head;
    public:
        Linked_list(); //建構式
    public:
        void insert_last_node(int value); //無回傳值的函數
        void insert_nth_node(int input, int location); //無回傳值的函數
        Node* create_node(int value);
        void show_all();
        void insert_head_node(int input);
        void delete_last_node();
        void delete_first_node();
        void delete_nth_node(int location);
         
};

Linked_list::Linked_list(){
    head = NULL; //NULL=啥都沒有
};

void Linked_list::insert_last_node(int value) {
    Node* n = create_node(value); 
    if(head == NULL){
        head = n;
    }
    else{
        Node* tmp = head;
        while(tmp -> next != NULL){
            tmp = tmp -> next;
        }
        tmp -> next = n;
    }
    show_all();
}

void Linked_list::insert_nth_node(int input, int location) {
    Node* n = create_node(input);
    if(head == NULL){
        head = n;
    }
    else {
        Node* tmp = head;
        int count = 1; // 前面有幾個東西
        while((tmp -> next != NULL) && (count != location - 1)) {
            tmp = tmp -> next;
            count++;
        }

        // 1. 他已經走到最後面了
        if(tmp -> next == NULL) {
            tmp -> next = n;
        }
        // 2. 他已經找到位置了
        else {
            n -> next = tmp -> next;
            tmp -> next = n;
        }
        show_all();
    }
}

Node* Linked_list::create_node(int value){
    Node* n = new Node(value); // 類似於 Node n
    return n;//回傳記憶體位址
}

void Linked_list::show_all(){
    if(head == NULL){
        cout << "Nothing to show!" << endl;
    }
    else{
        cout << "Linked-list: " ;
        Node* tmp = head;
        while(tmp != NULL){
            cout << tmp -> data << " ";
            tmp = tmp -> next;
        }
        cout << endl;
    }
}

void Linked_list::insert_head_node(int input){
    Node* n = create_node(input);
    if(head!=NULL){
        n -> next = head;
        head = n;
    }
    else{
        head = n;
    }
    show_all();
}

void Linked_list::delete_last_node(){
    if(head == NULL){
        cout << "Nothing to delete." << endl;
    }
    else{
        if (head->next!= NULL){
            Node* tmp = head;
            while(tmp -> next->next != NULL){
                tmp = tmp -> next;
            }
            tmp -> next = NULL;
        }
        else{
            head = NULL;
            
        }
        show_all();
    } 
}

void Linked_list::delete_first_node(){
    if(head == NULL){
        cout << "Nothing to delete." << endl;
    }
    else{
        head = head -> next;
        
    }
    show_all();
}

void Linked_list::delete_nth_node(int location){
    if(head == NULL){
        cout << "Nothing to delete." << endl;
    }
    else{
        Node* tmp1 = head;
        for(int i = 1; i < location - 1; i++){
            tmp1 = tmp1 -> next;
        }
        Node* tmp2 = tmp1 -> next  ;
        Node* tmp3 = tmp2 -> next ;
        tmp2 = NULL;
        tmp1 -> next = tmp3;
        show_all();
    }
}

