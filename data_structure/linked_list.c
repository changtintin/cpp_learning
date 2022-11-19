#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Node{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void InsertFront(int val){
    struct Node *tmp = (struct Node*)malloc(sizeof(struct Node));
    tmp -> data = val;
    tmp -> next = head; 
    head = tmp;
}

void InsertMid(int val, int seq){
    struct Node *tmp = head;
    int i = 1;
    while(i < seq){
        if(i != seq - 1){
            tmp = tmp -> next;
            i++;
        }
        else{
            break;
        }
    }
    if(tmp != NULL){
        struct Node *n = (struct Node*)malloc(sizeof(struct Node));
        n -> data = val;
        n -> next = tmp -> next;
        tmp -> next = n;
    }
    else{
        printf("No Such position\n");
    }
}

void Delete(int seq){
    struct Node *tmp1 = head;
    struct Node *tmp2;

    int i = 0;
    while(i < seq){
        if(i != seq - 1){
            tmp1 = tmp1 -> next;
            i++;
        }
        else{
            if(tmp1 -> next != NULL){
                tmp2 = tmp1 -> next;
            }
            break;
        }
    }
    if(tmp1 != NULL && tmp2 != NULL){
        tmp1 -> next = tmp2 -> next;
        free(tmp2);
    }
    else{
        printf("No Such position\n");
    }
}

bool Find(int num){
    struct Node *tmp = head;
    while(tmp != NULL){
        if(tmp -> data == num){
            return true;
        }
        tmp = tmp -> next;
    }
    return false;
}

void Show(){
    struct Node *tmp = head;
    while(tmp != NULL){
        printf(" %d", tmp -> data);
        tmp = tmp -> next;
    }
    printf("\n");
}

int main() {
    InsertFront(4);
    InsertFront(22);
    InsertFront(54);
    InsertFront(92);
    InsertFront(31);
    InsertFront(7);
    InsertFront(12);
    InsertFront(61);

    bool b = Find(22);
    if(!b){
        printf("No Result\n");
    }
    else{
        printf("Exist\n");
    }

    Show();
    InsertMid(10,3);
    Show();
    Delete(5);
    Show();
}
