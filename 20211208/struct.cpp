#include <iostream>
#include <string>
using namespace std;

typedef struct {
    int id;
    int age;
    string name;
} student;

typedef struct node {
    student data;
    struct node* next;
    struct node* last;
} node;

int main(void) {
    student ming, hua, mei;
    ming.id = 1;
    ming.age = 17;
    ming.name = "ming";

    hua.id = 2;
    hua.age = 18;
    hua.name = "hua";

    mei.id = 3;
    mei.age = 16;
    mei.name = "mei";

    node* MI = (node*)(malloc(sizeof(node)));
    MI -> data = ming;

    node* HU = (node*)(malloc(sizeof(node)));
    HU -> data = hua;

    node* ME = (node*)(malloc(sizeof(node)));
    ME -> data = mei;


    MI -> next = HU;

    HU -> next = ME;
    HU -> last = MI;

    ME -> last = HU;

    cout << MI -> next -> last -> data.age << endl;
}