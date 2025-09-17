#include <stdlib.h>
#include <time.h>

int get_rand_num(int min, int max) {
    srand(time(NULL));

    int num = min + rand() % (max - min + 1);
    return num;
}

void fill_int_arr_rand(int *arr, int size, int min, int max) {
    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        arr[i] = min + rand() % (max - min + 1);
    }
}