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

LinkedList create_linked_list(void) {
    return (LinkedList) {
        .head = NULL,
        .tail = NULL,
        .length = 0
    };
}

void init_linked_list(LinkedList *list) {
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
}

void insert_end(LinkedList* list, void* data) {
    Node* new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->nxt = NULL;   

    if (list->length == 0) {
        list->head = new_node;
        list->tail = new_node;   
    } else {
        list->tail->nxt = new_node;
        list->tail = new_node;
    }
    list->length++;
}

void insert_at(LinkedList* list, void* data, const int pos) {
    if (pos < 0 || pos > list->length) return;

    Node* new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->nxt = NULL;

    if (pos == 0) {
        new_node->nxt = list->head;
        list->head = new_node;
        if (list->length == 0) list->tail = new_node;
    } else {
        Node* current_node = list->head;
        int current_pos = 0;
        
        while (current_pos < pos-1) {
            current_node = current_node->nxt;
            current_pos++;
        }
        
        new_node->nxt = current_node->nxt;
        current_node->nxt = new_node;

        if (pos == list->length) list->tail = new_node;
    }
    list->length++;
}

void* remove_end(LinkedList* list) {
    if (list->length == 0) return NULL;

    if (list->length == 1) {
        void* data = list->tail->data;
        free(list->tail);
        list->head = NULL;
        list->tail = NULL;
        list->length--;
        return data;
    }

    Node* prev_node = list->head;
    int prev_pos = 0;
    while (prev_pos < list->length-2) {
        prev_node = prev_node->nxt;
        prev_pos++;
    }

    void* data = list->tail->data;
    free(list->tail);
    prev_node->nxt = NULL;
    list->tail = prev_node;
    list->length--;

    return data;
}

void* remove_at(LinkedList* list, const int pos) {
    if (pos < 0 || pos >= list->length) return NULL;
    
    void* data;

    if (pos == 0) {
        Node* temp = list->head;
        data = temp->data;
        list->head = temp->nxt;
        
        if (list->length == 1) list->tail = NULL;
        free(temp);
    } else {
        Node* prev_node = list->head;
        int prev_pos = 0;
        while(prev_pos < pos-1) {
            prev_node = prev_node->nxt;
            prev_pos++;
        }

        Node* current_node = prev_node->nxt;     
        data = current_node->data;
        prev_node->nxt = current_node->nxt;
        
        if (pos == list->length-1) {
            list->tail = prev_node;
        }
        free(current_node);
    }
    
    list->length--;
    return data;
}

void* get_at(LinkedList* list, const int pos) {
    if (!list) return NULL;
    if (pos < 0 || pos >= list->length) return NULL;

    Node* current = list->head;
    for (int i = 0; i < pos; i++) {
        current = current->nxt;
    }
    return current->data;
}
 
void free_list(LinkedList* list, void (*free_fn)(void*)) {
    Node* current = list->head;
    while (current != NULL) {
        Node* next = current->nxt;

        if (free_fn) free_fn(current->data);

        free(current);
        current = next;
    }
    list->head = NULL;
    list->tail = NULL;
    list -> length = 0;
}

int search(LinkedList* list, const void* target, int (*cmp)(const void*, const void*)) {
    Node* current = list->head;
    int pos = 0;

    while (current != NULL) {
        if (cmp(current->data, target) == 0) return pos;
        current = current->nxt;
        pos++;
    }
    return -1;
}

void reverse(LinkedList* list) {
    if (list->length <= 1) return;

    Node* prev = NULL;
    Node* current = list->head;
    Node* next = NULL;

    list->tail = list->head;

    while (current != NULL) {
        next = current->nxt;
        current->nxt = prev;
        prev = current;
        current = next;
    }

    list->head = prev;
}

void print_list(LinkedList* list, void print_fn(void*)) {

    if (list->length == 0) {
        printf("[ ]\n");
        return;
    }

    printf("[");

    Node* current_node = list->head;
    while (current_node != NULL) {
        print_fn(current_node->data);
        if (current_node != list->tail) printf(",");
        current_node = current_node->nxt;
    }
    printf(" ]\n");
}