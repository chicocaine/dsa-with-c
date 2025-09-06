#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

int* make_int(int value);
void free_int(void *data);
void print_int(void *data);

int main() {
    Queue q = create_queue(4);

    print_queue(&q, print_int);

    enqueue(&q, make_int(10));
    print_queue(&q, print_int);
    printf("Queue head: %zu \n", q.head);
    printf("Queue tail: %zu \n", q.tail);


    enqueue(&q, make_int(20));
    enqueue(&q, make_int(30));
    enqueue(&q, make_int(40));
    enqueue(&q, make_int(50));
    
    print_queue(&q, print_int);
    printf("Queue head: %zu \n", q.head);
    printf("Queue tail: %zu \n", q.tail);

    printf("Queue size: %zu \n", q.size);
    printf("Queue capacity: %zu \n", q.capacity);

    printf("Dequeued: %d \n", *(int*)dequeue(&q));
    print_queue(&q, print_int);
    printf("Queue size: %zu \n", q.size);
    printf("Queue capacity: %zu \n", q.capacity);
    printf("Queue head: %zu \n", q.head);
    printf("Queue tail: %zu \n", q.tail);

    printf("Dequeued: %d \n", *(int*)dequeue(&q));
    print_queue(&q, print_int);
    printf("Queue size: %zu \n", q.size);
    printf("Queue capacity: %zu \n", q.capacity);
    printf("Queue head: %zu \n", q.head);
    printf("Queue tail: %zu \n", q.tail);

    printf("Dequeued: %d \n", *(int*)dequeue(&q));
    print_queue(&q, print_int);
    printf("Queue size: %zu \n", q.size);
    printf("Queue capacity: %zu \n", q.capacity);
    printf("Queue head: %zu \n", q.head);
    printf("Queue tail: %zu \n", q.tail);

    printf("Dequeued: %d \n", *(int*)dequeue(&q));
    print_queue(&q, print_int);
    printf("Queue size: %zu \n", q.size);
    printf("Queue capacity: %zu \n", q.capacity);
    printf("Queue head: %zu \n", q.head);
    printf("Queue tail: %zu \n", q.tail);

    printf("%d\n", *(int*)q.data[q.head]);
    print_queue(&q, print_int);

    printf("Queue head: %zu \n", q.head);
    printf("Queue tail: %zu \n", q.tail);

    printf("Queue size: %zu \n", q.size);
    printf("Queue capacity: %zu \n", q.capacity);

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

void print_int(void* data) {
    printf(" %d", *(int*)data);
}