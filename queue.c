#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} node;

typedef struct queue{
    node *front;
    node *rear;
} queue;

node *create_node(int data){
    node *new_node = (struct node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

queue *create_queue(){
    queue *new_queue = (struct queue*)malloc(sizeof(queue));
    new_queue->front = new_queue->rear = NULL;
    return new_queue;
}

int is_empty(queue *q){
    return q->front == NULL;
}

void enqueue(queue *q, int data) {
    node *new_node = create_node(data);
    if(is_empty(q)){
        q->front = q->rear = new_node;
        return;
    }
    q->rear->next = new_node;
    q->rear = new_node;
}

int dequeue(queue *q) {
    if(is_empty(q)){
        printf("Queue is empty\n");
        return -1;
    }
    node *temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    free(temp);
    if(q->front == NULL) q->rear = NULL;
    return data;
}

void print_queue(queue *q){
    if(is_empty(q)){
        printf("Queue is empty\n");
        return;
    }

    node *temp = q->front;

    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    queue *q = create_queue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    print_queue(q);
    printf("Dequeued element: %d\n", dequeue(q));
    printf("Dequeued element: %d\n", dequeue(q));
    printf("Dequeued element: %d\n", dequeue(q));
    printf("Dequeued element: %d\n", dequeue(q));
    print_queue(q);
}
