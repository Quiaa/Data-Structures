#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node* next;
} Node;

Node *createNode(int value){
    Node *node = (Node*) malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    return node;
}

void insert(Node **heap, int value){
    Node *newNode = createNode(value);
    if(*heap == NULL){
        *heap = newNode;
        return;
    }
    if(value > (*heap)->value){
        newNode->next = *heap;
        *heap = newNode;
        return;
    }
    Node* current = *heap;
    while (current->next != NULL && value <= current->next->value) current = current->next;
    newNode->next = current->next;
    current->next = newNode;
}

int delete(Node** heap){
    if(*heap == NULL){
        printf("Heap is empty\n");
        return -1;
    }
    Node* nodeToDelete = *heap;
    int value = nodeToDelete->value;
    *heap = (*heap)->next;
    free(nodeToDelete);
    return value;
}

void heapify(Node **heap){
    if(*heap == NULL || (*heap)->next == NULL) return;
    Node* current = *heap;
    while(current->next != NULL){
        if(current->value > current->next->value){
            int temp = current->value;
            current->value = current->next->value;
            current->next->value = temp;
            current = *heap;
        } 
        else current = current->next;
    }
}

void printHeap(Node *heap){
    if(heap == NULL){
        printf("Heap is empty\n");
        return;
    }
    while(heap != NULL){
        printf("%d ", heap->value);
        heap = heap->next;
    }
    printf("\n");
}

int main(){
    Node* heap = NULL;
    insert(&heap, 10);
    insert(&heap, 20);
    insert(&heap, 30);
    insert(&heap, 40);
    insert(&heap, 50);
    printf("Heap: ");
    printHeap(heap);

    delete(&heap);
    printf("Heap after deleting root: ");
    printHeap(heap);

    heapify(&heap);
    printf("Heap after heapify: ");
    printHeap(heap);

    return 0;
}