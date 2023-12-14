#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct stackNode{
    char data;
    struct stackNode *next;
} stackNode;

typedef struct stack_t{
    stackNode *top;
    int size;
} stack_t;

stackNode *newNode(char data){
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

void push(stack_t *stack, char data){
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

char pop(stack_t *stack){
    if(stack->size == 0) return -1;
    stackNode *node = stack->top;
    stack->top = node->next;
    --stack->size;
    char data = node->data;
    free(node);
    return data;
}

int priority(char x){
    if(x == '(') return 0;
    if(x == '+' || x == '-') return 1;
    if(x == '*' || x == '/') return 2;
    return 0;
}


int main(){
    stack_t *stack = newStack();
    char ex[200];
    char *x, y;
    printf("Write a expression: ");
    scanf("%s", ex);
    printf("\n");
    x = ex;
    while(*x != '\0')
    {
        if(isalnum(*x)) printf("%c ", y);
        else if(*x == '(') push(stack, *x);
        else if(*x == ')') while((y = pop(stack)) != '(') printf("%c ", y);
        else{
            stackNode *node = stack->top;
            while(priority(node->data) >= priority(*x)) printf("%c ", pop(stack));
            push(stack, *x);
        }
        x++;
    }
    while(stack->top != NULL) printf("%c ", pop(stack));
}