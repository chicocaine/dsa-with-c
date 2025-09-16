#include <stdlib.h>
#include <stdio.h>

typedef struct Queue {
    void **data;
    size_t capacity;
    size_t size;
    size_t head;
    size_t tail;
} Queue;

Queue create_queue(size_t cap) {
    return (Queue) {
        .data = calloc(cap, sizeof(void*)),
        .capacity = cap,
        .size = 0,
        .head = 0,
        .tail = 0   
    };
}

void resize_queue(Queue *queue, size_t new_cap) {
    void **new_data = calloc(new_cap, sizeof(void*));
    for (size_t i = 0; i < queue->size; i++) {
        new_data[i] = queue->data[(queue->head + i) % queue->capacity];
    }
    free(queue->data);
    queue->data = new_data;
    queue->capacity = new_cap;
    queue->head = 0;
    queue->tail = queue->size;
}

void enqueue(Queue *queue, void *data) {
    if (queue->size == queue->capacity) resize_queue(queue, queue->capacity * 2);

    queue->data[queue->tail] = data;
    queue->tail = (queue->tail + 1) % queue->capacity;
    queue->size++;
}

void* dequeue(Queue *queue) {
    if (queue->size == 0) {
        fprintf(stderr, "Queue underflow.");
        exit(EXIT_FAILURE);
    }
    if (queue->size == queue->capacity / 4) resize_queue(queue, queue->capacity / 2);
    
    void *data = queue->data[queue->head];
    queue->head = (queue->head + 1) % queue->capacity;
    queue->size--;
    
    return data;
}

void print_queue(Queue *queue, void (*print_fn)(void*)) {
    if (queue->size == 0) {
        printf("[ ]\n");
        return;
    }
    printf("[");
    for (size_t i = 0; i < queue->size; i++) {
        print_fn(queue->data[(queue->head + i) % queue->capacity]);
        if ((queue->head + i) < queue->tail - 1) printf(",");
    }
    printf(" ]\n");
}

void free_queue(Queue *queue, void (*free_fn)(void*)) {
    for (size_t i = 0; i < queue->size; i++) {
        if(free_fn) {
            free_fn(queue->data[(queue->head + i) % queue->capacity]);
        }
    }
    free(queue->data);
    queue->data = NULL;
    queue->size = queue->capacity = queue->head = queue->tail = 0;
}