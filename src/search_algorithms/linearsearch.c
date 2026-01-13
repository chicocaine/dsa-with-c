#include <stdlib.h>

int linear_search(
    void *key, 
    void *arr, 
    int arr_size,
    size_t elem_size, 
    int (*cmp)(const void*, const void*)
) {
    const char *base = arr;
    for (int i = 0; i < arr_size; i++) {
        const void *elem = base + (i * elem_size);
        if (cmp(elem, key) == 0) {
            return i;
        }
    }
    return -1;
}