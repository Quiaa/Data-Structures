#include <stdio.h>
#include <stdlib.h>

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

void insert_to_tail(int data){
    node *newNode = allocate();
    newNode->data = data;
    if(!head){
        head = newNode;
        last_node = head; 
        return;
    }
    last_node->next = newNode;
    last_node = newNode;
}

void insert_in_order(int data){
    if(!head){
        head = allocate();
        head->data = data;
        last_node = head;
        return;
    }
    node *prv = NULL, *current = head;

    while(current && current->data < data){
        prv = current;
        current = current->next;
    }

    node *tmp = allocate();
    tmp->data = data;

    if(!prv){
        tmp->next = head;
        head = tmp;
    }
    else{
        prv->next = tmp;
        tmp->next = current;
    }
    
    return;
}

void print_list(){
    node *current = head;
    while(current){
        printf("%d ", current->data);
        current = current->next;
    }
}

int find(int what){
    node *current = head;
    while(current){
        if(current->data == what) return 1;
        current = current->next;
    }
    return 0;
}

int delete(int what){
    node *tmp = head;
    node *prv = NULL;
    while(tmp){
        if(tmp->data == what){
            if(tmp == head){
                head = head->next;
            }
            else prv->next = tmp->next;
            
            free(tmp);
            return 1;
        }
        prv = tmp;
        tmp = tmp->next;
    }
    return 0;  
}

int main(){
    insert_in_order(8);
    insert_in_order(3);
    insert_in_order(6);

    print_list();
}
