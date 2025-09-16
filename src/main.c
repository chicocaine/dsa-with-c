#include <stdlib.h>
#include <stdio.h>
#include "basic_data_structures_h/hashtable.h"

int* make_int(int value);
void free_int(void *data);
void print_int(void *data);

int main() {

    HashTable hashy = create_hashtable(10);

    insert(&hashy, "Mark", make_int(21), free_int);
    insert(&hashy, "Sofia", make_int(22), free_int);
    insert(&hashy, "Terry", make_int(12), free_int);

    int *x = (int*)get(&hashy, "Terry");
    printf("Terry is %d years old.\n", *x);
    insert(&hashy, "Terry", make_int(13), free_int);
    x = (int*)get(&hashy, "Terry");
    printf("Terry is %d years old.\n", *x);

    delete(&hashy, "Sofia", free_int);
    if (get(&hashy, "Sofia") == NULL) printf("Key successfully removed.\n");

    free_table(&hashy, free_int);
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