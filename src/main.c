#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "util_h/util.h"
#include "search_algorithms/linearsearch.h"
#include "search_algorithms/binarysearch.h"
#include "sorting_algorithms/quicksort.h"

int* make_int(int value);
void free_int(void *data);
void print_int(void *data);
int is_int(const void *a, const void *b);

int main() {

    srand(time(NULL));

    int arr[20] = { 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    int n = sizeof(arr)/sizeof(int);
    quicksort(arr, 0, n-1);

    int key = 4;
    
    print_int_arr(arr, 20);
    int idx_lin = linear_search(&key, arr, n, sizeof(int), is_int);
    int idx_bin = binarysearch(&key, arr, n);
    printf("Index Linear: ");
    print_int(&idx_lin);
    printf("Index Binary: ");
    print_int(&idx_bin);
}

int is_int(const void *a, const void *b) {
    int x = *(int *)a;
    int y = *(int *)b;
    if (x != y) return 1;
    return 0;
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
    printf(" %d\n", *(int*)data);
}