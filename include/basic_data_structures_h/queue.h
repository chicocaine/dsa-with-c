#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>
#include <stdio.h>

typedef struct Queue {
    void **data;
    size_t capacity;
    size_t size;
    size_t head;
    size_t tail;
} Queue;

Queue create_queue(size_t cap);

void resize_queue(Queue *queue, size_t new_cap);

void enqueue(Queue *queue, void *data);

void* dequeue(Queue *queue);

void *peek(Queue *queue);

int is_empty(Queue *queue);

int is_full(Queue *queue);

void free_queue(Queue *queue, void (*free_fn)(void*));

void print_queue(Queue *queue, void (*print_fn)(void*));

#endif