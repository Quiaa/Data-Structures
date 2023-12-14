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

int insert_to_front(int data){
    if(!head){
        head = allocate();
        head->data = data;
        last_node = head;
        return 0;  
    }

    node *tmp = allocate();
    tmp->data = data;
    tmp->next = head;
    head = tmp;

    return 0;
}

int insert_to_tail(int data){
    if(!head){
        head = allocate();
        head->data = data;
        last_node = head;
        return 0;
    }

    node *tmp = allocate();

    last_node->next = tmp;
    last_node = tmp;
    tmp->data = data;

    return 0;
}

int insert_in_order(int data){
    if(!head){
        head = allocate();
        head->data = data;
        last_node = head;
        return 0;
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
    
    return 0;
}

void print_list(){
    node *tmp = head;
    while(tmp){
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
}

int find(int what){
    node *tmp = head;
    while(tmp){
        if(tmp->data == what) return 1;
        tmp = tmp->next;
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
    insert_in_order(7);
    insert_in_order(11);
    insert_in_order(2);
    
    delete(7);
    print_list();
}






