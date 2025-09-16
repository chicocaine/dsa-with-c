#include <stdlib.h>
#include <stdio.h>
#include "basic_data_structures_h/linkedlist.h"

// queue implementation with linked list

typedef struct Queue_ll {
    LinkedList list;
} Queue_ll;

Queue_ll create_queue_ll(void) {
    return (Queue_ll) { 
        .list = { 
            .head = NULL, 
            .tail = NULL, 
            .length = 0
        }
    };
}

void init_queue_ll(Queue_ll *queue) {
    queue->list.head = NULL;
    queue->list.tail = NULL;
    queue->list.length = 0;
}

void enqueue_ll(Queue_ll *queue, void *data) {
    insert_at(&queue->list, data, 0);
}

void* dequeue_ll(Queue_ll *queue) {
    if (queue->list.length == 0) {
        fprintf(stderr, "Error: Cannot dequeue an empty queue.");
        exit(1);
    }
    return remove_end(&queue->list);
}

void* queue_top(Queue_ll *queue) {
    if (queue->list.length == 0) {
        fprintf(stderr, "Error: Cannot queue_top an empty queue.");
        exit(1);
    }
    return get_at(&queue->list, 0);
}

void* queue_bottom(Queue_ll *queue) {
    if (queue->list.length == 0) {
        fprintf(stderr, "Error: Cannot queue_bottom an empty queue.");
        exit(1);
    }
    return get_at(&queue->list, queue->list.length-1);
}

void free_queue_ll(Queue_ll *queue, void (*free_fn)(void*)) {
    free_list(&queue->list, free_fn);
}
