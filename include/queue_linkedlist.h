#ifndef QUEUE_LINKEDLIST_H
#define QUEUE_LINKEDLIST_H

#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"

typedef struct Queue_ll_ll {
    LinkedList list;
} Queue_ll;

Queue_ll create_queue_ll(void);

void init_queue_ll(Queue_ll *queue);

void enqueue_ll(Queue_ll *queue, void *data);

void* dequeue_ll(Queue_ll *queue);

void* queue_top(Queue_ll *queue);

void* queue_bottom(Queue_ll *queue);

void free_queue_ll(Queue_ll *queue, void (*free_fn)(void*));

#endif