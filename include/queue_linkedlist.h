#ifndef QUEUE_LINKEDLIST_H
#define QUEUE_LINKEDLIST_H

#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"

typedef struct Queue {
    LinkedList list;
} Queue;

Queue create_new_queue(void);

void init_queue(Queue *queue);

void enqueue(Queue *queue, void *data);

void* dequeue(Queue *queue);

void* queue_top(Queue *queue);

void* queue_bottom(Queue *queue);

void free_queue(Queue *queue, void (*free_fn)(void*));

#endif