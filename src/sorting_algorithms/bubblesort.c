#include <stdlib.h>

void bubble_sort(int *arr, size_t arrlen) {
    int tmp;
    for (size_t i = 0; i < arrlen - 1; i++) {
        for (size_t j = 0; j < arrlen - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;    
            }
        }
    }
}