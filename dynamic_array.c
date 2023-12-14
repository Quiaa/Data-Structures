#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void array_printer(int *a, int size);
int *array_allocater(int size);
int *array_resizer(int *a, int oldSize, int newSize);

int main(){
    int *a = array_allocater(SIZE);

    for(int i = 0; i < SIZE; i++) a[i] = i;

    array_printer(a, SIZE);

    a = array_resizer(a, SIZE, SIZE*2);

    array_printer(a , SIZE*2);

    free(a);
    return 0;
}

int *array_allocater(int size){
    int *a = calloc(size, sizeof(int));
    return a;
}

int *array_resizer(int *a, int oldSize, int newSize){
    int *new_a = calloc(newSize, sizeof(int));
    for(int i = 0; i<(oldSize<newSize?oldSize:newSize); i++) new_a[i] = a[i];    
    return new_a;
}

void array_printer(int *a, int size){
    printf("Array starts at %p\n", a);
    for(int i = 0; i < size; i++) printf("%d ", a[i]);
    printf("\n");
}