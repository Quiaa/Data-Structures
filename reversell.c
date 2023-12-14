#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int st[SIZE];
int top = -1;
typedef struct node{
	int data;
	struct node *next;
} node;
node *head = NULL;
node *last_node = NULL;

node *allocate(){
    node *temp = (node*) malloc(sizeof(struct node));
    temp->next = NULL;
    return temp;
}

void insert_to_front(int data){
    node *newNode = allocate();
    newNode->data = data;
    newNode->next = NULL;
    if(!head){
        head = newNode;
        last_node = head; 
        return;
    }
    newNode->next = head;
    head = newNode;
}
void print_list(){
    node *current = head;
    while(current){
        printf("%d ", current->data);
        current = current->next;
    }
}
int push(int data){
    if(top >= SIZE){
        printf("Stack overflow");
        return -1;
    }
    st[++top] = data;
    return data;
}
int pop(){
    int val = st[top];
    top--;
    return val;
}
int reversal(){
    int i = 0;
    while(i < 2){
        push(head->data);
        head = head->next;
        printf("%2d: [%2d]\n", i, st[i]);
        i++;
    }
}
int main(){
    insert_to_front(5);
    insert_to_front(2);
    print_list();
    reversal();
    print_list();
}
