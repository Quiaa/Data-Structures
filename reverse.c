#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//        Beginning of the Stack
typedef struct stackNode{
    int data;
    struct stackNode *next;
} stackNode;

typedef struct stack_t{
    stackNode *top;
    int size;
} stack_t;

stackNode *newNode(int data){
    stackNode *temp = (stackNode*) malloc(sizeof(stackNode));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

stack_t *newStack(){
    stack_t *temp = (stack_t*) malloc(sizeof(stack_t));
    temp->size = 0;
    temp->top = NULL;
    return temp;
}

void push(stack_t *stack, int data){
    stackNode *node = newNode(data);
    if(stack->size == 0){
        stack->top = node;
    }
    else{
        node->next = stack->top;
        stack->top = node;
    }
    ++stack->size;
}

int pop(stack_t *stack){
    if(stack->size == 0) return -1;
    stackNode *node = stack->top;
    stack->top = node->next;
    --stack->size;
    int data = node->data;
    free(node);
    return data;
}

void printS(stack_t *stack){
    stackNode *cur = stack->top;
    printf("Stack [%d]=>",stack->size);
    while(cur){
        printf("%d ",cur->data);
        cur = cur->next;
    }
    printf("\n");
} 
//                End of the stack

//                Beggining of the Linked List
typedef struct listNode{
    int data;
    struct listNode *next;
} listNode;

typedef struct list_t{
    listNode *head, *tail;
    int size;
} list_t;

listNode *newLNode(int data){
    listNode *temp = (listNode*) malloc(sizeof(listNode));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

list_t *newList(){
    list_t *temp = (list_t*) malloc(sizeof(list_t));
    temp->size = 0;
    temp->head = NULL;
    temp->tail = NULL;
    return temp;
}

void addToFront(list_t *list, int data){
    listNode *node = newLNode(data);
    if(list->size == 0){
        list->head = node;
        list->tail = node;
    }
    else{
        node->next = list->head;
        list->head = node;
    }
    ++list->size;
}

void addToBack(list_t *list, int data){
    listNode *node = newLNode(data);
    if(list->size == 0){
        list->head = node;
        list->tail = node;
    }
    else{
        list->tail->next = node;
        list->tail = node;
    }
    ++list->size;
}

void printL(list_t *list){
    listNode *cur = list->head;
    printf("List [%d]=>",list->size);
    while(cur){
        printf("%d ",cur->data);
        cur = cur->next;
    }
    printf("\n");
} 
//                End of the Linked List

void reverse(list_t *list){
    if(list->size <= 1) return;
    stack_t *stack = newStack();
    listNode *cur = list->head;
    listNode *temp;
    while(cur){
        push(stack, cur->data);
        temp = cur;
        cur = cur->next;
        free(temp);       
    }
    list->size = 0;
    while(stack->size){
        addToBack(list, pop(stack));
    }
    free(stack);
}

int main(){
    srand(time(NULL));
    list_t *list = newList(); 

    for(int i = 0; i < 15; ++i){
        addToFront(list, rand()%50);
    }
    printL(list);

    reverse(list);
    printL(list);
}