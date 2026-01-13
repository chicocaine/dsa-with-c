#include <stdlib.h>

int binarysearch(int *key, int *arr, int arr_size) {
    int l = 0;
    int h = arr_size - 1;
    while (l <= h) {
        int mid = l + (h - l)/2;
        if (*key == arr[mid]) return mid;
        if (*key < arr[mid]) h = mid - 1;
        if (*key > arr[mid]) l = mid + 1;
    }
    return -1;
}