#include <stdio.h>
#define SIZE 10

int s[SIZE];
int top = -1

int is_empty(){
    return top <= -1;
}

int pop(){
    if(is_empty()){
        printf("Stack underflow");
        return -1;
    }
    int val = s[top];
    top--;
    return val;
}

int push(int data){
    if(top >= SIZE){
        printf("Stack overflow");
        return -1;
    }
    s[++top] = data;
    return data;
}

int peek(){
    if(is_empty()){
        printf("Stack underflow");
        return -1;
    }
    return s[top];
}

int display(){
    printf("Stack internals\n");
    printf("---------------\n");
    printf("Top: %d\n", top);
    for(int i = 0; i<=top; i++){
        printf("%2d: [%2d]\n", i, s[i]);
    }
    return 0;
}
int main(){
    display();
    push[10];
    push[12];
    push[14];
    display();
    int val = pop();
    printf("Popped value = %d\n", val);
    
    
    
    }