#include<iostream>
using namespace std;
class Node{
    public:
        int value;
        Node* next;
    public:
        Node(int input);
};
Node::Node(int input){
    value = input;
    next = NULL;
}
class Stack_linked_list{
    public:
        Node* head;
    public:
        Stack_linked_list();
    public:
        void create_stack(int input);
        void show_all();
        void push(int input);
        void pop();

    
};
Stack_linked_list::Stack_linked_list(){
    head = NULL;
}
void Stack_linked_list::create_stack(int num){
    Node* location = new Node(num);
    head = location;
}
void Stack_linked_list::show_all(){
    if(head != NULL){
        Node* temp = head;
        while(temp -> next != NULL){
            cout << temp -> value << " ";
            temp = temp -> next;
        }
        cout<< temp -> value << endl;
    }
    else{
        cout << "Nothing to show!" << endl;
    }
}
void Stack_linked_list::push(int input){
    Node* location = new Node(input);
    if(head != NULL){
        Node* temp = head;
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        temp -> next = location;
        location -> next = NULL;
    }
    else{
        create_stack(input);
    }
    show_all();
}
void Stack_linked_list::pop(){
    Node* temp = head;
    
    if(head == NULL){
        cout << "Nothing to pop" << endl;
    }
    else{
        if(head -> next == NULL){
            head = NULL;
        }
        else{
            while(temp -> next -> next !=0){
                temp = temp -> next;
            }
            temp -> next = NULL;
        }
        show_all();
    }
}
int main(){
    Stack_linked_list new_stack;
    new_stack.push(25);
    new_stack.pop();
    new_stack.push(211);
    new_stack.push(31);
    new_stack.push(77);
    new_stack.pop();
    new_stack.pop();
    new_stack.push(80);
    new_stack.push(43);
    new_stack.push(6);
    new_stack.push(10);
    new_stack.pop();
}