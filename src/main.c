#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

int* make_int(int value);
void free_int(void *data);

int main() {
    Stack s;
    init_stack(&s, 2);

    push(&s, make_int(10));
    push(&s, make_int(20));
    push(&s, make_int(30));

    printf("Top: %d\n", *(int*)top(&s));   

    printf("Popped: %d\n", *(int*)pop(&s)); // 30
    printf("Popped: %d\n", *(int*)pop(&s)); // 20
    printf("Popped: %d\n", *(int*)pop(&s)); // 10

    free_stack(&s, free_int);

    if (&s == NULL) printf("nice\n");

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