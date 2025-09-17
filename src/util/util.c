#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int get_rand_num(int min, int max) {
    srand(time(NULL));

    int num = min + rand() % (max - min + 1);
    return num;
}

void fill_int_arr_rand(int *arr, size_t size, int min, int max) {
    srand(time(NULL));

    for (size_t i = 0; i < size; i++) {
        arr[i] = min + rand() % (max - min + 1);
    }
}

void print_int_arr(int *arr, size_t arrlen) {
    if (arrlen == 0) {
        printf("[ ]\n");
        return;
    }

    printf("[ ");
    for (size_t i = 0; i < arrlen; i++) {
        printf(" %d", arr[i]);
        if (i < arrlen - 1) printf(",");
    }
    printf(" ]\n");
}