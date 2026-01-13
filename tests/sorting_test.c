#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "util_h/util.h"
#include "sorting_algorithms/bubblesort.h"
#include "sorting_algorithms/insertionsort.h"
#include "sorting_algorithms/mergesort.h"
#include "sorting_algorithms/quicksort.h"
#include "sorting_algorithms/selectionsort.h"
#include "sorting_algorithms/heapsort.h"

int* make_int(int value);
void free_int(void *data);
void print_int(void *data);

int main() {

    srand(time(NULL));

    int arr[20];
    fill_int_arr_rand(arr, 20, 0, 50);
    int n = sizeof(arr) / sizeof(arr[0]);

    print_int_arr(arr, 20);
    heapsort(arr, 20);
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