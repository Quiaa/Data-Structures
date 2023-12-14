#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
 
typedef struct stack_t{
    int top;
    unsigned capacity;
    int* array;
}stack_t;

stack_t *stackCreator(unsigned capacity){
    stack_t *stack = (stack_t *)malloc(sizeof(stack_t));
 
    if (!stack) return NULL;
 
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*) malloc(stack->capacity * sizeof(int));
 
    if (!stack->array) return NULL;
    return stack;
}
 
int isEmpty(stack_t *stack){
    return stack->top == -1 ;
}
 
char peek(stack_t *stack){
    return stack->array[stack->top];
}
 
char pop(stack_t *stack){
    if (!isEmpty(stack))
        return stack->array[stack->top--] ;
    return '$';
}
 
void push(stack_t *stack, char op){
    stack->array[++stack->top] = op;
}
 

int evaluater(char* exp){
    stack_t *stack = stackCreator(strlen(exp));

    if (!stack) return -1;

    for (int i = 0; exp[i]; ++i){
        if (isdigit(exp[i])) push(stack, exp[i] - '0');
        else{
            int val1 = pop(stack);
            int val2 = pop(stack);
            switch (exp[i]){
            case '+': push(stack, val2 + val1);
                break;
            case '-': push(stack, val2 - val1);
                break;
            case '*': push(stack, val2 * val1);
                break;
            case '/': push(stack, val2/val1);
                break;
            }
        }
    }
    return pop(stack);
}

int main(){
    char exp[] = "592*+3-";
    printf ("%d ", evaluater(exp));
    return 0;
}