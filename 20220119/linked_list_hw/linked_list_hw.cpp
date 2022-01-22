#include<iostream>
using namespace std;
class Node{
    public:
        Node* last;
        int data;
        Node* next;
    public:
       Node(int input); 
};
Node::Node(int input){
    data = input;
    next = NULL;
    last = NULL;
}
class Linked_list{
    public:
        Node* head;
        Node* tail;
    public:
        Linked_list();
    public:
    void insert_last_node(int input);
    void traversal();
    void reverse_traversal();
    void delete_exist_node(int num);
    void sort_list();

};
Linked_list::Linked_list(){
    head = NULL;
    tail = NULL;
}
void Linked_list::insert_last_node(int input){
    Node* location = new Node(input);
    if(head == NULL){
        head = location;
    }
    else{
        Node* tmp1 = head;
        while(tmp1 -> next != NULL){
            tmp1 = tmp1 -> next;
        }
        tmp1 -> next = location;
        location -> last = tmp1;
        tail = location;
    }
}
void Linked_list::traversal() {
    if(head == NULL){
        cout << "Nothing to show." << endl;
    }
    else{
        Node* tmp = head;
        while(tmp -> next != NULL){
            cout << tmp -> data << " " ;
            tmp = tmp -> next;
        }
        cout << tmp -> data << endl;
    }
}
void Linked_list::reverse_traversal(){
    if(head == NULL){
        cout << "Nothing to show." << endl;
    }
    else{
        Node* tmp = tail;
        while(tmp -> last != NULL){
            cout << tmp -> data << " " ;
            tmp = tmp -> last;
        }
        cout << tmp -> data << endl;
    }
}
void Linked_list::delete_exist_node(int input){
    if(head == NULL){
        cout << "Nothing to show." << endl;
    }
    else{
        Node* tmp = head;
        while(tmp -> next != NULL){
            if(tmp -> data == input){
                (tmp -> last) -> next = tmp -> next;
                (tmp -> next) -> last = tmp -> last;
            }
            
            tmp = tmp -> next;
            
        }
    }
}
void Linked_list::sort_list(){
    if(head == NULL){
        cout << "Nothing to sort." << endl;
    }
    else{
        Node* tmp1 = head;
        Node* tmp2 = head -> next;
        while(tmp1 -> next != NULL){
            while(tmp2 -> next != NULL){
                if(tmp1 -> data > tmp2 -> data){
                    int a = tmp2 -> data;
                    tmp2 -> data = tmp1 -> data;
                    tmp1 -> data = a;
                }
                tmp2 = tmp2 -> next;
            }
            if(tmp1 -> data > tmp2 -> data){
                    int a = tmp2 -> data;
                    tmp2 -> data = tmp1 -> data;
                    tmp1 -> data = a;
            }
            tmp1 = tmp1 -> next;
            tmp2 = tmp1 -> next;
        }
    }
}
int main(){
    Linked_list list;
    int num;
    list.insert_last_node(88);
    list.insert_last_node(2);
    list.insert_last_node(53);
    list.insert_last_node(0);
    list.insert_last_node(12);
    list.insert_last_node(39);
    list.insert_last_node(7);
    list.insert_last_node(1);
    list.traversal();
    cout << "Enter a number to delete: ";
    cin >> num;
    list.delete_exist_node(num);
    list.traversal();
    list.sort_list();
    list.traversal();
}