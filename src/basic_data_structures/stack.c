#include <stdlib.h>
#include "basic_data_structures_h/dynamicarray.h"

typedef struct Stack {
    DynamicArray arr;
} Stack;

Stack create_stack(size_t cap) {
    return (Stack) {.arr.data = malloc(cap * sizeof(void*)), .arr.capacity = cap, .arr.size = 0};
}

void push(Stack *stack, void* data) {
    append(&stack->arr, data);
}

void* pop(Stack *stack) {
    if (stack->arr.size == 0) {
        fprintf(stderr, "Error: Stack underflow.\n"); 
        exit(1);
    }
    return remove_back(&stack->arr);
}

void* top(Stack *stack) {
    if (stack->arr.size == 0) {
        fprintf(stderr, "Error: Stack is empty.\n"); 
        exit(1);
    }
    return stack->arr.data[stack->arr.size-1];
}

void free_stack(Stack *stack, void (*free_fn)(void*)) {
    free_array(&stack->arr, free_fn);
}