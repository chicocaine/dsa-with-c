#include <stdlib.h>
#include <stdio.h>
#include "util_h/util.h"
#include "sorting_algorithms/bubblesort.h"
#include "sorting_algorithms/insertionsort.h"

int* make_int(int value);
void free_int(void *data);
void print_int(void *data);

int main() {

    int arr[10];
    fill_int_arr_rand(arr, 10, 0, 10);
    
    print_int_arr(arr, 10);
    insertion_sort(arr, 10);
    print_int_arr(arr, 10);
    
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

void print_int(void* data) {
    printf(" %d", *(int*)data);
}