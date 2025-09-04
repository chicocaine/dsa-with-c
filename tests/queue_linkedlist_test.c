#include <stdlib.h>
#include <stdio.h>
#include "queue_linkedlist.h"

int* make_int(int value);
void free_int(void *data);

int main() {
    Queue q;
    init_queue(&q);

    enqueue(&q, make_int(10));
    enqueue(&q, make_int(20));
    enqueue(&q, make_int(30));
    enqueue(&q, make_int(40));
    enqueue(&q, make_int(50));

    printf("Top: %d\n", *(int*)queue_top(&q));
    printf("Bottom: %d\n", *(int*)queue_bottom(&q));

    printf("Dequeued: %d\n", *(int*)dequeue(&q));
    printf("Top: %d\n", *(int*)queue_top(&q));
    printf("Bottom: %d\n", *(int*)queue_bottom(&q));

    printf("Dequeued: %d\n", *(int*)dequeue(&q));
    printf("Dequeued: %d\n", *(int*)dequeue(&q));

    printf("Top: %d\n", *(int*)queue_top(&q));
    printf("Bottom: %d\n", *(int*)queue_bottom(&q));

    free_queue(&q, free_int);
    
    return 0;
}

int* make_int(int value) {
    int* num = malloc(sizeof(int));
    if (!num) {
        perror("malloc failed"); 
        exit(1);
    }
    *num = value;
    return num;
}

void free_int(void *data) {
    free(data);
}