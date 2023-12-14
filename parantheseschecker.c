#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

int isOpening(char ch){
    return ch == '(' || ch == '{' || ch == '[';
}

int isClosing(char ch){
    return ch == ')' || ch == '}' || ch == ']';
}

int bracketsMatch(char opening, char closing){
    return (opening == '(' && closing == ')') || (opening == '{' && closing == '}') || (opening == '[' && closing == ']');
}

int isBalanced(char expr[]){
    char stack[SIZE];
    int top = -1;

    for (int i = 0; expr[i] != '\0'; i++) {
        if (isOpening(expr[i])) stack[++top] = expr[i];
        else if (isClosing(expr[i])){
            if(top == -1 || !bracketsMatch(stack[top], expr[i])) return 0;
            else top--; 
        }
    }
    return top == -1;
}

int main() {
    char expr[SIZE] = "[(())]";

    if(isBalanced(expr)) printf("Balanced");
    else printf("Unbalanced");
    return 0;
}