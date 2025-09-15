#include <stdlib.h>
#include <stdio.h>
#include "hashtable.h"

int* make_int(int value);
void free_int(void *data);
void print_int(void *data);

int main() {

    HashTable hashy = create_hashtable(10);

    insert(&hashy, "Mark", 21);
    insert(&hashy, "Sofia", 20);
    insert(&hashy, "Terry", 12);

    int *x = get(&hashy, "Terry");
    printf("Terry is %d years old.\n", *x);
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
    printf(" %d", *(int*)data);
}