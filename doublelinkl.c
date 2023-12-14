#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *head = NULL;

Node *createNode(int data){
    Node *newNode = (Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void adder(int data){
    Node *newNode = createNode(data);

    if(head == NULL){
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

void delete(int data){
    Node *current = head;

    while(current != NULL){
        if(current->data == data){
            if(current == head){
                head = current->next;
                head->prev = NULL;
            } 
            else if(current->next == NULL) current->prev->next = NULL;
            else{
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            free(current);
            return;
        }
        current = current->next;
    }
}

Node *find(int data){
    Node *current = head;

    while(current != NULL) {
        if(current->data == data) return current;
        current = current->next;
    }
    return NULL;
}

void printList(){
    Node *current = head;

    while(current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main(){
    adder(1);
    adder(2);
    adder(3);
    adder(4);
    adder(5);
    printList();
    delete(3);
    printList();
    Node *node = find(4);
    printf("%d\n", node->data);
    return 0;
}