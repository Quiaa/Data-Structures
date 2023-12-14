#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int pq[SIZE];
int front = -1, rear = -1;

int is_empty(){
    return front == -1;
}

int is_full(){
    return (front == 0 && rear == SIZE - 1) || (rear == front - 1);
}

void enqueue(int item){
    if (is_full()){
        printf("Priority queue is full\n");
        return;
    }
    
    if (front == -1){
        front = rear = 0;
        pq[rear] = item;
        return;
    }
    
    int i;
    for (i = rear; i >= front; i--) {
        if (item > pq[i]) pq[i + 1] = pq[i];
        else break;
    }
    
    pq[i + 1] = item;
    rear++;
}

int dequeue(){
    if (is_empty()){
        printf("Priority queue is empty\n");
        return -1;
    }
    
    int item = pq[front];
    
    if (front == rear) front = rear = -1;
    else front = (front + 1) % SIZE;

    return item;
}

void display(){
    if (is_empty()){
        printf("Priority queue is empty\n");
        return;
    }
    for (int i = front; i != rear; i = (i + 1) % SIZE) printf("%d ", pq[i]);
    printf("%d\n", pq[rear]);
}

int main(){
    enqueue(5);
    enqueue(3);
    enqueue(7);
    enqueue(1);
    enqueue(8);
    display();
    
    printf("Dequeued: %d\n", dequeue());
    printf("Dequeued: %d\n", dequeue());
    display();
    
    return 0;
}