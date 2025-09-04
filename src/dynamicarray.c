#include <stdlib.h>
#include <stdio.h>

typedef struct DynamicArray {
    void **data;
    size_t size;
    size_t capacity;
} DynamicArray;

void init_array(DynamicArray *arr, size_t ini_cap) {
    arr->data = malloc(ini_cap * sizeof(void*));
    arr->size = 0;
    arr->capacity = ini_cap;
}

void resize_arr(DynamicArray *arr, size_t new_cap) {
    arr->data = realloc(arr->data, new_cap * sizeof(void*));
    arr->capacity = new_cap;
}

void append(DynamicArray *arr, void* data) {
    if (arr != NULL && arr->size == arr->capacity) resize_arr(arr, arr->capacity * 2);
    arr->data[arr->size++] = data;
}

void* remove_back(DynamicArray *arr) {
    if (arr != NULL && arr->size == 0) {
        fprintf(stderr, "Error: Cannot remove on an empty array.");
        exit(1);
    } 

    void* value = arr->data[--arr->size];
    
    if (arr != NULL && arr->size == arr->capacity / 4) resize_arr(arr, arr->capacity / 2);
    
    return value;
}

void free_array(DynamicArray *arr, void (*free_fn)(void*)) {
    for (int i = 0; i < arr->size; i++) {
        if(free_fn) {
            free_fn(arr->data[i]);
        } else {
            fprintf(stderr, "Error: Invalid free_fn.");
            exit(1);
        }
    }
    free(arr->data);
    arr->data = NULL;
    arr->size = arr->capacity = 0;
}