#include <stdlib.h>
#include <stdio.h>
#include "queue_linkedlist.h"

int* make_int(int value);
void free_int(void *data);

int main() {
    Queue_ll q;
    init_queue(&q);

    enqueue_ll(&q, make_int(10));
    enqueue_ll(&q, make_int(20));
    enqueue_ll(&q, make_int(30));
    enqueue_ll(&q, make_int(40));
    enqueue_ll(&q, make_int(50));

    printf("Top: %d\n", *(int*)queue_top(&q));
    printf("Bottom: %d\n", *(int*)queue_bottom(&q));

    printf("Dequeued: %d\n", *(int*)dequeue_ll(&q));
    printf("Top: %d\n", *(int*)queue_top(&q));
    printf("Bottom: %d\n", *(int*)queue_bottom(&q));

    printf("Dequeued: %d\n", *(int*)dequeue_ll(&q));
    printf("Dequeued: %d\n", *(int*)dequeue_ll(&q));

    printf("Top: %d\n", *(int*)queue_top(&q));
    printf("Bottom: %d\n", *(int*)queue_bottom(&q));

    free_queue_ll(&q, free_int);
    
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