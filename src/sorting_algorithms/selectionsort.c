#include <stdlib.h>

void selectionsort(int arr[], int size) {
    int sorted = 0;
    while (sorted < size - 1) {
        int min_idx = sorted;
        for (int cur_idx = sorted + 1; cur_idx < size; cur_idx++) {
            if (arr[cur_idx] < arr[min_idx]) {
                min_idx = cur_idx;
            }
        }
        int temp = arr[sorted];
        arr[sorted] = arr[min_idx];
        arr[min_idx] = temp;
        sorted++;
    }
}