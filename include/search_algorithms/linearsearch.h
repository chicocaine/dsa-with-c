#ifndef LINEARSEARCH_H
#define LINEARSEARCH_H

#include <stdlib.h>

int linear_search(
    void *key, 
    void *arr, 
    int arr_size,
    size_t elem_size, 
    int (*cmp)(const void*, const void*)
);

#endif