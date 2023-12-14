#include <stdio.h>
#include <ctype.h>
#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char data){
    if(top > SIZE) return;
    stack[++top] = data;
}

char pop(){
    if(top == -1) return -1;
    return stack[top--];
}

int comp(char data){
    if(data == '(') return 0;
    if(data == '+' || data == '-') return 1;
    if(data == '*' || data == '/') return 2;
    return 0;
}

int main(){
    char ex[SIZE];
    char *x, y;
    printf("Write the expression : ");
    scanf("%s",ex);
    x = ex;
    while(*x != '\0'){
        if(isalnum(*x)) printf("%c ",*x);
        else if(*x == '(') push(*x);
        else if(*x == ')') while((y = pop()) != '(') printf("%c ", y);
        else{
            while(comp(stack[top]) >= comp(*x)) printf("%c ", pop());
            push(*x);
        }
        x++;
    }
    while(top != -1) printf("%c ", pop());
    return 0;
}