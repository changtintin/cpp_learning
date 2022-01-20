#include <iostream>
using namespace std;

#include "linked_list_class.cpp"

int main() {
    int num, input;
    Linked_list ll;
    ll.delete_last_node();
    ll.insert_last_node(6);
    ll.delete_last_node();
    ll.insert_last_node(4);
    ll.insert_last_node(90);
    ll.insert_last_node(7788);
    ll.insert_last_node(7414);
    ll.insert_last_node(512);
    ll.insert_last_node(100000);
    ll.insert_last_node(123);
    ll.insert_nth_node(999, 9);// 999 在最後面
    ll.insert_nth_node(333, 3);// 333 在第三個
    ll.insert_head_node(17);
    ll.delete_last_node();
    ll.delete_first_node();
    cout << "Which note do u want to drop?" << endl;
    cin >> num ;
    ll.delete_nth_node(num);
    
}