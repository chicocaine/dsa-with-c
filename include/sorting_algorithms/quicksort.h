#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <stdlib.h>
#include "util_h/util.h"

int partition(int arr[], int l, int h);
void quicksort(int arr[], int l, int h);

#endif