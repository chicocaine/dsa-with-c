#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"

// queue implementation with linked list

typedef struct Queue {
    LinkedList list;
} Queue;

Queue create_new_queue(void) {
    return (Queue) { 
        .list = { 
            .head = NULL, 
            .tail = NULL, 
            .length = 0
        }
    };
}

void init_queue(Queue *queue) {
    queue->list.head = NULL;
    queue->list.tail = NULL;
    queue->list.length = 0;
}

void enqueue(Queue *queue, void *data) {
    insert_at(&queue->list, data, 0);
}

void* dequeue(Queue *queue) {
    if (queue->list.length == 0) {
        fprintf(stderr, "Error: Cannot dequeue an empty queue.");
        exit(1);
    }
    return remove_end(&queue->list);
}

void* queue_top(Queue *queue) {
    if (queue->list.length == 0) {
        fprintf(stderr, "Error: Cannot queue_top an empty queue.");
        exit(1);
    }
    return get_at(&queue->list, 0);
}

void* queue_bottom(Queue *queue) {
    if (queue->list.length == 0) {
        fprintf(stderr, "Error: Cannot queue_bottom an empty queue.");
        exit(1);
    }
    return get_at(&queue->list, queue->list.length-1);
}

void free_queue(Queue *queue, void (*free_fn)(void*)) {
    free_list(&queue->list, free_fn);
}
