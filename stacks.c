#include <stdio.h>
#define SIZE 10

int st[SIZE];
int top = -1;

int warn(){
    if(top>=SIZE){
        printf("---------------\n");
        printf("Stack overflow!\n");
        return 10;
    }
    else if(top <= -1){
        printf("----------------\n");
        printf("Stack underflow!\n");
        return 11;
    }
}
int push(int data){
    if(warn() == 10) return -1;
    st[++top] = data;
    return data;
}
int pop(){
    if(warn() == 11) return -1;
    int val = st[top--];
    return val;
}
int peek(){
    warn();
    return st[top];
}
void printStack(){
    printf("---------------\n");
    printf("Stack includes\n");
    printf("Top: %d\n", top);
    for(int i=0; i<=top; i++) printf("%2d: [%2d]\n", i, st[i]);
}

int main(){
    printStack();
    push(5);
    push(1);
    printStack();
    pop();
    printStack();
    pop();
    printStack();
    pop();
    printStack();
    
}