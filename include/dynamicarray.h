#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <stdlib.h>
#include <stdio.h>

typedef struct DynamicArray {
    void **data;
    size_t size;
    size_t capacity;
} DynamicArray;

void init_array(DynamicArray *arr, size_t ini_cap);

void resize_arr(DynamicArray *arr, size_t new_cap);

void append(DynamicArray *arr, void* data);

void* remove_back(DynamicArray *arr);

void free_array(DynamicArray *arr, void (*free_fn)(void*));

#endif