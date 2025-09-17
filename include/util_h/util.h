#ifndef UTIL_H
#define UTIL_H

#include <stdlib.h>
#include <time.h>

int get_rand_num(int min, int max);

void fill_int_arr_rand(int *arr, size_t size, int min, int max);

void print_int_arr(int *arr, size_t arrlen);

#endif