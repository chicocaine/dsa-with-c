#include <stdlib.h>
#include "util_h/util.h"

int partition(int arr[], int l, int h) {
    int rand_index = get_rand_num(l, h);
    int pivot = arr[rand_index];
    int i = l - 1, j = h + 1;

    while (1) {
        do {
            i++;
        } while (arr[i] < pivot);
        do {
            j--;
        } while (arr[j] > pivot);
        
        if (i >= j) return j;

        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp; 
    }
}

void quicksort(int arr[], int l, int h) {
    if (l < h) {
        int p = partition(arr, l, h);
        quicksort(arr, l, p);
        quicksort(arr, p + 1, h);
    }
}