#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdlib.h>
#include <stdio.h>

typedef struct Node Node;

typedef struct LinkedList {
    Node* head;
    Node* tail;
    int length;
} LinkedList;

struct Node {
    void* data;
    Node* nxt;
};

void insert_end(LinkedList* list, void* data);
void insert_at(LinkedList* list, void* data, const int pos);

void* remove_end(LinkedList* list);
void* remove_at(LinkedList* list, const int pos);

void* get_at(LinkedList* list, const int pos);
int search(LinkedList* list, const void* target, int (*cmp)(const void*, const void*));

void reverse(LinkedList* list);
void free_list(LinkedList* list, void (*free_fn)(void*));

void print_list(LinkedList* list, void print_fn(void*));

#endif 
