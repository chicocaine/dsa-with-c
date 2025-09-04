#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include "dynamicarray.h"

typedef struct Stack {
    DynamicArray arr;
} Stack;

void init_stack(Stack *stack, size_t ini_cap);

void push(Stack *stack, void *data);

void* pop(Stack *stack);

void* top(Stack *stack);

void free_stack(Stack *stack, void (*free_fn)(void*));

#endif