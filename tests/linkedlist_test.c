#include <stdlib.h>
#include <assert.h>
#include "linkedlist.h"

void print_int(void* data);
void free_int(void* data);
int* make_int(int value);

int main() {
    LinkedList list = { NULL, NULL, 0 };

    insert_end(&list, make_int(42));
    int* x = (int*)get_at(&list, 0);
    assert(*x == 42);

    insert_at(&list, make_int(99), 0);
    int* y = (int*)get_at(&list, 0);
    assert(*y == 99);

    free_list(&list, free_int);
    return 0; 
}

void print_int(void* data) {
    printf(" %d", *(int*)data);
}

void free_int(void* data) {
    free(data);
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