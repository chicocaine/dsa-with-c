#include <stdlib.h>
#include <stdio.h>
#include "util_h/util.h"
#include "sorting_algorithms/bubblesort.h"
#include "sorting_algorithms/insertionsort.h"
#include "sorting_algorithms/mergesort.h"

int* make_int(int value);
void free_int(void *data);
void print_int(void *data);

int main() {

    int arr[20];
    int n = 20;
    fill_int_arr_rand(arr, 20, 0, 50);

    print_int_arr(arr, 20);
    mergesort(arr, 0, n - 1);
    print_int_arr(arr, 20);
    
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